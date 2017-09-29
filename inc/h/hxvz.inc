' ########################################################################################
' Microsoft Windows
' File: hxvz.inc
' Library name: MSHelpControls
' Version: 1.0, Locale ID = 0
' Library GUID: {314111BA-A502-11D2-BBCA-00C04F8EC294}
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\Help\hxvz.dll
' Contents: Microsoft Help Visuals 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HXVZ_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {314111C6-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxIndexCtrl1 = "HxVz.HxIndexCtrl.1"
' CLSID = {314111B8-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxTocCtrl1 = "HxVz.HxTocCtrl.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {314111C6-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxIndexCtrl = "HxVz.HxIndexCtrl"
' CLSID = {314111B8-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxTocCtrl = "HxVz.HxTocCtrl"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_HxIndexCtrl = GUID$("{314111C6-A502-11D2-BBCA-00C04F8EC294}")
$CLSID_HxTocCtrl = GUID$("{314111B8-A502-11D2-BBCA-00C04F8EC294}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IHxIndexView = GUID$("{314111C4-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxIndexViewEvents = GUID$("{314111DF-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxTreeView = GUID$("{314111B9-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxTreeViewEvents = GUID$("{314111BB-A502-11D2-BBCA-00C04F8EC294}")

' ========================================================================================
' HxTreeLineStyleConstant enum
' IID: {314111C0-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxTreeLineStyle_TreeLines                              = 0            ' &H0
%HxTreeLineStyle_RootLines                              = 1            ' &H1

' ========================================================================================
' HxTreeStyleConstant enum
' IID: {314111C1-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxTreeStyle_TextOnly                                   = 0            ' &H0
%HxTreeStyle_PictureText                                = 1            ' &H1
%HxTreeStyle_PlusMinusText                              = 2            ' &H2
%HxTreeStyle_PlusPictureText                            = 3            ' &H3
%HxTreeStyle_TreelinesText                              = 4            ' &H4
%HxTreeStyle_TreelinesPictureText                       = 5            ' &H5
%HxTreeStyle_TreelinesPlusMinusText                     = 6            ' &H6
%HxTreeStyle_TreelinesPlusMinusPictureText              = 7            ' &H7

' ========================================================================================
' HxBorderStyle enum
' IID: {314111BE-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxBorderStyle_None                                     = 0            ' &H0
%HxBorderStyle_FixedSingle                              = 1            ' &H1

' ========================================================================================
' HxAppearanceConstant enum
' IID: {314111BF-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxAppearance_Flat                                      = 0            ' &H0
%HxAppearance_3D                                        = 1            ' &H1

' ========================================================================================
' HxMousePointerConstant enum
' IID: {314111C2-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxMousePointer_Default                                 = 0            ' &H0
%HxMousePointer_Arrow                                   = 1            ' &H1
%HxMousePointer_Cross                                   = 2            ' &H2
%HxMousePointer_IBeam                                   = 3            ' &H3
%HxMousePointer_Icon                                    = 4            ' &H4
%HxMousePointer_Size                                    = 5            ' &H5
%HxMousePointer_SizeNESW                                = 6            ' &H6
%HxMousePointer_SizeNS                                  = 7            ' &H7
%HxMousePointer_SizeNWSE                                = 8            ' &H8
%HxMousePointer_SizeEW                                  = 9            ' &H9
%HxMousePointer_UpArrow                                 = 10           ' &HA
%HxMousePointer_Hourglass                               = 11           ' &HB
%HxMousePointer_NoDrop                                  = 12           ' &HC
%HxMousePointer_ArrowHourglass                          = 13           ' &HD
%HxMousePointer_ArrowQuestion                           = 14           ' &HE
%HxMousePointer_SizeAll                                 = 15           ' &HF
%HxMousePointer_Custom                                  = 99           ' &H63

' ========================================================================================
' HxFontSourceConstant enum
' IID: {31411231-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxFontCollection                                       = 0            ' &H0
%HxFontExternal                                         = 1            ' &H1

' ########################################################################################
' Interface name = IHxTreeView
' IID = {314111B9-A502-11D2-BBCA-00C04F8EC294}
' IHxTreeView Interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxTreeView_INTERFACE_DEFINED)
    %IHxTreeView_INTERFACE_DEFINED = 1

INTERFACE IHxTreeView $IID_IHxTreeView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Hierarchy <4096> ( _                    ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IHxHierarchy** ppIHxHierarchy
   ' =====================================================================================
   PROPERTY SET Hierarchy <4096> ( _                    ' VTable offset = 32
     BYVAL ppIHxHierarchy AS IDispatch _                ' __in IHxHierarchy* ppIHxHierarchy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ImageList <4100> ( _                    ' VTable offset = 36
     BYVAL phImageList AS LONG _                        ' __in long phImageList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageList <4100> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* phImageList
   ' =====================================================================================
   PROPERTY GET HideSelection <4097> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbHideSelection
   ' =====================================================================================
   PROPERTY SET HideSelection <4097> ( _                ' VTable offset = 48
     BYVAL pbHideSelection AS INTEGER _                 ' __in VARIANT_BOOL pbHideSelection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle <4098> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out HxTreeLineStyleConstant* psLineStyle
   ' =====================================================================================
   PROPERTY SET LineStyle <4098> ( _                    ' VTable offset = 56
     BYVAL psLineStyle AS LONG _                        ' __in HxTreeLineStyleConstant psLineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TreeStyle <4099> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out HxTreeStyleConstant* psStyle
   ' =====================================================================================
   PROPERTY SET TreeStyle <4099> ( _                    ' VTable offset = 64
     BYVAL psStyle AS LONG _                            ' __in HxTreeStyleConstant psStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 68
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 72
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 76
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 80
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclr
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 84
     BYVAL pstyle AS LONG _                             ' __in HxBorderStyle pstyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 88
   ) AS LONG                                            ' __retval_out HxBorderStyle* pstyle
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 92
     BYVAL pappearance AS LONG _                        ' __in HxAppearanceConstant pappearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out HxAppearanceConstant* pappearance
   ' =====================================================================================
   PROPERTY SET MousePointer <-521> ( _                 ' VTable offset = 100
     BYVAL ppointer AS LONG _                           ' __in HxMousePointerConstant ppointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <-521> ( _                 ' VTable offset = 104
   ) AS LONG                                            ' __retval_out HxMousePointerConstant* ppointer
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 112
     BYVAL Font AS IDispatch _                          ' __in Font* ppFont Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 116
     BYVAL ppFont AS IDispatch _                        ' __in Font* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 120
   ) AS IDispatch                                       ' __retval_out Font** ppFont
   ' =====================================================================================
   METHOD Synchronize <4101> ( _                        ' VTable offset = 124
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selection <4102> ( _                    ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long* phNode
   ' =====================================================================================
   PROPERTY GET LangId <4103> ( _                       ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out short* piHelpLangId
   ' =====================================================================================
   PROPERTY SET LangId <4103> ( _                       ' VTable offset = 136
     BYVAL piHelpLangId AS INTEGER _                    ' __in short piHelpLangId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontSource <4104> ( _                   ' VTable offset = 140
   ) AS LONG                                            ' __retval_out HxFontSourceConstant* pFontSource
   ' =====================================================================================
   PROPERTY SET FontSource <4104> ( _                   ' VTable offset = 144
     BYVAL pFontSource AS LONG _                        ' __in HxFontSourceConstant pFontSource
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxTreeView_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxIndexView
' IID = {314111C4-A502-11D2-BBCA-00C04F8EC294}
' IHxIndexView Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxIndexView_INTERFACE_DEFINED)
    %IHxIndexView_INTERFACE_DEFINED = 1

INTERFACE IHxIndexView $IID_IHxIndexView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IndexData <16384> ( _                   ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IHxIndex** ppIHxIndex
   ' =====================================================================================
   PROPERTY SET IndexData <16384> ( _                   ' VTable offset = 32
     BYVAL ppIHxIndex AS IDispatch _                    ' __in IHxIndex* ppIHxIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Selection <16385> ( _                   ' VTable offset = 36
     BYVAL piItem AS LONG _                             ' __in long piItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selection <16385> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* piItem
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 44
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 52
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 60
     BYVAL pstyle AS LONG _                             ' __in HxBorderStyle pstyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out HxBorderStyle* pstyle
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 68
     BYVAL pappearance AS LONG _                        ' __in HxAppearanceConstant pappearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out HxAppearanceConstant* pappearance
   ' =====================================================================================
   PROPERTY SET MousePointer <-521> ( _                 ' VTable offset = 76
     BYVAL ppointer AS LONG _                           ' __in HxMousePointerConstant ppointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <-521> ( _                 ' VTable offset = 80
   ) AS LONG                                            ' __retval_out HxMousePointerConstant* ppointer
   ' =====================================================================================
   METHOD SelectItem <16386> ( _                        ' VTable offset = 84
     BYVAL iItem AS LONG _                              ' __in long iItem
   )                                                    ' void
   ' =====================================================================================
   METHOD ClickItem <16387> ( _                         ' VTable offset = 88
     BYVAL iItem AS LONG _                              ' __in long iItem
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 96
     BYVAL ppFont AS IDispatch _                        ' __in Font* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 100
     BYVAL ppFont AS IDispatch _                        ' __in Font* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 104
   ) AS IDispatch                                       ' __retval_out Font** ppFont
   ' =====================================================================================
   PROPERTY SET HighlightForeColor <16388> ( _          ' VTable offset = 108
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighlightForeColor <16388> ( _          ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET HighlightBackColor <16389> ( _          ' VTable offset = 116
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighlightBackColor <16389> ( _          ' VTable offset = 120
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET FocusHighlightForeColor <16390> ( _     ' VTable offset = 124
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FocusHighlightForeColor <16390> ( _     ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY SET FocusHighlightBackColor <16391> ( _     ' VTable offset = 132
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FocusHighlightBackColor <16391> ( _     ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclr
   ' =====================================================================================
   PROPERTY GET LangId <16392> ( _                      ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out short* piHelpLangId
   ' =====================================================================================
   PROPERTY SET LangId <16392> ( _                      ' VTable offset = 144
     BYVAL piHelpLangId AS INTEGER _                    ' __in short piHelpLangId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontSource <16393> ( _                  ' VTable offset = 148
   ) AS LONG                                            ' __retval_out HxFontSourceConstant* pFontSource
   ' =====================================================================================
   PROPERTY SET FontSource <16393> ( _                  ' VTable offset = 152
     BYVAL pFontSource AS LONG _                        ' __in HxFontSourceConstant pFontSource
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxIndexView_INTERFACE_DEFINED__ */
