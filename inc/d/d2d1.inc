' ########################################################################################
' Microsoft Windows
' File: D2D1.inc
' Contents: Master include file for Direct2D
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D2D1_INC = 1

'#ifndef COM_NO_WINDOWS_H
'#include <windows.h>
'#endif // #ifndef COM_NO_WINDOWS_H
#INCLUDE ONCE "windows.inc"

#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "dcommon.inc"
#INCLUDE ONCE "D2DErr.inc"
#INCLUDE ONCE "D2DBaseTypes.inc"
#INCLUDE ONCE "dxgiformat.inc"
#INCLUDE ONCE "dwrite.inc"
#INCLUDE ONCE "wincodec.inc"

'#ifndef D2D_NO_INCLUDE_D3D10
'#include <d3d10_1.h>
'#endif // #ifndef D2D_NO_INCLUDE_D3D10
'#IF NOT %DEF(%D2D_NO_INCLUDE_D3D10)
#INCLUDE ONCE "d3d10_1.inc"
'#ENDIF   ' // #ifndef D2D_NO_INCLUDE_D3D10

'#define D2D1_INVALID_TAG ULONGLONG_MAX   ' 0xffffffffffffffffui64
'#define D2D1_DEFAULT_FLATTENING_TOLERANCE (0.25f)
MACRO D2D1_DEFAULT_FLATTENING_TOLERANCE = 0.25!

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_ALPHA_MODE
'//
'//  Synopsis:
'//      Qualifies how alpha is to be treated in a bitmap or render target containing
'//      alpha.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_ALPHA_MODE
'{

'        //
'        // Alpha mode should be determined implicitly. Some target surfaces do not supply
'        // or imply this information in which case alpha must be specified.
'        //
'        D2D1_ALPHA_MODE_UNKNOWN = 0,

'        //
'        // Treat the alpha as premultipled.
'        //
'        D2D1_ALPHA_MODE_PREMULTIPLIED = 1,

'        //
'        // Opacity is in the 'A' component only.
'        //
'        D2D1_ALPHA_MODE_STRAIGHT = 2,

'        //
'        // Ignore any alpha channel information.
'        //
'        D2D1_ALPHA_MODE_IGNORE = 3,
'        D2D1_ALPHA_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_ALPHA_MODE;

' enum D2D1_ALPHA_MODE
%D2D1_ALPHA_MODE_UNKNOWN = 0???
%D2D1_ALPHA_MODE_PREMULTIPLIED = 1???
%D2D1_ALPHA_MODE_STRAIGHT = 2???
%D2D1_ALPHA_MODE_IGNORE = 3???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_GAMMA
'//
'//  Synopsis:
'//      This determines what gamma is used for interpolation/blending.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_GAMMA
'{

'        //
'        // Colors are manipulated in 2.2 gamma color space.
'        //
'        D2D1_GAMMA_2_2 = 0,

'        //
'        // Colors are manipulated in 1.0 gamma color space.
'        //
'        D2D1_GAMMA_1_0 = 1,
'        D2D1_GAMMA_FORCE_DWORD = 0xffffffff

'} D2D1_GAMMA;

' enum D2D1_GAMMA
%D2D1_GAMMA_2_2 = 0???
%D2D1_GAMMA_1_0 = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_OPACITY_MASK_CONTENT
'//
'//  Synopsis:
'//      Specifies what the contents are of an opacity mask.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_OPACITY_MASK_CONTENT
'{

'        //
'        // The mask contains geometries or bitmaps.
'        //
'        D2D1_OPACITY_MASK_CONTENT_GRAPHICS = 0,

'        //
'        // The mask contains text rendered using one of the natural text modes.
'        //
'        D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL = 1,

'        //
'        // The mask contains text rendered using one of the GDI compatible text modes.
'        //
'        D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE = 2,
'        D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD = 0xffffffff

'} D2D1_OPACITY_MASK_CONTENT;

' enum D2D1_OPACITY_MASK_CONTENT
%D2D1_OPACITY_MASK_CONTENT_GRAPHICS = 0???
%D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL = 1???
%D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE = 2???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_EXTEND_MODE
'//
'//  Synopsis:
'//      Enum which descibes how to sample from a source outside it's base tile.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_EXTEND_MODE
'{

'        //
'        // Extend the edges of the source out by clamping sample points outside the source
'        // to the edges.
'        //
'        D2D1_EXTEND_MODE_CLAMP = 0,

'        //
'        // The base tile is drawn untransformed and the remainder are filled by repeating
'        // the base tile.
'        //
'        D2D1_EXTEND_MODE_WRAP = 1,

'        //
'        // The same as wrap, but alternate tiles are flipped  The base tile is drawn
'        // untransformed.
'        //
'        D2D1_EXTEND_MODE_MIRROR = 2,
'        D2D1_EXTEND_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_EXTEND_MODE;

' enum D2D1_EXTEND_MODE
%D2D1_EXTEND_MODE_CLAMP = 0???
%D2D1_EXTEND_MODE_WRAP = 1???
%D2D1_EXTEND_MODE_MIRROR = 2???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_ANTIALIAS_MODE
'//
'//  Synopsis:
'//      Enum which descibes the manner in which we render edges of non-text primitives.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_ANTIALIAS_MODE
'{

'        //
'        // The edges of each primitive are antialiased sequentially.
'        //
'        D2D1_ANTIALIAS_MODE_PER_PRIMITIVE = 0,

'        //
'        // Each pixel is rendered if its pixel center is contained by the geometry.
'        //
'        D2D1_ANTIALIAS_MODE_ALIASED = 1,
'        D2D1_ANTIALIAS_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_ANTIALIAS_MODE;

' enum D2D1_ANTIALIAS_MODE
%D2D1_ANTIALIAS_MODE_PER_PRIMITIVE = 0???
%D2D1_ANTIALIAS_MODE_ALIASED = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_TEXT_ANTIALIAS_MODE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_TEXT_ANTIALIAS_MODE
'{

'        //
'        // Render text using the current system setting.
'        //
'        D2D1_TEXT_ANTIALIAS_MODE_DEFAULT = 0,

'        //
'        // Render text using ClearType.
'        //
'        D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE = 1,

'        //
'        // Render text using gray-scale.
'        //
'        D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE = 2,

'        //
'        // Render text aliased.
'        //
'        D2D1_TEXT_ANTIALIAS_MODE_ALIASED = 3,
'        D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_TEXT_ANTIALIAS_MODE;

' enum D2D1_TEXT_ANTIALIAS_MODE
%D2D1_TEXT_ANTIALIAS_MODE_DEFAULT = 0???
%D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE = 1???
%D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE = 2???
%D2D1_TEXT_ANTIALIAS_MODE_ALIASED = 3???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_BITMAP_INTERPOLATION_MODE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_BITMAP_INTERPOLATION_MODE
'{

'        //
'        // Nearest Neighbor filtering. Also known as nearest pixel or nearest point
'        // sampling.
'        //
'        D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR = 0,

'        //
'        // Linear filtering.
'        //
'        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR = 1,
'        D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_BITMAP_INTERPOLATION_MODE;

' enum D2D1_BITMAP_INTERPOLATION_MODE
%D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR = 0???
%D2D1_BITMAP_INTERPOLATION_MODE_LINEAR = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_DRAW_TEXT_OPTIONS
'//
'//  Synopsis:
'//      Modifications made to the draw text call that influence how the text is
'//      rendered.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_DRAW_TEXT_OPTIONS
'{

'        //
'        // Do not snap the baseline of the text vertically.
'        //
'        D2D1_DRAW_TEXT_OPTIONS_NO_SNAP = 0x00000001,

'        //
'        // Clip the text to the content bounds.
'        //
'        D2D1_DRAW_TEXT_OPTIONS_CLIP = 0x00000002,
'        D2D1_DRAW_TEXT_OPTIONS_NONE = 0x00000000,
'        D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD = 0xffffffff

'} D2D1_DRAW_TEXT_OPTIONS;

' enum D2D1_DRAW_TEXT_OPTIONS
%D2D1_DRAW_TEXT_OPTIONS_NO_SNAP = &H00000001???
%D2D1_DRAW_TEXT_OPTIONS_CLIP = &H00000002???
%D2D1_DRAW_TEXT_OPTIONS_NONE = &H00000000???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_DRAW_TEXT_OPTIONS);


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_PIXEL_FORMAT
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_PIXEL_FORMAT
'{
'    DXGI_FORMAT format;
'    D2D1_ALPHA_MODE alphaMode;

'} D2D1_PIXEL_FORMAT;

' // Size = 8 bytes
TYPE D2D1_PIXEL_FORMAT DWORD
   format    AS DWORD   ' DXGI_FORMAT
   alphaMode AS DWORD   ' D2D1_ALPHA_MODE
END TYPE

'typedef D2D_POINT_2U D2D1_POINT_2U;
'typedef D2D_POINT_2F D2D1_POINT_2F;
'typedef D2D_RECT_F D2D1_RECT_F;
'typedef D2D_RECT_U D2D1_RECT_U;
'typedef D2D_SIZE_F D2D1_SIZE_F;
'typedef D2D_SIZE_U D2D1_SIZE_U;
'typedef D2D_COLOR_F D2D1_COLOR_F;
'typedef D2D_MATRIX_3X2_F D2D1_MATRIX_3X2_F;
'typedef UINT64 D2D1_TAG;

MACRO D2D1_POINT_2U = D2D_POINT_2U
MACRO D2D1_POINT_2F = D2D_POINT_2F
MACRO D2D1_RECT_F = D2D_RECT_F
MACRO D2D1_RECT_U = D2D_RECT_U
MACRO D2D1_SIZE_F = D2D_SIZE_F
MACRO D2D1_SIZE_U = D2D_SIZE_U
MACRO D2D1_COLOR_F = D2D_COLOR_F
MACRO D2D1_MATRIX_3X2_F = D2D_MATRIX_3X2_F
'typedef UINT64 D2D1_TAG;

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_BITMAP_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_BITMAP_PROPERTIES
'{
'    D2D1_PIXEL_FORMAT pixelFormat;
'    FLOAT dpiX;
'    FLOAT dpiY;

'} D2D1_BITMAP_PROPERTIES;

' // Size = 16 bytes
TYPE D2D1_BITMAP_PROPERTIES DWORD
   pixelFormat AS D2D1_PIXEL_FORMAT
   dpiX        AS SINGLE              ' FLOAT
   dpiY        AS SINGLE              ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_GRADIENT_STOP
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_GRADIENT_STOP
'{
'    FLOAT position;
'    D2D1_COLOR_F color;

'} D2D1_GRADIENT_STOP;

' // Size = 20 bytes
TYPE D2D1_GRADIENT_STOP DWORD
   position AS SINGLE         ' FLOAT
   color    AS D2D1_COLOR_F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_BRUSH_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_BRUSH_PROPERTIES
'{
'    FLOAT opacity;
'    D2D1_MATRIX_3X2_F transform;

'} D2D1_BRUSH_PROPERTIES;

' // Size = 28 bytes
TYPE D2D1_BRUSH_PROPERTIES DWORD
   opacity   AS SINGLE              ' FLOAT
   transform AS D2D1_MATRIX_3X2_F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_BITMAP_BRUSH_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_BITMAP_BRUSH_PROPERTIES
'{
'    D2D1_EXTEND_MODE extendModeX;
'    D2D1_EXTEND_MODE extendModeY;
'    D2D1_BITMAP_INTERPOLATION_MODE interpolationMode;

'} D2D1_BITMAP_BRUSH_PROPERTIES;

' // Size = 12 bytes
TYPE D2D1_BITMAP_BRUSH_PROPERTIES DWORD
   extendModeX       AS DWORD   ' D2D1_EXTEND_MODE
   extendModeY       AS DWORD   ' D2D1_EXTEND_MODE
   interpolationMode AS DWORD   ' D2D1_BITMAP_INTERPOLATION_MODE
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
'{
'    D2D1_POINT_2F startPoint;
'    D2D1_POINT_2F endPoint;

'} D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES;

' // Size = 16 bytes
TYPE D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES DWORD
   startPoint AS D2D1_POINT_2F
   endPoint   AS D2D1_POINT_2F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
'{
'    D2D1_POINT_2F center;
'    D2D1_POINT_2F gradientOriginOffset;
'    FLOAT radiusX;
'    FLOAT radiusY;

'} D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES;

' // Size = 24 bytes
TYPE D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES DWORD
   center               AS D2D1_POINT_2F
   gradientOriginOffset AS D2D1_POINT_2F
   radiusX              AS SINGLE          ' FLOAT
   radiusY              AS SINGLE          ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_ARC_SIZE
'//
'//  Synopsis:
'//      Differentiates which of the two possible arcs could match the given arc
'//      parameters.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_ARC_SIZE
'{
'        D2D1_ARC_SIZE_SMALL = 0,
'        D2D1_ARC_SIZE_LARGE = 1,
'        D2D1_ARC_SIZE_FORCE_DWORD = 0xffffffff

'} D2D1_ARC_SIZE;

' enum D2D1_ARC_SIZE
%D2D1_ARC_SIZE_SMALL = 0???
%D2D1_ARC_SIZE_LARGE = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_CAP_STYLE
'//
'//  Synopsis:
'//      Enum which descibes the drawing of the ends of a line.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_CAP_STYLE
'{

'        //
'        // Flat line cap.
'        //
'        D2D1_CAP_STYLE_FLAT = 0,

