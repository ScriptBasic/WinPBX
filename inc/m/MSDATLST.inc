' ########################################################################################
' Microsoft Windows
' File: MSDatLst.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSDataListLib
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft DataList Controls 6.0 (OLEDB)
' Library name: MSDATLST.OCX
' Library GUID: {F0D2F211-CCB0-11D0-A316-00AA00688B10}
' Help file: dblist98.chm
' License key: A133F000-CCB0-11d0-A316-00AA00688B10
' ########################################################################################

#INCLUDE THIS ONCE
%MSDATLST_INC = 1

$RTLKEY_DATALIST = "A133F000-CCB0-11d0-A316-00AA00688B10"

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "msdatsrc.inc"
#INCLUDE ONCE "vbinterf.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_MSDataListLibDataCombo1 = "MSDataListLib.DataCombo.1"
$PROGID_MSDataListLibDataList1 = "MSDataListLib.DataList.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DataCombo = GUID$("{F0D2F21C-CCB0-11D0-A316-00AA00688B10}")
$CLSID_DataList = GUID$("{F0D2F219-CCB0-11D0-A316-00AA00688B10}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DDataComboEvents = GUID$("{F0D2F21B-CCB0-11D0-A316-00AA00688B10}")
$IID_DDataListEvents = GUID$("{F0D2F218-CCB0-11D0-A316-00AA00688B10}")
$IID_IDataCombo = GUID$("{F0D2F21A-CCB0-11D0-A316-00AA00688B10}")
$IID_IDataList = GUID$("{F0D2F217-CCB0-11D0-A316-00AA00688B10}")

' ========================================================================================
' OLEDragConstants enum
' IID: {D8898460-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDragMode property (but not the DragMode or OLEDropMode properties).
' ========================================================================================

%dblOLEDragManual                                       = 0            ' &H0
%dblOLEDragAutomatic                                    = 1            ' &H1

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%dblOLEDropNone                                         = 0            ' &H0
%dblOLEDropManual                                       = 1            ' &H1

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%dblEnter                                               = 0            ' &H0
%dblLeave                                               = 1            ' &H1
%dblOver                                                = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%dblCFText                                              = 1            ' &H1
%dblCFBitmap                                            = 2            ' &H2
%dblCFMetafile                                          = 3            ' &H3
%dblCFDIB                                               = 8            ' &H8
%dblCFPalette                                           = 9            ' &H9
%dblCFEMetafile                                         = 14           ' &HE
%dblCFFiles                                             = 15           ' &HF
%dblCFRTF                                               = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%dblOLEDropEffectNone                                   = 0            ' &H0
%dblOLEDropEffectCopy                                   = 1            ' &H1
%dblOLEDropEffectMove                                   = 2            ' &H2
%dblOLEDropEffectScroll                                 = -2147483648  ' &H80000000

' ========================================================================================
' AppearanceConstants enum
' IID: {F0D2F212-CCB0-11D0-A316-00AA00688B10}
' Appearance Constants
' ========================================================================================

%dblFlat                                                = 0            ' &H0
%dbl3D                                                  = 1            ' &H1

' ========================================================================================
' AreaConstants enum
' Area Constants (for the control's Click and DblClick Events)
' ========================================================================================

%dbcAreaButton                                          = 0            ' &H0
%dbcAreaEdit                                            = 1            ' &H1
%dbcAreaList                                            = 2            ' &H2

' ========================================================================================
' MousePointerConstants enum
' IID: {F0D2F213-CCB0-11D0-A316-00AA00688B10}
' MousePointer Constants
' ========================================================================================

%dblDefault                                             = 0            ' &H0
%dblArrow                                               = 1            ' &H1
%dblCross                                               = 2            ' &H2
%dblIBeam                                               = 3            ' &H3
%dblIcon                                                = 4            ' &H4
%dblSize                                                = 5            ' &H5
%dblSizeNESW                                            = 6            ' &H6
%dblSizeNS                                              = 7            ' &H7
%dblSizeNWSE                                            = 8            ' &H8
%dblSizeEW                                              = 9            ' &H9
%dblUpArrow                                             = 10           ' &HA
%dblHourglass                                           = 11           ' &HB
%dblNoDrop                                              = 12           ' &HC
%dblArrowHourglass                                      = 13           ' &HD
%dblArrowQuestion                                       = 14           ' &HE
%dblSizeAll                                             = 15           ' &HF
%dblCustom                                              = 99           ' &H63

