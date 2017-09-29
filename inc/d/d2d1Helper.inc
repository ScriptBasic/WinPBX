' ########################################################################################
' Microsoft Windows
' File: D2D1helper.inc
' Contents: Helper methods over the D2D interfaces and APIs.
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D2D1HELPER_INC = 1

#INCLUDE ONCE "d2d1.inc"

%D2D1_AliceBlue            = &HF0F8FF???
%D2D1_AntiqueWhite         = &HFAEBD7???
%D2D1_Aqua                 = &H00FFFF???
%D2D1_Aquamarine           = &H7FFFD4???
%D2D1_Azure                = &HF0FFFF???
%D2D1_Beige                = &HF5F5DC???
%D2D1_Bisque               = &HFFE4C4???
%D2D1_Black                = &H000000???
%D2D1_BlanchedAlmond       = &HFFEBCD???
%D2D1_Blue                 = &H0000FF???
%D2D1_BlueViolet           = &H8A2BE2???
%D2D1_Brown                = &HA52A2A???
%D2D1_BurlyWood            = &HDEB887???
%D2D1_CadetBlue            = &H5F9EA0???
%D2D1_Chartreuse           = &H7FFF00???
%D2D1_Chocolate            = &HD2691E???
%D2D1_Coral                = &HFF7F50???
%D2D1_CornflowerBlue       = &H6495ED???
%D2D1_Cornsilk             = &HFFF8DC???
%D2D1_Crimson              = &HDC143C???
%D2D1_Cyan                 = &H00FFFF???
%D2D1_DarkBlue             = &H00008B???
%D2D1_DarkCyan             = &H008B8B???
%D2D1_DarkGoldenrod        = &HB8860B???
%D2D1_DarkGray             = &HA9A9A9???
%D2D1_DarkGreen            = &H006400???
%D2D1_DarkKhaki            = &HBDB76B???
%D2D1_DarkMagenta          = &H8B008B???
%D2D1_DarkOliveGreen       = &H556B2F???
%D2D1_DarkOrange           = &HFF8C00???
%D2D1_DarkOrchid           = &H9932CC???
%D2D1_DarkRed              = &H8B0000???
%D2D1_DarkSalmon           = &HE9967A???
%D2D1_DarkSeaGreen         = &H8FBC8F???
%D2D1_DarkSlateBlue        = &H483D8B???
%D2D1_DarkSlateGray        = &H2F4F4F???
%D2D1_DarkTurquoise        = &H00CED1???
%D2D1_DarkViolet           = &H9400D3???
%D2D1_DeepPink             = &HFF1493???
%D2D1_DeepSkyBlue          = &H00BFFF???
%D2D1_DimGray              = &H696969???
%D2D1_DodgerBlue           = &H1E90FF???
%D2D1_Firebrick            = &HB22222???
%D2D1_FloralWhite          = &HFFFAF0???
%D2D1_ForestGreen          = &H228B22???
%D2D1_Fuchsia              = &HFF00FF???
%D2D1_Gainsboro            = &HDCDCDC???
%D2D1_GhostWhite           = &HF8F8FF???
%D2D1_Gold                 = &HFFD700???
%D2D1_Goldenrod            = &HDAA520???
%D2D1_Gray                 = &H808080???
%D2D1_Green                = &H008000???
%D2D1_GreenYellow          = &HADFF2F???
%D2D1_Honeydew             = &HF0FFF0???
%D2D1_HotPink              = &HFF69B4???
%D2D1_IndianRed            = &HCD5C5C???
%D2D1_Indigo               = &H4B0082???
%D2D1_Ivory                = &HFFFFF0???
%D2D1_Khaki                = &HF0E68C???
%D2D1_Lavender             = &HE6E6FA???
%D2D1_LavenderBlush        = &HFFF0F5???
%D2D1_LawnGreen            = &H7CFC00???
%D2D1_LemonChiffon         = &HFFFACD???
%D2D1_LightBlue            = &HADD8E6???
%D2D1_LightCoral           = &HF08080???
%D2D1_LightCyan            = &HE0FFFF???
%D2D1_LightGoldenrodYellow = &HFAFAD2???
%D2D1_LightGreen           = &H90EE90???
%D2D1_LightGray            = &HD3D3D3???
%D2D1_LightPink            = &HFFB6C1???
%D2D1_LightSalmon          = &HFFA07A???
%D2D1_LightSeaGreen        = &H20B2AA???
%D2D1_LightSkyBlue         = &H87CEFA???
%D2D1_LightSlateGray       = &H778899???
%D2D1_LightSteelBlue       = &HB0C4DE???
%D2D1_LightYellow          = &HFFFFE0???
%D2D1_Lime                 = &H00FF00???
%D2D1_LimeGreen            = &H32CD32???
%D2D1_Linen                = &HFAF0E6???
%D2D1_Magenta              = &HFF00FF???
%D2D1_Maroon               = &H800000???
%D2D1_MediumAquamarine     = &H66CDAA???
%D2D1_MediumBlue           = &H0000CD???
%D2D1_MediumOrchid         = &HBA55D3???
%D2D1_MediumPurple         = &H9370DB???
%D2D1_MediumSeaGreen       = &H3CB371???
%D2D1_MediumSlateBlue      = &H7B68EE???
%D2D1_MediumSpringGreen    = &H00FA9A???
%D2D1_MediumTurquoise      = &H48D1CC???
%D2D1_MediumVioletRed      = &HC71585???
%D2D1_MidnightBlue         = &H191970???
%D2D1_MintCream            = &HF5FFFA???
%D2D1_MistyRose            = &HFFE4E1???
%D2D1_Moccasin             = &HFFE4B5???
%D2D1_NavajoWhite          = &HFFDEAD???
%D2D1_Navy                 = &H000080???
%D2D1_OldLace              = &HFDF5E6???
%D2D1_Olive                = &H808000???
%D2D1_OliveDrab            = &H6B8E23???
%D2D1_Orange               = &HFFA500???
%D2D1_OrangeRed            = &HFF4500???
%D2D1_Orchid               = &HDA70D6???
%D2D1_PaleGoldenrod        = &HEEE8AA???
%D2D1_PaleGreen            = &H98FB98???
%D2D1_PaleTurquoise        = &HAFEEEE???
%D2D1_PaleVioletRed        = &HDB7093???
%D2D1_PapayaWhip           = &HFFEFD5???
%D2D1_PeachPuff            = &HFFDAB9???
%D2D1_Peru                 = &HCD853F???
%D2D1_Pink                 = &HFFC0CB???
%D2D1_Plum                 = &HDDA0DD???
%D2D1_PowderBlue           = &HB0E0E6???
%D2D1_Purple               = &H800080???
%D2D1_Red                  = &HFF0000???
%D2D1_RosyBrown            = &HBC8F8F???
%D2D1_RoyalBlue            = &H4169E1???
%D2D1_SaddleBrown          = &H8B4513???
%D2D1_Salmon               = &HFA8072???
%D2D1_SandyBrown           = &HF4A460???
%D2D1_SeaGreen             = &H2E8B57???
%D2D1_SeaShell             = &HFFF5EE???
%D2D1_Sienna               = &HA0522D???
%D2D1_Silver               = &HC0C0C0???
%D2D1_SkyBlue              = &H87CEEB???
%D2D1_SlateBlue            = &H6A5ACD???
%D2D1_SlateGray            = &H708090???
%D2D1_Snow                 = &HFFFAFA???
%D2D1_SpringGreen          = &H00FF7F???
%D2D1_SteelBlue            = &H4682B4???
%D2D1_Tan                  = &HD2B48C???
%D2D1_Teal                 = &H008080???
%D2D1_Thistle              = &HD8BFD8???
%D2D1_Tomato               = &HFF6347???
%D2D1_Turquoise            = &H40E0D0???
%D2D1_Violet               = &HEE82EE???
%D2D1_Wheat                = &HF5DEB3???
%D2D1_White                = &HFFFFFF???
%D2D1_WhiteSmoke           = &HF5F5F5???
%D2D1_Yellow               = &HFFFF00???
%D2D1_YellowGreen          = &H9ACD32???

%sc_redShift   = 16???
%sc_greenShift = 8???
%sc_blueShift  = 0???

'static const UINT32 sc_redMask = 0xff << sc_redShift;
'static const UINT32 sc_greenMask = 0xff << sc_greenShift;
'static const UINT32 sc_blueMask = 0xff << sc_blueShift;

