' ########################################################################################
' Microsoft Windows
' File: MCI32.inc
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MCI
' Version: 1.1, Locale ID = 0
' Documentation string: Microsoft Multimedia Control 6.0
' Path: C:\WINDOWS\system32\MCI32.OCX
' Library GUID: {C1A8AF28-1257-101B-8FB0-0020AF039CA3}
' Help file: C:\WINDOWS\HELP\MMEDIA98.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%MCI32_INC = 1

#INCLUDE ONCE "ocidl.inc"

$RTLKEY_MMControl = "B1EFCCF0-6AC1-11cf-8ADB-00AA00C00905"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MMControl = GUID$("{C1A8AF25-1257-101B-8FB0-0020AF039CA3}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_MMControl1 = "MCI.MMControl.1"

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DmciEvents = GUID$("{C1A8AF27-1257-101B-8FB0-0020AF039CA3}")
$IID_Imci = GUID$("{B7ABC220-DF71-11CF-8E74-00A0C90F26F8}")

' ========================================================================================
' ErrorConstants enum
' IID: {3BD44960-C350-11CF-9D77-524153480000}
' Control's run-time errors
' ========================================================================================

%mciInvalidPropertyValue                                = 380          ' &H17C
%mciGetNotSupported                                     = 394          ' &H18A
%mciSetNotSupported                                     = 383          ' &H17F
%mciInvalidProcedureCall                                = 5            ' &H5
%mciInvalidObjectUse                                    = 425          ' &H1A9
%mciWrongClipboardFormat                                = 461          ' &H1CD
%mciDataObjectLocked                                    = 672          ' &H2A0
%mciExpectedAnArgument                                  = 673          ' &H2A1
%mciRecursiveOleDrag                                    = 674          ' &H2A2
%mciFormatNotByteArray                                  = 675          ' &H2A3
%mciDataNotSetForFormat                                 = 676          ' &H2A4
%mciCantCreateButton                                    = 30001        ' &H7531
%mciCantCreateTimer                                     = 30002        ' &H7532
%mciUnsupportedFunction                                 = 30004        ' &H7534

' ========================================================================================
' BorderStyleConstants enum
' IID: {C1A8AF36-1257-101B-8FB0-0020AF039CA3}
' BorderStyle constants.
' ========================================================================================

%mciNone                                                = 0            ' &H0
%mciFixedSingle                                         = 1            ' &H1

' ========================================================================================
' RecordModeConstants enum
' IID: {C1A8AF37-1257-101B-8FB0-0020AF039CA3}
' RecordMode constants.
' ========================================================================================

%mciRecordInsert                                        = 0            ' &H0
%mciRecordOverwrite                                     = 1            ' &H1

' ========================================================================================
' MousePointerConstants enum
' IID: {C1A8AF38-1257-101B-8FB0-0020AF039CA3}
' MousePointer constants.
' ========================================================================================

%mciDefault                                             = 0            ' &H0
%mciArrow                                               = 1            ' &H1
%mciCross                                               = 2            ' &H2
%mciIBeam                                               = 3            ' &H3
%mciIcon                                                = 4            ' &H4
%mciSize                                                = 5            ' &H5
%mciSizeNESW                                            = 6            ' &H6
%mciSizeNS                                              = 7            ' &H7
%mciSizeNWSE                                            = 8            ' &H8
%mciSizeEW                                              = 9            ' &H9
%mciUpArrow                                             = 10           ' &HA
%mciHourglass                                           = 11           ' &HB
%mciNoDrop                                              = 12           ' &HC
%mciArrowHourglass                                      = 13           ' &HD
%mciArrowQuestion                                       = 14           ' &HE
%mciSizeAll                                             = 15           ' &HF
%mciCustom                                              = 99           ' &H63

' ========================================================================================
' ModeConstants enum
' IID: {C1A8AF39-1257-101B-8FB0-0020AF039CA3}
' Mode constants.
' ========================================================================================

%mciModeNotOpen                                         = 524          ' &H20C
%mciModeStop                                            = 525          ' &H20D
%mciModePlay                                            = 526          ' &H20E
%mciModeRecord                                          = 527          ' &H20F
%mciModeSeek                                            = 528          ' &H210
%mciModePause                                           = 529          ' &H211
%mciModeReady                                           = 530          ' &H212

' ========================================================================================
' NotifyConstants enum
' IID: {C1A8AF40-1257-101B-8FB0-0020AF039CA3}
' Notify constants.
' ========================================================================================

%mciNotifySuccessful                                    = 1            ' &H1
%mciNotifySuperseded                                    = 2            ' &H2
%mciAborted                                             = 4            ' &H4
%mciFailure                                             = 8            ' &H8

' ========================================================================================
' OrientationConstants enum
' IID: {C1A8AF41-1257-101B-8FB0-0020AF039CA3}
' Orientation constants.
' ========================================================================================

%mciOrientHorz                                          = 0            ' &H0
%mciOrientVert                                          = 1            ' &H1

' ========================================================================================
' FormatConstants enum
' IID: {C1A8AF42-1257-101B-8FB0-0020AF039CA3}
' Constants for TimeFormat Property
' ========================================================================================

%mciFormatMilliseconds                                  = 0            ' &H0
%mciFormatHms                                           = 1            ' &H1
%mciFormatMsf                                           = 2            ' &H2
%mciFormatFrames                                        = 3            ' &H3
%mciFormatSmpte24                                       = 4            ' &H4
%mciFormatSmpte25                                       = 5            ' &H5
%mciFormatSmpte30                                       = 6            ' &H6
%mciFormatSmpte30Drop                                   = 7            ' &H7
%mciFormatBytes                                         = 8            ' &H8
%mciFormatSamples                                       = 9            ' &H9
%mciFormatTmsf                                          = 10           ' &HA

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%mciOLEDropNone                                         = 0            ' &H0
%mciOLEDropManual                                       = 1            ' &H1

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%mciEnter                                               = 0            ' &H0
%mciLeave                                               = 1            ' &H1
%mciOver                                                = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%mciCFText                                              = 1            ' &H1
%mciCFBitmap                                            = 2            ' &H2
%mciCFMetafile                                          = 3            ' &H3
%mciCFDIB                                               = 8            ' &H8
%mciCFPalette                                           = 9            ' &H9
%mciCFEMetafile                                         = 14           ' &HE
%mciCFFiles                                             = 15           ' &HF
%mciCFRTF                                               = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%mciOLEDropEffectNone                                   = 0            ' &H0
%mciOLEDropEffectCopy                                   = 1            ' &H1
%mciOLEDropEffectMove                                   = 2            ' &H2
%mciOLEDropEffectScroll                                 = -2147483648  ' &H80000000

' ########################################################################################
' Interface name = Imci
' IID = {B7ABC220-DF71-11CF-8E74-00A0C90F26F8}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%Imci_INTERFACE_DEFINED)
    %Imci_INTERFACE_DEFINED = 1

INTERFACE Imci $IID_Imci

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceType <21> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrType
   ' =====================================================================================
   PROPERTY SET DeviceType <21> ( _                     ' VTable offset = 32
     BYVAL pbstrType AS WSTRING _                       ' __in BSTR pbstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoEnable <2> ( _                      ' VTable offset = 36
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnable
   ' =====================================================================================
   PROPERTY SET AutoEnable <2> ( _                      ' VTable offset = 40
     BYVAL pfEnable AS INTEGER _                        ' __in VARIANT_BOOL pfEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrevVisible <3> ( _                     ' VTable offset = 44
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET PrevVisible <3> ( _                     ' VTable offset = 48
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NextVisible <4> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET NextVisible <4> ( _                     ' VTable offset = 56
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayVisible <5> ( _                     ' VTable offset = 60
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET PlayVisible <5> ( _                     ' VTable offset = 64
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PauseVisible <6> ( _                    ' VTable offset = 68
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET PauseVisible <6> ( _                    ' VTable offset = 72
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackVisible <7> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET BackVisible <7> ( _                     ' VTable offset = 80
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepVisible <8> ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET StepVisible <8> ( _                     ' VTable offset = 88
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopVisible <9> ( _                     ' VTable offset = 92
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET StopVisible <9> ( _                     ' VTable offset = 96
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordVisible <10> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET RecordVisible <10> ( _                  ' VTable offset = 104
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EjectVisible <11> ( _                   ' VTable offset = 108
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfVisible
   ' =====================================================================================
   PROPERTY SET EjectVisible <11> ( _                   ' VTable offset = 112
     BYVAL pfVisible AS INTEGER _                       ' __in VARIANT_BOOL pfVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrevEnabled <12> ( _                    ' VTable offset = 116
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET PrevEnabled <12> ( _                    ' VTable offset = 120
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NextEnabled <13> ( _                    ' VTable offset = 124
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET NextEnabled <13> ( _                    ' VTable offset = 128
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayEnabled <14> ( _                    ' VTable offset = 132
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET PlayEnabled <14> ( _                    ' VTable offset = 136
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PauseEnabled <15> ( _                   ' VTable offset = 140
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET PauseEnabled <15> ( _                   ' VTable offset = 144
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackEnabled <16> ( _                    ' VTable offset = 148
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET BackEnabled <16> ( _                    ' VTable offset = 152
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepEnabled <17> ( _                    ' VTable offset = 156
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET StepEnabled <17> ( _                    ' VTable offset = 160
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopEnabled <18> ( _                    ' VTable offset = 164
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET StopEnabled <18> ( _                    ' VTable offset = 168
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordEnabled <19> ( _                  ' VTable offset = 172
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET RecordEnabled <19> ( _                  ' VTable offset = 176
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EjectEnabled <20> ( _                   ' VTable offset = 180
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET EjectEnabled <20> ( _                   ' VTable offset = 184
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <22> ( _                       ' VTable offset = 188
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrName
   ' =====================================================================================
   PROPERTY SET FileName <22> ( _                       ' VTable offset = 192
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Command <23> ( _                        ' VTable offset = 196
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrCmd
   ' =====================================================================================
   PROPERTY SET Command <23> ( _                        ' VTable offset = 200
     BYVAL pbstrCmd AS WSTRING _                        ' __in BSTR pbstrCmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Notify <24> ( _                         ' VTable offset = 204
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfNotify
   ' =====================================================================================
   PROPERTY SET Notify <24> ( _                         ' VTable offset = 208
     BYVAL pfNotify AS INTEGER _                        ' __in VARIANT_BOOL pfNotify
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Wait <25> ( _                           ' VTable offset = 212
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfWait
   ' =====================================================================================
   PROPERTY SET Wait <25> ( _                           ' VTable offset = 216
     BYVAL pfWait AS INTEGER _                          ' __in VARIANT_BOOL pfWait
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Shareable <26> ( _                      ' VTable offset = 220
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfShare
   ' =====================================================================================
   PROPERTY SET Shareable <26> ( _                      ' VTable offset = 224
     BYVAL pfShare AS INTEGER _                         ' __in VARIANT_BOOL pfShare
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <27> ( _                    ' VTable offset = 228
   ) AS LONG                                            ' __out_retval OrientationConstants* peOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <27> ( _                    ' VTable offset = 232
     BYVAL peOrientation AS LONG _                      ' __in OrientationConstants peOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorMessage <28> ( _                   ' VTable offset = 236
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrMsg
   ' =====================================================================================
   PROPERTY SET ErrorMessage <28> ( _                   ' VTable offset = 240
     BYVAL pbstrMsg AS WSTRING _                        ' __in BSTR pbstrMsg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET From <29> ( _                           ' VTable offset = 244
   ) AS LONG                                            ' __out_retval long* plFrom
   ' =====================================================================================
   PROPERTY SET From <29> ( _                           ' VTable offset = 248
     BYVAL plFrom AS LONG _                             ' __in long plFrom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET To <30> ( _                             ' VTable offset = 252
   ) AS LONG                                            ' __out_retval long* plTo
   ' =====================================================================================
   PROPERTY SET To <30> ( _                             ' VTable offset = 256
     BYVAL plTo AS LONG _                               ' __in long plTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanEject <31> ( _                       ' VTable offset = 260
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfCanEject
   ' =====================================================================================
   PROPERTY SET CanEject <31> ( _                       ' VTable offset = 264
     BYVAL pfCanEject AS INTEGER _                      ' __in VARIANT_BOOL pfCanEject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanPlay <32> ( _                        ' VTable offset = 268
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfCanPlay
   ' =====================================================================================
   PROPERTY SET CanPlay <32> ( _                        ' VTable offset = 272
     BYVAL pfCanPlay AS INTEGER _                       ' __in VARIANT_BOOL pfCanPlay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanRecord <33> ( _                      ' VTable offset = 276
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfCanRecord
   ' =====================================================================================
   PROPERTY SET CanRecord <33> ( _                      ' VTable offset = 280
     BYVAL pfCanRecord AS INTEGER _                     ' __in VARIANT_BOOL pfCanRecord
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <34> ( _                        ' VTable offset = 284
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfCanStep
   ' =====================================================================================
   PROPERTY SET CanStep <34> ( _                        ' VTable offset = 288
     BYVAL pfCanStep AS INTEGER _                       ' __in VARIANT_BOOL pfCanStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <35> ( _                           ' VTable offset = 292
   ) AS LONG                                            ' __out_retval long* plMode
   ' =====================================================================================
   PROPERTY SET Mode <35> ( _                           ' VTable offset = 296
     BYVAL plMode AS LONG _                             ' __in long plMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Length <36> ( _                         ' VTable offset = 300
   ) AS LONG                                            ' __out_retval long* plLength
   ' =====================================================================================
   PROPERTY SET Length <36> ( _                         ' VTable offset = 304
     BYVAL plLength AS LONG _                           ' __in long plLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Position <37> ( _                       ' VTable offset = 308
   ) AS LONG                                            ' __out_retval long* plPosition
   ' =====================================================================================
   PROPERTY SET Position <37> ( _                       ' VTable offset = 312
     BYVAL plPosition AS LONG _                         ' __in long plPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Start <38> ( _                          ' VTable offset = 316
   ) AS LONG                                            ' __out_retval long* plStart
   ' =====================================================================================
   PROPERTY SET Start <38> ( _                          ' VTable offset = 320
     BYVAL plStart AS LONG _                            ' __in long plStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeFormat <39> ( _                     ' VTable offset = 324
   ) AS LONG                                            ' __out_retval long* plTimeFormat
   ' =====================================================================================
   PROPERTY SET TimeFormat <39> ( _                     ' VTable offset = 328
     BYVAL plTimeFormat AS LONG _                       ' __in long plTimeFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Silent <40> ( _                         ' VTable offset = 332
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfSilent
   ' =====================================================================================
   PROPERTY SET Silent <40> ( _                         ' VTable offset = 336
     BYVAL pfSilent AS INTEGER _                        ' __in VARIANT_BOOL pfSilent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Track <41> ( _                          ' VTable offset = 340
   ) AS LONG                                            ' __out_retval long* plTrack
   ' =====================================================================================
   PROPERTY SET Track <41> ( _                          ' VTable offset = 344
     BYVAL plTrack AS LONG _                            ' __in long plTrack
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tracks <42> ( _                         ' VTable offset = 348
   ) AS LONG                                            ' __out_retval long* plTracks
   ' =====================================================================================
   PROPERTY SET Tracks <42> ( _                         ' VTable offset = 352
     BYVAL plTracks AS LONG _                           ' __in long plTracks
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TrackLength <43> ( _                    ' VTable offset = 356
   ) AS LONG                                            ' __out_retval long* plTrackLength
   ' =====================================================================================
   PROPERTY SET TrackLength <43> ( _                    ' VTable offset = 360
     BYVAL plTrackLength AS LONG _                      ' __in long plTrackLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TrackPosition <44> ( _                  ' VTable offset = 364
   ) AS LONG                                            ' __out_retval long* plTrackPosition
   ' =====================================================================================
   PROPERTY SET TrackPosition <44> ( _                  ' VTable offset = 368
     BYVAL plTrackPosition AS LONG _                    ' __in long plTrackPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateInterval <45> ( _                 ' VTable offset = 372
   ) AS INTEGER                                         ' __out_retval short* psUpdateInterval
   ' =====================================================================================
   PROPERTY SET UpdateInterval <45> ( _                 ' VTable offset = 376
     BYVAL psUpdateInterval AS INTEGER _                ' __in short psUpdateInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsesWindows <46> ( _                    ' VTable offset = 380
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfUsesWindows
   ' =====================================================================================
   PROPERTY SET UsesWindows <46> ( _                    ' VTable offset = 384
     BYVAL pfUsesWindows AS INTEGER _                   ' __in VARIANT_BOOL pfUsesWindows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Frames <47> ( _                         ' VTable offset = 388
   ) AS LONG                                            ' __out_retval long* plFrames
   ' =====================================================================================
   PROPERTY SET Frames <47> ( _                         ' VTable offset = 392
     BYVAL plFrames AS LONG _                           ' __in long plFrames
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordMode <48> ( _                     ' VTable offset = 396
   ) AS LONG                                            ' __out_retval RecordModeConstants* peRecordMode
   ' =====================================================================================
   PROPERTY SET RecordMode <48> ( _                     ' VTable offset = 400
     BYVAL peRecordMode AS LONG _                       ' __in RecordModeConstants peRecordMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWndDisplay <49> ( _                    ' VTable offset = 404
   ) AS LONG                                            ' __out_retval long* plhWndDisplay
   ' =====================================================================================
   PROPERTY SET hWndDisplay <49> ( _                    ' VTable offset = 408
     BYVAL plhWndDisplay AS LONG _                      ' __in long plhWndDisplay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotifyValue <50> ( _                    ' VTable offset = 412
   ) AS INTEGER                                         ' __out_retval short* psNotifyValue
   ' =====================================================================================
   PROPERTY SET NotifyValue <50> ( _                    ' VTable offset = 416
     BYVAL psNotifyValue AS INTEGER _                   ' __in short psNotifyValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotifyMessage <51> ( _                  ' VTable offset = 420
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrMsg
   ' =====================================================================================
   PROPERTY SET NotifyMessage <51> ( _                  ' VTable offset = 424
     BYVAL pbstrMsg AS WSTRING _                        ' __in BSTR pbstrMsg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <52> ( _                        ' VTable offset = 428
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <52> ( _                        ' VTable offset = 432
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 436
   ) AS LONG                                            ' __out_retval BorderStyleConstants* peBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 440
     BYVAL peBorderStyle AS LONG _                      ' __in BorderStyleConstants peBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Error <53> ( _                          ' VTable offset = 444
   ) AS INTEGER                                         ' __out_retval short* psError
   ' =====================================================================================
   PROPERTY SET Error <53> ( _                          ' VTable offset = 448
     BYVAL psError AS INTEGER _                         ' __in short psError
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeviceID <54> ( _                       ' VTable offset = 452
   ) AS INTEGER                                         ' __out_retval short* psDeviceID
   ' =====================================================================================
   PROPERTY SET DeviceID <54> ( _                       ' VTable offset = 456
     BYVAL psDeviceID AS INTEGER _                      ' __in short psDeviceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <1> ( _                    ' VTable offset = 460
   ) AS LONG                                            ' __out_retval MousePointerConstants* peMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <1> ( _                    ' VTable offset = 464
     BYVAL peMousePointer AS LONG _                     ' __in MousePointerConstants peMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <55> ( _                      ' VTable offset = 468
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppMouseIcon
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <55> ( _               ' VTable offset = 472
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp* ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 476
   ) AS LONG                                            ' __out_retval OLE_HANDLE* phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 480
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Command_ <0> ( _                        ' VTable offset = 484
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrCommand
   ' =====================================================================================
   PROPERTY SET Command_ <0> ( _                        ' VTable offset = 488
     BYVAL pbstrCommand AS WSTRING _                    ' __in BSTR pbstrCommand
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 492
   ) AS LONG                                            ' __out_retval OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 496
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 500
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 504
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 508
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Imci_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CDmciEvents
' Interface name = DmciEvents
' IID = {C1A8AF27-1257-101B-8FB0-0020AF039CA3}
' Event interface for MCI Control
' Attributes = 4224 [&H1080] [Nonextensible] [Dispatchable]
' Code generated by the TypeLib Browser 4.0.12 (c) 2008 by José Roca
' Date: 13 nov 2008   Time: 17:19:28
' ########################################################################################

'CLASS CDmciEvents GUID$("{B3E24942-B304-4371-9577-4A3EB1489861}") AS EVENT

'INTERFACE DmciEventsImpl GUID$("{C1A8AF27-1257-101B-8FB0-0020AF039CA3}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Done <38> ( _
'     BYREF NotifyCode AS INTEGER _                      ' __out short *NotifyCode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD BackClick <1> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PrevClick <2> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NextClick <3> ( _
'     BYREF Cancel AS INTEGER _                          ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayClick <4> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PauseClick <5> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StepClick <6> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StopClick <7> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordClick <8> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EjectClick <9> ( _
'     BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PrevGotFocus <10>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PrevLostFocus <11>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NextGotFocus <12>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NextLostFocus <13>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayGotFocus <14>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayLostFocus <15>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PauseGotFocus <16>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PauseLostFocus <17>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD BackGotFocus <18>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD BackLostFocus <19>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StepGotFocus <20>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StepLostFocus <21>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StopLostFocus <22>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StopGotFocus <23>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordGotFocus <24>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordLostFocus <25>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EjectGotFocus <26>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EjectLostFocus <27>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StatusUpdate <28>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NextCompleted <29> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayCompleted <30> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PauseCompleted <31> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD BackCompleted <32> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StepCompleted <33> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StopCompleted <34> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecordCompleted <35> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EjectCompleted <36> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PrevCompleted <37> ( _
'     BYREF Errorcode AS LONG _                          ' __out long* Errorcode
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
'   , BYREF DataFormat AS INTEGER _                      ' __in_out ishort *DataFormat
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
'   , BYREF iButton AS INTEGER _                         ' __in_out short *Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF X AS SINGLE _                                ' __in_out float* X
'   , BYREF Y AS SINGLE _                                ' __in_out float* Y
'   , BYREF iState AS INTEGER _                          ' __in_out short* State
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short *Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short *Shift
'   , BYREF X AS SINGLE _                                ' __in_out float* X
'   , BYREF Y AS SINGLE _                                ' __in_out float* Y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
