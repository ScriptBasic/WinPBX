' ########################################################################################
' Microsoft Windows
' File: Inked.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: INKEDLib
' Version: 1.0, Locale ID = 0
' Description: Microsoft InkEdit Control 1.0
' Path: C:\Windows\System32\Inked.dll
' Library GUID: {8405D0DF-9FDD-4829-AEAD-8E2B0A18FEA4}
' Help file: C:\Windows\System32\TPCSDK10.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%INKED_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "msinkaut.inc"

$LIBID_INKEDLib = GUID$("{8405D0DF-9FDD-4829-AEAD-8E2B0A18FEA4}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {E5CA59F5-57C4-4DD8-9BD6-1DEEEDD27AF4}
$PROGID_InkEdit1 = "InkEd.InkEdit.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {E5CA59F5-57C4-4DD8-9BD6-1DEEEDD27AF4}
$PROGID_InkEdit = "InkEd.InkEdit"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_InkEdit = GUID$("{E5CA59F5-57C4-4DD8-9BD6-1DEEEDD27AF4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IInkEdit = GUID$("{F2127A19-FBFB-4AED-8464-3F36D78CFEFB}")
$IID__IInkEditEvents = GUID$("{E3B0B797-A72E-46DB-A0D7-6C9EBA8E9BBC}")

'///////////////////////////////////////////////////////////////////////////////
'//
'// InkEdit Win32 API
'//
'///////////////////////////////////////////////////////////////////////////////

'#define INKEDIT_CLASSW  L"INKEDIT"

'#ifdef UNICODE
'#define INKEDIT_CLASS   INKEDIT_CLASSW
'#else
'#define INKEDIT_CLASS   "INKEDIT"
'#endif

$INKEDIT_CLASS = "INKEDIT"

'// InkEdit Constants

'// InkEdit Structures

' // Size = 20 bytes
UNION IEC_STROKEINFO_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR       ' NMHDR nmhdr
   nmhdr  AS NMHDR       ' NMHDR nmhdr
END UNION

TYPE IEC_STROKEINFO DWORD
   IEC_STROKEINFO_UNION  ' NMHDR nmhdr
   Cursor AS DWORD PTR   ' IInkCursor * Cursor
   Stroke AS DWORD PTR   ' IInkStrokeDisp * Stroke
END TYPE

' // Size = 40 bytes
UNION IEC_GESTUREINFO_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR       ' NMHDR nmhdr
   nmhdr  AS NMHDR       ' NMHDR nmhdr
END UNION

TYPE IEC_GESTUREINFO DWORD
   IEC_GESTUREINFO_UNION       ' NMHDR nmhdr
   Cursor      AS DWORD PTR    ' IInkCursor * Cursor
   Strokes     AS DWORD PTR    ' IInkStrokes * Strokes
   Gestures    AS tagVARIANT   ' VARIANT Gestures
   alignment__ AS DWORD
END TYPE

' // Size = 16 bytes
UNION IEC_RECOGNITIONRESULTINFO_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR       ' NMHDR nmhdr
   nmhdr  AS NMHDR       ' NMHDR nmhdr
END UNION

TYPE IEC_RECOGNITIONRESULTINFO DWORD
   IEC_RECOGNITIONRESULTINFO_UNION  ' NMHDR nmhdr
   RecognitionResult AS DWORD PTR   ' IInkRecognitionResult * RecognitionResult
END TYPE

'// InkEdit messages

%IEC__BASE               = %WM_USER   + &H0200
%EM_GETINKMODE           = %IEC__BASE + 1
%EM_SETINKMODE           = %IEC__BASE + 2
%EM_GETINKINSERTMODE     = %IEC__BASE + 3
%EM_SETINKINSERTMODE     = %IEC__BASE + 4
%EM_GETDRAWATTR          = %IEC__BASE + 5
%EM_SETDRAWATTR          = %IEC__BASE + 6
%EM_GETRECOTIMEOUT       = %IEC__BASE + 7
%EM_SETRECOTIMEOUT       = %IEC__BASE + 8
%EM_GETGESTURESTATUS     = %IEC__BASE + 9
%EM_SETGESTURESTATUS     = %IEC__BASE + 10
%EM_GETRECOGNIZER        = %IEC__BASE + 11
%EM_SETRECOGNIZER        = %IEC__BASE + 12
%EM_GETFACTOID           = %IEC__BASE + 13
%EM_SETFACTOID           = %IEC__BASE + 14
%EM_GETSELINK            = %IEC__BASE + 15
%EM_SETSELINK            = %IEC__BASE + 16
%EM_GETMOUSEICON         = %IEC__BASE + 17
%EM_SETMOUSEICON         = %IEC__BASE + 18
%EM_GETMOUSEPOINTER      = %IEC__BASE + 19
%EM_SETMOUSEPOINTER      = %IEC__BASE + 20
%EM_GETSTATUS            = %IEC__BASE + 21
%EM_RECOGNIZE            = %IEC__BASE + 22
%EM_GETUSEMOUSEFORINPUT  = %IEC__BASE + 23
%EM_SETUSEMOUSEFORINPUT  = %IEC__BASE + 24
%EM_SETSELINKDISPLAYMODE = %IEC__BASE + 25
%EM_GETSELINKDISPLAYMODE = %IEC__BASE + 26

'///////////////////////////////////////////////////////////////////////////////

'// InkEdit notifications

%IECN__BASE             = &H0800
%IECN_STROKE            = %IECN__BASE + 1
%IECN_GESTURE           = %IECN__BASE + 2
%IECN_RECOGNITIONRESULT = %IECN__BASE + 3

' ========================================================================================
' MouseButton enum
' Defines values that specify which mouse button was pressed.
' ========================================================================================

%MouseButton_NO_BUTTON                                  = 0
%MouseButton_LEFT_BUTTON                                = &H1
%MouseButton_RIGHT_BUTTON                               = &H2
%MouseButton_MIDDLE_BUTTON                              = &H4

' ========================================================================================
' SelAlignmentConstants enum
' Defines values that specify whether a paragraph is aligned along the left margin, along the right margin, or between the left and right margin of the control.
' ========================================================================================

%SelAlignment_rtfLeft                                   = 0
%SelAlignment_rtfRight                                  = 1
%SelAlignment_rtfCenter                                 = 2


' ========================================================================================
' DISPID_InkEdit enum
' ========================================================================================

%DISPID_InkEdit_Text               = %DISPID_VALUE
%DISPID_InkEdit_TextRTF            = %DISPID_InkEdit_Text               + 1
%DISPID_InkEdit_Hwnd               = %DISPID_InkEdit_TextRTF            + 1
%DISPID_InkEdit_DisableNoScroll    = %DISPID_InkEdit_Hwnd               + 1
%DISPID_InkEdit_Locked             = %DISPID_InkEdit_DisableNoScroll    + 1
%DISPID_InkEdit_Enabled            = %DISPID_InkEdit_Locked             + 1
%DISPID_InkEdit_MaxLength          = %DISPID_InkEdit_Enabled            + 1
%DISPID_InkEdit_MultiLine          = %DISPID_InkEdit_MaxLength          + 1
%DISPID_InkEdit_ScrollBars         = %DISPID_InkEdit_MultiLine          + 1
%DISPID_InkEdit_RTSelStart         = %DISPID_InkEdit_ScrollBars         + 1
%DISPID_InkEdit_RTSelLength        = %DISPID_InkEdit_RTSelStart         + 1
%DISPID_InkEdit_RTSelText          = %DISPID_InkEdit_RTSelLength        + 1
%DISPID_InkEdit_SelAlignment       = %DISPID_InkEdit_RTSelText          + 1
%DISPID_InkEdit_SelBold            = %DISPID_InkEdit_SelAlignment       + 1
%DISPID_InkEdit_SelCharOffset      = %DISPID_InkEdit_SelBold            + 1
%DISPID_InkEdit_SelColor           = %DISPID_InkEdit_SelCharOffset      + 1
%DISPID_InkEdit_SelFontName        = %DISPID_InkEdit_SelColor           + 1
%DISPID_InkEdit_SelFontSize        = %DISPID_InkEdit_SelFontName        + 1
%DISPID_InkEdit_SelItalic          = %DISPID_InkEdit_SelFontSize        + 1
%DISPID_InkEdit_SelRTF             = %DISPID_InkEdit_SelItalic          + 1
%DISPID_InkEdit_SelUnderline       = %DISPID_InkEdit_SelRTF             + 1
%DISPID_InkEdit_DragIcon           = %DISPID_InkEdit_SelUnderline       + 1
%DISPID_InkEdit_Status             = %DISPID_InkEdit_DragIcon           + 1
%DISPID_InkEdit_UseMouseForInput   = %DISPID_InkEdit_Status             + 1
%DISPID_InkEdit_InkMode            = %DISPID_InkEdit_UseMouseForInput   + 1
%DISPID_InkEdit_InkInsertMode      = %DISPID_InkEdit_InkMode            + 1
%DISPID_InkEdit_RecoTimeout        = %DISPID_InkEdit_InkInsertMode      + 1
%DISPID_InkEdit_DrawAttr           = %DISPID_InkEdit_RecoTimeout        + 1
%DISPID_InkEdit_Recognizer         = %DISPID_InkEdit_DrawAttr           + 1
%DISPID_InkEdit_Factoid            = %DISPID_InkEdit_Recognizer         + 1
%DISPID_InkEdit_SelInk             = %DISPID_InkEdit_Factoid            + 1
%DISPID_InkEdit_SelInksDisplayMode = %DISPID_InkEdit_SelInk             + 1
%DISPID_InkEdit_Recognize          = %DISPID_InkEdit_SelInksDisplayMode + 1
%DISPID_InkEdit_GetGestStatus      = %DISPID_InkEdit_Recognize          + 1
%DISPID_InkEdit_SetGestStatus      = %DISPID_InkEdit_GetGestStatus      + 1
%DISPID_InkEdit_Refresh            = %DISPID_InkEdit_SetGestStatus      + 1

' ========================================================================================
' DISPID_InkEditEvents enum
' ========================================================================================

%DISPID_IeeChange            = 1
%DISPID_IeeSelChange         = 2
%DISPID_IeeKeyDown           = 3
%DISPID_IeeKeyUp             = 4
%DISPID_IeeMouseUp           = 5
%DISPID_IeeMouseDown         = 6
%DISPID_IeeKeyPress          = 7
%DISPID_IeeDblClick          = 8
%DISPID_IeeClick             = 9
%DISPID_IeeMouseMove         = 10
%DISPID_IeeCursorDown        = 21
%DISPID_IeeStroke            = 22
%DISPID_IeeGesture           = 23
%DISPID_IeeRecognitionResult = 24

' ########################################################################################
' Interface name = IInkEdit
' IID = {F2127A19-FBFB-4AED-8464-3F36D78CFEFB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IInkEdit_INTERFACE_DEFINED)
    %IInkEdit_INTERFACE_DEFINED = 1

' enum InkMode
%IEM_Disabled      = 0
%IEM_Ink           = 1
%IEM_InkAndGesture = 2

' enum InkInsertMode
%IEM_InsertText    = 0
%IEM_InsertInk     = 1

' enum InkEditStatus
%IES_Idle          = 0
%IES_Collecting    = 1
%IES_Recognizing   = 2

' enum InkDisplayMode
%IEDM_Ink           = 0
%IEDM_Text          = 1

' enum AppearanceConstants
%IEA_rtfFlat       = 0
%IEA_rtfThreeD     = 1

' enum BorderStyleConstants
%IEBS_rtfNoBorder       = 0
%IEBS_rtfFixedSingle    = 1

' enum ScrollBarsConstants
%IESB_rtfNone           = 0
%IESB_rtfHorizontal     = 1
%IESB_rtfVertical       = 2
%IESB_rtfBoth           = 3

INTERFACE IInkEdit $IID_IInkEdit

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Status <22> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out InkEditStatus *pStatus
   ' =====================================================================================
   PROPERTY GET UseMouseForInput <23> ( _               ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseMouseForInput <23> ( _               ' VTable offset = 36
     OPTIONAL BYVAL pVal AS INTEGER _                   ' __in_opt VARIANT_BOOL pVal = -1
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InkMode <24> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out InkMode *pVal
   ' =====================================================================================
   PROPERTY SET InkMode <24> ( _                        ' VTable offset = 44
     OPTIONAL BYVAL pVal AS LONG _                      ' __in_opt InkMode pVal = 2
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InkInsertMode <25> ( _                  ' VTable offset = 48
   ) AS LONG                                            ' __retval_out InkInsertMode *pVal
   ' =====================================================================================
   PROPERTY SET InkInsertMode <25> ( _                  ' VTable offset = 52
     OPTIONAL BYVAL pVal AS LONG _                      ' __in_opt InkInsertMode pVal = 0
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DrawingAttributes <27> ( _              ' VTable offset = 56
   ) AS IInkDrawingAttributes                           ' __retval_out IInkDrawingAttributes **pVal
   ' =====================================================================================
   PROPERTY SET putref_DrawingAttributes <27> ( _       ' VTable offset = 60
     BYVAL pVal AS IInkDrawingAttributes _              ' __in IInkDrawingAttributes *pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecognitionTimeout <26> ( _             ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET RecognitionTimeout <26> ( _             ' VTable offset = 68
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recognizer <28> ( _                     ' VTable offset = 72
   ) AS IInkRecognizer                                  ' __retval_out IInkRecognizer **pVal
   ' =====================================================================================
   PROPERTY SET putref_Recognizer <28> ( _              ' VTable offset = 76
     BYVAL pVal AS IInkRecognizer _                     ' __in IInkRecognizer *pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Factoid <29> ( _                        ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Factoid <29> ( _                        ' VTable offset = 84
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelInks <30> ( _                        ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pSelInk
   ' =====================================================================================
   PROPERTY SET SelInks <30> ( _                        ' VTable offset = 92
     BYVAL pSelInk AS VARIANT _                         ' __in VARIANT pSelInk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelInksDisplayMode <31> ( _             ' VTable offset = 96
   ) AS LONG                                            ' __retval_out InkDisplayMode *pInkDisplayMode
   ' =====================================================================================
   PROPERTY SET SelInksDisplayMode <31> ( _             ' VTable offset = 100
     BYVAL pInkDisplayMode AS LONG _                    ' __in InkDisplayMode pInkDisplayMode
   )                                                    ' void
   ' =====================================================================================
   METHOD Recognize <32> ( _                            ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGestureStatus <33> ( _                     ' VTable offset = 108
     BYVAL Gesture AS LONG _                            ' __in InkApplicationGesture Gesture
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pListen
   ' =====================================================================================
   METHOD SetGestureStatus <34> ( _                     ' VTable offset = 112
     BYVAL Gesture AS LONG _                            ' __in InkApplicationGesture Gesture
   , BYVAL Listen AS INTEGER _                          ' __in VARIANT_BOOL Listen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 116
     BYVAL pclr AS DWORD _                              ' __in OLE_COLOR pclr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 120
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclr
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 124
   ) AS LONG                                            ' __retval_out AppearanceConstants *pAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 128
     BYVAL pAppearance AS LONG _                        ' __in AppearanceConstants pAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 132
   ) AS LONG                                            ' __retval_out BorderStyleConstants *pBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 136
     BYVAL pBorderStyle AS LONG _                       ' __in BorderStyleConstants pBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hwnd <-515> ( _                         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out OLE_HANDLE *pohHwnd
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 144
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 148
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp *ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <0> ( _                            ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrText
   ' =====================================================================================
   PROPERTY SET Text <0> ( _                            ' VTable offset = 156
     BYVAL pbstrText AS WSTRING _                       ' __in BSTR pbstrText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <-522> ( _                    ' VTable offset = 160
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp **MouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <-522> ( _                    ' VTable offset = 164
     BYVAL MouseIcon AS IPictureDisp _                  ' __in IPictureDisp *MouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <-522> ( _             ' VTable offset = 168
     BYVAL MouseIcon AS IPictureDisp _                  ' __in IPictureDisp *MouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <-521> ( _                 ' VTable offset = 172
   ) AS LONG                                            ' __retval_out InkMousePointer *MousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <-521> ( _                 ' VTable offset = 176
     BYVAL MousePointer AS LONG _                       ' __in InkMousePointer MousePointer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <4> ( _                          ' VTable offset = 180
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Locked <4> ( _                          ' VTable offset = 184
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <5> ( _                         ' VTable offset = 188
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Enabled <5> ( _                         ' VTable offset = 192
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxLength <6> ( _                       ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long *plMaxLength
   ' =====================================================================================
   PROPERTY SET MaxLength <6> ( _                       ' VTable offset = 200
     BYVAL plMaxLength AS LONG _                        ' __in long plMaxLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiLine <7> ( _                       ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal VT_BOOL
   ' =====================================================================================
   PROPERTY SET MultiLine <7> ( _                       ' VTable offset = 208
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScrollBars <8> ( _                      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out ScrollBarsConstants *pVal
   ' =====================================================================================
   PROPERTY SET ScrollBars <8> ( _                      ' VTable offset = 216
     BYVAL pVal AS LONG _                               ' __in ScrollBarsConstants pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisableNoScroll <3> ( _                 ' VTable offset = 220
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET DisableNoScroll <3> ( _                 ' VTable offset = 224
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelAlignment <12> ( _                   ' VTable offset = 228
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelAlignment
   ' =====================================================================================
   PROPERTY SET SelAlignment <12> ( _                   ' VTable offset = 232
     BYVAL pvarSelAlignment AS VARIANT _                ' __in VARIANT pvarSelAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelBold <13> ( _                        ' VTable offset = 236
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelBold
   ' =====================================================================================
   PROPERTY SET SelBold <13> ( _                        ' VTable offset = 240
     BYVAL pvarSelBold AS VARIANT _                     ' __in VARIANT pvarSelBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelItalic <18> ( _                      ' VTable offset = 244
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelItalic
   ' =====================================================================================
   PROPERTY SET SelItalic <18> ( _                      ' VTable offset = 248
     BYVAL pvarSelItalic AS VARIANT _                   ' __in VARIANT pvarSelItalic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelUnderline <20> ( _                   ' VTable offset = 252
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelUnderline
   ' =====================================================================================
   PROPERTY SET SelUnderline <20> ( _                   ' VTable offset = 256
     BYVAL pvarSelUnderline AS VARIANT _                ' __in VARIANT pvarSelUnderline
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelColor <15> ( _                       ' VTable offset = 260
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelColor
   ' =====================================================================================
   PROPERTY SET SelColor <15> ( _                       ' VTable offset = 264
     BYVAL pvarSelColor AS VARIANT _                    ' __in VARIANT pvarSelColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelFontName <16> ( _                    ' VTable offset = 268
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelFontName
   ' =====================================================================================
   PROPERTY SET SelFontName <16> ( _                    ' VTable offset = 272
     BYVAL pvarSelFontName AS VARIANT _                 ' __in VARIANT pvarSelFontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelFontSize <17> ( _                    ' VTable offset = 276
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelFontSize
   ' =====================================================================================
   PROPERTY SET SelFontSize <17> ( _                    ' VTable offset = 280
     BYVAL pvarSelFontSize AS VARIANT _                 ' __in VARIANT pvarSelFontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelCharOffset <14> ( _                  ' VTable offset = 284
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSelCharOffset
   ' =====================================================================================
   PROPERTY SET SelCharOffset <14> ( _                  ' VTable offset = 288
     BYVAL pvarSelCharOffset AS VARIANT _               ' __in VARIANT pvarSelCharOffset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextRTF <1> ( _                         ' VTable offset = 292
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTextRTF
   ' =====================================================================================
   PROPERTY SET TextRTF <1> ( _                         ' VTable offset = 296
     BYVAL pbstrTextRTF AS WSTRING _                    ' __in BSTR pbstrTextRTF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelStart <9> ( _                        ' VTable offset = 300
   ) AS LONG                                            ' __retval_out long *plSelStart
   ' =====================================================================================
   PROPERTY SET SelStart <9> ( _                        ' VTable offset = 304
     BYVAL plSelStart AS LONG _                         ' __in long plSelStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelLength <10> ( _                      ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long *plSelLength
   ' =====================================================================================
   PROPERTY SET SelLength <10> ( _                      ' VTable offset = 312
     BYVAL plSelLength AS LONG _                        ' __in long plSelLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelText <11> ( _                        ' VTable offset = 316
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSelText
   ' =====================================================================================
   PROPERTY SET SelText <11> ( _                        ' VTable offset = 320
     BYVAL pbstrSelText AS WSTRING _                    ' __in BSTR pbstrSelText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelRTF <19> ( _                         ' VTable offset = 324
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSelRTF
   ' =====================================================================================
   PROPERTY SET SelRTF <19> ( _                         ' VTable offset = 328
     BYVAL pbstrSelRTF AS WSTRING _                     ' __in BSTR pbstrSelRTF
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <35> ( _                              ' VTable offset = 332
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInkEdit_INTERFACE_DEFINED__ */


'#ifndef ___IInkEditEvents_DISPINTERFACE_DEFINED__
'#define ___IInkEditEvents_DISPINTERFACE_DEFINED__

'EXTERN_C const IID DIID__IInkEditEvents;

'#if defined(__cplusplus) && !defined(CINTERFACE)

'    MIDL_INTERFACE("E3B0B797-A72E-46DB-A0D7-6C9EBA8E9BBC")
'    _IInkEditEvents : public IDispatch
'    {
'    };

'#endif    /* ___IInkEditEvents_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Class CIInkEditEvents
' Interface name = _IInkEditEvents
' IID = {E3B0B797-A72E-46DB-A0D7-6C9EBA8E9BBC}
' _IInkEditEvents Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CIInkEditEvents GUID$("{274881D9-53DE-4BA6-8D07-CF5B83DEB6F0}") AS EVENT

'INTERFACE IInkEditEventsImpl GUID$("{E3B0B797-A72E-46DB-A0D7-6C9EBA8E9BBC}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Change <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SelChange <2>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <3> ( _
'     BYREF pKey AS LONG _                               ' long *pKey
'   , BYVAL ShiftKey AS INTEGER _                        ' short ShiftKey
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <4> ( _
'     BYREF pKey AS LONG _                               ' long *pKey
'   , BYVAL ShiftKey AS INTEGER _                        ' short ShiftKey
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <5> ( _
'     BYVAL iButton AS INTEGER _                         ' short Button
'   , BYVAL ShiftKey AS INTEGER _                        ' short ShiftKey
'   , BYVAL xMouse AS LONG _                             ' long xMouse
'   , BYVAL yMouse AS LONG _                             ' long yMouse
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <6> ( _
'     BYVAL iButton AS INTEGER _                         ' short Button
'   , BYVAL ShiftKey AS INTEGER _                        ' short ShiftKey
'   , BYVAL xMouse AS LONG _                             ' long xMouse
'   , BYVAL yMouse AS LONG _                             ' long yMouse
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <7> ( _
'     BYREF Char AS LONG _                               ' long *Char
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <8>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <9>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <10> ( _
'     BYVAL iButton AS INTEGER _                         ' short Button
'   , BYVAL ShiftKey AS INTEGER _                        ' short ShiftKey
'   , BYVAL xMouse AS LONG _                             ' long xMouse
'   , BYVAL yMouse AS LONG _                             ' long yMouse
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Stroke <22> ( _
'     BYVAL pCursor AS IInkCursor _                      ' __in IInkCursor *Cursor
'   , BYVAL Stroke AS IInkStrokeDisp _                   ' __in IInkStrokeDisp *Stroke
'   , BYREF bCancel AS INTEGER _                         ' __inout VARIANT_BOOL *Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Gesture <23> ( _
'     BYVAL pCursor AS IInkCursor _                      ' __in IInkCursor *Cursor
'   , BYVAL Strokes AS IInkStrokes _                     ' __in IInkStrokes *Strokes
'   , BYVAL Gestures AS VARIANT _                        ' __in VARIANT Gestures
'   , BYREF bCancel AS INTEGER _                         ' __inout VARIANT_BOOL *Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecognitionResult <24> ( _
'     BYVAL RecognitionResult AS IInkRecognitionResult _ ' __in IInkRecognitionResult *RecognitionResult
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