%sc_redMask = &H00FF0000???
%sc_greenMask = &H0000FF00???
%sc_blueMask = &H000000FF???

'#ifndef D2D_USE_C_DEFINITIONS

'namespace D2D1

' ########################################################################################
' Class CD2D1Helper
' Implemented interface: ID2D1Helper
' Inherited interface: IUnknown
' Note: This is not a literal translation, but an adaptation implemented as a class to
' be able to return structures.
' ########################################################################################

CLASS CD2D1Helper

   INTERFACE ID2D1Helper

   INHERIT IUnknown

'{
'    //
'    // Forward declared IdentityMatrix function to allow matrix class to use
'    // these constructors.
'    //
'    D2D1FORCEINLINE
'    D2D1_MATRIX_3X2_F
'    IdentityMatrix();

'    //
'    // The default trait type for objects in D2D is float.
'    //
'    template<typename Type>
'    struct TypeTraits
'    {
'        typedef D2D1_POINT_2F Point;
'        typedef D2D1_SIZE_F   Size;
'        typedef D2D1_RECT_F   Rect;
'    };

'    template<>
'    struct TypeTraits<UINT32>
'    {
'        typedef D2D1_POINT_2U Point;
'        typedef D2D1_SIZE_U   Size;
'        typedef D2D1_RECT_U   Rect;
'    };

'    static inline
'    FLOAT FloatMax()
'    {
'        #ifdef FLT_MAX
'            return FLT_MAX;
'        #else
'            return 3.402823466e+38F;
'        #endif
'    }

   ' =====================================================================================
   ' Returns the maximum floating-point value.
   ' =====================================================================================
   METHOD FloatMax () AS SINGLE
      METHOD = 3.402823466e+38
   END METHOD
   ' =====================================================================================

   ' //
   ' // Construction helpers
   ' //
'    template<typename Type>
'    D2D1FORCEINLINE
'    typename TypeTraits<Type>::Point
'    Point2(
'        Type x,
'        Type y
'        )
'    {
'        typename TypeTraits<Type>::Point point = { x, y };

'        return point;
'    }

'    D2D1FORCEINLINE
'    D2D1_POINT_2F
'    Point2F(
'        FLOAT x = 0.f,
'        FLOAT y = 0.f
'        )
'    {
'        return Point2<FLOAT>(x, y);
'    }

   ' =====================================================================================
   ' Creates a D2D1_POINT_2F structure that contains the specified x-coordinates and y-coordinates.
   ' =====================================================================================
   METHOD Point2F (OPTIONAL BYVAL x AS SINGLE, OPTIONAL BYVAL y AS SINGLE) AS D2D1_POINT_2F
      LOCAL p2f AS D2D1_POINT_2F
      p2f.x = x
      p2f.y = y
      METHOD = p2f
   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_POINT_2U
'    Point2U(
'        UINT32 x = 0,
'        UINT32 y = 0
'        )
'    {
'        return Point2<UINT32>(x, y);
'    }

   ' =====================================================================================
   ' Creates a D2D1_POINT_2F  structure that contains the specified x-coordinates and y-coordinates.
   ' =====================================================================================
   METHOD Point2U (OPTIONAL BYVAL x AS DWORD, OPTIONAL BYVAL y AS DWORD) AS D2D1_POINT_2U
      LOCAL p2u AS D2D1_POINT_2U
      p2u.x = x
      p2u.y = y
      METHOD = p2u
   END METHOD
   ' =====================================================================================

'    template<typename Type>
'    D2D1FORCEINLINE
'    typename TypeTraits<Type>::Size
'    Size(
'        Type width,
'        Type height
'        )
'    {
'        typename TypeTraits<Type>::Size size = { width, height };

'        return size;
'    }

'    D2D1FORCEINLINE
'    D2D1_SIZE_F
'    SizeF(
'        FLOAT width = 0.f,
'        FLOAT height = 0.f
'        )
'    {
'        return Size<FLOAT>(width, height);
'    }

   ' =====================================================================================
   ' Creates a D2D1_SIZE_F  structure that contains the specified width and height.
   ' =====================================================================================
   METHOD SizeF (OPTIONAL BYVAL nWidth AS SINGLE, OPTIONAL BYVAL nHeight AS SINGLE) AS D2D1_SIZE_F
      LOCAL sf AS D2D1_SIZE_F
      sf.width = nWidth
      sf.height = nHeight
      METHOD = sf
   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_SIZE_U
'    SizeU(
'        UINT32 width = 0,
'        UINT32 height = 0
'        )
'    {
'        return Size<UINT32>(width, height);
'    }

   ' =====================================================================================
   ' Creates a D2D1_SIZE_F  structure that contains the specified width and height.
   ' =====================================================================================
   METHOD SizeU (OPTIONAL BYVAL nWidth AS DWORD, OPTIONAL BYVAL nHeight AS DWORD) AS D2D1_SIZE_U
      LOCAL su AS D2D1_SIZE_U
      su.width = nWidth
      su.height = nHeight
      METHOD = su
   END METHOD
   ' =====================================================================================

'    template<typename Type>
'    D2D1FORCEINLINE
'    typename TypeTraits<Type>::Rect
'    Rect(
'        Type left,
'        Type top,
'        Type right,
'        Type bottom
'        )
'    {
'        typename TypeTraits<Type>::Rect rect = { left, top, right, bottom };

'        return rect;
'    }

'    D2D1FORCEINLINE
'    D2D1_RECT_F
'    RectF(
'        FLOAT left = 0.f,
'        FLOAT top = 0.f,
'        FLOAT right = 0.f,
'        FLOAT bottom = 0.f
'        )
'    {
'        return Rect<FLOAT>(left, top, right, bottom);
'    }

   ' =====================================================================================
   ' Creates a D2D1_RECT_F  structure that contains the specified dimensions.
   ' =====================================================================================
   METHOD RectF (OPTIONAL BYVAL nLeft AS SINGLE, OPTIONAL BYVAL nTop AS SINGLE, OPTIONAL BYVAL nRight AS SINGLE, OPTIONAL BYVAL nBottom AS SINGLE) AS D2D1_RECT_F
      LOCAL rf AS D2D1_RECT_F
      rf.left = nLeft
      rf.top = nTop
      rf.right = nRight
      rf.bottom = nBottom
      METHOD = rf
   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_RECT_U
'    RectU(
'        UINT32 left = 0,
'        UINT32 top = 0,
'        UINT32 right = 0,
'        UINT32 bottom = 0
'        )
'    {
'        return Rect<UINT32>(left, top, right, bottom);
'    }

   ' =====================================================================================
   ' Creates a D2D1_RECT_F structure that contains the specified dimensions.
   ' =====================================================================================
   METHOD RectU (OPTIONAL BYVAL nLeft AS DWORD, OPTIONAL BYVAL nTop AS DWORD, OPTIONAL BYVAL nRight AS DWORD, OPTIONAL BYVAL nBottom AS DWORD) AS D2D1_RECT_U
      LOCAL ru AS D2D1_RECT_U
      ru.left = nLeft
      ru.top = nTop
      ru.right = nRight
      ru.bottom = nBottom
      METHOD = ru
   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_RECT_F
'    InfiniteRect()
'    {
'        D2D1_RECT_F rect = { -FloatMax(), -FloatMax(), FloatMax(),  FloatMax() };

'        return rect;
'    }

   ' =====================================================================================
   ' Creates a rectangle that has its upper-left corner set to (negative infinity,
   ' negative infinity) and its lower-right corner set to (infinity, infinity).
   ' =====================================================================================
   METHOD InfiniteRect () AS D2D1_RECT_F
      LOCAL rf AS D2D1_RECT_F
      rf.left = -3.402823466e+38
      rf.top = -3.402823466e+38
      rf.right = 3.402823466e+38
      rf.bottom = 3.402823466e+38
      METHOD = rf
   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_ARC_SEGMENT
'    ArcSegment(
'        __in CONST D2D1_POINT_2F &point,
'        __in CONST D2D1_SIZE_F &size,
'        __in FLOAT rotationAngle,
'        __in D2D1_SWEEP_DIRECTION sweepDirection,
'        __in D2D1_ARC_SIZE arcSize
'        )
'    {
'        D2D1_ARC_SEGMENT arcSegment = { point, size, rotationAngle, sweepDirection, arcSize };

