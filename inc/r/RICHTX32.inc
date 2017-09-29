' ########################################################################################
' Microsoft Windows
' File: RICHTX32.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RichTextLib
' Version: 1.2, Locale ID = 0
' Documentation string: Microsoft Rich Textbox Control 6.0 (SP6)
' Path: C:\Software\OCXs\RICHTX32.OCX
' Library GUID: {3B7C8863-D78F-101B-B9B5-04021C009402}
' Help file: C:\Software\OCXs\RTFBox98.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%RICHTX32_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vbinterf.inc"

$RTLKEY_RichTextBox = "DC4D7920-6AC8-11cf-8ADB-00AA00C00905"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_RichText_OLEObject = GUID$("{4A8F35A1-D900-11CF-89B4-00AA00688B10}")
$CLSID_RichText_OLEObjects = GUID$("{4A8F35A0-D900-11CF-89B4-00AA00688B10}")
$CLSID_RichTextBox = GUID$("{3B7C8860-D78F-101B-B9B5-04021C009402}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DRichTextEvents = GUID$("{3B7C8862-D78F-101B-B9B5-04021C009402}")
$IID_RichText_IOLEObject = GUID$("{ED117630-4090-11CF-8981-00AA00688B10}")
$IID_RichText_IOLEObjects = GUID$("{859321D0-3FD1-11CF-8981-00AA00688B10}")
$IID_IRichText = GUID$("{E9A5593C-CAB0-11D1-8C0B-0000F8754DA1}")

' ========================================================================================
' OLEDragConstants enum
' IID: {D8898460-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDragMode property (but not the DragMode or OLEDropMode properties).
' ========================================================================================

%rtfOLEDragManual                                       = 0            ' &H0
%rtfOLEDragAutomatic                                    = 1            ' &H1

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%rtfOLEDropNone                                         = 0            ' &H0
%rtfOLEDropManual                                       = 1            ' &H1
%rtfOLEDropAutomatic                                    = 2            ' &H2

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%rtfEnter                                               = 0            ' &H0
%rtfLeave                                               = 1            ' &H1
%rtfOver                                                = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%rtfCFText                                              = 1            ' &H1
%rtfCFBitmap                                            = 2            ' &H2
%rtfCFMetafile                                          = 3            ' &H3
%rtfCFDIB                                               = 8            ' &H8
%rtfCFPalette                                           = 9            ' &H9
%rtfCFEMetafile                                         = 14           ' &HE
%rtfCFFiles                                             = 15           ' &HF
%rtfCFRTF                                               = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%rtfOLEDropEffectNone                                   = 0            ' &H0
%rtfOLEDropEffectCopy                                   = 1            ' &H1
%rtfOLEDropEffectMove                                   = 2            ' &H2
%rtfOLEDropEffectScroll                                 = -2147483648  ' &H80000000

' ========================================================================================
' AppearanceConstants enum
' IID: {84B13220-741A-11CE-9575-0020AF039CA3}
' Appearance constants.
' ========================================================================================

%rtfFlat                                                = 0            ' &H0
%rtfThreeD                                              = 1            ' &H1

' ========================================================================================
' BorderStyleConstants enum
' IID: {3B7C886A-D78F-101B-B9B5-04021C009402}
' BorderStyle constants.
' ========================================================================================

%rtfNoBorder                                            = 0            ' &H0
%rtfFixedSingle                                         = 1            ' &H1

' ========================================================================================
' FindConstants enum
' IID: {F2991EA8-75B9-11CE-B4BC-524153480004}
' Find constants.
' ========================================================================================

%rtfWholeWord                                           = 2            ' &H2
%rtfMatchCase                                           = 4            ' &H4
%rtfNoHighlight                                         = 8            ' &H8

' ========================================================================================
' LoadSaveConstants enum
' IID: {9FAEAB20-894B-11CE-9576-0020AF039CA3}
' LoadSave constants.
' ========================================================================================

%rtfRTF                                                 = 0            ' &H0
%rtfText                                                = 1            ' &H1

' ========================================================================================
' MousePointerConstants enum
' IID: {3B7C886B-D78F-101B-B9B5-04021C009402}
' MousePointer constants.
' ========================================================================================

%rtfDefault                                             = 0            ' &H0
%rtfArrow                                               = 1            ' &H1
%rtfCross                                               = 2            ' &H2
%rtfIBeam                                               = 3            ' &H3
%rtfIcon                                                = 4            ' &H4
%rtfSize                                                = 5            ' &H5
%rtfSizeNESW                                            = 6            ' &H6
%rtfSizeNS                                              = 7            ' &H7
%rtfSizeNWSE                                            = 8            ' &H8
%rtfSizeEW                                              = 9            ' &H9
%rtfUpArrow                                             = 10           ' &HA
%rtfHourglass                                           = 11           ' &HB
%rtfNoDrop                                              = 12           ' &HC
%rtfArrowHourglass                                      = 13           ' &HD
%rtfArrowQuestion                                       = 14           ' &HE
%rtfSizeAll                                             = 15           ' &HF
%rtfCustom                                              = 99           ' &H63

' ========================================================================================
' ScrollBarsConstants enum
' IID: {3B7C886C-D78F-101B-B9B5-04021C009402}
' ScrollBars constants.
' ========================================================================================

%rtfNone                                                = 0            ' &H0
%rtfHorizontal                                          = 1            ' &H1
%rtfVertical                                            = 2            ' &H2
%rtfBoth                                                = 3            ' &H3

' ========================================================================================
' SelAlignmentConstants enum
' IID: {32D50A00-894E-11CE-9576-0020AF039CA3}
' SelAlignment constants.
' ========================================================================================

%rtfLeft                                                = 0            ' &H0
%rtfRight                                               = 1            ' &H1
%rtfCenter                                              = 2            ' &H2

' ========================================================================================
' DisplayTypeConstants enum
' IID: {587A1890-455E-11CF-8983-00AA00688B10}
' OLEObject DisplayType constants
' ========================================================================================

%rtfDisplayContent                                      = 0            ' &H0
%rtfDisplayIcon                                         = 1            ' &H1

' ========================================================================================
' ErrorConstants enum
' IID: {A97022A1-D6C5-11CF-89B4-00AA00688B10}
' Error Constants
' ========================================================================================

%rtfOutOfMemory                                         = 7            ' &H7
%rtfInvalidPropertyValue                                = 380          ' &H17C
%rtfInvalidPropertyArrayIndex                           = 381          ' &H17D
%rtfSetNotSupported                                     = 383          ' &H17F
%rtfSetNotPermitted                                     = 387          ' &H183
%rtfGetNotSupported                                     = 394          ' &H18A
%rtfInvalidProcedureCall                                = 5            ' &H5
%rtfInvalidObjectUse                                    = 425          ' &H1A9
%rtfWrongClipboardFormat                                = 461          ' &H1CD
%rtfDataObjectLocked                                    = 672          ' &H2A0
%rtfExpectedAnArgument                                  = 673          ' &H2A1
%rtfRecursiveOleDrag                                    = 674          ' &H2A2
%rtfFormatNotByteArray                                  = 675          ' &H2A3
%rtfDataNotSetInFormat                                  = 676          ' &H2A4
%rtfPathFileAccessError                                 = 75           ' &H4B
%rtfInvalidFileFormat                                   = 321          ' &H141
%rtfInvalidCharPosition                                 = 32000        ' &H7D00
%rtfInvalidHdc                                          = 32001        ' &H7D01
%rtfCannotLoadFile                                      = 32002        ' &H7D02
%rtfProtected                                           = 32011        ' &H7D0B
%rtfInvalidKeyName                                      = 32005        ' &H7D05
%rtfInvalidClassName                                    = 32006        ' &H7D06
%rtfKeyNotFound                                         = 32007        ' &H7D07
%rtfOLESourceRequired                                   = 32008        ' &H7D08
%rtfNonUniqueKey                                        = 32009        ' &H7D09
%rtfInvalidObject                                       = 32010        ' &H7D0A
%rtfOleCreate                                           = 32012        ' &H7D0C
%rtfOleServer                                           = 32013        ' &H7D0D


' ########################################################################################
' Interface name = IOLEObject
' IID = {ED117630-4090-11CF-8981-00AA00688B10}
' The RichTextBox control enables you to add insertable objects to an RTF file. Insertable objects are represented by the OLEObject.
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%RichText_IOLEObject_INTERFACE_DEFINED)
    %RichText_IOLEObject_INTERFACE_DEFINED = 1