'        //
'        // Square line cap.
'        //
'        D2D1_CAP_STYLE_SQUARE = 1,

'        //
'        // Round line cap.
'        //
'        D2D1_CAP_STYLE_ROUND = 2,

'        //
'        // Triangle line cap.
'        //
'        D2D1_CAP_STYLE_TRIANGLE = 3,
'        D2D1_CAP_STYLE_FORCE_DWORD = 0xffffffff

'} D2D1_CAP_STYLE;

' enum D2D1_CAP_STYLE
%D2D1_CAP_STYLE_FLAT = 0???
%D2D1_CAP_STYLE_SQUARE = 1???
%D2D1_CAP_STYLE_ROUND = 2???
%D2D1_CAP_STYLE_TRIANGLE = 3???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_DASH_STYLE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_DASH_STYLE
'{
'        D2D1_DASH_STYLE_SOLID = 0,
'        D2D1_DASH_STYLE_DASH = 1,
'        D2D1_DASH_STYLE_DOT = 2,
'        D2D1_DASH_STYLE_DASH_DOT = 3,
'        D2D1_DASH_STYLE_DASH_DOT_DOT = 4,
'        D2D1_DASH_STYLE_CUSTOM = 5,
'        D2D1_DASH_STYLE_FORCE_DWORD = 0xffffffff

'} D2D1_DASH_STYLE;

' enum D2D1_DASH_STYLE
%D2D1_DASH_STYLE_SOLID = 0???
%D2D1_DASH_STYLE_DASH = 1???
%D2D1_DASH_STYLE_DOT = 2???
%D2D1_DASH_STYLE_DASH_DOT = 3???
%D2D1_DASH_STYLE_DASH_DOT_DOT = 4???
%D2D1_DASH_STYLE_CUSTOM = 5???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_LINE_JOIN
'//
'//  Synopsis:
'//      Enum which descibes the drawing of the corners on the line.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_LINE_JOIN
'{

'        //
'        // Miter join.
'        //
'        D2D1_LINE_JOIN_MITER = 0,

'        //
'        // Bevel join.
'        //
'        D2D1_LINE_JOIN_BEVEL = 1,

'        //
'        // Round join.
'        //
'        D2D1_LINE_JOIN_ROUND = 2,

'        //
'        // Miter/Bevel join.
'        //
'        D2D1_LINE_JOIN_MITER_OR_BEVEL = 3,
'        D2D1_LINE_JOIN_FORCE_DWORD = 0xffffffff

'} D2D1_LINE_JOIN;

' enum D2D1_LINE_JOIN
%D2D1_LINE_JOIN_MITER = 0???
%D2D1_LINE_JOIN_BEVEL = 1???
%D2D1_LINE_JOIN_ROUND = 2???
%D2D1_LINE_JOIN_MITER_OR_BEVEL = 3???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_COMBINE_MODE
'//
'//  Synopsis:
'//      This enumeration describes the type of combine operation to be performed.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_COMBINE_MODE
'{

'        //
'        // Produce a geometry representing the set of points contained in either
'        // the first or the second geometry.
'        //
'        D2D1_COMBINE_MODE_UNION = 0,

'        //
'        // Produce a geometry representing the set of points common to the first
'        // and the second geometries.
'        //
'        D2D1_COMBINE_MODE_INTERSECT = 1,

'        //
'        // Produce a geometry representing the set of points contained in the
'        // first geometry or the second geometry, but not both.
'        //
'        D2D1_COMBINE_MODE_XOR = 2,

'        //
'        // Produce a geometry representing the set of points contained in the
'        // first geometry but not the second geometry.
'        //
'        D2D1_COMBINE_MODE_EXCLUDE = 3,
'        D2D1_COMBINE_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_COMBINE_MODE;

' enum D2D1_COMBINE_MODE
%D2D1_COMBINE_MODE_UNION = 0???
%D2D1_COMBINE_MODE_INTERSECT = 1???
%D2D1_COMBINE_MODE_XOR = 2???
%D2D1_COMBINE_MODE_EXCLUDE = 3???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_GEOMETRY_RELATION
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_GEOMETRY_RELATION
'{

'        //
'        // The relation between the geometries couldn't be determined. This value is never
'        // returned by any D2D method.
'        //
'        D2D1_GEOMETRY_RELATION_UNKNOWN = 0,

'        //
'        // The two geometries do not intersect at all.
'        //
'        D2D1_GEOMETRY_RELATION_DISJOINT = 1,

'        //
'        // The passed in geometry is entirely contained by the object.
'        //
'        D2D1_GEOMETRY_RELATION_IS_CONTAINED = 2,

'        //
'        // The object entirely contains the passed in geometry.
'        //
'        D2D1_GEOMETRY_RELATION_CONTAINS = 3,

'        //
'        // The two geometries overlap but neither completely contains the other.
'        //
'        D2D1_GEOMETRY_RELATION_OVERLAP = 4,
'        D2D1_GEOMETRY_RELATION_FORCE_DWORD = 0xffffffff

'} D2D1_GEOMETRY_RELATION;

' enum D2D1_GEOMETRY_RELATION
%D2D1_GEOMETRY_RELATION_UNKNOWN = 0???
%D2D1_GEOMETRY_RELATION_DISJOINT = 1???
%D2D1_GEOMETRY_RELATION_IS_CONTAINED = 2???
%D2D1_GEOMETRY_RELATION_CONTAINS = 3???
%D2D1_GEOMETRY_RELATION_OVERLAP = 4???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_GEOMETRY_SIMPLIFICATION_OPTION
'//
'//  Synopsis:
'//      Specifies how simple the output of a simplified geometry sink should be.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_GEOMETRY_SIMPLIFICATION_OPTION
'{
'        D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES = 0,
'        D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES = 1,
'        D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD = 0xffffffff

'} D2D1_GEOMETRY_SIMPLIFICATION_OPTION;

' enum D2D1_GEOMETRY_SIMPLIFICATION_OPTION
%D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES = 0???
%D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_FIGURE_BEGIN
'//
'//  Synopsis:
'//      Indicates whether the given figure is filled or hollow.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_FIGURE_BEGIN
'{
'        D2D1_FIGURE_BEGIN_FILLED = 0,
'        D2D1_FIGURE_BEGIN_HOLLOW = 1,
'        D2D1_FIGURE_BEGIN_FORCE_DWORD = 0xffffffff

'} D2D1_FIGURE_BEGIN;

' enum D2D1_FIGURE_BEGIN
%D2D1_FIGURE_BEGIN_FILLED = 0???
%D2D1_FIGURE_BEGIN_HOLLOW = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_FIGURE_END
'//
'//  Synopsis:
'//      Indicates whether the figure ir open or closed on its end point.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_FIGURE_END
'{
'        D2D1_FIGURE_END_OPEN = 0,
'        D2D1_FIGURE_END_CLOSED = 1,
'        D2D1_FIGURE_END_FORCE_DWORD = 0xffffffff

'} D2D1_FIGURE_END;

' enum D2D1_FIGURE_END
%D2D1_FIGURE_END_OPEN = 0???
%D2D1_FIGURE_END_CLOSED = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_BEZIER_SEGMENT
'//
'//  Synopsis:
'//      Describes a cubic bezier in a path.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_BEZIER_SEGMENT
'{
'    D2D1_POINT_2F point1;
'    D2D1_POINT_2F point2;
'    D2D1_POINT_2F point3;

'} D2D1_BEZIER_SEGMENT;

' // Size = 24 bytes
TYPE D2D1_BEZIER_SEGMENT DWORD
   point1 AS D2D1_POINT_2F
   point2 AS D2D1_POINT_2F
   point3 AS D2D1_POINT_2F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_TRIANGLE
'//
'//  Synopsis:
'//      Describes a triangle.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_TRIANGLE
'{
'    D2D1_POINT_2F point1;
'    D2D1_POINT_2F point2;
'    D2D1_POINT_2F point3;

'} D2D1_TRIANGLE;

' // Size = 24 bytes
TYPE D2D1_TRIANGLE DWORD
   point1 AS D2D1_POINT_2F
   point2 AS D2D1_POINT_2F
   point3 AS D2D1_POINT_2F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_PATH_SEGMENT
'//
'//  Synopsis:
'//      Indicates whether the given segment should be stroked, or, if the join between
'//      this segment and the previous one should be smooth.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_PATH_SEGMENT
'{
'        D2D1_PATH_SEGMENT_NONE = 0x00000000,
'        D2D1_PATH_SEGMENT_FORCE_UNSTROKED = 0x00000001,
'        D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN = 0x00000002,
'        D2D1_PATH_SEGMENT_FORCE_DWORD = 0xffffffff

'} D2D1_PATH_SEGMENT;

' enum D2D1_PATH_SEGMENT
%D2D1_PATH_SEGMENT_NONE = &H00000000???
%D2D1_PATH_SEGMENT_FORCE_UNSTROKED = &H00000001???
%D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN = &H00000002???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_PATH_SEGMENT);


'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_SWEEP_DIRECTION
'//
'//------------------------------------------------------------------------------
' enum D2D1_SWEEP_DIRECTION
%D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE = 0
%D2D1_SWEEP_DIRECTION_CLOCKWISE = 1

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_FILL_MODE
'//
'//------------------------------------------------------------------------------
' enum D2D1_FILL_MODE
%D2D1_FILL_MODE_ALTERNATE = 0
%D2D1_FILL_MODE_WINDING = 1

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_ARC_SEGMENT
'//
'//  Synopsis:
'//      Describes an arc that is defined as part of a path.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_ARC_SEGMENT
'{
'    D2D1_POINT_2F point;
'    D2D1_SIZE_F size;
'    FLOAT rotationAngle;
'    D2D1_SWEEP_DIRECTION sweepDirection;
'    D2D1_ARC_SIZE arcSize;

'} D2D1_ARC_SEGMENT;

' // Size = 28 bytes
TYPE D2D1_ARC_SEGMENT DWORD
   point          AS D2D1_POINT_2F
   size           AS D2D1_SIZE_F
   rotationAngle  AS SINGLE          ' FLOAT
   sweepDirection AS DWORD           ' D2D1_SWEEP_DIRECTION
   arcSize        AS DWORD           ' D2D1_ARC_SIZE
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_QUADRATIC_BEZIER_SEGMENT
'//
'//------------------------------------------------------------------------------

' // Size = 16 bytes
TYPE D2D1_QUADRATIC_BEZIER_SEGMENT DWORD
   point1 AS D2D1_POINT_2F
   point2 AS D2D1_POINT_2F
END TYPE


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_ELLIPSE
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_ELLIPSE
'{
'    D2D1_POINT_2F point;
'    FLOAT radiusX;
'    FLOAT radiusY;

'} D2D1_ELLIPSE;

' // Size = 16 bytes
TYPE D2D1_ELLIPSE DWORD
   point   AS D2D1_POINT_2F
   radiusX AS SINGLE          ' FLOAT
   radiusY AS SINGLE          ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_ROUNDED_RECT
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_ROUNDED_RECT
'{
'    D2D1_RECT_F rect;
'    FLOAT radiusX;
'    FLOAT radiusY;

'} D2D1_ROUNDED_RECT;

' // Size = 24 bytes
TYPE D2D1_ROUNDED_RECT DWORD
   rect    AS D2D1_RECT_F
   radiusX AS SINGLE        ' FLOAT
   radiusY AS SINGLE        ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_STROKE_STYLE_PROPERTIES
'//
'//  Synopsis:
'//      Properties, aside from the width, that allow geometric penning to be specified.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_STROKE_STYLE_PROPERTIES
'{
'    D2D1_CAP_STYLE startCap;
'    D2D1_CAP_STYLE endCap;
'    D2D1_CAP_STYLE dashCap;
'    D2D1_LINE_JOIN lineJoin;
'    FLOAT miterLimit;
'    D2D1_DASH_STYLE dashStyle;
'    FLOAT dashOffset;

'} D2D1_STROKE_STYLE_PROPERTIES;

' // Size = 28 bytes
TYPE D2D1_STROKE_STYLE_PROPERTIES DWORD
   startCap   AS DWORD    ' D2D1_CAP_STYLE
   endCap     AS DWORD    ' D2D1_CAP_STYLE
   dashCap    AS DWORD    ' D2D1_CAP_STYLE
   lineJoin   AS DWORD    ' D2D1_LINE_JOIN
   miterLimit AS SINGLE   ' FLOAT
   dashStyle  AS DWORD    ' D2D1_DASH_STYLE
   dashOffset AS SINGLE   ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_LAYER_OPTIONS
'//
'//  Synopsis:
'//      Specified options that can be applied when a layer resource is applied to create
'//      a layer.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_LAYER_OPTIONS
'{
'        D2D1_LAYER_OPTIONS_NONE = 0x00000000,

'        //
'        // The layer will render correctly for ClearType text. If the render target was set
'        // to ClearType previously, the layer will continue to render ClearType. If the
'        // render target was set to ClearType and this option is not specified, the render
'        // target will be set to render gray-scale until the layer is popped. The caller
'        // can override this default by calling SetTextAntialiasMode while within the
'        // layer. This flag is slightly slower than the default.
'        //
'        D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE = 0x00000001,
'        D2D1_LAYER_OPTIONS_FORCE_DWORD = 0xffffffff

'} D2D1_LAYER_OPTIONS;