'        return arcSegment;
'    }

   ' =====================================================================================
   ' Creates a D2D1_ARC_SEGMENT structure.
   ' =====================================================================================
   METHOD ArcSegment ( _
      BYREF pf AS D2D1_POINT_2F, _
      BYREF sf AS D2D1_SIZE_F, _
      BYVAL rotationAngle AS SINGLE, _
      BYVAL sweepDirection AS DWORD, _
      BYVAL arcSize AS DWORD _
      ) AS D2D1_ARC_SEGMENT

      LOCAL arcseg AS D2D1_ARC_SEGMENT
      arcseg.point = pf
      arcseg.size = sf
      arcseg.rotationAngle = rotationAngle
      arcseg.sweepDirection = sweepDirection
      arcseg.arcSize = arcSize
      METHOD = arcseg

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_BEZIER_SEGMENT
'    BezierSegment(
'        __in CONST D2D1_POINT_2F &point1,
'        __in CONST D2D1_POINT_2F &point2,
'        __in CONST D2D1_POINT_2F &point3
'        )
'    {
'        D2D1_BEZIER_SEGMENT bezierSegment = { point1, point2, point3 };

'        return bezierSegment;
'    }

   ' =====================================================================================
   ' Creates a D2D1_BEZIER_SEGMENT structure.
   ' =====================================================================================
   METHOD BezierSegment ( _
      BYREF point1 AS D2D1_POINT_2F, _
      BYREF point2 AS D2D1_POINT_2F, _
      BYREF point3 AS D2D1_POINT_2F _
      ) AS D2D1_ARC_SEGMENT

      LOCAL bzseg AS D2D1_BEZIER_SEGMENT
      bzseg.point1 = point1
      bzseg.point2 = point2
      bzseg.point3 = point3
      METHOD = bzseg

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_ELLIPSE
'    Ellipse(
'        __in CONST D2D1_POINT_2F &center,
'        FLOAT radiusX,
'        FLOAT radiusY
'        )
'    {
'        D2D1_ELLIPSE ellipse;

'        ellipse.point = center;
'        ellipse.radiusX = radiusX;
'        ellipse.radiusY = radiusY;

'        return ellipse;
'    }

   ' =====================================================================================
   ' Creates a D2D1_ELLIPSE structure.
   ' =====================================================================================
   METHOD Ellipse ( _
      BYREF center AS D2D1_POINT_2F, _
      BYVAL radiusX AS SINGLE, _
      BYVAL radiusY AS SINGLE _
      ) AS D2D1_ELLIPSE

      LOCAL e AS D2D1_ELLIPSE
      e.point = center
      e.radiusX = radiusX
      e.radiusY = radiusY
      METHOD = e

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_ROUNDED_RECT
'    RoundedRect(
'        __in CONST D2D1_RECT_F &rect,
'        FLOAT radiusX,
'        FLOAT radiusY
'        )
'    {
'        D2D1_ROUNDED_RECT roundedRect;

'        roundedRect.rect = rect;
'        roundedRect.radiusX = radiusX;
'        roundedRect.radiusY = radiusY;

'        return roundedRect;
'    }

   ' =====================================================================================
   ' Creates a D2D1_ROUNDED_RECT structure.
   ' =====================================================================================
   METHOD RoundedRect ( _
      BYREF rc AS D2D1_RECT_F, _
      BYVAL radiusX AS SINGLE, _
      BYVAL radiusY AS SINGLE _
      ) AS D2D1_ROUNDED_RECT

      LOCAL r AS D2D1_ROUNDED_RECT
      r.rect = rc
      r.radiusX = radiusX
      r.radiusY = radiusY
      METHOD = r

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_BRUSH_PROPERTIES
'    BrushProperties(
'        __in FLOAT opacity = 1.0,
'        __in CONST D2D1_MATRIX_3X2_F &transform = D2D1::IdentityMatrix()
'        )
'    {
'        D2D1_BRUSH_PROPERTIES brushProperties;

'        brushProperties.opacity = opacity;
'        brushProperties.transform = transform;

'        return brushProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_BRUSH_PROPERTIES structure.
   ' =====================================================================================
   METHOD BrushProperties ( _
      OPTIONAL BYREF opacity AS SINGLE, _
      OPTIONAL BYREF transform AS D2D1_MATRIX_3X2_F _
      ) AS D2D1_BRUSH_PROPERTIES

      LOCAL bprop AS D2D1_BRUSH_PROPERTIES
      IF ISMISSING(opacity) THEN
         bprop.opacity = 1.0!
      ELSE
         bprop.opacity = opacity
      END IF
      IF ISMISSING(transform) THEN
         bprop.transform = ME.IdentityMatrix
      ELSE
         bprop.transform = transform
      END IF
      METHOD = bprop

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_GRADIENT_STOP
'    GradientStop(
'        FLOAT position,
'        __in CONST D2D1_COLOR_F &color
'        )
'    {
'        D2D1_GRADIENT_STOP gradientStop = { position, color };

'        return gradientStop;
'    }

   ' =====================================================================================
   ' Creates a D2D1_GRADIENT_STOP structure.
   ' =====================================================================================
   METHOD GradientStop ( _
      BYVAL position AS SINGLE, _
      BYREF clr AS D2D1_COLOR_F _
      ) AS D2D1_GRADIENT_STOP

      LOCAL gstop AS D2D1_GRADIENT_STOP
      gstop.position = position
      gstop.color = clr
      METHOD = gstop

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_QUADRATIC_BEZIER_SEGMENT
'    QuadraticBezierSegment(
'        __in CONST D2D1_POINT_2F &point1,
'        __in CONST D2D1_POINT_2F &point2
'        )
'    {
'        D2D1_QUADRATIC_BEZIER_SEGMENT quadraticBezier = { point1, point2 };

'        return quadraticBezier;
'    }

   ' =====================================================================================
   ' Creates a D2D1_QUADRATIC_BEZIER_SEGMENT structure.
   ' =====================================================================================
   METHOD QuadraticBezierSegment ( _
      BYREF point1 AS D2D1_POINT_2F, _
      BYREF point2 AS D2D1_POINT_2F _
      ) AS D2D1_QUADRATIC_BEZIER_SEGMENT

      LOCAL qbs AS D2D1_QUADRATIC_BEZIER_SEGMENT
      qbs.point1 = point1
      qbs.point2 = point2
      METHOD = qbs

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_STROKE_STYLE_PROPERTIES
'    StrokeStyleProperties(
'        D2D1_CAP_STYLE startCap = D2D1_CAP_STYLE_FLAT,
'        D2D1_CAP_STYLE endCap = D2D1_CAP_STYLE_FLAT,
'        D2D1_CAP_STYLE dashCap = D2D1_CAP_STYLE_FLAT,
'        D2D1_LINE_JOIN lineJoin = D2D1_LINE_JOIN_MITER,
'        FLOAT miterLimit = 10.0f,
'        D2D1_DASH_STYLE dashStyle = D2D1_DASH_STYLE_SOLID,
'        FLOAT dashOffset = 0.0f
'        )
'    {
'        D2D1_STROKE_STYLE_PROPERTIES strokeStyleProperties;

'        strokeStyleProperties.startCap = startCap;
'        strokeStyleProperties.endCap = endCap;
'        strokeStyleProperties.dashCap = dashCap;
'        strokeStyleProperties.lineJoin = lineJoin;
'        strokeStyleProperties.miterLimit = miterLimit;
'        strokeStyleProperties.dashStyle = dashStyle;
'        strokeStyleProperties.dashOffset = dashOffset;

'        return strokeStyleProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_STROKE_STYLE_PROPERTIES structure.
   ' =====================================================================================
   METHOD StrokeStyleProperties ( _
      OPTIONAL BYVAL startCap AS DWORD, _
      OPTIONAL BYVAL endCap AS DWORD, _
      OPTIONAL BYVAL dashCap AS DWORD, _
      OPTIONAL BYVAL lineJoin AS DWORD, _
      OPTIONAL BYREF miterLimit AS SINGLE, _
      OPTIONAL BYVAL dashStyle AS DWORD, _
      OPTIONAL BYVAL dashOffset AS SINGLE _
      ) AS D2D1_STROKE_STYLE_PROPERTIES

      LOCAL ssp AS D2D1_STROKE_STYLE_PROPERTIES
      ssp.startCap = startCap
      ssp.endCap = endCap
      ssp.dashCap = dashCap
      ssp.lineJoin = lineJoin
      IF ISMISSING(miterLimit) THEN
         ssp.miterLimit = 10.0!
      ELSE
         ssp.miterLimit = miterLimit
      END IF
      ssp.dashStyle = dashStyle
      ssp.dashOffset = dashOffset
      METHOD = ssp

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_BITMAP_BRUSH_PROPERTIES
'    BitmapBrushProperties(
'        D2D1_EXTEND_MODE extendModeX = D2D1_EXTEND_MODE_CLAMP,
'        D2D1_EXTEND_MODE extendModeY = D2D1_EXTEND_MODE_CLAMP,
'        D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
'        )
'    {
'        D2D1_BITMAP_BRUSH_PROPERTIES bitmapBrushProperties;

