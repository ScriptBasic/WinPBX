' ########################################################################################
' Microsoft Windows
' File: GdiplusColor.inc
' Contents: GDI+ Color constants and class
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSCOLOR_INC = 1

' // Size = 4 bytes
TYPE GDIPCOLOR_BGRA_STRUCT BYTE
   blue  AS BYTE
   green AS BYTE
   red   AS BYTE
   alpha AS BYTE
END TYPE

' // Size = 4 bytes
UNION GDIPCOLOR_BGRA_UNION
   color AS DWORD
   GDIPCOLOR_BGRA_STRUCT
END UNION

'//----------------------------------------------------------------------------
'// Color mode
'//----------------------------------------------------------------------------

' enum ColorMode
%ColorModeARGB32 = 0
%ColorModeARGB64 = 1

'//----------------------------------------------------------------------------
'// Color Channel flags
'//----------------------------------------------------------------------------

' enum ColorChannelFlags
%ColorChannelFlagsC    = 0
%ColorChannelFlagsM    = 1
%ColorChannelFlagsY    = 2
%ColorChannelFlagsK    = 3
%ColorChannelFlagsLast = 4

'//----------------------------------------------------------------------------
'// Color
'//----------------------------------------------------------------------------

%ARGB_AliceBlue            = &HFFF0F8FF???
%ARGB_AntiqueWhite         = &HFFFAEBD7???
%ARGB_Aqua                 = &HFF00FFFF???
%ARGB_Aquamarine           = &HFF7FFFD4???
%ARGB_Azure                = &HFFF0FFFF???
%ARGB_Beige                = &HFFF5F5DC???
%ARGB_Bisque               = &HFFFFE4C4???
%ARGB_Black                = &HFF000000???
%ARGB_BlanchedAlmond       = &HFFFFEBCD???
%ARGB_Blue                 = &HFF0000FF???
%ARGB_BlueViolet           = &HFF8A2BE2???
%ARGB_Brown                = &HFFA52A2A???
%ARGB_BurlyWood            = &HFFDEB887???
%ARGB_CadetBlue            = &HFF5F9EA0???
%ARGB_Chartreuse           = &HFF7FFF00???
%ARGB_Chocolate            = &HFFD2691E???
%ARGB_Coral                = &HFFFF7F50???
%ARGB_CornflowerBlue       = &HFF6495ED???
%ARGB_Cornsilk             = &HFFFFF8DC???
%ARGB_Crimson              = &HFFDC143C???
%ARGB_Cyan                 = &HFF00FFFF???
%ARGB_DarkBlue             = &HFF00008B???
%ARGB_DarkCyan             = &HFF008B8B???
%ARGB_DarkGoldenrod        = &HFFB8860B???
%ARGB_DarkGray             = &HFFA9A9A9???
%ARGB_DarkGreen            = &HFF006400???
%ARGB_DarkKhaki            = &HFFBDB76B???
%ARGB_DarkMagenta          = &HFF8B008B???
%ARGB_DarkOliveGreen       = &HFF556B2F???
%ARGB_DarkOrange           = &HFFFF8C00???
%ARGB_DarkOrchid           = &HFF9932CC???
%ARGB_DarkRed              = &HFF8B0000???
%ARGB_DarkSalmon           = &HFFE9967A???
%ARGB_DarkSeaGreen         = &HFF8FBC8B???
%ARGB_DarkSlateBlue        = &HFF483D8B???
%ARGB_DarkSlateGray        = &HFF2F4F4F???
%ARGB_DarkTurquoise        = &HFF00CED1???
%ARGB_DarkViolet           = &HFF9400D3???
%ARGB_DeepPink             = &HFFFF1493???
%ARGB_DeepSkyBlue          = &HFF00BFFF???
%ARGB_DimGray              = &HFF696969???
%ARGB_DodgerBlue           = &HFF1E90FF???
%ARGB_Firebrick            = &HFFB22222???
%ARGB_FloralWhite          = &HFFFFFAF0???
%ARGB_ForestGreen          = &HFF228B22???
%ARGB_Fuchsia              = &HFFFF00FF???
%ARGB_Gainsboro            = &HFFDCDCDC???
%ARGB_GhostWhite           = &HFFF8F8FF???
%ARGB_Gold                 = &HFFFFD700???
%ARGB_Goldenrod            = &HFFDAA520???
%ARGB_Gray                 = &HFF808080???
%ARGB_Green                = &HFF008000???
%ARGB_GreenYellow          = &HFFADFF2F???
%ARGB_Honeydew             = &HFFF0FFF0???
%ARGB_HotPink              = &HFFFF69B4???
%ARGB_IndianRed            = &HFFCD5C5C???
%ARGB_Indigo               = &HFF4B0082???
%ARGB_Ivory                = &HFFFFFFF0???
%ARGB_Khaki                = &HFFF0E68C???
%ARGB_Lavender             = &HFFE6E6FA???
%ARGB_LavenderBlush        = &HFFFFF0F5???
%ARGB_LawnGreen            = &HFF7CFC00???
%ARGB_LemonChiffon         = &HFFFFFACD???
%ARGB_LightBlue            = &HFFADD8E6???
%ARGB_LightCoral           = &HFFF08080???
%ARGB_LightCyan            = &HFFE0FFFF???
%ARGB_LightGoldenrodYellow = &HFFFAFAD2???
%ARGB_LightGray            = &HFFD3D3D3???
%ARGB_LightGreen           = &HFF90EE90???
%ARGB_LightPink            = &HFFFFB6C1???
%ARGB_LightSalmon          = &HFFFFA07A???
%ARGB_LightSeaGreen        = &HFF20B2AA???
%ARGB_LightSkyBlue         = &HFF87CEFA???
%ARGB_LightSlateGray       = &HFF778899???
%ARGB_LightSteelBlue       = &HFFB0C4DE???
%ARGB_LightYellow          = &HFFFFFFE0???
%ARGB_Lime                 = &HFF00FF00???
%ARGB_LimeGreen            = &HFF32CD32???
%ARGB_Linen                = &HFFFAF0E6???
%ARGB_Magenta              = &HFFFF00FF???
%ARGB_Maroon               = &HFF800000???
%ARGB_MediumAquamarine     = &HFF66CDAA???
%ARGB_MediumBlue           = &HFF0000CD???
%ARGB_MediumOrchid         = &HFFBA55D3???
%ARGB_MediumPurple         = &HFF9370DB???
%ARGB_MediumSeaGreen       = &HFF3CB371???
%ARGB_MediumSlateBlue      = &HFF7B68EE???
%ARGB_MediumSpringGreen    = &HFF00FA9A???
%ARGB_MediumTurquoise      = &HFF48D1CC???
%ARGB_MediumVioletRed      = &HFFC71585???
%ARGB_MidnightBlue         = &HFF191970???
%ARGB_MintCream            = &HFFF5FFFA???
%ARGB_MistyRose            = &HFFFFE4E1???
%ARGB_Moccasin             = &HFFFFE4B5???
%ARGB_NavajoWhite          = &HFFFFDEAD???
%ARGB_Navy                 = &HFF000080???
%ARGB_OldLace              = &HFFFDF5E6???
%ARGB_Olive                = &HFF808000???
%ARGB_OliveDrab            = &HFF6B8E23???
%ARGB_Orange               = &HFFFFA500???
%ARGB_OrangeRed            = &HFFFF4500???
%ARGB_Orchid               = &HFFDA70D6???
%ARGB_PaleGoldenrod        = &HFFEEE8AA???
%ARGB_PaleGreen            = &HFF98FB98???
%ARGB_PaleTurquoise        = &HFFAFEEEE???
%ARGB_PaleVioletRed        = &HFFDB7093???
%ARGB_PapayaWhip           = &HFFFFEFD5???
%ARGB_PeachPuff            = &HFFFFDAB9???
%ARGB_Peru                 = &HFFCD853F???
%ARGB_Pink                 = &HFFFFC0CB???
%ARGB_Plum                 = &HFFDDA0DD???
%ARGB_PowderBlue           = &HFFB0E0E6???
%ARGB_Purple               = &HFF800080???
%ARGB_Red                  = &HFFFF0000???
%ARGB_RosyBrown            = &HFFBC8F8F???
%ARGB_RoyalBlue            = &HFF4169E1???
%ARGB_SaddleBrown          = &HFF8B4513???
%ARGB_Salmon               = &HFFFA8072???
%ARGB_SandyBrown           = &HFFF4A460???
%ARGB_SeaGreen             = &HFF2E8B57???
%ARGB_SeaShell             = &HFFFFF5EE???
%ARGB_Sienna               = &HFFA0522D???
%ARGB_Silver               = &HFFC0C0C0???
%ARGB_SkyBlue              = &HFF87CEEB???
%ARGB_SlateBlue            = &HFF6A5ACD???
%ARGB_SlateGray            = &HFF708090???
%ARGB_Snow                 = &HFFFFFAFA???
%ARGB_SpringGreen          = &HFF00FF7F???
%ARGB_SteelBlue            = &HFF4682B4???
%ARGB_Tan                  = &HFFD2B48C???
%ARGB_Teal                 = &HFF008080???
%ARGB_Thistle              = &HFFD8BFD8???
%ARGB_Tomato               = &HFFFF6347???
%ARGB_Transparent          = &H00FFFFFF???
%ARGB_Turquoise            = &HFF40E0D0???
%ARGB_Violet               = &HFFEE82EE???
%ARGB_Wheat                = &HFFF5DEB3???
%ARGB_White                = &HFFFFFFFF???
%ARGB_WhiteSmoke           = &HFFF5F5F5???
%ARGB_Yellow               = &HFFFFFF00???
%ARGB_YellowGreen          = &HFF9ACD32???