' ========================================================================================
' MatchEntryConstants enum
' IID: {F0D2F214-CCB0-11D0-A316-00AA00688B10}
' MatchEntry Constants
' ========================================================================================

%dblBasicMatching                                       = 0            ' &H0
%dblExtendedMatching                                    = 1            ' &H1

' ========================================================================================
' StyleConstants enum
' IID: {F0D2F215-CCB0-11D0-A316-00AA00688B10}
' Style Constants
' ========================================================================================

%dbcDropdownCombo                                       = 0            ' &H0
%dbcSimpleCombo                                         = 1            ' &H1
%dbcDropdownList                                        = 2            ' &H2

' ========================================================================================
' ErrorConstants enum
' IID: {F0D2F216-CCB0-11D0-A316-00AA00688B10}
' Run-time error constants
' ========================================================================================

%dblOutOfMemory                                         = 7            ' &H7
%dblGetNotSupported                                     = 394          ' &H18A
%dblSetNotPermitted                                     = 387          ' &H183
%dblInvalidPropertyValue                                = 380          ' &H17C
%dblDataObjectLocked                                    = 672          ' &H2A0
%dblExpectedAnArgument                                  = 673          ' &H2A1
%dblInvalidProcedureCall                                = 5            ' &H5
%dblInvalidObjectUse                                    = 425          ' &H1A9
%dblWrongClipboardFormat                                = 461          ' &H1CD
%dblRecursiveOleDrag                                    = 674          ' &H2A2
%dblFormatNotByteArray                                  = 675          ' &H2A3
%dblDataNotSetForFormat                                 = 676          ' &H2A4

' ########################################################################################
' Interface name = IDataList
' IID = {F0D2F217-CCB0-11D0-A316-00AA00688B10}
' Fills a list box with a field from one Data control and can pass the field to a second Data control.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDataList_INTERFACE_DEFINED)
    %IDataList_INTERFACE_DEFINED = 1