'        bitmapBrushProperties.extendModeX = extendModeX;
'        bitmapBrushProperties.extendModeY = extendModeY;
'        bitmapBrushProperties.interpolationMode = interpolationMode;

'        return bitmapBrushProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_BITMAP_BRUSH_PROPERTIES structure.
   ' =====================================================================================
   METHOD BitmapBrushProperties ( _
      OPTIONAL BYVAL extendModeX AS DWORD, _
      OPTIONAL BYVAL extendModeY AS DWORD, _
      OPTIONAL BYREF interpolationMode AS DWORD _
      ) AS D2D1_BITMAP_BRUSH_PROPERTIES

      LOCAL bbp AS D2D1_BITMAP_BRUSH_PROPERTIES
      bbp.extendModeX = extendModeX
      bbp.extendModeY = extendModeY
      IF ISMISSING(interpolationMode) THEN
         bbp.interpolationMode = %D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
      ELSE
         bbp.interpolationMode = interpolationMode
      END IF
      METHOD = bbp

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
'    LinearGradientBrushProperties(
'        __in CONST D2D1_POINT_2F &startPoint,
'        __in CONST D2D1_POINT_2F &endPoint
'        )
'    {
'        D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES linearGradientBrushProperties;

'        linearGradientBrushProperties.startPoint = startPoint;
'        linearGradientBrushProperties.endPoint = endPoint;

'        return linearGradientBrushProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES structure.
   ' =====================================================================================
   METHOD LinearGradientBrushProperties ( _
      BYREF startPoint AS D2D1_POINT_2F, _
      BYREF endPoint AS D2D1_POINT_2F _
      ) AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES

      LOCAL lgbp AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
      lgbp.startPoint = startPoint
      lgbp.endPoint = endPoint
      METHOD = lgbp

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
'    RadialGradientBrushProperties(
'        __in CONST D2D1_POINT_2F &center,
'        __in CONST D2D1_POINT_2F &gradientOriginOffset,
'        FLOAT radiusX,
'        FLOAT radiusY
'        )
'    {
'        D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES radialGradientBrushProperties;

'        radialGradientBrushProperties.center = center;
'        radialGradientBrushProperties.gradientOriginOffset = gradientOriginOffset;
'        radialGradientBrushProperties.radiusX = radiusX;
'        radialGradientBrushProperties.radiusY = radiusY;

'        return radialGradientBrushProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES structure.
   ' =====================================================================================
   METHOD RadialGradientBrushProperties ( _
      BYREF center AS D2D1_POINT_2F, _
      BYREF gradientOriginOffset AS D2D1_POINT_2F, _
      BYVAL radiusX AS SINGLE, _
      BYVAL radiusY AS SINGLE _
      ) AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES

      LOCAL rgbp AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
      rgbp.center = center
      rgbp.gradientOriginOffset = gradientOriginOffset
      rgbp.radiusX = radiusX
      rgbp.radiusY = radiusY
      METHOD = rgbp

   END METHOD
   ' =====================================================================================

   ' //
   ' // PixelFormat
   ' //
'    D2D1FORCEINLINE
'    D2D1_PIXEL_FORMAT
'    PixelFormat(
'        __in DXGI_FORMAT dxgiFormat = DXGI_FORMAT_UNKNOWN,
'        __in D2D1_ALPHA_MODE alphaMode = D2D1_ALPHA_MODE_UNKNOWN
'        )
'    {
'        D2D1_PIXEL_FORMAT pixelFormat;

'        pixelFormat.format = dxgiFormat;
'        pixelFormat.alphaMode = alphaMode;

'        return pixelFormat;
'    }

   ' =====================================================================================
   ' Creates a D2D1_PIXEL_FORMAT structure.
   ' Note: Parameters declared as optional taking advantage that the default values,
   ' DXGI_FORMAT_UNKNOWN and D2D1_ALPHA_MODE_UNKNOWN are both 0.
   ' =====================================================================================
   METHOD PixelFormat ( _
      OPTIONAL BYVAL dxgiFormat AS DWORD, _
      OPTIONAL BYVAL alphaMode AS DWORD _
      ) AS D2D1_PIXEL_FORMAT

      LOCAL pxf AS D2D1_PIXEL_FORMAT
      pxf.format = dxgiFormat
      pxf.alphaMode = alphaMode
      METHOD = pxf

   END METHOD
   ' =====================================================================================

   ' //
   ' // Bitmaps
   ' //
'    D2D1FORCEINLINE
'    D2D1_BITMAP_PROPERTIES
'    BitmapProperties(
'        CONST D2D1_PIXEL_FORMAT &pixelFormat = D2D1::PixelFormat(),
'        FLOAT dpiX = 96.0f,
'        FLOAT dpiY = 96.0f
'        )
'    {
'        D2D1_BITMAP_PROPERTIES bitmapProperties;

'        bitmapProperties.pixelFormat = pixelFormat;
'        bitmapProperties.dpiX = dpiX;
'        bitmapProperties.dpiY = dpiY;

'        return bitmapProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_BITMAP_PROPERTIES structure.
   ' =====================================================================================
   METHOD BitmapProperties ( _
      OPTIONAL BYREF pixelFormat AS D2D1_PIXEL_FORMAT, _
      OPTIONAL BYREF dpiX AS SINGLE, _
      OPTIONAL BYREF dpiY AS SINGLE _
      ) AS D2D1_BITMAP_PROPERTIES

      LOCAL bmp AS D2D1_BITMAP_PROPERTIES
      IF ISMISSING(pixelFormat) THEN
         bmp.pixelFormat = ME.pixelFormat
      ELSE
         bmp.pixelFormat = pixelFormat
      END IF
      IF ISMISSING(dpiX) THEN
         bmp.dpiX = 96.0!
      ELSE
         bmp.dpiX = dpiX
      END IF
      IF ISMISSING(dpiY) THEN
         bmp.dpiY = 96.0!
      ELSE
         bmp.dpiY = dpiY
      END IF
      METHOD = bmp

   END METHOD
   ' =====================================================================================

   ' //
   ' // Render Targets
   ' //
'    D2D1FORCEINLINE
'    D2D1_RENDER_TARGET_PROPERTIES
'    RenderTargetProperties(
'        D2D1_RENDER_TARGET_TYPE type =  D2D1_RENDER_TARGET_TYPE_DEFAULT,
'        __in CONST D2D1_PIXEL_FORMAT &pixelFormat = D2D1::PixelFormat(),
'        FLOAT dpiX = 0.0,
'        FLOAT dpiY = 0.0,
'        D2D1_RENDER_TARGET_USAGE usage = D2D1_RENDER_TARGET_USAGE_NONE,
'        D2D1_FEATURE_LEVEL  minLevel = D2D1_FEATURE_LEVEL_DEFAULT
'        )
'    {
'        D2D1_RENDER_TARGET_PROPERTIES renderTargetProperties;

'        renderTargetProperties.type = type;
'        renderTargetProperties.pixelFormat = pixelFormat;
'        renderTargetProperties.dpiX = dpiX;
'        renderTargetProperties.dpiY = dpiY;
'        renderTargetProperties.usage = usage;
'        renderTargetProperties.minLevel = minLevel;

