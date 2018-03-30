' ########################################################################################
' Microsoft Windows
' File: UIRibbon.inc
' Contents: Interfaces for the Windows Ribbon Framework
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: UIRibbon
' Version: 1.0, Locale ID = 0
' Library GUID: {942F35C2-E83B-45EF-B085-AC295DD63D5B}
' ########################################################################################

#INCLUDE THIS ONCE
%UIRIBBON_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "UIRibbonKeydef.inc"

$LIBID_UIRibbon = GUID$("{942F35C2-E83B-45EF-B085-AC295DD63D5B}")
$CLSID_UIRibbonFramework = GUID$("{926749FA-2615-4987-8845-C33E65F2B957}")
$CLSID_UIRibbonImageFromBitmapFactory = GUID$("{0F7434B6-59B6-4250-999E-D168D6AE4293}")

'#define DEFINE_UIPROPERTYKEY(name, type, index) EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY name = { { 0x00000000 + index, 0x7363, 0x696e, { 0x84, 0x41, 0x79, 0x8a, 0xcf, 0x5a, 0xeb, 0xb7 } }, type }

'DEFINE_UIPROPERTYKEY(UI_PKEY_Enabled,                      VT_BOOL,                1);
'DEFINE_UIPROPERTYKEY(UI_PKEY_LabelDescription,             VT_LPWSTR,              2);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Keytip,                       VT_LPWSTR,              3);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Label,                        VT_LPWSTR,              4);
'DEFINE_UIPROPERTYKEY(UI_PKEY_TooltipDescription,           VT_LPWSTR,              5);
'DEFINE_UIPROPERTYKEY(UI_PKEY_TooltipTitle,                 VT_LPWSTR,              6);
'DEFINE_UIPROPERTYKEY(UI_PKEY_LargeImage,                   VT_UNKNOWN,             7);
'DEFINE_UIPROPERTYKEY(UI_PKEY_LargeHighContrastImage,       VT_UNKNOWN,             8);
'DEFINE_UIPROPERTYKEY(UI_PKEY_SmallImage,                   VT_UNKNOWN,             9);
'DEFINE_UIPROPERTYKEY(UI_PKEY_SmallHighContrastImage,       VT_UNKNOWN,             10);
'DEFINE_UIPROPERTYKEY(UI_PKEY_CommandId,                    VT_UI4,                 100);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ItemsSource,                  VT_UNKNOWN,             101);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Categories,                   VT_UNKNOWN,             102);
'DEFINE_UIPROPERTYKEY(UI_PKEY_CategoryId,                   VT_UI4,                 103);
'DEFINE_UIPROPERTYKEY(UI_PKEY_SelectedItem,                 VT_UI4,                 104);
'DEFINE_UIPROPERTYKEY(UI_PKEY_CommandType,                  VT_UI4,                 105);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ItemImage,                    VT_UNKNOWN,             106);
'DEFINE_UIPROPERTYKEY(UI_PKEY_BooleanValue,                 VT_BOOL,                200);
'DEFINE_UIPROPERTYKEY(UI_PKEY_DecimalValue,                 VT_DECIMAL,             201);
'DEFINE_UIPROPERTYKEY(UI_PKEY_StringValue,                  VT_LPWSTR,              202);
'DEFINE_UIPROPERTYKEY(UI_PKEY_MaxValue,                     VT_DECIMAL,             203);
'DEFINE_UIPROPERTYKEY(UI_PKEY_MinValue,                     VT_DECIMAL,             204);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Increment,                    VT_DECIMAL,             205);
'DEFINE_UIPROPERTYKEY(UI_PKEY_DecimalPlaces,                VT_UI4,                 206);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FormatString,                 VT_LPWSTR,              207);
'DEFINE_UIPROPERTYKEY(UI_PKEY_RepresentativeString,         VT_LPWSTR,              208);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties,                     VT_UNKNOWN,             300);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Family,              VT_LPWSTR,              301);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Size,                VT_DECIMAL,             302);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Bold,                VT_UI4,                 303);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Italic,              VT_UI4,                 304);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Underline,           VT_UI4,                 305);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_Strikethrough,       VT_UI4,                 306);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_VerticalPositioning, VT_UI4,                 307);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_ForegroundColor,     VT_UI4,                 308);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_BackgroundColor,     VT_UI4,                 309);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_ForegroundColorType, VT_UI4,                 310);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_BackgroundColorType, VT_UI4,                 311);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_ChangedProperties,   VT_UNKNOWN,             312);
'DEFINE_UIPROPERTYKEY(UI_PKEY_FontProperties_DeltaSize,           VT_UI4,                 313);
'DEFINE_UIPROPERTYKEY(UI_PKEY_RecentItems,                  VT_ARRAY|VT_UNKNOWN,    350);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Pinned,                       VT_BOOL,                351);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Color,                        VT_UI4,                 400);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ColorType,                    VT_UI4,                 401);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ColorMode,                    VT_UI4,                 402);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ThemeColorsCategoryLabel,     VT_LPWSTR,              403);
'DEFINE_UIPROPERTYKEY(UI_PKEY_StandardColorsCategoryLabel,  VT_LPWSTR,              404);
'DEFINE_UIPROPERTYKEY(UI_PKEY_RecentColorsCategoryLabel,    VT_LPWSTR,              405);
'DEFINE_UIPROPERTYKEY(UI_PKEY_AutomaticColorLabel,          VT_LPWSTR,              406);
'DEFINE_UIPROPERTYKEY(UI_PKEY_NoColorLabel,                 VT_LPWSTR,              407);
'DEFINE_UIPROPERTYKEY(UI_PKEY_MoreColorsLabel,              VT_LPWSTR,              408);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ThemeColors,                  VT_VECTOR|VT_UI4,       409);
'DEFINE_UIPROPERTYKEY(UI_PKEY_StandardColors,               VT_VECTOR|VT_UI4,       410);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ThemeColorsTooltips,          VT_VECTOR|VT_LPWSTR,    411);
'DEFINE_UIPROPERTYKEY(UI_PKEY_StandardColorsTooltips,       VT_VECTOR|VT_LPWSTR,    412);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Viewable,                     VT_BOOL,                1000);
'DEFINE_UIPROPERTYKEY(UI_PKEY_Minimized,                    VT_BOOL,                1001);
'DEFINE_UIPROPERTYKEY(UI_PKEY_QuickAccessToolbarDock,       VT_UI4,                 1002);
'DEFINE_UIPROPERTYKEY(UI_PKEY_ContextAvailable,             VT_UI4,                 1100);
'DEFINE_UIPROPERTYKEY(UI_PKEY_GlobalBackgroundColor,        VT_UI4,                 2000);
'DEFINE_UIPROPERTYKEY(UI_PKEY_GlobalHighlightColor,         VT_UI4,                 2001);
'DEFINE_UIPROPERTYKEY(UI_PKEY_GlobalTextColor,              VT_UI4,                 2002);