INTERFACE IDataList $IID_IDataList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET defText <0> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrText
   ' =====================================================================================
   PROPERTY SET defText <0> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <1> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfLocked
   ' =====================================================================================
   PROPERTY SET Locked <1> ( _                          ' VTable offset = 40
     BYVAL pfLocked AS INTEGER _                        ' __in VARIANT_BOOL pfLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BoundText <2> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBoundText
   ' =====================================================================================
   PROPERTY SET BoundText <2> ( _                       ' VTable offset = 48
     BYVAL pbstrBoundText AS WSTRING _                  ' __in BSTR pbstrBoundText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BoundColumn <4> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBoundColumn
   ' =====================================================================================
   PROPERTY SET BoundColumn <4> ( _                     ' VTable offset = 56
     BYVAL pbstrBoundColumn AS WSTRING _                ' __in BSTR pbstrBoundColumn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <-521> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out MousePointerConstants* psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <-521> ( _                 ' VTable offset = 64
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <6> ( _                       ' VTable offset = 68
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp** ppMouseIconDisp
   ' =====================================================================================
   PROPERTY SET MouseIcon <6> ( _                       ' VTable offset = 72
     BYVAL ppMouseIconDisp AS IPictureDisp _            ' __in IPictureDisp *ppMouseIconDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <6> ( _                ' VTable offset = 76
     BYVAL ppMouseIconDisp AS IPictureDisp _            ' __in IPictureDisp* ppMouseIconDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IntegralHeight <7> ( _                  ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfIntegral
   ' =====================================================================================
   PROPERTY SET IntegralHeight <7> ( _                  ' VTable offset = 84
     BYVAL pfIntegral AS INTEGER _                      ' __in VARIANT_BOOL pfIntegral
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MatchEntry <8> ( _                      ' VTable offset = 88
   ) AS LONG                                            ' __retval_out MatchEntryConstants *pmec
   ' =====================================================================================
   PROPERTY SET MatchEntry <8> ( _                      ' VTable offset = 92
     BYVAL pmec AS LONG _                               ' __in MatchEntryConstants pmec
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <9> ( _                    ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarSelectedItem
   ' =====================================================================================
   PROPERTY GET VisibleCount <10> ( _                   ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out short* psCount
   ' =====================================================================================
   PROPERTY GET Text <11> ( _                           ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrText
   ' =====================================================================================
   PROPERTY SET Text <11> ( _                           ' VTable offset = 108
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListField <12> ( _                      ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrListField
   ' =====================================================================================
   PROPERTY SET ListField <12> ( _                      ' VTable offset = 116
     BYVAL pbstrListField AS WSTRING _                  ' __in BSTR pbstrListField
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 120
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 124
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfEnable
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 132
     BYVAL pfEnable AS INTEGER _                        ' __in VARIANT_BOOL pfEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 136
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 140
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 148
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MatchedWithList <15> ( _                ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfMatched
   ' =====================================================================================
   PROPERTY GET Appearance <16> ( _                     ' VTable offset = 156
   ) AS LONG                                            ' __retval_out AppearanceConstants* penumAppearances
   ' =====================================================================================
   PROPERTY SET Appearance <16> ( _                     ' VTable offset = 160
     BYVAL penumAppearances AS LONG _                   ' __in AppearanceConstants penumAppearances
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RightToLeft <-611> ( _                  ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfRightToLeft
   ' =====================================================================================
   PROPERTY SET RightToLeft <-611> ( _                  ' VTable offset = 168
     BYVAL pfRightToLeft AS INTEGER _                   ' __in VARIANT_BOOL pfRightToLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hwnd <-515> ( _                         ' VTable offset = 172
   ) AS LONG                                            ' __retval_out OLE_HANDLE* phWnd
   ' =====================================================================================
   PROPERTY GET RowSource <104> ( _                     ' VTable offset = 176
   ) AS DataSource                                      ' __retval_out DataSource** ppDataSource
   ' =====================================================================================
   PROPERTY SET putref_RowSource <104> ( _              ' VTable offset = 180
     BYVAL ppDataSource AS DataSource _                 ' __in DataSource* ppDataSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowMember <103> ( _                     ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out DataMember* dmMember
   ' =====================================================================================
   PROPERTY SET RowMember <103> ( _                     ' VTable offset = 188
     BYVAL dmMember AS WSTRING _                        ' __in DataMember dmMember
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 192
   ) AS LONG                                            ' __retval_out OLEDragConstants* psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 196
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 204
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD ReFill <13> ( _                               ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VisibleItems <14> ( _                   ' VTable offset = 212
     BYVAL nIndex AS INTEGER _                          ' __in short nIndex
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarItem
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CachePages <100> ( _                    ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out short* psSize
   ' =====================================================================================
   PROPERTY SET CachePages <100> ( _                    ' VTable offset = 228
     BYVAL psSize AS INTEGER _                          ' __in short psSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CachePageSize <101> ( _                 ' VTable offset = 232
   ) AS INTEGER                                         ' __retval_out short* psSize
   ' =====================================================================================
   PROPERTY SET CachePageSize <101> ( _                 ' VTable offset = 236
     BYVAL psSize AS INTEGER _                          ' __in short psSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmoothScroll <102> ( _                  ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSmoothScroll
   ' =====================================================================================
   PROPERTY SET SmoothScroll <102> ( _                  ' VTable offset = 244
     BYVAL pfSmoothScroll AS INTEGER _                  ' __in VARIANT_BOOL pfSmoothScroll
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataCombo
' IID = {F0D2F21A-CCB0-11D0-A316-00AA00688B10}
' Fills a list box with a field from a Data control and can pass this data to a second
' Data control. The field is copied to a text box, which can be edited.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDataCombo_INTERFACE_DEFINED)
    %IDataCombo_INTERFACE_DEFINED = 1

INTERFACE IDataCombo $IID_IDataCombo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET defText <0> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrText
   ' =====================================================================================
   PROPERTY SET defText <0> ( _                         ' VTable offset = 32
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListField <1> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrListField
   ' =====================================================================================
   PROPERTY SET ListField <1> ( _                       ' VTable offset = 40
     BYVAL pbstrListField AS WSTRING _                  ' __in BSTR pbstrListField
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BoundText <2> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBoundText
   ' =====================================================================================
   PROPERTY SET BoundText <2> ( _                       ' VTable offset = 48
     BYVAL pbstrBoundText AS WSTRING _                  ' __in BSTR pbstrBoundText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BoundColumn <3> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrBoundColumn
   ' =====================================================================================
   PROPERTY SET BoundColumn <3> ( _                     ' VTable offset = 56
     BYVAL pbstrBoundColumn AS WSTRING _                ' __in BSTR pbstrBoundColumn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <4> ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out StyleConstants* psc
   ' =====================================================================================
   PROPERTY SET Style <4> ( _                           ' VTable offset = 64
     BYVAL psc AS LONG _                                ' __in StyleConstants psc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <-521> ( _                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out MousePointerConstants* psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <-521> ( _                 ' VTable offset = 72
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <6> ( _                          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfLocked
   ' =====================================================================================
   PROPERTY SET Locked <6> ( _                          ' VTable offset = 80
     BYVAL pfLocked AS INTEGER _                        ' __in VARIANT_BOOL pfLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <7> ( _                       ' VTable offset = 84
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp** ppMouseIconDisp
   ' =====================================================================================
   PROPERTY SET MouseIcon <7> ( _                       ' VTable offset = 88
     BYVAL ppMouseIconDisp AS IPictureDisp _            ' __in IPictureDisp* ppMouseIconDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <7> ( _                ' VTable offset = 92
     BYVAL ppMouseIconDisp AS IPictureDisp _            ' __in IPictureDisp* ppMouseIconDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IntegralHeight <8> ( _                  ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfIntegral
   ' =====================================================================================
   PROPERTY SET IntegralHeight <8> ( _                  ' VTable offset = 100
     BYVAL pfIntegral AS INTEGER _                      ' __in VARIANT_BOOL pfIntegral
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <9> ( _                        ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long* plSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <9> ( _                        ' VTable offset = 108
     BYVAL plSelStart AS LONG _                         ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <10> ( _                      ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long* plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <10> ( _                      ' VTable offset = 116
     BYVAL plSelLength AS LONG _                        ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelText <11> ( _                        ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSelText
   ' =====================================================================================
   PROPERTY SET SelText <11> ( _                        ' VTable offset = 124
     BYVAL pbstrSelText AS WSTRING _                    ' __in BSTR pbstrSelText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MatchEntry <12> ( _                     ' VTable offset = 128
   ) AS LONG                                            ' __retval_out MatchEntryConstants* pmec
   ' =====================================================================================
   PROPERTY SET MatchEntry <12> ( _                     ' VTable offset = 132
     BYVAL pmec AS LONG _                               ' __in MatchEntryConstants pmec
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <13> ( _                   ' VTable offset = 136
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarSelectedItem
   ' =====================================================================================
   PROPERTY GET VisibleCount <14> ( _                   ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out short* psCount
   ' =====================================================================================
   PROPERTY GET Text <15> ( _                           ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrText
   ' =====================================================================================
   PROPERTY SET Text <15> ( _                           ' VTable offset = 148
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 156
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 160
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 164
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 168
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 172
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfEnable
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 180
     BYVAL pfEnable AS INTEGER _                        ' __in VARIANT_BOOL pfEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MatchedWithList <19> ( _                ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfMatched
   ' =====================================================================================
   PROPERTY GET Appearance <20> ( _                     ' VTable offset = 188
   ) AS LONG                                            ' __retval_out AppearanceConstants* penumAppearances
   ' =====================================================================================
   PROPERTY SET Appearance <20> ( _                     ' VTable offset = 192
     BYVAL penumAppearances AS LONG _                   ' __in AppearanceConstants penumAppearances
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hwnd <-515> ( _                         ' VTable offset = 196
   ) AS LONG                                            ' __retval_out OLE_HANDLE* phWnd
   ' =====================================================================================
   PROPERTY GET RightToLeft <-611> ( _                  ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfRightToLeft
   ' =====================================================================================
   PROPERTY SET RightToLeft <-611> ( _                  ' VTable offset = 204
     BYVAL pfRightToLeft AS INTEGER _                   ' __in VARIANT_BOOL pfRightToLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowSource <104> ( _                     ' VTable offset = 208
   ) AS DataSource                                      ' __retval_out DataSource** ppDataSource
   ' =====================================================================================
   PROPERTY SET putref_RowSource <104> ( _              ' VTable offset = 212
     BYVAL ppDataSource AS DataSource _                 ' __in DataSource* ppDataSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowMember <103> ( _                     ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out DataMember* dmMember
   ' =====================================================================================
   PROPERTY SET RowMember <103> ( _                     ' VTable offset = 220
     BYVAL dmMember AS WSTRING _                        ' __in DataMember dmMember
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 224
   ) AS LONG                                            ' __retval_out OLEDragConstants* psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 228
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 232
   ) AS LONG                                            ' __retval_out OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 236
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD ReFill <17> ( _                               ' VTable offset = 240
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VisibleItems <18> ( _                   ' VTable offset = 244
     BYVAL nIndex AS INTEGER _                          ' __in short nIndex
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarItem
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CachePages <100> ( _                    ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out short* psSize
   ' =====================================================================================
   PROPERTY SET CachePages <100> ( _                    ' VTable offset = 260
     BYVAL psSize AS INTEGER _                          ' __in short psSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CachePageSize <101> ( _                 ' VTable offset = 264
   ) AS INTEGER                                         ' __retval_out short* psSize
   ' =====================================================================================
   PROPERTY SET CachePageSize <101> ( _                 ' VTable offset = 268
     BYVAL psSize AS INTEGER _                          ' __in short psSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmoothScroll <102> ( _                  ' VTable offset = 272
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSmoothScroll
   ' =====================================================================================
   PROPERTY SET SmoothScroll <102> ( _                  ' VTable offset = 276
     BYVAL pfSmoothScroll AS INTEGER _                  ' __in VARIANT_BOOL pfSmoothScroll
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataCombo_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDDataListEvents
' Interface name = DDataListEvents
' IID = {F0D2F218-CCB0-11D0-A316-00AA00688B10}
' Event interface for DataList control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDDataListEvents GUID$("{669367DC-0518-46B1-84E2-BAF230CD34A5}") AS EVENT

'INTERFACE DDataListEventsImpl GUID$("{F0D2F218-CCB0-11D0-A316-00AA00688B10}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in_out short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in     short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' __in_out short* KeyAscii
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in_out short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in     short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF AllowedEffects AS LONG _                     ' __in_out long* AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF DefaultCursors AS INTEGER _                  ' __in_out VARIANT_BOOL* DefaultCursors
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF DataFormat AS INTEGER _                      ' __in_out short* DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __in_out long* Effect
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF x AS SINGLE _                                ' __in_out float* x
'   , BYREF y AS SINGLE _                                ' __in_out float* y
'   , BYREF iState AS INTEGER _                          ' __in_out short* State
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF x AS SINGLE _                                ' __in_out float* x
'   , BYREF y AS SINGLE _                                ' __in_out float* y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDataComboEvents
' Interface name = DDataComboEvents
' IID = {F0D2F21B-CCB0-11D0-A316-00AA00688B10}
' Event interface for DataCombo control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDDataComboEvents GUID$("{9B116225-0DE1-4A78-A5CD-A0B028DFAA80}") AS EVENT

'INTERFACE DDataComboEventsImpl GUID$("{F0D2F21B-CCB0-11D0-A316-00AA00688B10}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Click <-600> ( _
'     BYVAL Area AS INTEGER _                            ' __in short Area
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601> ( _
'     BYVAL Area AS INTEGER _                            ' __in short Area
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in_out short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in     short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' __in_out short* KeyAscii
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in_out short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in     short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Change <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject* Data
'   , BYREF AllowedEffects AS LONG _                     ' __in_out long* AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF DefaultCursors AS INTEGER _                  ' __in_out VARIANT_BOOL* DefaultCursors
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF DataFormat AS INTEGER _                      ' __in_out short* DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __in_out long* Effect
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF x AS SINGLE _                                ' __in_out float* x
'   , BYREF y AS SINGLE _                                ' __in_out float* y
'   , BYREF iState AS INTEGER _                          ' __in_out short* State
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF x AS SINGLE _                                ' __in_out float* x
'   , BYREF y AS SINGLE _                                ' __in_out float* y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