'        return renderTargetProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_RENDER_TARGET_PROPERTIES structure.
   ' =====================================================================================
   METHOD RenderTargetProperties ( _
      OPTIONAL BYVAL nType AS DWORD, _
      OPTIONAL BYREF pixelFormat AS D2D1_PIXEL_FORMAT, _
      OPTIONAL BYVAL dpiX AS SINGLE, _
      OPTIONAL BYVAL dpiY AS SINGLE, _
      OPTIONAL BYVAL usage AS DWORD, _
      OPTIONAL BYVAL minLevel AS DWORD _
      ) AS D2D1_RENDER_TARGET_PROPERTIES

      LOCAL rtp AS D2D1_RENDER_TARGET_PROPERTIES
      rtp.type = nType
      IF ISMISSING(pixelFormat) THEN
         rtp.pixelFormat = ME.pixelFormat
      ELSE
         rtp.pixelFormat = pixelFormat
      END IF
      rtp.dpiX = dpiX
      rtp.dpiY = dpiY
      rtp.usage = usage
      rtp.minLevel = minLevel
      METHOD = rtp

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_HWND_RENDER_TARGET_PROPERTIES
'    HwndRenderTargetProperties(
'        __in HWND hwnd,
'        __in D2D1_SIZE_U pixelSize = D2D1::Size(static_cast<UINT>(0), static_cast<UINT>(0)),
'        __in D2D1_PRESENT_OPTIONS presentOptions = D2D1_PRESENT_OPTIONS_NONE
'        )
'    {
'        D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRenderTargetProperties;

'        hwndRenderTargetProperties.hwnd = hwnd;
'        hwndRenderTargetProperties.pixelSize = pixelSize;
'        hwndRenderTargetProperties.presentOptions = presentOptions;

'        return hwndRenderTargetProperties;
'    }

   ' =====================================================================================
   ' Creates a D2D1_HWND_RENDER_TARGET_PROPERTIES structure.
   ' =====================================================================================
   METHOD HwndRenderTargetProperties ( _
      BYVAL hwnd AS DWORD, _
      OPTIONAL BYREF pixelSize AS D2D1_SIZE_U, _
      OPTIONAL BYVAL presentOptions AS DWORD _
      ) AS D2D1_HWND_RENDER_TARGET_PROPERTIES

      LOCAL hrtp AS D2D1_HWND_RENDER_TARGET_PROPERTIES
      hrtp.hwnd = hwnd
      IF ISMISSING(pixelSize) THEN
         ' Do nothing. The members of hrtp.pixelSize are already initialized to 0.
      ELSE
         hrtp.pixelSize = pixelSize
      END IF
      hrtp.presentOptions = presentOptions
      METHOD = hrtp

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_LAYER_PARAMETERS
'    LayerParameters(
'        __in CONST D2D1_RECT_F &contentBounds = D2D1::InfiniteRect(),
'        __in_opt ID2D1Geometry *geometricMask = NULL,
'        D2D1_ANTIALIAS_MODE maskAntialiasMode = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
'        D2D1_MATRIX_3X2_F maskTransform = D2D1::IdentityMatrix(),
'        FLOAT opacity = 1.0,
'        __in_opt ID2D1Brush *opacityBrush = NULL,
'        D2D1_LAYER_OPTIONS layerOptions = D2D1_LAYER_OPTIONS_NONE
'        )
'    {
'        D2D1_LAYER_PARAMETERS layerParameters = { 0 };

'        layerParameters.contentBounds = contentBounds;
'        layerParameters.geometricMask = geometricMask;
'        layerParameters.maskAntialiasMode = maskAntialiasMode;
'        layerParameters.maskTransform = maskTransform;
'        layerParameters.opacity = opacity;
'        layerParameters.opacityBrush = opacityBrush;
'        layerParameters.layerOptions = layerOptions;

'        return layerParameters;
'    }

   ' =====================================================================================
   ' Creates a D2D1_LAYER_PARAMETERS structure.
   ' =====================================================================================
   METHOD LayerParameters ( _
      OPTIONAL BYREF contentBounds AS D2D1_RECT_F, _
      OPTIONAL BYVAL geometricMask AS ID2D1Geometry, _
      OPTIONAL BYVAL maskAntialiasMode AS DWORD, _
      OPTIONAL BYREF maskTransform AS D2D1_MATRIX_3X2_F, _
      OPTIONAL BYREF opacity AS SINGLE, _
      OPTIONAL BYVAL opacityBrush AS ID2D1Brush, _
      OPTIONAL BYVAL layerOptions AS DWORD _
      ) AS D2D1_LAYER_PARAMETERS

      LOCAL lprms AS D2D1_LAYER_PARAMETERS
      IF ISMISSING(contentBounds) THEN
         lprms.contentBounds = ME.InfiniteRect
      ELSE
         lprms.contentBounds = contentBounds
      END IF
      lprms.geometricMask = OBJPTR(geometricMask)
      lprms.maskAntialiasMode = maskAntialiasMode
      IF ISMISSING(maskTransform) THEN
         lprms.maskTransform = ME.IdentityMatrix
      ELSE
         lprms.maskTransform = maskTransform
      END IF
      IF ISMISSING(opacity) THEN
         lprms.opacity = 1.0!
      ELSE
         lprms.opacity = opacity
      END IF
      lprms.opacityBrush = OBJPTR(opacityBrush)
      lprms.layerOptions = layerOptions
      METHOD = lprms

   END METHOD
   ' =====================================================================================

'    D2D1FORCEINLINE
'    D2D1_DRAWING_STATE_DESCRIPTION
'    DrawingStateDescription(
'        D2D1_ANTIALIAS_MODE antialiasMode = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
'        D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode = D2D1_TEXT_ANTIALIAS_MODE_DEFAULT,
'        D2D1_TAG tag1 = 0,
'        D2D1_TAG tag2 = 0,
'        __in const D2D1_MATRIX_3X2_F &transform = D2D1::IdentityMatrix()
'        )
'    {
'        D2D1_DRAWING_STATE_DESCRIPTION drawingStateDescription;

'        drawingStateDescription.antialiasMode = antialiasMode;
'        drawingStateDescription.textAntialiasMode = textAntialiasMode;
'        drawingStateDescription.tag1 = tag1;
'        drawingStateDescription.tag2 = tag2;
'        drawingStateDescription.transform = transform;

'        return drawingStateDescription;
'    }

   ' =====================================================================================
   ' Creates a D2D1_DRAWING_STATE_DESCRIPTION structure.
   ' =====================================================================================
   METHOD DrawingStateDescription ( _
      BYVAL antialiasMode AS DWORD, _
      BYVAL textAntialiasMode AS DWORD, _
      BYVAL tag1 AS QUAD, _
      BYVAL tag2 AS QUAD, _
      BYREF transform AS D2D1_MATRIX_3X2_F _
      ) AS D2D1_DRAWING_STATE_DESCRIPTION

      LOCAL dsd AS D2D1_DRAWING_STATE_DESCRIPTION
      dsd.antialiasMode = antialiasMode
      dsd.textAntialiasMode = textAntialiasMode
      dsd.tag1 = tag1
      dsd.tag2 = tag2
      IF ISMISSING(transform) THEN
         dsd.transform = ME.IdentityMatrix
      ELSE
         dsd.transform = transform
      END IF
      METHOD = dsd

   END METHOD
   ' =====================================================================================

   ' //
   ' // Colors, this enum defines a set of predefined colors.
   ' //

'    class ColorF : public D2D1_COLOR_F
'    {
'    public:

