' ########################################################################################
' Microsoft Windows
' File: xpsobjectmodel.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSXPS
' Version: 0.0, Locale ID = 0
' Library GUID: {B47491A0-CF33-4FE4-9A48-B0ACDAE207E8}
' ########################################################################################

#INCLUDE THIS ONCE
%XPSOBJECTMODEL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "msopc.inc"

$LIBID_MSXPS = GUID$("{B47491A0-CF33-4FE4-9A48-B0ACDAE207E8}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_XpsOMObjectFactory = GUID$("{E974D26D-3D9B-4D47-88CC-3872F2DC3585}")
$CLSID_XpsOMThumbnailGenerator = GUID$("{7E4A23E2-B969-4761-BE35-1A8CED58E323}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IXpsOMBrush = GUID$("{56A3F80C-EA4C-4187-A57B-A2A473B2B42B}")
$IID_IXpsOMCanvas = GUID$("{221D1452-331E-47C6-87E9-6CCEFB9B5BA3}")
$IID_IXpsOMColorProfileResource = GUID$("{67BD7D69-1EEF-4BB1-B5E7-6F4F87BE8ABE}")
$IID_IXpsOMColorProfileResourceCollection = GUID$("{12759630-5FBA-4283-8F7D-CCA849809EDB}")
$IID_IXpsOMCoreProperties = GUID$("{3340FE8F-4027-4AA1-8F5F-D35AE45FE597}")
$IID_IXpsOMDashCollection = GUID$("{081613F4-74EB-48F2-83B3-37A9CE2D7DC6}")
$IID_IXpsOMDictionary = GUID$("{897C86B8-8EAF-4AE3-BDDE-56419FCF4236}")
$IID_IXpsOMDocument = GUID$("{2C2C94CB-AC5F-4254-8EE9-23948309D9F0}")
$IID_IXpsOMDocumentCollection = GUID$("{D1C87F0D-E947-4754-8A25-971478F7E83E}")
$IID_IXpsOMDocumentSequence = GUID$("{56492EB4-D8D5-425E-8256-4C2B64AD0264}")
$IID_IXpsOMDocumentStructureResource = GUID$("{85FEBC8A-6B63-48A9-AF07-7064E4ECFF30}")
$IID_IXpsOMFontResource = GUID$("{A8C45708-47D9-4AF4-8D20-33B48C9B8485}")
$IID_IXpsOMFontResourceCollection = GUID$("{70B4A6BB-88D4-4FA8-AAF9-6D9C596FDBAD}")
$IID_IXpsOMGeometry = GUID$("{64FCF3D7-4D58-44BA-AD73-A13AF6492072}")
$IID_IXpsOMGeometryFigure = GUID$("{D410DC83-908C-443E-8947-B1795D3C165A}")
$IID_IXpsOMGeometryFigureCollection = GUID$("{FD48C3F3-A58E-4B5A-8826-1DE54ABE72B2}")
$IID_IXpsOMGlyphs = GUID$("{819B3199-0A5A-4B64-BEC7-A9E17E780DE2}")
$IID_IXpsOMGlyphsEditor = GUID$("{A5AB8616-5B16-4B9F-9629-89B323ED7909}")
$IID_IXpsOMGradientBrush = GUID$("{EDB59622-61A2-42C3-BACE-ACF2286C06BF}")
$IID_IXpsOMGradientStop = GUID$("{5CF4F5CC-3969-49B5-A70A-5550B618FE49}")
$IID_IXpsOMGradientStopCollection = GUID$("{C9174C3A-3CD3-4319-BDA4-11A39392CEEF}")
$IID_IXpsOMImageBrush = GUID$("{3DF0B466-D382-49EF-8550-DD94C80242E4}")
$IID_IXpsOMImageResource = GUID$("{3DB8417D-AE50-485E-9A44-D7758F78A23F}")
$IID_IXpsOMImageResourceCollection = GUID$("{7A4A1A71-9CDE-4B71-B33F-62DE843EABFE}")
$IID_IXpsOMLinearGradientBrush = GUID$("{005E279F-C30D-40FF-93EC-1950D3C528DB}")
$IID_IXpsOMMatrixTransform = GUID$("{B77330FF-BB37-4501-A93E-F1B1E50BFC46}")
$IID_IXpsOMNameCollection = GUID$("{4BDDF8EC-C915-421B-A166-D173D25653D2}")
$IID_IXpsOMObjectFactory = GUID$("{F9B2A685-A50D-4FC2-B764-B56E093EA0CA}")
$IID_IXpsOMPackage = GUID$("{18C3DF65-81E1-4674-91DC-FC452F5A416F}")
$IID_IXpsOMPackageWriter = GUID$("{4E2AA182-A443-42C6-B41B-4F8E9DE73FF9}")
$IID_IXpsOMPage = GUID$("{D3E18888-F120-4FEE-8C68-35296EAE91D4}")
$IID_IXpsOMPageReference = GUID$("{ED360180-6F92-4998-890D-2F208531A0A0}")
$IID_IXpsOMPageReferenceCollection = GUID$("{CA16BA4D-E7B9-45C5-958B-F98022473745}")
$IID_IXpsOMPart = GUID$("{74EB2F0B-A91E-4486-AFAC-0FABECA3DFC6}")
$IID_IXpsOMPartResources = GUID$("{F4CF7729-4864-4275-99B3-A8717163ECAF}")
$IID_IXpsOMPartUriCollection = GUID$("{57C650D4-067C-4893-8C33-F62A0633730F}")
$IID_IXpsOMPath = GUID$("{37D38BB6-3EE9-4110-9312-14B194163337}")
$IID_IXpsOMPrintTicketResource = GUID$("{E7FF32D2-34AA-499B-BBE9-9CD4EE6C59F7}")
$IID_IXpsOMRadialGradientBrush = GUID$("{75F207E5-08BF-413C-96B1-B82B4064176B}")
$IID_IXpsOMRemoteDictionaryResource = GUID$("{C9BD7CD4-E16A-4BF8-8C84-C950AF7A3061}")
$IID_IXpsOMRemoteDictionaryResourceCollection = GUID$("{5C38DB61-7FEC-464A-87BD-41E3BEF018BE}")
$IID_IXpsOMResource = GUID$("{DA2AC0A2-73A2-4975-AD14-74097C3FF3A5}")
$IID_IXpsOMShareable = GUID$("{7137398F-2FC1-454D-8C6A-2C3115A16ECE}")
$IID_IXpsOMSignatureBlockResource = GUID$("{4776AD35-2E04-4357-8743-EBF6C171A905}")
$IID_IXpsOMSignatureBlockResourceCollection = GUID$("{AB8F5D8E-351B-4D33-AAED-FA56F0022931}")
$IID_IXpsOMSolidColorBrush = GUID$("{A06F9F05-3BE9-4763-98A8-094FC672E488}")
$IID_IXpsOMStoryFragmentsResource = GUID$("{C2B3CA09-0473-4282-87AE-1780863223F0}")
$IID_IXpsOMThumbnailGenerator = GUID$("{15B873D5-1971-41E8-83A3-6578403064C7}")
$IID_IXpsOMTileBrush = GUID$("{0FC2328D-D722-4A54-B2EC-BE90218A789E}")
$IID_IXpsOMVisual = GUID$("{BC3E7333-FB0B-4AF3-A819-0B4EAAD0D2FD}")
$IID_IXpsOMVisualBrush = GUID$("{97E294AF-5B37-46B4-8057-874D2F64119B}")
$IID_IXpsOMVisualCollection = GUID$("{94D8ABDE-AB91-46A8-82B7-F5B05EF01A96}")

'#if (NTDDI_VERSION >= NTDDI_WIN7)

'#ifndef __MSXPS_LIBRARY_DEFINED__
'#define __MSXPS_LIBRARY_DEFINED__

' enum XPS_TILE_MODE
%XPS_TILE_MODE_NONE   = 1
%XPS_TILE_MODE_TILE   = %XPS_TILE_MODE_NONE  + 1
%XPS_TILE_MODE_FLIPX  = %XPS_TILE_MODE_TILE  + 1
%XPS_TILE_MODE_FLIPY  = %XPS_TILE_MODE_FLIPX + 1
%XPS_TILE_MODE_FLIPXY = %XPS_TILE_MODE_FLIPY + 1

' enum XPS_COLOR_INTERPOLATION
%XPS_COLOR_INTERPOLATION_SCRGBLINEAR = 1
%XPS_COLOR_INTERPOLATION_SRGBLINEAR  = %XPS_COLOR_INTERPOLATION_SCRGBLINEAR + 1

' enum XPS_SPREAD_METHOD
%XPS_SPREAD_METHOD_PAD     = 1
%XPS_SPREAD_METHOD_REFLECT = %XPS_SPREAD_METHOD_PAD     + 1
%XPS_SPREAD_METHOD_REPEAT  = %XPS_SPREAD_METHOD_REFLECT + 1

' enum XPS_STYLE_SIMULATION
%XPS_STYLE_SIMULATION_NONE       = 1
%XPS_STYLE_SIMULATION_ITALIC     = %XPS_STYLE_SIMULATION_NONE   + 1
%XPS_STYLE_SIMULATION_BOLD       = %XPS_STYLE_SIMULATION_ITALIC + 1
%XPS_STYLE_SIMULATION_BOLDITALIC = %XPS_STYLE_SIMULATION_BOLD   + 1

' enum XPS_LINE_CAP
%XPS_LINE_CAP_FLAT     = 1
%XPS_LINE_CAP_ROUND    = %XPS_LINE_CAP_FLAT   + 1
%XPS_LINE_CAP_SQUARE   = %XPS_LINE_CAP_ROUND  + 1
%XPS_LINE_CAP_TRIANGLE = %XPS_LINE_CAP_SQUARE + 1

' enum XPS_DASH_CAP
%XPS_DASH_CAP_FLAT     = 1
%XPS_DASH_CAP_ROUND    = %XPS_DASH_CAP_FLAT   + 1
%XPS_DASH_CAP_SQUARE   = %XPS_DASH_CAP_ROUND  + 1
%XPS_DASH_CAP_TRIANGLE = %XPS_DASH_CAP_SQUARE + 1

' enum v
%XPS_LINE_JOIN_MITER   = 1
%XPS_LINE_JOIN_BEVEL   = %XPS_LINE_JOIN_MITER + 1
%XPS_LINE_JOIN_ROUND   = %XPS_LINE_JOIN_BEVEL + 1

' enum XPS_IMAGE_TYPE
%XPS_IMAGE_TYPE_JPEG = 1
%XPS_IMAGE_TYPE_PNG  = %XPS_IMAGE_TYPE_JPEG + 1
%XPS_IMAGE_TYPE_TIFF = %XPS_IMAGE_TYPE_PNG  + 1
%XPS_IMAGE_TYPE_WDP  = %XPS_IMAGE_TYPE_TIFF + 1

' enum XPS_COLOR_TYPE
%XPS_COLOR_TYPE_SRGB   = 1
%XPS_COLOR_TYPE_SCRGB   = %XPS_COLOR_TYPE_SRGB  + 1
%XPS_COLOR_TYPE_CONTEXT = %XPS_COLOR_TYPE_SCRGB + 1

' enum XPS_FILL_RULE
%XPS_FILL_RULE_EVENODD = 1
%XPS_FILL_RULE_NONZERO = %XPS_FILL_RULE_EVENODD + 1

' enum XPS_SEGMENT_TYPE
%XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE        = 1
%XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE = %XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE        + 1
%XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE        = %XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE + 1
%XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE = %XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE        + 1
%XPS_SEGMENT_TYPE_BEZIER                     = %XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE + 1
%XPS_SEGMENT_TYPE_LINE                       = %XPS_SEGMENT_TYPE_BEZIER                     + 1
%XPS_SEGMENT_TYPE_QUADRATIC_BEZIER           = %XPS_SEGMENT_TYPE_LINE                       + 1

' enum XPS_SEGMENT_STROKE_PATTERN
%XPS_SEGMENT_STROKE_PATTERN_ALL   = 1
%XPS_SEGMENT_STROKE_PATTERN_NONE  = %XPS_SEGMENT_STROKE_PATTERN_ALL  + 1
%XPS_SEGMENT_STROKE_PATTERN_MIXED = %XPS_SEGMENT_STROKE_PATTERN_NONE + 1

' enum XPS_FONT_EMBEDDING
%XPS_FONT_EMBEDDING_NORMAL                  = 1
%XPS_FONT_EMBEDDING_OBFUSCATED              = %XPS_FONT_EMBEDDING_NORMAL     + 1
%XPS_FONT_EMBEDDING_RESTRICTED              = %XPS_FONT_EMBEDDING_OBFUSCATED + 1
%XPS_FONT_EMBEDDING_RESTRICTED_UNOBFUSCATED = %XPS_FONT_EMBEDDING_RESTRICTED + 1

' enum XPS_OBJECT_TYPE
%XPS_OBJECT_TYPE_CANVAS                = 1
%XPS_OBJECT_TYPE_GLYPHS                = %XPS_OBJECT_TYPE_CANVAS                + 1
%XPS_OBJECT_TYPE_PATH                  = %XPS_OBJECT_TYPE_GLYPHS                + 1
%XPS_OBJECT_TYPE_MATRIX_TRANSFORM      = %XPS_OBJECT_TYPE_PATH                  + 1
%XPS_OBJECT_TYPE_GEOMETRY              = %XPS_OBJECT_TYPE_MATRIX_TRANSFORM      + 1
%XPS_OBJECT_TYPE_SOLID_COLOR_BRUSH     = %XPS_OBJECT_TYPE_GEOMETRY              + 1
%XPS_OBJECT_TYPE_IMAGE_BRUSH           = %XPS_OBJECT_TYPE_SOLID_COLOR_BRUSH     + 1
%XPS_OBJECT_TYPE_LINEAR_GRADIENT_BRUSH = %XPS_OBJECT_TYPE_IMAGE_BRUSH           + 1
%XPS_OBJECT_TYPE_RADIAL_GRADIENT_BRUSH = %XPS_OBJECT_TYPE_LINEAR_GRADIENT_BRUSH + 1
%XPS_OBJECT_TYPE_VISUAL_BRUSH          = %XPS_OBJECT_TYPE_RADIAL_GRADIENT_BRUSH + 1

' enum XPS_THUMBNAIL_SIZE
%XPS_THUMBNAIL_SIZE_VERYSMALL = 1
%XPS_THUMBNAIL_SIZE_SMALL     = %XPS_THUMBNAIL_SIZE_VERYSMALL + 1
%XPS_THUMBNAIL_SIZE_MEDIUM    = %XPS_THUMBNAIL_SIZE_SMALL     + 1
%XPS_THUMBNAIL_SIZE_LARGE     = %XPS_THUMBNAIL_SIZE_MEDIUM    + 1

' enum XPS_INTERLEAVING
%XPS_INTERLEAVING_OFF = 1
%XPS_INTERLEAVING_ON  = %XPS_INTERLEAVING_OFF + 1

' // Size = 8 bytes
TYPE XPS_POINT DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
END TYPE

' // Size = 8 bytes
TYPE XPS_SIZE DWORD
   width  AS SINGLE   ' FLOAT
   height AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
TYPE XPS_RECT DWORD
   x      AS SINGLE   ' FLOAT
   y      AS SINGLE   ' FLOAT
   width  AS SINGLE   ' FLOAT
   height AS SINGLE   ' FLOAT
END TYPE

' // Size = 8 bytes
TYPE XPS_DASH DWORD
   length AS SINGLE   ' FLOAT
   gap    AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
TYPE XPS_GLYPH_INDEX DWORD
   index            AS LONG     ' LONG
   advanceWidth     AS SINGLE   ' FLOAT
   horizontalOffset AS SINGLE   ' FLOAT
   verticalOffset   AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
TYPE XPS_GLYPH_MAPPING DWORD
   unicodeStringStart  AS DWORD   ' UINT32
   unicodeStringLength AS WORD    ' UINT16
   glyphIndicesStart   AS DWORD   ' UINT32
   glyphIndicesLength  AS WORD    ' UINT16
END TYPE

' // Size = 24 bytes
TYPE XPS_MATRIX DWORD
   m11 AS SINGLE   ' FLOAT
   m12 AS SINGLE   ' FLOAT
   m21 AS SINGLE   ' FLOAT
   m22 AS SINGLE   ' FLOAT
   m31 AS SINGLE   ' FLOAT
   m32 AS SINGLE   ' FLOAT
END TYPE

' // Size = 4 bytes
TYPE XPS_COLOR_sRGB BYTE
   alpha AS BYTE   ' UINT8
   red   AS BYTE   ' UINT8
   green AS BYTE   ' UINT8
   blue  AS BYTE   ' UINT8
END TYPE

' // Size = 16 bytes
TYPE XPS_COLOR_scRGB DWORD
   alpha AS SINGLE   ' FLOAT
   red   AS SINGLE   ' FLOAT
   green AS SINGLE   ' FLOAT
   blue  AS SINGLE   ' FLOAT
END TYPE

' // Size = 40 bytes
TYPE XPS_COLOR_context DWORD
   channelCount AS WORD     ' UINT8
   channels(8)  AS SINGLE   ' FLOAT[9]
END TYPE

' // Size = 40 bytes
UNION XPS_COLOR_UNION DWORD
   sRGB    AS XPS_COLOR_sRGB
   scRGB   AS XPS_COLOR_scRGB
   context AS XPS_COLOR_context
END UNION

' // Size = 44 bytes
TYPE XPS_COLOR DWORD
   colorType AS LONG   ' XPS_COLOR_TYPE
   value     AS XPS_COLOR_UNION
END TYPE


' ########################################################################################
' Interface name = IXpsOMPackage
' IID = {18C3DF65-81E1-4674-91DC-FC452F5A416F}
' Specify the root of Xps Tree
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPackage_INTERFACE_DEFINED)
    %IXpsOMPackage_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPackage $IID_IXpsOMPackage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocumentSequence ( _                       ' VTable offset = 12
     BYREF documentSequence AS IXpsOMDocumentSequence _ ' __out IXpsOMDocumentSequence **documentSequence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocumentSequence ( _                       ' VTable offset = 16
     BYVAL documentSequence AS IXpsOMDocumentSequence _ ' __in IXpsOMDocumentSequence *documentSequence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCoreProperties ( _                         ' VTable offset = 20
     BYREF coreProperties AS IXpsOMCoreProperties _     ' __out IXpsOMCoreProperties **coreProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCoreProperties ( _                         ' VTable offset = 24
     BYVAL coreProperties AS IXpsOMCoreProperties _     ' __in IXpsOMCoreProperties *coreProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDiscardControlPartName ( _                 ' VTable offset = 28
     BYREF discardControlPartUri AS IOpcPartUri _       ' __out IOpcPartUri **discardControlPartUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDiscardControlPartName ( _                 ' VTable offset = 32
     BYVAL discardControlPartUri AS IOpcPartUri _       ' __in IOpcPartUri *discardControlPartUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnailResource ( _                      ' VTable offset = 36
     BYREF imageResource AS IXpsOMImageResource _       ' __out IXpsOMImageResource **imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailResource ( _                      ' VTable offset = 40
     BYVAL imageResource AS IXpsOMImageResource _       ' __in IXpsOMImageResource *imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteToFile ( _                               ' VTable offset = 44
     BYREF fileName AS WSTRINGZ _                       ' __in fileName VT_LPWSTR
   , BYREF securityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES securityAttributes
   , BYVAL flagsAndAttributes AS DWORD _                ' __in DWORD flagsAndAttributes
   , BYVAL optimizeMarkupSize AS LONG _                 ' __in BOOL optimizeMarkupSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteToStream ( _                             ' VTable offset = 48
     BYVAL stream AS ISequentialStream _                ' __in ISequentialStream *stream
   , BYVAL optimizeMarkupSize AS LONG _                 ' __in BOOL optimizeMarkupSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPackage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXpsOMPart
' IID = {74EB2F0B-A91E-4486-AFAC-0FABECA3DFC6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPart_INTERFACE_DEFINED)
    %IXpsOMPart_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPart $IID_IXpsOMPart

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPart_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMShareable
' IID = {7137398F-2FC1-454D-8C6A-2C3115A16ECE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMShareable_INTERFACE_DEFINED)
    %IXpsOMShareable_INTERFACE_DEFINED = 1

INTERFACE IXpsOMShareable $IID_IXpsOMShareable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMShareable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMVisual
' IID = {BC3E7333-FB0B-4AF3-A819-0B4EAAD0D2FD}
' Inherited interface = IXpsOMShareable
' ########################################################################################

#IF NOT %DEF(%IXpsOMVisual_INTERFACE_DEFINED)
    %IXpsOMVisual_INTERFACE_DEFINED = 1

INTERFACE IXpsOMVisual $IID_IXpsOMVisual

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMVisual Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 20
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 24
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 28
     BYVAL matrixTransform AS IXpsOMMatrixTransform _   ' __in IXpsOMMatrixTransform *matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 32
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 36
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometry ( _                           ' VTable offset = 40
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLocal ( _                      ' VTable offset = 44
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLocal ( _                      ' VTable offset = 48
     BYVAL clipGeometry AS IXpsOMGeometry _             ' __in IXpsOMGeometry *clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLookup ( _                     ' VTable offset = 52
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLookup ( _                     ' VTable offset = 56
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 60
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 64
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrush ( _                       ' VTable offset = 68
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLocal ( _                  ' VTable offset = 72
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLocal ( _                  ' VTable offset = 76
     BYVAL opacityMaskBrush AS IXpsOMBrush _            ' __in IXpsOMBrush *opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLookup ( _                 ' VTable offset = 80
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLookup ( _                 ' VTable offset = 84
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 88
     BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 92
     BYREF name AS WSTRINGZ _                           ' __in LPCWSTR name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsHyperlinkTarget ( _                      ' VTable offset = 96
     BYREF isHyperlink AS LONG _                        ' __out BOOL *isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsHyperlinkTarget ( _                      ' VTable offset = 100
     BYVAL isHyperlink AS LONG _                        ' __in BOOL isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHyperlinkNavigateUri ( _                   ' VTable offset = 104
     BYREF hyperlinkUri AS IUri _                       ' __out IUri **hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHyperlinkNavigateUri ( _                   ' VTable offset = 108
     BYVAL hyperlinkUri AS IUri _                       ' __in IUri *hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 112
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 116
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMVisual_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXpsOMBrush
' IID = {56A3F80C-EA4C-4187-A57B-A2A473B2B42B}
' Inherited interface = IXpsOMShareable
' ########################################################################################

#IF NOT %DEF(%IXpsOMBrush_INTERFACE_DEFINED)
    %IXpsOMBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMBrush $IID_IXpsOMBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMTileBrush
' IID = {0FC2328D-D722-4A54-B2EC-BE90218A789E}
' Inherited interface = IXpsOMBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMTileBrush_INTERFACE_DEFINED)
    %IXpsOMTileBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMTileBrush $IID_IXpsOMTileBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMTileBrush Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 36
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 40
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewbox ( _                                ' VTable offset = 48
     BYREF viewbox AS XPS_RECT _                        ' __out XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewbox ( _                                ' VTable offset = 52
     BYREF viewbox AS XPS_RECT _                        ' __in XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 56
     BYREF viewport AS XPS_RECT _                       ' __out XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 60
     BYREF viewport AS XPS_RECT _                       ' __in XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTileMode ( _                               ' VTable offset = 64
     BYREF tileMode AS LONG _                           ' __out XPS_TILE_MODE *tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTileMode ( _                               ' VTable offset = 68
     BYVAL tileMode AS LONG _                           ' __in XPS_TILE_MODE tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMTileBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMResource
' IID = {DA2AC0A2-73A2-4975-AD14-74097C3FF3A5}
' Inherited interface = IXpsOMPart
' ########################################################################################

#IF NOT %DEF(%IXpsOMResource_INTERFACE_DEFINED)
    %IXpsOMResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMResource $IID_IXpsOMResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

END INTERFACE

#ENDIF   ' /* __IXpsOMResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMCanvas
' IID = {221D1452-331E-47C6-87E9-6CCEFB9B5BA3}
' Inherited interface = IXpsOMVisual
' ########################################################################################

#IF NOT %DEF(%IXpsOMCanvas_INTERFACE_DEFINED)
    %IXpsOMCanvas_INTERFACE_DEFINED = 1

INTERFACE IXpsOMCanvas $IID_IXpsOMCanvas

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMVisual Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 20
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 24
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 28
     BYVAL matrixTransform AS IXpsOMMatrixTransform _   ' __in IXpsOMMatrixTransform *matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 32
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 36
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometry ( _                           ' VTable offset = 40
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLocal ( _                      ' VTable offset = 44
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLocal ( _                      ' VTable offset = 48
     BYVAL clipGeometry AS IXpsOMGeometry _             ' __in IXpsOMGeometry *clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLookup ( _                     ' VTable offset = 52
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLookup ( _                     ' VTable offset = 56
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 60
     BYREF capacity AS SINGLE _                         ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 64
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrush ( _                       ' VTable offset = 68
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLocal ( _                  ' VTable offset = 72
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLocal ( _                  ' VTable offset = 76
     BYVAL opacityMaskBrush AS IXpsOMBrush _            ' __in IXpsOMBrush *opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLookup ( _                 ' VTable offset = 80
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLookup ( _                 ' VTable offset = 84
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 88
     BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 92
     BYREF name AS WSTRINGZ _                           ' __in LPCWSTR name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsHyperlinkTarget ( _                      ' VTable offset = 96
     BYREF isHyperlink AS LONG _                        ' __out BOOL *isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsHyperlinkTarget ( _                      ' VTable offset = 100
     BYVAL isHyperlink AS LONG _                        ' __in BOOL isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHyperlinkNavigateUri ( _                   ' VTable offset = 104
     BYREF hyperlinkUri AS IUri _                       ' __out IUri **hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHyperlinkNavigateUri ( _                   ' VTable offset = 108
     BYVAL hyperlinkUri AS IUri _                       ' __in IUri *hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 112
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 116
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMCanvas Methods
   ' =====================================================================================
   METHOD GetVisuals ( _                                ' VTable offset = 120
     BYREF visuals AS IXpsOMVisualCollection _          ' __out IXpsOMVisualCollection **visuals
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUseAliasedEdgeMode ( _                     ' VTable offset = 124
     BYREF useAliasedEdgeMode AS LONG _                 ' __out BOOL *useAliasedEdgeMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUseAliasedEdgeMode ( _                     ' VTable offset = 128
     BYVAL useAliasedEdgeMode AS LONG _                 ' __in BOOL useAliasedEdgeMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccessibilityShortDescription ( _          ' VTable offset = 132
     BYREF shortDescription AS DWORD _                  ' __out LPWSTR *shortDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessibilityShortDescription ( _          ' VTable offset = 136
     BYREF shortDescription AS WSTRINGZ _               ' __in LPCWSTR shortDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccessibilityLongDescription ( _           ' VTable offset = 140
     BYREF longDescription AS DWORD _                   ' __out LPWSTR *longDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessibilityLongDescription ( _           ' VTable offset = 144
     BYREF longDescription AS WSTRINGZ _                ' __in LPCWSTR longDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionary ( _                             ' VTable offset = 148
     BYREF resourceDictionary AS IXpsOMDictionary _     ' __out IXpsOMDictionary **resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionaryLocal ( _                        ' VTable offset = 152
     BYREF resourceDictionary AS IXpsOMDictionary _     ' __out IXpsOMDictionary **resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictionaryLocal ( _                        ' VTable offset = 156
     BYVAL resourceDictionary AS IXpsOMDictionary _     ' __in IXpsOMDictionary *resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionaryResource ( _                     ' VTable offset = 160
     BYREF remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __out IXpsOMRemoteDictionaryResource **remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictionaryResource ( _                     ' VTable offset = 164
     BYVAL remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __in IXpsOMRemoteDictionaryResource *remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 168
     BYREF canvas AS IXpsOMCanvas _                     ' __out IXpsOMCanvas **canvas
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMCanvas_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMColorProfileResource
' IID = {67BD7D69-1EEF-4BB1-B5E7-6F4F87BE8ABE}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMColorProfileResource_INTERFACE_DEFINED)
    %IXpsOMColorProfileResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMColorProfileResource $IID_IXpsOMColorProfileResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMColorProfileResource Methods
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 20
     BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 24
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMColorProfileResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMColorProfileResourceCollection
' IID = {12759630-5FBA-4283-8F7D-CCA849809EDB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMColorProfileResourceCollection_INTERFACE_DEFINED)
    %IXpsOMColorProfileResourceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMColorProfileResourceCollection $IID_IXpsOMColorProfileResourceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF object AS IXpsOMColorProfileResource _       ' __out IXpsOMColorProfileResource **object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMColorProfileResource _       ' __in IXpsOMColorProfileResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMColorProfileResource _       ' __in IXpsOMColorProfileResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL object AS IXpsOMColorProfileResource _       ' __in IXpsOMColorProfileResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByPartName ( _                             ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYREF part AS IXpsOMColorProfileResource _         ' __out IXpsOMColorProfileResource **part
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMColorProfileResourceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDashCollection
' IID = {081613F4-74EB-48F2-83B3-37A9CE2D7DC6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMDashCollection_INTERFACE_DEFINED)
    %IXpsOMDashCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDashCollection $IID_IXpsOMDashCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF dash AS XPS_DASH _                           ' __out XPS_DASH *dash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF dash AS XPS_DASH _                           ' __in XPS_DASH *dash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF dash AS XPS_DASH _                           ' __in XPS_DASH *dash
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYREF dash AS XPS_DASH _                           ' __in XPS_DASH *dash XPS_DASH
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDashCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMFontResource
' IID = {A8C45708-47D9-4AF4-8D20-33B48C9B8485}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMFontResource_INTERFACE_DEFINED)
    %IXpsOMFontResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMFontResource $IID_IXpsOMFontResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMColorProfileResource Methods
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 20
      BYREF stream AS IStream _                         ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 24
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMFontResource Methods
   ' =====================================================================================
   ' Note: Renamed as GetStream_ because it conflicts with the GetStream method of the
   ' inherited interface IXpsOMColorProfileResource.
   METHOD GetStream_ ( _                                ' VTable offset = 20
     BYREF readerStream AS IStream _                    ' __out IStream **readerStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' Note: Renamed as SetContent_ because it conflicts with the SetContent method of the
   ' inherited interface IXpsOMColorProfileResource.
   METHOD SetContent_ ( _                               ' VTable offset = 24
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL embeddingOption AS LONG _                    ' __in XPS_FONT_EMBEDDING embeddingOption
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEmbeddingOption ( _                        ' VTable offset = 28
     BYREF embeddingOption AS LONG _                    ' __out XPS_FONT_EMBEDDING *embeddingOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMFontResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMFontResourceCollection
' IID = {70B4A6BB-88D4-4FA8-AAF9-6D9C596FDBAD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMFontResourceCollection_INTERFACE_DEFINED)
    %IXpsOMFontResourceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMFontResourceCollection $IID_IXpsOMFontResourceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF value AS IXpsOMFontResource _                ' __out IXpsOMFontResource **value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL value AS IXpsOMFontResource _                ' __in IXpsOMFontResource *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL value AS IXpsOMFontResource _                ' __in IXpsOMFontResource *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 28
     BYVAL value AS IXpsOMFontResource _                ' __in IXpsOMFontResource *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 32
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByPartName ( _                             ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYREF part AS IXpsOMFontResource _                 ' __out IXpsOMFontResource **part
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMFontResourceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGeometry
' IID = {64FCF3D7-4D58-44BA-AD73-A13AF6492072}
' Inherited interface = IXpsOMShareable
' ########################################################################################

#IF NOT %DEF(%IXpsOMGeometry_INTERFACE_DEFINED)
    %IXpsOMGeometry_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGeometry $IID_IXpsOMGeometry

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMGeometry Methods
   ' =====================================================================================
   METHOD GetFigures ( _                                ' VTable offset = 20
     BYREF figures AS IXpsOMGeometryFigureCollection _  ' __out IXpsOMGeometryFigureCollection **figures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillRule ( _                               ' VTable offset = 24
     BYREF fillRule AS LONG _                           ' __out XPS_FILL_RULE *fillRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillRule ( _                               ' VTable offset = 28
     BYVAL fillRule AS LONG _                           ' __in XPS_FILL_RULE fillRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 36
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 40
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 44
     BYREF lookup AS DWORD _                            ' __out LPWSTR *lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 48
     BYREF lookup AS WSTRINGZ _                         ' __in LPCWSTR lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF geometry AS IXpsOMGeometry _                 ' __out IXpsOMGeometry **geometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGeometry_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGeometryFigure
' IID = {D410DC83-908C-443E-8947-B1795D3C165A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMGeometryFigure_INTERFACE_DEFINED)
    %IXpsOMGeometryFigure_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGeometryFigure $IID_IXpsOMGeometryFigure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IXpsOMGeometry _                    ' __out IXpsOMGeometry **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentData ( _                            ' VTable offset = 16
     BYREF dataCount AS DWORD _                         ' __in__out UINT32 *dataCount
   , BYREF segmentData AS SINGLE _                      ' __in__out FLOAT *segmentData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentTypes ( _                           ' VTable offset = 20
     BYREF segmentCount AS DWORD _                      ' __in__out UINT32 *segmentCount
   , BYREF segmentTypes AS LONG _                       ' __in__out XPS_SEGMENT_TYPE *segmentTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentStrokes ( _                         ' VTable offset = 24
     BYREF segmentCount AS DWORD _                      ' __in__out UINT32 *segmentCount
   , BYREF segmentStrokes AS LONG _                     ' __in__out BOOL *segmentStrokes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSegments ( _                               ' VTable offset = 28
     BYVAL segmentCount AS DWORD _                      ' __in UINT32 segmentCount VT_UINT <Dword>
   , BYVAL segmentDataCount AS DWORD _                  ' __in UINT32 segmentDataCount VT_UINT <Dword>
   , BYREF segmentTypes AS LONG _                       ' __in XPS_SEGMENT_TYPE *segmentTypes
   , BYREF segmentData AS SINGLE _                      ' __in const FLOAT *segmentData
   , BYREF segmentStrokes AS LONG _                     ' __in const BOOL *segmentStrokes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartPoint ( _                             ' VTable offset = 32
     BYREF startPoint AS XPS_POINT _                    ' __out XPS_POINT *startPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStartPoint ( _                             ' VTable offset = 36
     BYREF startPoint AS XPS_POINT _                    ' __in XPS_POINT *startPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsClosed ( _                               ' VTable offset = 40
     BYREF isClosed AS LONG _                           ' __out BOOL *isClosed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsClosed ( _                               ' VTable offset = 44
     BYVAL isClosed AS LONG _                           ' __in BOOL isClosed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsFilled ( _                               ' VTable offset = 48
     BYREF isFilled AS LONG _                           ' __out BOOL *isFilled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsFilled ( _                               ' VTable offset = 52
     BYVAL isFilled AS LONG _                           ' __in BOOL isFilled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentCount ( _                           ' VTable offset = 56
     BYREF segmentCount AS DWORD _                      ' __out UINT32 *segmentCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentDataCount ( _                       ' VTable offset = 60
     BYREF segmentDataCount AS DWORD _                  ' __out UINT32 *segmentDataCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSegmentStrokePattern ( _                   ' VTable offset = 64
     BYREF segmentStrokePattern AS LONG _               ' __out XPS_SEGMENT_STROKE_PATTERN *segmentStrokePattern
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 68
     BYREF geometryFigure AS IXpsOMGeometryFigure _     ' __out IXpsOMGeometryFigure **geometryFigure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGeometryFigure_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGeometryFigureCollection
' IID = {FD48C3F3-A58E-4B5A-8826-1DE54ABE72B2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMGeometryFigureCollection_INTERFACE_DEFINED)
    %IXpsOMGeometryFigureCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGeometryFigureCollection $IID_IXpsOMGeometryFigureCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF geometryFigure AS IXpsOMGeometryFigure _     ' __out IXpsOMGeometryFigure **geometryFigure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL geometryFigure AS IXpsOMGeometryFigure _     ' __in IXpsOMGeometryFigure *geometryFigure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL geometryFigure AS IXpsOMGeometryFigure _     ' __in IXpsOMGeometryFigure *geometryFigure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL geometryFigure AS IXpsOMGeometryFigure _     ' __in IXpsOMGeometryFigure *geometryFigure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGeometryFigureCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGlyphs
' IID = {819B3199-0A5A-4B64-BEC7-A9E17E780DE2}
' Inherited interface = IXpsOMVisual
' ########################################################################################

#IF NOT %DEF(%IXpsOMGlyphs_INTERFACE_DEFINED)
    %IXpsOMGlyphs_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGlyphs $IID_IXpsOMGlyphs

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMVisual Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 20
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 24
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 28
     BYVAL matrixTransform AS IXpsOMMatrixTransform _   ' __in IXpsOMMatrixTransform *matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 32
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 36
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometry ( _                           ' VTable offset = 40
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLocal ( _                      ' VTable offset = 44
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLocal ( _                      ' VTable offset = 48
     BYVAL clipGeometry AS IXpsOMGeometry _             ' __in IXpsOMGeometry *clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLookup ( _                     ' VTable offset = 52
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLookup ( _                     ' VTable offset = 56
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 60
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 64
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrush ( _                       ' VTable offset = 68
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLocal ( _                  ' VTable offset = 72
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLocal ( _                  ' VTable offset = 76
     BYVAL opacityMaskBrush AS IXpsOMBrush _            ' __in IXpsOMBrush *opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLookup ( _                 ' VTable offset = 80
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLookup ( _                 ' VTable offset = 84
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 88
     BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 92
     BYREF name AS WSTRINGZ _                           ' __in LPCWSTR name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsHyperlinkTarget ( _                      ' VTable offset = 96
     BYREF isHyperlink AS LONG _                        ' __out BOOL *isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsHyperlinkTarget ( _                      ' VTable offset = 100
     BYVAL isHyperlink AS LONG _                        ' __in BOOL isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHyperlinkNavigateUri ( _                   ' VTable offset = 104
     BYREF hyperlinkUri AS IUri _                       ' __out IUri **hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHyperlinkNavigateUri ( _                   ' VTable offset = 108
     BYVAL hyperlinkUri AS IUri _                       ' __in IUri *hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 112
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 116
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMGlyphs Methods
   ' =====================================================================================
   METHOD GetUnicodeString ( _                          ' VTable offset = 120
     BYREF unicodeString AS DWORD _                     ' __out LPWSTR *unicodeString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphIndexCount ( _                        ' VTable offset = 124
     BYREF indexCount AS DWORD _                        ' __out UINT32 *indexCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphIndices ( _                           ' VTable offset = 128
     BYREF indexCount AS DWORD _                        ' __inout UINT32 *indexCount
   , BYREF glyphIndices AS XPS_GLYPH_INDEX _            ' __inout XPS_GLYPH_INDEX *glyphIndices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphMappingCount ( _                      ' VTable offset = 132
     BYREF glyphMappingCount AS DWORD _                 ' __out UINT32 *glyphMappingCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphMappings ( _                          ' VTable offset = 136
     BYREF glyphMappingCount AS DWORD _                 ' __inout UINT32 *glyphMappingCount
   , BYREF glyphMappings AS XPS_GLYPH_MAPPING _         ' __inout XPS_GLYPH_MAPPING *glyphMappings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProhibitedCaretStopCount ( _               ' VTable offset = 140
     BYREF prohibitedCaretStopCount AS DWORD _          ' __out UINT32 *prohibitedCaretStopCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProhibitedCaretStops ( _                   ' VTable offset = 144
     BYREF prohibitedCaretStopCount AS DWORD _          ' __inout UINT32 *prohibitedCaretStopCount
   , BYREF prohibitedCaretStops AS DWORD _              ' __out UINT32 *prohibitedCaretStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBidiLevel ( _                              ' VTable offset = 148
     BYREF bidiLevel AS DWORD _                         ' __out UINT32 *bidiLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsSideways ( _                             ' VTable offset = 152
     BYREF isSideways AS LONG _                         ' __out BOOL *isSideways
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceFontName ( _                         ' VTable offset = 156
     BYREF deviceFontName AS DWORD _                    ' __out LPWSTR *deviceFontName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStyleSimulations ( _                       ' VTable offset = 160
     BYREF styleSimulations AS LONG _                   ' __out XPS_STYLE_SIMULATION *styleSimulations
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStyleSimulations ( _                       ' VTable offset = 164
     BYVAL styleSimulations AS LONG _                   ' __in XPS_STYLE_SIMULATION styleSimulations
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOrigin ( _                                 ' VTable offset = 168
     BYREF origin AS XPS_POINT _                        ' __out XPS_POINT *origin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOrigin ( _                                 ' VTable offset = 172
     BYREF origin AS XPS_POINT _                        ' __in XPS_POINT *origin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontRenderingEmSize ( _                    ' VTable offset = 176
     BYREF fontRenderingEmSize AS SINGLE _              ' __out FLOAT *fontRenderingEmSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontRenderingEmSize ( _                    ' VTable offset = 180
     BYVAL fontRenderingEmSize AS SINGLE _              ' __in FLOAT fontRenderingEmSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontResource ( _                           ' VTable offset = 184
     BYREF fontResource AS IXpsOMFontResource _         ' __out IXpsOMFontResource **fontResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontResource ( _                           ' VTable offset = 188
     BYVAL fontResource AS IXpsOMFontResource _         ' __in IXpsOMFontResource *fontResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontFaceIndex ( _                          ' VTable offset = 192
     BYREF fontFaceIndex AS INTEGER _                   ' __out SHORT *fontFaceIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontFaceIndex ( _                          ' VTable offset = 196
     BYVAL fontFaceIndex AS INTEGER _                   ' __in SHORT fontFaceIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrush ( _                              ' VTable offset = 200
     BYREF fillBrush AS IXpsOMBrush _                   ' __out IXpsOMBrush **fillBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrushLocal ( _                         ' VTable offset = 204
     BYREF fillBrush AS IXpsOMBrush _                   ' __out IXpsOMBrush **fillBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillBrushLocal ( _                         ' VTable offset = 208
     BYVAL fillBrush AS IXpsOMBrush _                   ' __in IXpsOMBrush *fillBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrushLookup ( _                        ' VTable offset = 212
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillBrushLookup ( _                        ' VTable offset = 216
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphsEditor ( _                           ' VTable offset = 220
     BYREF editor AS IXpsOMGlyphsEditor _               ' __out IXpsOMGlyphsEditor **editor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 224
     BYREF glyphs AS IXpsOMGlyphs _                     ' __out IXpsOMGlyphs **glyphs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGlyphs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGradientBrush
' IID = {EDB59622-61A2-42C3-BACE-ACF2286C06BF}
' Inherited interface = IXpsOMBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMGradientBrush_INTERFACE_DEFINED)
    %IXpsOMGradientBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGradientBrush $IID_IXpsOMGradientBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMGradientBrush Methods
   ' =====================================================================================
   METHOD GetGradientStops ( _                          ' VTable offset = 28
     BYREF gradientStops AS IXpsOMGradientStopCollection _ ' __out IXpsOMGradientStopCollection **gradientStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 36
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 40
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 48
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpreadMethod ( _                           ' VTable offset = 52
     BYREF spreadMethod AS LONG _                       ' __out XPS_SPREAD_METHOD *spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpreadMethod ( _                           ' VTable offset = 56
     BYVAL spreadMethod AS LONG _                       ' __in XPS_SPREAD_METHOD spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorInterpolationMode ( _                 ' VTable offset = 60
     BYREF colorInterpolationMode AS LONG _             ' __out XPS_COLOR_INTERPOLATION *colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorInterpolationMode ( _                 ' VTable offset = 64
     BYVAL colorInterpolationMode AS LONG _             ' __in XPS_COLOR_INTERPOLATION colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGradientBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGradientStop
' IID = {5CF4F5CC-3969-49B5-A70A-5550B618FE49}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMGradientStop_INTERFACE_DEFINED)
    %IXpsOMGradientStop_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGradientStop $IID_IXpsOMGradientStop

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IXpsOMGradientBrush _               ' __out IXpsOMGradientBrush **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOffset ( _                                 ' VTable offset = 16
     BYREF offset AS SINGLE _                           ' __out FLOAT *offset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOffset ( _                                 ' VTable offset = 20
     BYVAL offset AS SINGLE _                           ' __in FLOAT offset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 24
     BYREF color AS XPS_COLOR _                         ' __out XPS_COLOR *color
   , BYREF colorProfile AS IXpsOMColorProfileResource _ ' __out IXpsOMColorProfileResource **colorProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 28
     BYREF color AS XPS_COLOR _                         ' __in XPS_COLOR *color
   , BYVAL colorProfile AS IXpsOMColorProfileResource _ ' __in IXpsOMColorProfileResource *colorProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 32
     BYREF gradientStop AS IXpsOMGradientStop _         ' __out IXpsOMGradientStop **gradientStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGradientStop_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGradientStopCollection
' IID = {C9174C3A-3CD3-4319-BDA4-11A39392CEEF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMGradientStopCollection_INTERFACE_DEFINED)
    %IXpsOMGradientStopCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGradientStopCollection $IID_IXpsOMGradientStopCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in index VT_UINT <Dword>
   , BYREF stop AS IXpsOMGradientStop _                 ' __out IXpsOMGradientStop **stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL stop AS IXpsOMGradientStop _                 ' __in IXpsOMGradientStop *stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL stop AS IXpsOMGradientStop _                 ' __in IXpsOMGradientStop *stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL stop AS IXpsOMGradientStop _                 ' __in IXpsOMGradientStop *stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGradientStopCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMImageBrush
' IID = {3DF0B466-D382-49EF-8550-DD94C80242E4}
' Inherited interface = IXpsOMTileBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMImageBrush_INTERFACE_DEFINED)
    %IXpsOMImageBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMImageBrush $IID_IXpsOMImageBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMTileBrush Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 36
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 40
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewbox ( _                                ' VTable offset = 48
     BYREF viewbox AS XPS_RECT _                        ' __out XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewbox ( _                                ' VTable offset = 52
     BYREF viewbox AS XPS_RECT _                        ' __in XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 56
     BYREF viewport AS XPS_RECT _                       ' __out XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 60
     BYREF viewport AS XPS_RECT _                       ' __in XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTileMode ( _                               ' VTable offset = 64
     BYREF tileMode AS LONG _                           ' __out XPS_TILE_MODE *tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTileMode ( _                               ' VTable offset = 68
     BYVAL tileMode AS LONG _                           ' __in XPS_TILE_MODE tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMImageBrush Methods
   ' =====================================================================================
   METHOD GetImageResource ( _                          ' VTable offset = 72
     BYREF imageResource AS IXpsOMImageResource _       ' __out IXpsOMImageResource **imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImageResource ( _                          ' VTable offset = 76
     BYVAL imageResource AS IXpsOMImageResource _       ' __in IXpsOMImageResource *imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorProfileResource ( _                   ' VTable offset = 80
     BYREF colorProfileResource AS IXpsOMColorProfileResource _ ' __out IXpsOMColorProfileResource **colorProfileResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorProfileResource ( _                   ' VTable offset = 84
     BYVAL colorProfileResource AS IXpsOMColorProfileResource _ ' __in IXpsOMColorProfileResource *colorProfileResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 88
     BYREF imageBrush AS IXpsOMImageBrush _             ' __out IXpsOMImageBrush **imageBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMImageBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMImageResource
' IID = {3DB8417D-AE50-485E-9A44-D7758F78A23F}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMImageResource_INTERFACE_DEFINED)
    %IXpsOMImageResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMImageResource $IID_IXpsOMImageResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMImageResource Methods
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 20
     BYREF readerStream AS IStream _                    ' __out IStream **readerStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 24
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL imageType AS LONG _                          ' __in XPS_IMAGE_TYPE imageType
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageType ( _                              ' VTable offset = 28
     BYREF imageType AS LONG _                          ' __out XPS_IMAGE_TYPE *imageType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMImageResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMImageResourceCollection
' IID = {7A4A1A71-9CDE-4B71-B33F-62DE843EABFE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMImageResourceCollection_INTERFACE_DEFINED)
    %IXpsOMImageResourceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMImageResourceCollection $IID_IXpsOMImageResourceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF object AS IXpsOMImageResource _              ' __out IXpsOMImageResource **object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMImageResource _              ' __in IXpsOMImageResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMImageResource _              ' __in IXpsOMImageResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL object AS IXpsOMImageResource _              ' __in IXpsOMImageResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByPartName ( _                             ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYREF part AS IXpsOMImageResource _                ' __out IXpsOMImageResource **part
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMImageResourceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMLinearGradientBrush
' IID = {005E279F-C30D-40FF-93EC-1950D3C528DB}
' Inherited interface = IXpsOMGradientBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMLinearGradientBrush_INTERFACE_DEFINED)
    %IXpsOMLinearGradientBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMLinearGradientBrush $IID_IXpsOMLinearGradientBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMGradientBrush Methods
   ' =====================================================================================
   METHOD GetGradientStops ( _                          ' VTable offset = 28
     BYREF gradientStops AS IXpsOMGradientStopCollection _ ' __out IXpsOMGradientStopCollection **gradientStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 36
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 40
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 48
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpreadMethod ( _                           ' VTable offset = 52
     BYREF spreadMethod AS LONG _                       ' __out XPS_SPREAD_METHOD *spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpreadMethod ( _                           ' VTable offset = 56
     BYVAL spreadMethod AS LONG _                       ' __in XPS_SPREAD_METHOD spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorInterpolationMode ( _                 ' VTable offset = 60
     BYREF colorInterpolationMode AS LONG _             ' __out XPS_COLOR_INTERPOLATION *colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorInterpolationMode ( _                 ' VTable offset = 64
     BYVAL colorInterpolationMode AS LONG _             ' __in XPS_COLOR_INTERPOLATION colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMLinearGradientBrush Methods
   ' =====================================================================================
   METHOD GetStartPoint ( _                             ' VTable offset = 68
     BYREF startPoint AS XPS_POINT _                    ' __out XPS_POINT *startPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStartPoint ( _                             ' VTable offset = 72
     BYREF startPoint AS XPS_POINT _                    ' __in XPS_POINT *startPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEndPoint ( _                               ' VTable offset = 76
     BYREF endPoint AS XPS_POINT _                      ' __out XPS_POINT *endPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEndPoint ( _                               ' VTable offset = 80
     BYREF endPoint AS XPS_POINT _                      ' __in XPS_POINT *endPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 84
     BYREF linearGradientBrush AS IXpsOMLinearGradientBrush _ ' __out IXpsOMLinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMLinearGradientBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMMatrixTransform
' IID = {B77330FF-BB37-4501-A93E-F1B1E50BFC46}
' Inherited interface = IXpsOMShareable
' ########################################################################################

#IF NOT %DEF(%IXpsOMMatrixTransform_INTERFACE_DEFINED)
    %IXpsOMMatrixTransform_INTERFACE_DEFINED = 1

INTERFACE IXpsOMMatrixTransform $IID_IXpsOMMatrixTransform

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMMatrixTransform Methods
   ' =====================================================================================
   METHOD GetMatrix ( _                                 ' VTable offset = 20
     BYREF matrix AS XPS_MATRIX _                       ' __out XPS_MATRIX *matrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 24
     BYREF matrix AS XPS_MATRIX _                       ' __in XPS_MATRIX *matrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 28
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMMatrixTransform_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPartResources
' IID = {F4CF7729-4864-4275-99B3-A8717163ECAF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPartResources_INTERFACE_DEFINED)
    %IXpsOMPartResources_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPartResources $IID_IXpsOMPartResources

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFontResources ( _                          ' VTable offset = 12
     BYREF fontResources AS IXpsOMFontResourceCollection _ ' __out IXpsOMFontResourceCollection **fontResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageResources ( _                         ' VTable offset = 16
     BYREF imageResources AS IXpsOMImageResourceCollection _ ' __out IXpsOMImageResourceCollection **imageResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorProfileResources ( _                  ' VTable offset = 20
     BYREF colorProfileResources AS IXpsOMColorProfileResourceCollection _ ' ' __out IXpsOMColorProfileResourceCollection **colorProfileResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRemoteDictionaryResources ( _              ' VTable offset = 24
     BYREF dictionaryResources AS IXpsOMRemoteDictionaryResourceCollection _ ' __out IXpsOMRemoteDictionaryResourceCollection **dictionaryResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPartResources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPath
' IID = {37D38BB6-3EE9-4110-9312-14B194163337}
' Inherited interface = IXpsOMVisual
' ########################################################################################

#IF NOT %DEF(%IXpsOMPath_INTERFACE_DEFINED)
    %IXpsOMPath_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPath $IID_IXpsOMPath

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMVisual Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 20
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 24
     BYREF matrixTransform AS IXpsOMMatrixTransform _   ' __out IXpsOMMatrixTransform **matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 28
     BYVAL matrixTransform AS IXpsOMMatrixTransform _   ' __in IXpsOMMatrixTransform *matrixTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 32
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 36
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometry ( _                           ' VTable offset = 40
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLocal ( _                      ' VTable offset = 44
     BYREF clipGeometry AS IXpsOMGeometry _             ' __out IXpsOMGeometry **clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLocal ( _                      ' VTable offset = 48
     BYVAL clipGeometry AS IXpsOMGeometry _             ' __in IXpsOMGeometry *clipGeometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipGeometryLookup ( _                     ' VTable offset = 52
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipGeometryLookup ( _                     ' VTable offset = 56
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 60
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 64
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrush ( _                       ' VTable offset = 68
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLocal ( _                  ' VTable offset = 72
     BYREF opacityMaskBrush AS IXpsOMBrush _            ' __out IXpsOMBrush **opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLocal ( _                  ' VTable offset = 76
     BYVAL opacityMaskBrush AS IXpsOMBrush _            ' __in IXpsOMBrush *opacityMaskBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacityMaskBrushLookup ( _                 ' VTable offset = 80
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacityMaskBrushLookup ( _                 ' VTable offset = 84
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 88
     BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 92
     BYREF name AS WSTRINGZ _                           ' __in LPCWSTR name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsHyperlinkTarget ( _                      ' VTable offset = 96
     BYREF isHyperlink AS LONG _                        ' __out BOOL *isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsHyperlinkTarget ( _                      ' VTable offset = 100
     BYVAL isHyperlink AS LONG _                        ' __in BOOL isHyperlink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHyperlinkNavigateUri ( _                   ' VTable offset = 104
     BYREF hyperlinkUri AS IUri _                       ' __out IUri **hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHyperlinkNavigateUri ( _                   ' VTable offset = 108
     BYVAL hyperlinkUri AS IUri _                       ' __in IUri *hyperlinkUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 112
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 116
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMPath Methods
   ' =====================================================================================
   METHOD GetGeometry ( _                               ' VTable offset = 120
     BYREF geometry AS IXpsOMGeometry _                 ' __out IXpsOMGeometry **geometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGeometryLocal ( _                          ' VTable offset = 124
     BYREF geometry AS IXpsOMGeometry _                 ' __out IXpsOMGeometry **geometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGeometryLocal ( _                          ' VTable offset = 128
     BYVAL geometry AS IXpsOMGeometry _                 ' __in IXpsOMGeometry *geometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGeometryLookup ( _                         ' VTable offset = 132
     BYREF lookup AS DWORD _                            ' __out LPWSTR *lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGeometryLookup ( _                         ' VTable offset = 136
     BYREF lookup AS WSTRINGZ _                         ' __in LPCWSTR lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccessibilityShortDescription ( _          ' VTable offset = 140
     BYREF shortDescription AS DWORD _                  ' __out LPWSTR *shortDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessibilityShortDescription ( _          ' VTable offset = 144
     BYREF shortDescription AS WSTRINGZ _               ' __in LPCWSTR shortDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccessibilityLongDescription ( _           ' VTable offset = 148
     BYREF longDescription AS DWORD _                   ' __out LPWSTR *longDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessibilityLongDescription ( _           ' VTable offset = 152
     BYREF longDescription AS WSTRINGZ _                ' __in LPCWSTR longDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSnapsToPixels ( _                          ' VTable offset = 156
     BYREF snapsToPixels AS LONG _                      ' __out BOOL *snapsToPixels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSnapsToPixels ( _                          ' VTable offset = 160
     BYVAL snapsToPixels AS LONG _                      ' __in BOOL snapsToPixels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeBrush ( _                            ' VTable offset = 164
     BYREF brush AS IXpsOMBrush _                       ' __out IXpsOMBrush **brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeBrushLocal ( _                       ' VTable offset = 168
     BYREF brush AS IXpsOMBrush _                       ' __out IXpsOMBrush **brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeBrushLocal ( _                       ' VTable offset = 172
     BYVAL brush AS IXpsOMBrush _                       ' __in IXpsOMBrush *brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeBrushLookup ( _                      ' VTable offset = 176
     BYREF lookup AS DWORD _                            ' __out LPWSTR *lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeBrushLookup ( _                      ' VTable offset = 180
     BYREF lookup AS WSTRINGZ _                         ' __in LPCWSTR lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeDashes ( _                           ' VTable offset = 184
     BYREF strokeDashes AS IXpsOMDashCollection _       ' __out IXpsOMDashCollection **strokeDashes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeDashCap ( _                          ' VTable offset = 188
     BYREF strokeDashCap AS LONG _                      ' __out XPS_DASH_CAP *strokeDashCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeDashCap ( _                          ' VTable offset = 192
     BYVAL strokeDashCap AS LONG _                      ' __in XPS_DASH_CAP strokeDashCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeDashOffset ( _                       ' VTable offset = 196
     BYREF strokeDashOffset AS SINGLE _                 ' __out FLOAT *strokeDashOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeDashOffset ( _                       ' VTable offset = 200
     BYVAL strokeDashOffset AS SINGLE _                 ' __in FLOAT strokeDashOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeStartLineCap ( _                     ' VTable offset = 204
     BYREF strokeStartLineCap AS LONG _                 ' __out XPS_LINE_CAP *strokeStartLineCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeStartLineCap ( _                     ' VTable offset = 208
     BYVAL strokeStartLineCap AS LONG _                 ' __in XPS_LINE_CAP strokeStartLineCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeEndLineCap ( _                       ' VTable offset = 212
     BYREF strokeEndLineCap AS LONG _                   ' __out XPS_LINE_CAP *strokeEndLineCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeEndLineCap ( _                       ' VTable offset = 216
     BYVAL strokeEndLineCap AS LONG _                   ' __in XPS_LINE_CAP strokeEndLineCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeLineJoin ( _                         ' VTable offset = 220
     BYREF strokeLineJoin AS LONG _                     ' __out XPS_LINE_JOIN *strokeLineJoin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeLineJoin ( _                         ' VTable offset = 224
     BYVAL strokeLineJoin AS LONG _                     ' __in XPS_LINE_JOIN strokeLineJoin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeMiterLimit ( _                       ' VTable offset = 228
     BYREF strokeMiterLimit AS SINGLE _                 ' __out FLOAT *strokeMiterLimit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeMiterLimit ( _                       ' VTable offset = 232
     BYVAL strokeMiterLimit AS SINGLE _                 ' __in FLOAT strokeMiterLimit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeThickness ( _                        ' VTable offset = 236
     BYREF strokeThickness AS SINGLE _                  ' __out FLOAT *strokeThickness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeThickness ( _                        ' VTable offset = 240
     BYVAL strokeThickness AS SINGLE _                  ' __in FLOAT strokeThickness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrush ( _                              ' VTable offset = 244
     BYREF brush AS IXpsOMBrush _                       ' __out IXpsOMBrush **brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrushLocal ( _                         ' VTable offset = 248
     BYREF brush AS IXpsOMBrush _                       ' __out IXpsOMBrush **brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillBrushLocal ( _                         ' VTable offset = 252
     BYVAL brush AS IXpsOMBrush _                       ' __in IXpsOMBrush *brush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillBrushLookup ( _                        ' VTable offset = 256
     BYREF lookup AS DWORD _                            ' __out LPWSTR *lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFillBrushLookup ( _                        ' VTable offset = 260
     BYREF lookup AS WSTRINGZ _                         ' __in LPCWSTR lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 264
     BYREF path AS IXpsOMPath _                         ' __out IXpsOMPath **path
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPath_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPartUriCollection
' IID = {57C650D4-067C-4893-8C33-F62A0633730F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPartUriCollection_INTERFACE_DEFINED)
    %IXpsOMPartUriCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPartUriCollection $IID_IXpsOMPartUriCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPartUriCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMRadialGradientBrush
' IID = {75F207E5-08BF-413C-96B1-B82B4064176B}
' Inherited interface = IXpsOMGradientBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMRadialGradientBrush_INTERFACE_DEFINED)
    %IXpsOMRadialGradientBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMRadialGradientBrush $IID_IXpsOMRadialGradientBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMGradientBrush Methods
   ' =====================================================================================
   METHOD GetGradientStops ( _                          ' VTable offset = 28
     BYREF gradientStops AS IXpsOMGradientStopCollection _ ' __out IXpsOMGradientStopCollection **gradientStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 36
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 40
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 48
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpreadMethod ( _                           ' VTable offset = 52
     BYREF spreadMethod AS LONG _                       ' __out XPS_SPREAD_METHOD *spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpreadMethod ( _                           ' VTable offset = 56
     BYVAL spreadMethod AS LONG _                       ' __in XPS_SPREAD_METHOD spreadMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorInterpolationMode ( _                 ' VTable offset = 60
     BYREF colorInterpolationMode AS LONG _             ' __out XPS_COLOR_INTERPOLATION *colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorInterpolationMode ( _                 ' VTable offset = 64
     BYVAL colorInterpolationMode AS LONG _             ' __in XPS_COLOR_INTERPOLATION colorInterpolationMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMRadialGradientBrush Methods
   ' =====================================================================================
   METHOD GetCenter ( _                                 ' VTable offset = 68
     BYREF center AS XPS_POINT _                        ' __out XPS_POINT *center
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCenter ( _                                 ' VTable offset = 72
     BYREF center AS XPS_POINT _                        ' __in XPS_POINT *center
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRadiiSizes ( _                             ' VTable offset = 76
     BYREF radiiSizes AS XPS_SIZE _                     ' __out XPS_SIZE *radiiSizes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRadiiSizes ( _                             ' VTable offset = 80
     BYREF radiiSizes AS XPS_SIZE _                     ' __in XPS_SIZE *radiiSizes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGradientOrigin ( _                         ' VTable offset = 84
     BYREF origin AS XPS_POINT _                        ' __out XPS_POINT *origin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGradientOrigin ( _                         ' VTable offset = 88
     BYREF origin AS XPS_POINT _                        ' __in XPS_POINT *origin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 92
     BYREF radialGradientBrush AS IXpsOMRadialGradientBrush _ ' __out IXpsOMRadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMRadialGradientBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMRemoteDictionaryResource
' IID = {C9BD7CD4-E16A-4BF8-8C84-C950AF7A3061}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMRemoteDictionaryResource_INTERFACE_DEFINED)
    %IXpsOMRemoteDictionaryResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMRemoteDictionaryResource $IID_IXpsOMRemoteDictionaryResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMRemoteDictionaryResource Methods
   ' =====================================================================================
   METHOD GetDictionary ( _                             ' VTable offset = 20
     BYREF dictionary AS IXpsOMDictionary _             ' __out IXpsOMDictionary **dictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictionary ( _                             ' VTable offset = 24
     BYVAL dictionary AS IXpsOMDictionary _             ' __in IXpsOMDictionary *dictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMRemoteDictionaryResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMRemoteDictionaryResourceCollection
' IID = {5C38DB61-7FEC-464A-87BD-41E3BEF018BE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMRemoteDictionaryResourceCollection_INTERFACE_DEFINED)
    %IXpsOMRemoteDictionaryResourceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMRemoteDictionaryResourceCollection $IID_IXpsOMRemoteDictionaryResourceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF object AS IXpsOMRemoteDictionaryResource _   ' __out IXpsOMRemoteDictionaryResource **object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMRemoteDictionaryResource _   ' __in IXpsOMRemoteDictionaryResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMRemoteDictionaryResource _   ' __in IXpsOMRemoteDictionaryResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL object AS IXpsOMRemoteDictionaryResource _   ' __in IXpsOMRemoteDictionaryResource *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByPartName ( _                             ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYREF remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __out IXpsOMRemoteDictionaryResource **remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMRemoteDictionaryResourceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDictionary
' IID = {897C86B8-8EAF-4AE3-BDDE-56419FCF4236}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMDictionary_INTERFACE_DEFINED)
    %IXpsOMDictionary_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDictionary $IID_IXpsOMDictionary

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF key AS DWORD _                               ' __out LPWSTR *key
   , BYREF entry AS IXpsOMShareable _                   ' __out IXpsOMShareable **entry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByKey ( _                                  ' VTable offset = 24
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   , BYVAL beforeEntry AS IXpsOMShareable _             ' __in IXpsOMShareable *beforeEntry
   , BYREF entry AS IXpsOMShareable _                   ' __out IXpsOMShareable **entry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 28
     BYVAL entry AS IXpsOMShareable _                   ' __in IXpsOMShareable *entry
   , BYREF index AS DWORD _                             ' __out UINT32 *index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   , BYVAL entry AS IXpsOMShareable _                   ' __in IXpsOMShareable *entry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 36
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   , BYVAL entry AS IXpsOMShareable _                   ' __in IXpsOMShareable *entry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 40
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 44
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   , BYVAL entry AS IXpsOMShareable _                   ' __in IXpsOMShareable *entry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 48
     BYREF dictionary AS IXpsOMDictionary _             ' __out IXpsOMDictionary **dictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMSolidColorBrush
' IID = {A06F9F05-3BE9-4763-98A8-094FC672E488}
' Inherited interface = IXpsOMBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMSolidColorBrush_INTERFACE_DEFINED)
    %IXpsOMSolidColorBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMSolidColorBrush $IID_IXpsOMSolidColorBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMSolidColorBrush Methods
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 28
     BYREF color AS XPS_COLOR _                         ' __out XPS_COLOR *color
   , BYREF colorProfile AS IXpsOMColorProfileResource _ ' __out IXpsOMColorProfileResource **colorProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 32
     BYREF color AS XPS_COLOR _                         ' __in XPS_COLOR *color
   , BYVAL colorProfile AS IXpsOMColorProfileResource _ ' __in IXpsOMColorProfileResource *colorProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 36
     BYREF solidColorBrush AS IXpsOMSolidColorBrush _   ' __out IXpsOMSolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMSolidColorBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMVisualBrush
' IID = {97E294AF-5B37-46B4-8057-874D2F64119B}
' Inherited interface = IXpsOMTileBrush
' ########################################################################################

#IF NOT %DEF(%IXpsOMVisualBrush_INTERFACE_DEFINED)
    %IXpsOMVisualBrush_INTERFACE_DEFINED = 1

INTERFACE IXpsOMVisualBrush $IID_IXpsOMVisualBrush

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMShareable Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF owner AS IUnknown _                          ' __out IUnknown **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF type AS LONG _                               ' __out XPS_OBJECT_TYPE *type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMBrush Methods
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 20
     BYREF opacity AS SINGLE _                          ' __out FLOAT *opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 24
     BYVAL opacity AS SINGLE _                          ' __in FLOAT opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMTileBrush Methods
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 28
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLocal ( _                         ' VTable offset = 32
     BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLocal ( _                         ' VTable offset = 36
     BYVAL transform AS IXpsOMMatrixTransform _         ' __in IXpsOMMatrixTransform *transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransformLookup ( _                        ' VTable offset = 40
     BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformLookup ( _                        ' VTable offset = 44
     BYREF key AS WSTRINGZ _                            ' __in LPCWSTR key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewbox ( _                                ' VTable offset = 48
     BYREF viewbox AS XPS_RECT _                        ' __out XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewbox ( _                                ' VTable offset = 52
     BYREF viewbox AS XPS_RECT _                        ' __in XPS_RECT *viewbox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 56
     BYREF viewport AS XPS_RECT _                       ' __out XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 60
     BYREF viewport AS XPS_RECT _                       ' __in XPS_RECT *viewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTileMode ( _                               ' VTable offset = 64
     BYREF tileMode AS LONG _                           ' __out XPS_TILE_MODE *tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTileMode ( _                               ' VTable offset = 68
     BYVAL tileMode AS LONG _                           ' __in XPS_TILE_MODE tileMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMVisualBrush Methods
   ' =====================================================================================
   METHOD GetVisual ( _                                 ' VTable offset = 72
     BYREF visual AS IXpsOMVisual _                     ' __out IXpsOMVisual **visual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVisualLocal ( _                            ' VTable offset = 76
     BYREF visual AS IXpsOMVisual _                     ' __out IXpsOMVisual **visual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVisualLocal ( _                            ' VTable offset = 80
     BYVAL visual AS IXpsOMVisual _                     ' __in IXpsOMVisual *visual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVisualLookup ( _                           ' VTable offset = 84
     BYREF lookup AS DWORD _                            ' __out LPWSTR *lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVisualLookup ( _                           ' VTable offset = 88
     BYREF lookup AS WSTRINGZ _                         ' __in LPCWSTR lookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 92
     BYREF visualBrush AS IXpsOMVisualBrush _           ' __out IXpsOMVisualBrush **visualBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMVisualBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMVisualCollection
' IID = {94D8ABDE-AB91-46A8-82B7-F5B05EF01A96}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMVisualCollection_INTERFACE_DEFINED)
    %IXpsOMVisualCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMVisualCollection $IID_IXpsOMVisualCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF object AS IXpsOMVisual _                     ' __out IXpsOMVisual **object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMVisual _                     ' __in IXpsOMVisual *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL object AS IXpsOMVisual _                     ' __in IXpsOMVisual *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL object AS IXpsOMVisual _                     ' __in IXpsOMVisual *object
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMVisualCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPageReference
' IID = {ED360180-6F92-4998-890D-2F208531A0A0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPageReference_INTERFACE_DEFINED)
    %IXpsOMPageReference_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPageReference $IID_IXpsOMPageReference

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 12
     BYREF document AS IXpsOMDocument _                 ' __out IXpsOMDocument **document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPage ( _                                   ' VTable offset = 16
     BYREF page AS IXpsOMPage _                         ' __out IXpsOMPage **page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPage ( _                                   ' VTable offset = 20
     BYVAL page AS IXpsOMPage _                         ' __in IXpsOMPage *page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardPage ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPageLoaded ( _                              ' VTable offset = 28
     BYREF IsPageLoaded AS LONG _                       ' __out BOOL *IsPageLoaded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdvisoryPageDimensions ( _                 ' VTable offset = 32
     BYREF pageDimensions AS XPS_SIZE _                 ' __out XPS_SIZE *pageDimensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdvisoryPageDimensions ( _                 ' VTable offset = 36
     BYREF pageDimensions AS XPS_SIZE _                 ' __in XPS_SIZE *pageDimensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStoryFragmentsResource ( _                 ' VTable offset = 40
     BYREF storyFragmentsResource AS IXpsOMStoryFragmentsResource _ ' __out IXpsOMStoryFragmentsResource **storyFragmentsResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStoryFragmentsResource ( _                 ' VTable offset = 44
     BYVAL storyFragmentsResource AS IXpsOMStoryFragmentsResource _ ' __in IXpsOMStoryFragmentsResource *storyFragmentsResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrintTicketResource ( _                    ' VTable offset = 48
     BYREF printTicketResource AS IXpsOMPrintTicketResource _ ' __out IXpsOMPrintTicketResource **printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrintTicketResource ( _                    ' VTable offset = 52
     BYVAL printTicketResource AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnailResource ( _                      ' VTable offset = 56
     BYREF imageResource AS IXpsOMImageResource _       ' __out IXpsOMImageResource **imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailResource ( _                      ' VTable offset = 60
     BYVAL imageResource AS IXpsOMImageResource _       ' __in IXpsOMImageResource *imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollectLinkTargets ( _                        ' VTable offset = 64
     BYREF linkTargets AS IXpsOMNameCollection _        ' __out IXpsOMNameCollection **linkTargets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollectPartResources ( _                      ' VTable offset = 68
     BYREF partResources AS IXpsOMPartResources _       ' __out IXpsOMPartResources **partResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasRestrictedFonts ( _                        ' VTable offset = 72
     BYREF restrictedFonts AS LONG _                    ' __out BOOL *restrictedFonts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 76
     BYREF pageReference AS IXpsOMPageReference _       ' __out IXpsOMPageReference **pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPageReference_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDocumentSequence
' IID = {56492EB4-D8D5-425E-8256-4C2B64AD0264}
' Inherited interface = IXpsOMPart
' ########################################################################################

#IF NOT %DEF(%IXpsOMDocumentSequence_INTERFACE_DEFINED)
    %IXpsOMDocumentSequence_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDocumentSequence $IID_IXpsOMDocumentSequence

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMDocumentSequence Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF package AS IXpsOMPackage _                   ' __out IXpsOMPackage **package
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocuments ( _                              ' VTable offset = 24
     BYREF documents AS IXpsOMDocumentCollection _      ' __out IXpsOMDocumentCollection **documents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrintTicketResource ( _                    ' VTable offset = 28
     BYREF printTicketResource AS IXpsOMPrintTicketResource _ ' __out IXpsOMPrintTicketResource **printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrintTicketResource ( _                    ' VTable offset = 32
     BYVAL printTicketResource AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDocumentSequence_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMSignatureBlockResource
' IID = {4776AD35-2E04-4357-8743-EBF6C171A905}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMSignatureBlockResource_INTERFACE_DEFINED)
    %IXpsOMSignatureBlockResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMSignatureBlockResource $IID_IXpsOMSignatureBlockResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMSignatureBlockResource Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF owner AS IXpsOMDocument _                    ' __out IXpsOMDocument **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 24
     BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 28
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMSignatureBlockResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMSignatureBlockResourceCollection
' IID = {AB8F5D8E-351B-4D33-AAED-FA56F0022931}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMSignatureBlockResourceCollection_INTERFACE_DEFINED)
    %IXpsOMSignatureBlockResourceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMSignatureBlockResourceCollection $IID_IXpsOMSignatureBlockResourceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF signatureBlockResource AS IXpsOMSignatureBlockResource _ ' ' __out IXpsOMSignatureBlockResource **signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL signatureBlockResource AS IXpsOMSignatureBlockResource _ ' __in IXpsOMSignatureBlockResource *signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL signatureBlockResource AS IXpsOMSignatureBlockResource _ ' __in IXpsOMSignatureBlockResource *signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL signatureBlockResource AS IXpsOMSignatureBlockResource _ ' __in IXpsOMSignatureBlockResource *signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetByPartName ( _                             ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYREF signatureBlockResource AS IXpsOMSignatureBlockResource _ ' __out IXpsOMSignatureBlockResource **signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMSignatureBlockResourceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMNameCollection
' IID = {4BDDF8EC-C915-421B-A166-D173D25653D2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMNameCollection_INTERFACE_DEFINED)
    %IXpsOMNameCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMNameCollection $IID_IXpsOMNameCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMNameCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDocument
' IID = {2C2C94CB-AC5F-4254-8EE9-23948309D9F0}
' Inherited interface = IXpsOMPart
' ########################################################################################

#IF NOT %DEF(%IXpsOMDocument_INTERFACE_DEFINED)
    %IXpsOMDocument_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDocument $IID_IXpsOMDocument

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMDocument Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF documentSequence AS IXpsOMDocumentSequence _ ' __out IXpsOMDocumentSequence **documentSequence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageReferences ( _                         ' VTable offset = 24
     BYREF pageReferences AS IXpsOMPageReferenceCollection _ ' __out IXpsOMPageReferenceCollection **pageReferences
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrintTicketResource ( _                    ' VTable offset = 28
     BYREF printTicketResource AS IXpsOMPrintTicketResource _ ' __out IXpsOMPrintTicketResource **printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrintTicketResource ( _                    ' VTable offset = 32
     BYVAL printTicketResource AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentStructureResource ( _              ' VTable offset = 36
     BYREF documentStructureResource AS IXpsOMDocumentStructureResource _ ' __out IXpsOMDocumentStructureResource **documentStructureResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocumentStructureResource ( _              ' VTable offset = 40
     BYVAL documentStructureResource AS IXpsOMDocumentStructureResource _ ' __in IXpsOMDocumentStructureResource *documentStructureResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureBlockResources ( _                ' VTable offset = 44
     BYREF signatureBlockResources AS IXpsOMSignatureBlockResourceCollection _ ' __out IXpsOMSignatureBlockResourceCollection **signatureBlockResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 48
     BYREF document AS IXpsOMDocument _                 ' __out IXpsOMDocument **document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPage
' IID = {D3E18888-F120-4FEE-8C68-35296EAE91D4}
' Inherited interface = IXpsOMPart
' ########################################################################################

#IF NOT %DEF(%IXpsOMPage_INTERFACE_DEFINED)
    %IXpsOMPage_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPage $IID_IXpsOMPage

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMPage Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF pageReference AS IXpsOMPageReference _       ' __out IXpsOMPageReference **pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVisuals ( _                                ' VTable offset = 24
     BYREF visuals AS IXpsOMVisualCollection _          ' __out IXpsOMVisualCollection **visuals
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageDimensions ( _                         ' VTable offset = 28
     BYREF pageDimensions AS XPS_SIZE _                 ' __out XPS_SIZE *pageDimensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPageDimensions ( _                         ' VTable offset = 32
     BYREF pageDimensions AS XPS_SIZE _                 ' __in XPS_SIZE *pageDimensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentBox ( _                             ' VTable offset = 36
     BYREF contentBox AS XPS_RECT _                     ' __out XPS_RECT *contentBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentBox ( _                             ' VTable offset = 40
     BYREF contentBox AS XPS_RECT _                     ' __in XPS_RECT *contentBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBleedBox ( _                               ' VTable offset = 44
     BYREF bleedBox AS XPS_RECT _                       ' __out XPS_RECT *bleedBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBleedBox ( _                               ' VTable offset = 48
     BYREF bleedBox AS XPS_RECT _                       ' __in XPS_RECT *bleedBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 52
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 56
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 60
     BYREF name AS DWORD _                              ' __out LPWSTR *name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 64
     BYREF name AS WSTRINGZ _                            ' __in LPCWSTR name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsHyperlinkTarget ( _                      ' VTable offset = 68
     BYREF isHyperlinkTarget AS LONG _                  ' __out BOOL *isHyperlinkTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsHyperlinkTarget ( _                      ' VTable offset = 72
     BYVAL isHyperlinkTarget AS LONG _                  ' __in BOOL isHyperlinkTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionary ( _                             ' VTable offset = 76
     BYREF resourceDictionary AS IXpsOMDictionary _     ' __out IXpsOMDictionary **resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionaryLocal ( _                        ' VTable offset = 80
     BYREF resourceDictionary AS IXpsOMDictionary _     ' __out IXpsOMDictionary **resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictionaryLocal ( _                        ' VTable offset = 84
     BYVAL resourceDictionary AS IXpsOMDictionary _     ' __in IXpsOMDictionary *resourceDictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDictionaryResource ( _                     ' VTable offset = 88
     BYREF remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __out IXpsOMRemoteDictionaryResource **remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictionaryResource ( _                     ' VTable offset = 92
     BYVAL remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __in IXpsOMRemoteDictionaryResource *remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 96
     BYVAL stream AS ISequentialStream _                ' __in ISequentialStream *stream
   , BYVAL optimizeMarkupSize AS LONG _                 ' __in BOOL optimizeMarkupSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateUnusedLookupKey ( _                   ' VTable offset = 100
     BYVAL type AS LONG _                               ' __in XPS_OBJECT_TYPE type
   , BYREF key AS DWORD _                               ' __out LPWSTR *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 104
     BYREF page AS IXpsOMPage _                         ' __out IXpsOMPage **page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPackageWriter
' IID = {4E2AA182-A443-42C6-B41B-4F8E9DE73FF9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPackageWriter_INTERFACE_DEFINED)
    %IXpsOMPackageWriter_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPackageWriter $IID_IXpsOMPackageWriter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartNewDocument ( _                          ' VTable offset = 12
     BYVAL documentPartName AS IOpcPartUri _            ' __in IOpcPartUri *documentPartName
   , BYVAL documentPrintTicket AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *documentPrintTicket
   , BYVAL documentStructure AS IXpsOMDocumentStructureResource _ ' __in IXpsOMDocumentStructureResource *documentStructure
   , BYVAL signatureBlockResources AS IXpsOMSignatureBlockResourceCollection _ ' __in IXpsOMSignatureBlockResourceCollection *signatureBlockResources
   , BYVAL restrictedFonts AS IXpsOMPartUriCollection _ ' __in IXpsOMPartUriCollection *restrictedFonts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPage ( _                                   ' VTable offset = 16
     BYVAL page AS IXpsOMPage _                         ' __in IXpsOMPage *page
   , BYREF advisoryPageDimensions AS XPS_SIZE _         ' __in XPS_SIZE *advisoryPageDimensions
   , BYVAL discardableResourceParts AS IXpsOMPartUriCollection _ ' __in IXpsOMPartUriCollection *discardableResourceParts
   , BYVAL storyFragments AS IXpsOMStoryFragmentsResource _ ' __in IXpsOMStoryFragmentsResource *storyFragments
   , BYVAL pagePrintTicket AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *pagePrintTicket
   , BYVAL pageThumbnail AS IXpsOMImageResource _       ' __in IXpsOMImageResource *pageThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddResource ( _                               ' VTable offset = 20
     BYVAL resource AS IXpsOMResource _                 ' __in IXpsOMResource *resource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD isClosed ( _                                  ' VTable offset = 28
     BYREF isClosed AS LONG _                           ' __out BOOL *isClosed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPackageWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMGlyphsEditor
' IID = {A5AB8616-5B16-4B9F-9629-89B323ED7909}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMGlyphsEditor_INTERFACE_DEFINED)
    %IXpsOMGlyphsEditor_INTERFACE_DEFINED = 1

INTERFACE IXpsOMGlyphsEditor $IID_IXpsOMGlyphsEditor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ApplyEdits ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnicodeString ( _                          ' VTable offset = 16
     BYREF unicodeString AS DWORD _                     ' __out LPWSTR *unicodeString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnicodeString ( _                          ' VTable offset = 20
     BYREF unicodeString AS WSTRINGZ _                  ' __in LPCWSTR unicodeString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphIndexCount ( _                        ' VTable offset = 24
     BYREF indexCount AS DWORD _                        ' __out UINT32 *indexCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphIndices ( _                           ' VTable offset = 28
     BYREF indexCount AS DWORD _                        ' __inout UINT32 *indexCount
   , BYREF glyphIndices AS XPS_GLYPH_INDEX _            ' __out XPS_GLYPH_INDEX *glyphIndices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGlyphIndices ( _                           ' VTable offset = 32
     BYVAL indexCount AS DWORD _                        ' __in UINT32 indexCount
   , BYREF glyphIndices AS XPS_GLYPH_INDEX _            ' __in XPS_GLYPH_INDEX *glyphIndices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphMappingCount ( _                      ' VTable offset = 36
     BYREF glyphMappingCount AS DWORD _                 ' __out UINT32 *glyphMappingCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphMappings ( _                          ' VTable offset = 40
     BYREF glyphMappingCount AS DWORD _                 ' __inout UINT32 *glyphMappingCount
   , BYREF glyphMappings AS XPS_GLYPH_MAPPING _         ' __out XPS_GLYPH_MAPPING *glyphMappings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGlyphMappings ( _                          ' VTable offset = 44
     BYVAL glyphMappingCount AS DWORD _                 ' __in UINT32 glyphMappingCount
   , BYREF glyphMappings AS XPS_GLYPH_MAPPING _         ' __in XPS_GLYPH_MAPPING *glyphMappings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProhibitedCaretStopCount ( _               ' VTable offset = 48
     BYREF prohibitedCaretStopCount AS DWORD _          ' __out UINT32 *prohibitedCaretStopCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProhibitedCaretStops ( _                   ' VTable offset = 52
     BYREF count AS DWORD _                             ' __inout UINT32 *count
   , BYREF prohibitedCaretStops AS DWORD _              ' __out UINT32 *prohibitedCaretStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProhibitedCaretStops ( _                   ' VTable offset = 56
     BYVAL count AS DWORD _                             ' __in UINT32 count
   , BYREF prohibitedCaretStops AS DWORD _              ' __in UINT32 *prohibitedCaretStops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBidiLevel ( _                              ' VTable offset = 60
     BYREF bidiLevel AS DWORD _                         ' __out UINT32 *bidiLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBidiLevel ( _                              ' VTable offset = 64
     BYVAL bidiLevel AS DWORD _                         ' __in UINT32 bidiLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsSideways ( _                             ' VTable offset = 68
     BYREF isSideways AS LONG _                         ' __out BOOL *isSideways
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsSideways ( _                             ' VTable offset = 72
     BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceFontName ( _                         ' VTable offset = 76
     BYREF deviceFontName AS DWORD _                    ' __out LPWSTR *deviceFontName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeviceFontName ( _                         ' VTable offset = 80
     BYREF deviceFontName AS WSTRINGZ _                 ' __in LPCWSTR deviceFontName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMGlyphsEditor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPrintTicketResource
' IID = {E7FF32D2-34AA-499B-BBE9-9CD4EE6C59F7}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMPrintTicketResource_INTERFACE_DEFINED)
    %IXpsOMPrintTicketResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPrintTicketResource $IID_IXpsOMPrintTicketResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMPrintTicketResource Methods
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 20
     BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 24
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPrintTicketResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDocumentStructureResource
' IID = {85FEBC8A-6B63-48A9-AF07-7064E4ECFF30}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMDocumentStructureResource_INTERFACE_DEFINED)
    %IXpsOMDocumentStructureResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDocumentStructureResource $IID_IXpsOMDocumentStructureResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMResource Methods
   ' =====================================================================================

   ' This interface has not additional methods

   ' =====================================================================================
   ' IXpsOMDocumentStructureResource Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF owner AS IXpsOMDocument _                    ' __out IXpsOMDocument **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 24
     BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 28
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDocumentStructureResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMStoryFragmentsResource
' IID = {C2B3CA09-0473-4282-87AE-1780863223F0}
' Inherited interface = IXpsOMResource
' ########################################################################################

#IF NOT %DEF(%IXpsOMStoryFragmentsResource_INTERFACE_DEFINED)
    %IXpsOMStoryFragmentsResource_INTERFACE_DEFINED = 1

INTERFACE IXpsOMStoryFragmentsResource $IID_IXpsOMStoryFragmentsResource

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMStoryFragmentsResource Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF owner AS IXpsOMPageReference _               ' __out IXpsOMPageReference **owner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 24
     BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContent ( _                                ' VTable offset = 28
     BYVAL sourceStream AS IStream _                    ' __in IStream *sourceStream
   , BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMStoryFragmentsResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMPageReferenceCollection
' IID = {CA16BA4D-E7B9-45C5-958B-F98022473745}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMPageReferenceCollection_INTERFACE_DEFINED)
    %IXpsOMPageReferenceCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMPageReferenceCollection $IID_IXpsOMPageReferenceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF pageReference AS IXpsOMPageReference _       ' __out IXpsOMPageReference **pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL pageReference AS IXpsOMPageReference _       ' __in IXpsOMPageReference *pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL pageReference AS IXpsOMPageReference _       ' __in IXpsOMPageReference *pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL pageReference AS IXpsOMPageReference _       ' __in IXpsOMPageReference *pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMPageReferenceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMDocumentCollection
' IID = {D1C87F0D-E947-4754-8A25-971478F7E83E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMDocumentCollection_INTERFACE_DEFINED)
    %IXpsOMDocumentCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsOMDocumentCollection $IID_IXpsOMDocumentCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF document AS IXpsOMDocument _                 ' __out IXpsOMDocument **document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL document AS IXpsOMDocument _                 ' __in IXpsOMDocument *document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAt ( _                                     ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL document AS IXpsOMDocument _                 ' __in IXpsOMDocument *document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 32
     BYVAL document AS IXpsOMDocument _                 ' __in IXpsOMDocument *document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMDocumentCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMCoreProperties
' IID = {3340FE8F-4027-4AA1-8F5F-D35AE45FE597}
' Inherited interface = IXpsOMPart
' ########################################################################################

#IF NOT %DEF(%IXpsOMCoreProperties_INTERFACE_DEFINED)
    %IXpsOMCoreProperties_INTERFACE_DEFINED = 1

INTERFACE IXpsOMCoreProperties $IID_IXpsOMCoreProperties

   INHERIT IUnknown

   ' =====================================================================================
   ' IXpsOMPart Methods
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 12
     BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartName ( _                               ' VTable offset = 16
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXpsOMCoreProperties Methods
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 20
     BYREF package AS IXpsOMPackage _                   ' __out IXpsOMPackage **package
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 24
     BYREF category AS DWORD _                          ' __out LPWSTR *category
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCategory ( _                               ' VTable offset = 28
     BYREF category AS WSTRINGZ _                       ' __in LPCWSTR category
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentStatus ( _                          ' VTable offset = 32
     BYREF contentStatus AS DWORD _                     ' __out LPWSTR *contentStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentStatus ( _                          ' VTable offset = 36
     BYREF contentStatus AS WSTRINGZ _                  ' __in LPCWSTR contentStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentType ( _                            ' VTable offset = 40
     BYREF contentType AS DWORD _                       ' __out LPWSTR *contentType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentType ( _                            ' VTable offset = 44
     BYREF contentType AS WSTRINGZ _                    ' __in LPCWSTR contentType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreated ( _                                ' VTable offset = 48
     BYREF created AS SYSTEMTIME _                      ' __out SYSTEMTIME *created
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCreated ( _                                ' VTable offset = 52
     BYREF created AS SYSTEMTIME _                      ' __in SYSTEMTIME *created
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreator ( _                                ' VTable offset = 56
     BYREF creator AS DWORD _                           ' __out LPWSTR *creator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCreator ( _                                ' VTable offset = 60
     BYREF creator AS WSTRINGZ _                        ' __in LPCWSTR creator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 64
     BYREF description AS DWORD _                       ' __out LPWSTR *description
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 68
     BYREF description AS WSTRINGZ _                    ' __in LPCWSTR description
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIdentifier ( _                             ' VTable offset = 72
     BYREF identifier AS DWORD _                        ' __out LPWSTR *identifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIdentifier ( _                             ' VTable offset = 76
     BYREF identifier AS WSTRINGZ _                     ' __in LPCWSTR identifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeywords ( _                               ' VTable offset = 80
     BYREF keywords AS DWORD _                          ' __out LPWSTR *keywords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetKeywords ( _                               ' VTable offset = 84
     BYREF keywords AS WSTRINGZ _                       ' __in LPCWSTR keywords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 88
     BYREF language AS DWORD _                          ' __out LPWSTR *language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 92
     BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastModifiedBy ( _                         ' VTable offset = 96
     BYREF lastModifiedBy AS DWORD _                    ' __out LPWSTR *lastModifiedBy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLastModifiedBy ( _                         ' VTable offset = 100
     BYREF lastModifiedBy AS WSTRINGZ _                 ' __in LPCWSTR lastModifiedBy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPrinted ( _                            ' VTable offset = 104
     BYREF lastPrinted AS SYSTEMTIME _                  ' __out SYSTEMTIME *lastPrinted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLastPrinted ( _                            ' VTable offset = 108
     BYREF lastPrinted AS SYSTEMTIME _                  ' __in SYSTEMTIME *lastPrinted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModified ( _                               ' VTable offset = 112
     BYREF modified AS SYSTEMTIME _                     ' __out SYSTEMTIME *modified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetModified ( _                               ' VTable offset = 116
     BYREF modified AS SYSTEMTIME _                     ' __in SYSTEMTIME *modified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRevision ( _                               ' VTable offset = 120
     BYREF revision AS DWORD _                          ' __out LPWSTR *revision
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRevision ( _                               ' VTable offset = 124
     BYREF revision AS WSTRINGZ _                       ' __in LPCWSTR revision
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubject ( _                                ' VTable offset = 128
     BYREF subject AS DWORD _                           ' __out LPWSTR *subject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubject ( _                                ' VTable offset = 132
     BYREF subject AS WSTRINGZ _                        ' __in LPCWSTR subject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 136
     BYREF title AS DWORD _                             ' __out LPWSTR *title
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 140
     BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 144
     BYREF version AS DWORD _                           ' __out LPWSTR *version
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVersion ( _                                ' VTable offset = 148
     BYREF version AS WSTRINGZ _                        ' __in LPCWSTR version
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 152
     BYREF coreProperties AS IXpsOMCoreProperties _     ' __out IXpsOMCoreProperties **coreProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMCoreProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMObjectFactory
' IID = {F9B2A685-A50D-4FC2-B764-B56E093EA0CA}
' Methods to create Xps Objects
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMObjectFactory_INTERFACE_DEFINED)
    %IXpsOMObjectFactory_INTERFACE_DEFINED = 1

INTERFACE IXpsOMObjectFactory $IID_IXpsOMObjectFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePackage ( _                             ' VTable offset = 12
     BYREF package AS IXpsOMPackage _                   ' __out IXpsOMPackage **package
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePackageFromFile ( _                     ' VTable offset = 16
     BYREF fileName AS WSTRINGZ _                       ' __in LPCWSTR fileName
   , BYVAL reuseObjects AS LONG _                       ' __in BOOL reuseObjects
   , BYREF package AS IXpsOMPackage _                   ' __out IXpsOMPackage **package
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePackageFromStream ( _                   ' VTable offset = 20
     BYVAL stream AS IStream _                          ' __in IStream *stream
   , BYVAL reuseObjects AS LONG _                       ' __in BOOL reuseObjects
   , BYREF package AS IXpsOMPackage _                   ' __out IXpsOMPackage **package
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStoryFragmentsResource ( _              ' VTable offset = 24
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF storyFragmentsResource AS IXpsOMStoryFragmentsResource _ ' __out IXpsOMStoryFragmentsResource **storyFragmentsResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDocumentStructureResource ( _           ' VTable offset = 28
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF documentStructureResource AS IXpsOMDocumentStructureResource _ ' __out IXpsOMDocumentStructureResource **documentStructureResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSignatureBlockResource ( _              ' VTable offset = 32
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF signatureBlockResource AS IXpsOMSignatureBlockResource _ ' __out IXpsOMSignatureBlockResource **signatureBlockResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRemoteDictionaryResource ( _            ' VTable offset = 36
     BYVAL dictionary AS IXpsOMDictionary _             ' __in IXpsOMDictionary *dictionary
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF remoteDictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __out IXpsOMRemoteDictionaryResource **remoteDictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRemoteDictionaryResourceFromStream ( _  ' VTable offset = 40
     BYVAL dictionaryMarkupStream AS IStream _          ' __in IStream *dictionaryMarkupStream
   , BYVAL dictionaryPartUri AS IOpcPartUri _           ' __in IOpcPartUri *dictionaryPartUri
   , BYVAL resources AS IXpsOMPartResources _           ' __in IXpsOMPartResources *resources
   , BYREF dictionaryResource AS IXpsOMRemoteDictionaryResource _ ' __out IXpsOMRemoteDictionaryResource **dictionaryResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePartResources ( _                       ' VTable offset = 44
     BYREF partResources AS IXpsOMPartResources _       ' __out IXpsOMPartResources **partResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDocumentSequence ( _                    ' VTable offset = 48
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF documentSequence AS IXpsOMDocumentSequence _ ' __out IXpsOMDocumentSequence **documentSequence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDocument ( _                            ' VTable offset = 52
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF document AS IXpsOMDocument _                 ' __out IXpsOMDocument **document
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePageReference ( _                       ' VTable offset = 56
     BYREF advisoryPageDimensions AS XPS_SIZE _         ' __in XPS_SIZE *advisoryPageDimensions
   , BYREF pageReference AS IXpsOMPageReference _       ' __out IXpsOMPageReference **pageReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePage ( _                                ' VTable offset = 60
     BYREF pageDimensions AS XPS_SIZE _                 ' __in XPS_SIZE *pageDimensions
   , BYREF language AS WSTRINGZ _                       ' __in LPCWSTR language
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF page AS IXpsOMPage _                         ' __out IXpsOMPage **page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePageFromStream ( _                      ' VTable offset = 64
     BYVAL pageMarkupStream AS IStream _                ' __in IStream *pageMarkupStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYVAL resources AS IXpsOMPartResources _           ' __in IXpsOMPartResources *resources
   , BYVAL reuseObjects AS LONG _                       ' __in BOOL reuseObjects
   , BYREF page AS IXpsOMPage _                         ' __out IXpsOMPage **page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCanvas ( _                              ' VTable offset = 68
     BYREF canvas AS IXpsOMCanvas _                     ' __out IXpsOMCanvas **canvas
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGlyphs ( _                              ' VTable offset = 72
     BYVAL fontResource AS IXpsOMFontResource _         ' __in IXpsOMFontResource *fontResource
   , BYREF glyphs AS IXpsOMGlyphs _                     ' __out IXpsOMGlyphs **glyphs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePath ( _                                ' VTable offset = 76
     BYREF path AS IXpsOMPath _                         ' __out IXpsOMPath **path
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGeometry ( _                            ' VTable offset = 80
     BYREF geometry AS IXpsOMGeometry _                 ' __out IXpsOMGeometry **geometry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGeometryFigure ( _                      ' VTable offset = 84
     BYREF startPoint AS XPS_POINT _                    ' __in XPS_POINT *startPoint
   , BYREF figure AS IXpsOMGeometryFigure _             ' __out IXpsOMGeometryFigure **figure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMatrixTransform ( _                     ' VTable offset = 88
     BYREF matrix AS XPS_MATRIX _                       ' __in XPS_MATRIX *matrix
   , BYREF transform AS IXpsOMMatrixTransform _         ' __out IXpsOMMatrixTransform **transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSolidColorBrush ( _                     ' VTable offset = 92
     BYREF color AS XPS_COLOR _                         ' __in XPS_COLOR *color
   , BYVAL colorProfile AS IXpsOMColorProfileResource _ ' __in IXpsOMColorProfileResource *colorProfile
   , BYREF solidColorBrush AS IXpsOMSolidColorBrush _   ' __out IXpsOMSolidColorBrush **solidColorBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateColorProfileResource ( _                ' VTable offset = 96
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF colorProfileResource AS IXpsOMColorProfileResource _ ' __out IXpsOMColorProfileResource **colorProfileResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateImageBrush ( _                          ' VTable offset = 100
     BYVAL image AS IXpsOMImageResource _               ' __in IXpsOMImageResource *image
   , BYREF viewbox AS XPS_RECT _                        ' __in XPS_RECT *viewbox
   , BYREF viewport AS XPS_RECT _                       ' __in XPS_RECT *viewport
   , BYREF imageBrush AS IXpsOMImageBrush _             ' __out IXpsOMImageBrush **imageBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVisualBrush ( _                         ' VTable offset = 104
     BYREF viewbox AS XPS_RECT _                        ' __in XPS_RECT *viewbox
   , BYREF viewport AS XPS_RECT _                       ' __in XPS_RECT *viewport
   , BYREF visualBrush AS IXpsOMVisualBrush _           ' __out IXpsOMVisualBrush **visualBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateImageResource ( _                       ' VTable offset = 108
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL contentType AS LONG _                        ' __in XPS_IMAGE_TYPE contentType
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF imageResource AS IXpsOMImageResource _       ' __out IXpsOMImageResource **imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePrintTicketResource ( _                 ' VTable offset = 112
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF printTicketResource AS IXpsOMPrintTicketResource _ ' __out IXpsOMPrintTicketResource **printTicketResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFontResource ( _                        ' VTable offset = 116
     BYVAL acquiredStream AS IStream _                  ' __in IStream *acquiredStream
   , BYVAL fontEmbedding AS LONG _                      ' __in XPS_FONT_EMBEDDING fontEmbedding
   , BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYVAL isObfSourceStream AS LONG _                  ' __in BOOL isObfSourceStream
   , BYREF fontResource AS IXpsOMFontResource _         ' __out IXpsOMFontResource **fontResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGradientStop ( _                        ' VTable offset = 120
     BYREF color AS XPS_COLOR _                         ' __in XPS_COLOR *color
   , BYVAL colorProfile AS IXpsOMColorProfileResource _ ' __in IXpsOMColorProfileResource *colorProfile
   , BYVAL offset AS SINGLE _                           ' __in FLOAT offset
   , BYREF gradientStop AS IXpsOMGradientStop _         ' __out IXpsOMGradientStop **gradientStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLinearGradientBrush ( _                 ' VTable offset = 124
     BYVAL gradStop1 AS IXpsOMGradientStop _            ' __in IXpsOMGradientStop *gradStop1
   , BYVAL gradStop2 AS IXpsOMGradientStop _            ' __in IXpsOMGradientStop *gradStop2
   , BYREF startPoint AS XPS_POINT _                    ' __in XPS_POINT *startPoint
   , BYREF endPoint AS XPS_POINT _                      ' __in XPS_POINT *endPoint
   , BYREF linearGradientBrush AS IXpsOMLinearGradientBrush _ ' __out IXpsOMLinearGradientBrush **linearGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRadialGradientBrush ( _                 ' VTable offset = 128
     BYVAL gradStop1 AS IXpsOMGradientStop _            ' __in IXpsOMGradientStop *gradStop1
   , BYVAL gradStop2 AS IXpsOMGradientStop _            ' __in IXpsOMGradientStop *gradStop2
   , BYREF centerPoint AS XPS_POINT _                   ' __in XPS_POINT *centerPoint
   , BYREF gradientOrigin AS XPS_POINT _                ' __in XPS_POINT *gradientOrigin
   , BYREF radiiSizes AS XPS_SIZE _                     ' __in XPS_SIZE *radiiSizes
   , BYREF radialGradientBrush AS IXpsOMRadialGradientBrush _ ' __out IXpsOMRadialGradientBrush **radialGradientBrush
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCoreProperties ( _                      ' VTable offset = 132
     BYVAL partUri AS IOpcPartUri _                     ' __in IOpcPartUri *partUri
   , BYREF coreProperties AS IXpsOMCoreProperties _     ' __out IXpsOMCoreProperties **coreProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDictionary ( _                          ' VTable offset = 136
     BYREF dictionary AS IXpsOMDictionary _             ' __out IXpsOMDictionary **dictionary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePartUriCollection ( _                   ' VTable offset = 140
     BYREF partUriCollection AS IXpsOMPartUriCollection _ ' __out IXpsOMPartUriCollection **partUriCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePackageWriterOnFile ( _                 ' VTable offset = 144
     BYREF fileName AS WSTRINGZ _                       ' __in LPCWSTR fileName
   , BYREF securityAttributes AS SECURITY_ATTRIBUTES _  ' __in SECURITY_ATTRIBUTES *securityAttributes
   , BYVAL flagsAndAttributes AS DWORD _                ' __in DWORD flagsAndAttributes
   , BYVAL optimizeMarkupSize AS LONG _                 ' __in BOOL optimizeMarkupSize
   , BYVAL interleaving AS LONG _                       ' __in XPS_INTERLEAVING interleaving
   , BYVAL documentSequencePartName AS IOpcPartUri _    ' __in IOpcPartUri *documentSequencePartName
   , BYVAL coreProperties AS IXpsOMCoreProperties _     ' __in IXpsOMCoreProperties *coreProperties
   , BYVAL packageThumbnail AS IXpsOMImageResource _    ' __in IXpsOMImageResource *packageThumbnail
   , BYVAL documentSequencePrintTicket AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *documentSequencePrintTicket
   , BYVAL discardControlPartName AS IOpcPartUri _      ' __in *IOpcPartUri discardControlPartName
   , BYREF packageWriter AS IXpsOMPackageWriter _       ' __out IXpsOMPackageWriter **packageWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePackageWriterOnStream ( _               ' VTable offset = 148
     BYVAL outputStream AS ISequentialStream _          ' __in ISequentialStream *outputStream
   , BYVAL optimizeMarkupSize AS LONG _                 ' __in BOOL optimizeMarkupSize
   , BYVAL interleaving AS LONG _                       ' __in XPS_INTERLEAVING interleaving
   , BYVAL documentSequencePartName AS IOpcPartUri _    ' __in IOpcPartUri *documentSequencePartName
   , BYVAL coreProperties AS IXpsOMCoreProperties _     ' __in IXpsOMCoreProperties *coreProperties
   , BYVAL packageThumbnail AS IXpsOMImageResource _    ' __in IXpsOMImageResource *packageThumbnail
   , BYVAL documentSequencePrintTicket AS IXpsOMPrintTicketResource _ ' __in IXpsOMPrintTicketResource *documentSequencePrintTicket
   , BYVAL discardControlPartName AS IOpcPartUri _      ' __in IOpcPartUri *discardControlPartName
   , BYREF packageWriter AS IXpsOMPackageWriter _       ' __out IXpsOMPackageWriter **packageWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePartUri ( _                             ' VTable offset = 152
     BYREF uri AS WSTRINGZ _                            ' __in LPCWSTR uri
   , BYREF partUri AS IOpcPartUri _                     ' __out IOpcPartUri **partUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateReadOnlyStreamOnFile ( _                ' VTable offset = 156
     BYREF fileName AS WSTRINGZ _                       ' __in LPCWSTR fileName
   , BYREF stream AS IStream _                          ' __out IStream **stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMObjectFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsOMThumbnailGenerator
' IID = {15B873D5-1971-41E8-83A3-6578403064C7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsOMThumbnailGenerator_INTERFACE_DEFINED)
    %IXpsOMThumbnailGenerator_INTERFACE_DEFINED = 1

INTERFACE IXpsOMThumbnailGenerator $IID_IXpsOMThumbnailGenerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GenerateThumbnail ( _                         ' VTable offset = 12
     BYVAL page AS IXpsOMPage _                         ' __in IXpsOMPage *page
   , BYVAL thumbnailType AS LONG _                      ' __in XPS_IMAGE_TYPE thumbnailType
   , BYVAL thumbnailSize AS LONG _                      ' __in XPS_THUMBNAIL_SIZE thumbnailSize
   , BYVAL imageResourcePartName AS IOpcPartUri _       ' __in IOpcPartUri *imageResourcePartName
   , BYREF imageResource AS IXpsOMImageResource _       ' __out IXpsOMImageResource **imageResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsOMThumbnailGenerator_INTERFACE_DEFINED__ */


%XPS_E_INVALID_LANGUAGE                           = &H80520000&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x000)
%XPS_E_INVALID_NAME                               = &H80520001&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x001)
%XPS_E_INVALID_RESOURCE_KEY                       = &H80520002&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x002)
%XPS_E_INVALID_PAGE_SIZE                          = &H80520003&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x003)
%XPS_E_INVALID_BLEED_BOX                          = &H80520004&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x004)
%XPS_E_INVALID_THUMBNAIL_IMAGE_TYPE               = &H80520005&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x005)
%XPS_E_INVALID_LOOKUP_TYPE                        = &H80520006&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x006)
%XPS_E_INVALID_FLOAT                              = &H80520007&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x007)
%XPS_E_UNEXPECTED_CONTENT_TYPE                    = &H80520008&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x008)
%XPS_E_INVALID_FONT_URI                           = &H8052000a&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00a)
%XPS_E_INVALID_CONTENT_BOX                        = &H8052000b&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00b)
%XPS_E_INVALID_MARKUP                             = &H8052000c&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00c)
%XPS_E_INVALID_XML_ENCODING                       = &H8052000d&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00d)
%XPS_E_INVALID_CONTENT_TYPE                       = &H8052000e&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00e)
%XPS_E_INVALID_OBFUSCATED_FONT_URI                = &H8052000f&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x00f)
%XPS_E_UNEXPECTED_RELATIONSHIP_TYPE               = &H80520010&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x010)
%XPS_E_UNEXPECTED_RESTRICTED_FONT_RELATIONSHIP    = &H80520011&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x011)
%XPS_E_MISSING_NAME                               = &H80520100&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x100)
%XPS_E_MISSING_LOOKUP                             = &H80520101&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x101)
%XPS_E_MISSING_GLYPHS                             = &H80520102&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x102)
%XPS_E_MISSING_SEGMENT_DATA                       = &H80520103&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x103)
%XPS_E_MISSING_COLORPROFILE                       = &H80520104&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x104)
%XPS_E_MISSING_RELATIONSHIP_TARGET                = &H80520105&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x105)
%XPS_E_MISSING_RESOURCE_RELATIONSHIP              = &H80520106&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x106)
%XPS_E_MISSING_FONTURI                            = &H80520107&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x107)
%XPS_E_MISSING_DOCUMENTSEQUENCE_RELATIONSHIP      = &H80520108&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x108)
%XPS_E_MISSING_DOCUMENT                           = &H80520109&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x109)
%XPS_E_MISSING_REFERRED_DOCUMENT                  = &H8052010a&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10a)
%XPS_E_MISSING_REFERRED_PAGE                      = &H8052010b&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10b)
%XPS_E_MISSING_PAGE_IN_DOCUMENT                   = &H8052010c&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10c)
%XPS_E_MISSING_PAGE_IN_PAGEREFERENCE              = &H8052010d&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10d)
%XPS_E_MISSING_IMAGE_IN_IMAGEBRUSH                = &H8052010e&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10e)
%XPS_E_MISSING_RESOURCE_KEY                       = &H8052010f&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x10f)
%XPS_E_MISSING_PART_REFERENCE                     = &H80520110&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x110)
%XPS_E_MISSING_RESTRICTED_FONT_RELATIONSHIP       = &H80520111&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x111)
%XPS_E_MISSING_DISCARDCONTROL                     = &H80520112&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x112)
%XPS_E_MISSING_PART_STREAM                        = &H80520113&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x113)
%XPS_E_UNAVAILABLE_PACKAGE                        = &H80520114&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x114)
%XPS_E_DUPLICATE_RESOURCE_KEYS                    = &H80520200&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x200)
%XPS_E_MULTIPLE_RESOURCES                         = &H80520201&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x201)
%XPS_E_MULTIPLE_DOCUMENTSEQUENCE_RELATIONSHIPS    = &H80520202&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x202)
%XPS_E_MULTIPLE_THUMBNAILS_ON_PAGE                = &H80520203&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x203)
%XPS_E_MULTIPLE_THUMBNAILS_ON_PACKAGE             = &H80520204&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x204)
%XPS_E_MULTIPLE_PRINTTICKETS_ON_PAGE              = &H80520205&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x205)
%XPS_E_MULTIPLE_PRINTTICKETS_ON_DOCUMENT          = &H80520206&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x206)
%XPS_E_MULTIPLE_PRINTTICKETS_ON_DOCUMENTSEQUENCE  = &H80520207&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x207)
%XPS_E_MULTIPLE_REFERENCES_TO_PART                = &H80520208&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x208)
%XPS_E_DUPLICATE_NAMES                            = &H80520209&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x209)
%XPS_E_STRING_TOO_LONG                            = &H80520300&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x300)
%XPS_E_TOO_MANY_INDICES                           = &H80520301&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x301)
%XPS_E_MAPPING_OUT_OF_ORDER                       = &H80520302&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x302)
%XPS_E_MAPPING_OUTSIDE_STRING                     = &H80520303&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x303)
%XPS_E_MAPPING_OUTSIDE_INDICES                    = &H80520304&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x304)
%XPS_E_CARET_OUTSIDE_STRING                       = &H80520305&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x305)
%XPS_E_CARET_OUT_OF_ORDER                         = &H80520306&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x306)
%XPS_E_ODD_BIDILEVEL                              = &H80520307&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x307)
%XPS_E_ONE_TO_ONE_MAPPING_EXPECTED                = &H80520308&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x308)
%XPS_E_RESTRICTED_FONT_NOT_OBFUSCATED             = &H80520309&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x309)
%XPS_E_NEGATIVE_FLOAT                             = &H8052030a&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x30a)
%XPS_E_XKEY_ATTR_PRESENT_OUTSIDE_RES_DICT         = &H80520400&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x400)
%XPS_E_DICTIONARY_ITEM_NAMED                      = &H80520401&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x401)
%XPS_E_NESTED_REMOTE_DICTIONARY                   = &H80520402&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x402)
%XPS_E_INDEX_OUT_OF_RANGE                         = &H80520500&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x500)
%XPS_E_VISUAL_CIRCULAR_REF                        = &H80520501&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x501)
%XPS_E_NO_CUSTOM_OBJECTS                          = &H80520502&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x502)
%XPS_E_ALREADY_OWNED                              = &H80520503&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x503)
%XPS_E_RESOURCE_NOT_OWNED                         = &H80520504&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x504)
%XPS_E_UNEXPECTED_COLORPROFILE                    = &H80520505&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x505)
%XPS_E_COLOR_COMPONENT_OUT_OF_RANGE               = &H80520506&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x506)
%XPS_E_BOTH_PATHFIGURE_AND_ABBR_SYNTAX_PRESENT    = &H80520507&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x507)
%XPS_E_BOTH_RESOURCE_AND_SOURCEATTR_PRESENT       = &H80520508&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x508)
%XPS_E_BLEED_BOX_PAGE_DIMENSIONS_NOT_IN_SYNC      = &H80520509&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x509)
%XPS_E_RELATIONSHIP_EXTERNAL                      = &H8052050a&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x50a)
%XPS_E_NOT_ENOUGH_GRADIENT_STOPS                  = &H8052050b&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x50b)
%XPS_E_PACKAGE_WRITER_NOT_CLOSED                  = &H8052050c&   ' MAKE_HRESULT(1, FACILITY_XPS, 0x50c)

'#endif // (NTDDI >= NTDDI_WIN7)
