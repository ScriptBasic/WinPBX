' ########################################################################################
' Microsoft Windows
' File: MSComCtl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSComctlLib
' Version: 2.0, Locale ID = 0
' Description: Microsoft Windows Common Controls 6.0 (SP6)
' Path: C:\WINDOWS\system32\MSCOMCTL.OCX
' Library GUID: {831FDD16-0C5C-11D2-A9FC-0000F8754DA1}
' Help file: C:\WINDOWS\system32\cmctl198.chm
' License key: 9368265E-85FE-11d1-8BE3-0000F8754DA1
' ########################################################################################

#INCLUDE THIS ONCE
%MSCOMCTL_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vbinterf.inc"

$RTLKEY_MSCOMCTL = "9368265E-85FE-11d1-8BE3-0000F8754DA1"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {DD9DA666-8594-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ImageCombo2 = "MSComctlLib.ImageComboCtl.2"
' CLSID = {2C247F23-8591-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ImageList2 = "MSComctlLib.ImageListCtrl.2"
' CLSID = {BDD1F04B-858B-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ListView2 = "MSComctlLib.ListViewCtrl.2"
' CLSID = {35053A22-8589-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ProgressBar2 = "MSComctlLib.ProgCtrl.2"
' CLSID = {8E3867A3-8586-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_StatusBar2 = "MSComctlLib.SBarCtrl.2"
' CLSID = {F08DF954-8592-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_Slider2 = "MSComctlLib.Slider.2"
' CLSID = {1EFB6596-857C-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_TabStrip2 = "MSComctlLib.TabStrip.2"
' CLSID = {66833FE6-8583-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_Toolbar2 = "MSComctlLib.Toolbar.2"
' CLSID = {C74190B6-8589-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_TreeView2 = "MSComctlLib.TreeCtrl.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {DD9DA666-8594-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ImageCombo = "MSComctlLib.ImageComboCtl"
' CLSID = {2C247F23-8591-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ImageList = "MSComctlLib.ImageListCtrl"
' CLSID = {BDD1F04B-858B-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ListView = "MSComctlLib.ListViewCtrl"
' CLSID = {35053A22-8589-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_ProgressBar = "MSComctlLib.ProgCtrl"
' CLSID = {8E3867A3-8586-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_StatusBar = "MSComctlLib.SBarCtrl"
' CLSID = {F08DF954-8592-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_Slider = "MSComctlLib.Slider"
' CLSID = {1EFB6596-857C-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_TabStrip = "MSComctlLib.TabStrip"
' CLSID = {66833FE6-8583-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_Toolbar = "MSComctlLib.Toolbar"
' CLSID = {C74190B6-8589-11D1-B16A-00C0F0283628}
$PROGID_MSComCtl_TreeView = "MSComctlLib.TreeCtrl"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSComCtl_Button = GUID$("{66833FEA-8583-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ButtonMenu = GUID$("{66833FEE-8583-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ButtonMenus = GUID$("{66833FEC-8583-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Buttons = GUID$("{66833FE8-8583-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ColumnHeader = GUID$("{BDD1F052-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ColumnHeaders = GUID$("{0713E8C6-850A-101B-AFC0-4210102A8DA7}")
$CLSID_MSComCtl_ComboItem = GUID$("{DD9DA661-8594-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ComboItems = GUID$("{DD9DA663-8594-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Controls = GUID$("{C8A3DC01-8593-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListImage = GUID$("{2C247F27-8591-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListImages = GUID$("{2C247F25-8591-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListItem = GUID$("{BDD1F04F-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListItems = GUID$("{BDD1F04D-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListSubItem = GUID$("{BDD1F056-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListSubItems = GUID$("{BDD1F054-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Node = GUID$("{C74190B9-8589-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Nodes = GUID$("{0713E8C0-850A-101B-AFC0-4210102A8DA7}")
$CLSID_MSComCtl_Panel = GUID$("{8E3867AB-8586-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Panels = GUID$("{8E3867A5-8586-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Tab = GUID$("{1EFB659A-857C-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Tabs = GUID$("{1EFB6598-857C-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ImageCombo = GUID$("{DD9DA666-8594-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ImageList = GUID$("{2C247F23-8591-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ListView = GUID$("{BDD1F04B-858B-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_ProgressBar = GUID$("{35053A22-8589-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_StatusBar = GUID$("{8E3867A3-8586-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Slider = GUID$("{F08DF954-8592-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_TabStrip = GUID$("{1EFB6596-857C-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_Toolbar = GUID$("{66833FE6-8583-11D1-B16A-00C0F0283628}")
$CLSID_MSComCtl_TreeView = GUID$("{C74190B6-8589-11D1-B16A-00C0F0283628}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_MSComCtl_DImageComboEvents = GUID$("{DD9DA665-8594-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IButton = GUID$("{66833FE9-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IButtonMenu = GUID$("{66833FED-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IButtonMenus = GUID$("{66833FEB-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IButtons = GUID$("{66833FE7-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IColumnHeader = GUID$("{BDD1F051-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IColumnHeaders = GUID$("{BDD1F050-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IComboItem = GUID$("{DD9DA660-8594-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IComboItems = GUID$("{DD9DA662-8594-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IControls = GUID$("{C8A3DC00-8593-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IImage = GUID$("{2C247F26-8591-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IImageCombo = GUID$("{DD9DA664-8594-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IImageList = GUID$("{2C247F21-8591-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IImages = GUID$("{2C247F24-8591-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IListItem = GUID$("{BDD1F04E-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IListItems = GUID$("{BDD1F04C-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IListSubItem = GUID$("{BDD1F055-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IListSubItems = GUID$("{BDD1F053-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IListView = GUID$("{BDD1F049-858B-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ImageListEvents = GUID$("{2C247F22-8591-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_INode = GUID$("{C74190B8-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_INodes = GUID$("{C74190B7-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IPanel = GUID$("{8E3867AA-8586-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IPanels = GUID$("{8E3867A4-8586-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IProgressBar = GUID$("{35053A20-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IProgressBarEvents = GUID$("{35053A21-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ISlider = GUID$("{F08DF952-8592-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ISliderEvents = GUID$("{F08DF953-8592-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IStatusBar = GUID$("{8E3867A1-8586-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IStatusBarEvents = GUID$("{8E3867A2-8586-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITab = GUID$("{1EFB6599-857C-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITabs = GUID$("{1EFB6597-857C-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITabStrip = GUID$("{1EFB6594-857C-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITabStripEvents = GUID$("{1EFB6595-857C-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IToolbar = GUID$("{66833FE4-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_IToolbarEvents = GUID$("{66833FE5-8583-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITreeView = GUID$("{C74190B4-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ITreeViewEvents = GUID$("{C74190B5-8589-11D1-B16A-00C0F0283628}")
$IID_MSComCtl_ListViewEvents = GUID$("{BDD1F04A-858B-11D1-B16A-00C0F0283628}")

' ========================================================================================
' BorderStyleConstants enum
' IID: {76B523C0-8579-11D1-B16A-00C0F0283628}
' BorderStyle constants
' ========================================================================================

%ccNone                                                 = 0            ' &H0
%ccFixedSingle                                          = 1            ' &H1

' ========================================================================================
' MousePointerConstants enum
' IID: {76B523C1-8579-11D1-B16A-00C0F0283628}
' MousePointer constants
' ========================================================================================

%ccDefault                                              = 0            ' &H0
%ccArrow                                                = 1            ' &H1
%ccCross                                                = 2            ' &H2
%ccIBeam                                                = 3            ' &H3
%ccIcon                                                 = 4            ' &H4
%ccSize                                                 = 5            ' &H5
%ccSizeNESW                                             = 6            ' &H6
%ccSizeNS                                               = 7            ' &H7
%ccSizeNWSE                                             = 8            ' &H8
%ccSizeEW                                               = 9            ' &H9
%ccUpArrow                                              = 10           ' &HA
%ccHourglass                                            = 11           ' &HB
%ccNoDrop                                               = 12           ' &HC
%ccArrowHourglass                                       = 13           ' &HD
%ccArrowQuestion                                        = 14           ' &HE
%ccSizeAll                                              = 15           ' &HF
%ccCustom                                               = 99           ' &H63

' ========================================================================================
' AppearanceConstants enum
' IID: {76B523C2-8579-11D1-B16A-00C0F0283628}
' Appearance constants
' ========================================================================================

%ccFlat                                                 = 0            ' &H0
%cc3D                                                   = 1            ' &H1

' ========================================================================================
' VB4AppearanceConstants enum
' ========================================================================================

%vbFlat                                                 = 0            ' &H0
%vb3D                                                   = 1            ' &H1

' ========================================================================================
' ScrollingConstants enum
' IID: {76B523C3-8579-11D1-B16A-00C0F0283628}
' Scrolling constants
' ========================================================================================

%ccScrollingStandard                                    = 0            ' &H0
%ccScrollingSmooth                                      = 1            ' &H1

' ========================================================================================
' OrientationConstants enum
' IID: {76B523C4-8579-11D1-B16A-00C0F0283628}
' Slider orientation constants
' ========================================================================================

%ccOrientationHorizontal                                = 0            ' &H0
%ccOrientationVertical                                  = 1            ' &H1

' ========================================================================================
' OLEDragConstants enum
' IID: {D8898460-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDragMode property (but not the DragMode or OLEDropMode properties).
' ========================================================================================

%ccOLEDragManual                                        = 0            ' &H0
%ccOLEDragAutomatic                                     = 1            ' &H1

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%ccOLEDropNone                                          = 0            ' &H0
%ccOLEDropManual                                        = 1            ' &H1

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%ccEnter                                                = 0            ' &H0
%ccLeave                                                = 1            ' &H1
%ccOver                                                 = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%ccCFText                                               = 1            ' &H1
%ccCFBitmap                                             = 2            ' &H2
%ccCFMetafile                                           = 3            ' &H3
%ccCFDIB                                                = 8            ' &H8
%ccCFPalette                                            = 9            ' &H9
%ccCFEMetafile                                          = 14           ' &HE
%ccCFFiles                                              = 15           ' &HF
%ccCFRTF                                                = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%ccOLEDropEffectNone                                    = 0            ' &H0
%ccOLEDropEffectCopy                                    = 1            ' &H1
%ccOLEDropEffectMove                                    = 2            ' &H2
%ccOLEDropEffectScroll                                  = -2147483648  ' &H80000000

' ========================================================================================
' ErrorConstants enum
' IID: {76B523C5-8579-11D1-B16A-00C0F0283628}
' Error constants
' ========================================================================================

%ccInvalidProcedureCall                                 = 5            ' &H5
%ccOutOfMemory                                          = 7            ' &H7
%ccTypeMismatch                                         = 13           ' &HD
%ccObjectVariableNotSet                                 = 91           ' &H5B
%ccInvalidPropertyValue                                 = 380          ' &H17C
%ccSetNotSupportedAtRuntime                             = 382          ' &H17E
%ccSetNotSupported                                      = 383          ' &H17F
%ccSetNotPermitted                                      = 387          ' &H183
%ccGetNotSupported                                      = 394          ' &H18A
%ccInvalidPicture                                       = 481          ' &H1E1
%ccInvalidObjectUse                                     = 425          ' &H1A9
%ccWrongClipboardFormat                                 = 461          ' &H1CD
%ccDataObjectLocked                                     = 672          ' &H2A0
%ccExpectedAnArgument                                   = 673          ' &H2A1
%ccRecursiveOleDrag                                     = 674          ' &H2A2
%ccFormatNotByteArray                                   = 675          ' &H2A3
%ccDataNotSetForFormat                                  = 676          ' &H2A4
%ccIndexOutOfBounds                                     = 35600        ' &H8B10
%ccElemNotFound                                         = 35601        ' &H8B11
%ccNonUniqueKey                                         = 35602        ' &H8B12
%ccInvalidKey                                           = 35603        ' &H8B13
%ccElemNotPartOfCollection                              = 35605        ' &H8B15
%ccCollectionChangedDuringEnum                          = 35606        ' &H8B16
%ccWouldIntroduceCycle                                  = 35614        ' &H8B1E
%ccMissingRequiredArg                                   = 35607        ' &H8B17
%ccBadObjectReference                                   = 35610        ' &H8B1A
%ccCircularReference                                    = 35700        ' &H8B74
%ccCol1MustBeLeftAligned                                = 35604        ' &H8B14
%ccReadOnlyIfHasImages                                  = 35611        ' &H8B1B
%ccImageListMustBeInitialized                           = 35613        ' &H8B1D
%ccNotSameSize                                          = 35615        ' &H8B1F
%ccImageListLocked                                      = 35617        ' &H8B21
%ccMaxPanelsExceeded                                    = 35616        ' &H8B20
%ccMaxButtonsExceeded                                   = 35619        ' &H8B23
%ccInvalidSafeModeProcCall                              = 680          ' &H2A8

' ========================================================================================
' TabWidthStyleConstants enum
' IID: {1EFB6590-857C-11D1-B16A-00C0F0283628}
' TabWidthStyle constants.
' ========================================================================================

%tabJustified                                           = 0            ' &H0
%tabNonJustified                                        = 1            ' &H1
%tabFixed                                               = 2            ' &H2

' ========================================================================================
' TabStyleConstants enum
' IID: {1EFB6591-857C-11D1-B16A-00C0F0283628}
' TabStyle constants.
' ========================================================================================

%tabTabs                                                = 0            ' &H0
%tabButtons                                             = 1            ' &H1
%tabFlatButtons                                         = 2            ' &H2

' ========================================================================================
' PlacementConstants enum
' IID: {1EFB6592-857C-11D1-B16A-00C0F0283628}
' Placement constants.
' ========================================================================================

%tabPlacementTop                                        = 0            ' &H0
%tabPlacementBottom                                     = 1            ' &H1
%tabPlacementLeft                                       = 2            ' &H2
%tabPlacementRight                                      = 3            ' &H3

' ========================================================================================
' TabSelStyleConstants enum
' IID: {1EFB6593-857C-11D1-B16A-00C0F0283628}
' Tab selection style constants.
' ========================================================================================

%tabTabStandard                                         = 0            ' &H0
%tabTabOpposite                                         = 1            ' &H1

' ========================================================================================
' ButtonStyleConstants enum
' IID: {66833FE0-8583-11D1-B16A-00C0F0283628}
' Toolbar Button Style constants.
' ========================================================================================

%tbrDefault                                             = 0            ' &H0
%tbrCheck                                               = 1            ' &H1
%tbrButtonGroup                                         = 2            ' &H2
%tbrSeparator                                           = 3            ' &H3
%tbrPlaceholder                                         = 4            ' &H4
%tbrDropdown                                            = 5            ' &H5

' ========================================================================================
' ValueConstants enum
' IID: {66833FE1-8583-11D1-B16A-00C0F0283628}
' Toolbar Value constants.
' ========================================================================================

%tbrUnpressed                                           = 0            ' &H0
%tbrPressed                                             = 1            ' &H1

' ========================================================================================
' ToolbarStyleConstants enum
' IID: {66833FE2-8583-11D1-B16A-00C0F0283628}
' Toolbar Style constants.
' ========================================================================================

%tbrStandard                                            = 0            ' &H0
%tbrFlat                                                = 1            ' &H1

' ========================================================================================
' ToolbarTextAlignConstants enum
' IID: {66833FE3-8583-11D1-B16A-00C0F0283628}
' Toolbar Text Alignment constants.
' ========================================================================================

%tbrTextAlignBottom                                     = 0            ' &H0
%tbrTextAlignRight                                      = 1            ' &H1

' ========================================================================================
' SbarStyleConstants enum
' IID: {8E3867A0-8586-11D1-B16A-00C0F0283628}
' StatusBar Style constants
' ========================================================================================

%sbrNormal                                              = 0            ' &H0
%sbrSimple                                              = 1            ' &H1

' ========================================================================================
' PanelAlignmentConstants enum
' IID: {8E3867A6-8586-11D1-B16A-00C0F0283628}
' Panel Alignment constants
' ========================================================================================

%sbrLeft                                                = 0            ' &H0
%sbrCenter                                              = 1            ' &H1
%sbrRight                                               = 2            ' &H2

' ========================================================================================
' PanelAutoSizeConstants enum
' IID: {8E3867A7-8586-11D1-B16A-00C0F0283628}
' Panel AutoSize constants
' ========================================================================================

%sbrNoAutoSize                                          = 0            ' &H0
%sbrSpring                                              = 1            ' &H1
%sbrContents                                            = 2            ' &H2

' ========================================================================================
' PanelBevelConstants enum
' IID: {8E3867A8-8586-11D1-B16A-00C0F0283628}
' Panel Bevel constants
' ========================================================================================

%sbrNoBevel                                             = 0            ' &H0
%sbrInset                                               = 1            ' &H1
%sbrRaised                                              = 2            ' &H2

' ========================================================================================
' PanelStyleConstants enum
' IID: {8E3867A9-8586-11D1-B16A-00C0F0283628}
' Panel Style constants
' ========================================================================================

%sbrText                                                = 0            ' &H0
%sbrCaps                                                = 1            ' &H1
%sbrNum                                                 = 2            ' &H2
%sbrIns                                                 = 3            ' &H3
%sbrScrl                                                = 4            ' &H4
%sbrTime                                                = 5            ' &H5
%sbrDate                                                = 6            ' &H6
%sbrKana                                                = 7            ' &H7

' ========================================================================================
' LabelEditConstants enum
' IID: {C74190B0-8589-11D1-B16A-00C0F0283628}
' LabelEdit constants
' ========================================================================================

%tvwAutomatic                                           = 0            ' &H0
%tvwManual                                              = 1            ' &H1

' ========================================================================================
' TreeLineStyleConstants enum
' IID: {C74190B1-8589-11D1-B16A-00C0F0283628}
' TreeLine style constants
' ========================================================================================

%tvwTreeLines                                           = 0            ' &H0
%tvwRootLines                                           = 1            ' &H1

' ========================================================================================
' TreeStyleConstants enum
' IID: {C74190B2-8589-11D1-B16A-00C0F0283628}
' TreeStyle constants
' ========================================================================================

%tvwTextOnly                                            = 0            ' &H0
%tvwPictureText                                         = 1            ' &H1
%tvwPlusMinusText                                       = 2            ' &H2
%tvwPlusPictureText                                     = 3            ' &H3
%tvwTreelinesText                                       = 4            ' &H4
%tvwTreelinesPictureText                                = 5            ' &H5
%tvwTreelinesPlusMinusText                              = 6            ' &H6
%tvwTreelinesPlusMinusPictureText                       = 7            ' &H7

' ========================================================================================
' TreeRelationshipConstants enum
' IID: {C74190B3-8589-11D1-B16A-00C0F0283628}
' TreeView Relationship constants
' ========================================================================================

%tvwFirst                                               = 0            ' &H0
%tvwLast                                                = 1            ' &H1
%tvwNext                                                = 2            ' &H2
%tvwPrevious                                            = 3            ' &H3
%tvwChild                                               = 4            ' &H4

' ========================================================================================
' ListTextBackgroundConstants enum
' IID: {BDD1F040-858B-11D1-B16A-00C0F0283628}
' TextBackground constants
' ========================================================================================

%lvwTransparent                                         = 0            ' &H0
%lvwOpaque                                              = 1            ' &H1

' ========================================================================================
' ListArrangeConstants enum
' IID: {BDD1F041-858B-11D1-B16A-00C0F0283628}
' ListArrange constants
' ========================================================================================

%lvwNone                                                = 0            ' &H0
%lvwAutoLeft                                            = 1            ' &H1
%lvwAutoTop                                             = 2            ' &H2

' ========================================================================================
' ListPictureAlignmentConstants enum
' IID: {BDD1F042-858B-11D1-B16A-00C0F0283628}
' Determines the placement of the background picture.
' ========================================================================================

%lvwTopLeft                                             = 0            ' &H0
%lvwTopRight                                            = 1            ' &H1
%lvwBottomLeft                                          = 2            ' &H2
%lvwBottomRight                                         = 3            ' &H3
%lvwCenter                                              = 4            ' &H4
%lvwTile                                                = 5            ' &H5

' ========================================================================================
' ListLabelEditConstants enum
' IID: {BDD1F043-858B-11D1-B16A-00C0F0283628}
' LabelEdit constants
' ========================================================================================

%lvwAutomatic                                           = 0            ' &H0
%lvwManual                                              = 1            ' &H1

' ========================================================================================
' ListSortOrderConstants enum
' IID: {BDD1F044-858B-11D1-B16A-00C0F0283628}
' SortOrder constants
' ========================================================================================

%lvwAscending                                           = 0            ' &H0
%lvwDescending                                          = 1            ' &H1

' ========================================================================================
' ListViewConstants enum
' IID: {BDD1F045-858B-11D1-B16A-00C0F0283628}
' View constants
' ========================================================================================

%lvwIcon                                                = 0            ' &H0
%lvwSmallIcon                                           = 1            ' &H1
%lvwList                                                = 2            ' &H2
%lvwReport                                              = 3            ' &H3

' ========================================================================================
' ListColumnAlignmentConstants enum
' IID: {BDD1F046-858B-11D1-B16A-00C0F0283628}
' ColumnAlignment constants
' ========================================================================================

%lvwColumnLeft                                          = 0            ' &H0
%lvwColumnRight                                         = 1            ' &H1
%lvwColumnCenter                                        = 2            ' &H2

' ========================================================================================
' ListFindItemWhereConstants enum
' IID: {BDD1F047-858B-11D1-B16A-00C0F0283628}
' FindItemWhere constants
' ========================================================================================

%lvwText                                                = 0            ' &H0
%lvwSubItem                                             = 1            ' &H1
%lvwTag                                                 = 2            ' &H2

' ========================================================================================
' ListFindItemHowConstants enum
' IID: {BDD1F048-858B-11D1-B16A-00C0F0283628}
' FindItemHow constants
' ========================================================================================

%lvwWhole                                               = 0            ' &H0
%lvwPartial                                             = 1            ' &H1

' ========================================================================================
' ImageDrawConstants enum
' IID: {2C247F20-8591-11D1-B16A-00C0F0283628}
' ImageList Draw constants
' ========================================================================================

%imlNormal                                              = 0            ' &H0
%imlTransparent                                         = 1            ' &H1
%imlSelected                                            = 2            ' &H2
%imlFocus                                               = 3            ' &H3

' ========================================================================================
' TickStyleConstants enum
' IID: {F08DF950-8592-11D1-B16A-00C0F0283628}
' TickStyle constants
' ========================================================================================

%sldBottomRight                                         = 0            ' &H0
%sldTopLeft                                             = 1            ' &H1
%sldBoth                                                = 2            ' &H2
%sldNoTicks                                             = 3            ' &H3

' ========================================================================================
' TextPositionConstants enum
' IID: {F08DF951-8592-11D1-B16A-00C0F0283628}
' TextPosition constants
' ========================================================================================

%sldAboveLeft                                           = 0            ' &H0
%sldBelowRight                                          = 1            ' &H1

' ========================================================================================
' ImageComboStyleConstants enum
' IID: {DD9DA667-8594-11D1-B16A-00C0F0283628}
' Constants for the Style property of a ComboBox control.
' ========================================================================================

%ImgCboDropdownCombo                                    = 0            ' &H0
%ImgCboSimpleCombo                                      = 1            ' &H1
%ImgCboDropdownList                                     = 2            ' &H2

' ########################################################################################
' Interface name = ITabStrip
' IID = {1EFB6594-857C-11D1-B16A-00C0F0283628}
' Microsoft TabStrip Control
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_ITabStrip_INTERFACE_DEFINED)
    %MSComCtl_ITabStrip_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_ITabStrip $IID_MSComCtl_ITabStrip

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Tabs <4> ( _                            ' VTable offset = 28
   ) AS MSComCtl_ITabs                                  ' __retval_out ITabs **ppTabs
   ' =====================================================================================
   PROPERTY SET putref_Tabs <4> ( _                     ' VTable offset = 32
     BYVAL ppTabs AS MSComCtl_ITabs _                   ' __in ITabs *ppTabs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 40
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 44
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFontDisp
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 48
     BYVAL ppFontDisp AS IFontDisp _                    ' __in IFontDisp *ppFontDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 56
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <5> ( _                       ' VTable offset = 60
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <5> ( _                       ' VTable offset = 64
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <5> ( _                ' VTable offset = 68
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiRow <1> ( _                        ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMultiRow
   ' =====================================================================================
   PROPERTY SET MultiRow <1> ( _                        ' VTable offset = 76
     BYVAL pbMultiRow AS INTEGER _                      ' __in VARIANT_BOOL pbMultiRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <6> ( _                           ' VTable offset = 80
   ) AS LONG                                            ' __retval_out TabStyleConstants *psStyle
   ' =====================================================================================
   PROPERTY SET Style <6> ( _                           ' VTable offset = 84
     BYVAL psStyle AS LONG _                            ' __in TabStyleConstants psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabFixedWidth <7> ( _                   ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out short *psTabFixedWidth
   ' =====================================================================================
   PROPERTY SET TabFixedWidth <7> ( _                   ' VTable offset = 92
     BYVAL psTabFixedWidth AS INTEGER _                 ' __in short psTabFixedWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabWidthStyle <8> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out TabWidthStyleConstants *psTabWidthStyle
   ' =====================================================================================
   PROPERTY SET TabWidthStyle <8> ( _                   ' VTable offset = 100
     BYVAL psTabWidthStyle AS LONG _                    ' __in TabWidthStyleConstants psTabWidthStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientTop <9> ( _                       ' VTable offset = 104
   ) AS SINGLE                                          ' __retval_out float *pfClientTop
   ' =====================================================================================
   PROPERTY SET ClientTop <9> ( _                       ' VTable offset = 108
     BYVAL pfClientTop AS SINGLE _                      ' __in float pfClientTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientLeft <10> ( _                     ' VTable offset = 112
   ) AS SINGLE                                          ' __retval_out float *pfClientLeft
   ' =====================================================================================
   PROPERTY SET ClientLeft <10> ( _                     ' VTable offset = 116
     BYVAL pfClientLeft AS SINGLE _                     ' __in float pfClientLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientHeight <11> ( _                   ' VTable offset = 120
   ) AS SINGLE                                          ' __retval_out float *pfClientHeight
   ' =====================================================================================
   PROPERTY SET ClientHeight <11> ( _                   ' VTable offset = 124
     BYVAL pfClientHeight AS SINGLE _                   ' __in float pfClientHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientWidth <12> ( _                    ' VTable offset = 128
   ) AS SINGLE                                          ' __retval_out float *pfClientWidth
   ' =====================================================================================
   PROPERTY SET ClientWidth <12> ( _                    ' VTable offset = 132
     BYVAL pfClientWidth AS SINGLE _                    ' __in float pfClientWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <2> ( _                    ' VTable offset = 136
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <2> ( _                    ' VTable offset = 140
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageList <13> ( _                      ' VTable offset = 144
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET ImageList <13> ( _                      ' VTable offset = 148
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ImageList <13> ( _               ' VTable offset = 152
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabFixedHeight <14> ( _                 ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out short *psTabFixedHeight
   ' =====================================================================================
   PROPERTY SET TabFixedHeight <14> ( _                 ' VTable offset = 160
     BYVAL psTabFixedHeight AS INTEGER _                ' __in short psTabFixedHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTips <3> ( _                        ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowTips
   ' =====================================================================================
   PROPERTY SET ShowTips <3> ( _                        ' VTable offset = 168
     BYVAL pbShowTips AS INTEGER _                      ' __in VARIANT_BOOL pbShowTips
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <15> ( _                   ' VTable offset = 172
   ) AS MSComCtl_ITab                                   ' __retval_out ITab **ppSelectedItem
   ' =====================================================================================
   PROPERTY SET putref_SelectedItem <15> ( _            ' VTable offset = 176
     BYVAL ppSelectedItem AS MSComCtl_ITab _            ' __in ITab *ppSelectedItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SelectedItem <15> ( _                   ' VTable offset = 180
     BYREF IN ppSelectedItem AS VARIANT _               ' __in VARIANT *ppSelectedItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 184
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 188
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 196
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 200
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HotTracking <16> ( _                    ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHotTracking
   ' =====================================================================================
   PROPERTY SET HotTracking <16> ( _                    ' VTable offset = 208
     BYVAL pbHotTracking AS INTEGER _                   ' __in VARIANT_BOOL pbHotTracking
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiSelect <17> ( _                    ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMultiSelect
   ' =====================================================================================
   PROPERTY SET MultiSelect <17> ( _                    ' VTable offset = 216
     BYVAL pbMultiSelect AS INTEGER _                   ' __in VARIANT_BOOL pbMultiSelect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Placement <18> ( _                      ' VTable offset = 220
   ) AS LONG                                            ' __retval_out PlacementConstants *penumPlacement
   ' =====================================================================================
   PROPERTY SET Placement <18> ( _                      ' VTable offset = 224
     BYVAL penumPlacement AS LONG _                     ' __in PlacementConstants penumPlacement
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Separators <19> ( _                     ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSeparators
   ' =====================================================================================
   PROPERTY SET Separators <19> ( _                     ' VTable offset = 232
     BYVAL pbSeparators AS INTEGER _                    ' __in VARIANT_BOOL pbSeparators
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabMinWidth <20> ( _                    ' VTable offset = 236
   ) AS SINGLE                                          ' __retval_out float *pflTabMinWidth
   ' =====================================================================================
   PROPERTY SET TabMinWidth <20> ( _                    ' VTable offset = 240
     BYVAL pflTabMinWidth AS SINGLE _                   ' __in float pflTabMinWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabStyle <21> ( _                       ' VTable offset = 244
   ) AS LONG                                            ' __retval_out TabSelStyleConstants *penumTabStyle
   ' =====================================================================================
   PROPERTY SET TabStyle <21> ( _                       ' VTable offset = 248
     BYVAL penumTabStyle AS LONG _                      ' __in TabSelStyleConstants penumTabStyle
   )                                                    ' void
   ' =====================================================================================
   METHOD DeselectAll <22> ( _                          ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_ITabStrip_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITabs
' IID = {1EFB6597-857C-11D1-B16A-00C0F0283628}
' StatusBar Tabs collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_ITabs_INTERFACE_DEFINED)
    %MSComCtl_ITabs_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_ITabs $IID_MSComCtl_ITabs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL psCount AS INTEGER _                         ' __in short psCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN pvIndex AS VARIANT _                      ' __in VARIANT *pvIndex
   ) AS MSComCtl_ITab                                   ' __retval_out ITab **ppTab
   ' =====================================================================================
   PROPERTY SET putref_ControlDefault <0> ( _           ' VTable offset = 40
     BYREF IN pvIndex AS VARIANT _                      ' __in VARIANT *pvIndex
   , BYVAL ppTab AS MSComCtl_ITab _                     ' __in ITab *ppTab
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 44
     BYREF IN pvIndex AS VARIANT _                      ' __in VARIANT *pvIndex
   ) AS MSComCtl_ITab                                   ' __retval_out ITab **ppTab
   ' =====================================================================================
   PROPERTY SET putref_Item <2> ( _                     ' VTable offset = 48
     BYREF IN pvIndex AS VARIANT _                      ' __in VARIANT *pvIndex
   , BYVAL ppTab AS MSComCtl_ITab _                     ' __in ITab *ppTab
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 52
     BYREF pvIndex AS VARIANT _                         ' __in VARIANT *pvIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <5> ( _                                   ' VTable offset = 60
     OPTIONAL BYREF pvIndex AS VARIANT _                ' __in_opt VARIANT *pvIndex
   , OPTIONAL BYREF pvKey AS VARIANT _                  ' __in_opt VARIANT *pvKey
   , OPTIONAL BYREF pvCaption AS VARIANT _              ' __in_opt VARIANT *pvCaption
   , OPTIONAL BYREF pvImage AS VARIANT _                ' __in_opt VARIANT *pvImage
   ) AS MSComCtl_ITab                                   ' __retval_out ITab **ppTab
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_ITabs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITab
' IID = {1EFB6599-857C-11D1-B16A-00C0F0283628}
' An individual object, analogous to a page, contained in a TabStrip control.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_ITab_INTERFACE_DEFINED)
    %MSComCtl_ITab_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_ITab $IID_MSComCtl_ITab

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <2> ( _                         ' VTable offset = 40
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <1> ( _                             ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <1> ( _                             ' VTable offset = 48
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <3> ( _                           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET Index <3> ( _                           ' VTable offset = 56
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <4> ( _                             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <4> ( _                             ' VTable offset = 64
     BYVAL pbstrKeys AS WSTRING _                       ' __in BSTR pbstrKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolTipText <5> ( _                     ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrToolTipText
   ' =====================================================================================
   PROPERTY SET ToolTipText <5> ( _                     ' VTable offset = 72
     BYVAL pbstrToolTipText AS WSTRING _                ' __in BSTR pbstrToolTipText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <6> ( _                           ' VTable offset = 76
   ) AS SINGLE                                          ' __retval_out float *pfWidth
   ' =====================================================================================
   PROPERTY SET Width <6> ( _                           ' VTable offset = 80
     BYVAL pfWidth AS SINGLE _                          ' __in float pfWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <7> ( _                          ' VTable offset = 84
   ) AS SINGLE                                          ' __retval_out float *pfHeight
   ' =====================================================================================
   PROPERTY SET Height <7> ( _                          ' VTable offset = 88
     BYVAL pfHeight AS SINGLE _                         ' __in float pfHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <8> ( _                             ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out float *pfTop
   ' =====================================================================================
   PROPERTY SET Top <8> ( _                             ' VTable offset = 96
     BYVAL pfTop AS SINGLE _                            ' __in float pfTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <9> ( _                            ' VTable offset = 100
   ) AS SINGLE                                          ' __retval_out float *pfLeft
   ' =====================================================================================
   PROPERTY SET Left <9> ( _                            ' VTable offset = 104
     BYVAL pfLeft AS SINGLE _                           ' __in float pfLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected <10> ( _                       ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSelected
   ' =====================================================================================
   PROPERTY SET Selected <10> ( _                       ' VTable offset = 112
     BYVAL pbSelected AS INTEGER _                      ' __in VARIANT_BOOL pbSelected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Image <11> ( _                          ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvImage
   ' =====================================================================================
   PROPERTY SET Image <11> ( _                          ' VTable offset = 120
     BYVAL pvImage AS VARIANT _                         ' __in VARIANT pvImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighLighted <12> ( _                    ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHighLighted
   ' =====================================================================================
   PROPERTY SET HighLighted <12> ( _                    ' VTable offset = 128
     BYVAL pbHighLighted AS INTEGER _                   ' __in VARIANT_BOOL pbHighLighted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <1> ( _                      ' VTable offset = 132
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_ITab_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IToolbar
' IID = {66833FE4-8583-11D1-B16A-00C0F0283628}
' Microsoft Toolbar Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IToolbar_INTERFACE_DEFINED)
    %MSComCtl_IToolbar_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IToolbar $IID_MSComCtl_IToolbar

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out AppearanceConstants *pnAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 32
     BYVAL pnAppearance AS LONG _                       ' __in AppearanceConstants pnAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowCustomize <2> ( _                  ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowCustomize
   ' =====================================================================================
   PROPERTY SET AllowCustomize <2> ( _                  ' VTable offset = 40
     BYVAL pbAllowCustomize AS INTEGER _                ' __in VARIANT_BOOL pbAllowCustomize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Buttons <3> ( _                         ' VTable offset = 44
   ) AS MSComCtl_IButtons                               ' __retval_out IButtons **ppButtons
   ' =====================================================================================
   PROPERTY SET putref_Buttons <3> ( _                  ' VTable offset = 48
     BYVAL ppButtons AS MSComCtl_IButtons _             ' __in IButtons *ppButtons
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Controls <15> ( _                       ' VTable offset = 52
   ) AS MSComCtl_IControls                              ' __retval_out IControls **ppControls
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 60
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 68
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <4> ( _                       ' VTable offset = 72
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <4> ( _                       ' VTable offset = 76
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <4> ( _                ' VTable offset = 80
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <1> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <1> ( _                    ' VTable offset = 88
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageList <5> ( _                       ' VTable offset = 92
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET ImageList <5> ( _                       ' VTable offset = 96
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ImageList <5> ( _                ' VTable offset = 100
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTips <6> ( _                        ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bShowTips
   ' =====================================================================================
   PROPERTY SET ShowTips <6> ( _                        ' VTable offset = 108
     BYVAL bShowTips AS INTEGER _                       ' __in VARIANT_BOOL bShowTips
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 112
   ) AS LONG                                            ' __retval_out BorderStyleConstants *psBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 116
     BYVAL psBorderStyle AS LONG _                      ' __in BorderStyleConstants psBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Wrappable <7> ( _                       ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbWrappable
   ' =====================================================================================
   PROPERTY SET Wrappable <7> ( _                       ' VTable offset = 124
     BYVAL pbWrappable AS INTEGER _                     ' __in VARIANT_BOOL pbWrappable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonHeight <8> ( _                    ' VTable offset = 128
   ) AS SINGLE                                          ' __retval_out float *pfButtonHeight
   ' =====================================================================================
   PROPERTY SET ButtonHeight <8> ( _                    ' VTable offset = 132
     BYVAL pfButtonHeight AS SINGLE _                   ' __in float pfButtonHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonWidth <9> ( _                     ' VTable offset = 136
   ) AS SINGLE                                          ' __retval_out float *pfButtonWidth
   ' =====================================================================================
   PROPERTY SET ButtonWidth <9> ( _                     ' VTable offset = 140
     BYVAL pfButtonWidth AS SINGLE _                    ' __in float pfButtonWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContextID <13> ( _                  ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *plHelpContextID
   ' =====================================================================================
   PROPERTY SET HelpContextID <13> ( _                  ' VTable offset = 148
     BYVAL plHelpContextID AS LONG _                    ' __in long plHelpContextID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFile <14> ( _                       ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrHelpFile
   ' =====================================================================================
   PROPERTY SET HelpFile <14> ( _                       ' VTable offset = 156
     BYVAL pbstrHelpFile AS WSTRING _                   ' __in BSTR pbstrHelpFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 160
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 164
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 168
   )                                                    ' void
   ' =====================================================================================
   METHOD Customize <10> ( _                            ' VTable offset = 172
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToolbar <11> ( _                          ' VTable offset = 176
     BYVAL Key AS WSTRING _                             ' __in BSTR Key
   , BYVAL Subkey AS WSTRING _                          ' __in BSTR Subkey
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreToolbar <12> ( _                       ' VTable offset = 180
     BYVAL Key AS WSTRING _                             ' __in BSTR Key
   , BYVAL Subkey AS WSTRING _                          ' __in BSTR Subkey
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisabledImageList <17> ( _              ' VTable offset = 192
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisabledImageList
   ' =====================================================================================
   PROPERTY SET DisabledImageList <17> ( _              ' VTable offset = 196
     BYVAL ppDisabledImageList AS IDispatch _           ' __in IDispatch *ppDisabledImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_DisabledImageList <17> ( _       ' VTable offset = 200
     BYVAL ppDisabledImageList AS IDispatch _           ' __in IDispatch *ppDisabledImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HotImageList <18> ( _                   ' VTable offset = 204
   ) AS IDispatch                                       ' __retval_out IDispatch **ppHotImageList
   ' =====================================================================================
   PROPERTY SET HotImageList <18> ( _                   ' VTable offset = 208
     BYVAL ppHotImageList AS IDispatch _                ' __in IDispatch *ppHotImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_HotImageList <18> ( _            ' VTable offset = 212
     BYVAL ppHotImageList AS IDispatch _                ' __in IDispatch *ppHotImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <16> ( _                          ' VTable offset = 216
   ) AS LONG                                            ' __retval_out ToolbarStyleConstants *penumStyle
   ' =====================================================================================
   PROPERTY SET Style <16> ( _                          ' VTable offset = 220
     BYVAL penumStyle AS LONG _                         ' __in ToolbarStyleConstants penumStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextAlignment <19> ( _                  ' VTable offset = 224
   ) AS LONG                                            ' __retval_out ToolbarTextAlignConstants *penumTextAlignment
   ' =====================================================================================
   PROPERTY SET TextAlignment <19> ( _                  ' VTable offset = 228
     BYVAL penumTextAlignment AS LONG _                 ' __in ToolbarTextAlignConstants penumTextAlignment
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IToolbar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IButtons
' IID = {66833FE7-8583-11D1-B16A-00C0F0283628}
' ToolBar Buttons
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IButtons_INTERFACE_DEFINED)
    %MSComCtl_IButtons_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IButtons $IID_MSComCtl_IButtons

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL psCount AS INTEGER _                         ' __in short psCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IButton                                ' __retval_out IButton **ppButton
   ' =====================================================================================
   PROPERTY SET putref_ControlDefault <0> ( _           ' VTable offset = 40
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppButton AS MSComCtl_IButton _               ' __in IButton *ppButton
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 44
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IButton                                ' __retval_out IButton **ppButton
   ' =====================================================================================
   PROPERTY SET putref_Item <2> ( _                     ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppButton AS MSComCtl_IButton _               ' __in IButton *ppButton
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 52
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <5> ( _                                   ' VTable offset = 60
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Caption AS VARIANT _                ' __in_opt VARIANT *Caption
   , OPTIONAL BYREF Style AS VARIANT _                  ' __in_opt VARIANT *Style
   , OPTIONAL BYREF Image AS VARIANT _                  ' __in_opt VARIANT *Image
   ) AS MSComCtl_IButton                                ' __retval_out IButton **ppButton
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispatch
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IButtons_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IButton
' IID = {66833FE9-8583-11D1-B16A-00C0F0283628}
' ToolBar Button
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IButton_INTERFACE_DEFINED)
    %MSComCtl_IButton_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IButton $IID_MSComCtl_IButton

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr_ObjectDefault
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstr_ObjectDefault AS WSTRING _             ' __in BSTR pbstr_ObjectDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <2> ( _                         ' VTable offset = 40
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <1> ( _                             ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <1> ( _                             ' VTable offset = 48
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <3> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <3> ( _                         ' VTable offset = 56
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <4> ( _                           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET Index <4> ( _                           ' VTable offset = 64
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <5> ( _                             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <5> ( _                             ' VTable offset = 72
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolTipText <6> ( _                     ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrToolTipText
   ' =====================================================================================
   PROPERTY SET ToolTipText <6> ( _                     ' VTable offset = 80
     BYVAL pbstrToolTipText AS WSTRING _                ' __in BSTR pbstrToolTipText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <7> ( _                         ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbVisible
   ' =====================================================================================
   PROPERTY SET Visible <7> ( _                         ' VTable offset = 88
     BYVAL pbVisible AS INTEGER _                       ' __in VARIANT_BOOL pbVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <8> ( _                           ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out float *pfWidth
   ' =====================================================================================
   PROPERTY SET Width <8> ( _                           ' VTable offset = 96
     BYVAL pfWidth AS SINGLE _                          ' __in float pfWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <9> ( _                          ' VTable offset = 100
   ) AS SINGLE                                          ' __retval_out float *pfHeight
   ' =====================================================================================
   PROPERTY SET Height <9> ( _                          ' VTable offset = 104
     BYVAL pfHeight AS SINGLE _                         ' __in float pfHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <10> ( _                            ' VTable offset = 108
   ) AS SINGLE                                          ' __retval_out float *pfTop
   ' =====================================================================================
   PROPERTY SET Top <10> ( _                            ' VTable offset = 112
     BYVAL pfTop AS SINGLE _                            ' __in float pfTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <11> ( _                           ' VTable offset = 116
   ) AS SINGLE                                          ' __retval_out float *pfLeft
   ' =====================================================================================
   PROPERTY SET Left <11> ( _                           ' VTable offset = 120
     BYVAL pfLeft AS SINGLE _                           ' __in float pfLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <12> ( _                          ' VTable offset = 124
   ) AS LONG                                            ' __retval_out ValueConstants *psValue
   ' =====================================================================================
   PROPERTY SET Value <12> ( _                          ' VTable offset = 128
     BYVAL psValue AS LONG _                            ' __in ValueConstants psValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <13> ( _                          ' VTable offset = 132
   ) AS LONG                                            ' __retval_out ButtonStyleConstants *psStyle
   ' =====================================================================================
   PROPERTY SET Style <13> ( _                          ' VTable offset = 136
     BYVAL psStyle AS LONG _                            ' __in ButtonStyleConstants psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <14> ( _                    ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <14> ( _                    ' VTable offset = 144
     BYVAL pbstrDescription AS WSTRING _                ' __in BSTR pbstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Image <15> ( _                          ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *pvImage
   ' =====================================================================================
   PROPERTY SET Image <15> ( _                          ' VTable offset = 152
     BYVAL pvImage AS VARIANT _                         ' __in VARIANT pvImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixedState <16> ( _                     ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMixedState
   ' =====================================================================================
   PROPERTY SET MixedState <16> ( _                     ' VTable offset = 160
     BYVAL pbMixedState AS INTEGER _                    ' __in VARIANT_BOOL pbMixedState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonMenus <17> ( _                    ' VTable offset = 164
   ) AS MSComCtl_IButtonMenus                           ' __retval_out IButtonMenus **ppButtonMenus
   ' =====================================================================================
   PROPERTY SET putref_ButtonMenus <17> ( _             ' VTable offset = 168
     BYVAL ppButtonMenus AS MSComCtl_IButtonMenus _     ' __in IButtonMenus *ppButtonMenus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <1> ( _                      ' VTable offset = 172
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IButton_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IButtonMenus
' IID = {66833FEB-8583-11D1-B16A-00C0F0283628}
' ToolBar ButtonMenus
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IButtonMenus_INTERFACE_DEFINED)
    %MSComCtl_IButtonMenus_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IButtonMenus $IID_MSComCtl_IButtonMenus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL psCount AS INTEGER _                         ' __in short psCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IButtonMenu                            ' __retval_out IButtonMenu **ppButtonMenu
   ' =====================================================================================
   PROPERTY SET putref_ControlDefault <0> ( _           ' VTable offset = 40
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppButtonMenu AS MSComCtl_IButtonMenu _       ' __in IButtonMenu *ppButtonMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 44
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IButtonMenu                            ' __retval_out IButtonMenu **ppButtonMenu
   ' =====================================================================================
   PROPERTY SET putref_Item <2> ( _                     ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppButtonMenu AS MSComCtl_IButtonMenu _       ' __in IButtonMenu *ppButtonMenu
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 52
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <5> ( _                                   ' VTable offset = 60
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   ) AS MSComCtl_IButtonMenu                            ' __retval_out IButtonMenu **ppButtonMenu
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' º__retval_out IDispatch **ppDispatch
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IButtonMenus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IButtonMenu
' IID = {66833FED-8583-11D1-B16A-00C0F0283628}
' ToolBar ButtonMenu
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IButtonMenu_INTERFACE_DEFINED)
    %MSComCtl_IButtonMenu_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IButtonMenu $IID_MSComCtl_IButtonMenu

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrObjectDefault
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstrObjectDefault AS WSTRING _              ' __in BSTR pbstrObjectDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <1> ( _                         ' VTable offset = 40
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <2> ( _                           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET Index <2> ( _                           ' VTable offset = 48
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <3> ( _                             ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <3> ( _                             ' VTable offset = 56
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <4> ( _                          ' VTable offset = 60
   ) AS MSComCtl_IButton                                ' __retval_out IButton **ppParent
   ' =====================================================================================
   PROPERTY SET putref_Parent <4> ( _                   ' VTable offset = 64
     BYVAL ppParent AS MSComCtl_IButton _               ' __in IButton *ppParent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <5> ( _                             ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <5> ( _                             ' VTable offset = 72
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <6> ( _                            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <6> ( _                            ' VTable offset = 80
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <7> ( _                         ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbVisible
   ' =====================================================================================
   PROPERTY SET Visible <7> ( _                         ' VTable offset = 88
     BYVAL pbVisible AS INTEGER _                       ' __in VARIANT_BOOL pbVisible
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IButtonMenu_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStatusBar
' IID = {8E3867A1-8586-11D1-B16A-00C0F0283628}
' Microsoft StatusBar Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IStatusBar_INTERFACE_DEFINED)
    %MSComCtl_IStatusBar_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IStatusBar $IID_MSComCtl_IStatusBar

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SimpleText <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSimpleText
   ' =====================================================================================
   PROPERTY SET SimpleText <1> ( _                      ' VTable offset = 32
     BYVAL pbstrSimpleText AS WSTRING _                 ' __in BSTR pbstrSimpleText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out SbarStyleConstants *psStyle
   ' =====================================================================================
   PROPERTY SET Style <2> ( _                           ' VTable offset = 40
     BYVAL psStyle AS LONG _                            ' __in SbarStyleConstants psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Panels <3> ( _                          ' VTable offset = 44
   ) AS MSComCtl_IPanels                                ' __retval_out IPanels **ppPanels
   ' =====================================================================================
   PROPERTY SET putref_Panels <3> ( _                   ' VTable offset = 48
     BYVAL ppPanels AS MSComCtl_IPanels _               ' __in IPanels *ppPanels
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <4> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <4> ( _                    ' VTable offset = 56
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <5> ( _                       ' VTable offset = 60
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <5> ( _                       ' VTable offset = 64
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <5> ( _                ' VTable offset = 68
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTips <7> ( _                        ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bShowTips
   ' =====================================================================================
   PROPERTY SET ShowTips <7> ( _                        ' VTable offset = 76
     BYVAL bShowTips AS INTEGER _                       ' __in VARIANT_BOOL bShowTips
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PanelProperties <6> ( _                 ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPanelProperties
   ' =====================================================================================
   PROPERTY SET PanelProperties <6> ( _                 ' VTable offset = 84
     BYVAL pbstrPanelProperties AS WSTRING _            ' __in BSTR pbstrPanelProperties
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 88
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 92
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 100
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 104
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 108
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 116
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IStatusBar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPanels
' IID = {8E3867A4-8586-11D1-B16A-00C0F0283628}
' StatusBar Panels collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IPanels_INTERFACE_DEFINED)
    %MSComCtl_IPanels_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IPanels $IID_MSComCtl_IPanels

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *sCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL sCount AS INTEGER _                          ' __in short sCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IPanel                                 ' __retval_out IPanel **ppPanel
   ' =====================================================================================
   PROPERTY SET putref_ControlDefault <0> ( _           ' VTable offset = 40
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppPanel AS MSComCtl_IPanel _                 ' __in IPanel *ppPanel
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 44
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Style AS VARIANT _                  ' __in_opt VARIANT *Style
   , OPTIONAL BYREF Picture AS VARIANT _                ' __in_opt VARIANT *Picture
   ) AS MSComCtl_IPanel                                 ' __retval_out IPanel **ppPanel
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 52
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IPanel                                 ' __retval_out IPanel **ppPanel
   ' =====================================================================================
   PROPERTY SET putref_Item <4> ( _                     ' VTable offset = 56
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppPanel AS MSComCtl_IPanel _                 ' __in IPanel *ppPanel
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 60
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IPanels_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPanel
' IID = {8E3867AA-8586-11D1-B16A-00C0F0283628}
' StatusBar Panel
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IPanel_INTERFACE_DEFINED)
    %MSComCtl_IPanel_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IPanel $IID_MSComCtl_IPanel

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Alignment <1> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out PanelAlignmentConstants *psAlignment
   ' =====================================================================================
   PROPERTY SET Alignment <1> ( _                       ' VTable offset = 40
     BYVAL psAlignment AS LONG _                        ' __in PanelAlignmentConstants psAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoSize <2> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out PanelAutoSizeConstants *psAutoSize
   ' =====================================================================================
   PROPERTY SET AutoSize <2> ( _                        ' VTable offset = 48
     BYVAL psAutoSize AS LONG _                         ' __in PanelAutoSizeConstants psAutoSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bevel <3> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out PanelBevelConstants *psBevel
   ' =====================================================================================
   PROPERTY SET Bevel <3> ( _                           ' VTable offset = 56
     BYVAL psBevel AS LONG _                            ' __in PanelBevelConstants psBevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <4> ( _                         ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <4> ( _                         ' VTable offset = 64
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <5> ( _                           ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *sIndex
   ' =====================================================================================
   PROPERTY SET Index <5> ( _                           ' VTable offset = 72
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <6> ( _                             ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <6> ( _                             ' VTable offset = 80
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <7> ( _                            ' VTable offset = 84
   ) AS SINGLE                                          ' __retval_out float *pfLeft
   ' =====================================================================================
   PROPERTY SET Left <7> ( _                            ' VTable offset = 88
     BYVAL pfLeft AS SINGLE _                           ' __in float pfLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinWidth <8> ( _                        ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out float *pfMinWidth
   ' =====================================================================================
   PROPERTY SET MinWidth <8> ( _                        ' VTable offset = 96
     BYVAL pfMinWidth AS SINGLE _                       ' __in float pfMinWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <9> ( _                         ' VTable offset = 100
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppPicture
   ' =====================================================================================
   PROPERTY SET putref_Picture <9> ( _                  ' VTable offset = 104
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp *ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <10> ( _                          ' VTable offset = 108
   ) AS LONG                                            ' __retval_out PanelStyleConstants *psStyle
   ' =====================================================================================
   PROPERTY SET Style <10> ( _                          ' VTable offset = 112
     BYVAL psStyle AS LONG _                            ' __in PanelStyleConstants psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <14> ( _                            ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <14> ( _                            ' VTable offset = 120
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <11> ( _                           ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <11> ( _                           ' VTable offset = 128
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolTipText <15> ( _                    ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrToolTipText
   ' =====================================================================================
   PROPERTY SET ToolTipText <15> ( _                    ' VTable offset = 136
     BYVAL pbstrToolTipText AS WSTRING _                ' __in BSTR pbstrToolTipText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <12> ( _                        ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbVisible
   ' =====================================================================================
   PROPERTY SET Visible <12> ( _                        ' VTable offset = 144
     BYVAL pbVisible AS INTEGER _                       ' __in VARIANT_BOOL pbVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <13> ( _                          ' VTable offset = 148
   ) AS SINGLE                                          ' __retval_out float *pfWidth
   ' =====================================================================================
   PROPERTY SET Width <13> ( _                          ' VTable offset = 152
     BYVAL pfWidth AS SINGLE _                          ' __in float pfWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Picture <9> ( _                         ' VTable offset = 156
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp *ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <14> ( _                     ' VTable offset = 160
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IPanel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProgressBar
' IID = {35053A20-8589-11D1-B16A-00C0F0283628}
' Microsoft ProgressBar Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IProgressBar_INTERFACE_DEFINED)
    %MSComCtl_IProgressBar_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IProgressBar $IID_MSComCtl_IProgressBar

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float *pfValue
   ' =====================================================================================
   PROPERTY SET ControlDefault <0> ( _                  ' VTable offset = 32
     BYVAL pfValue AS SINGLE _                          ' __in float pfValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Max <1> ( _                             ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float *pfMax
   ' =====================================================================================
   PROPERTY SET Max <1> ( _                             ' VTable offset = 40
     BYVAL pfMax AS SINGLE _                            ' __in float pfMax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Min <2> ( _                             ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float *pfMin
   ' =====================================================================================
   PROPERTY SET Min <2> ( _                             ' VTable offset = 48
     BYVAL pfMin AS SINGLE _                            ' __in float pfMin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <3> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out MousePointerConstants *pMousePointers
   ' =====================================================================================
   PROPERTY SET MousePointer <3> ( _                    ' VTable offset = 56
     BYVAL pMousePointers AS LONG _                     ' __in MousePointerConstants pMousePointers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <4> ( _                       ' VTable offset = 60
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppPictureDisp
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <4> ( _                ' VTable offset = 64
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp *ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET MouseIcon <4> ( _                       ' VTable offset = 68
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp *ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <5> ( _                           ' VTable offset = 72
   ) AS SINGLE                                          ' __retval_out float *pfValue
   ' =====================================================================================
   PROPERTY SET Value <5> ( _                           ' VTable offset = 76
     BYVAL pfValue AS SINGLE _                          ' __in float pfValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 84
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out AppearanceConstants *penumAppearances
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 92
     BYVAL penumAppearances AS LONG _                   ' __in AppearanceConstants penumAppearances
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 96
   ) AS LONG                                            ' __retval_out BorderStyleConstants AS *penumBorderStyles
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 100
     BYVAL penumBorderStyles AS LONG _                  ' __in BorderStyleConstants penumBorderStyles
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT _BOOL *bEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 108
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT bEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 116
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <6> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out OrientationConstants *penumOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <6> ( _                     ' VTable offset = 128
     BYVAL penumOrientation AS LONG _                   ' __in OrientationConstants penumOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scrolling <7> ( _                       ' VTable offset = 132
   ) AS LONG                                            ' __retval_out ScrollingConstants *penumScrolling
   ' =====================================================================================
   PROPERTY SET Scrolling <7> ( _                       ' VTable offset = 136
     BYVAL penumScrolling AS LONG _                     ' __in ScrollingConstants penumScrolling
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IProgressBar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITreeView
' IID = {C74190B4-8589-11D1-B16A-00C0F0283628}
' Displays a hierarchical list of Node objects, each of which consists of a label and an optional bitmap.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_ITreeView_INTERFACE_DEFINED)
    %MSComCtl_ITreeView_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_ITreeView $IID_MSComCtl_ITreeView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DropHighlight <1> ( _                   ' VTable offset = 28
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   PROPERTY SET putref_DropHighlight <1> ( _            ' VTable offset = 32
     BYVAL ppNode AS MSComCtl_INode _                   ' __in INode *ppNode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DropHighlight <1> ( _                   ' VTable offset = 36
     BYREF IN ppNode AS VARIANT _                       ' __in VARIANT *ppNode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HideSelection <2> ( _                   ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHideSelection
   ' =====================================================================================
   PROPERTY SET HideSelection <2> ( _                   ' VTable offset = 44
     BYVAL pbHideSelection AS INTEGER _                 ' __in VARIANT_BOOL pbHideSelection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageList <3> ( _                       ' VTable offset = 48
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET putref_ImageList <3> ( _                ' VTable offset = 52
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ImageList <3> ( _                       ' VTable offset = 56
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Indentation <4> ( _                     ' VTable offset = 60
   ) AS SINGLE                                          ' __retval_out float *pfIndentation
   ' =====================================================================================
   PROPERTY SET Indentation <4> ( _                     ' VTable offset = 64
     BYVAL pfIndentation AS SINGLE _                    ' __in float pfIndentation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LabelEdit <5> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LabelEditConstants *psLabelEdit
   ' =====================================================================================
   PROPERTY SET LabelEdit <5> ( _                       ' VTable offset = 72
     BYVAL psLabelEdit AS LONG _                        ' __in LabelEditConstants psLabelEdit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle <6> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out TreeLineStyleConstants *psLineStyle
   ' =====================================================================================
   PROPERTY SET LineStyle <6> ( _                       ' VTable offset = 80
     BYVAL psLineStyle AS LONG _                        ' __in TreeLineStyleConstants psLineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <7> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <7> ( _                    ' VTable offset = 88
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <8> ( _                       ' VTable offset = 92
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <8> ( _                       ' VTable offset = 96
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <8> ( _                ' VTable offset = 100
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Nodes <9> ( _                           ' VTable offset = 104
   ) AS MSComCtl_INodes                                 ' __retval_out INodes **ppNode
   ' =====================================================================================
   PROPERTY SET putref_Nodes <9> ( _                    ' VTable offset = 108
     BYVAL ppNode AS MSComCtl_INodes _                  ' __in INodes *ppNode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathSeparator <10> ( _                  ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathSeparator
   ' =====================================================================================
   PROPERTY SET PathSeparator <10> ( _                  ' VTable offset = 116
     BYVAL pbstrPathSeparator AS WSTRING _              ' __in BSTR pbstrPathSeparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <11> ( _                   ' VTable offset = 120
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   PROPERTY SET putref_SelectedItem <11> ( _            ' VTable offset = 124
     BYVAL ppNode AS MSComCtl_INode _                   ' __in INode *ppNode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SelectedItem <11> ( _                   ' VTable offset = 128
     BYREF IN ppNode AS VARIANT _                       ' __in VARIANT_BOOL *ppNode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sorted <12> ( _                         ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSorted
   ' =====================================================================================
   PROPERTY SET Sorted <12> ( _                         ' VTable offset = 136
     BYVAL pbSorted AS INTEGER _                        ' __in VARIANT_BOOL pbSorted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <13> ( _                          ' VTable offset = 140
   ) AS LONG                                            ' __retval_out TreeStyleConstants *psStyle
   ' =====================================================================================
   PROPERTY SET Style <13> ( _                          ' VTable offset = 144
     BYVAL psStyle AS LONG _                            ' __in TreeStyleConstants psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 148
   ) AS LONG                                            ' __retval_out OLEDragConstants *psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 152
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 156
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 160
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 164
   ) AS LONG                                            ' __retval_out AppearanceConstants *psAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 168
     BYVAL psAppearance AS LONG _                       ' __in AppearanceConstants psAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 172
   ) AS LONG                                            ' __retval_out BorderStyleConstants *psBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 176
     BYVAL psBorderStyle AS LONG _                      ' __in BorderStyleConstants psBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 180
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 184
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 188
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 192
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 196
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 200
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 204
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   METHOD HitTest <14> ( _                              ' VTable offset = 208
     BYVAL x AS SINGLE _                                ' __in float x
   , BYVAL y AS SINGLE _                                ' __in float y
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   METHOD GetVisibleCount <15> ( _                      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out long *plVisibleCount
   ' =====================================================================================
   METHOD StartLabelEdit <16> ( _                       ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 224
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 228
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Checkboxes <17> ( _                     ' VTable offset = 232
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbCheckboxes
   ' =====================================================================================
   PROPERTY SET Checkboxes <17> ( _                     ' VTable offset = 236
     BYVAL pbCheckboxes AS INTEGER _                    ' __in VARIANT_BOOL pbCheckboxes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullRowSelect <18> ( _                  ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbFullRowSelect
   ' =====================================================================================
   PROPERTY SET FullRowSelect <18> ( _                  ' VTable offset = 244
     BYVAL pbFullRowSelect AS INTEGER _                 ' __in VARIANT_BOOL pbFullRowSelect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HotTracking <19> ( _                    ' VTable offset = 248
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHotTracking
   ' =====================================================================================
   PROPERTY SET HotTracking <19> ( _                    ' VTable offset = 252
     BYVAL pbHotTracking AS INTEGER _                   ' __in VARIANT_BOOL pbHotTracking
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scroll <20> ( _                         ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbScroll
   ' =====================================================================================
   PROPERTY SET Scroll <20> ( _                         ' VTable offset = 260
     BYVAL pbScroll AS INTEGER _                        ' __in VARIANT_BOOL pbScroll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SingleSel <21> ( _                      ' VTable offset = 264
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSingleSel
   ' =====================================================================================
   PROPERTY SET SingleSel <21> ( _                      ' VTable offset = 268
     BYVAL pbSingleSel AS INTEGER _                     ' __in VARIANT_BOOL pbSingleSel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_ITreeView_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INodes
' IID = {C74190B7-8589-11D1-B16A-00C0F0283628}
' Treeview Nodes collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_INodes_INTERFACE_DEFINED)
    %MSComCtl_INodes_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_INodes $IID_MSComCtl_INodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL psCount AS INTEGER _                         ' __in short psCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   PROPERTY SET ControlDefault <0> ( _                  ' VTable offset = 40
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppNode AS MSComCtl_INode _                   ' __in INode *ppNode
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 44
     OPTIONAL BYREF Relative AS VARIANT _               ' __in_opt VARIANT *Relative
   , OPTIONAL BYREF Relationship AS VARIANT _           ' __in_opt VARIANT *Relationship
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Image AS VARIANT _                  ' __in_opt VARIANT *Image
   , OPTIONAL BYREF SelectedImage AS VARIANT _          ' __in_opt VARIANT *SelectedImage
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 52
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNode
   ' =====================================================================================
   PROPERTY SET Item <4> ( _                            ' VTable offset = 56
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppNode AS MSComCtl_INode _                   ' __in INode *ppNode
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 60
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_INodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INode
' IID = {C74190B8-8589-11D1-B16A-00C0F0283628}
' An object in a TreeView control that can contain images and text.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_INode_INTERFACE_DEFINED)
    %MSComCtl_INode_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_INode $IID_MSComCtl_INode

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Child <1> ( _                           ' VTable offset = 36
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppChild
   ' =====================================================================================
   PROPERTY SET putref_Child <1> ( _                    ' VTable offset = 40
     BYVAL ppChild AS MSComCtl_INode _                  ' __in INode *ppChild
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Children <2> ( _                        ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *psChildren
   ' =====================================================================================
   PROPERTY SET Children <2> ( _                        ' VTable offset = 48
     BYVAL psChildren AS INTEGER _                      ' __in short psChildren
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Expanded <3> ( _                        ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExpanded
   ' =====================================================================================
   PROPERTY SET Expanded <3> ( _                        ' VTable offset = 56
     BYVAL pbExpanded AS INTEGER _                      ' __in VARIANT_BOOL pbExpanded
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExpandedImage <4> ( _                   ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pExpandedImage
   ' =====================================================================================
   PROPERTY SET ExpandedImage <4> ( _                   ' VTable offset = 64
     BYVAL pExpandedImage AS VARIANT _                  ' __in VARIANT pExpandedImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstSibling <5> ( _                    ' VTable offset = 68
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppFirstSibling
   ' =====================================================================================
   PROPERTY SET putref_FirstSibling <5> ( _             ' VTable offset = 72
     BYVAL ppFirstSibling AS MSComCtl_INode _           ' __in INode *ppFirstSibling
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullPath <6> ( _                        ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFullPath
   ' =====================================================================================
   PROPERTY SET FullPath <6> ( _                        ' VTable offset = 80
     BYVAL pbstrFullPath AS WSTRING _                   ' __in BSTR pbstrFullPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Image <7> ( _                           ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pImage
   ' =====================================================================================
   PROPERTY SET Image <7> ( _                           ' VTable offset = 88
     BYVAL pImage AS VARIANT _                          ' __in VARIANT pImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <8> ( _                           ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET Index <8> ( _                           ' VTable offset = 96
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <9> ( _                             ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <9> ( _                             ' VTable offset = 104
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastSibling <10> ( _                    ' VTable offset = 108
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppLastSibling
   ' =====================================================================================
   PROPERTY SET putref_LastSibling <10> ( _             ' VTable offset = 112
     BYVAL ppLastSibling AS MSComCtl_INode _            ' __in INode *ppLastSibling
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Next <11> ( _                           ' VTable offset = 116
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppNext
   ' =====================================================================================
   PROPERTY SET putref_Next <11> ( _                    ' VTable offset = 120
     BYVAL ppNext AS MSComCtl_INode _                   ' __in INode *ppNext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <12> ( _                         ' VTable offset = 124
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppParent
   ' =====================================================================================
   PROPERTY SET putref_Parent <12> ( _                  ' VTable offset = 128
     BYVAL ppParent AS MSComCtl_INode _                 ' __in INode *ppParent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Previous <13> ( _                       ' VTable offset = 132
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppPrevious
   ' =====================================================================================
   PROPERTY SET putref_Previous <13> ( _                ' VTable offset = 136
     BYVAL ppPrevious AS MSComCtl_INode _               ' __in INode *ppPrevious
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Root <14> ( _                           ' VTable offset = 140
   ) AS MSComCtl_INode                                  ' __retval_out INode **ppRoot
   ' =====================================================================================
   PROPERTY SET putref_Root <14> ( _                    ' VTable offset = 144
     BYVAL ppRoot AS MSComCtl_INode _                   ' __in INode *ppRoot
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected <15> ( _                       ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSelected
   ' =====================================================================================
   PROPERTY SET Selected <15> ( _                       ' VTable offset = 152
     BYVAL pbSelected AS INTEGER _                      ' __in VARIANT_BOOL pbSelected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedImage <16> ( _                  ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pSelectedImage
   ' =====================================================================================
   PROPERTY SET SelectedImage <16> ( _                  ' VTable offset = 160
     BYVAL pSelectedImage AS VARIANT _                  ' __in VARIANT pSelectedImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sorted <17> ( _                         ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSorted
   ' =====================================================================================
   PROPERTY SET Sorted <17> ( _                         ' VTable offset = 168
     BYVAL pbSorted AS INTEGER _                        ' __in VARIANT_BOOL pbSorted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <18> ( _                            ' VTable offset = 172
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <18> ( _                            ' VTable offset = 176
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <19> ( _                           ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *bstrText
   ' =====================================================================================
   PROPERTY SET Text <19> ( _                           ' VTable offset = 184
     BYVAL bstrText AS WSTRING _                        ' __in BSTR bstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <20> ( _                        ' VTable offset = 188
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbVisible
   ' =====================================================================================
   PROPERTY SET Visible <20> ( _                        ' VTable offset = 192
     BYVAL pbVisible AS INTEGER _                       ' __in VARIANT_BOOL pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDragImage <21> ( _                      ' VTable offset = 196
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppDragImage
   ' =====================================================================================
   METHOD EnsureVisible <22> ( _                        ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnsureVisible
   ' =====================================================================================
   PROPERTY GET BackColor <23> ( _                      ' VTable offset = 204
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <23> ( _                      ' VTable offset = 208
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bold <24> ( _                           ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBold
   ' =====================================================================================
   PROPERTY SET Bold <24> ( _                           ' VTable offset = 216
     BYVAL pbBold AS INTEGER _                          ' __in VARIANT_BOOL pbBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Checked <25> ( _                        ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbChecked
   ' =====================================================================================
   PROPERTY SET Checked <25> ( _                        ' VTable offset = 224
     BYVAL pbChecked AS INTEGER _                       ' __in VARIANT_BOOL pbChecked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <26> ( _                      ' VTable offset = 228
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <26> ( _                      ' VTable offset = 232
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <18> ( _                     ' VTable offset = 236
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_INode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IListView
' IID = {BDD1F049-858B-11D1-B16A-00C0F0283628}
' Displays a collection of ListItems such as files or folders.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IListView_INTERFACE_DEFINED)
    %MSComCtl_IListView_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IListView $IID_MSComCtl_IListView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Arrange <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out ListArrangeConstants *pArrange
   ' =====================================================================================
   PROPERTY SET Arrange <1> ( _                         ' VTable offset = 32
     BYVAL pArrange AS LONG _                           ' __in ListArrangeConstants pArrange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnHeaders <2> ( _                   ' VTable offset = 36
   ) AS MSComCtl_IColumnHeaders                         ' __retval_out IColumnHeaders **ppIColumnHeaders
   ' =====================================================================================
   PROPERTY SET ColumnHeaders <2> ( _                   ' VTable offset = 40
     BYVAL ppIColumnHeaders AS MSComCtl_IColumnHeaders _ ' __in IColumnHeaders *ppIColumnHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DropHighlight <3> ( _                   ' VTable offset = 44
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   PROPERTY SET putref_DropHighlight <3> ( _            ' VTable offset = 48
     BYVAL ppIListItem AS MSComCtl_IListItem _          ' __in IListItem *ppIListItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DropHighlight <3> ( _                   ' VTable offset = 52
     BYREF IN ppIListItem AS VARIANT _                  ' __in VARIANT *ppIListItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HideColumnHeaders <4> ( _               ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHide
   ' =====================================================================================
   PROPERTY SET HideColumnHeaders <4> ( _               ' VTable offset = 60
     BYVAL pfHide AS INTEGER _                          ' __in VARIANT_BOOL pfHide
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HideSelection <5> ( _                   ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHide
   ' =====================================================================================
   PROPERTY SET HideSelection <5> ( _                   ' VTable offset = 68
     BYVAL pfHide AS INTEGER _                          ' __in VARIANT_BOOL pfHide
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Icons <6> ( _                           ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppIcons
   ' =====================================================================================
   PROPERTY SET putref_Icons <6> ( _                    ' VTable offset = 76
     BYVAL ppIcons AS IDispatch _                       ' __in IDispatch *ppIcons
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Icons <6> ( _                           ' VTable offset = 80
     BYVAL ppIcons AS IDispatch _                       ' __in IDispatch *ppIcons
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListItems <7> ( _                       ' VTable offset = 84
   ) AS MSComCtl_IListItems                             ' __retval_out IListItems **ppListItems
   ' =====================================================================================
   PROPERTY SET ListItems <7> ( _                       ' VTable offset = 88
     BYVAL ppListItems AS MSComCtl_IListItems _         ' __in IListItems *ppListItems
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LabelEdit <8> ( _                       ' VTable offset = 92
   ) AS LONG                                            ' __retval_out ListLabelEditConstants *pRet
   ' =====================================================================================
   PROPERTY SET LabelEdit <8> ( _                       ' VTable offset = 96
     BYVAL pRet AS LONG _                               ' __in ListLabelEditConstants pRet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LabelWrap <9> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfOn
   ' =====================================================================================
   PROPERTY SET LabelWrap <9> ( _                       ' VTable offset = 104
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <10> ( _                      ' VTable offset = 108
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <10> ( _                      ' VTable offset = 112
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <10> ( _               ' VTable offset = 116
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <11> ( _                   ' VTable offset = 120
   ) AS LONG                                            ' __retval_out MousePointerConstants *pnIndex
   ' =====================================================================================
   PROPERTY SET MousePointer <11> ( _                   ' VTable offset = 124
     BYVAL pnIndex AS LONG _                            ' __in MousePointerConstants pnIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiSelect <12> ( _                    ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfOn
   ' =====================================================================================
   PROPERTY SET MultiSelect <12> ( _                    ' VTable offset = 132
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <13> ( _                   ' VTable offset = 136
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppListItem
   ' =====================================================================================
   PROPERTY SET putref_SelectedItem <13> ( _            ' VTable offset = 140
     BYVAL ppListItem AS MSComCtl_IListItem _           ' __in IListItem *ppListItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SelectedItem <13> ( _                   ' VTable offset = 144
     BYREF IN ppListItem AS VARIANT _                   ' __in VARIANT *ppListItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmallIcons <14> ( _                     ' VTable offset = 148
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET putref_SmallIcons <14> ( _              ' VTable offset = 152
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SmallIcons <14> ( _                     ' VTable offset = 156
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sorted <15> ( _                         ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfOn
   ' =====================================================================================
   PROPERTY SET Sorted <15> ( _                         ' VTable offset = 164
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortKey <16> ( _                        ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out short *psKey
   ' =====================================================================================
   PROPERTY SET SortKey <16> ( _                        ' VTable offset = 172
     BYVAL psKey AS INTEGER _                           ' __in short psKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortOrder <17> ( _                      ' VTable offset = 176
   ) AS LONG                                            ' __retval_out ListSortOrderConstants *pOrder
   ' =====================================================================================
   PROPERTY SET SortOrder <17> ( _                      ' VTable offset = 180
     BYVAL pOrder AS LONG _                             ' __in ListSortOrderConstants pOrder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET View <18> ( _                           ' VTable offset = 184
   ) AS LONG                                            ' __retval_out ListViewConstants *pnView
   ' =====================================================================================
   PROPERTY SET View <18> ( _                           ' VTable offset = 188
     BYVAL pnView AS LONG _                             ' __in ListViewConstants pnView
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 192
   ) AS LONG                                            ' __retval_out OLEDragConstants *psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 196
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 204
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out AppearanceConstants *pnAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 212
     BYVAL pnAppearance AS LONG _                       ' __in AppearanceConstants pnAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 216
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pcrBack
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 220
     BYVAL pcrBack AS DWORD _                           ' __in OLE_COLOR pcrBack
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 224
   ) AS LONG                                            ' __retval_out BorderStyleConstants *pnStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 228
     BYVAL pnStyle AS LONG _                            ' __in BorderStyleConstants pnStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 232
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 236
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL AS pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 240
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFontDisp
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 244
     BYVAL ppFontDisp AS IFontDisp _                    ' __in IFontDisp *ppFontDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 248
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pcrFore
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 252
     BYVAL pcrFore AS DWORD _                           ' __in OLE_COLOR pcrFore
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 256
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 260
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   METHOD FindItem <19> ( _                             ' VTable offset = 264
     BYVAL sz AS WSTRING _                              ' __in BSTR sz
   , OPTIONAL BYREF Where AS VARIANT _                  ' __in_opt VARIANT *Where
   , OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF fPartial AS VARIANT _               ' __in_opt VARIANT *fPartial
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   METHOD GetFirstVisible <20> ( _                      ' VTable offset = 268
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   METHOD HitTest <21> ( _                              ' VTable offset = 272
     BYVAL x AS SINGLE _                                ' __in float x
   , BYVAL y AS SINGLE _                                ' __in float y
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppListItem
   ' =====================================================================================
   METHOD StartLabelEdit <22> ( _                       ' VTable offset = 276
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 284
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 288
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowColumnReorder <23> ( _             ' VTable offset = 292
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowColumnReorder
   ' =====================================================================================
   PROPERTY SET AllowColumnReorder <23> ( _             ' VTable offset = 296
     BYVAL pfAllowColumnReorder AS INTEGER _            ' __in VARIANT_BOOL pfAllowColumnReorder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Checkboxes <24> ( _                     ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCheckboxes
   ' =====================================================================================
   PROPERTY SET Checkboxes <24> ( _                     ' VTable offset = 304
     BYVAL pfCheckboxes AS INTEGER _                    ' __in VARIANT_BOOL pfCheckboxes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FlatScrollBar <25> ( _                  ' VTable offset = 308
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfFlatScrollBar
   ' =====================================================================================
   PROPERTY SET FlatScrollBar <25> ( _                  ' VTable offset = 312
     BYVAL pfFlatScrollBar AS INTEGER _                 ' __in VARIANT_BOOL pfFlatScrollBar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullRowSelect <26> ( _                  ' VTable offset = 316
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfFullRowSelect
   ' =====================================================================================
   PROPERTY SET FullRowSelect <26> ( _                  ' VTable offset = 320
     BYVAL pfFullRowSelect AS INTEGER _                 ' __in VARIANT_BOOL pfFullRowSelect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GridLines <27> ( _                      ' VTable offset = 324
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfGridLines
   ' =====================================================================================
   PROPERTY SET GridLines <27> ( _                      ' VTable offset = 328
     BYVAL pfGridLines AS INTEGER _                     ' __in VARIANT_BOOL pfGridLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HotTracking <28> ( _                    ' VTable offset = 332
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHotTracking
   ' =====================================================================================
   PROPERTY SET HotTracking <28> ( _                    ' VTable offset = 336
     BYVAL pfHotTracking AS INTEGER _                   ' __in VARIANT_BOOL pfHotTracking
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HoverSelection <29> ( _                 ' VTable offset = 340
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHoverSelection
   ' =====================================================================================
   PROPERTY SET HoverSelection <29> ( _                 ' VTable offset = 344
     BYVAL pfHoverSelection AS INTEGER _                ' __in VARIANT_BOOL pfHoverSelection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <31> ( _                        ' VTable offset = 348
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppPictureDisp
   ' =====================================================================================
   PROPERTY SET Picture <31> ( _                        ' VTable offset = 352
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp *ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Picture <31> ( _                 ' VTable offset = 356
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp *ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PictureAlignment <30> ( _               ' VTable offset = 360
   ) AS LONG                                            ' __retval_out ListPictureAlignmentConstants *psAlignment
   ' =====================================================================================
   PROPERTY SET PictureAlignment <30> ( _               ' VTable offset = 364
     BYVAL psAlignment AS LONG _                        ' __in ListPictureAlignmentConstants psAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnHeaderIcons <32> ( _              ' VTable offset = 368
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET putref_ColumnHeaderIcons <32> ( _       ' VTable offset = 372
     BYVAL ppImageList AS IDispatch _                   ' __inIDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ColumnHeaderIcons <32> ( _              ' VTable offset = 376
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextBackground <33> ( _                 ' VTable offset = 380
   ) AS LONG                                            ' __retval_out ListTextBackgroundConstants *penumTextBackground
   ' =====================================================================================
   PROPERTY SET TextBackground <33> ( _                 ' VTable offset = 384
     BYVAL penumTextBackground AS LONG _                ' __in ListTextBackgroundConstants penumTextBackground
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IListView_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IListItems
' IID = {BDD1F04C-858B-11D1-B16A-00C0F0283628}
' ListView Item collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IListItems_INTERFACE_DEFINED)
    %MSComCtl_IListItems_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IListItems $IID_MSComCtl_IListItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN VARIANT _                                 ' __in VARIANT *Index
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Icon AS VARIANT _                   ' __in_opt VARIANT *Icon
   , OPTIONAL BYREF SmallIcon AS VARIANT _              ' __in_opt VARIANT *SmallIcon
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IListItem                              ' __retval_out IListItem **ppIListItem
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 52
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IListItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IListItem
' IID = {BDD1F04E-858B-11D1-B16A-00C0F0283628}
' An item in a ListView control that contains the index of icons associated with it, text, and an array of strings representing subitems that are displayed in Report view.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IListItem_INTERFACE_DEFINED)
    %MSComCtl_IListItem_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IListItem $IID_MSComCtl_IListItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Default <0> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Default <0> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <10> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <10> ( _                           ' VTable offset = 40
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ghosted <1> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfOn
   ' =====================================================================================
   PROPERTY SET Ghosted <1> ( _                         ' VTable offset = 48
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <2> ( _                          ' VTable offset = 52
   ) AS SINGLE                                          ' __retval_out float *pflHeight
   ' =====================================================================================
   PROPERTY SET Height <2> ( _                          ' VTable offset = 56
     BYVAL pflHeight AS SINGLE _                        ' __in float pflHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Icon <3> ( _                            ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pnIndex
   ' =====================================================================================
   PROPERTY SET Icon <3> ( _                            ' VTable offset = 64
     BYVAL pnIndex AS VARIANT _                         ' __in VARIANT pnIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <4> ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   PROPERTY SET Index <4> ( _                           ' VTable offset = 72
     BYVAL plIndex AS LONG _                            ' __in long plIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <5> ( _                             ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <5> ( _                             ' VTable offset = 80
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <6> ( _                            ' VTable offset = 84
   ) AS SINGLE                                          ' __retval_out float *pflLeft
   ' =====================================================================================
   PROPERTY SET Left <6> ( _                            ' VTable offset = 88
     BYVAL pflLeft AS SINGLE _                          ' __in float pflLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected <7> ( _                        ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfOn
   ' =====================================================================================
   PROPERTY SET Selected <7> ( _                        ' VTable offset = 96
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmallIcon <8> ( _                       ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pnIndex
   ' =====================================================================================
   PROPERTY SET SmallIcon <8> ( _                       ' VTable offset = 104
     BYVAL pnIndex AS VARIANT _                         ' __in VARIANT pnIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <9> ( _                             ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <9> ( _                             ' VTable offset = 112
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <11> ( _                            ' VTable offset = 116
   ) AS SINGLE                                          ' __retval_out float *pflTop
   ' =====================================================================================
   PROPERTY SET Top <11> ( _                            ' VTable offset = 120
     BYVAL pflTop AS SINGLE _                           ' __in float pflTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <12> ( _                          ' VTable offset = 124
   ) AS SINGLE                                          ' __retval_out float *pflWidth
   ' =====================================================================================
   PROPERTY SET Width <12> ( _                          ' VTable offset = 128
     BYVAL pflWidth AS SINGLE _                         ' __in float pflWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubItems <13> ( _                       ' VTable offset = 132
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrItem
   ' =====================================================================================
   PROPERTY SET SubItems <13> ( _                       ' VTable offset = 136
     BYVAL Index AS INTEGER _                           ' __in short Index
   , BYVAL pbstrItem AS WSTRING _                       ' __in BSTR pbstrItem
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDragImage <14> ( _                      ' VTable offset = 140
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppImage
   ' =====================================================================================
   METHOD EnsureVisible <15> ( _                        ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfVisible
   ' =====================================================================================
   PROPERTY SET putref_Tag <9> ( _                      ' VTable offset = 148
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListSubItems <16> ( _                   ' VTable offset = 152
   ) AS MSComCtl_IListSubItems                          ' __retval_out IListSubItems **ppSubItems
   ' =====================================================================================
   PROPERTY SET ListSubItems <16> ( _                   ' VTable offset = 156
     BYVAL ppSubItems AS MSComCtl_IListSubItems _       ' __in IListSubItems *ppSubItems
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Checked <17> ( _                        ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfChecked
   ' =====================================================================================
   PROPERTY SET Checked <17> ( _                        ' VTable offset = 164
     BYVAL pfChecked AS INTEGER _                       ' __in VARIANT_BOOL pfChecked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 168
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pcrFore
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 172
     BYVAL pcrFore AS DWORD _                           ' __in OLE_COLOR pcrFore
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolTipText <18> ( _                    ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrToolTipText
   ' =====================================================================================
   PROPERTY SET ToolTipText <18> ( _                    ' VTable offset = 180
     BYVAL pbstrToolTipText AS WSTRING _                ' __in BSTR pbstrToolTipText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bold <19> ( _                           ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfBold
   ' =====================================================================================
   PROPERTY SET Bold <19> ( _                           ' VTable offset = 188
     BYVAL pfBold AS INTEGER _                          ' __in VARIANT_BOOL pfBold
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IListItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IColumnHeaders
' IID = {BDD1F050-858B-11D1-B16A-00C0F0283628}
' ListView Column Header collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IColumnHeaders_INTERFACE_DEFINED)
    %MSComCtl_IColumnHeaders_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IColumnHeaders $IID_MSComCtl_IColumnHeaders

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IColumnHeader                          ' __retval_out IColumnHeader **ppIColumnHeader
   ' =====================================================================================
   METHOD Add_PreVB98 <2> ( _                           ' VTable offset = 40
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Width AS VARIANT _                  ' __in_opt VARIANT *Width
   , OPTIONAL BYREF Alignment AS VARIANT _              ' __in_opt VARIANT *Alignment
   ) AS MSComCtl_IColumnHeader                          ' __retval_out IColumnHeader **ppIColumnHeader
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IColumnHeader                          ' __retval_out IColumnHeader **ppIColumnHeader
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 52
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnknown
   ' =====================================================================================
   METHOD Add <6> ( _                                   ' VTable offset = 60
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Width AS VARIANT _                  ' __in_opt VARIANT *Width
   , OPTIONAL BYREF Alignment AS VARIANT _              ' __in_opt VARIANT *Alignment
   , OPTIONAL BYREF Icon AS VARIANT _                   ' __in_opt VARIANT *Icon
   ) AS MSComCtl_IColumnHeader                          ' __retval_out IColumnHeader **ppIColumnHeader
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IColumnHeaders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IColumnHeader
' IID = {BDD1F051-858B-11D1-B16A-00C0F0283628}
' ListView Column Header
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IColumnHeader_INTERFACE_DEFINED)
    %MSComCtl_IColumnHeader_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IColumnHeader $IID_MSComCtl_IColumnHeader

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Default <0> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Default <0> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <7> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <7> ( _                            ' VTable offset = 40
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Alignment <1> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out ListColumnAlignmentConstants *pnAlignment
   ' =====================================================================================
   PROPERTY SET Alignment <1> ( _                       ' VTable offset = 48
     BYVAL pnAlignment AS LONG _                        ' __in ListColumnAlignmentConstants pnAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <2> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   PROPERTY SET Index <2> ( _                           ' VTable offset = 56
     BYVAL plIndex AS LONG _                            ' __in long plIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <3> ( _                             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <3> ( _                             ' VTable offset = 64
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <4> ( _                            ' VTable offset = 68
   ) AS SINGLE                                          ' __retval_out float *pflLeft
   ' =====================================================================================
   PROPERTY SET Left <4> ( _                            ' VTable offset = 72
     BYVAL pflLeft AS SINGLE _                          ' __in float pflLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubItemIndex <5> ( _                    ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET SubItemIndex <5> ( _                    ' VTable offset = 80
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <6> ( _                             ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <6> ( _                             ' VTable offset = 88
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <8> ( _                           ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out float *pflWidth
   ' =====================================================================================
   PROPERTY SET Width <8> ( _                           ' VTable offset = 96
     BYVAL pflWidth AS SINGLE _                         ' __in float pflWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <6> ( _                      ' VTable offset = 100
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Icon <9> ( _                            ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pnIndex
   ' =====================================================================================
   PROPERTY SET Icon <9> ( _                            ' VTable offset = 108
     BYVAL pnIndex AS VARIANT _                         ' __in VARIANT pnIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Position <10> ( _                       ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out short *piPosition
   ' =====================================================================================
   PROPERTY SET Position <10> ( _                       ' VTable offset = 116
     BYVAL piPosition AS INTEGER _                      ' __in short piPosition
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IColumnHeader_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IListSubItems
' IID = {BDD1F053-858B-11D1-B16A-00C0F0283628}
' ListView SubItem object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IListSubItems_INTERFACE_DEFINED)
    %MSComCtl_IListSubItems_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IListSubItems $IID_MSComCtl_IListSubItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IListSubItem                           ' __retval_out IListSubItem **ppIListSubItem
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF ReportIcon AS VARIANT _             ' __in_opt VARIANT *ReportIcon
   , OPTIONAL BYREF ToolTipText AS VARIANT _            ' __in_opt VARIANT *ToolTipText
   ) AS MSComCtl_IListSubItem                           ' __retval_out IListSubItem **ppIListSubItem
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IListSubItem                           ' __retval_out IListSubItem **ppIListSubItem
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 52
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IListSubItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IListSubItem
' IID = {BDD1F055-858B-11D1-B16A-00C0F0283628}
' ListView SubItem object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IListSubItem_INTERFACE_DEFINED)
    %MSComCtl_IListSubItem_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IListSubItem $IID_MSComCtl_IListSubItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Default <0> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Default <0> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <1> ( _                            ' VTable offset = 40
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pcrFore
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 48
     BYVAL pcrFore AS DWORD _                           ' __in OLE_COLOR pcrFore
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bold <2> ( _                            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfBold
   ' =====================================================================================
   PROPERTY SET Bold <2> ( _                            ' VTable offset = 56
     BYVAL pfBold AS INTEGER _                          ' __in VARIANT_BOOL pfBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReportIcon <4> ( _                      ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pnIndex
   ' =====================================================================================
   PROPERTY SET ReportIcon <4> ( _                      ' VTable offset = 64
     BYVAL pnIndex AS VARIANT _                         ' __in VARIANT pnIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolTipText <5> ( _                     ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrToolTipText
   ' =====================================================================================
   PROPERTY SET ToolTipText <5> ( _                     ' VTable offset = 72
     BYVAL pbstrToolTipText AS WSTRING _                ' __in BSTR pbstrToolTipText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <6> ( _                           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   PROPERTY SET Index <6> ( _                           ' VTable offset = 80
     BYVAL plIndex AS LONG _                            ' __in long plIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <7> ( _                             ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <7> ( _                             ' VTable offset = 88
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <8> ( _                             ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <8> ( _                             ' VTable offset = 96
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <8> ( _                      ' VTable offset = 100
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IListSubItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImageList
' IID = {2C247F21-8591-11D1-B16A-00C0F0283628}
' Contains a collection of ListImage objects, each of which can be referred to by its index or key
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IImageList_INTERFACE_DEFINED)
    %MSComCtl_IImageList_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IImageList $IID_MSComCtl_IImageList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ImageHeight <1> ( _                     ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psImageHeight
   ' =====================================================================================
   PROPERTY SET ImageHeight <1> ( _                     ' VTable offset = 32
     BYVAL psImageHeight AS INTEGER _                   ' __in short psImageHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageWidth <2> ( _                      ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short *psImageWidth
   ' =====================================================================================
   PROPERTY SET ImageWidth <2> ( _                      ' VTable offset = 40
     BYVAL psImageWidth AS INTEGER _                    ' __in short psImageWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaskColor <3> ( _                       ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrMaskColor
   ' =====================================================================================
   PROPERTY SET MaskColor <3> ( _                       ' VTable offset = 48
     BYVAL pclrMaskColor AS DWORD _                     ' __in OLE_COLOR pclrMaskColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseMaskColor <7> ( _                    ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET UseMaskColor <7> ( _                    ' VTable offset = 56
     BYVAL pbState AS INTEGER _                         ' __in VARIANT_BOOL pbState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListImages <4> ( _                      ' VTable offset = 60
   ) AS MSComCtl_IImages                                ' __retval_out IImages **ppListImages
   ' =====================================================================================
   PROPERTY SET putref_ListImages <4> ( _               ' VTable offset = 64
     BYVAL ppListImages AS MSComCtl_IImages _           ' __in IImages *ppListImages
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hImageList <5> ( _                      ' VTable offset = 68
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phImageList
   ' =====================================================================================
   PROPERTY SET hImageList <5> ( _                      ' VTable offset = 72
     BYVAL phImageList AS LONG _                        ' __in OLE_HANDLE phImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 80
     BYVAL pclrBackColor AS DWORD _                     ' __in OLE_COLOR pclrBackColor
   )                                                    ' void
   ' =====================================================================================
   METHOD Overlay <6> ( _                               ' VTable offset = 84
     BYREF Key1 AS VARIANT _                            ' __in VARIANT *Key1
   , BYREF Key2 AS VARIANT _                            ' __in VARIANT *Key2
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppPictureDisp
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IImageList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImages
' IID = {2C247F24-8591-11D1-B16A-00C0F0283628}
' A bitmap or icon of any size that can be used in other controls.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IImages_INTERFACE_DEFINED)
    %MSComCtl_IImages_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IImages $IID_MSComCtl_IImages

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psCount
   ' =====================================================================================
   PROPERTY SET Count <1> ( _                           ' VTable offset = 32
     BYVAL psCount AS INTEGER _                         ' __in short psCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlDefault <0> ( _                  ' VTable offset = 36
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IImage                                 ' __retval_out IImage **ppListImage
   ' =====================================================================================
   PROPERTY SET putref_ControlDefault <0> ( _           ' VTable offset = 40
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppListImage AS MSComCtl_IImage _             ' __in IImage *ppListImage
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 44
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Picture AS VARIANT _                ' __in_opt VARIANT *Picture
   ) AS MSComCtl_IImage                                 ' __retval_out IImage **ppListImage
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <4> ( _                            ' VTable offset = 52
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IImage                                 ' __retval_out IImage **Item
   ' =====================================================================================
   PROPERTY SET putref_Item <4> ( _                     ' VTable offset = 56
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL Item AS MSComCtl_IImage _                    ' __in IImage *Item
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 60
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IImages_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImage
' IID = {2C247F26-8591-11D1-B16A-00C0F0283628}
' A bitmap or icon of any size that can be used in other controls.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IImage_INTERFACE_DEFINED)
    %MSComCtl_IImage_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IImage $IID_MSComCtl_IImage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Index <1> ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *psIndex
   ' =====================================================================================
   PROPERTY SET Index <1> ( _                           ' VTable offset = 32
     BYVAL psIndex AS INTEGER _                         ' __in short psIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <2> ( _                             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <2> ( _                             ' VTable offset = 40
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <6> ( _                             ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <6> ( _                             ' VTable offset = 48
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <3> ( _                         ' VTable offset = 52
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppPictureDisp
   ' =====================================================================================
   PROPERTY SET putref_Picture <3> ( _                  ' VTable offset = 56
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp *ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   METHOD Draw <4> ( _                                  ' VTable offset = 60
     BYVAL hDC AS LONG _                                ' __in OLE_HANDLE hDC
   , OPTIONAL BYREF x AS VARIANT _                      ' __in_opt VARIANT *x
   , OPTIONAL BYREF y AS VARIANT _                      ' __in_opt VARIANT *y
   , OPTIONAL BYREF Style AS VARIANT _                  ' __in_opt VARIANT *Style
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractIcon <5> ( _                           ' VTable offset = 64
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppIconDisp
   ' =====================================================================================
   PROPERTY SET putref_Tag <6> ( _                      ' VTable offset = 68
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT pvTag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IImage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISlider
' IID = {F08DF952-8592-11D1-B16A-00C0F0283628}
' A calibrated control with a slider for setting or selecting values.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_ISlider_INTERFACE_DEFINED)
    %MSComCtl_ISlider_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_ISlider $IID_MSComCtl_ISlider

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value_ <0> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY SET Value_ <0> ( _                          ' VTable offset = 32
     BYVAL plValue AS LONG _                            ' __in long plValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LargeChange <1> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plLargeChange
   ' =====================================================================================
   PROPERTY SET LargeChange <1> ( _                     ' VTable offset = 40
     BYVAL plLargeChange AS LONG _                      ' __in long plLargeChange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmallChange <2> ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plSmallChange
   ' =====================================================================================
   PROPERTY SET SmallChange <2> ( _                     ' VTable offset = 48
     BYVAL plSmallChange AS LONG _                      ' __in long plSmallChange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Max <3> ( _                             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plMax
   ' =====================================================================================
   PROPERTY SET Max <3> ( _                             ' VTable offset = 56
     BYVAL plMax AS LONG _                              ' __in long plMax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Min <4> ( _                             ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plMin
   ' =====================================================================================
   PROPERTY SET Min <4> ( _                             ' VTable offset = 64
     BYVAL plMin AS LONG _                              ' __in long plMin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <5> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out OrientationConstants *pOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <5> ( _                     ' VTable offset = 72
     BYVAL pOrientation AS LONG _                       ' __in OrientationConstants pOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectRange <6> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSelectRange
   ' =====================================================================================
   PROPERTY SET SelectRange <6> ( _                     ' VTable offset = 80
     BYVAL pbSelectRange AS INTEGER _                   ' __in VARIANT_BOOL pbSelectRange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <7> ( _                        ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <7> ( _                        ' VTable offset = 88
     BYVAL plSelStart AS LONG _                         ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <8> ( _                       ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <8> ( _                       ' VTable offset = 96
     BYVAL plSelLength AS LONG _                        ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TickStyle <9> ( _                       ' VTable offset = 100
   ) AS LONG                                            ' __retval_out TickStyleConstants *pTickStyle
   ' =====================================================================================
   PROPERTY SET TickStyle <9> ( _                       ' VTable offset = 104
     BYVAL pTickStyle AS LONG _                         ' __in TickStyleConstants pTickStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TickFrequency <10> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plTickFrequency
   ' =====================================================================================
   PROPERTY SET TickFrequency <10> ( _                  ' VTable offset = 112
     BYVAL plTickFrequency AS LONG _                    ' __in long plTickFrequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <11> ( _                          ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY SET Value <11> ( _                          ' VTable offset = 120
     BYVAL plValue AS LONG _                            ' __in long plValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <12> ( _                      ' VTable offset = 124
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <12> ( _                      ' VTable offset = 128
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <12> ( _               ' VTable offset = 132
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <13> ( _                   ' VTable offset = 136
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <13> ( _                   ' VTable offset = 140
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 148
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 152
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 156
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 160
   ) AS LONG                                            ' __retval_out BorderStyleConstants *psBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 164
     BYVAL psBorderStyle AS LONG _                      ' __in BorderStyleConstants psBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 168
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 172
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 176
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearSel <14> ( _                             ' VTable offset = 180
   )                                                    ' void
   ' =====================================================================================
   METHOD DoClick <-551> ( _                            ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetNumTicks <15> ( _                    ' VTable offset = 188
   ) AS LONG                                            ' __retval_out long *plNumTicks
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 196
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <16> ( _                           ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <16> ( _                           ' VTable offset = 204
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextPosition <17> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out TextPositionConstants *penumTextPosition
   ' =====================================================================================
   PROPERTY SET TextPosition <17> ( _                   ' VTable offset = 212
     BYVAL penumTextPosition AS LONG _                  ' __in TextPositionConstants penumTextPosition
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_ISlider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IControls
' IID = {C8A3DC00-8593-11D1-B16A-00C0F0283628}
' A collection whose elements represent each contained control in a parent control.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IControls_INTERFACE_DEFINED)
    %MSComCtl_IControls_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IControls $IID_MSComCtl_IControls

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IControls_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComboItem
' IID = {DD9DA660-8594-11D1-B16A-00C0F0283628}
' An object that represents an entry in the listbox portion of the combobox control.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IComboItem_INTERFACE_DEFINED)
    %MSComCtl_IComboItem_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IComboItem $IID_MSComCtl_IComboItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectDefault_ <0> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET ObjectDefault_ <0> ( _                  ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Image <2> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pvImage
   ' =====================================================================================
   PROPERTY SET Image <2> ( _                           ' VTable offset = 40
     BYVAL pvImage AS VARIANT _                         ' __in VARIANT pvImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Indentation <5> ( _                     ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *psIndent
   ' =====================================================================================
   PROPERTY SET Indentation <5> ( _                     ' VTable offset = 48
     BYVAL psIndent AS INTEGER _                        ' __in short psIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <6> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   PROPERTY SET Index <6> ( _                           ' VTable offset = 56
     BYVAL plIndex AS LONG _                            ' __in long plIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <8> ( _                             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <8> ( _                             ' VTable offset = 64
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected <13> ( _                       ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSelected
   ' =====================================================================================
   PROPERTY SET Selected <13> ( _                       ' VTable offset = 72
     BYVAL pbSelected AS INTEGER _                      ' __in VARIANT_BOOL pbSelected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelImage <15> ( _                       ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT_BOOL *pvImage
   ' =====================================================================================
   PROPERTY SET SelImage <15> ( _                       ' VTable offset = 80
     BYVAL pvImage AS VARIANT _                         ' __in VARIANT_BOOL pvImage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tag <21> ( _                            ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT_BOOL *pvTag
   ' =====================================================================================
   PROPERTY SET Tag <21> ( _                            ' VTable offset = 88
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT_BOOL pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Tag <21> ( _                     ' VTable offset = 92
     BYVAL pvTag AS VARIANT _                           ' __in VARIANT_BOOL pvTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <23> ( _                           ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <23> ( _                           ' VTable offset = 100
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IComboItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComboItems
' IID = {DD9DA662-8594-11D1-B16A-00C0F0283628}
' The ComboItems Collection.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IComboItems_INTERFACE_DEFINED)
    %MSComCtl_IComboItems_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IComboItems $IID_MSComCtl_IComboItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CollectionDefault_ <0> ( _              ' VTable offset = 28
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IComboItem                             ' __retval_out IComboItem **ppComboItem
   ' =====================================================================================
   PROPERTY SET CollectionDefault_ <0> ( _              ' VTable offset = 32
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL MSComCtl_IComboItem _                        ' __in IComboItem *ppComboItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <27> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY SET Count <27> ( _                          ' VTable offset = 40
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <28> ( _                           ' VTable offset = 44
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS MSComCtl_IComboItem                             ' __retval_out IComboItem **ppComboItem
   ' =====================================================================================
   PROPERTY SET Item <28> ( _                           ' VTable offset = 48
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   , BYVAL ppComboItem AS MSComCtl_IComboItem _         ' __in IComboItem *ppComboItem
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <25> ( _                                  ' VTable offset = 52
     OPTIONAL BYREF Index AS VARIANT _                  ' __in_opt VARIANT *Index
   , OPTIONAL BYREF Key AS VARIANT _                    ' __in_opt VARIANT *Key
   , OPTIONAL BYREF Text AS VARIANT _                   ' __in_opt VARIANT *Text
   , OPTIONAL BYREF Image AS VARIANT _                  ' __in_opt VARIANT *Image
   , OPTIONAL BYREF SelImage AS VARIANT _               ' __in_opt VARIANT *SelImage
   , OPTIONAL BYREF Indentation AS VARIANT _            ' __in_opt VARIANT *Indentation
   ) AS MSComCtl_IComboItem                             ' __retval_out IComboItem **ppComboItem
   ' =====================================================================================
   METHOD Clear <26> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <29> ( _                               ' VTable offset = 60
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IComboItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImageCombo
' IID = {DD9DA664-8594-11D1-B16A-00C0F0283628}
' Microsoft ImageComboBox Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl_IImageCombo_INTERFACE_DEFINED)
    %MSComCtl_IImageCombo_INTERFACE_DEFINED = 1

INTERFACE MSComCtl_IImageCombo $IID_MSComCtl_IImageCombo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Text <-517> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <-517> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 40
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 48
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 52
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 56
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 60
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 68
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 76
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageList <3> ( _                       ' VTable offset = 80
   ) AS IDispatch                                       ' __retval_out IDispatch **ppImageList
   ' =====================================================================================
   PROPERTY SET putref_ImageList <3> ( _                ' VTable offset = 84
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ImageList <3> ( _                       ' VTable offset = 88
     BYVAL ppImageList AS IDispatch _                   ' __in IDispatch *ppImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Indentation <4> ( _                     ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out short *psIndent
   ' =====================================================================================
   PROPERTY SET Indentation <4> ( _                     ' VTable offset = 96
     BYVAL psIndent AS INTEGER _                        ' __in short psIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ComboItems <7> ( _                      ' VTable offset = 100
   ) AS MSComCtl_IComboItems                            ' __retval_out IComboItems **ppComboItems
   ' =====================================================================================
   PROPERTY SET putref_ComboItems <7> ( _               ' VTable offset = 104
     BYVAL ppComboItems AS MSComCtl_IComboItems _       ' __in IComboItems *ppComboItems
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <9> ( _                          ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbLocked
   ' =====================================================================================
   PROPERTY SET Locked <9> ( _                          ' VTable offset = 112
     BYVAL pbLocked AS INTEGER _                        ' __in VARIANT_BOOL pbLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <10> ( _                      ' VTable offset = 116
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <10> ( _                      ' VTable offset = 120
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <10> ( _               ' VTable offset = 124
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <11> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out MousePointerConstants *penumMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <11> ( _                   ' VTable offset = 132
     BYVAL penumMousePointer AS LONG _                  ' __in MousePointerConstants penumMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 136
   ) AS LONG                                            ' __retval_out OLEDragConstants *psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 140
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 144
   ) AS LONG                                            ' __retval_out OLEDragConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 148
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDragConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <14> ( _                   ' VTable offset = 152
   ) AS MSComCtl_IComboItem                             ' __retval_out IComboItem **ppIComboItem
   ' =====================================================================================
   PROPERTY SET putref_SelectedItem <14> ( _            ' VTable offset = 156
     BYVAL ppIComboItem AS MSComCtl_IComboItem _        ' __in IComboItem *ppIComboItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SelectedItem <14> ( _                   ' VTable offset = 160
     BYREF IN ppIComboItem AS VARIANT _                 ' __in VARIANT *ppIComboItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <16> ( _                      ' VTable offset = 164
   ) AS LONG                                            ' __retval_out long *plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <16> ( _                      ' VTable offset = 168
     BYVAL plSelLength AS LONG _                        ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <17> ( _                       ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *plSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <17> ( _                       ' VTable offset = 176
     BYVAL plSelStart AS LONG _                         ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelText <18> ( _                        ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET SelText <18> ( _                        ' VTable offset = 184
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <20> ( _                          ' VTable offset = 188
   ) AS LONG                                            ' __retval_out ImageComboStyleConstants *penumStyle
   ' =====================================================================================
   PROPERTY SET Style <20> ( _                          ' VTable offset = 192
     BYVAL penumStyle AS LONG _                         ' __in ImageComboStyleConstants penumStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsePathSep <24> ( _                     ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUsePathSep
   ' =====================================================================================
   PROPERTY SET UsePathSep <24> ( _                     ' VTable offset = 200
     BYVAL pbUsePathSep AS INTEGER _                    ' __in VARIANT_BOOL pbUsePathSep
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFirstVisible <30> ( _                      ' VTable offset = 208
   ) AS MSComCtl_IComboItem                             ' __retval_out IComboItem **ppIComboItem
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 212
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl_IImageCombo_INTERFACE_DEFINED__ */