'        enum Enum
'        {
'            AliceBlue = 0xF0F8FF,
'            AntiqueWhite = 0xFAEBD7,
'            Aqua = 0x00FFFF,
'            Aquamarine = 0x7FFFD4,
'            Azure = 0xF0FFFF,
'            Beige = 0xF5F5DC,
'            Bisque = 0xFFE4C4,
'            Black = 0x000000,
'            BlanchedAlmond = 0xFFEBCD,
'            Blue = 0x0000FF,
'            BlueViolet = 0x8A2BE2,
'            Brown = 0xA52A2A,
'            BurlyWood = 0xDEB887,
'            CadetBlue = 0x5F9EA0,
'            Chartreuse = 0x7FFF00,
'            Chocolate = 0xD2691E,
'            Coral = 0xFF7F50,
'            CornflowerBlue = 0x6495ED,
'            Cornsilk = 0xFFF8DC,
'            Crimson = 0xDC143C,
'            Cyan = 0x00FFFF,
'            DarkBlue = 0x00008B,
'            DarkCyan = 0x008B8B,
'            DarkGoldenrod = 0xB8860B,
'            DarkGray = 0xA9A9A9,
'            DarkGreen = 0x006400,
'            DarkKhaki = 0xBDB76B,
'            DarkMagenta = 0x8B008B,
'            DarkOliveGreen = 0x556B2F,
'            DarkOrange = 0xFF8C00,
'            DarkOrchid = 0x9932CC,
'            DarkRed = 0x8B0000,
'            DarkSalmon = 0xE9967A,
'            DarkSeaGreen = 0x8FBC8F,
'            DarkSlateBlue = 0x483D8B,
'            DarkSlateGray = 0x2F4F4F,
'            DarkTurquoise = 0x00CED1,
'            DarkViolet = 0x9400D3,
'            DeepPink = 0xFF1493,
'            DeepSkyBlue = 0x00BFFF,
'            DimGray = 0x696969,
'            DodgerBlue = 0x1E90FF,
'            Firebrick = 0xB22222,
'            FloralWhite = 0xFFFAF0,
'            ForestGreen = 0x228B22,
'            Fuchsia = 0xFF00FF,
'            Gainsboro = 0xDCDCDC,
'            GhostWhite = 0xF8F8FF,
'            Gold = 0xFFD700,
'            Goldenrod = 0xDAA520,
'            Gray = 0x808080,
'            Green = 0x008000,
'            GreenYellow = 0xADFF2F,
'            Honeydew = 0xF0FFF0,
'            HotPink = 0xFF69B4,
'            IndianRed = 0xCD5C5C,
'            Indigo = 0x4B0082,
'            Ivory = 0xFFFFF0,
'            Khaki = 0xF0E68C,
'            Lavender = 0xE6E6FA,
'            LavenderBlush = 0xFFF0F5,
'            LawnGreen = 0x7CFC00,
'            LemonChiffon = 0xFFFACD,
'            LightBlue = 0xADD8E6,
'            LightCoral = 0xF08080,
'            LightCyan = 0xE0FFFF,
'            LightGoldenrodYellow = 0xFAFAD2,
'            LightGreen = 0x90EE90,
'            LightGray = 0xD3D3D3,
'            LightPink = 0xFFB6C1,
'            LightSalmon = 0xFFA07A,
'            LightSeaGreen = 0x20B2AA,
'            LightSkyBlue = 0x87CEFA,
'            LightSlateGray = 0x778899,
'            LightSteelBlue = 0xB0C4DE,
'            LightYellow = 0xFFFFE0,
'            Lime = 0x00FF00,
'            LimeGreen = 0x32CD32,
'            Linen = 0xFAF0E6,
'            Magenta = 0xFF00FF,
'            Maroon = 0x800000,
'            MediumAquamarine = 0x66CDAA,
'            MediumBlue = 0x0000CD,
'            MediumOrchid = 0xBA55D3,
'            MediumPurple = 0x9370DB,
'            MediumSeaGreen = 0x3CB371,
'            MediumSlateBlue = 0x7B68EE,
'            MediumSpringGreen = 0x00FA9A,
'            MediumTurquoise = 0x48D1CC,
'            MediumVioletRed = 0xC71585,
'            MidnightBlue = 0x191970,
'            MintCream = 0xF5FFFA,
'            MistyRose = 0xFFE4E1,
'            Moccasin = 0xFFE4B5,
'            NavajoWhite = 0xFFDEAD,
'            Navy = 0x000080,
'            OldLace = 0xFDF5E6,
'            Olive = 0x808000,
'            OliveDrab = 0x6B8E23,
'            Orange = 0xFFA500,
'            OrangeRed = 0xFF4500,
'            Orchid = 0xDA70D6,
'            PaleGoldenrod = 0xEEE8AA,
'            PaleGreen = 0x98FB98,
'            PaleTurquoise = 0xAFEEEE,
'            PaleVioletRed = 0xDB7093,
'            PapayaWhip = 0xFFEFD5,
'            PeachPuff = 0xFFDAB9,
'            Peru = 0xCD853F,
'            Pink = 0xFFC0CB,
'            Plum = 0xDDA0DD,
'            PowderBlue = 0xB0E0E6,
'            Purple = 0x800080,
'            Red = 0xFF0000,
'            RosyBrown = 0xBC8F8F,
'            RoyalBlue = 0x4169E1,
'            SaddleBrown = 0x8B4513,
'            Salmon = 0xFA8072,
'            SandyBrown = 0xF4A460,
'            SeaGreen = 0x2E8B57,
'            SeaShell = 0xFFF5EE,
'            Sienna = 0xA0522D,
'            Silver = 0xC0C0C0,
'            SkyBlue = 0x87CEEB,
'            SlateBlue = 0x6A5ACD,
'            SlateGray = 0x708090,
'            Snow = 0xFFFAFA,
'            SpringGreen = 0x00FF7F,
'            SteelBlue = 0x4682B4,
'            Tan = 0xD2B48C,
'            Teal = 0x008080,
'            Thistle = 0xD8BFD8,
'            Tomato = 0xFF6347,
'            Turquoise = 0x40E0D0,
'            Violet = 0xEE82EE,
'            Wheat = 0xF5DEB3,
'            White = 0xFFFFFF,
'            WhiteSmoke = 0xF5F5F5,
'            Yellow = 0xFFFF00,
'            YellowGreen = 0x9ACD32,
'        };

      '  //
      '  // Construct a color, note that the alpha value from the "rgb" component
      '  // is never used.
      '  //
'        D2D1FORCEINLINE
'        ColorF(
'            UINT32 rgb,
'            FLOAT a = 1.0
'            )
'        {
'            Init(rgb, a);
'        }

   ' =====================================================================================
   ' Creates a D2D1_COLOR_F structure that contains the specified RGB and alpha values.
   ' =====================================================================================
   METHOD ColorF_2 ( _
      BYVAL urgb AS DWORD, _
      OPTIONAL BYREF a AS SINGLE _
      ) AS D2D1_COLOR_F

      IF ISMISSING(a) THEN
         METHOD = ME.InitColorF(urgb, 1.0!)
      ELSE
         METHOD = ME.InitColorF(urgb, a)
      END IF

   END METHOD
   ' =====================================================================================

'        D2D1FORCEINLINE
'        ColorF(
'            Enum knownColor,
'            FLOAT a = 1.0
'            )
'        {
'            Init(knownColor, a);
'        }

   ' =====================================================================================
   ' Creates a D2D1_COLOR_F structure from the specified known color name and alpha values.
   ' =====================================================================================
   METHOD ColorF_3 ( _
      BYVAL knownColor AS DWORD, _
      OPTIONAL BYREF a AS SINGLE _
      ) AS D2D1_COLOR_F

      IF ISMISSING(a) THEN
         METHOD = ME.InitColorF(knownColor, 1.0!)
      ELSE
         METHOD = ME.InitColorF(knownColor, a)
      END IF

   END METHOD
   ' =====================================================================================

'        D2D1FORCEINLINE
'        ColorF(
'            FLOAT r,
'            FLOAT g,
'            FLOAT b,
'            FLOAT a = 1.0
'            )
'        {
'            this->r = r;
'            this->g = g;
'            this->b = b;
'            this->a = a;
'        }

   ' =====================================================================================
   ' Creates a D2D1_COLOR_F structure that contains the specified red, green, blue, and alpha values.
   ' =====================================================================================
   METHOD ColorF ( _
      BYVAL r AS SINGLE, _
      BYVAL g AS SINGLE, _
      BYVAL b AS SINGLE, _
      OPTIONAL BYREF a AS SINGLE _
      ) AS D2D1_COLOR_F

      LOCAL cf AS D2D1_COLOR_F
      cf.r = r
      cf.g = g
      cf.b = b
      IF ISMISSING(a) THEN
         cf.a = 1.0!
      ELSE
         cf.a = a
      END IF
      METHOD = cf

   END METHOD
   ' =====================================================================================

'    private:

'        D2D1FORCEINLINE
'        void
'        Init(
'            UINT32 rgb,
'            FLOAT a
'            )
'        {
'            this->r = static_cast<FLOAT>((rgb & sc_redMask) >> sc_redShift) / 255.f;
'            this->g = static_cast<FLOAT>((rgb & sc_greenMask) >> sc_greenShift) / 255.f;
'            this->b = static_cast<FLOAT>((rgb & sc_blueMask) >> sc_blueShift) / 255.f;
'            this->a = a;
'        }

'        static const UINT32 sc_redShift   = 16;
'        static const UINT32 sc_greenShift = 8;
'        static const UINT32 sc_blueShift  = 0;