' enum D2D1_LAYER_OPTIONS
%D2D1_LAYER_OPTIONS_NONE = &H00000000???
%D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE = &H00000001???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_LAYER_OPTIONS);


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_LAYER_PARAMETERS
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_LAYER_PARAMETERS
'{

'    //
'    // The rectangular clip that will be applied to the layer. The clip is affected by
'    // the world transform. Content outside of the content bounds will not render.
'    //
'    D2D1_RECT_F contentBounds;

'    //
'    // A general mask that can be optionally applied to the content. Content not inside
'    // the fill of the mask will not be rendered.
'    //
'    __field_ecount_opt(1) ID2D1Geometry *geometricMask;

'    //
'    // Specifies whether the mask should be aliased or antialiased.
'    //
'    D2D1_ANTIALIAS_MODE maskAntialiasMode;

'    //
'    // An additional transform that may be applied to the mask in addition to the
'    // current world transform.
'    //
'    D2D1_MATRIX_3X2_F maskTransform;

'    //
'    // The opacity with which all of the content in the layer will be blended back to
'    // the target when the layer is popped.
'    //
'    FLOAT opacity;

'    //
'    // An additional brush that can be applied to the layer. Only the opacity channel
'    // is sampled from this brush and multiplied both with the layer content and the
'    // over-all layer opacity.
'    //
'    __field_ecount_opt(1) ID2D1Brush *opacityBrush;

'    //
'    // Specifies if ClearType will be rendered into the layer.
'    //
'    D2D1_LAYER_OPTIONS layerOptions;

'} D2D1_LAYER_PARAMETERS;

' // Size = 60 bytes
TYPE D2D1_LAYER_PARAMETERS DWORD
   contentBounds     AS D2D1_RECT_F
   geometricMask     AS DWORD PTR           ' __field_ecount_opt(1) ID2D1Geometry *
   maskAntialiasMode AS DWORD               ' D2D1_ANTIALIAS_MODE
   maskTransform     AS D2D1_MATRIX_3X2_F
   opacity           AS SINGLE              ' FLOAT
   opacityBrush      AS DWORD PTR           ' __field_ecount_opt(1) ID2D1Brush *
   layerOptions      AS DWORD               ' D2D1_LAYER_OPTIONS
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_WINDOW_STATE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_WINDOW_STATE
'{
'        D2D1_WINDOW_STATE_NONE = 0x0000000,
'        D2D1_WINDOW_STATE_OCCLUDED = 0x0000001,
'        D2D1_WINDOW_STATE_FORCE_DWORD = 0xffffffff

'} D2D1_WINDOW_STATE;

' enum D2D1_WINDOW_STATE
%D2D1_WINDOW_STATE_NONE = &H0000000???
%D2D1_WINDOW_STATE_OCCLUDED = &H0000001???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_WINDOW_STATE);


'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_RENDER_TARGET_TYPE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_RENDER_TARGET_TYPE
'{

'        //
'        // D2D is free to choose the render target type for the caller.
'        //
'        D2D1_RENDER_TARGET_TYPE_DEFAULT = 0,

'        //
'        // The render target will render using the CPU.
'        //
'        D2D1_RENDER_TARGET_TYPE_SOFTWARE = 1,

'        //
'        // The render target will render using the GPU.
'        //
'        D2D1_RENDER_TARGET_TYPE_HARDWARE = 2,
'        D2D1_RENDER_TARGET_TYPE_FORCE_DWORD = 0xffffffff

'} D2D1_RENDER_TARGET_TYPE;

' enum D2D1_RENDER_TARGET_TYPE
%D2D1_RENDER_TARGET_TYPE_DEFAULT = 0???
%D2D1_RENDER_TARGET_TYPE_SOFTWARE = 1???
%D2D1_RENDER_TARGET_TYPE_HARDWARE = 2???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_FEATURE_LEVEL
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_FEATURE_LEVEL
'{

'        //
'        // The caller does not require a particular underlying D3D device level.
'        //
'        D2D1_FEATURE_LEVEL_DEFAULT = 0,

'        //
'        // The D3D device level is DX9 compatible.
'        //
'        D2D1_FEATURE_LEVEL_9 = D3D10_FEATURE_LEVEL_9_1,

'        //
'        // The D3D device level is DX10 compatible.
'        //
'        D2D1_FEATURE_LEVEL_10 = D3D10_FEATURE_LEVEL_10_0,
'        D2D1_FEATURE_LEVEL_FORCE_DWORD = 0xffffffff

'} D2D1_FEATURE_LEVEL;

' enum D2D1_FEATURE_LEVEL
%D2D1_FEATURE_LEVEL_DEFAULT = 0???
%D2D1_FEATURE_LEVEL_9 = %D3D10_FEATURE_LEVEL_9_1
%D2D1_FEATURE_LEVEL_10 = %D3D10_FEATURE_LEVEL_10_0

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_RENDER_TARGET_USAGE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_RENDER_TARGET_USAGE
'{
'        D2D1_RENDER_TARGET_USAGE_NONE = 0x00000000,

'        //
'        // Rendering will occur locally, if a terminal-services session is established, the
'        // bitmap updates will be sent to the terminal services client.
'        //
'        D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING = 0x00000001,

'        //
'        // The render target will allow a call to GetDC on the IGdiInteropRenderTarget
'        // interface. Rendering will also occur locally.
'        //
'        D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE = 0x00000002,
'        D2D1_RENDER_TARGET_USAGE_FORCE_DWORD = 0xffffffff

'} D2D1_RENDER_TARGET_USAGE;

' enum D2D1_RENDER_TARGET_USAGE
%D2D1_RENDER_TARGET_USAGE_NONE = &H00000000???
%D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING = &H00000001???
%D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE = &H00000002???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_RENDER_TARGET_USAGE);


'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_PRESENT_OPTIONS
'//
'//  Synopsis:
'//      Describes how present should behave.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_PRESENT_OPTIONS
'{
'        D2D1_PRESENT_OPTIONS_NONE = 0x00000000,

'        //
'        // Keep the target contents intact through present.
'        //
'        D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS = 0x00000001,

'        //
'        // Do not wait for display refresh to commit changes to display.
'        //
'        D2D1_PRESENT_OPTIONS_IMMEDIATELY = 0x00000002,
'        D2D1_PRESENT_OPTIONS_FORCE_DWORD = 0xffffffff

'} D2D1_PRESENT_OPTIONS;

' enum D2D1_PRESENT_OPTIONS
%D2D1_PRESENT_OPTIONS_NONE = &H00000000???
%D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS = &H00000001???
%D2D1_PRESENT_OPTIONS_IMMEDIATELY = &H00000002???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_PRESENT_OPTIONS);


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_RENDER_TARGET_PROPERTIES
'//
'//------------------------------------------------------------------------------

' // Size = 28 bytes
TYPE D2D1_RENDER_TARGET_PROPERTIES
   type        AS DWORD               ' D2D1_RENDER_TARGET_TYPE
   pixelFormat AS D2D1_PIXEL_FORMAT
   dpiX        AS SINGLE              ' FLOAT
   dpiY        AS SINGLE              ' FLOAT
   usage       AS DWORD               ' D2D1_RENDER_TARGET_USAGE
   minLevel    AS DWORD               ' D2D1_FEATURE_LEVEL
END TYPE


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_HWND_RENDER_TARGET_PROPERTIES
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_HWND_RENDER_TARGET_PROPERTIES
'{
'    HWND hwnd;
'    D2D1_SIZE_U pixelSize;
'    D2D1_PRESENT_OPTIONS presentOptions;

'} D2D1_HWND_RENDER_TARGET_PROPERTIES;

' // Size = 16 bytes
TYPE D2D1_HWND_RENDER_TARGET_PROPERTIES DWORD
   hwnd           AS DWORD         ' HWND
   pixelSize      AS D2D1_SIZE_U
   presentOptions AS DWORD         ' D2D1_PRESENT_OPTIONS
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Flag:
'//      D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS
'{
'        D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE = 0x00000000,

'        //
'        // The compatible render target will allow a call to GetDC on the
'        // IGdiInteropRenderTarget interface. This can be specified even if the parent
'        // render target is not GDI compatible.
'        //
'        D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE = 0x00000001,
'        D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD = 0xffffffff

'} D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS;

' enum D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS
%D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE = &H00000000???
%D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE = &H00000001???

'DEFINE_ENUM_FLAG_OPERATORS(D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS);


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_DRAWING_STATE_DESCRIPTION
'//
'//  Synopsis:
'//      Allows the drawing state to be atomically created. This also specifies the
'//      drawing state that is saved into an IDrawingStateBlock object.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_DRAWING_STATE_DESCRIPTION
'{
'    D2D1_ANTIALIAS_MODE antialiasMode;
'    D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
'    D2D1_TAG tag1;
'    D2D1_TAG tag2;
'    D2D1_MATRIX_3X2_F transform;

'} D2D1_DRAWING_STATE_DESCRIPTION;

' // Size = 48 bytes
TYPE D2D1_DRAWING_STATE_DESCRIPTION DWORD
   antialiasMode     AS DWORD               ' D2D1_ANTIALIAS_MODE
   textAntialiasMode AS DWORD               ' D2D1_TEXT_ANTIALIAS_MODE
   tag1              AS QUAD                ' D2D1_TAG
   tag2              AS QUAD                ' D2D1_TAG
   transform         AS D2D1_MATRIX_3X2_F
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_DC_INITIALIZE_MODE
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_DC_INITIALIZE_MODE
'{

'        //
'        // The contents of the D2D render target will be copied to the DC.
'        //
'        D2D1_DC_INITIALIZE_MODE_COPY = 0,

'        //
'        // The contents of the DC will be cleared.
'        //
'        D2D1_DC_INITIALIZE_MODE_CLEAR = 1,
'        D2D1_DC_INITIALIZE_MODE_FORCE_DWORD = 0xffffffff

'} D2D1_DC_INITIALIZE_MODE;

' enum D2D1_DC_INITIALIZE_MODE
%D2D1_DC_INITIALIZE_MODE_COPY = 0???
%D2D1_DC_INITIALIZE_MODE_CLEAR = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_DEBUG_LEVEL
'//
'//  Synopsis:
'//      Indicates the debug level to be outputed by the debug layer.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_DEBUG_LEVEL
'{
'        D2D1_DEBUG_LEVEL_NONE = 0,
'        D2D1_DEBUG_LEVEL_ERROR = 1,
'        D2D1_DEBUG_LEVEL_WARNING = 2,
'        D2D1_DEBUG_LEVEL_INFORMATION = 3,
'        D2D1_DEBUG_LEVEL_FORCE_DWORD = 0xffffffff

'} D2D1_DEBUG_LEVEL;

' enum D2D1_DEBUG_LEVEL
%D2D1_DEBUG_LEVEL_NONE = 0
%D2D1_DEBUG_LEVEL_ERROR = 1
%D2D1_DEBUG_LEVEL_WARNING = 2
%D2D1_DEBUG_LEVEL_INFORMATION = 3

'//+-----------------------------------------------------------------------------
'//
'//  Enum:
'//      D2D1_FACTORY_TYPE
'//
'//  Synopsis:
'//      Specifies the threading model of the created factory and all of its derived
'//      resources.
'//
'//------------------------------------------------------------------------------
'typedef enum D2D1_FACTORY_TYPE
'{

'        //
'        // The resulting factory and derived resources may only be invoked serially.
'        // Reference counts on resources are interlocked, however, resource and render
'        // target state is not protected from multi-threaded access.
'        //
'        D2D1_FACTORY_TYPE_SINGLE_THREADED = 0,

'        //
'        // The resulting factory may be invoked from multiple threads. Returned resources
'        // use interlocked reference counting and their state is protected.
'        //
'        D2D1_FACTORY_TYPE_MULTI_THREADED = 1,
'        D2D1_FACTORY_TYPE_FORCE_DWORD = 0xffffffff

'} D2D1_FACTORY_TYPE;

' enum D2D1_FACTORY_TYPE
%D2D1_FACTORY_TYPE_SINGLE_THREADED = 0???
%D2D1_FACTORY_TYPE_MULTI_THREADED = 1???

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D1_FACTORY_OPTIONS
'//
'//  Synopsis:
'//      Allows additional parameters for factory creation.
'//
'//------------------------------------------------------------------------------
'typedef struct D2D1_FACTORY_OPTIONS
'{

'    //
'    // Requests a certain level of debugging information from the debug layer. This
'    // parameter is ignored if the debug layer DLL is not present.
'    //
'    D2D1_DEBUG_LEVEL debugLevel;

'} D2D1_FACTORY_OPTIONS;

TYPE D2D1_FACTORY_OPTIONS
   debugLevel AS DWORD   ' D2D1_DEBUG_LEVEL
END TYPE

