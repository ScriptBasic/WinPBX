' ########################################################################################
' Microsoft Windows
' File: MSDatGrd.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSDataGridLib
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft DataGrid Control 6.0 (OLEDB)
' Library name: MSDATGRD.OCX
' Library GUID: {CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}
' Help file: DBGRID98.CHM
' License key: CDE57A55-8B86-11D0-b3C6-00A0C90AEA82
' ########################################################################################

#INCLUDE THIS ONCE
%MSDATGRD_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "msdatsrc.inc"
#INCLUDE ONCE "msstdfmt.inc"

$RTLKEY_DataGrid = "CDE57A55-8B86-11D0-b3C6-00A0C90AEA82"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DataGrid = GUID$("{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DataGrid_Column = GUID$("{CDE57A4F-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_DataGrid_Columns = GUID$("{CDE57A50-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_DDataGridEvents = GUID$("{CDE57A42-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_IDataGrid = GUID$("{CDE57A41-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_DataGrid_SelBookmarks = GUID$("{CDE57A52-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_DataGrid_Split = GUID$("{CDE57A54-8B86-11D0-B3C6-00A0C90AEA82}")
$IID_DataGrid_Splits = GUID$("{CDE57A53-8B86-11D0-B3C6-00A0C90AEA82}")

' ========================================================================================
' AddNewModeConstants enum
' IID: {CDE57A45-8B86-11D0-B3C6-00A0C90AEA82}
' AddNewMode Constants
' ========================================================================================

%dbgNoAddNew                                            = 0            ' &H0
%dbgAddNewCurrent                                       = 1            ' &H1
%dbgAddNewPending                                       = 2            ' &H2

' ========================================================================================
' AlignmentConstants enum
' IID: {CDE57A46-8B86-11D0-B3C6-00A0C90AEA82}
' Alignment Constants
' ========================================================================================

%dbgLeft                                                = 0            ' &H0
%dbgRight                                               = 1            ' &H1
%dbgCenter                                              = 2            ' &H2
%dbgGeneral                                             = 3            ' &H3

' ========================================================================================
' AppearanceConstants enum
' IID: {CDE57A47-8B86-11D0-B3C6-00A0C90AEA82}
' Appearance Constants
' ========================================================================================

%dbgFlat                                                = 0            ' &H0
%dbg3D                                                  = 1            ' &H1

' ========================================================================================
' BorderStyleConstants enum
' IID: {CDE57A48-8B86-11D0-B3C6-00A0C90AEA82}
' BorderStyle Constants
' ========================================================================================

%dbgNoBorder                                            = 0            ' &H0
%dbgFixedSingle                                         = 1            ' &H1

' ========================================================================================
' DividerStyleConstants enum
' IID: {CDE57A4A-8B86-11D0-B3C6-00A0C90AEA82}
' DividerStyle Constants
' ========================================================================================

%dbgNoDividers                                          = 0            ' &H0
%dbgBlackLine                                           = 1            ' &H1
%dbgDarkGrayLine                                        = 2            ' &H2
%dbgRaised                                              = 3            ' &H3
%dbgInset                                               = 4            ' &H4
%dbgUseForeColor                                        = 5            ' &H5
%dbgLightGrayLine                                       = 6            ' &H6

' ========================================================================================
' ErrorConstants enum
' IID: {AC88CF9C-E803-11D0-BCF9-00C04FC2FB86}
' Valid errors returned by the Datagrid control
' ========================================================================================

%dbgOutOfMemory                                         = 7            ' &H7
%dbgSubscriptRange                                      = 9            ' &H9
%dbgTypeMismatch                                        = 13           ' &HD
%dbgInvalidPropertyValue                                = 380          ' &H17C
%dbgInvalidSafeModeProcCall                             = 680          ' &H2A8
%dbgColIndex                                            = 6145         ' &H1801
%dbgSplitIndex                                          = 6244         ' &H1864
%dbgCNotFound                                           = 6147         ' &H1803
%dbgInvBookmark                                         = 6149         ' &H1805
%dbgDataAccess                                          = 6160         ' &H1810
%dbgNoPropNow                                           = 6162         ' &H1812
%dbgBindError                                           = 4097         ' &H1001
%dbgInvRowNum                                           = 6148         ' &H1804
%dbgBadEvent                                            = 6161         ' &H1811
%dbgScrollRange                                         = 6151         ' &H1807
%dbgDelMultRows                                         = 6159         ' &H180F
%dbgDelError                                            = 6155         ' &H180B
%dbgAddError                                            = 6154         ' &H180A
%dbgUpdError                                            = 6153         ' &H1809
%dbgErrorSetCurrent                                     = 6152         ' &H1808
%dbgNotBookmarkable                                     = 7004         ' &H1B5C
%dbgOrphaned                                            = 7000         ' &H1B58
%dbgUnknown                                             = 7001         ' &H1B59
%dbgMustHaveSplit                                       = 7002         ' &H1B5A
%dbgNoMethodNow                                         = 7003         ' &H1B5B
%dbgNoRowset                                            = 7005         ' &H1B5D
%dbgConvertData                                         = 7006         ' &H1B5E
%dbgErrUpdateColumn                                     = 7007         ' &H1B5F
%dbgNoCurrentRow                                        = 7008         ' &H1B60
%dbgNoRowFound                                          = 7009         ' &H1B61
%dbgColReadOnly                                         = 7010         ' &H1B62
%dbgActionCanceled                                      = 7011         ' &H1B63

' ========================================================================================
' MarqueeStyleConstants enum
' IID: {CDE57A4B-8B86-11D0-B3C6-00A0C90AEA82}
' MarqueeStyle Constants
' ========================================================================================

%dbgDottedCellBorder                                    = 0            ' &H0
%dbgSolidCellBorder                                     = 1            ' &H1
%dbgHighlightCell                                       = 2            ' &H2
%dbgHighlightRow                                        = 3            ' &H3
%dbgHighlightRowRaiseCell                               = 4            ' &H4
%dbgNoMarquee                                           = 5            ' &H5
%dbgFloatingEditor                                      = 6            ' &H6

' ========================================================================================
' ScrollBarsConstants enum
' IID: {CDE57A4C-8B86-11D0-B3C6-00A0C90AEA82}
' ScrollBar Constants
' ========================================================================================

%dbgNone                                                = 0            ' &H0
%dbgHorizontal                                          = 1            ' &H1
%dbgVertical                                            = 2            ' &H2
%dbgBoth                                                = 3            ' &H3
%dbgAutomatic                                           = 4            ' &H4

' ========================================================================================
' SplitSizeModeConstants enum
' IID: {CDE57A4D-8B86-11D0-B3C6-00A0C90AEA82}
' SplitSizeMode Constants
' ========================================================================================

%dbgScalable                                            = 0            ' &H0
%dbgExact                                               = 1            ' &H1

' ========================================================================================
' TabActionConstants enum
' IID: {CDE57A4E-8B86-11D0-B3C6-00A0C90AEA82}
' TabAction Constants
' ========================================================================================

%dbgControlNavigation                                   = 0            ' &H0
%dbgColumnNavigation                                    = 1            ' &H1
%dbgGridNavigation                                      = 2            ' &H2

' ########################################################################################
' Interface name = Column
' IID = {CDE57A4F-8B86-11D0-B3C6-00A0C90AEA82}
' Column Object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DataGrid_Column_INTERFACE_DEFINED)
    %DataGrid_Column_INTERFACE_DEFINED = 1

INTERFACE DataGrid_Column $IID_DataGrid_Column

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Alignment <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out AlignmentConstants *penumAlignment
   ' =====================================================================================
   PROPERTY SET Alignment <1> ( _                       ' VTable offset = 32
     BYVAL AlignmentConstants AS LONG _                 ' __in AlignmentConstants penumAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowSizing <2> ( _                     ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowSizing
   ' =====================================================================================
   PROPERTY SET AllowSizing <2> ( _                     ' VTable offset = 40
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowSizing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Button <3> ( _                          ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfButton
   ' =====================================================================================
   PROPERTY SET Button <3> ( _                          ' VTable offset = 48
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfButton
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <-518> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <-518> ( _                      ' VTable offset = 56
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColIndex <4> ( _                        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *piColIndex
   ' =====================================================================================
   PROPERTY GET DataChanged <5> ( _                     ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfDataChanged
   ' =====================================================================================
   PROPERTY GET DataField <6> ( _                       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDataField
   ' =====================================================================================
   PROPERTY SET DataField <6> ( _                       ' VTable offset = 72
     BYVAL pbstrDataField AS WSTRING _                  ' __in BSTR pbstrDataField
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DividerStyle <8> ( _                    ' VTable offset = 76
   ) AS LONG                                            ' __retval_out DividerStyleConstants *penumDividerStyle
   ' =====================================================================================
   PROPERTY SET DividerStyle <8> ( _                    ' VTable offset = 80
     BYVAL LONG _                                       ' __in DividerStyleConstants penumDividerStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <9> ( _                            ' VTable offset = 84
   ) AS SINGLE                                          ' __retval_out OLE_XPOS_CONTAINER *pxposLeft OLE_XPOS_CONTAINER
   ' =====================================================================================
   PROPERTY GET Locked <10> ( _                         ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfLocked
   ' =====================================================================================
   PROPERTY SET Locked <10> ( _                         ' VTable offset = 92
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumberFormat <11> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNumberFormat
   ' =====================================================================================
   PROPERTY SET NumberFormat <11> ( _                   ' VTable offset = 100
     BYVAL pbstrNumberFormat AS WSTRING _               ' __in BSTR pbstrNumberFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <0> ( _                            ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <0> ( _                            ' VTable offset = 108
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <12> ( _                            ' VTable offset = 112
   ) AS SINGLE                                          ' __retval_out OLE_YPOS_CONTAINER *pyposTop
   ' =====================================================================================
   PROPERTY GET Value <13> ( _                          ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   PROPERTY SET Value <13> ( _                          ' VTable offset = 120
     BYVAL VARIANT _                                    ' __in VARIANT pvarValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <14> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfVisible
   ' =====================================================================================
   PROPERTY SET Visible <14> ( _                        ' VTable offset = 128
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <15> ( _                          ' VTable offset = 132
   ) AS SINGLE                                          ' __retval_out OLE_XSIZE_CONTAINER *pxsizeWidth
   ' =====================================================================================
   PROPERTY SET Width <15> ( _                          ' VTable offset = 136
     BYVAL SINGLE _                                     ' __in OLE_XSIZE_CONTAINER pxsizeWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrapText <16> ( _                       ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfWrapText
   ' =====================================================================================
   PROPERTY SET WrapText <16> ( _                       ' VTable offset = 144
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfWrapText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataFormat <17> ( _                     ' VTable offset = 148
   ) AS IDataFormatDisp                                 ' __retval_out IDataFormatDisp **ppdf
   ' =====================================================================================
   PROPERTY SET putref_DataFormat <17> ( _              ' VTable offset = 152
     BYVAL IDataFormatDisp _                            ' __in IDataFormatDisp *ppdf
   )                                                    ' void
   ' =====================================================================================
   METHOD CellText <100> ( _                            ' VTable offset = 156
     BYVAL VARIANT _                                    ' __in VARIANT Bookmark
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   METHOD CellValue <101> ( _                           ' VTable offset = 160
     BYVAL VARIANT _                                    ' __in VARIANT Bookmark
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DataGrid_Column_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Columns
' IID = {CDE57A50-8B86-11D0-B3C6-00A0C90AEA82}
' Contains a collection of grid columns
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DataGrid_Columns_INTERFACE_DEFINED)
    %DataGrid_Columns_INTERFACE_DEFINED = 1

INTERFACE DataGrid_Columns $IID_DataGrid_Columns

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **_ppNewEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL INTEGER _                                    ' __in short Index
   ) AS DataGrid_Column                                 ' __retval_out Column **pcol
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL VARIANT _                                    ' __in VARIANT Index
   ) AS DataGrid_Column                                 ' __retval_out Column **pcol
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL VARIANT _                                    ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DataGrid_Columns_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SelBookmarks
' IID = {CDE57A52-8B86-11D0-B3C6-00A0C90AEA82}
' Contains a collection of selected row bookmarks
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DataGrid_SelBookmarks_INTERFACE_DEFINED)
    %DataGrid_SelBookmarks_INTERFACE_DEFINED = 1

INTERFACE DataGrid_SelBookmarks $IID_DataGrid_SelBookmarks

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **_ppNewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL VARIANT _                                    ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBookmark
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 40
     BYVAL VARIANT _                                    ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 44
     BYVAL VARIANT _                                    ' __in VARIANT Bookmark
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DataGrid_SelBookmarks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Split
' IID = {CDE57A54-8B86-11D0-B3C6-00A0C90AEA82}
' Represents a group of adjacent columns that scroll as a unit
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DataGrid_Split_INTERFACE_DEFINED)
    %DataGrid_Split_INTERFACE_DEFINED = 1

INTERFACE DataGrid_Split $IID_DataGrid_Split

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AllowFocus <1> ( _                      ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowFocus
   ' =====================================================================================
   PROPERTY SET AllowFocus <1> ( _                      ' VTable offset = 32
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowFocus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowRowSizing <2> ( _                  ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowRowSizing
   ' =====================================================================================
   PROPERTY SET AllowRowSizing <2> ( _                  ' VTable offset = 40
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowRowSizing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowSizing <3> ( _                     ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowSizing
   ' =====================================================================================
   PROPERTY SET AllowSizing <3> ( _                     ' VTable offset = 48
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowSizing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCellVisible <4> ( _              ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCurrentCellVisible
   ' =====================================================================================
   PROPERTY SET CurrentCellVisible <4> ( _              ' VTable offset = 56
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfCurrentCellVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstRow <5> ( _                        ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarFirstRow
   ' =====================================================================================
   PROPERTY SET FirstRow <5> ( _                        ' VTable offset = 64
     BYVAL VARIANT _                                    ' __in VARIANT pvarFirstRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <6> ( _                           ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *piIndex
   ' =====================================================================================
   PROPERTY GET LeftCol <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *piLeftCol
   ' =====================================================================================
   PROPERTY SET LeftCol <7> ( _                         ' VTable offset = 76
     BYVAL INTEGER _                                    ' __in short piLeftCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <8> ( _                          ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfLocked
   ' =====================================================================================
   PROPERTY SET Locked <8> ( _                          ' VTable offset = 84
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarqueeStyle <9> ( _                    ' VTable offset = 88
   ) AS LONG                                            ' __retval_out MarqueeStyleConstants *penumMarqueeStyle
   ' =====================================================================================
   PROPERTY SET MarqueeStyle <9> ( _                    ' VTable offset = 92
     BYVAL LONG _                                       ' __in MarqueeStyleConstants penumMarqueeStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordSelectors <10> ( _                ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRecordSelectors
   ' =====================================================================================
   PROPERTY SET RecordSelectors <10> ( _                ' VTable offset = 100
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfRecordSelectors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollBars <11> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out ScrollBarsConstants *penumScrollBars
   ' =====================================================================================
   PROPERTY SET ScrollBars <11> ( _                     ' VTable offset = 108
     BYVAL LONG _                                       ' __in ScrollBarsConstants penumScrollBars
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollGroup <12> ( _                    ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out short *piScrollGroup
   ' =====================================================================================
   PROPERTY SET ScrollGroup <12> ( _                    ' VTable offset = 116
     BYVAL INTEGER _                                    ' __in short piScrollGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelEndCol <13> ( _                      ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out short *piSelEndCol
   ' =====================================================================================
   PROPERTY SET SelEndCol <13> ( _                      ' VTable offset = 124
     BYVAL INTEGER _                                    ' __in short piSelEndCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStartCol <14> ( _                    ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *piSelStartCol
   ' =====================================================================================
   PROPERTY SET SelStartCol <14> ( _                    ' VTable offset = 132
     BYVAL INTEGER _                                    ' __in short piSelStartCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <15> ( _                           ' VTable offset = 136
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSize
   ' =====================================================================================
   PROPERTY SET Size <15> ( _                           ' VTable offset = 140
     BYVAL VARIANT _                                    ' __in VARIANT pvarSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeMode <16> ( _                       ' VTable offset = 144
   ) AS LONG                                            ' __retval_out SplitSizeModeConstants *penumSizeMode
   ' =====================================================================================
   PROPERTY SET SizeMode <16> ( _                       ' VTable offset = 148
     BYVAL LONG _                                       ' __in SplitSizeModeConstants penumSizeMode
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearSelCols <100> ( _                        ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Columns <101> ( _                       ' VTable offset = 156
   ) AS DataGrid_Columns                                ' __retval_out Columns **ppColumns
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DataGrid_Split_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Splits
' IID = {CDE57A53-8B86-11D0-B3C6-00A0C90AEA82}
' Contains a collection of grid splits
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SDataGrid_plits_INTERFACE_DEFINED)
    %DataGrid_Splits_INTERFACE_DEFINED = 1

INTERFACE DataGrid_Splits $IID_DataGrid_Splits

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **_ppNewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL VARIANT _                                    ' __in VARIANT Index
   ) AS DataGrid_Split                                  ' __retval_out Split **psplit
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL INTEGER _                                    ' __in short Index
   ) AS DataGrid_Split                                  ' __retval_out Split **psplit
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL VARIANT _                                    ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Splits_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataGrid
' IID = {CDE57A41-8B86-11D0-B3C6-00A0C90AEA82}
' Microsoft DataGrid Control 6.0 (OLEDB)
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDataGrid_INTERFACE_DEFINED)
    %IDataGrid_INTERFACE_DEFINED = 1

INTERFACE IDataGrid $IID_IDataGrid

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AddNewMode <1> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out AddNewModeConstants *penumAddNewMode
   ' =====================================================================================
   PROPERTY GET AllowAddNew <2> ( _                     ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowAddNew
   ' =====================================================================================
   PROPERTY SET AllowAddNew <2> ( _                     ' VTable offset = 36
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowAddNew
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowArrows <3> ( _                     ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowArrows
   ' =====================================================================================
   PROPERTY SET AllowArrows <3> ( _                     ' VTable offset = 44
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowArrows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowDelete <4> ( _                     ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowDelete
   ' =====================================================================================
   PROPERTY SET AllowDelete <4> ( _                     ' VTable offset = 52
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowDelete
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowRowSizing <5> ( _                  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowRowSizing
   ' =====================================================================================
   PROPERTY SET AllowRowSizing <5> ( _                  ' VTable offset = 60
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowRowSizing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowUpdate <6> ( _                     ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowUpdate
   ' =====================================================================================
   PROPERTY SET AllowUpdate <6> ( _                     ' VTable offset = 68
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfAllowUpdate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out AppearanceConstants *penumAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 76
     BYVAL LONG _                                       ' __in AppearanceConstants penumAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApproxCount <8> ( _                     ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plApproxCount
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 84
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 88
     BYVAL DWORD _                                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bookmark <9> ( _                        ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBookmark
   ' =====================================================================================
   PROPERTY SET Bookmark <9> ( _                        ' VTable offset = 96
     BYVAL VARIANT _                                    ' __in VARIANT pvarBookmark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BorderStyleConstants *penumBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 104
     BYVAL LONG _                                       ' __in BorderStyleConstants penumBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <-518> ( _                      ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <-518> ( _                      ' VTable offset = 112
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Col <10> ( _                            ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out short *piCol
   ' =====================================================================================
   PROPERTY SET Col <10> ( _                            ' VTable offset = 120
     BYVAL INTEGER _                                    ' __in short piCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnHeaders <11> ( _                  ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfColumnHeaders
   ' =====================================================================================
   PROPERTY SET ColumnHeaders <11> ( _                  ' VTable offset = 128
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfColumnHeaders
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCellModified <12> ( _            ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCurrentCellModified
   ' =====================================================================================
   PROPERTY SET CurrentCellModified <12> ( _            ' VTable offset = 136
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfCurrentCellModified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCellVisible <13> ( _             ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCurrentCellVisible
   ' =====================================================================================
   PROPERTY SET CurrentCellVisible <13> ( _             ' VTable offset = 144
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfCurrentCellVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataChanged <14> ( _                    ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfDataChanged
   ' =====================================================================================
   PROPERTY SET DataChanged <14> ( _                    ' VTable offset = 152
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfDataChanged
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <42> ( _                     ' VTable offset = 156
   ) AS DataSource                                      ' __retval_out DataSource **ppds
   ' =====================================================================================
   PROPERTY SET putref_DataSource <42> ( _              ' VTable offset = 160
     BYVAL DataSource _                                 ' __in DataSource *ppds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataMember <43> ( _                     ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out DataMember *pdm
   ' =====================================================================================
   PROPERTY SET DataMember <43> ( _                     ' VTable offset = 168
     BYVAL pdm AS WSTRING _                             ' __in DataMember pdm
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefColWidth <16> ( _                    ' VTable offset = 172
   ) AS SINGLE                                          ' __retval_out float *psDefColWidth
   ' =====================================================================================
   PROPERTY SET DefColWidth <16> ( _                    ' VTable offset = 176
     BYVAL SINGLE _                                     ' __in float psDefColWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditActive <17> ( _                     ' VTable offset = 180
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEditActive
   ' =====================================================================================
   PROPERTY SET EditActive <17> ( _                     ' VTable offset = 184
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfEditActive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 188
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 192
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorText <18> ( _                      ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrErrorText
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 200
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 204
     BYVAL IFontDisp _                                  ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 208
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 212
     BYVAL DWORD _                                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstRow <19> ( _                       ' VTable offset = 216
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarFirstRow
   ' =====================================================================================
   PROPERTY SET FirstRow <19> ( _                       ' VTable offset = 220
     BYVAL VARIANT _                                    ' __in VARIANT pvarFirstRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HeadFont <20> ( _                       ' VTable offset = 224
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_HeadFont <20> ( _                ' VTable offset = 228
     BYVAL IFontDisp _                                  ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HeadLines <21> ( _                      ' VTable offset = 232
   ) AS SINGLE                                          ' __retval_out float *pxHeadLines
   ' =====================================================================================
   PROPERTY SET HeadLines <21> ( _                      ' VTable offset = 236
     BYVAL SINGLE _                                     ' __in float pxHeadLines
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 240
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY GET hWndEditor <22> ( _                     ' VTable offset = 244
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWndEditor
   ' =====================================================================================
   PROPERTY GET LeftCol <23> ( _                        ' VTable offset = 248
   ) AS INTEGER                                         ' __retval_out short *piLeftCol
   ' =====================================================================================
   PROPERTY SET LeftCol <23> ( _                        ' VTable offset = 252
     BYVAL INTEGER _                                    ' __in short piLeftCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarqueeStyle <25> ( _                   ' VTable offset = 256
   ) AS LONG                                            ' __retval_out MarqueeStyleConstants *penumMarqueeStyle
   ' =====================================================================================
   PROPERTY SET MarqueeStyle <25> ( _                   ' VTable offset = 260
     BYVAL LONG _                                       ' __in MarqueeStyleConstants penumMarqueeStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordSelectors <26> ( _                ' VTable offset = 264
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRecordSelectors
   ' =====================================================================================
   PROPERTY SET RecordSelectors <26> ( _                ' VTable offset = 268
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfRecordSelectors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RightToLeft <-611> ( _                  ' VTable offset = 272
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRightToLeft
   ' =====================================================================================
   PROPERTY SET RightToLeft <-611> ( _                  ' VTable offset = 276
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfRightToLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Row <27> ( _                            ' VTable offset = 280
   ) AS INTEGER                                         ' __retval_out short *piRow
   ' =====================================================================================
   PROPERTY SET Row <27> ( _                            ' VTable offset = 284
     BYVAL INTEGER _                                    ' __in short piRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowDividerStyle <28> ( _                ' VTable offset = 288
   ) AS LONG                                            ' __retval_out DividerStyleConstants *penumDividerStyle
   ' =====================================================================================
   PROPERTY SET RowDividerStyle <28> ( _                ' VTable offset = 292
     BYVAL LONG _                                       ' __in DividerStyleConstants penumDividerStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowHeight <29> ( _                      ' VTable offset = 296
   ) AS SINGLE                                          ' __retval_out float *pxRowHeight
   ' =====================================================================================
   PROPERTY SET RowHeight <29> ( _                      ' VTable offset = 300
     BYVAL SINGLE _                                     ' __in float pxRowHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollBars <-535> ( _                   ' VTable offset = 304
   ) AS LONG                                            ' __retval_out ScrollBarsConstants *penumScrollBars
   ' =====================================================================================
   PROPERTY SET ScrollBars <-535> ( _                   ' VTable offset = 308
     BYVAL LONG _                                       ' __in ScrollBarsConstants penumScrollBars
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelEndCol <31> ( _                      ' VTable offset = 312
   ) AS INTEGER                                         ' __retval_out short *piSelEndCol
   ' =====================================================================================
   PROPERTY SET SelEndCol <31> ( _                      ' VTable offset = 316
     BYVAL INTEGER _                                    ' __in short piSelEndCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <-548> ( _                    ' VTable offset = 320
   ) AS LONG                                            ' __retval_out long *plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <-548> ( _                    ' VTable offset = 324
     BYVAL LONG _                                       ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <-547> ( _                     ' VTable offset = 328
   ) AS LONG                                            ' __retval_out long *plSelStar
   ' =====================================================================================
   PROPERTY SET SelStart <-547> ( _                     ' VTable offset = 332
     BYVAL LONG _                                       ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStartCol <34> ( _                    ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out short *piSelStartCol
   ' =====================================================================================
   PROPERTY SET SelStartCol <34> ( _                    ' VTable offset = 340
     BYVAL INTEGER _                                    ' __in short piSelStartCol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelText <-546> ( _                      ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSelText
   ' =====================================================================================
   PROPERTY SET SelText <-546> ( _                      ' VTable offset = 348
     BYVAL pbstrSelText AS WSTRING _                    ' __in BSTR pbstrSelText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Split <36> ( _                          ' VTable offset = 352
   ) AS INTEGER                                         ' __retval_out short *piSplit
   ' =====================================================================================
   PROPERTY SET Split <36> ( _                          ' VTable offset = 356
     BYVAL INTEGER _                                    ' __in short piSplit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabAcrossSplits <37> ( _                ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfTabAcrossSplits
   ' =====================================================================================
   PROPERTY SET TabAcrossSplits <37> ( _                ' VTable offset = 364
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfTabAcrossSplits
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabAction <38> ( _                      ' VTable offset = 368
   ) AS LONG                                            ' __retval_out TabActionConstants *penumTabAction
   ' =====================================================================================
   PROPERTY SET TabAction <38> ( _                      ' VTable offset = 372
     BYVAL LONG _                                       ' __in TabActionConstants penumTabAction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <0> ( _                            ' VTable offset = 376
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <0> ( _                            ' VTable offset = 380
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VisibleCols <39> ( _                    ' VTable offset = 384
   ) AS INTEGER                                         ' __retval_out short *piVisibleCols
   ' =====================================================================================
   PROPERTY GET VisibleRows <40> ( _                    ' VTable offset = 388
   ) AS INTEGER                                         ' __retval_out short *piVisibleRows
   ' =====================================================================================
   PROPERTY GET WrapCellPointer <41> ( _                ' VTable offset = 392
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfWrapCellPointer
   ' =====================================================================================
   PROPERTY SET WrapCellPointer <41> ( _                ' VTable offset = 396
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pfWrapCellPointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataFormats <44> ( _                    ' VTable offset = 400
   ) AS IStdDataFormatsDisp                             ' __retval_out IStdDataFormatsDisp **ppCollection
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 404
   )                                                    ' void
   ' =====================================================================================
   METHOD CaptureImage <101> ( _                        ' VTable offset = 408
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppCaptureImage
   ' =====================================================================================
   METHOD ClearSelCols <102> ( _                        ' VTable offset = 412
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearFields <103> ( _                         ' VTable offset = 416
   )                                                    ' void
   ' =====================================================================================
   METHOD ColContaining <104> ( _                       ' VTable offset = 420
     BYVAL SINGLE _                                     ' __in float X
   ) AS INTEGER                                         ' __retval_out short *piColContaining
   ' =====================================================================================
   PROPERTY GET Columns <105> ( _                       ' VTable offset = 424
   ) AS DataGrid_Columns                                ' __retval_out Columns **ppColumns
   ' =====================================================================================
   METHOD GetBookmark <106> ( _                         ' VTable offset = 428
     BYVAL LONG _                                       ' __in long RowNum
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBookmark
   ' =====================================================================================
   METHOD HoldFields <107> ( _                          ' VTable offset = 432
   )                                                    ' void
   ' =====================================================================================
   METHOD ReBind <108> ( _                              ' VTable offset = 436
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 440
   )                                                    ' void
   ' =====================================================================================
   METHOD RowBookmark <109> ( _                         ' VTable offset = 444
     BYVAL INTEGER _                                    ' __in short RowNum
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBookmark
   ' =====================================================================================
   METHOD RowContaining <110> ( _                       ' VTable offset = 448
     BYVAL SINGLE _                                     ' __in float Y
   ) AS INTEGER                                         ' __retval_out short *piRow
   ' =====================================================================================
   METHOD RowTop <111> ( _                              ' VTable offset = 452
     BYVAL INTEGER _                                    ' __in short RowNum
   ) AS SINGLE                                          ' __retval_out floot *psRowTop
   ' =====================================================================================
   METHOD Scroll <220> ( _                              ' VTable offset = 456
     BYVAL LONG _                                       ' __in long Cols
   , BYVAL LONG _                                       ' __in long Rows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelBookmarks <113> ( _                  ' VTable offset = 460
   ) AS DataGrid_SelBookmarks                           ' __retval_out SelBookmarks **ppSelBookmarks
   ' =====================================================================================
   METHOD SplitContaining <114> ( _                     ' VTable offset = 464
     BYVAL SINGLE _                                     ' __in float X
   , BYVAL SINGLE _                                     ' __in float Y
   ) AS INTEGER                                         ' __retval_out short *piSplit
   ' =====================================================================================
   PROPERTY GET Splits <115> ( _                        ' VTable offset = 468
   ) AS DataGrid_Splits                                 ' __retval_out Splits **ppSplits
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataGrid_INTERFACE_DEFINED__ */