'        static const UINT32 sc_redMask = 0xff << sc_redShift;
'        static const UINT32 sc_greenMask = 0xff << sc_greenShift;
'        static const UINT32 sc_blueMask = 0xff << sc_blueShift;
'    };

   ' =====================================================================================
   ' Helper method for ColorF_2 and ColorF_3.
   ' =====================================================================================
   METHOD InitColorF( _
      BYVAL urgb AS DWORD, _
      BYVAL a AS SINGLE _
      ) AS D2D1_COLOR_F

      LOCAL cf AS D2D1_COLOR_F
      LOCAL x AS DWORD
      x = urgb AND %sc_redMask
      SHIFT RIGHT x, %sc_redShift
      cf.r = x / 255.0!
      x = urgb AND %sc_greenMask
      SHIFT RIGHT x, %sc_greenShift
      cf.g = x / 255.0!
      x = urgb AND %sc_blueMask
      SHIFT RIGHT x, %sc_blueShift
      cf.b = x / 255.0!
      cf.a = a
      METHOD = cf

   END METHOD
   ' =====================================================================================


'    class Matrix3x2F : public D2D1_MATRIX_3X2_F
'    {
'    public:

'        D2D1FORCEINLINE
'        Matrix3x2F(
'            FLOAT _11,
'            FLOAT _12,
'            FLOAT _21,
'            FLOAT _22,
'            FLOAT _31,
'            FLOAT _32
'            )
'        {
'            this->_11 = _11;
'            this->_12 = _12;
'            this->_21 = _21;
'            this->_22 = _22;
'            this->_31 = _31;
'            this->_32 = _32;
'        }

   ' =====================================================================================
   ' Creates a D2D_MATRIX_3X2_F structure that contains the specified values.
   ' =====================================================================================
   METHOD Matrix3x2F ( _
      BYVAL m11 AS SINGLE, _
      BYVAL m12 AS SINGLE, _
      BYVAL m21 AS SINGLE, _
      BYVAL m22 AS SINGLE, _
      BYVAL m31 AS SINGLE, _
      BYVAL m32 AS SINGLE _
      ) AS D2D_MATRIX_3X2_F

      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = m11
      m.m12 = m12
      m.m21 = m21
      m.m22 = m22
      m.m31 = m31
      m.m32 = m32
      METHOD = m

   END METHOD
   ' =====================================================================================

'        //
'        // Creates an identity matrix
'        //
'        D2D1FORCEINLINE
'        Matrix3x2F(
'            )
'        {
'        }

      ' Simply declare a variable as D2D_MATRIX_3X2_F in your code.

      '  //
      '  // Named quasi-constructors
      '  //
'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Identity()
'        {
'            Matrix3x2F identity;

'            identity._11 = 1.f;
'            identity._12 = 0.f;
'            identity._21 = 0.f;
'            identity._22 = 1.f;
'            identity._31 = 0.f;
'            identity._32 = 0.f;

'            return identity;
'        }

   ' =====================================================================================
   ' Creates an identity matrix.
   ' =====================================================================================
   METHOD IdentityMatrix () AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = 1.0!
      m.m12 = 0.0!
      m.m21 = 0.0!
      m.m22 = 1.0!
      m.m31 = 0.0!
      m.m32 = 0.0!
      METHOD = m
   END METHOD
   ' =====================================================================================

'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Translation(
'            D2D1_SIZE_F size
'            )
'        {
'            Matrix3x2F translation;

'            translation._11 = 1.0; translation._12 = 0.0;
'            translation._21 = 0.0; translation._22 = 1.0;
'            translation._31 = size.width; translation._32 = size.height;