$IID_ID2D1Resource = GUID$("{2cd90691-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1Bitmap = GUID$("{a2296057-ea42-4099-983b-539fb6505426}")
$IID_ID2D1GradientStopCollection = GUID$("{2cd906a7-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1Brush = GUID$("{2cd906a8-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1BitmapBrush = GUID$("{2cd906aa-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1SolidColorBrush = GUID$("{2cd906a9-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1LinearGradientBrush = GUID$("{2cd906ab-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1RadialGradientBrush = GUID$("{2cd906ac-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1StrokeStyle = GUID$("{2cd9069d-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1Geometry = GUID$("{2cd906a1-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1RectangleGeometry = GUID$("{2cd906a2-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1RoundedRectangleGeometry = GUID$("{2cd906a3-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1EllipseGeometry = GUID$("{2cd906a4-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1GeometryGroup = GUID$("{2cd906a6-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1TransformedGeometry = GUID$("{2cd906bb-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1SimplifiedGeometrySink = GUID$("{2cd9069e-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1GeometrySink = GUID$("{2cd9069f-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1TessellationSink = GUID$("{2cd906c1-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1PathGeometry = GUID$("{2cd906a5-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1Mesh = GUID$("{2cd906c2-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1Layer = GUID$("{2cd9069b-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1DrawingStateBlock = GUID$("{28506e39-ebf6-46a1-bb47-fd85565ab957}")
$IID_ID2D1RenderTarget = GUID$("{2cd90694-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1BitmapRenderTarget = GUID$("{2cd90695-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1HwndRenderTarget = GUID$("{2cd90698-12e2-11dc-9fed-001143a055f9}")
$IID_ID2D1GdiInteropRenderTarget = GUID$("{e0db51c3-6f77-4bae-b3d5-e47509b35838}")
$IID_ID2D1DCRenderTarget = GUID$("{1c51bc64-de61-46fd-9899-63a5d8f03950}")
$IID_ID2D1Factory = GUID$("{06152247-6f50-465a-9245-118bfd3b6007}")

' ########################################################################################
' ID2D1Resource interface
' IID = 2cd90691-12e2-11dc-9fed-001143a055f9
' The root interface for all resources in D2D.
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ID2D1Resource $IID_ID2D1Resource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Bitmap interface
' IID = a2296057-ea42-4099-983b-539fb6505426
' Root bitmap resource, linearly scaled on a draw call.
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1Bitmap $IID_ID2D1Bitmap

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Bitmap methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================
   METHOD GetPixelSize ( _                              ' VTable offset = 20
   ) AS D2D1_SIZE_U                                     ' D2D1_SIZE_U
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 24
   ) AS D2D1_PIXEL_FORMAT                               ' D2D1_PIXEL_FORMAT
   ' =====================================================================================
   METHOD GetDpi ( _                                    ' VTable offset = 28
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyFromBitmap ( _                            ' VTable offset = 32
     BYREF destPoint AS D2D1_POINT_2U _                 ' __in_opt CONST D2D1_POINT_2U *destPoint
   , BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , OPTIONAL BYREF srcRect AS D2D1_RECT_U _            ' __in_opt CONST D2D1_RECT_U *srcRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyFromRenderTarget ( _                      ' VTable offset = 36
     BYREF destPoint AS D2D1_POINT_2U _                 ' __in_opt CONST D2D1_POINT_2U *destPoint
   , BYVAL renderTarget AS ID2D1RenderTarget _          ' __in ID2D1RenderTarget *renderTarget
   , OPTIONAL BYREF srcRect AS D2D1_RECT_U _            ' __in_opt CONST D2D1_RECT_U *srcRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyFromMemory ( _                            ' VTable offset = 40
     BYREF dstRect AS D2D1_RECT_U _                     ' __in_opt CONST D2D1_RECT_U *dstRect
   , BYVAL srcData AS DWORD _                           ' __in CONST void *srcData
   , BYVAL pitch AS DWORD _                             ' __in UINT32 pitch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1GradientStopCollection interface
' IID = 2cd906a7-12e2-11dc-9fed-001143a055f9
' Represents an collection of gradient stops that can then be the source resource
' for either a linear or radial gradient brush.
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1GradientStopCollection $IID_ID2D1GradientStopCollection

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1GradientStopCollection methods
   ' =====================================================================================
   METHOD GetGradientStopCount ( _                      ' VTable offset = 16
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetGradientStops ( _                          ' VTable offset = 20
     BYREF gradientStops AS D2D1_GRADIENT_STOP _        ' __out D2D1_GRADIENT_STOP *gradientStops
   , BYVAL gradientStopsCount AS DWORD _                ' __in UINT gradientStopsCount
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColorInterpolationGamma ( _                ' VTable offset = 20
   ) AS DWORD                                           ' D2D1_GAMMA
   ' =====================================================================================
   METHOD GetExtendMode ( _                             ' VTable offset = 24
   ) AS DWORD                                           ' D2D1_EXTEND_MODE
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Brush interface
' IID = 2cd906a8-12e2-11dc-9fed-001143a055f9
' The root brush interface. All brushes can be used to fill or pen a geometry.
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1Brush $IID_ID2D1Brush

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Brush methods
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 16
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 24
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1BitmapBrush interface
' IID = 2cd906aa-12e2-11dc-9fed-001143a055f9
' A bitmap brush allows a bitmap to be used to fill a geometry.
' Inherited interface = ID2D1Brush
' ########################################################################################

INTERFACE ID2D1BitmapBrush $IID_ID2D1BitmapBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Brush methods
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 16
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 24
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1BitmapBrush methods
   ' =====================================================================================
   METHOD SetExtendModeX ( _                            ' VTable offset = 32
     BYVAL extendModeX AS DWORD _                       ' __in D2D1_EXTEND_MODE extendModeX
   )                                                    ' void
   ' =====================================================================================
   METHOD SetExtendModeY ( _                            ' VTable offset = 36
     BYVAL extendModeY AS DWORD _                       ' __in D2D1_EXTEND_MODE extendModeY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInterpolationMode ( _                      ' VTable offset = 40
     BYVAL interpolationMode AS DWORD _                 ' __in D2D1_BITMAP_INTERPOLATION_MODE interpolationMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBitmap ( _                                 ' VTable offset = 44
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtendModeX ( _                            ' VTable offset = 48
   ) AS DWORD                                           ' D2D1_EXTEND_MODE
   ' =====================================================================================
   METHOD GetExtendModeY ( _                            ' VTable offset = 52
   ) AS DWORD                                           ' D2D1_EXTEND_MODE
   ' =====================================================================================
   METHOD GetInterpolationMode ( _                      ' VTable offset = 56
   ) AS DWORD                                           ' D2D1_BITMAP_INTERPOLATION_MODE
   ' =====================================================================================
   METHOD GetBitmap ( _                                 ' VTable offset = 60
     BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   )                                                    ' void
   ' =====================================================================================


END INTERFACE


' ########################################################################################
' ID2D1SolidColorBrush interface
' IID = 2cd906a9-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Brush
' ########################################################################################

INTERFACE ID2D1SolidColorBrush $IID_ID2D1SolidColorBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Brush methods
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 16
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 24
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1SolidColorBrush methods
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 32
     BYREF color AS D2D1_COLOR_F _                      ' __in CONST D2D1_COLOR_F *color
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 36
   ) AS D2D1_COLOR_F                                    ' D2D1_COLOR_F
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1LinearGradientBrush interface
' IID = 2cd906ab-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Brush
' ########################################################################################

INTERFACE ID2D1LinearGradientBrush $IID_ID2D1LinearGradientBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Brush methods
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 16
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 24
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1LinearGradientBrush methods
   ' =====================================================================================
   METHOD SetStartPoint ( _                             ' VTable offset = 32
     BYVAL startPoint AS D2D1_POINT_2F _                ' __in D2D1_POINT_2F startPoint
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEndPoint ( _                               ' VTable offset = 36
     BYVAL endPoint AS D2D1_POINT_2F _                  ' __in D2D1_POINT_2F endPoint
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStartPoint ( _                             ' VTable offset = 40
   ) AS D2D1_POINT_2F                                   ' D2D1_POINT_2F
   ' =====================================================================================
   METHOD GetEndPoint ( _                               ' VTable offset = 44
   ) AS D2D1_POINT_2F                                   ' D2D1_POINT_2F
   ' =====================================================================================
   METHOD GetGradientStopCollection ( _                 ' VTable offset = 48
     BYREF gradientStopCollection AS ID2D1GradientStopCollection _ ' __out ID2D1GradientStopCollection **gradientStopCollection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1RadialGradientBrush interface
' IID = 2cd906ac-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Brush
' ########################################################################################

INTERFACE ID2D1RadialGradientBrush $IID_ID2D1RadialGradientBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Brush methods
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 16
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 24
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RadialGradientBrush methods
   ' =====================================================================================
   METHOD SetCenter ( _                                 ' VTable offset = 32
     BYVAL center AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F center
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGradientOriginOffset ( _                   ' VTable offset = 36
     BYVAL gradientOriginOffset AS D2D1_POINT_2F _      ' __in D2D1_POINT_2F gradientOriginOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRadiusX ( _                                ' VTable offset = 40
     BYVAL radiusX AS SINGLE _                          ' __in FLOAT radiusX
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRadiusY ( _                                ' VTable offset = 44
     BYVAL radiusY AS SINGLE _                          ' __in FLOAT radiusY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCenter ( _                                 ' VTable offset = 48
   ) AS D2D1_POINT_2F                                   ' D2D1_POINT_2F
   ' =====================================================================================
   METHOD GetGradientOriginOffset ( _                   ' VTable offset = 52
   ) AS D2D1_POINT_2F                                   ' D2D1_POINT_2F
   ' =====================================================================================
   METHOD GetRadiusX ( _                                ' VTable offset = 56
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetRadiusY ( _                                ' VTable offset = 60
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetGradientStopCollection ( _                 ' VTable offset = 64
     BYREF gradientStopCollection AS ID2D1GradientStopCollection _ ' __out ID2D1GradientStopCollection **gradientStopCollection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1StrokeStyle interface
' IID = 2cd9069d-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1StrokeStyle $IID_ID2D1StrokeStyle

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1StrokeStyle methods
   ' =====================================================================================
   METHOD GetStartCap ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' D2D1_CAP_STYLE
   ' =====================================================================================
   METHOD GetEndCap ( _                                 ' VTable offset = 20
   ) AS DWORD                                           ' D2D1_CAP_STYLE
   ' =====================================================================================
   METHOD GetDashCap ( _                                ' VTable offset = 24
   ) AS DWORD                                           ' D2D1_CAP_STYLE
   ' =====================================================================================
   METHOD GetMiterLimit ( _                             ' VTable offset = 28
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetLineJoin ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' D2D1_LINE_JOIN
   ' =====================================================================================
   METHOD GetDashOffset ( _                             ' VTable offset = 36
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetDashStyle ( _                              ' VTable offset = 40
   ) AS DWORD                                           ' D2D1_DASH_STYLE
   ' =====================================================================================
   METHOD GetDashesCount ( _                            ' VTable offset = 44
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetDashes ( _                                 ' VTable offset = 48
     BYREF dashes AS SINGLE _                           ' __out FLOAT *dashes
   , BYVAL dashesCount AS DWORD _                       ' __in UINT dashesCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Geometry interface
' IID = 2cd906a1-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1Geometry $IID_ID2D1Geometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1RectangleGeometry interface
' IID = 2cd906a2-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1RectangleGeometry $IID_ID2D1RectangleGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RectangleGeometry methods
   ' =====================================================================================
   METHOD GetRect ( _                                   ' VTable offset = 68
     BYREF rect AS D2D1_RECT_F _                        ' __out D2D1_RECT_F *rect
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1RoundedRectangleGeometry interface
' IID = 2cd906a3-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1RoundedRectangleGeometry $IID_ID2D1RoundedRectangleGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RoundedRectangleGeometry methods
   ' =====================================================================================
   METHOD GetRoundedRect ( _                            ' VTable offset = 68
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __out D2D1_ROUNDED_RECT *roundedRect
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1EllipseGeometry interface
' IID = 2cd906a4-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1EllipseGeometry $IID_ID2D1EllipseGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1EllipseGeometry methods
   ' =====================================================================================
   METHOD GetEllipse ( _                                ' VTable offset = 68
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __out D2D1_ELLIPSE *ellipse
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1GeometryGroup interface
' IID = 2cd906a6-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1GeometryGroup $IID_ID2D1GeometryGroup

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1GeometryGroup methods
   ' =====================================================================================
   METHOD GetFillMode ( _                               ' VTable offset = 68
   ) AS DWORD                                           ' D2D1_FILL_MODE
   ' =====================================================================================
   METHOD GetSourceGeometryCount ( _                    ' VTable offset = 72
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetSourceGeometries ( _                       ' VTable offset = 76
     BYREF geometries AS ID2D1Geometry _                ' __out ID2D1Geometry **geometries
   , BYVAL geometriesCount AS DWORD _                   ' __in UINT geometriesCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1TransformedGeometry interface
' IID = 2cd906bb-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1TransformedGeometry $IID_ID2D1TransformedGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1TransformedGeometry methods
   ' =====================================================================================
   METHOD GetSourceGeometry ( _                         ' VTable offset = 68
     BYREF sourceGeometry AS ID2D1Geometry _            ' __out ID2D1Geometry **sourceGeometry
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 72
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __out D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1SimplifiedGeometrySink interface
' IID = 2cd9069e-12e2-11dc-9fed-001143a055f9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ID2D1SimplifiedGeometrySink $IID_ID2D1SimplifiedGeometrySink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFillMode ( _                               ' VTable offset = 12
     BYVAL fillMode AS LONG _                           ' __in D2D1_FILL_MODE fillMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSegmentFlags ( _                           ' VTable offset = 16
     BYVAL vertexFlags AS DWORD _                       ' __in D2D1_PATH_SEGMENT vertexFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginFigure ( _                               ' VTable offset = 20
     BYVAL startPoint AS D2D1_POINT_2F _                ' __in D2D1_POINT_2F startPoint
   , BYVAL figureBegin AS DWORD _                       ' __in D2D1_FIGURE_BEGIN figureBegin
   )                                                    ' void
   ' =====================================================================================
   METHOD AddLines ( _                                  ' VTable offset = 24
     BYREF points AS D2D1_POINT_2F _                    ' __in CONST D2D1_POINT_2F *points
   , BYVAL pointsCount AS DWORD _                       ' __in UINT pointsCount
   )                                                    ' void
   ' =====================================================================================
   METHOD AddBeziers ( _                                ' VTable offset = 28
     BYREF beziers AS D2D1_BEZIER_SEGMENT _             ' __in CONST D2D1_BEZIER_SEGMENT *beziers
   , BYVAL beziersCount AS DWORD _                      ' __in UINT beziersCount
   )                                                    ' void
   ' =====================================================================================
   METHOD EndFigure ( _                                 ' VTable offset = 32
     BYVAL figureEnd AS DWORD _                         ' __in D2D1_FIGURE_END figureEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1GeometrySink interface
' IID = 2cd9069f-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1SimplifiedGeometrySink
' ########################################################################################

INTERFACE ID2D1GeometrySink $IID_ID2D1GeometrySink

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1SimplifiedGeometrySink methods
   ' =====================================================================================
   METHOD SetFillMode ( _                               ' VTable offset = 12
     BYVAL fillMode AS LONG _                           ' __in D2D1_FILL_MODE fillMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSegmentFlags ( _                           ' VTable offset = 16
     BYVAL vertexFlags AS DWORD _                       ' __in D2D1_PATH_SEGMENT vertexFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginFigure ( _                               ' VTable offset = 20
     BYVAL startPoint AS D2D1_POINT_2F _                ' __in D2D1_POINT_2F startPoint
   , BYVAL figureBegin AS DWORD _                       ' __in D2D1_FIGURE_BEGIN figureBegin
   )                                                    ' void
   ' =====================================================================================
   METHOD AddLines ( _                                  ' VTable offset = 24
     BYREF points AS D2D1_POINT_2F _                    ' __in CONST D2D1_POINT_2F *points
   , BYVAL pointsCount AS DWORD _                       ' __in UINT pointsCount
   )                                                    ' void
   ' =====================================================================================
   METHOD AddBeziers ( _                                ' VTable offset = 28
     BYREF beziers AS D2D1_BEZIER_SEGMENT _             ' __in CONST D2D1_BEZIER_SEGMENT *beziers
   , BYVAL beziersCount AS DWORD _                      ' __in UINT beziersCount
   )                                                    ' void
   ' =====================================================================================
   METHOD EndFigure ( _                                 ' VTable offset = 32
     BYVAL figureEnd AS DWORD _                         ' __in D2D1_FIGURE_END figureEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1GeometrySink methods
   ' =====================================================================================
   METHOD AddLine ( _                                   ' VTable offset = 40
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddBezier ( _                                 ' VTable offset = 44
     BYREF bezier AS D2D1_BEZIER_SEGMENT _              ' __in CONST D2D1_BEZIER_SEGMENT *bezier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddQuadraticBezier ( _                        ' VTable offset = 48
     BYREF bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT _    ' __in CONST D2D1_QUADRATIC_BEZIER_SEGMENT *bezier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddQuadraticBeziers ( _                       ' VTable offset = 52
     BYREF beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT _   ' __in CONST D2D1_QUADRATIC_BEZIER_SEGMENT *beziers
   , BYVAL beziersCount AS DWORD _                      ' __in UINT beziersCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddArc ( _                                    ' VTable offset = 56
     BYREF arc AS D2D1_ARC_SEGMENT _                    ' __in CONST D2D1_ARC_SEGMENT *arc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1TessellationSink interface
' IID = 2cd906c1-12e2-11dc-9fed-001143a055f9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ID2D1TessellationSink $IID_ID2D1TessellationSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddTriangles ( _                              ' VTable offset = 12
     BYREF triangles AS D2D1_TRIANGLE _                 ' __in D2D1_TRIANGLE *triangles
   , BYVAL trianglesCount AS DWORD _                    ' __in UINT trianglesCount
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1PathGeometry interface
' IID = 2cd906a5-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Geometry
' ########################################################################################

INTERFACE ID2D1PathGeometry $IID_ID2D1PathGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Geometry methods
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 16
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidenedBounds ( _                          ' VTable offset = 20
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF bounds AS D2D1_RECT_F _                      ' __out D2D1_RECT_F *bounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StrokeContainsPoint ( _                       ' VTable offset = 24
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillContainsPoint ( _                         ' VTable offset = 28
     BYVAL point AS D2D1_POINT_2F _                     ' __in D2D1_POINT_2F point
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF contains AS LONG _                           ' __out BOOL *contains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareWithGeometry ( _                       ' VTable offset = 32
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF relation AS LONG _                           ' __out D2D1_GEOMETRY_RELATION *relation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Simplify ( _                                  ' VTable offset = 36
     BYVAL simplificationOption AS DWORD _              ' __in D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 40
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL tessellationSink AS ID2D1TessellationSink _  ' __in ID2D1TessellationSink *tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineWithGeometry ( _                       ' VTable offset = 44
     BYVAL inputGeometry AS ID2D1Geometry _             ' __in ID2D1Geometry *inputGeometry
   , BYVAL combineMode AS DWORD _                       ' __in D2D1_COMBINE_MODE combineMode
   , BYREF inputGeometryTransform AS D2D1_MATRIX_3X2_F _ ' __in_opt CONST D2D1_MATRIX_3X2_F *inputGeometryTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Outline ( _                                   ' VTable offset = 48
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeArea ( _                               ' VTable offset = 52
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF area AS SINGLE _                             ' __out FLOAT *area
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeLength ( _                             ' VTable offset = 56
     BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYREF length AS SINGLE _                           ' __out FLOAT *length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputePointAtLength ( _                      ' VTable offset = 60
     BYVAL length AS SINGLE _                           ' __in FLOAT length
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , OPTIONAL BYREF point AS D2D1_POINT_2F _            ' __out_opt D2D1_POINT_2F *point
   , OPTIONAL BYREF unitTangentVector AS D2D1_POINT_2F _ ' __out_opt D2D1_POINT_2F *unitTangentVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Widen ( _                                     ' VTable offset = 64
     BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth
   , BYVAL strokeStyle AS ID2D1StrokeStyle _            ' __in_opt ID2D1StrokeStyle *strokeStyle
   , BYREF worldTransform AS D2D1_MATRIX_3X2_F _        ' __in_opt CONST D2D1_MATRIX_3X2_F *worldTransform
   , BYVAL flatteningTolerance AS SINGLE _              ' __in FLOAT flatteningTolerance
   , BYVAL geometrySink AS ID2D1SimplifiedGeometrySink _ ' __in ID2D1SimplifiedGeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1PathGeometry methods
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 68
     BYREF geometrySink AS ID2D1GeometrySink _          ' __out ID2D1GeometrySink **geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stream ( _                                    ' VTable offset = 72
     BYVAL geometrySink AS ID2D1GeometrySink _          ' __in ID2D1GeometrySink *geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentCount ( _                           ' VTable offset = 76
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFigureCount ( _                            ' VTable offset = 80
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Mesh interface
' IID = 2cd906c2-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1Mesh $IID_ID2D1Mesh

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Mesh method
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 16
     BYREF tessellationSink AS ID2D1TessellationSink _  ' __out ID2D1TessellationSink **tessellationSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Layer interface
' IID = 2cd9069b-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1Layer $IID_ID2D1Layer

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1Layer method
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1DrawingStateBlock interface
' IID = 28506e39-ebf6-46a1-bb47-fd85565ab957
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1DrawingStateBlock $IID_ID2D1DrawingStateBlock

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1DrawingStateBlock methods
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION _ ' __out D2D1_DRAWING_STATE_DESCRIPTION *stateDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 20
     BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION _ ' __in CONST D2D1_DRAWING_STATE_DESCRIPTION *stateDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextRenderingParams ( _                    ' VTable offset = 24
     OPTIONAL BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextRenderingParams ( _                    ' VTable offset = 28
     OPTIONAL BYREF textRenderingParams AS IDWriteRenderingParams _ ' __out_opt IDWriteRenderingParams **textRenderingParams
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1RenderTarget interface
' IID = 2cd90694-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1Resource
' ########################################################################################

INTERFACE ID2D1RenderTarget $IID_ID2D1RenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RenderTarget methods
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 16
     BYVAL size AS D2D1_SIZE_U _                        ' __in D2D1_SIZE_U size
   , BYREF srcData AS DWORD _                           ' __in_opt CONST void *srcData
   , BYVAL pitch AS DWORD _                             ' __in UINT32 pitch
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromWicBitmap ( _                 ' VTable offset = 20
     BYVAL wicBitmapSource AS IWICBitmapSource _        ' __in IWICBitmapSource *wicBitmapSource
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedBitmap ( _                        ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL data AS IUnknown _                           ' __inout void *data
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapBrush ( _                         ' VTable offset = 28
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF bitmapBrushProperties AS D2D1_BITMAP_BRUSH_PROPERTIES _ '__in_opt CONST D2D1_BITMAP_BRUSH_PROPERTIES *bitmapBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF bitmapBrush AS ID2D1BitmapBrush _            ' __out ID2D1BitmapBrush **bitmapBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSolidColorBrush ( _                     ' VTable offset = 32
     BYREF color AS D2D1_COLOR_F _                      ' __in CONST D2D1_COLOR_F *color
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF solidColorBrush AS ID2D1SolidColorBrush _    ' __out ID2D1SolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGradientStopCollection ( _              ' VTable offset = 36
     BYREF gradientStops AS D2D1_GRADIENT_STOP _        ' __in CONST D2D1_GRADIENT_STOP *gradientStops
   , BYVAL gradientStopsCount AS DWORD _                ' __in UINT gradientStopsCount
   , BYVAL colorInterpolationGamma AS DWORD _           ' __in D2D1_GAMMA colorInterpolationGamma
   , BYVAL extendMode AS DWORD _                        ' __in D2D1_EXTEND_MODE extendMode
   , BYREF gradientStopCollection AS ID2D1GradientStopCollection _ '__out ID2D1GradientStopCollection **gradientStopCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLinearGradientBrush ( _                 ' VTable offset = 40
     BYREF linearGradientBrushProperties AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *linearGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF linearGradientBrush AS ID2D1LinearGradientBrush _ ' __out ID2D1LinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRadialGradientBrush ( _                 ' VTable offset = 44
     BYREF radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *radialGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF radialGradientBrush AS ID2D1RadialGradientBrush _ '__out ID2D1RadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompatibleRenderTarget ( _              ' VTable offset = 48
     BYREF desiredSize AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *desiredSize
   , BYREF desiredPixelSize AS D2D1_SIZE_U _            ' __in_opt CONST D2D1_SIZE_U *desiredPixelSize
   , BYREF desiredFormat AS D2D1_PIXEL_FORMAT _         ' __in_opt CONST D2D1_PIXEL_FORMAT *desiredFormat
   , BYVAL options AS DWORD _                           ' __in D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
   , BYREF bitmapRenderTarget AS ID2D1BitmapRenderTarget _ ' __out ID2D1BitmapRenderTarget **bitmapRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLayer ( _                               ' VTable offset = 52
     BYREF D2D1_SIZE_F AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *size
   , BYREF layer AS ID2D1Layer _                        ' __out ID2D1Layer **layer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 56
     BYREF mesh AS ID2D1Mesh _                          ' __out ID2D1Mesh **mesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 60
     BYVAL point0 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point0
   , BYVAL point1 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point1
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRectangle ( _                             ' VTable offset = 64
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        '  __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRectangle ( _                             ' VTable offset = 68
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedRectangle ( _                      ' VTable offset = 72
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRoundedRectangle ( _                      ' VTable offset = 76
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 80
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillEllipse ( _                               ' VTable offset = 84
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGeometry ( _                              ' VTable offset = 88
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillGeometry ( _                              ' VTable offset = 92
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , OPTIONAL BYVAL opacityBrush AS ID2D1Brush _        ' __in_opt ID2D1Brush *opacityBrush = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillMesh ( _                                  ' VTable offset = 96
     BYVAL mesh AS ID2D1Mesh _                          ' __in ID2D1Mesh *mesh
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD FillOpacityMask ( _                           ' VTable offset = 100
     BYVAL opacityMask AS ID2D1Bitmap _                 ' __in ID2D1Bitmap *opacityMask
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL content AS DWORD _                           ' __in D2D1_OPACITY_MASK_CONTENT content
   , OPTIONAL BYREF destinationRectangle AS D2D1_RECT_F _ ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBitmap ( _                                ' VTable offset = 104
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF destinationRectangle AS D2D1_RECT_F _        ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity = 1.0f
   , BYVAL interpolationMode AS DWORD _                 ' __in D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 108
     BYREF string AS WSTRINGZ _                         ' __in_ecount(stringLength) CONST WCHAR *string
   , BYVAL stringLength AS DWORD _                      ' __in UINT stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat *textFormat
   , BYREF layoutRect AS D2D1_RECT_F _                  ' __in CONST D2D1_RECT_F *layoutRect
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawTextLayout ( _                            ' VTable offset = 112
     BYVAL origin AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F origin
   , BYVAL textLayout AS IDWriteTextLayout _            ' __in IDWriteTextLayout *textLayout
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 116
     BYVAL baselineOrigin AS D2D1_POINT_2F _            ' __in D2D1_POINT_2F baselineOrigin
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in CONST DWRITE_GLYPH_RUN *glyphRun
   , BYVAL foregroundBrush AS ID2D1Brush _              ' __in ID2D1Brush *foregroundBrush
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 120
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 124
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __out D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAntialiasMode ( _                          ' VTable offset = 128
     BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAntialiasMode ( _                          ' VTable offset = 132
   ) AS DWORD                                           ' D2D1_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextAntialiasMode ( _                      ' VTable offset = 136
     BYVAL textAntialiasMode AS DWORD _                 ' __in D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextAntialiasMode ( _                      ' VTable offset = 140
   ) AS DWORD                                           ' D2D1_TEXT_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextRenderingParams ( _                    ' VTable offset = 144
     OPTIONAL BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextRenderingParams ( _                    ' VTable offset = 148
     OPTIONAL BYREF textRenderingParams AS IDWriteRenderingParams _ '__out_opt IDWriteRenderingParams **textRenderingParams
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTags ( _                                   ' VTable offset = 152
     BYVAL tag1 AS QUAD _                               ' __in D2D1_TAG tag1
   , BYVAL tag2 AS QUAD _                               ' __in D2D1_TAG tag2
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTags ( _                                   ' VTable offset = 156
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD PushLayer ( _                                 ' VTable offset = 160
     BYREF layerParameters AS D2D1_LAYER_PARAMETERS _   ' __in CONST D2D1_LAYER_PARAMETERS *layerParameters
   , BYVAL layer AS ID2D1Layer _                        ' __in ID2D1Layer *layer
   )                                                    ' void
   ' =====================================================================================
   METHOD PopLayer ( _                                  ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 168
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDrawingState ( _                          ' VTable offset = 172
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__inout ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDrawingState ( _                       ' VTable offset = 176
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__in ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD PushAxisAlignedClip ( _                       ' VTable offset = 180
     BYREF clipRect AS D2D1_RECT_F _                    ' __in CONST D2D1_RECT_F *clipRect
   , BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD PopAxisAlignedClip ( _                        ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 188
     OPTIONAL BYREF clearColor AS D2D1_COLOR_F _        ' __in_opt CONST D2D1_COLOR_F *clearColor = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginDraw ( _                                 ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD EndDraw ( _                                   ' VTable offset = 196
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 200
   ) AS D2D1_PIXEL_FORMAT                               ' D2D1_PIXEL_FORMAT
   ' =====================================================================================
   METHOD SetDpi ( _                                    ' VTable offset = 204
     BYVAL dpiX AS SINGLE _                             ' __in FLOAT dpiX
   , BYVAL dpiY AS SINGLE _                             ' __in FLOAT dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDpi ( _                                    ' VTable offset = 208
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 212
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================
   METHOD GetPixelSize ( _                              ' VTable offset = 216
   ) AS D2D1_SIZE_U                                     ' D2D1_SIZE_U
   ' =====================================================================================
   METHOD GetMaximumBitmapSize ( _                      ' VTable offset = 220
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 224
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1BitmapRenderTarget interface
' IID = 2cd90695-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

INTERFACE ID2D1BitmapRenderTarget $IID_ID2D1BitmapRenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RenderTarget methods
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 16
     BYVAL size AS D2D1_SIZE_U _                        ' __in D2D1_SIZE_U size
   , BYREF srcData AS DWORD _                           ' __in_opt CONST void *srcData
   , BYVAL pitch AS DWORD _                             ' __in UINT32 pitch
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromWicBitmap ( _                 ' VTable offset = 20
     BYVAL wicBitmapSource AS IWICBitmapSource _        ' __in IWICBitmapSource *wicBitmapSource
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedBitmap ( _                        ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL data AS IUnknown _                           ' __inout void *data
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapBrush ( _                         ' VTable offset = 28
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF bitmapBrushProperties AS D2D1_BITMAP_BRUSH_PROPERTIES _ '__in_opt CONST D2D1_BITMAP_BRUSH_PROPERTIES *bitmapBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF bitmapBrush AS ID2D1BitmapBrush _            ' __out ID2D1BitmapBrush **bitmapBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSolidColorBrush ( _                     ' VTable offset = 32
     BYREF color AS D2D1_COLOR_F _                      ' __in CONST D2D1_COLOR_F *color
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF solidColorBrush AS ID2D1SolidColorBrush _    ' __out ID2D1SolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGradientStopCollection ( _              ' VTable offset = 36
     BYREF gradientStops AS D2D1_GRADIENT_STOP _        ' __in CONST D2D1_GRADIENT_STOP *gradientStops
   , BYVAL gradientStopsCount AS DWORD _                ' UINT gradientStopsCount
   , BYVAL colorInterpolationGamma AS DWORD _           ' __in D2D1_GAMMA colorInterpolationGamma
   , BYVAL extendMode AS DWORD _                        ' __in D2D1_EXTEND_MODE extendMode
   , BYREF gradientStopCollection AS ID2D1GradientStopCollection _ '__out ID2D1GradientStopCollection **gradientStopCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLinearGradientBrush ( _                 ' VTable offset = 40
     BYREF linearGradientBrushProperties AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *linearGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF linearGradientBrush AS ID2D1LinearGradientBrush _ ' __out ID2D1LinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRadialGradientBrush ( _                 ' VTable offset = 44
     BYREF radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *radialGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF radialGradientBrush AS ID2D1RadialGradientBrush _ '__out ID2D1RadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompatibleRenderTarget ( _              ' VTable offset = 48
     BYREF desiredSize AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *desiredSize
   , BYREF desiredPixelSize AS D2D1_SIZE_U _            ' __in_opt CONST D2D1_SIZE_U *desiredPixelSize
   , BYREF desiredFormat AS D2D1_PIXEL_FORMAT _         ' __in_opt CONST D2D1_PIXEL_FORMAT *desiredFormat
   , BYVAL options AS DWORD _                           ' __in D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
   , BYREF bitmapRenderTarget AS ID2D1BitmapRenderTarget _ ' __out ID2D1BitmapRenderTarget **bitmapRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLayer ( _                               ' VTable offset = 52
     BYREF D2D1_SIZE_F AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *size
   , BYREF layer AS ID2D1Layer _                        ' __out ID2D1Layer **layer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 56
     BYREF mesh AS ID2D1Mesh _                          ' __out ID2D1Mesh **mesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 60
     BYVAL point0 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point0
   , BYVAL point1 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point1
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRectangle ( _                             ' VTable offset = 64
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        '  __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRectangle ( _                             ' VTable offset = 68
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedRectangle ( _                      ' VTable offset = 72
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRoundedRectangle ( _                      ' VTable offset = 76
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 80
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillEllipse ( _                               ' VTable offset = 84
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGeometry ( _                              ' VTable offset = 88
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillGeometry ( _                              ' VTable offset = 92
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , OPTIONAL BYVAL opacityBrush AS ID2D1Brush _        ' __in_opt ID2D1Brush *opacityBrush = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillMesh ( _                                  ' VTable offset = 96
     BYVAL mesh AS ID2D1Mesh _                          ' __in ID2D1Mesh *mesh
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD FillOpacityMask ( _                           ' VTable offset = 100
     BYVAL opacityMask AS ID2D1Bitmap _                 ' __in ID2D1Bitmap *opacityMask
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL content AS DWORD _                           ' __in D2D1_OPACITY_MASK_CONTENT content
   , OPTIONAL BYREF destinationRectangle AS D2D1_RECT_F _ ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBitmap ( _                                ' VTable offset = 104
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF destinationRectangle AS D2D1_RECT_F _        ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity = 1.0f
   , BYVAL interpolationMode AS DWORD _                 ' __in D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 108
     BYREF string AS WSTRINGZ _                         ' __in_ecount(stringLength) CONST WCHAR *string
   , BYVAL stringLength AS DWORD _                      ' __in UINT stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat *textFormat
   , BYREF layoutRect AS D2D1_RECT_F _                  ' __in CONST D2D1_RECT_F *layoutRect
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawTextLayout ( _                            ' VTable offset = 112
     BYVAL origin AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F origin
   , BYVAL textLayout AS IDWriteTextLayout _            ' __in IDWriteTextLayout *textLayout
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 116
     BYVAL baselineOrigin AS D2D1_POINT_2F _            ' __in D2D1_POINT_2F baselineOrigin
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in CONST DWRITE_GLYPH_RUN *glyphRun
   , BYVAL foregroundBrush AS ID2D1Brush _              ' __in ID2D1Brush *foregroundBrush
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 120
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 124
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __out D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAntialiasMode ( _                          ' VTable offset = 128
     BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAntialiasMode ( _                          ' VTable offset = 132
   ) AS DWORD                                           ' D2D1_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextAntialiasMode ( _                      ' VTable offset = 136
     BYVAL textAntialiasMode AS DWORD _                 ' __in D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextAntialiasMode ( _                      ' VTable offset = 140
   ) AS DWORD                                           ' D2D1_TEXT_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextRenderingParams ( _                    ' VTable offset = 144
     OPTIONAL BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextRenderingParams ( _                    ' VTable offset = 148
     OPTIONAL BYREF textRenderingParams AS IDWriteRenderingParams _ '__out_opt IDWriteRenderingParams **textRenderingParams
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTags ( _                                   ' VTable offset = 152
     BYVAL tag1 AS QUAD _                               ' __in D2D1_TAG tag1
   , BYVAL tag2 AS QUAD _                               ' __in D2D1_TAG tag2
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTags ( _                                   ' VTable offset = 156
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD PushLayer ( _                                 ' VTable offset = 160
     BYREF layerParameters AS D2D1_LAYER_PARAMETERS _   ' __in CONST D2D1_LAYER_PARAMETERS *layerParameters
   , BYVAL layer AS ID2D1Layer _                        ' __in ID2D1Layer *layer
   )                                                    ' void
   ' =====================================================================================
   METHOD PopLayer ( _                                  ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 168
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDrawingState ( _                          ' VTable offset = 172
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__inout ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDrawingState ( _                       ' VTable offset = 176
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__in ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD PushAxisAlignedClip ( _                       ' VTable offset = 180
     BYREF clipRect AS D2D1_RECT_F _                    ' __in CONST D2D1_RECT_F *clipRect
   , BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD PopAxisAlignedClip ( _                        ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 188
     OPTIONAL BYREF clearColor AS D2D1_COLOR_F _        ' __in_opt CONST D2D1_COLOR_F *clearColor = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginDraw ( _                                 ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD EndDraw ( _                                   ' VTable offset = 196
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 200
   ) AS D2D1_PIXEL_FORMAT                               ' D2D1_PIXEL_FORMAT
   ' =====================================================================================
   METHOD SetDpi ( _                                    ' VTable offset = 204
     BYVAL dpiX AS SINGLE _                             ' __in FLOAT dpiX
   , BYVAL dpiY AS SINGLE _                             ' __in FLOAT dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDpi ( _                                    ' VTable offset = 208
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 212
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================
   METHOD GetPixelSize ( _                              ' VTable offset = 216
   ) AS D2D1_SIZE_U                                     ' D2D1_SIZE_U
   ' =====================================================================================
   METHOD GetMaximumBitmapSize ( _                      ' VTable offset = 220
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 224
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1BitmapRenderTarget method
   ' =====================================================================================
   METHOD GetBitmap ( _                                 ' VTable offset = 228
     BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1HwndRenderTarget interface
' IID = 2cd90698-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

INTERFACE ID2D1HwndRenderTarget $IID_ID2D1HwndRenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RenderTarget methods
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 16
     BYVAL size AS D2D1_SIZE_U _                        ' __in D2D1_SIZE_U size
   , BYREF srcData AS DWORD _                           ' __in_opt CONST void *srcData
   , BYVAL pitch AS DWORD _                             ' __in UINT32 pitch
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromWicBitmap ( _                 ' VTable offset = 20
     BYVAL wicBitmapSource AS IWICBitmapSource _        ' __in IWICBitmapSource *wicBitmapSource
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedBitmap ( _                        ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL data AS IUnknown _                           ' __inout void *data
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapBrush ( _                         ' VTable offset = 28
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF bitmapBrushProperties AS D2D1_BITMAP_BRUSH_PROPERTIES _ '__in_opt CONST D2D1_BITMAP_BRUSH_PROPERTIES *bitmapBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF bitmapBrush AS ID2D1BitmapBrush _            ' __out ID2D1BitmapBrush **bitmapBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSolidColorBrush ( _                     ' VTable offset = 32
     BYREF color AS D2D1_COLOR_F _                      ' __in CONST D2D1_COLOR_F *color
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF solidColorBrush AS ID2D1SolidColorBrush _    ' __out ID2D1SolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGradientStopCollection ( _              ' VTable offset = 36
     BYREF gradientStops AS D2D1_GRADIENT_STOP _        ' __in CONST D2D1_GRADIENT_STOP *gradientStops
   , BYVAL gradientStopsCount AS DWORD _                ' UINT gradientStopsCount
   , BYVAL colorInterpolationGamma AS DWORD _           ' __in D2D1_GAMMA colorInterpolationGamma
   , BYVAL extendMode AS DWORD _                        ' __in D2D1_EXTEND_MODE extendMode
   , BYREF gradientStopCollection AS ID2D1GradientStopCollection _ '__out ID2D1GradientStopCollection **gradientStopCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLinearGradientBrush ( _                 ' VTable offset = 40
     BYREF linearGradientBrushProperties AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *linearGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF linearGradientBrush AS ID2D1LinearGradientBrush _ ' __out ID2D1LinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRadialGradientBrush ( _                 ' VTable offset = 44
     BYREF radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *radialGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF radialGradientBrush AS ID2D1RadialGradientBrush _ '__out ID2D1RadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompatibleRenderTarget ( _              ' VTable offset = 48
     BYREF desiredSize AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *desiredSize
   , BYREF desiredPixelSize AS D2D1_SIZE_U _            ' __in_opt CONST D2D1_SIZE_U *desiredPixelSize
   , BYREF desiredFormat AS D2D1_PIXEL_FORMAT _         ' __in_opt CONST D2D1_PIXEL_FORMAT *desiredFormat
   , BYVAL options AS DWORD _                           ' __in D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
   , BYREF bitmapRenderTarget AS ID2D1BitmapRenderTarget _ ' __out ID2D1BitmapRenderTarget **bitmapRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLayer ( _                               ' VTable offset = 52
     BYREF D2D1_SIZE_F AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *size
   , BYREF layer AS ID2D1Layer _                        ' __out ID2D1Layer **layer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 56
     BYREF mesh AS ID2D1Mesh _                          ' __out ID2D1Mesh **mesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 60
     BYVAL point0 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point0
   , BYVAL point1 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point1
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRectangle ( _                             ' VTable offset = 64
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRectangle ( _                             ' VTable offset = 68
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedRectangle ( _                      ' VTable offset = 72
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRoundedRectangle ( _                      ' VTable offset = 76
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 80
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillEllipse ( _                               ' VTable offset = 84
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGeometry ( _                              ' VTable offset = 88
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillGeometry ( _                              ' VTable offset = 92
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , OPTIONAL BYVAL opacityBrush AS ID2D1Brush _        ' __in_opt ID2D1Brush *opacityBrush = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillMesh ( _                                  ' VTable offset = 96
     BYVAL mesh AS ID2D1Mesh _                          ' __in ID2D1Mesh *mesh
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD FillOpacityMask ( _                           ' VTable offset = 100
     BYVAL opacityMask AS ID2D1Bitmap _                 ' __in ID2D1Bitmap *opacityMask
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL content AS DWORD _                           ' __in D2D1_OPACITY_MASK_CONTENT content
   , OPTIONAL BYREF destinationRectangle AS D2D1_RECT_F _ ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBitmap ( _                                ' VTable offset = 104
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF destinationRectangle AS D2D1_RECT_F _        ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity = 1.0f
   , BYVAL interpolationMode AS DWORD _                 ' __in D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 108
     BYREF string AS WSTRINGZ _                         ' __in_ecount(stringLength) CONST WCHAR *string
   , BYVAL stringLength AS DWORD _                      ' __in UINT stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat *textFormat
   , BYREF layoutRect AS D2D1_RECT_F _                  ' __in CONST D2D1_RECT_F *layoutRect
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawTextLayout ( _                            ' VTable offset = 112
     BYVAL origin AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F origin
   , BYVAL textLayout AS IDWriteTextLayout _            ' __in IDWriteTextLayout *textLayout
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 116
     BYVAL baselineOrigin AS D2D1_POINT_2F _            ' __in D2D1_POINT_2F baselineOrigin
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in CONST DWRITE_GLYPH_RUN *glyphRun
   , BYVAL foregroundBrush AS ID2D1Brush _              ' __in ID2D1Brush *foregroundBrush
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 120
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 124
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __out D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAntialiasMode ( _                          ' VTable offset = 128
     BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAntialiasMode ( _                          ' VTable offset = 132
   ) AS DWORD                                           ' D2D1_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextAntialiasMode ( _                      ' VTable offset = 136
     BYVAL textAntialiasMode AS DWORD _                 ' __in D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextAntialiasMode ( _                      ' VTable offset = 140
   ) AS DWORD                                           ' D2D1_TEXT_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextRenderingParams ( _                    ' VTable offset = 144
     OPTIONAL BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextRenderingParams ( _                    ' VTable offset = 148
     OPTIONAL BYREF textRenderingParams AS IDWriteRenderingParams _ '__out_opt IDWriteRenderingParams **textRenderingParams
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTags ( _                                   ' VTable offset = 152
     BYVAL tag1 AS QUAD _                               ' __in D2D1_TAG tag1
   , BYVAL tag2 AS QUAD _                               ' __in D2D1_TAG tag2
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTags ( _                                   ' VTable offset = 156
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD PushLayer ( _                                 ' VTable offset = 160
     BYREF layerParameters AS D2D1_LAYER_PARAMETERS _   ' __in CONST D2D1_LAYER_PARAMETERS *layerParameters
   , BYVAL layer AS ID2D1Layer _                        ' __in ID2D1Layer *layer
   )                                                    ' void
   ' =====================================================================================
   METHOD PopLayer ( _                                  ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 168
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDrawingState ( _                          ' VTable offset = 172
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__inout ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDrawingState ( _                       ' VTable offset = 176
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__in ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD PushAxisAlignedClip ( _                       ' VTable offset = 180
     BYREF clipRect AS D2D1_RECT_F _                    ' __in CONST D2D1_RECT_F *clipRect
   , BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD PopAxisAlignedClip ( _                        ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 188
     OPTIONAL BYREF clearColor AS D2D1_COLOR_F _        ' __in_opt CONST D2D1_COLOR_F *clearColor = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginDraw ( _                                 ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD EndDraw ( _                                   ' VTable offset = 196
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 200
   ) AS D2D1_PIXEL_FORMAT                               ' D2D1_PIXEL_FORMAT
   ' =====================================================================================
   METHOD SetDpi ( _                                    ' VTable offset = 204
     BYVAL dpiX AS SINGLE _                             ' __in FLOAT dpiX
   , BYVAL dpiY AS SINGLE _                             ' __in FLOAT dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDpi ( _                                    ' VTable offset = 208
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 212
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================
   METHOD GetPixelSize ( _                              ' VTable offset = 216
   ) AS D2D1_SIZE_U                                     ' D2D1_SIZE_U
   ' =====================================================================================
   METHOD GetMaximumBitmapSize ( _                      ' VTable offset = 220
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 224
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1HwndRenderTarget methods
   ' =====================================================================================
   METHOD CheckWindowState ( _                          ' VTable offset = 228
   ) AS DWORD                                           ' D2D1_WINDOW_STATE
   ' =====================================================================================
   METHOD Resize ( _                                    ' VTable offset = 232
     BYREF pixelSize AS D2D1_SIZE_U _                   ' __in CONST D2D1_SIZE_U *pixelSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHwnd ( _                                   ' VTable offset = 236
   ) AS DWORD                                           ' HWND
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1GdiInteropRenderTarget interface
' IID = e0db51c3-6f77-4bae-b3d5-e47509b35838
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ID2D1GdiInteropRenderTarget $IID_ID2D1GdiInteropRenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 12
     BYVAL mode AS DWORD _                              ' __in D2D1_DC_INITIALIZE_MODE mode
   , BYREF hdc AS DWORD _                               ' __out HDC *hdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 16
     OPTIONAL BYREF update AS RECT _                    ' __in_opt CONST RECT *update
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1DCRenderTarget interface
' IID = 2cd90698-12e2-11dc-9fed-001143a055f9
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

INTERFACE ID2D1DCRenderTarget $IID_ID2D1DCRenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   ' ID2D1Resource method
   ' =====================================================================================
   METHOD GetFactory ( _                                ' VTable offset = 12
     BYREF factory AS ID2D1Factory _                    ' __out ID2D1Factory **factory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1RenderTarget methods
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 16
     BYVAL size AS D2D1_SIZE_U _                        ' __in D2D1_SIZE_U size
   , BYREF srcData AS DWORD _                           ' __in_opt CONST void *srcData
   , BYVAL pitch AS DWORD _                             ' __in UINT32 pitch
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromWicBitmap ( _                 ' VTable offset = 20
     BYVAL wicBitmapSource AS IWICBitmapSource _        ' __in IWICBitmapSource *wicBitmapSource
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedBitmap ( _                        ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL data AS IUnknown _                           ' __inout void *data
   , BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES _ ' __in_opt CONST D2D1_BITMAP_PROPERTIES *bitmapProperties
   , BYREF bitmap AS ID2D1Bitmap _                      ' __out ID2D1Bitmap **bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapBrush ( _                         ' VTable offset = 28
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF bitmapBrushProperties AS D2D1_BITMAP_BRUSH_PROPERTIES _ '__in_opt CONST D2D1_BITMAP_BRUSH_PROPERTIES *bitmapBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF bitmapBrush AS ID2D1BitmapBrush _            ' __out ID2D1BitmapBrush **bitmapBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSolidColorBrush ( _                     ' VTable offset = 32
     BYREF color AS D2D1_COLOR_F _                      ' __in CONST D2D1_COLOR_F *color
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYREF solidColorBrush AS ID2D1SolidColorBrush _    ' __out ID2D1SolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGradientStopCollection ( _              ' VTable offset = 36
     BYREF gradientStops AS D2D1_GRADIENT_STOP _        ' __in CONST D2D1_GRADIENT_STOP *gradientStops
   , BYVAL gradientStopsCount AS DWORD _                ' UINT gradientStopsCount
   , BYVAL colorInterpolationGamma AS DWORD _           ' __in D2D1_GAMMA colorInterpolationGamma
   , BYVAL extendMode AS DWORD _                        ' __in D2D1_EXTEND_MODE extendMode
   , BYREF gradientStopCollection AS ID2D1GradientStopCollection _ '__out ID2D1GradientStopCollection **gradientStopCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLinearGradientBrush ( _                 ' VTable offset = 40
     BYREF linearGradientBrushProperties AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES *linearGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF linearGradientBrush AS ID2D1LinearGradientBrush _ ' __out ID2D1LinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRadialGradientBrush ( _                 ' VTable offset = 44
     BYREF radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES _ ' __in CONST D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES *radialGradientBrushProperties
   , BYREF brushProperties AS D2D1_BRUSH_PROPERTIES _   ' __in_opt CONST D2D1_BRUSH_PROPERTIES *brushProperties
   , BYVAL gradientStopCollection AS ID2D1GradientStopCollection _ ' __in ID2D1GradientStopCollection *gradientStopCollection
   , BYREF radialGradientBrush AS ID2D1RadialGradientBrush _ '__out ID2D1RadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompatibleRenderTarget ( _              ' VTable offset = 48
     BYREF desiredSize AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *desiredSize
   , BYREF desiredPixelSize AS D2D1_SIZE_U _            ' __in_opt CONST D2D1_SIZE_U *desiredPixelSize
   , BYREF desiredFormat AS D2D1_PIXEL_FORMAT _         ' __in_opt CONST D2D1_PIXEL_FORMAT *desiredFormat
   , BYVAL options AS DWORD _                           ' __in D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options
   , BYREF bitmapRenderTarget AS ID2D1BitmapRenderTarget _ ' __out ID2D1BitmapRenderTarget **bitmapRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLayer ( _                               ' VTable offset = 52
     BYREF D2D1_SIZE_F AS D2D1_SIZE_F _                 ' __in_opt CONST D2D1_SIZE_F *size
   , BYREF layer AS ID2D1Layer _                        ' __out ID2D1Layer **layer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 56
     BYREF mesh AS ID2D1Mesh _                          ' __out ID2D1Mesh **mesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 60
     BYVAL point0 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point0
   , BYVAL point1 AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F point1
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRectangle ( _                             ' VTable offset = 64
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        '  __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRectangle ( _                             ' VTable offset = 68
     BYREF rect AS D2D1_RECT_F _                        ' __in CONST D2D1_RECT_F *rect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedRectangle ( _                      ' VTable offset = 72
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRoundedRectangle ( _                      ' VTable offset = 76
     BYREF roundedRect AS D2D1_ROUNDED_RECT _           ' __in CONST D2D1_ROUNDED_RECT *roundedRect
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 80
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillEllipse ( _                               ' VTable offset = 84
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGeometry ( _                              ' VTable offset = 88
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL strokeWidth AS SINGLE _                      ' __in FLOAT strokeWidth = 1.0f
   , OPTIONAL BYVAL strokeStyle AS ID2D1StrokeStyle _   ' __in_opt ID2D1StrokeStyle *strokeStyle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillGeometry ( _                              ' VTable offset = 92
     BYVAL geometry AS ID2D1Geometry _                  ' __in ID2D1Geometry *geometry
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , OPTIONAL BYVAL opacityBrush AS ID2D1Brush _        ' __in_opt ID2D1Brush *opacityBrush = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD FillMesh ( _                                  ' VTable offset = 96
     BYVAL mesh AS ID2D1Mesh _                          ' __in ID2D1Mesh *mesh
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   )                                                    ' void
   ' =====================================================================================
   METHOD FillOpacityMask ( _                           ' VTable offset = 100
     BYVAL opacityMask AS ID2D1Bitmap _                 ' __in ID2D1Bitmap *opacityMask
   , BYVAL brush AS ID2D1Brush _                        ' __in ID2D1Brush *brush
   , BYVAL content AS DWORD _                           ' __in D2D1_OPACITY_MASK_CONTENT content
   , OPTIONAL BYREF destinationRectangle AS D2D1_RECT_F _ ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   ,OPTIONAL  BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBitmap ( _                                ' VTable offset = 104
     BYVAL bitmap AS ID2D1Bitmap _                      ' __in ID2D1Bitmap *bitmap
   , BYREF destinationRectangle AS D2D1_RECT_F _        ' __in_opt CONST D2D1_RECT_F *destinationRectangle = NULL
   , BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity = 1.0f
   , BYVAL interpolationMode AS DWORD _                 ' __in D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
   , OPTIONAL BYREF sourceRectangle AS D2D1_RECT_F _    ' __in_opt CONST D2D1_RECT_F *sourceRectangle = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 108
     BYREF string AS WSTRINGZ _                         ' __in_ecount(stringLength) CONST WCHAR *string
   , BYVAL stringLength AS DWORD _                      ' __in UINT stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat *textFormat
   , BYREF layoutRect AS D2D1_RECT_F _                  ' __in CONST D2D1_RECT_F *layoutRect
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawTextLayout ( _                            ' VTable offset = 112
     BYVAL origin AS D2D1_POINT_2F _                    ' __in D2D1_POINT_2F origin
   , BYVAL textLayout AS IDWriteTextLayout _            ' __in IDWriteTextLayout *textLayout
   , BYVAL defaultForegroundBrush AS ID2D1Brush _       ' __in ID2D1Brush *defaultForegroundBrush
   , BYVAL options AS DWORD _                           ' __in D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 116
     BYVAL baselineOrigin AS D2D1_POINT_2F _            ' __in D2D1_POINT_2F baselineOrigin
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in CONST DWRITE_GLYPH_RUN *glyphRun
   , BYVAL foregroundBrush AS ID2D1Brush _              ' __in ID2D1Brush *foregroundBrush
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 120
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 124
     BYREF transform AS D2D1_MATRIX_3X2_F _             ' __out D2D1_MATRIX_3X2_F *transform
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAntialiasMode ( _                          ' VTable offset = 128
     BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAntialiasMode ( _                          ' VTable offset = 132
   ) AS DWORD                                           ' D2D1_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextAntialiasMode ( _                      ' VTable offset = 136
     BYVAL textAntialiasMode AS DWORD _                 ' __in D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextAntialiasMode ( _                      ' VTable offset = 140
   ) AS DWORD                                           ' D2D1_TEXT_ANTIALIAS_MODE
   ' =====================================================================================
   METHOD SetTextRenderingParams ( _                    ' VTable offset = 144
     OPTIONAL BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextRenderingParams ( _                    ' VTable offset = 148
     OPTIONAL BYREF textRenderingParams AS IDWriteRenderingParams _ '__out_opt IDWriteRenderingParams **textRenderingParams
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTags ( _                                   ' VTable offset = 152
     BYVAL tag1 AS QUAD _                               ' __in D2D1_TAG tag1
   , BYVAL tag2 AS QUAD _                               ' __in D2D1_TAG tag2
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTags ( _                                   ' VTable offset = 156
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD PushLayer ( _                                 ' VTable offset = 160
     BYREF layerParameters AS D2D1_LAYER_PARAMETERS _   ' __in CONST D2D1_LAYER_PARAMETERS *layerParameters
   , BYVAL layer AS ID2D1Layer _                        ' __in ID2D1Layer *layer
   )                                                    ' void
   ' =====================================================================================
   METHOD PopLayer ( _                                  ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 168
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDrawingState ( _                          ' VTable offset = 172
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__inout ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDrawingState ( _                       ' VTable offset = 176
     BYVAL drawingStateBlock AS ID2D1DrawingStateBlock _ '__in ID2D1DrawingStateBlock *drawingStateBlock
   )                                                    ' void
   ' =====================================================================================
   METHOD PushAxisAlignedClip ( _                       ' VTable offset = 180
     BYREF clipRect AS D2D1_RECT_F _                    ' __in CONST D2D1_RECT_F *clipRect
   , BYVAL antialiasMode AS DWORD _                     ' __in D2D1_ANTIALIAS_MODE antialiasMode
   )                                                    ' void
   ' =====================================================================================
   METHOD PopAxisAlignedClip ( _                        ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 188
     OPTIONAL BYREF clearColor AS D2D1_COLOR_F _        ' __in_opt CONST D2D1_COLOR_F *clearColor = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginDraw ( _                                 ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD EndDraw ( _                                   ' VTable offset = 196
     OPTIONAL BYREF tag1 AS QUAD _                      ' __out_opt D2D1_TAG *tag1 = NULL
   , OPTIONAL BYREF tag2 AS QUAD _                      ' __out_opt D2D1_TAG *tag2 = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 200
   ) AS D2D1_PIXEL_FORMAT                               ' D2D1_PIXEL_FORMAT
   ' =====================================================================================
   METHOD SetDpi ( _                                    ' VTable offset = 204
     BYVAL dpiX AS SINGLE _                             ' __in FLOAT dpiX
   , BYVAL dpiY AS SINGLE _                             ' __in FLOAT dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDpi ( _                                    ' VTable offset = 208
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 212
   ) AS D2D1_SIZE_F                                     ' D2D1_SIZE_F
   ' =====================================================================================
   METHOD GetPixelSize ( _                              ' VTable offset = 216
   ) AS D2D1_SIZE_U                                     ' D2D1_SIZE_U
   ' =====================================================================================
   METHOD GetMaximumBitmapSize ( _                      ' VTable offset = 220
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 224
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

   ' =====================================================================================
   ' ID2D1DCRenderTarget methods
   ' =====================================================================================
   METHOD BindDC ( _                                    ' VTable offset = 228
     BYVAL hDC AS DWORD _                               ' __in CONST HDC hDC
   , BYREF pSubRect AS RECT _                           ' __in CONST RECT *pSubRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ID2D1Factory interface
' IID = 06152247-6f50-465a-9245-118bfd3b6007
' The root factory interface for all of D2D's objects.
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ID2D1Factory $IID_ID2D1Factory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReloadSystemMetrics ( _                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopDpi ( _                             ' VTable offset = 16
     BYREF dpiX AS SINGLE _                             ' __out FLOAT *dpiX
   , BYREF dpiY AS SINGLE _                             ' __out FLOAT *dpiY
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRectangleGeometry ( _                   ' VTable offset = 20
     BYREF rectangle AS D2D1_RECT_F _                   ' __in CONST D2D1_RECT_F *rectangle
   , BYREF rectangleGeometry AS ID2D1RectangleGeometry _ '__out ID2D1RectangleGeometry **rectangleGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRoundedRectangleGeometry ( _            ' VTable offset = 24
     BYREF roundedRectangle AS D2D1_ROUNDED_RECT _      ' __in CONST D2D1_ROUNDED_RECT *roundedRectangle
   , BYREF roundedRectangleGeometry AS ID2D1RoundedRectangleGeometry _ ' __out ID2D1RoundedRectangleGeometry **roundedRectangleGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEllipseGeometry ( _                     ' VTable offset = 28
     BYREF ellipse AS D2D1_ELLIPSE _                    ' __in CONST D2D1_ELLIPSE *ellipse
   , BYREF ellipseGeometry AS ID2D1EllipseGeometry _    ' __out ID2D1EllipseGeometry **ellipseGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGeometryGroup ( _                       ' VTable offset = 32
     BYVAL fillMode AS DWORD _                          ' __in D2D1_FILL_MODE fillMode
   , BYREF geometries AS ID2D1Geometry _                ' __in ID2D1Geometry **geometries
   , BYVAL geometriesCount AS DWORD _                   ' __in UINT geometriesCount
   , BYREF geometryGroup AS ID2D1GeometryGroup _        ' __out ID2D1GeometryGroup **geometryGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTransformedGeometry ( _                 ' VTable offset = 36
     BYVAL sourceGeometry AS ID2D1Geometry _            ' __in ID2D1Geometry *sourceGeometry
   , BYREF transform AS D2D1_MATRIX_3X2_F _             ' __in CONST D2D1_MATRIX_3X2_F *transform
   , BYREF transformedGeometry AS ID2D1TransformedGeometry _ ' __out ID2D1TransformedGeometry **transformedGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePathGeometry ( _                        ' VTable offset = 40
     BYREF pathGeometry AS ID2D1PathGeometry _          ' __out ID2D1PathGeometry **pathGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStrokeStyle ( _                         ' VTable offset = 44
     BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES _ ' __in CONST D2D1_STROKE_STYLE_PROPERTIES *strokeStyleProperties
   , BYREF dashes AS SINGLE _                           ' __in CONST FLOAT *dashes
   , BYVAL dashesCount AS DWORD _                       ' __in UINT dashesCount
   , BYREF strokeStyle AS ID2D1StrokeStyle _            ' __out ID2D1StrokeStyle **strokeStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDrawingStateBlock ( _                   ' VTable offset = 48
     BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION _ ' __in_opt CONST D2D1_DRAWING_STATE_DESCRIPTION *drawingStateDescription
   , BYVAL textRenderingParams AS IDWriteRenderingParams _ ' __in_opt IDWriteRenderingParams *textRenderingParams
   , BYREF drawingStateBlock AS ID2D1DrawingStateBlock _ ' __out ID2D1DrawingStateBlock **drawingStateBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateWicBitmapRenderTarget ( _               ' VTable offset = 52
     BYVAL target AS IWICBitmap _                       ' __in IWICBitmap *target
   , BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   , BYREF renderTarget AS ID2D1RenderTarget _          ' __out ID2D1RenderTarget **renderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateHwndRenderTarget ( _                    ' VTable offset = 56
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ '__in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   , BYREF hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_HWND_RENDER_TARGET_PROPERTIES *hwndRenderTargetProperties
   , BYREF hwndRenderTarget AS ID2D1HwndRenderTarget _  ' __out ID2D1HwndRenderTarget **hwndRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDxgiSurfaceRenderTarget ( _             ' VTable offset = 60
     BYVAL dxgiSurface AS IDXGISurface _                ' __in IDXGISurface *dxgiSurface
   , BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   , BYREF renderTarget AS ID2D1RenderTarget _          ' __out ID2D1RenderTarget **renderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDCRenderTarget ( _                      ' VTable offset = 64
     BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES _ ' __in CONST D2D1_RENDER_TARGET_PROPERTIES *renderTargetProperties
   , BYREF dcRenderTarget AS ID2D1DCRenderTarget _      ' __out ID2D1DCRenderTarget **dcRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ========================================================================================
' Creates a factory object that can be used to create Direct2D resources.
' ========================================================================================
DECLARE FUNCTION D2D1CreateFactory IMPORT "D2d1.dll" ALIAS "D2D1CreateFactory" ( _
   BYVAL factoryType AS DWORD _                         ' __in D2D1_FACTORY_TYPE factoryType
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF pFactoryOptions AS D2D1_FACTORY_OPTIONS _      ' __in_opt CONST D2D1_FACTORY_OPTIONS *pFactoryOptions
 , BYREF ppIFactory AS IUnknown _                       ' __out void **ppIFactory
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Wrapper function for D2D1CreateFactory (saves some typing).
' ========================================================================================
FUNCTION D2D1CreateFactory2 (OPTIONAL BYVAL factoryType AS DWORD, BYREF ppIFactory AS IUnknown) AS LONG
   FUNCTION = D2D1CreateFactory(factoryType, $IID_ID2D1Factory, BYVAL %NULL, ppIFactory)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a rotation transformation that rotates by the specified angle about the specified point.
' ========================================================================================
DECLARE SUB D2D1MakeRotateMatrix IMPORT "D2d1.dll" ALIAS "D2D1MakeRotateMatrix" ( _
   BYVAL angle AS SINGLE _                              ' __in FLOAT angle
 , BYVAL center AS D2D1_POINT_2F _                      ' __in D2D1_POINT_2F center
 , BYREF matrix AS D2D1_MATRIX_3X2_F _                  ' __out D2D1_MATRIX_3X2_F *matrix
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' Creates a skew transformation that has the specified x-axis angle, y-axis angle, and center point.
' ========================================================================================
DECLARE SUB D2D1MakeSkewMatrix IMPORT "D2d1.dll" ALIAS "D2D1MakeSkewMatrix" ( _
   BYVAL angleX AS SINGLE _                             ' __in FLOAT angleX
 , BYVAL angleY AS SINGLE _                             ' __in FLOAT angleY
 , BYVAL center AS D2D1_POINT_2F _                      ' __in D2D1_POINT_2F center
 , BYREF matrix AS D2D1_MATRIX_3X2_F _                  ' __out D2D1_MATRIX_3X2_F *matrix
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' Indicates whether the specified matrix is invertible.
' ========================================================================================
DECLARE FUNCTION D2D1IsMatrixInvertible IMPORT "D2d1.dll" ALIAS "D2D1IsMatrixInvertible" ( _
   BYREF matrix AS D2D1_MATRIX_3X2_F _                  ' __in CONST D2D1_MATRIX_3X2_F *matrix
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' Attempts to invert the specified matrix.
' ========================================================================================
DECLARE FUNCTION D2D1InvertMatrix IMPORT "D2d1.dll" ALIAS "D2D1InvertMatrix" ( _
   BYREF matrix AS D2D1_MATRIX_3X2_F _                  ' __inout D2D1_MATRIX_3X2_F *matrix
 ) AS LONG                                              ' BOOL
' ========================================================================================

'#include <d2d1helper.h>