' Note: Defined as macros for easy assignment to PROPERTY SET structures.
' Usage: DIM t AS PROPERTY KEY : TYPE SET t = UI_PKEY_Enabled
MACRO UI_PKEY_Enabled = GUID$("{00000001-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_BOOL)
MACRO UI_PKEY_LabelDescription = GUID$("{00000002-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_Keytip = GUID$("{00000003-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_Label = GUID$("{00000004-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_TooltipDescription = GUID$("{00000005-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_TooltipTitle = GUID$("{00000006-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_LargeImage = GUID$("{00000007-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_LargeHighContrastImage = GUID$("{00000008-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_SmallImage = GUID$("{00000009-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_SmallHighContrastImage = GUID$("{00000010-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_CommandId = GUID$("{00000100-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ItemsSource = GUID$("{00000101-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_Categories = GUID$("{00000102-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_CategoryId = GUID$("{00000103-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_SelectedItem = GUID$("{00000104-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_CommandType = GUID$("{00000105-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ItemImage = GUID$("{00000106-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_BooleanValue = GUID$("{00000200-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_BOOL)
MACRO UI_PKEY_DecimalValue = GUID$("{00000201-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_DECIMAL)
MACRO UI_PKEY_StringValue = GUID$("{00000202-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_MaxValue = GUID$("{00000203-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_DECIMAL)
MACRO UI_PKEY_MinValue = GUID$("{00000204-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_DECIMAL)
MACRO UI_PKEY_Increment = GUID$("{00000205-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_DECIMAL)
MACRO UI_PKEY_DecimalPlaces = GUID$("{00000206-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FormatString = GUID$("{00000207-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_RepresentativeString = GUID$("{00000208-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_FontProperties = GUID$("{00000300-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_FontProperties_Family = GUID$("{00000301-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_FontProperties_Size = GUID$("{00000302-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_DECIMAL)
MACRO UI_PKEY_FontProperties_Bold = GUID$("{00000303-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_Italic = GUID$("{00000304-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_Underline = GUID$("{00000305-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_Strikethrough = GUID$("{00000306-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_VerticalPositioning = GUID$("{00000307-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_ForegroundColor = GUID$("{00000308-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_BackgroundColor = GUID$("{00000309-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_ForegroundColorType = GUID$("{00000310-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_BackgroundColorType = GUID$("{00000311-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_FontProperties_ChangedProperties = GUID$("{00000312-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UNKNOWN)
MACRO UI_PKEY_FontProperties_DeltaSize = GUID$("{00000313-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_RecentItems = GUID$("{00000350-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_ARRAY OR %VT_UNKNOWN)
MACRO UI_PKEY_Pinned = GUID$("{00000351-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_BOOL)
MACRO UI_PKEY_Color = GUID$("{00000400-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ColorType = GUID$("{00000401-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ColorMode = GUID$("{00000402-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ThemeColorsCategoryLabel = GUID$("{00000403-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_StandardColorsCategoryLabel = GUID$("{00000404-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_RecentColorsCategoryLabel = GUID$("{00000405-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_AutomaticColorLabel = GUID$("{00000406-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_NoColorLabel = GUID$("{00000407-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_MoreColorsLabel = GUID$("{00000408-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_LPWSTR)
MACRO UI_PKEY_ThemeColors = GUID$("{00000409-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_VECTOR OR %VT_UI4)
MACRO UI_PKEY_StandardColors = GUID$("{00000410-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_VECTOR OR %VT_UI4)
MACRO UI_PKEY_ThemeColorsTooltips = GUID$("{00000411-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_VECTOR OR %VT_LPWSTR)
MACRO UI_PKEY_StandardColorsTooltips = GUID$("{00000412-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_VECTOR OR %VT_LPWSTR)
MACRO UI_PKEY_Viewable = GUID$("{00001000-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_BOOL)
MACRO UI_PKEY_Minimized = GUID$("{00001001-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_BOOL)
MACRO UI_PKEY_QuickAccessToolbarDock = GUID$("{00001002-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_ContextAvailable = GUID$("{00001100-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_GlobalBackgroundColor = GUID$("{00002000-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_GlobalHighlightColor = GUID$("{00002001-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)
MACRO UI_PKEY_GlobalTextColor = GUID$("{00002002-7363-696e-8441-798acf5aebb7}") & MKDWD$(%VT_UI4)

'typedef DWORD UI_HSBCOLOR;
'__inline UI_HSBCOLOR UI_HSB(BYTE hue, BYTE saturation, BYTE brightness)
'{
'    return hue | (saturation << 8) | (brightness << 16);
'}

FUNCTION UI_HSB (BYVAL hue AS BYTE, BYVAL saturation AS BYTE, BYVAL brightness AS BYTE) AS DWORD
   SHIFT LEFT saturation, 8
   SHIFT LEFT brightness, 16
   FUNCTION = hue OR saturation OR brightness
END FUNCTION

' enum UI_CONTEXTAVAILABILITY
%UI_CONTEXTAVAILABILITY_NOTAVAILABLE = 0
%UI_CONTEXTAVAILABILITY_AVAILABLE    = 1
%UI_CONTEXTAVAILABILITY_ACTIVE       = 2

' enum UI_FONTPROPERTIES
%UI_FONTPROPERTIES_NOTAVAILABLE = 0
%UI_FONTPROPERTIES_NOTSET       = 1
%UI_FONTPROPERTIES_SET          = 2

' enum UI_FONTVERTICALPOSITION
%UI_FONTVERTICALPOSITION_NOTAVAILABLE = 0
%UI_FONTVERTICALPOSITION_NOTSET       = 1
%UI_FONTVERTICALPOSITION_SUPERSCRIPT  = 2
%UI_FONTVERTICALPOSITION_SUBSCRIPT    = 3

' enum UI_FONTUNDERLINE
%UI_FONTUNDERLINE_NOTAVAILABLE = 0
%UI_FONTUNDERLINE_NOTSET       = 1
%UI_FONTUNDERLINE_SET          = 2

' enum UI_FONTDELTASIZE
%UI_FONTDELTASIZE_GROW   = 0
%UI_FONTDELTASIZE_SHRINK = 1

' enum UI_CONTROLDOCK
%UI_CONTROLDOCK_TOP    = 1
%UI_CONTROLDOCK_BOTTOM = 3

' enum UI_SWATCHCOLORTYPE
%UI_SWATCHCOLORTYPE_NOCOLOR   = 0
%UI_SWATCHCOLORTYPE_AUTOMATIC = 1
%UI_SWATCHCOLORTYPE_RGB       = 2

' enum UI_SWATCHCOLORMODE
%UI_SWATCHCOLORMODE_NORMAL     = 0
%UI_SWATCHCOLORMODE_MONOCHROME = 1

' ########################################################################################
' Interface name = IUISimplePropertySet
' IID = C205BB48-5B1C-4219-A106-15BD0A5F24E2
' Simple property bag
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUISimplePropertySet_INTERFACE_DEFINED)
    %IUISimplePropertySet_INTERFACE_DEFINED = 1

$IID_IUISimplePropertySet = GUID$("{C205BB48-5B1C-4219-A106-15BD0A5F24E2}")

INTERFACE IUISimplePropertySet $IID_IUISimplePropertySet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 12
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF value AS PROPVARIANT _                       ' __out PROPVARIANT *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUISimplePropertySet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIRibbon
' IID = 803982AB-370A-4F7E-A9E7-8784036A6E26
' Windows Ribbon IUIRibbon interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIRibbon_INTERFACE_DEFINED)
    %IUIRibbon_INTERFACE_DEFINED = 1

$IID_IUIRibbon = GUID$("{803982AB-370A-4F7E-A9E7-8784036A6E26}")

INTERFACE IUIRibbon $IID_IUIRibbon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 12
     BYREF cy AS DWORD _                                ' __out UINT32 *cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadSettingsFromStream ( _                    ' VTable offset = 16
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveSettingsToStream ( _                      ' VTable offset = 20
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIRibbon_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIFramework
' IID = F4F0385D-6872-43A8-AD09-4C339CB3F5C5
' Windows Ribbon Application interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIFramework_INTERFACE_DEFINED)
    %IUIFramework_INTERFACE_DEFINED = 1

$IID_IUIFramework = GUID$("{F4F0385D-6872-43A8-AD09-4C339CB3F5C5}")

' enum UI_INVALIDATIONS
%UI_INVALIDATIONS_STATE         = &H1
%UI_INVALIDATIONS_VALUE         = &H2
%UI_INVALIDATIONS_PROPERTY      = &H4
%UI_INVALIDATIONS_ALLPROPERTIES = &H8

'DEFINE_ENUM_FLAG_OPERATORS(UI_INVALIDATIONS)
%UI_ALL_COMMANDS = 0

INTERFACE IUIFramework $IID_IUIFramework

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL frameWnd AS DWORD _                          ' __in frameWnd HWND
   , BYVAL application AS IUIApplication _              ' __in IUIApplication *application
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadUI ( _                                    ' VTable offset = 20
     BYVAL instance AS DWORD _                          ' __in HINSTANCE *instance
   , BYREF resourceName AS WSTRINGZ _                   ' __in LPCWSTR resourceName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetView ( _                                   ' VTable offset = 24
     BYVAL viewId AS DWORD _                            ' __in UINT32 viewId
   , BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUICommandProperty ( _                      ' VTable offset = 28
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF value AS PROPVARIANT _                       ' __out PROPVARIANT *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUICommandProperty ( _                      ' VTable offset = 32
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF value AS PROPVARIANT _                       ' __in PROPVARIANT *value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvalidateUICommand ( _                       ' VTable offset = 36
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYVAL flags AS LONG _                              ' __in UI_INVALIDATIONS flags
   , BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlushPendingInvalidations ( _                 ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetModes ( _                                  ' VTable offset = 44
     BYVAL iModes AS LONG _                             ' __in INT32 iModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIFramework_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIContextualUI
' IID = EEA11F37-7C46-437C-8E55-B52122B29293
' Provides the core functionality for the Context Popup View.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIContextualUI_INTERFACE_DEFINED)
    %IUIContextualUI_INTERFACE_DEFINED = 1

$IID_IUIContextualUI = GUID$("{EEA11F37-7C46-437C-8E55-B52122B29293}")

INTERFACE IUIContextualUI $IID_IUIContextualUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowAtLocation ( _                            ' VTable offset = 12
     BYVAL x AS LONG _                                  ' __in INT32 x
   , BYVAL y AS LONG _                                  ' __in INT32 y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIContextualUI_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUICollection
' IID = DF4F45BF-6F9D-4DD7-9D68-D8F9CD18C4DB
' Defines the methods for dynamically manipulating collection-based control.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUICollection_INTERFACE_DEFINED)
    %IUICollection_INTERFACE_DEFINED = 1

$IID_IUICollection = GUID$("{DF4F45BF-6F9D-4DD7-9D68-D8F9CD18C4DB}")

INTERFACE IUICollection $IID_IUICollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS LONG _                              ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF item AS IUnknown _                           ' __out IUnknown **item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYVAL item AS IUnknown _                           ' __in IUnknown *item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYVAL item AS IUnknown _                           ' __in IUnknown *item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Replace ( _                                   ' VTable offset = 32
     BYVAL indexReplaced AS DWORD _                     ' __in UINT32 indexReplaced
   , BYVAL itemReplaceWith AS IUnknown _                ' __in IUnknown *itemReplaceWith
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUICollection_INTERFACE_DEFINED__ */

' enum UI_COLLECTIONCHANGE
%UI_COLLECTIONCHANGE_INSERT  = 0
%UI_COLLECTIONCHANGE_REMOVE  = 1
%UI_COLLECTIONCHANGE_REPLACE = 2
%UI_COLLECTIONCHANGE_RESET   = 3

%UI_COLLECTION_INVALIDINDEX  = &Hffffffff???

' ########################################################################################
' Interface name = IUICollectionChangedEvent
' IID = 6502AE91-A14D-44B5-BBD0-62AACC581D52
' The IUICollectionChangedEvent interface is implemented by the application and defines
' the method required to handle changes to a collection at run time.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUICollectionChangedEvent_INTERFACE_DEFINED)
    %IUICollectionChangedEvent_INTERFACE_DEFINED = 1

$IID_IUICollectionChangedEvent = GUID$("{6502AE91-A14D-44B5-BBD0-62AACC581D52}")

INTERFACE IUICollectionChangedEvent $IID_IUICollectionChangedEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChanged( _                                  ' VTable offset = 12
     BYVAL action AS LONG _                             ' __in UI_COLLECTIONCHANGE action
   , BYVAL oldIndex AS DWORD _                          ' __in UINT32 oldIndex
   , BYVAL oldItem AS IUnknown _                        ' __in_opt IUnknown *oldItem
   , BYVAL newIndex AS DWORD _                          ' __in UINT32 newIndex
   , BYVAL newItem AS IUnknown _                        ' __in_opt IUnknown *newItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUICollectionChangedEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IUICommandHandler
' IID = 75AE0A2D-DC03-4C9F-8883-069660D0BEB6
' Command handler interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUICommandHandler_INTERFACE_DEFINED)
    %IUICommandHandler_INTERFACE_DEFINED = 1

$IID_IUICommandHandler = GUID$("{75AE0A2D-DC03-4C9F-8883-069660D0BEB6}")

' enum UI_EXECUTIONVERB
%UI_EXECUTIONVERB_EXECUTE       = 0
%UI_EXECUTIONVERB_PREVIEW       = 1
%UI_EXECUTIONVERB_CANCELPREVIEW = 2

INTERFACE IUICommandHandler $IID_IUICommandHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 12
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYVAL verb AS LONG _                               ' __in UI_EXECUTIONVERB verb
   , BYREF key AS PROPERTYKEY _                         ' __in_opt const PROPERTYKEY *key
   , BYREF currentValue AS PROPVARIANT _                ' __in_opt const PROPVARIANT *currentValue
   , BYVAL commandExecutionProperties AS IUISimplePropertySet _ ' __in_opt IUISimplePropertySet *commandExecutionProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateProperty ( _                            ' VTable offset = 16
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY *key
   , BYREF currentValue AS PROPVARIANT _                ' __in_opt const PROPVARIANT *currentValue
   , BYREF newValue AS PROPVARIANT _                    ' __out PROPVARIANT *newValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUICommandHandler_INTERFACE_DEFINED__ */

' enum UI_COMMANDTYPE
%UI_COMMANDTYPE_UNKNOWN           = 0
%UI_COMMANDTYPE_GROUP             = 1
%UI_COMMANDTYPE_ACTION            = 2
%UI_COMMANDTYPE_ANCHOR            = 3
%UI_COMMANDTYPE_CONTEXT           = 4
%UI_COMMANDTYPE_COLLECTION        = 5
%UI_COMMANDTYPE_COMMANDCOLLECTION = 6
%UI_COMMANDTYPE_DECIMAL           = 7
%UI_COMMANDTYPE_BOOLEAN           = 8
%UI_COMMANDTYPE_FONT              = 9
%UI_COMMANDTYPE_RECENTITEMS       = 10
%UI_COMMANDTYPE_COLORANCHOR       = 11
%UI_COMMANDTYPE_COLORCOLLECTION   = 12

' enum UI_VIEWTYPE
%UI_VIEWTYPE_RIBBON = 1

' ########################################################################################
' Interface name = IUIApplication
' IID = D428903C-729A-491D-910D-682A08FF2522
' Application callback interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIApplication_INTERFACE_DEFINED)
    %IUIApplication_INTERFACE_DEFINED = 1

$IID_IUIApplication = GUID$("{D428903C-729A-491D-910D-682A08FF2522}")

' enum UI_VIEWVERB
%UI_VIEWVERB_CREATE  = 0
%UI_VIEWVERB_DESTROY = 1
%UI_VIEWVERB_SIZE    = 2
%UI_VIEWVERB_ERROR   = 3

INTERFACE IUIApplication $IID_IUIApplication

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnViewChanged ( _                             ' VTable offset = 12
     BYVAL viewId AS DWORD _                            ' __in INT32 viewId
   , BYVAL typeID AS LONG _                             ' __in UI_VIEWTYPE typeID
   , BYVAL view AS IUnknown _                           ' __in IUnknown *view
   , BYVAL verb AS LONG _                               ' __in UI_VIEWVERB verb
   , BYVAL uReasonCode AS LONG _                        ' __in INT32 uReasonCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateUICommand ( _                         ' VTable offset = 16
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYVAL typeID AS LONG _                             ' __in UI_COMMANDTYPE typeID
   , BYREF commandHandler AS IUICommandHandler _        ' __out IUICommandHandler **commandHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDestroyUICommand ( _                        ' VTable offset = 20
     BYVAL commandId AS DWORD _                         ' __in UINT32 commandId
   , BYVAL typeID AS LONG _                             ' __in UI_COMMANDTYPE typeID
   , BYVAL commandHandler AS IUICommandHandler _        ' __in_opt IUICommandHandler *commandHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIImage
' IID = 23C8C838-4DE6-436B-AB01-5554BB7C30DD
' Container for bitmap image
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIImage_INTERFACE_DEFINED)
    %IUIImage_INTERFACE_DEFINED = 1

$IID_IUIImage = GUID$("{23C8C838-4DE6-436B-AB01-5554BB7C30DD}")

INTERFACE IUIImage $IID_IUIImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBitmap ( _                                 ' VTable offset = 12
     BYREF bitmap AS DWORD _                            ' __out HBITMAP *bitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIImage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIImageFromBitmap
' IID = 18ABA7F3-4C1C-4BA2-BF6C-F5C3326FA816
' Produces containers for bitmap images
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIImageFromBitmap_INTERFACE_DEFINED)
    %IUIImageFromBitmap_INTERFACE_DEFINED = 1

$IID_IUIImageFromBitmap = GUID$("{18ABA7F3-4C1C-4BA2-BF6C-F5C3326FA816}")

' enum UI_OWNERSHIP
%UI_OWNERSHIP_TRANSFER = 0
%UI_OWNERSHIP_COPY     = 1

INTERFACE IUIImageFromBitmap $IID_IUIImageFromBitmap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateImage ( _                               ' VTable offset = 12
     BYVAL bitmap AS DWORD _                            ' __in HBITMAP bitmap
   , BYVAL options AS LONG _                            ' __in UI_OWNERSHIP options
   , BYREF image AS IUIImage _                          ' __out IUIImage **image
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIImageFromBitmap_INTERFACE_DEFINED__ */

'#define UI_MAKEAPPMODE(x) (1 << (x))
FUNCTION UI_MAKEAPPMODE (BYVAL x AS LONG) AS LONG
   LOCAL m AS LONG
   m = 1
   SHIFT LEFT m, x
   FUNCTION = m
END FUNCTION
