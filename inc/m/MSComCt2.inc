' ########################################################################################
' Microsoft Windows
' File: MSComCt2.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSComCtl2
' Version: 2.0, Locale ID = 0
' Description: Microsoft Windows Common Controls-2 6.0 (SP4)
' Path: C:\WINDOWS\system32\mscomct2.ocx
' Library GUID: {86CF1D34-0C5F-11D2-A9FC-0000F8754DA1}
' Help file: C:\WINDOWS\\HELP\cmctl298.chm
' License key: 651A8940-87C5-11d1-8BE3-0000F8754DA1
' ########################################################################################

#INCLUDE THIS ONCE
%MSCOMCT2_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vbinterf.inc"

$RTLKEY_MSCOMCT2 = "651A8940-87C5-11d1-8BE3-0000F8754DA1"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {B09DE715-87C1-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_Animation2 = "MSComCtl2.Animation.2"
' CLSID = {20DD1B9E-87C4-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_DTPicker2 = "MSComCtl2.DTPicker.2"
' CLSID = {FE38753A-44A3-11D1-B5B7-0000C09000C4}
$PROGID_MSComCtl2_FlatScrollBar2 = "MSComCtl2.FlatScrollBar.2"
' CLSID = {232E456A-87C3-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_MonthView2 = "MSComCtl2.MonthView.2"
' CLSID = {603C7E80-87C2-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_UpDown2 = "MSComCtl2.UpDown.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {B09DE715-87C1-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_Animation = "MSComCtl2.Animation"
' CLSID = {20DD1B9E-87C4-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_DTPicker = "MSComCtl2.DTPicker"
' CLSID = {FE38753A-44A3-11D1-B5B7-0000C09000C4}
$PROGID_MSComCtl2_FlatScrollBar = "MSComCtl2.FlatScrollBar"
' CLSID = {232E456A-87C3-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_MonthView = "MSComCtl2.MonthView"
' CLSID = {603C7E80-87C2-11D1-8BE3-0000F8754DA1}
$PROGID_MSComCtl2_UpDown = "MSComCtl2.UpDown"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSComCtl2_Animation = GUID$("{B09DE715-87C1-11D1-8BE3-0000F8754DA1}")
$CLSID_MSComCtl2_DTPicker = GUID$("{20DD1B9E-87C4-11D1-8BE3-0000F8754DA1}")
$CLSID_MSComCtl2_FlatScrollBar = GUID$("{FE38753A-44A3-11D1-B5B7-0000C09000C4}")
$CLSID_MSComCtl2_MonthView = GUID$("{232E456A-87C3-11D1-8BE3-0000F8754DA1}")
$CLSID_MSComCtl2_UpDown = GUID$("{603C7E80-87C2-11D1-8BE3-0000F8754DA1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_MSComCtl2_DAnimationEvents = GUID$("{B09DE714-87C1-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_DDTPickerEvents = GUID$("{20DD1B9D-87C4-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_DFlatSBEvents = GUID$("{FE387539-44A3-11D1-B5B7-0000C09000C4}")
$IID_MSComCtl2_DMonthViewEvents = GUID$("{232E4569-87C3-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_DUpDownEvents = GUID$("{603C7E7F-87C2-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_IAnimation = GUID$("{B09DE713-87C1-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_IDTPicker = GUID$("{20DD1B9B-87C4-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_IFlatSB = GUID$("{FE387538-44A3-11D1-B5B7-0000C09000C4}")
$IID_MSComCtl2_IMonthView = GUID$("{232E4565-87C3-11D1-8BE3-0000F8754DA1}")
$IID_MSComCtl2_IUpDown = GUID$("{603C7E7E-87C2-11D1-8BE3-0000F8754DA1}")

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%cc2OLEDropNone                                         = 0            ' &H0
%cc2OLEDropManual                                       = 1            ' &H1

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%cc2Enter                                               = 0            ' &H0
%cc2Leave                                               = 1            ' &H1
%cc2Over                                                = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%cc2CFText                                              = 1            ' &H1
%cc2CFBitmap                                            = 2            ' &H2
%cc2CFMetafile                                          = 3            ' &H3
%cc2CFDIB                                               = 8            ' &H8
%cc2CFPalette                                           = 9            ' &H9
%cc2CFEMetafile                                         = 14           ' &HE
%cc2CFFiles                                             = 15           ' &HF
%cc2CFRTF                                               = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%cc2OLEDropEffectNone                                   = 0            ' &H0
%cc2OLEDropEffectCopy                                   = 1            ' &H1
%cc2OLEDropEffectMove                                   = 2            ' &H2
%cc2OLEDropEffectScroll                                 = -2147483648  ' &H80000000

' ========================================================================================
' ErrorConstants enum
' IID: {79311D2C-87C0-11D1-8BE3-0000F8754DA1}
' Error Constants
' ========================================================================================

%cc2BadFileNameOrNumber                                 = 52           ' &H34
%cc2FileNotFound                                        = 53           ' &H35
%cc2InvalidPropertyValue                                = 380          ' &H17C
%cc2SetNotSupportedAtRuntime                            = 382          ' &H17E
%cc2SetNotSupported                                     = 383          ' &H17F
%cc2GetNotSupported                                     = 394          ' &H18A
%cc2DataObjectLocked                                    = 672          ' &H2A0
%cc2ExpectedAnArgument                                  = 673          ' &H2A1
%cc2InvalidProcedureCall                                = 5            ' &H5
%cc2InvalidObjectUse                                    = 425          ' &H1A9
%cc2WrongClipboardFormat                                = 461          ' &H1CD
%cc2RecursiveOleDrag                                    = 674          ' &H2A2
%cc2FormatNotByteArray                                  = 675          ' &H2A3
%cc2DataNotSetForFormat                                 = 676          ' &H2A4
%cc2InconsistentObject                                  = 35750        ' &H8BA6
%cc2ErrorDuringSet                                      = 35751        ' &H8BA7
%cc2ErrorOpeningVideo                                   = 35752        ' &H8BA8
%cc2ErrorPlayingVideo                                   = 35753        ' &H8BA9
%cc2VideoNotOpen                                        = 35755        ' &H8BAB
%cc2ErrorStoppingVideo                                  = 35757        ' &H8BAD
%cc2ErrorClosingVideo                                   = 35758        ' &H8BAE
%cc2CantStopAutoPlay                                    = 35759        ' &H8BAF
%cc2NoValidBuddyCtl                                     = 35754        ' &H8BAA
%cc2AutoBuddyNotSet                                     = 35756        ' &H8BAC
%cc2BuddyNotASibling                                    = 35760        ' &H8BB0
%cc2NoUpDownAsBuddy                                     = 35761        ' &H8BB1
%cc2InvalidRange                                        = 35770        ' &H8BBA
%cc2InvalidMaxDate                                      = 35771        ' &H8BBB
%cc2InvalidMinDate                                      = 35772        ' &H8BBC
%cc2DateOutOfRange                                      = 35773        ' &H8BBD
%cc2InvalidMaxDateMin                                   = 35774        ' &H8BBE
%cc2InvalidMinDateMax                                   = 35775        ' &H8BBF
%cc2InvalidRowColValue                                  = 35776        ' &H8BC0
%cc2InvalidRowColTotal                                  = 35777        ' &H8BC1
%cc2MonthViewError                                      = 35778        ' &H8BC2
%cc2SetDayMultiSelectOn                                 = 35779        ' &H8BC3
%cc2SetDayOfWeekMultiSelectOn                           = 35780        ' &H8BC4
%cc2SetMonthMultiSelectOn                               = 35781        ' &H8BC5
%cc2SetWeekMultiSelectOn                                = 35782        ' &H8BC6
%cc2SetYearMultiSelectOn                                = 35783        ' &H8BC7
%cc2SetMaxSelCountMultiSelectOff                        = 35784        ' &H8BC8
%cc2SetSelEndMultiSelectOff                             = 35785        ' &H8BC9
%cc2SetSelStartMultiSelectOff                           = 35786        ' &H8BCA
%cc2NullValueNotAllowed                                 = 35787        ' &H8BCB
%cc2DTPickerError                                       = 35788        ' &H8BCC
%cc2ScrollValueOutOfRange                               = 35789        ' &H8BCD

' ========================================================================================
' AppearanceConstants enum
' IID: {79311D2D-87C0-11D1-8BE3-0000F8754DA1}
' Appearance constants
' ========================================================================================

%cc2Flat                                                = 0            ' &H0
%cc23D                                                  = 1            ' &H1

' ========================================================================================
' BorderStyleConstants enum
' IID: {79311D2E-87C0-11D1-8BE3-0000F8754DA1}
' BorderStyle constants
' ========================================================================================

%cc2None                                                = 0            ' &H0
%cc2FixedSingle                                         = 1            ' &H1

' ========================================================================================
' MousePointerConstants enum
' IID: {79311D2F-87C0-11D1-8BE3-0000F8754DA1}
' MousePointer constants
' ========================================================================================

%cc2Default                                             = 0            ' &H0
%cc2Arrow                                               = 1            ' &H1
%cc2Cross                                               = 2            ' &H2
%cc2IBeam                                               = 3            ' &H3
%cc2Icon                                                = 4            ' &H4
%cc2Size                                                = 5            ' &H5
%cc2SizeNESW                                            = 6            ' &H6
%cc2SizeNS                                              = 7            ' &H7
%cc2SizeNWSE                                            = 8            ' &H8
%cc2SizeEW                                              = 9            ' &H9
%cc2UpArrow                                             = 10           ' &HA
%cc2Hourglass                                           = 11           ' &HB
%cc2NoDrop                                              = 12           ' &HC
%cc2ArrowHourglass                                      = 13           ' &HD
%cc2ArrowQuestion                                       = 14           ' &HE
%cc2SizeAll                                             = 15           ' &HF
%cc2Custom                                              = 99           ' &H63

' ========================================================================================
' OrientationConstants enum
' IID: {603C7E7D-87C2-11D1-8BE3-0000F8754DA1}
' Orientations
' ========================================================================================

%cc2OrientationVertical                                 = 0            ' &H0
%cc2OrientationHorizontal                               = 1            ' &H1

' ========================================================================================
' BackStyleConstants enum
' IID: {B09DE712-87C1-11D1-8BE3-0000F8754DA1}
' Background Style Constants
' ========================================================================================

%cc2BackstyleTransparent                                = 0            ' &H0
%cc2BackstyleOpaque                                     = 1            ' &H1

' ========================================================================================
' AlignmentConstants enum
' IID: {603C7E7C-87C2-11D1-8BE3-0000F8754DA1}
' Alignments
' ========================================================================================

%cc2AlignmentLeft                                       = 0            ' &H0
%cc2AlignmentRight                                      = 1            ' &H1

' ========================================================================================
' DayConstants enum
' IID: {232E4566-87C3-11D1-8BE3-0000F8754DA1}
' Day Constants
' ========================================================================================

%mvwSunday                                              = 1            ' &H1
%mvwMonday                                              = 2            ' &H2
%mvwTuesday                                             = 3            ' &H3
%mvwWednesday                                           = 4            ' &H4
%mvwThursday                                            = 5            ' &H5
%mvwFriday                                              = 6            ' &H6
%mvwSaturday                                            = 7            ' &H7

' ========================================================================================
' MonthConstants enum
' IID: {232E4567-87C3-11D1-8BE3-0000F8754DA1}
' Month Constants
' ========================================================================================

%mvwJanuary                                             = 1            ' &H1
%mvwFebruary                                            = 2            ' &H2
%mvwMarch                                               = 3            ' &H3
%mvwApril                                               = 4            ' &H4
%mvwMay                                                 = 5            ' &H5
%mvwJune                                                = 6            ' &H6
%mvwJuly                                                = 7            ' &H7
%mvwAugust                                              = 8            ' &H8
%mvwSeptember                                           = 9            ' &H9
%mvwOctober                                             = 10           ' &HA
%mvwNovember                                            = 11           ' &HB
%mvwDecember                                            = 12           ' &HC

' ========================================================================================
' MonthViewHitTestAreas enum
' IID: {232E4568-87C3-11D1-8BE3-0000F8754DA1}
' HitTest Constants
' ========================================================================================

%mvwCalendarBack                                        = 0            ' &H0
%mvwCalendarDate                                        = 1            ' &H1
%mvwCalendarDateNext                                    = 2            ' &H2
%mvwCalendarDatePrev                                    = 3            ' &H3
%mvwCalendarDay                                         = 4            ' &H4
%mvwCalendarWeekNum                                     = 5            ' &H5
%mvwNoWhere                                             = 6            ' &H6
%mvwTitleBack                                           = 7            ' &H7
%mvwTitleBtnNext                                        = 8            ' &H8
%mvwTitleBtnPrev                                        = 9            ' &H9
%mvwTitleMonth                                          = 10           ' &HA
%mvwTitleYear                                           = 11           ' &HB
%mvwTodayLink                                           = 12           ' &HC

' ========================================================================================
' FormatConstants enum
' IID: {20DD1B9C-87C4-11D1-8BE3-0000F8754DA1}
' Format Constants
' ========================================================================================

%dtpLongDate                                            = 0            ' &H0
%dtpShortDate                                           = 1            ' &H1
%dtpTime                                                = 2            ' &H2
%dtpCustom                                              = 3            ' &H3

' ========================================================================================
' FlatScrollBarAppearanceConstants enum
' IID: {FE387535-44A3-11D1-B5B7-0000C09000C4}
' Flat Scrollbar Appearance Constants
' ========================================================================================

%fsb3D                                                  = 0            ' &H0
%fsbFlat                                                = 1            ' &H1
%fsbTrack3D                                             = 2            ' &H2

' ========================================================================================
' ArrowsConstants enum
' IID: {FE387536-44A3-11D1-B5B7-0000C09000C4}
' Arrows Constants
' ========================================================================================

%cc2Both                                                = 0            ' &H0
%cc2LeftUp                                              = 1            ' &H1
%cc2RightDown                                           = 2            ' &H2

' ########################################################################################
' Interface name = IAnimation
' IID = {B09DE713-87C1-11D1-8BE3-0000F8754DA1}
' Animation Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl2_IAnimation_INTERFACE_DEFINED)
    %MSComCtl2_IAnimation_INTERFACE_DEFINED = 1

INTERFACE MSComCtl2_IAnimation $IID_MSComCtl2_IAnimation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET AutoPlay <1> ( _                        ' VTable offset = 28
     BYVAL pfAutoPlay AS INTEGER _                      ' __in VARIANT_BOOL pfAutoPlay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoPlay <1> ( _                        ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAutoPlay
   ' =====================================================================================
   PROPERTY SET BackStyle <2> ( _                       ' VTable offset = 36
     BYVAL penumBackStyle AS LONG _                     ' __in BackStyleConstants penumBackStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackStyle <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BackStyleConstants *penumBackStyle
   ' =====================================================================================
   PROPERTY SET Center <3> ( _                          ' VTable offset = 44
     BYVAL pfCenter AS INTEGER _                        ' __in VARIANT_BOOL pfCenter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Center <3> ( _                          ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCenter
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 52
     BYVAL pfEnable AS INTEGER _                        ' __in VARIANT_BOOL pfEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnable
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 64
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_HANDLE pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pocBackColor
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 72
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 76
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <4> ( _                                 ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <5> ( _                                  ' VTable offset = 84
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <6> ( _                                  ' VTable offset = 88
     OPTIONAL BYVAL varRepeatCount AS VARIANT _         ' __in_opt VARIANT varRepeatCount
   , OPTIONAL BYVAL varStartFrame AS VARIANT _          ' __in_opt VARIANT varStartFrame
   , OPTIONAL BYVAL varEndFrame AS VARIANT _            ' __in_opt VARIANT varEndFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <7> ( _                                  ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl2_IAnimation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUpDown
' IID = {603C7E7E-87C2-11D1-8BE3-0000F8754DA1}
' UpDown Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl2_IUpDown_INTERFACE_DEFINED)
    %MSComCtl2_IUpDown_INTERFACE_DEFINED = 1

INTERFACE MSComCtl2_IUpDown $IID_MSComCtl2_IUpDown

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 28
     BYVAL plValue AS LONG _                            ' __in long plValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY SET Acceleration <1> ( _                    ' VTable offset = 36
     BYVAL psAcceleration AS INTEGER _                  ' __in short psAcceleration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Acceleration <1> ( _                    ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *psAcceleration
   ' =====================================================================================
   PROPERTY SET Alignment <2> ( _                       ' VTable offset = 44
     BYVAL penumAlignment AS LONG _                     ' __in AlignmentConstants penumAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Alignment <2> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out AlignmentConstants *penumAlignment
   ' =====================================================================================
   PROPERTY SET AutoBuddy <3> ( _                       ' VTable offset = 52
     BYVAL pfAutoBuddy AS INTEGER _                     ' __in VARIANT_BOOL pfAutoBuddy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoBuddy <3> ( _                       ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAutoBuddy
   ' =====================================================================================
   PROPERTY SET BuddyControl <4> ( _                    ' VTable offset = 60
     BYVAL pvarBuddyCtl AS VARIANT _                    ' __in VARIANT pvarBuddyCtl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_BuddyControl <4> ( _             ' VTable offset = 64
     BYVAL pvarBuddyCtl AS VARIANT _                    ' __in VARIANT pvarBuddyCtl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BuddyControl <4> ( _                    ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBuddyCtl
   ' =====================================================================================
   PROPERTY SET Increment <5> ( _                       ' VTable offset = 72
     BYVAL plIncrement AS LONG _                        ' __in long plIncrement
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Increment <5> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plIncrement
   ' =====================================================================================
   PROPERTY SET Max <6> ( _                             ' VTable offset = 80
     BYVAL plMax AS LONG _                              ' __in long plMax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Max <6> ( _                             ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plMax
   ' =====================================================================================
   PROPERTY SET Min <7> ( _                             ' VTable offset = 88
     BYVAL plMin AS LONG _                              ' __in long plMin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Min <7> ( _                             ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plMin
   ' =====================================================================================
   PROPERTY SET Orientation <8> ( _                     ' VTable offset = 96
     BYVAL penumOrientation AS LONG _                   ' __in OrientationConstants penumOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <8> ( _                     ' VTable offset = 100
   ) AS LONG                                            ' __retval_out OrientationConstants *penumOrientation
   ' =====================================================================================
   PROPERTY SET SyncBuddy <9> ( _                       ' VTable offset = 104
     BYVAL pfSyncBuddy AS INTEGER _                     ' __in VARIANT_BOOL pfSyncBuddy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SyncBuddy <9> ( _                       ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSyncBuddy
   ' =====================================================================================
   PROPERTY SET Wrap <10> ( _                           ' VTable offset = 112
     BYVAL pfWrap AS INTEGER _                          ' __in VARIANT_BOOL pfWrap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Wrap <10> ( _                           ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfWrap
   ' =====================================================================================
   PROPERTY SET BuddyProperty <11> ( _                  ' VTable offset = 120
     BYVAL pvarDispidBuddyProperty AS VARIANT _         ' __in VARIANT pvarDispidBuddyProperty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BuddyProperty <11> ( _                  ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDispidBuddyProperty
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 128
     BYVAL pfEnable AS INTEGER _                        ' __in VARIANT_BOOL pfEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnable
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 136
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 140
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 144
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl2_IUpDown_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMonthView
' IID = {232E4565-87C3-11D1-8BE3-0000F8754DA1}
' Microsoft MonthView Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl2_IMonthView_INTERFACE_DEFINED)
    %MSComCtl2_IMonthView_INTERFACE_DEFINED = 1

INTERFACE MSComCtl2_IMonthView $IID_MSComCtl2_IMonthView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out AppearanceConstants *penumAppearances
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 32
     BYVAL penumAppearances AS LONG _                   ' __in AppearanceConstants penumAppearances
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 40
     BYVAL pclrBackColor AS DWORD _                     ' __in OLE_COLOR pclrBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out BorderStyleConstants *psBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 48
     BYVAL psBorderStyle AS LONG _                      ' __in BorderStyleConstants psBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Day <1> ( _                             ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short *psDay
   ' =====================================================================================
   PROPERTY SET Day <1> ( _                             ' VTable offset = 56
     BYVAL psDay AS INTEGER _                           ' __in short psDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayBold <2> ( _                         ' VTable offset = 60
     BYVAL dateIndex AS DOUBLE _                        ' __in DATE dateIndex
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDayBold
   ' =====================================================================================
   PROPERTY SET DayBold <2> ( _                         ' VTable offset = 64
     BYVAL dateIndex AS DOUBLE _                        ' __in DATE dateIndex
   , BYVAL pbDayBold AS INTEGER _                       ' __in VARIANT_BOOL pbDayBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayOfWeek <3> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out DayConstants *penumDayOfWeek
   ' =====================================================================================
   PROPERTY SET DayOfWeek <3> ( _                       ' VTable offset = 72
     BYVAL penumDayOfWeek AS LONG _                     ' __in DayConstants penumDayOfWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 80
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 84
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 88
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 92
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 96
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 100
     BYVAL pclrForeColor AS DWORD _                     ' __in OLE_COLOR pclrForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 104
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 108
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxDate <4> ( _                         ' VTable offset = 112
   ) AS DOUBLE                                          ' __retval_out DATE *pdateMaxDate
   ' =====================================================================================
   PROPERTY SET MaxDate <4> ( _                         ' VTable offset = 116
     BYVAL pdateMaxDate AS DOUBLE _                     ' __in DATE pdateMaxDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxSelCount <5> ( _                     ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out short *psMaxSelCount
   ' =====================================================================================
   PROPERTY SET MaxSelCount <5> ( _                     ' VTable offset = 124
     BYVAL psMaxSelCount AS INTEGER _                   ' __in short psMaxSelCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinDate <6> ( _                         ' VTable offset = 128
   ) AS DOUBLE                                          ' __retval_out DATE *pdateMinDate
   ' =====================================================================================
   PROPERTY SET MinDate <6> ( _                         ' VTable offset = 132
     BYVAL pdateMinDate AS DOUBLE _                     ' __in DATE pdateMinDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Month <7> ( _                           ' VTable offset = 136
   ) AS LONG                                            ' __retval_out MonthConstants *psMonth
   ' =====================================================================================
   PROPERTY SET Month <7> ( _                           ' VTable offset = 140
     BYVAL psMonth AS LONG _                            ' __in MonthConstants psMonth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthBackColor <8> ( _                  ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrMonthBackColor
   ' =====================================================================================
   PROPERTY SET MonthBackColor <8> ( _                  ' VTable offset = 148
     BYVAL pclrMonthBackColor AS DWORD _                ' __in OLE_COLOR pclrMonthBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthColumns <9> ( _                    ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out short *psMonthColumns
   ' =====================================================================================
   PROPERTY SET MonthColumns <9> ( _                    ' VTable offset = 156
     BYVAL psMonthColumns AS INTEGER _                  ' __in short psMonthColumns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthRows <10> ( _                      ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out short *psMonthRows
   ' =====================================================================================
   PROPERTY SET MonthRows <10> ( _                      ' VTable offset = 164
     BYVAL psMonthRows AS INTEGER _                     ' __in short psMonthRows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <11> ( _                      ' VTable offset = 168
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <11> ( _                      ' VTable offset = 172
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <11> ( _               ' VTable offset = 176
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <12> ( _                   ' VTable offset = 180
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <12> ( _                   ' VTable offset = 184
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiSelect <13> ( _                    ' VTable offset = 188
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMultiSelect
   ' =====================================================================================
   PROPERTY SET MultiSelect <13> ( _                    ' VTable offset = 192
     BYVAL pbMultiSelect AS INTEGER _                   ' __in VARIANT_BOOL pbMultiSelect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 196
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 200
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollRate <14> ( _                     ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out short *psScrollRate
   ' =====================================================================================
   PROPERTY SET ScrollRate <14> ( _                     ' VTable offset = 208
     BYVAL psScrollRate AS INTEGER _                    ' __in short psScrollRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelEnd <15> ( _                         ' VTable offset = 212
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSelEnd
   ' =====================================================================================
   PROPERTY SET SelEnd <15> ( _                         ' VTable offset = 216
     BYVAL pdateSelEnd AS DOUBLE _                      ' __in DATE pdateSelEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <16> ( _                       ' VTable offset = 220
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <16> ( _                       ' VTable offset = 224
     BYVAL pdateSelStart AS DOUBLE _                    ' __in DATE pdateSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowToday <17> ( _                      ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowToday
   ' =====================================================================================
   PROPERTY SET ShowToday <17> ( _                      ' VTable offset = 232
     BYVAL pbShowToday AS INTEGER _                     ' __in VARIANT_BOOL pbShowToday
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowWeekNumbers <18> ( _                ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowWeekNumbers
   ' =====================================================================================
   PROPERTY SET ShowWeekNumbers <18> ( _                ' VTable offset = 240
     BYVAL pbShowWeekNumbers AS INTEGER _               ' __in VARIANT_BOOL pbShowWeekNumbers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartOfWeek <19> ( _                    ' VTable offset = 244
   ) AS LONG                                            ' __retval_out DayConstants *penumStartOfWeek
   ' =====================================================================================
   PROPERTY SET StartOfWeek <19> ( _                    ' VTable offset = 248
     BYVAL penumStartOfWeek AS LONG _                   ' __in DayConstants penumStartOfWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleBackColor <20> ( _                 ' VTable offset = 252
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTitleBackColor
   ' =====================================================================================
   PROPERTY SET TitleBackColor <20> ( _                 ' VTable offset = 256
     BYVAL pclrTitleBackColor AS DWORD _                ' __in OLE_COLOR pclrTitleBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleForeColor <21> ( _                 ' VTable offset = 260
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTitleForeColor
   ' =====================================================================================
   PROPERTY SET TitleForeColor <21> ( _                 ' VTable offset = 264
     BYVAL pclrTitleForeColor AS DWORD _                ' __in OLE_COLOR pclrTitleForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TrailingForeColor <22> ( _              ' VTable offset = 268
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTrailingForeColor
   ' =====================================================================================
   PROPERTY SET TrailingForeColor <22> ( _              ' VTable offset = 272
     BYVAL pclrTrailingForeColor AS DWORD _             ' __in OLE_COLOR pclrTrailingForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <23> ( _                          ' VTable offset = 276
   ) AS DOUBLE                                          ' __retval_out DATE *pdateValue
   ' =====================================================================================
   PROPERTY SET Value <23> ( _                          ' VTable offset = 280
     BYVAL pdateValue AS DOUBLE _                       ' __in DATE pdateValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value_ <0> ( _                          ' VTable offset = 284
   ) AS DOUBLE                                          ' __retval_out DATE *pdateValue
   ' =====================================================================================
   PROPERTY SET Value_ <0> ( _                          ' VTable offset = 288
     BYVAL pdateValue AS DOUBLE _                       ' __in DATE pdateValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VisibleDays <24> ( _                    ' VTable offset = 292
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   ) AS DOUBLE                                          ' __retval_out DATE *pdateVisibleDays
   ' =====================================================================================
   PROPERTY SET VisibleDays <24> ( _                    ' VTable offset = 296
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   , BYVAL pdateVisibleDays AS DOUBLE _                 ' __in DATE pdateVisibleDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Week <25> ( _                           ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out short *psWeek
   ' =====================================================================================
   PROPERTY SET Week <25> ( _                           ' VTable offset = 304
     BYVAL psWeek AS INTEGER _                          ' __in short psWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Year <26> ( _                           ' VTable offset = 308
   ) AS INTEGER                                         ' __retval_out short *psYear
   ' =====================================================================================
   PROPERTY SET Year <26> ( _                           ' VTable offset = 312
     BYVAL psYear AS INTEGER _                          ' __in short psYear
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 316
   )                                                    ' void
   ' =====================================================================================
   METHOD ComputeControlSize <28> ( _                   ' VTable offset = 320
     BYVAL Rows AS INTEGER _                            ' __in short Rows
   , BYVAL Columns AS INTEGER _                         ' __in short Columns
   , BYREF Width AS SINGLE _                            ' __out float *Width
   , BYREF Height AS SINGLE _                           ' __out float *Height
   )                                                    ' void
   ' =====================================================================================
   METHOD HitTest <27> ( _                              ' VTable offset = 324
     BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYREF Date AS DOUBLE _                             ' __out DATE *Date
   ) AS LONG                                            ' __retval_out MonthViewHitTestAreas *enumHitTestArea
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 328
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 332
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl2_IMonthView_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTPicker
' IID = {20DD1B9B-87C4-11D1-8BE3-0000F8754DA1}
' Microsoft Date and Time Picker Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl2_IDTPicker_INTERFACE_DEFINED)
    %MSComCtl2_IDTPicker_INTERFACE_DEFINED = 1

INTERFACE MSComCtl2_IDTPicker $IID_MSComCtl2_IDTPicker

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Format <10> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out FormatConstants *penumFormat
   ' =====================================================================================
   PROPERTY SET Format <10> ( _                         ' VTable offset = 32
     BYVAL penumFormat AS LONG _                        ' __in FormatConstants penumFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CalendarBackColor <1> ( _               ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrCalendarBackColor
   ' =====================================================================================
   PROPERTY SET CalendarBackColor <1> ( _               ' VTable offset = 40
     BYVAL pclrCalendarBackColor AS DWORD _             ' __in OLE_COLOR pclrCalendarBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CalendarForeColor <2> ( _               ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrCalendarForeColor
   ' =====================================================================================
   PROPERTY SET CalendarForeColor <2> ( _               ' VTable offset = 48
     BYVAL pclrCalendarForeColor AS DWORD _             ' __in OLE_COLOR pclrCalendarForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CalendarTitleBackColor <3> ( _          ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTitleBackColor
   ' =====================================================================================
   PROPERTY SET CalendarTitleBackColor <3> ( _          ' VTable offset = 56
     BYVAL pclrTitleBackColor AS DWORD _                ' __in OLE_COLOR pclrTitleBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CalendarTitleForeColor <4> ( _          ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTitleForeColor
   ' =====================================================================================
   PROPERTY SET CalendarTitleForeColor <4> ( _          ' VTable offset = 64
     BYVAL pclrTitleForeColor AS DWORD _                ' __in OLE_COLOR pclrTitleForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CalendarTrailingForeColor <5> ( _       ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrTrailingForeColor
   ' =====================================================================================
   PROPERTY SET CalendarTrailingForeColor <5> ( _       ' VTable offset = 72
     BYVAL pclrTrailingForeColor AS DWORD _             ' __in OLE_COLOR pclrTrailingForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckBox <6> ( _                        ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET CheckBox <6> ( _                        ' VTable offset = 80
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomFormat <7> ( _                    ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCustomFormat
   ' =====================================================================================
   PROPERTY SET CustomFormat <7> ( _                    ' VTable offset = 88
     BYVAL pbstrCustomFormat AS WSTRING _               ' __in BSTR pbstrCustomFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Day <8> ( _                             ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *pvDay
   ' =====================================================================================
   PROPERTY SET Day <8> ( _                             ' VTable offset = 96
     BYVAL pvDay AS VARIANT _                           ' __in VARIANT pvDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayOfWeek <9> ( _                       ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvDayOfWeek
   ' =====================================================================================
   PROPERTY SET DayOfWeek <9> ( _                       ' VTable offset = 104
     BYVAL pvDayOfWeek AS VARIANT _                     ' __in VARIANT pvDayOfWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 112
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 116
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET Font <-512> ( _                         ' VTable offset = 120
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 124
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hour <11> ( _                           ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT *pvHour
   ' =====================================================================================
   PROPERTY SET Hour <11> ( _                           ' VTable offset = 132
     BYVAL pvHour AS VARIANT _                          ' __in VARIANT pvHour
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 136
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 140
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxDate <12> ( _                        ' VTable offset = 144
   ) AS DOUBLE                                          ' __retval_out DATE *pdateMaxDate
   ' =====================================================================================
   PROPERTY SET MaxDate <12> ( _                        ' VTable offset = 148
     BYVAL pdateMaxDate AS DOUBLE _                     ' __in DATE pdateMaxDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinDate <13> ( _                        ' VTable offset = 152
   ) AS DOUBLE                                          ' __retval_out DATE *pdateMinDate
   ' =====================================================================================
   PROPERTY SET MinDate <13> ( _                        ' VTable offset = 156
     BYVAL pdateMinDate AS DOUBLE _                     ' __in DATE pdateMinDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Minute <14> ( _                         ' VTable offset = 160
   ) AS VARIANT                                         ' __retval_out VARIANT *pvMinute
   ' =====================================================================================
   PROPERTY SET Minute <14> ( _                         ' VTable offset = 164
     BYVAL pvMinute AS VARIANT _                        ' __in VARIANT pvMinute
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Month <15> ( _                          ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *pvMonth
   ' =====================================================================================
   PROPERTY SET Month <15> ( _                          ' VTable offset = 172
     BYVAL pvMonth AS VARIANT _                         ' __in VARIANT pvMonth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <16> ( _                      ' VTable offset = 176
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <16> ( _                      ' VTable offset = 180
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <16> ( _               ' VTable offset = 184
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <17> ( _                   ' VTable offset = 188
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <17> ( _                   ' VTable offset = 192
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 196
   ) AS LONG                                            ' __retval_out OLEDropConstants *psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 200
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Second <18> ( _                         ' VTable offset = 204
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSecond
   ' =====================================================================================
   PROPERTY SET Second <18> ( _                         ' VTable offset = 208
     BYVAL pvSecond AS VARIANT _                        ' __in VARIANT pvSecond
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpDown <19> ( _                         ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUpDown
   ' =====================================================================================
   PROPERTY SET UpDown <19> ( _                         ' VTable offset = 216
     BYVAL pbUpDown AS INTEGER _                        ' __in VARIANT_BOOL pbUpDown
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <20> ( _                          ' VTable offset = 220
   ) AS VARIANT                                         ' __retval_out VARIANT *pvdateValue
   ' =====================================================================================
   PROPERTY SET Value <20> ( _                          ' VTable offset = 224
     BYVAL pvdateValue AS VARIANT _                     ' __in VARIANT pvdateValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value_ <0> ( _                          ' VTable offset = 228
   ) AS VARIANT                                         ' __retval_out VARIANT *pvdateValue
   ' =====================================================================================
   PROPERTY SET Value_ <0> ( _                          ' VTable offset = 232
     BYVAL pvdateValue AS VARIANT _                     ' __in VARIANT pvdateValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Year <21> ( _                           ' VTable offset = 236
   ) AS VARIANT                                         ' __retval_out VARIANT *pvYear
   ' =====================================================================================
   PROPERTY SET Year <21> ( _                           ' VTable offset = 240
     BYVAL pvYear AS VARIANT _                          ' __in VARIANT pvYear
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl2_IDTPicker_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFlatSB
' IID = {FE387538-44A3-11D1-B5B7-0000C09000C4}
' Microsoft Flat Scrollbar Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSComCtl2_IFlatSB_INTERFACE_DEFINED)
    %MSComCtl2_IFlatSB_INTERFACE_DEFINED = 1

INTERFACE MSComCtl2_IFlatSB $IID_MSComCtl2_IFlatSB

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Appearance <1> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out FlatScrollBarAppearanceConstants *penumAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <1> ( _                      ' VTable offset = 32
     BYVAL penumAppearance AS LONG _                    ' __in FlatScrollBarAppearanceConstants penumAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Arrows <2> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out ArrowsConstants *penumArrows
   ' =====================================================================================
   PROPERTY SET Arrows <2> ( _                          ' VTable offset = 40
     BYVAL penumArrows AS LONG _                        ' __in ArrowsConstants penumArrows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 48
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out OLE_HANDLE *phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 56
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LargeChange <3> ( _                     ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *psLargeChange
   ' =====================================================================================
   PROPERTY SET LargeChange <3> ( _                     ' VTable offset = 64
     BYVAL psLargeChange AS INTEGER _                   ' __in short psLargeChange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Min <4> ( _                             ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *psMin
   ' =====================================================================================
   PROPERTY SET Min <4> ( _                             ' VTable offset = 72
     BYVAL psMin AS INTEGER _                           ' __in short psMin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Max <5> ( _                             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short *psMax
   ' =====================================================================================
   PROPERTY SET Max <5> ( _                             ' VTable offset = 80
     BYVAL psMax AS INTEGER _                           ' __in short psMax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <6> ( _                       ' VTable offset = 84
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <6> ( _                       ' VTable offset = 88
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <6> ( _                ' VTable offset = 92
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp *ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <7> ( _                    ' VTable offset = 96
   ) AS LONG                                            ' __retval_out MousePointerConstants *psMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <7> ( _                    ' VTable offset = 100
     BYVAL psMousePointer AS LONG _                     ' __in MousePointerConstants psMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <8> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out OrientationConstants *penumOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <8> ( _                     ' VTable offset = 108
     BYVAL penumOrientation AS LONG _                   ' __in OrientationConstants penumOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmallChange <9> ( _                     ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out short *psSmallChange
   ' =====================================================================================
   PROPERTY SET SmallChange <9> ( _                     ' VTable offset = 116
     BYVAL psSmallChange AS INTEGER _                   ' __in short psSmallChange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <10> ( _                          ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out short *psValue
   ' =====================================================================================
   PROPERTY SET Value <10> ( _                          ' VTable offset = 124
     BYVAL psValue AS INTEGER _                         ' __in short psValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value_ <0> ( _                          ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *psValue
   ' =====================================================================================
   PROPERTY SET Value_ <0> ( _                          ' VTable offset = 132
     BYVAL psValue AS INTEGER _                         ' __in short psValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSComCtl2_IFlatSB_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDAnimationEvents
' Interface name = DAnimationEvents
' IID = {B09DE714-87C1-11D1-8BE3-0000F8754DA1}
' Event interface for Animation control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDAnimationEvents GUID$("{F9233F2A-BC26-4007-9BCB-358FD5080DEE}") AS EVENT

'INTERFACE DAnimationEventsImpl GUID$("{B09DE714-87C1-11D1-8BE3-0000F8754DA1}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF AllowedEffects AS LONG _                     ' __inout long *AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF DefaultCursors AS INTEGER _                  ' __inout VARIANT_BOOL *DefaultCursors
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF DataFormat AS INTEGER _                      ' __inout short *DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __inout long *Effect
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short *Button
'   , BYREF iShift AS INTEGER _                          ' __inout short *Shift
'   , BYREF x AS SINGLE _                                ' __inout float *x
'   , BYREF y AS SINGLE _                                ' __inout float *y
'   , BYREF iState AS INTEGER _                          ' __inout short *State
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short *Button
'   , BYREF iShift AS INTEGER _                          ' __inout short *Shift
'   , BYREF x AS SINGLE _                                ' __inout float *x
'   , BYREF y AS SINGLE _                                ' __inout float *y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDDTPickerEvents
' Interface name = DDTPickerEvents
' IID = {20DD1B9D-87C4-11D1-8BE3-0000F8754DA1}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDDTPickerEvents GUID$("{0D4147F9-6B2E-4180-ACA7-DEE1A598E2C5}") AS EVENT

'INTERFACE DDTPickerEventsImpl GUID$("{20DD1B9D-87C4-11D1-8BE3-0000F8754DA1}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD CallbackKeyDown <1> ( _
'     BYVAL KeyCode AS INTEGER _                         ' __in short KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL CallbackField AS WSTRING _                   ' __in BSTR CallbackField
'   , BYREF CallbackDate AS DOUBLE _                     ' __inout DATE *CallbackDate
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Change <2>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CloseUp <3>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DropDown <4>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Format <5> ( _
'     BYVAL CallbackField AS WSTRING _                   ' __in BSTR CallbackField
'   , BYREF FormattedString AS WSTRING _                 ' __out BSTR *FormattedString
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FormatSize <6> ( _
'     BYVAL CallbackField AS WSTRING _                   ' __in BSTR CallbackField
'   , BYREF iSize AS INTEGER _                           ' __out short *Size
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' __inout short *KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' __inout short *KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' __inout short *KeyAscii
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
'   , BYVAL y AS LONG _                                  ' __in OLE_XPOS_PIXELS y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF AllowedEffects AS LONG _                     ' __inout long *AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF DefaultCursors AS INTEGER _                  ' __inout VARIANT_BOOL *DefaultCursors
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF DataFormat AS INTEGER _                      ' __inout short *DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __inout long *Effect
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short *Button
'   , BYREF iShift AS INTEGER _                          ' __inout short *Shift
'   , BYREF x AS SINGLE _                                ' __inout float *x
'   , BYREF y AS SINGLE _                                ' __inout float *y
'   , BYREF iState AS INTEGER _                          ' __inout short *State
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject **Data
'   , BYREF Effect AS LONG _                             ' __inout long *Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short *Button
'   , BYREF iShift AS INTEGER _                          ' __inout short *Shift
'   , BYREF x AS SINGLE _                                ' __inout float *x
'   , BYREF y AS SINGLE _                                ' __inout float *y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS


' ########################################################################################
' Class CDMonthViewEvents
' Interface name = DMonthViewEvents
' IID = {232E4569-87C3-11D1-8BE3-0000F8754DA1}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDMonthViewEvents GUID$("{9F1994AC-39EB-4F7E-90B7-205B285F840F}") AS EVENT

'INTERFACE DMonthViewEventsImpl GUID$("{232E4569-87C3-11D1-8BE3-0000F8754DA1}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD DateClick <1> ( _
'     BYVAL DateClicked AS DOUBLE _                      ' __in DATE DateClicked
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DateDblClick <2> ( _
'     BYVAL DateDblClicked AS DOUBLE _                   ' __in DATE DateDblClicked
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD GetDayBold <3> ( _
'     BYVAL StartDate AS DOUBLE _                        ' __in DATE StartDate
'   , BYVAL iCount AS INTEGER _                          ' __in short Count
'   , BYREF pState AS DWORD _                            ' __in_out SAFEARRAY *State
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SelChange <4> ( _
'     BYVAL StartDate AS DOUBLE _                        ' __in DATE StartDate
'   , BYVAL EndDate AS DOUBLE _                          ' __in DATE EndDate
'   , BYREF iCancel AS INTEGER _                         ' __out VARIANT_BOOL* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$
'     ' Sample code
''     LOCAL hCtrl AS DWORD
''     hCtrl = GetFocus
''     MSGBOX "DblClick"
''     SetFocus hCtrl

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' __inout short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in    short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' __inout short* KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in    short  Shift
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' __inout short* KeyAscii
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

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
'     OutputDebugString FUNCNAME$

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
'     OutputDebugString FUNCNAME$

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
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject** Data
'   , BYREF AllowedEffects AS LONG _                     ' __inout long *AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __inout long* Effect
'   , BYREF DefaultCursors AS INTEGER _                  ' __inout VARIANT_BOOL* DefaultCursors
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject** Data
'   , BYREF DataFormat AS INTEGER _                      ' __inout short *DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __inout long *Effect
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject** Data
'   , BYREF Effect AS LONG _                             ' __inout long* Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short* Button
'   , BYREF iShift AS INTEGER _                          ' __inout short* Shift
'   , BYREF x AS SINGLE _                                ' __inout float* x
'   , BYREF y AS SINGLE _                                ' __inout float* y
'   , BYREF iState AS INTEGER _                          ' __inout short* State
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __inout DataObject** Data
'   , BYREF Effect AS LONG _                             ' __inout long* Effect
'   , BYREF iButton AS INTEGER _                         ' __inout short* Button
'   , BYREF iShift AS INTEGER _                          ' __inout short* Shift
'   , BYREF x AS SINGLE _                                ' __inout float* x
'   , BYREF y AS SINGLE _                                ' __inout float* y
'   )                                                    ' void

'     ' *** Insert your code here ***
'     OutputDebugString FUNCNAME$

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
'' ========================================================================================
