' ########################################################################################
' Microsoft Windows
' File: Amovie.inc
' Library name: AMovie
' Version: 2.0, Locale ID = 0
' Contents: Microsoft ActiveMovie Control
' Library GUID: {05589FA0-C356-11CE-BF01-00AA0055595A}
' Path: C:\WINDOWS\system32\amcompat.tlb
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMOVIE_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {05589FA1-C356-11CE-BF01-00AA0055595A}
$PROGID_AMOVIEActiveMovieControl2 = "AMOVIE.ActiveMovieControl.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {05589FA1-C356-11CE-BF01-00AA0055595A}
$PROGID_AMOVIEActiveMovieControl = "AMOVIE.ActiveMovieControl"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ActiveMovie       = GUID$("{05589FA1-C356-11CE-BF01-00AA0055595A}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DActiveMovieEvents  = GUID$("{05589FA3-C356-11CE-BF01-00AA0055595A}")
$IID_DActiveMovieEvents2 = GUID$("{B6CD6553-E9CB-11D0-821F-00A0C91F9CA0}")
$IID_IActiveMovie        = GUID$("{05589FA2-C356-11CE-BF01-00AA0055595A}")
$IID_IActiveMovie2       = GUID$("{B6CD6554-E9CB-11D0-821F-00A0C91F9CA0}")
$IID_IActiveMovie3       = GUID$("{265EC140-AE62-11D1-8500-00A0C91F9CA0}")

' ========================================================================================
' ReadyStateConstants enum
' ActiveMovie Readiness State
' ========================================================================================

MACRO READYSTATECONSTANTS_ENUM = LONG
%amvUninitialized                                       = 0
%amvLoading                                             = 1
%amvInteractive                                         = 3
%amvComplete                                            = 4

' ========================================================================================
' StateConstants enum
' State of ActiveMovie Clip
' ========================================================================================

MACRO STATECONSTANTS_ENUM = LONG
%amvNotLoaded                                           = -1
%amvStopped                                             = 0
%amvPaused                                              = 1
%amvRunning                                             = 2

' ========================================================================================
' DisplayModeConstants enum
' ActiveMovie Display Mode
' ========================================================================================

MACRO DISPLAYMODECONSTANTS_ENUM = LONG
%amvTime                                                = 0
%amvFrames                                              = 1

' ========================================================================================
' WindowSizeConstants enum
' Direct Show Video Size
' ========================================================================================

MACRO WINDOWSIZECONSTANTS_ENUM = LONG
%amvOriginalSize                                        = 0
%amvDoubleOriginalSize                                  = 1
%amvOneSixteenthScreen                                  = 2
%amvOneFourthScreen                                     = 3
%amvOneHalfScreen                                       = 4

' ========================================================================================
' AppearanceConstants enum
' ActiveMovie Appearance
' ========================================================================================

MACRO APPEARANCECONSTANTS_ENUM = LONG
%amvFlat                                                = 0
%amv3D                                                  = 1

' ========================================================================================
' BorderStyleConstants enum
' ActiveMovie Border Style
' ========================================================================================MACRO BORDERSTYLECONSTANTS_ENUM = LONG

MACRO BORDERSTYLECONSTANTS_ENUM = LONG
%amvNone                                                = 0
%amvFixedSingle                                         = 1

' ########################################################################################
' Interface name = IActiveMovie
' IID = {05589FA2-C356-11CE-BF01-00AA0055595A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IActiveMovie_INTERFACE_DEFINED)
    %IActiveMovie_INTERFACE_DEFINED = 1

INTERFACE IActiveMovie $IID_IActiveMovie

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <1610743809> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <1610743810> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743811> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <4> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pWidth
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <5> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Author <6> ( _                          ' VTable offset = 52
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Title <7> ( _                           ' VTable offset = 56
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET Copyright <8> ( _                       ' VTable offset = 60
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <9> ( _                     ' VTable offset = 64
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <10> ( _                         ' VTable offset = 68
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET FileName <11> ( _                       ' VTable offset = 72
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <11> ( _                       ' VTable offset = 76
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <12> ( _                       ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY GET CurrentPosition <13> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET CurrentPosition <13> ( _                ' VTable offset = 88
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <14> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <14> ( _                      ' VTable offset = 96
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionStart <15> ( _                 ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionStart <15> ( _                 ' VTable offset = 104
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionEnd <16> ( _                   ' VTable offset = 108
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionEnd <16> ( _                   ' VTable offset = 112
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <17> ( _                   ' VTable offset = 116
   ) AS STATECONSTANTS_ENUM                             ' __retval_out StateConstants* pState
   ' =====================================================================================
   PROPERTY GET Rate <18> ( _                           ' VTable offset = 120
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET Rate <18> ( _                           ' VTable offset = 124
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <19> ( _                         ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Volume <19> ( _                         ' VTable offset = 132
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <20> ( _                        ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Balance <20> ( _                        ' VTable offset = 140
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <21> ( _              ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <21> ( _              ' VTable offset = 148
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDisplay <22> ( _                    ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowDisplay <22> ( _                    ' VTable offset = 156
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowControls <23> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowControls <23> ( _                   ' VTable offset = 164
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowPositionControls <24> ( _           ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowPositionControls <24> ( _           ' VTable offset = 172
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowSelectionControls <25> ( _          ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowSelectionControls <25> ( _          ' VTable offset = 180
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTracker <26> ( _                    ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowTracker <26> ( _                    ' VTable offset = 188
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnablePositionControls <27> ( _         ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnablePositionControls <27> ( _         ' VTable offset = 196
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableSelectionControls <28> ( _        ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableSelectionControls <28> ( _        ' VTable offset = 204
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableTracker <29> ( _                  ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableTracker <29> ( _                  ' VTable offset = 212
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideDisplay <30> ( _               ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideDisplay <30> ( _               ' VTable offset = 220
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideControls <31> ( _              ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideControls <31> ( _              ' VTable offset = 228
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayMode <32> ( _                    ' VTable offset = 232
   ) AS DISPLAYMODECONSTANTS_ENUM                       ' __retval_out DisplayModeConstants* pValue
   ' =====================================================================================
   PROPERTY SET DisplayMode <32> ( _                    ' VTable offset = 236
     BYVAL pValue AS DISPLAYMODECONSTANTS_ENUM _        ' __in DisplayModeConstants pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeDisplayMode <33> ( _         ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* fAllow
   ' =====================================================================================
   PROPERTY SET AllowChangeDisplayMode <33> ( _         ' VTable offset = 244
     BYVAL fAllow AS INTEGER _                          ' __in VARIANT_BOOL fAllow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraph <34> ( _                    ' VTable offset = 248
   ) AS IUnknown                                        ' __retval_out IUnknown** ppFilterGraph
   ' =====================================================================================
   PROPERTY SET FilterGraph <34> ( _                    ' VTable offset = 252
     BYVAL ppFilterGraph AS IUnknown _                  ' __in IUnknown* ppFilterGraph
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraphDispatch <35> ( _            ' VTable offset = 256
   ) AS IDispatch                                       ' __retval_out IDispatch** pDispatch
   ' =====================================================================================
   PROPERTY GET DisplayForeColor <36> ( _               ' VTable offset = 260
   ) AS DWORD                                           ' __retval_out unsigned long* ForeColor
   ' =====================================================================================
   PROPERTY SET DisplayForeColor <36> ( _               ' VTable offset = 264
     BYVAL ForeColor AS DWORD _                         ' __in unsigned long ForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayBackColor <37> ( _               ' VTable offset = 268
   ) AS DWORD                                           ' __retval_out unsigned long* BackColor
   ' =====================================================================================
   PROPERTY SET DisplayBackColor <37> ( _               ' VTable offset = 272
     BYVAL BackColor AS DWORD _                         ' __in unsigned long BackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MovieWindowSize <38> ( _                ' VTable offset = 276
   ) AS WINDOWSIZECONSTANTS_ENUM                        ' __retval_out WindowSizeConstants* WindowSize
   ' =====================================================================================
   PROPERTY SET MovieWindowSize <38> ( _                ' VTable offset = 280
     BYVAL WindowSize AS WINDOWSIZECONSTANTS_ENUM _     ' __in WindowSizeConstants WindowSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreenMode <39> ( _                 ' VTable offset = 284
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET FullScreenMode <39> ( _                 ' VTable offset = 288
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoStart <40> ( _                      ' VTable offset = 292
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoStart <40> ( _                      ' VTable offset = 296
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <41> ( _                     ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoRewind <41> ( _                     ' VTable offset = 304
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long* hWnd
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 312
   ) AS APPEARANCECONSTANTS_ENUM                        ' __retval_out AppearanceConstants* pAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 316
     BYVAL pAppearance AS APPEARANCECONSTANTS_ENUM _    ' __in AppearanceConstants pAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <42> ( _                    ' VTable offset = 320
   ) AS BORDERSTYLECONSTANTS_ENUM                       ' __retval_out BorderStyleConstants* pBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <42> ( _                    ' VTable offset = 324
     BYVAL pBorderStyle AS BORDERSTYLECONSTANTS_ENUM _  ' __in BorderStyleConstants pBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 332
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Info <1610743885> ( _                   ' VTable offset = 336
   ) AS LONG                                            ' __retval_out long* ppInfo
   ' =====================================================================================

END INTERFACE

#ENDIF             ' /* __IActiveMovie_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveMovie2
' IID = {B6CD6554-E9CB-11D0-821F-00A0C91F9CA0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IActiveMovie
' ########################################################################################

#IF NOT %DEF(%IActiveMovie2_INTERFACE_DEFINED)
    %IActiveMovie2_INTERFACE_DEFINED = 1

INTERFACE IActiveMovie2 $IID_IActiveMovie2

   INHERIT IDispatch

   ' =====================================================================================
   ' IActiveMovie Methods
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <1610743809> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <1610743810> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743811> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <4> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pWidth
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <5> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Author <6> ( _                          ' VTable offset = 52
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Title <7> ( _                           ' VTable offset = 56
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET Copyright <8> ( _                       ' VTable offset = 60
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <9> ( _                     ' VTable offset = 64
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <10> ( _                         ' VTable offset = 68
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET FileName <11> ( _                       ' VTable offset = 72
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <11> ( _                       ' VTable offset = 76
     BYVAL pbstrFileName  AS WSTRING _                  ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <12> ( _                       ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY GET CurrentPosition <13> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET CurrentPosition <13> ( _                ' VTable offset = 88
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <14> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <14> ( _                      ' VTable offset = 96
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionStart <15> ( _                 ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionStart <15> ( _                 ' VTable offset = 104
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionEnd <16> ( _                   ' VTable offset = 108
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionEnd <16> ( _                   ' VTable offset = 112
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <17> ( _                   ' VTable offset = 116
   ) AS STATECONSTANTS_ENUM                             ' __retval_out StateConstants* pState
   ' =====================================================================================
   PROPERTY GET Rate <18> ( _                           ' VTable offset = 120
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET Rate <18> ( _                           ' VTable offset = 124
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <19> ( _                         ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Volume <19> ( _                         ' VTable offset = 132
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <20> ( _                        ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Balance <20> ( _                        ' VTable offset = 140
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <21> ( _              ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <21> ( _              ' VTable offset = 148
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDisplay <22> ( _                    ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowDisplay <22> ( _                    ' VTable offset = 156
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowControls <23> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowControls <23> ( _                   ' VTable offset = 164
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowPositionControls <24> ( _           ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowPositionControls <24> ( _           ' VTable offset = 172
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowSelectionControls <25> ( _          ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowSelectionControls <25> ( _          ' VTable offset = 180
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTracker <26> ( _                    ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowTracker <26> ( _                    ' VTable offset = 188
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnablePositionControls <27> ( _         ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnablePositionControls <27> ( _         ' VTable offset = 196
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableSelectionControls <28> ( _        ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableSelectionControls <28> ( _        ' VTable offset = 204
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableTracker <29> ( _                  ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableTracker <29> ( _                  ' VTable offset = 212
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideDisplay <30> ( _               ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideDisplay <30> ( _               ' VTable offset = 220
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideControls <31> ( _              ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideControls <31> ( _              ' VTable offset = 228
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayMode <32> ( _                    ' VTable offset = 232
   ) AS DISPLAYMODECONSTANTS_ENUM                       ' __retval_out DisplayModeConstants* pValue
   ' =====================================================================================
   PROPERTY SET DisplayMode <32> ( _                    ' VTable offset = 236
     BYVAL pValue AS DISPLAYMODECONSTANTS_ENUM _        ' __in DisplayModeConstants pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeDisplayMode <33> ( _         ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* fAllow
   ' =====================================================================================
   PROPERTY SET AllowChangeDisplayMode <33> ( _         ' VTable offset = 244
     BYVAL fAllow AS INTEGER _                          ' __in VARIANT_BOOL fAllow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraph <34> ( _                    ' VTable offset = 248
   ) AS IUnknown                                        ' __retval_out IUnknown** ppFilterGraph
   ' =====================================================================================
   PROPERTY SET FilterGraph <34> ( _                    ' VTable offset = 252
     BYVAL ppFilterGraph AS IUnknown _                  ' __in IUnknown* ppFilterGraph
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraphDispatch <35> ( _            ' VTable offset = 256
   ) AS IDispatch                                       ' __retval_out IDispatch** pDispatch
   ' =====================================================================================
   PROPERTY GET DisplayForeColor <36> ( _               ' VTable offset = 260
   ) AS DWORD                                           ' __retval_out unsigned long* ForeColor
   ' =====================================================================================
   PROPERTY SET DisplayForeColor <36> ( _               ' VTable offset = 264
     BYVAL ForeColor AS DWORD _                         ' __in unsigned long ForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayBackColor <37> ( _               ' VTable offset = 268
   ) AS DWORD                                           ' __retval_out unsigned long* BackColor
   ' =====================================================================================
   PROPERTY SET DisplayBackColor <37> ( _               ' VTable offset = 272
     BYVAL BackColor AS DWORD _                         ' __in unsigned long BackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MovieWindowSize <38> ( _                ' VTable offset = 276
   ) AS WINDOWSIZECONSTANTS_ENUM                        ' __retval_out WindowSizeConstants* WindowSize
   ' =====================================================================================
   PROPERTY SET MovieWindowSize <38> ( _                ' VTable offset = 280
     BYVAL WindowSize AS WINDOWSIZECONSTANTS_ENUM _     ' __in WindowSizeConstants WindowSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreenMode <39> ( _                 ' VTable offset = 284
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET FullScreenMode <39> ( _                 ' VTable offset = 288
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoStart <40> ( _                      ' VTable offset = 292
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoStart <40> ( _                      ' VTable offset = 296
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <41> ( _                     ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoRewind <41> ( _                     ' VTable offset = 304
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long* hWnd
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 312
   ) AS APPEARANCECONSTANTS_ENUM                        ' __retval_out AppearanceConstants* pAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 316
     BYVAL pAppearance AS APPEARANCECONSTANTS_ENUM _    ' __in AppearanceConstants pAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <42> ( _                    ' VTable offset = 320
   ) AS BORDERSTYLECONSTANTS_ENUM                       ' __retval_out BorderStyleConstants* pBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <42> ( _                    ' VTable offset = 324
     BYVAL pBorderStyle AS BORDERSTYLECONSTANTS_ENUM _  ' __in BorderStyleConstants pBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 332
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Info <1610743885> ( _                   ' VTable offset = 336
   ) AS LONG                                            ' __retval_out long* ppInfo
   ' =====================================================================================

   ' =====================================================================================
   ' IActiveMovie2 Methods
   ' =====================================================================================
   METHOD IsSoundCardEnabled <53> ( _                   ' VTable offset = 340
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbSoundCard
   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 344
   ) AS READYSTATECONSTANTS_ENUM                        ' __retval_out ReadyStateConstants* pValue
   ' =====================================================================================

END INTERFACE

#ENDIF             ' /* __IActiveMovie2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveMovie3
' IID = {265EC140-AE62-11D1-8500-00A0C91F9CA0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IActiveMovie2
' ########################################################################################

#IF NOT %DEF(%IActiveMovie3_INTERFACE_DEFINED)
    %IActiveMovie3_INTERFACE_DEFINED = 1

INTERFACE IActiveMovie3 $IID_IActiveMovie3

   INHERIT IDispatch

   ' =====================================================================================
   ' IActiveMovie Methods
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <1610743809> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <1610743810> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743811> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageSourceWidth <4> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pWidth)
   ' =====================================================================================
   PROPERTY GET ImageSourceHeight <5> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* pHeight
   ' =====================================================================================
   PROPERTY GET Author <6> ( _                          ' VTable offset = 52
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrAuthor
   ' =====================================================================================
   PROPERTY GET Title <7> ( _                           ' VTable offset = 56
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   PROPERTY GET Copyright <8> ( _                       ' VTable offset = 60
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrCopyright
   ' =====================================================================================
   PROPERTY GET Description <9> ( _                     ' VTable offset = 64
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrDescription
   ' =====================================================================================
   PROPERTY GET Rating <10> ( _                         ' VTable offset = 68
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrRating
   ' =====================================================================================
   PROPERTY GET FileName <11> ( _                       ' VTable offset = 72
   )  AS WSTRING                                        ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <11> ( _                       ' VTable offset = 76
     BYVAL pbstrFileName  AS WSTRING _                  ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <12> ( _                       ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY GET CurrentPosition <13> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET CurrentPosition <13> ( _                ' VTable offset = 88
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlayCount <14> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* pPlayCount
   ' =====================================================================================
   PROPERTY SET PlayCount <14> ( _                      ' VTable offset = 96
     BYVAL pPlayCount AS LONG _                         ' __in long pPlayCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionStart <15> ( _                 ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionStart <15> ( _                 ' VTable offset = 104
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionEnd <16> ( _                   ' VTable offset = 108
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET SelectionEnd <16> ( _                   ' VTable offset = 112
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentState <17> ( _                   ' VTable offset = 116
   ) AS STATECONSTANTS_ENUM                             ' __retval_out StateConstants* pState
   ' =====================================================================================
   PROPERTY GET Rate <18> ( _                           ' VTable offset = 120
   ) AS DOUBLE                                          ' __retval_out double* pValue
   ' =====================================================================================
   PROPERTY SET Rate <18> ( _                           ' VTable offset = 124
     BYVAL pValue AS DOUBLE _                           ' __in double pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <19> ( _                         ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Volume <19> ( _                         ' VTable offset = 132
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <20> ( _                        ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long* pValue
   ' =====================================================================================
   PROPERTY SET Balance <20> ( _                        ' VTable offset = 140
     BYVAL pValue AS LONG _                             ' __in long pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableContextMenu <21> ( _              ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET EnableContextMenu <21> ( _              ' VTable offset = 148
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDisplay <22> ( _                    ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowDisplay <22> ( _                    ' VTable offset = 156
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowControls <23> ( _                   ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowControls <23> ( _                   ' VTable offset = 164
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowPositionControls <24> ( _           ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowPositionControls <24> ( _           ' VTable offset = 172
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowSelectionControls <25> ( _          ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowSelectionControls <25> ( _          ' VTable offset = 180
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTracker <26> ( _                    ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET ShowTracker <26> ( _                    ' VTable offset = 188
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnablePositionControls <27> ( _         ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnablePositionControls <27> ( _         ' VTable offset = 196
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableSelectionControls <28> ( _        ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableSelectionControls <28> ( _        ' VTable offset = 204
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableTracker <29> ( _                  ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enable
   ' =====================================================================================
   PROPERTY SET EnableTracker <29> ( _                  ' VTable offset = 212
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideDisplay <30> ( _               ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideDisplay <30> ( _               ' VTable offset = 220
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHideControls <31> ( _              ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET AllowHideControls <31> ( _              ' VTable offset = 228
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayMode <32> ( _                    ' VTable offset = 232
   ) AS DISPLAYMODECONSTANTS_ENUM                       ' __retval_out DisplayModeConstants* pValue
   ' =====================================================================================
   PROPERTY SET DisplayMode <32> ( _                    ' VTable offset = 236
     BYVAL pValue AS DISPLAYMODECONSTANTS_ENUM _        ' __in DisplayModeConstants pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowChangeDisplayMode <33> ( _         ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* fAllow
   ' =====================================================================================
   PROPERTY SET AllowChangeDisplayMode <33> ( _         ' VTable offset = 244
     BYVAL fAllow AS INTEGER _                          ' __in VARIANT_BOOL fAllow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraph <34> ( _                    ' VTable offset = 248
   ) AS IUnknown                                        ' __retval_out IUnknown** ppFilterGraph
   ' =====================================================================================
   PROPERTY SET FilterGraph <34> ( _                    ' VTable offset = 252
     BYVAL ppFilterGraph AS IUnknown _                  ' __in IUnknown* ppFilterGraph
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterGraphDispatch <35> ( _            ' VTable offset = 256
   ) AS IDispatch                                       ' __retval_out IDispatch** pDispatch
   ' =====================================================================================
   PROPERTY GET DisplayForeColor <36> ( _               ' VTable offset = 260
   ) AS DWORD                                           ' __retval_out unsigned long* ForeColor
   ' =====================================================================================
   PROPERTY SET DisplayForeColor <36> ( _               ' VTable offset = 264
     BYVAL ForeColor AS DWORD _                         ' __in unsigned long ForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayBackColor <37> ( _               ' VTable offset = 268
   ) AS DWORD                                           ' __retval_out unsigned long* BackColor
   ' =====================================================================================
   PROPERTY SET DisplayBackColor <37> ( _               ' VTable offset = 272
     BYVAL BackColor AS DWORD _                         ' __in unsigned long BackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MovieWindowSize <38> ( _                ' VTable offset = 276
   ) AS WINDOWSIZECONSTANTS_ENUM                        ' __retval_out WindowSizeConstants* WindowSize
   ' =====================================================================================
   PROPERTY SET MovieWindowSize <38> ( _                ' VTable offset = 280
     BYVAL WindowSize AS WINDOWSIZECONSTANTS_ENUM _     ' __in WindowSizeConstants WindowSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreenMode <39> ( _                 ' VTable offset = 284
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET FullScreenMode <39> ( _                 ' VTable offset = 288
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoStart <40> ( _                      ' VTable offset = 292
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoStart <40> ( _                      ' VTable offset = 296
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoRewind <41> ( _                     ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnable
   ' =====================================================================================
   PROPERTY SET AutoRewind <41> ( _                     ' VTable offset = 304
     BYVAL pEnable AS INTEGER _                         ' __in VARIANT_BOOL pEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long* hWnd
   ' =====================================================================================
   PROPERTY GET Appearance <-520> ( _                   ' VTable offset = 312
   ) AS APPEARANCECONSTANTS_ENUM                        ' __retval_out AppearanceConstants* pAppearance
   ' =====================================================================================
   PROPERTY SET Appearance <-520> ( _                   ' VTable offset = 316
     BYVAL pAppearance AS APPEARANCECONSTANTS_ENUM _    ' __in AppearanceConstants pAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <42> ( _                    ' VTable offset = 320
   ) AS BORDERSTYLECONSTANTS_ENUM                       ' __retval_out BorderStyleConstants* pBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <42> ( _                    ' VTable offset = 324
     BYVAL pBorderStyle AS BORDERSTYLECONSTANTS_ENUM _  ' __in BorderStyleConstants pBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 332
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Info <1610743885> ( _                   ' VTable offset = 336
   ) AS LONG                                            ' __retval_out long* ppInfo
   ' =====================================================================================

   ' =====================================================================================
   ' IActiveMovie2 Methods
   ' =====================================================================================
   METHOD IsSoundCardEnabled <53> ( _                   ' VTable offset = 340
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbSoundCard
   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 344
   ) AS READYSTATECONSTANTS_ENUM                        ' __retval_out ReadyStateConstants* pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IActiveMovie3 Methods
   ' =====================================================================================
   PROPERTY GET MediaPlayer <1111> ( _                  ' VTable offset = 348
   ) AS IDispatch                                       ' __retval_out IDispatch** ppDispatch
   ' =====================================================================================

END INTERFACE

#ENDIF             ' /* __IActiveMovie3_INTERFACE_DEFINED__ */