%AlphaShift                = 24???
%RedShift                  = 16???
%GreenShift                = 8???
%BlueShift                 = 0???

%AlphaMask                 = &HFF000000???
%RedMask                   = &HFF0000???
%GreenMask                 = &HFF00???
%BlueMask                  = &HFF???


' ########################################################################################
' A Color object stores a 32-bit value that represents a color. The color value contains
' four, 8-bit components: alpha, red, green, and blue. The first 8 bits (the most significant)
' contain the alpha component, the next 8 bits contain the red component, the next 8 bits
' contain the green component, and the next 8 bits (the least significant) contain the
' blue component. The 32-bit value is stored in a variable of type ARGB.
' ########################################################################################
CLASS CGdipColor

   INSTANCE m_Argb AS DWORD

   INTERFACE IGdipColor : INHERIT IAutomation

   ' =====================================================================================
   ' Creates a Color object by using an ARGB value. The default value is opaque black.
   ' =====================================================================================
   METHOD Color (OPTIONAL argbColor AS DWORD) THREADSAFE
      IF argbColor = 0 THEN m_Argb = %ARGB_Black ELSE m_Argb = argbColor
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Color object by using specified values for the red, green, and blue
   ' components. This constructor sets the alpha component to 255 (opaque).
   ' =====================================================================================
   METHOD ColorRGB (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE
      m_Argb = ME.MakeARGB(255, r, g, b)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Color object by using specified values for the alpha, red, green, and blue components.
   ' =====================================================================================
   METHOD ColorARGB (BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE
      m_Argb = ME.MakeARGB(a, r, g, b)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the alpha component of this Color object.
   ' =====================================================================================
   METHOD GetAlpha () THREADSAFE AS BYTE
      LOCAL clr AS GDIPCOLOR_BGRA_UNION
      clr.color = m_Argb
      METHOD = clr.alpha
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetA () THREADSAFE AS BYTE
      METHOD = ME.GetAlpha
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the red component of this Color object.
   ' =====================================================================================
   METHOD GetRed () THREADSAFE AS BYTE
      LOCAL clr AS GDIPCOLOR_BGRA_UNION
      clr.color = m_Argb
      METHOD = clr.Red
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetR () THREADSAFE AS BYTE
      METHOD = ME.GetRed
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the green component of this Color object.
   ' =====================================================================================
   METHOD GetGreen () THREADSAFE AS BYTE
      LOCAL clr AS GDIPCOLOR_BGRA_UNION
      clr.color = m_Argb
      METHOD = clr.green
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetG () THREADSAFE AS BYTE
      METHOD = ME.GetGreen
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the blue component of this Color object.
   ' =====================================================================================
   METHOD GetBlue () THREADSAFE AS BYTE
      LOCAL clr AS GDIPCOLOR_BGRA_UNION
      clr.color = m_Argb
      METHOD = clr.blue
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetB () THREADSAFE AS BYTE
      METHOD = ME.GetBlue
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the ARGB value of this Color object.
   ' =====================================================================================
   METHOD GetValue () THREADSAFE AS DWORD
      METHOD = m_Argb
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color of this Color object.
   ' =====================================================================================
   METHOD SetValue (BYVAL argbColor AS DWORD) THREADSAFE
      m_Argb = argbColor
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a Windows Graphics Device Interface (GDI)COLORREF value to set the ARGB value of
   ' this Color object.
   ' =====================================================================================
   METHOD SetFromCOLORREF(BYVAL rgbColor AS DWORD) THREADSAFE
      m_Argb = ME.MakeARGB(255, LO(BYTE, rgbColor), LO(BYTE, rgbColor \ 256), LO(BYTE, rgbColor \ 65536))
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts this Color object's ARGB value to a Windows Graphics Device Interface (GDI)COLORREF value.
   ' =====================================================================================
   METHOD ToCOLORREF () THREADSAFE AS DWORD
      METHOD = RGB(ME.GetRed, ME.GetGreen, ME.GetBlue)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a 32-bit value that consolidates the specified alpha, red, green, and blue components.
   ' =====================================================================================
   METHOD MakeARGB(BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE AS DWORD
      SHIFT LEFT b, %BlueShift
      SHIFT LEFT g, %GreenShift
      SHIFT LEFT r, %RedShift
      SHIFT LEFT a, %AlphaShift
      METHOD = b OR g OR r OR a
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ########################################################################################
' Creates new Color objects.
' ########################################################################################
FUNCTION NewGdipColor (OPTIONAL BYVAL argbColor AS DWORD) THREADSAFE AS IGdipColor
   LOCAL pGdipColor AS IGdipColor
   pGdipColor = CLASS "CGdipColor"
   IF ISNOTHING(pGdipColor) THEN EXIT FUNCTION
   pGdipColor.Color(argbColor)
   FUNCTION = pGdipColor
END FUNCTION
' ========================================================================================
FUNCTION NewGdipColorRGB (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE AS IGdipColor
   LOCAL pGdipColor AS IGdipColor
   pGdipColor = CLASS "CGdipColor"
   IF ISNOTHING(pGdipColor) THEN EXIT FUNCTION
   pGdipColor.ColorRGB(r, g, b)
   FUNCTION = pGdipColor
END FUNCTION
' ========================================================================================
FUNCTION NewGdipColorARGB (BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE AS IGdipColor
   LOCAL pGdipColor AS IGdipColor
   pGdipColor = CLASS "CGdipColor"
   IF ISNOTHING(pGdipColor) THEN EXIT FUNCTION
   pGdipColor.ColorARGB(a, r, g, b)
   FUNCTION = pGdipColor
END FUNCTION
' ########################################################################################