'            return translation;
'        }

   ' =====================================================================================
   ' Creates a translation transformation that has the specified x and y displacements.
   ' =====================================================================================
   METHOD MatrixTranslation_2 (BYREF tsize AS D2D1_SIZE_F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = 1.0!
      m.m12 = 0.0!
      m.m21 = 0.0!
      m.m22 = 1.0!
      m.m31 = tsize.width
      m.m32 = tsize.height
      METHOD = m
   END METHOD
   ' =====================================================================================

'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Translation(
'            FLOAT x,
'            FLOAT y
'            )
'        {
'            return Translation(SizeF(x, y));
'        }

   ' =====================================================================================
   ' Creates a translation transformation that has the specified x and y displacements.
   ' =====================================================================================
   METHOD MatrixTranslation (BYVAL x AS SINGLE, BYVAL y AS SINGLE) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = 1.0!
      m.m12 = 0.0!
      m.m21 = 0.0!
      m.m22 = 1.0!
      m.m31 = x
      m.m32 = y
      METHOD = m
   END METHOD
   ' =====================================================================================


'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Scale(
'            D2D1_SIZE_F size,
'            D2D1_POINT_2F center = D2D1::Point2F()
'            )
'        {
'            Matrix3x2F scale;

'            scale._11 = size.width; scale._12 = 0.0;
'            scale._21 = 0.0; scale._22 = size.height;
'            scale._31 = center.x - size.width * center.x;
'            scale._32 = center.y - size.height * center.y;

'            return scale;
'        }

   ' =====================================================================================
   ' Creates a scale transformation that has the specified scale factors and center point.
   ' =====================================================================================
   METHOD MatrixScale_2 (BYREF tsize AS D2D1_SIZE_F, OPTIONAL BYREF center AS D2D1_POINT_2F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = tsize.width
      m.m12 = 0.0!
      m.m21 = 0.0!
      m.m22 = tsize.height
      IF ISMISSING(center) THEN
         ' Do nothing beause the results are 0
      ELSE
         m.m31 = center.x - tsize.width * center.x
         m.m32 = center.y - tsize.height * center.y
      END IF
      METHOD = m
   END METHOD
   ' =====================================================================================

'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Scale(
'            FLOAT x,
'            FLOAT y,
'            D2D1_POINT_2F center = D2D1::Point2F()
'            )
'        {
'            return Scale(SizeF(x, y), center);
'        }

   ' =====================================================================================
   ' Creates a scale transformation that has the specified scale factors and center point.
   ' =====================================================================================
   METHOD MatrixScale (BYVAL x AS SINGLE, BYVAL y AS SINGLE, OPTIONAL BYREF center AS D2D1_POINT_2F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = x
      m.m12 = 0.0!
      m.m21 = 0.0!
      m.m22 = y
      IF ISMISSING(center) THEN
         ' Do nothing beause the results are 0
      ELSE
         m.m31 = center.x - x * center.x
         m.m32 = center.y - y * center.y
      END IF
      METHOD = m
   END METHOD
   ' =====================================================================================

'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Rotation(
'            FLOAT angle,
'            D2D1_POINT_2F center = D2D1::Point2F()
'            )
'        {
'            Matrix3x2F rotation;

'            D2D1MakeRotateMatrix(angle, center, &rotation);

'            return rotation;
'        }

   ' =====================================================================================
   ' Creates a rotation transformation that has the specified angle and center point.
   ' =====================================================================================
   METHOD MatrixRotation (BYVAL angle AS SINGLE, BYREF center AS D2D1_POINT_2F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      D2D1MakeRotateMatrix(angle, center, m)
      METHOD = m
   END METHOD
   ' =====================================================================================

'        static D2D1FORCEINLINE
'        Matrix3x2F
'        Skew(
'            FLOAT angleX,
'            FLOAT angleY,
'            D2D1_POINT_2F center = D2D1::Point2F()
'            )
'        {
'            Matrix3x2F skew;

'            D2D1MakeSkewMatrix(angleX, angleY, center, &skew);

'            return skew;
'        }

   ' =====================================================================================
   ' Creates a skew transformation that has the specified x-axis and y-axis values and center point.
   ' =====================================================================================
   METHOD MatrixSkew (BYVAL angleX AS SINGLE, BYVAL angleY AS SINGLE, BYREF center AS D2D1_POINT_2F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      LOCAL center_ AS D2D1_POINT_2F
      IF ISMISSING(center) THEN
         D2D1MakeSkewMatrix(angleX, angleY, center_, m)
      ELSE
         D2D1MakeSkewMatrix(angleX, angleY, center, m)
      END IF
      METHOD = m
   END METHOD
   ' =====================================================================================

      '  //
      '  // Functions for convertion from the base D2D1_MATRIX_3X2_F to this type
      '  // without making a copy
      '  //
      '  static inline const Matrix3x2F* ReinterpretBaseType(const D2D1_MATRIX_3X2_F *pMatrix)
      '  {
      '      return static_cast<const Matrix3x2F *>(pMatrix);
      '  }

      '  static inline Matrix3x2F* ReinterpretBaseType(D2D1_MATRIX_3X2_F *pMatrix)
      '  {
      '      return static_cast<Matrix3x2F *>(pMatrix);
      '  }

'        inline
'        FLOAT
'        Determinant() const
'        {
'            return (_11 * _22) - (_12 * _21);
'        }

   ' =====================================================================================
   ' Calculates the determinant of the matrix.
   ' =====================================================================================
   METHOD MatrixDeterminant (BYREF m AS D2D_MATRIX_3X2_F) AS SINGLE
      METHOD = (m.m11 * m.m22) - (m.m12 * m.m21)
   END METHOD
   ' =====================================================================================

'        inline
'        bool
'        IsInvertible() const
'        {
'            return !!D2D1IsMatrixInvertible(this);
'        }

   ' =====================================================================================
   ' Indicates whether the matrix is invertible.
   ' =====================================================================================
   METHOD IsInvertibleMatrix (BYREF m AS D2D_MATRIX_3X2_F) AS LONG
      METHOD = D2D1IsMatrixInvertible(m)
   END METHOD
   ' =====================================================================================

'        inline
'        bool
'        Invert()
'        {
'            return !!D2D1InvertMatrix(this);
'        }

   ' =====================================================================================
   ' Inverts the matrix, if it is invertible.
   ' =====================================================================================
   METHOD InvertMatrix (BYREF m AS D2D_MATRIX_3X2_F) AS LONG
      METHOD = D2D1InvertMatrix(m)
   END METHOD
   ' =====================================================================================

'        inline
'        bool
'        IsIdentity() const
'        {
'            return     _11 == 1.f && _12 == 0.f
'                    && _21 == 0.f && _22 == 1.f
'                    && _31 == 0.f && _32 == 0.f;
'        }

   ' =====================================================================================
   ' Indicates whether this matrix is the identity matrix.
   ' =====================================================================================
   METHOD IsIdentityMatrix (BYREF m AS D2D_MATRIX_3X2_F) AS LONG
      METHOD = (m.m11 = 1.0! AND m.m12 = 0.0! AND m.m21 = 0.0! AND m.m22 = 1.0! AND m.m31 = 0.0! AND m.m32 = 0.0!)
   END METHOD
   ' =====================================================================================

'        inline
'        void SetProduct(
'            const Matrix3x2F &a,
'            const Matrix3x2F &b
'            )
'        {
'            _11 = a._11 * b._11 + a._12 * b._21;
'            _12 = a._11 * b._12 + a._12 * b._22;
'            _21 = a._21 * b._11 + a._22 * b._21;
'            _22 = a._21 * b._12 + a._22 * b._22;
'            _31 = a._31 * b._11 + a._32 * b._21 + b._31;
'            _32 = a._31 * b._12 + a._32 * b._22 + b._32;
'        }

'        D2D1FORCEINLINE
'        Matrix3x2F
'        operator*(
'            const Matrix3x2F &matrix
'            ) const
'        {
'            Matrix3x2F result;

'            result.SetProduct(*this, matrix);

'            return result;
'        }

   ' =====================================================================================
   ' Multiplies the specified matrices and returns the result.
   ' =====================================================================================
   METHOD MultiplyMatrices (BYREF a AS D2D_MATRIX_3X2_F, BYREF b AS D2D_MATRIX_3X2_F) AS D2D_MATRIX_3X2_F
      LOCAL m AS D2D_MATRIX_3X2_F
      m.m11 = a.m11 * b.m11 + a.m12 * b.m21
      m.m12 = a.m11 * b.m12 + a.m12 * b.m22
      m.m21 = a.m21 * b.m11 + a.m22 * b.m21
      m.m22 = a.m21 * b.m12 + a.m22 * b.m22
      m.m31 = a.m31 * b.m11 + a.m32 * b.m21 + b.m31
      m.m32 = a.m31 * b.m12 + a.m32 * b.m22 + b.m32
      METHOD = m
   END METHOD
   ' =====================================================================================

'        D2D1FORCEINLINE
'        D2D1_POINT_2F
'        TransformPoint(
'            D2D1_POINT_2F point
'            ) const
'        {
'            D2D1_POINT_2F result =
'            {
'                point.x * _11 + point.y * _21 + _31,
'                point.x * _12 + point.y * _22 + _32
'            };

'            return result;
'        }
'    };

   ' =====================================================================================
   ' Uses the specified matrix to transform the specified point and returns the result.
   ' =====================================================================================
   METHOD MatrixTransformPoint (BYREF pt AS D2D1_POINT_2F, BYREF m AS D2D_MATRIX_3X2_F) AS D2D1_POINT_2F
      LOCAL result AS D2D1_POINT_2F
      result.x = pt.x * m.m11 + pt.y * m.m21 + m.m31
      result.y = pt.x * m.m12 + pt.y * m.m22 + m.m32
      METHOD = result
   END METHOD
   ' =====================================================================================

   ' D2D1FORCEINLINE
   ' D2D1_POINT_2F
   ' operator*(
   '     const D2D1_POINT_2F &point,
   '     const D2D1_MATRIX_3X2_F &matrix
   '     )
   ' {
   '     return Matrix3x2F::ReinterpretBaseType(&matrix)->TransformPoint(point);
   ' }

   ' D2D1_MATRIX_3X2_F
   ' IdentityMatrix()
   ' {
   '     return Matrix3x2F::Identity();
   ' }

'} // namespace D2D1

'D2D1FORCEINLINE
'D2D1_MATRIX_3X2_F
'operator*(
'    const D2D1_MATRIX_3X2_F &matrix1,
'    const D2D1_MATRIX_3X2_F &matrix2
'    )
'{
'    return
'        (*D2D1::Matrix3x2F::ReinterpretBaseType(&matrix1)) *
'        (*D2D1::Matrix3x2F::ReinterpretBaseType(&matrix2));
'}

'#endif // #ifndef D2D_USE_C_DEFINITIONS

   ' =====================================================================================
   ' MatrixReflectX reflects or mirrors the X values across the origin.
   ' Think mirroring across a vertical line around y=0 or flipping the image over left to right.
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectX() AS D2D1_MATRIX_3X2_F
      LOCAL m AS D2D1_MATRIX_3X2_F
      m.m11 = -1
      m.m12 = 0
      m.m21 = 0
      m.m22 = 1
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' MatrixReflectY reflects or mirrors the Y values across the origin.
   ' Think mirroring across a horizontal line around x=0 or flipping the image over top to bottom.
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectY() AS D2D1_MATRIX_3X2_F
      LOCAL m AS D2D1_MATRIX_3X2_F
      m.m11 = 1
      m.m12 = 0
      m.m21 = 0
      m.m22 = -1
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' MatrixReflectLeftDiagonal reflects or mirrors the x/y values across the origin using
   ' the line Top Right to Bottom Left.
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectLeftDiagonal() AS D2D1_MATRIX_3X2_F
      LOCAL m AS D2D1_MATRIX_3X2_F
      m.m11 = -1
      m.m12 = 0
      m.m21 = 0
      m.m22 = -1
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' MatrixReflectRightDiagonal reflects or mirrors the x/y values across the origin using
   ' the line Top Left to Bottom Right.
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectRightDiagonal() AS D2D1_MATRIX_3X2_F
      LOCAL m AS D2D1_MATRIX_3X2_F
      m.m11 = 0
      m.m12 = 1
      m.m21 = 1
      m.m22 = 0
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' MatrixReflectAngle reflects or mirrors the x/y values across the origin using the line
   ' defined by angle (counter clockwise).
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectAngle (BYREF angle AS SINGLE) AS D2D1_MATRIX_3X2_F
      LOCAL m AS D2D1_MATRIX_3X2_F
      m.m11 = COS(angle)
      m.m12 = -SIN(angle)
      m.m21 = SIN(angle)
      m.m22 = COS(angle)
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' MatrixReflectAntiAngle reflects or mirrors the x/y values across the origin using the line
   ' define by -angle (clockwise).
   ' Author: Larry Charlton
   ' =====================================================================================
   METHOD MatrixReflectAntiAngle (BYREF angle AS SINGLE) AS D2D1_MATRIX_3X2_F
      LOCAL m As D2D1_MATRIX_3X2_F
      m.m11 = COS(angle)
      m.m12 = SIN(angle)
      m.m21 = SIN(angle)
      m.m22 = -COS(angle)
      m.m31 = 0
      m.m32 = 0
      METHOD = m
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS

' ########################################################################################