INTERFACE RichText_IOLEObject $IID_RichText_IOLEObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Index <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __out_retval int* piIndex
   ' =====================================================================================
   PROPERTY GET Key <2> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrKey
   ' =====================================================================================
   PROPERTY SET Key <2> ( _                             ' VTable offset = 36
     BYVAL pbstrKey AS WSTRING _                        ' __in BSTR pbstrKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 40
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrClass
   ' =====================================================================================
   PROPERTY GET DisplayType <5> ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __out_retval DisplayTypeConstants* pnType
   ' =====================================================================================
   PROPERTY SET DisplayType <5> ( _                     ' VTable offset = 48
     BYVAL pnType AS LONG _                             ' __in DisplayTypeConstants pnType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectVerbs <6> ( _                     ' VTable offset = 52
   ) AS VARIANT                                         ' __out_retval VARIANT* pvArray
   ' =====================================================================================
   PROPERTY GET ObjectVerbFlags <7> ( _                 ' VTable offset = 56
   ) AS VARIANT                                         ' __out_retval VARIANT* pvArray
   ' =====================================================================================
   PROPERTY GET ObjectVerbsCount <8> ( _                ' VTable offset = 60
   ) AS LONG                                            ' __out_retval int* pnCount
   ' =====================================================================================
   METHOD DoVerb <9> ( _                                ' VTable offset = 64
     OPTIONAL BYVAL verb AS VARIANT _                   ' __opt_in VARIANT verb
   )                                                    ' void
   ' =====================================================================================
   METHOD FetchVerbs <10> ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __out_retval int* pnCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOLEObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IOLEObjects
' IID = {859321D0-3FD1-11CF-8981-00AA00688B10}
' RichText Control OLEObjects Collection Interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%RichText_IOLEObjects_INTERFACE_DEFINED)
    %RichText_IOLEObjects_INTERFACE_DEFINED = 1

INTERFACE RichText_IOLEObjects $IID_RichText_IOLEObjects

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     OPTIONAL BYVAL Item AS VARIANT _                   ' __opt_in VARIANT Item
   ) AS RichText_IOLEObject                             ' __out_retval IOLEObject** ppOLEObject
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __out_retval long* plCount
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     OPTIONAL BYVAL Index AS VARIANT _                  ' __opt_in VARIANT Index
   , OPTIONAL BYVAL Key AS VARIANT _                    ' __opt_in VARIANT Key
   , OPTIONAL BYVAL source AS VARIANT _                 ' __opt_in VARIANT source
   , OPTIONAL BYVAL objclass AS VARIANT _               ' __opt_in VARIANT objclass
   ) AS RichText_IOLEObject                             ' __out_retval IOLEObject** ppOLEObject
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 48
   ) AS IUnknown                                        ' __out_retval IUnknown** ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOLEObjects_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRichText
' IID = {E9A5593C-CAB0-11D1-8C0B-0000F8754DA1}
' Microsoft Rich Textbox Control 6.0 (SP6)
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRichText_INTERFACE_DEFINED)
    %IRichText_INTERFACE_DEFINED = 1

INTERFACE IRichText $IID_IRichText

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET defTextRTF <0> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrTextRTF
   ' =====================================================================================
   PROPERTY SET defTextRTF <0> ( _                      ' VTable offset = 32
     BYVAL pbstrTextRTF AS WSTRING _                    ' __in BSTR pbstrTextRTF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Appearance <29> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __out_retval AppearanceConstants* pAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <29> ( _                     ' VTable offset = 40
     BYVAL pAppearance AS LONG _                        ' __in AppearanceConstants pAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 44
   ) AS DWORD                                           ' __out_retval OLE_COLOR* pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 48
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <23> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __out_retval BorderStyleConstants* pBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <23> ( _                    ' VTable offset = 56
     BYVAL pBorderStyle AS LONG _                       ' __in BorderStyleConstants pBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BulletIndent <30> ( _                   ' VTable offset = 60
   ) AS SINGLE                                          ' __out_retval float* pflBulletIndent
   ' =====================================================================================
   PROPERTY SET BulletIndent <30> ( _                   ' VTable offset = 64
     BYVAL pflBulletIndent AS SINGLE _                  ' __in float pflBulletIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisableNoScroll <7> ( _                 ' VTable offset = 68
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfDisableNoScroll
   ' =====================================================================================
   PROPERTY SET DisableNoScroll <7> ( _                 ' VTable offset = 72
     BYVAL pfDisableNoScroll AS INTEGER _               ' __in VARIANT_BOOL pfDisableNoScroll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 80
     BYVAL pfEnabled AS INTEGER _                       ' __in VARIANT_BOOL pfEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <19> ( _                       ' VTable offset = 84
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <19> ( _                       ' VTable offset = 88
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 92
   ) AS IFontDisp                                       ' __out_retval IFontDisp** ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 96
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HideSelection <2> ( _                   ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfHideSelection
   ' =====================================================================================
   PROPERTY SET HideSelection <2> ( _                   ' VTable offset = 104
     BYVAL pfHideSelection AS INTEGER _                 ' __in VARIANT_BOOL pfHideSelection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hwnd <-515> ( _                         ' VTable offset = 108
   ) AS LONG                                            ' __out_retval OLE_HANDLE* pohHwnd
   ' =====================================================================================
   PROPERTY SET Hwnd <-515> ( _                         ' VTable offset = 112
     BYVAL pohHwnd AS LONG _                            ' __in OLE_HANDLE pohHwnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <22> ( _                         ' VTable offset = 116
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfLocked
   ' =====================================================================================
   PROPERTY SET Locked <22> ( _                         ' VTable offset = 120
     BYVAL pfLocked AS INTEGER _                        ' __in VARIANT_BOOL pfLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxLength <12> ( _                      ' VTable offset = 124
   ) AS LONG                                            ' __out_retval long* plMaxLength
   ' =====================================================================================
   PROPERTY SET MaxLength <12> ( _                      ' VTable offset = 128
     BYVAL plMaxLength AS LONG _                        ' __in long plMaxLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <6> ( _                       ' VTable offset = 132
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <6> ( _                       ' VTable offset = 136
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp* ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <6> ( _                ' VTable offset = 140
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp* ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <1> ( _                    ' VTable offset = 144
   ) AS LONG                                            ' __out_retval MousePointerConstants* pMousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <1> ( _                    ' VTable offset = 148
     BYVAL pMousePointer AS LONG _                      ' __in MousePointerConstants pMousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiLine <3> ( _                       ' VTable offset = 152
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfMultiLine
   ' =====================================================================================
   PROPERTY SET MultiLine <3> ( _                       ' VTable offset = 156
     BYVAL pfMultiLine AS INTEGER _                     ' __in VARIANT_BOOL pfMultiLine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RightMargin <32> ( _                    ' VTable offset = 160
   ) AS SINGLE                                          ' __out_retval float* pflRightMargin
   ' =====================================================================================
   PROPERTY SET RightMargin <32> ( _                    ' VTable offset = 164
     BYVAL pflRightMargin AS SINGLE _                   ' __in float pflRightMargin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollBars <4> ( _                      ' VTable offset = 168
   ) AS LONG                                            ' __out_retval ScrollBarsConstants* psbcScrollBars
   ' =====================================================================================
   PROPERTY SET ScrollBars <4> ( _                      ' VTable offset = 172
     BYVAL psbcScrollBars AS LONG _                     ' __in ScrollBarsConstants psbcScrollBars
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelAlignment <28> ( _                   ' VTable offset = 176
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelAlignment
   ' =====================================================================================
   PROPERTY SET SelAlignment <28> ( _                   ' VTable offset = 180
     BYVAL pvarSelAlignment AS VARIANT _                ' __in VARIANT pvarSelAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelBold <24> ( _                        ' VTable offset = 184
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelBold
   ' =====================================================================================
   PROPERTY SET SelBold <24> ( _                        ' VTable offset = 188
     BYVAL pvarSelBold AS VARIANT _                     ' __in VARIANT pvarSelBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelBullet <31> ( _                      ' VTable offset = 192
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelBullet
   ' =====================================================================================
   PROPERTY SET SelBullet <31> ( _                      ' VTable offset = 196
     BYVAL pvarSelBullet AS VARIANT _                   ' __in VARIANT pvarSelBullet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelCharOffset <16> ( _                  ' VTable offset = 200
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelCharOffset
   ' =====================================================================================
   PROPERTY SET SelCharOffset <16> ( _                  ' VTable offset = 204
     BYVAL pvarSelCharOffset AS VARIANT _               ' __in VARIANT pvarSelCharOffset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelColor <13> ( _                       ' VTable offset = 208
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelColor
   ' =====================================================================================
   PROPERTY SET SelColor <13> ( _                       ' VTable offset = 212
     BYVAL pvarSelColor AS VARIANT _                    ' __in VARIANT pvarSelColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelFontName <14> ( _                    ' VTable offset = 216
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelFontName
   ' =====================================================================================
   PROPERTY SET SelFontName <14> ( _                    ' VTable offset = 220
     BYVAL pvarSelFontName AS VARIANT _                 ' __in VARIANT pvarSelFontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelFontSize <15> ( _                    ' VTable offset = 224
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelFontSize
   ' =====================================================================================
   PROPERTY SET SelFontSize <15> ( _                    ' VTable offset = 228
     BYVAL pvarSelFontSize AS VARIANT _                 ' __in VARIANT pvarSelFontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelHangingIndent <18> ( _               ' VTable offset = 232
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelHangingIndent
   ' =====================================================================================
   PROPERTY SET SelHangingIndent <18> ( _               ' VTable offset = 236
     BYVAL pvarSelHangingIndent AS VARIANT _            ' __in VARIANT pvarSelHangingIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelIndent <17> ( _                      ' VTable offset = 240
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelIndent
   ' =====================================================================================
   PROPERTY SET SelIndent <17> ( _                      ' VTable offset = 244
     BYVAL pvarSelIndent AS VARIANT _                   ' __in VARIANT pvarSelIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelItalic <25> ( _                      ' VTable offset = 248
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelItalic
   ' =====================================================================================
   PROPERTY SET SelItalic <25> ( _                      ' VTable offset = 252
     BYVAL pvarSelItalic AS VARIANT _                   ' __in VARIANT pvarSelItalic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <5> ( _                       ' VTable offset = 256
   ) AS LONG                                            ' __out_retval long* plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <5> ( _                       ' VTable offset = 260
     BYVAL plSelLength AS LONG _                        ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelProtected <48> ( _                   ' VTable offset = 264
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelProtected
   ' =====================================================================================
   PROPERTY SET SelProtected <48> ( _                   ' VTable offset = 268
     BYVAL pvarSelProtected AS VARIANT _                ' __in VARIANT pvarSelProtected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelRightIndent <21> ( _                 ' VTable offset = 272
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelRightIndent
   ' =====================================================================================
   PROPERTY SET SelRightIndent <21> ( _                 ' VTable offset = 276
     BYVAL pvarSelRightIndent AS VARIANT _              ' __in VARIANT pvarSelRightIndent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelRTF <11> ( _                         ' VTable offset = 280
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrSelRTF
   ' =====================================================================================
   PROPERTY SET SelRTF <11> ( _                         ' VTable offset = 284
     BYVAL pbstrSelRTF AS WSTRING _                     ' __in BSTR pbstrSelRTF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <8> ( _                        ' VTable offset = 288
   ) AS LONG                                            ' __out_retval long* plSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <8> ( _                        ' VTable offset = 292
     BYVAL plSelStart AS LONG _                         ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStrikeThru <26> ( _                  ' VTable offset = 296
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelStrikeThru
   ' =====================================================================================
   PROPERTY SET SelStrikeThru <26> ( _                  ' VTable offset = 300
     BYVAL pvarSelStrikeThru AS VARIANT _               ' __in VARIANT pvarSelStrikeThru
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelTabCount <20> ( _                    ' VTable offset = 304
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelTabCount
   ' =====================================================================================
   PROPERTY SET SelTabCount <20> ( _                    ' VTable offset = 308
     BYVAL pvarSelTabCount AS VARIANT _                 ' __in VARIANT pvarSelTabCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelText <9> ( _                         ' VTable offset = 312
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrSelText
   ' =====================================================================================
   PROPERTY SET SelText <9> ( _                         ' VTable offset = 316
     BYVAL pbstrSelText AS WSTRING _                    ' __in BSTR pbstrSelText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelUnderline <27> ( _                   ' VTable offset = 320
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelUnderline
   ' =====================================================================================
   PROPERTY SET SelUnderline <27> ( _                   ' VTable offset = 324
     BYVAL pvarSelUnderline AS VARIANT _                ' __in VARIANT pvarSelUnderline
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <-517> ( _                         ' VTable offset = 328
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrText
   ' =====================================================================================
   PROPERTY SET Text <-517> ( _                         ' VTable offset = 332
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextRTF <10> ( _                        ' VTable offset = 336
   ) AS WSTRING                                         ' __out_retval BSTR* pbstrTextRTF
   ' =====================================================================================
   PROPERTY SET TextRTF <10> ( _                        ' VTable offset = 340
     BYVAL pbstrTextRTF AS WSTRING _                    ' __in BSTR pbstrTextRTF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEObjects <42> ( _                     ' VTable offset = 344
   ) AS RichText_IOLEObjects                            ' __out_retval IOLEObjects** ppOLEObjects
   ' =====================================================================================
   PROPERTY GET AutoVerbMenu <43> ( _                   ' VTable offset = 348
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL* pfOn
   ' =====================================================================================
   PROPERTY SET AutoVerbMenu <43> ( _                   ' VTable offset = 352
     BYVAL pfOn AS INTEGER _                            ' __in VARIANT_BOOL pfOn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 356
   ) AS LONG                                            ' __out_retval OLEDragConstants* psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 360
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 364
   ) AS LONG                                            ' __out_retval OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 368
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 372
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <34> ( _                                 ' VTable offset = 376
     BYVAL bstrString AS WSTRING _                      ' __in BSTR bstrString
   , OPTIONAL BYVAL vStart AS VARIANT _                 ' __opt_in VARIANT vStart
   , OPTIONAL BYVAL vEnd AS VARIANT _                   ' __opt_in VARIANT vEnd
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   ) AS LONG                                            ' __out_retval long* plFind
   ' =====================================================================================
   METHOD GetLineFromChar <33> ( _                      ' VTable offset = 380
     BYVAL lChar AS LONG _                              ' __in long lChar
   ) AS LONG                                            ' __out_retval long* plLine
   ' =====================================================================================
   METHOD LoadFile <37> ( _                             ' VTable offset = 384
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , OPTIONAL BYVAL vFileType AS VARIANT _              ' __opt_in VARIANT vFileType
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 388
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveFile <38> ( _                             ' VTable offset = 392
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , OPTIONAL BYVAL vFlags AS VARIANT _                 ' __opt_in VARIANT vFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD UnusedSelPrint <49> ( _                       ' VTable offset = 396
     BYVAL lHDC AS LONG _                               ' __in long lHDC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelTabs <40> ( _                        ' VTable offset = 400
     BYVAL sElement AS INTEGER _                        ' __in short sElement
   ) AS VARIANT                                         ' __out_retval VARIANT* pvarSelTab
   ' =====================================================================================
   PROPERTY SET SelTabs <40> ( _                        ' VTable offset = 404
     BYVAL sElement AS INTEGER _                        ' __in short sElement
   , BYVAL pvarSelTab AS VARIANT _                      ' __in VARIANT pvarSelTab
   )                                                    ' void
   ' =====================================================================================
   METHOD Span <35> ( _                                 ' VTable offset = 408
     BYVAL bstrCharacterSet AS WSTRING _                ' __in BSTR bstrCharacterSet
   , OPTIONAL BYVAL vForward AS VARIANT _               ' __opt_in VARIANT vForward
   , OPTIONAL BYVAL vNegate AS VARIANT _                ' __opt_in VARIANT vNegate
   )                                                    ' void
   ' =====================================================================================
   METHOD UpTo <36> ( _                                 ' VTable offset = 412
     BYVAL bstrCharacterSet AS WSTRING _                ' __in BSTR bstrCharacterSet
   , OPTIONAL BYVAL vForward AS VARIANT _               ' __opt_in VARIANT vForward
   , OPTIONAL BYVAL vNegate AS VARIANT _                ' __opt_in VARIANT vNegate
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 416
   )                                                    ' void
   ' =====================================================================================
   METHOD SelPrint <39> ( _                             ' VTable offset = 420
     BYVAL lHDC AS LONG _                               ' __in long lHDC
   , OPTIONAL BYVAL vStartDoc AS VARIANT _              ' __opt_in VARIANT vStartDoc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRichText_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDRichTextEvents
' Interface name = DRichTextEvents
' IID = {3B7C8862-D78F-101B-B9B5-04021C009402}
' Event interface for RichText control
' Attributes = 4224 [&H1080] [Nonextensible] [Dispatchable]
' ########################################################################################

'CLASS CDRichTextEvents GUID$("{CDCF0BC8-2A1B-483B-B037-86F53B1B4ED1}") AS EVENT

'INTERFACE DRichTextEventsImpl GUID$("{3B7C8862-D78F-101B-B9B5-04021C009402}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Change <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' *KeyCode VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' *KeyCode VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' *KeyAscii VT_I2 <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL x AS LONG _                                  ' x OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL y AS LONG _                                  ' y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL x AS LONG _                                  ' x OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL y AS LONG _                                  ' y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL x AS LONG _                                  ' x OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL y AS LONG _                                  ' y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SelChange <2>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF AllowedEffects AS LONG _                     ' [in][out] *AllowedEffects VT_I4 <Long>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF DefaultCursors AS INTEGER _                  ' [in][out] *DefaultCursors VT_BOOL <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF DataFormat AS INTEGER _                      ' [in][out] *DataFormat VT_I2 <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF iButton AS INTEGER _                         ' [in][out] *Button VT_I2 <Integer>
'   , BYREF iShift AS INTEGER _                          ' [in][out] *Shift VT_I2 <Integer>
'   , BYREF x AS SINGLE _                                ' [in][out] *x VT_R4 <Single>
'   , BYREF y AS SINGLE _                                ' [in][out] *y VT_R4 <Single>
'   , BYREF iState AS INTEGER _                          ' [in][out] *State VT_I2 <Integer>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF iButton AS INTEGER _                         ' [in][out] *Button VT_I2 <Integer>
'   , BYREF iShift AS INTEGER _                          ' [in][out] *Shift VT_I2 <Integer>
'   , BYREF x AS SINGLE _                                ' [in][out] *x VT_R4 <Single>
'   , BYREF y AS SINGLE _                                ' [in][out] *y VT_R4 <Single>
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
