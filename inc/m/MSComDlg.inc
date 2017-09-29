' ########################################################################################
' Microsoft Windows
' File: MSComDlg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSComDlg
' Version: 1.2
' Documentation string: Microsoft Common Dialog Control 6.0 (SP3)
' Path: C:\WINDOWS\system32\comdlg32.ocx
' Library GUID: {F9043C88-F6F2-101A-A3C9-08002B2F49FB}
' Help file: C:\WINDOWS\HELP\cmdlg98.chm
' License key: 28C4C820-401A-101B-A3C9-08002B2F49FB
' ########################################################################################

#INCLUDE THIS ONCE
%MSCOMFLG_INC = 1

$RTLKEY_CommonDialog = "28C4C820-401A-101B-A3C9-08002B2F49FB"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {F9043C85-F6F2-101A-A3C9-08002B2F49FB}
$PROGID_CommonDialog1 = "MSComDlg.CommonDialog.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {F9043C85-F6F2-101A-A3C9-08002B2F49FB}
$PROGID_CommonDialog = "MSComDlg.CommonDialog"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CommonDialog = GUID$("{F9043C85-F6F2-101A-A3C9-08002B2F49FB}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICommonDialog = GUID$("{083039C2-13F4-11D1-8B7E-0000F8754DA1}")
$IID_ICommonDialogEvents = GUID$("{F9043C87-F6F2-101A-A3C9-08002B2F49FB}")

' ========================================================================================
' PrinterConstants enum
' IID: {05428B50-E613-11CD-A2D5-08002B336F60}
' Printer Dialog Box Constants
' ========================================================================================

%cdlPDAllPages                                          = &H0
%cdlPDCollate                                           = &H10
%cdlPDDisablePrintToFile                                = &H80000
%cdlPDHidePrintToFile                                   = &H100000
%cdlPDNoPageNums                                        = &H8
%cdlPDNoSelection                                       = &H4
%cdlPDNoWarning                                         = &H80
%cdlPDPageNums                                          = &H2
%cdlPDPrintSetup                                        = &H40
%cdlPDPrintToFile                                       = &H20
%cdlPDReturnDC                                          = &H100
%cdlPDReturnDefault                                     = &H400
%cdlPDReturnIC                                          = &H200
%cdlPDSelection                                         = &H1
%cdlPDHelpButton                                        = &H800
%cdlPDUseDevModeCopies                                  = &H40000

' ========================================================================================
' ColorConstants enum
' IID: {05428B51-E613-11CD-A2D5-08002B336F60}
' Color Dialog Box Constants
' ========================================================================================

%cdlCCRGBInit                                           = &H1
%cdlCCFullOpen                                          = &H2
%cdlCCPreventFullOpen                                   = &H4
%cdlCCHelpButton                                        = &H8

' ========================================================================================
' FileOpenConstants enum
' IID: {05428B52-E613-11CD-A2D5-08002B336F60}
' File Open/Save Dialog Box Constants
' ========================================================================================

%cdlOFNReadOnly                                         = &H1
%cdlOFNOverwritePrompt                                  = &H2
%cdlOFNHideReadOnly                                     = &H4
%cdlOFNNoChangeDir                                      = &H8
%cdlOFNHelpButton                                       = &H10
%cdlOFNNoValidate                                       = &H100
%cdlOFNAllowMultiselect                                 = &H200
%cdlOFNExtensionDifferent                               = &H400
%cdlOFNPathMustExist                                    = &H800
%cdlOFNFileMustExist                                    = &H1000
%cdlOFNCreatePrompt                                     = &H2000
%cdlOFNShareAware                                       = &H4000
%cdlOFNNoReadOnlyReturn                                 = &H8000
%cdlOFNNoLongNames                                      = &H40000
%cdlOFNExplorer                                         = &H80000
%cdlOFNNoDereferenceLinks                               = &H100000
%cdlOFNLongNames                                        = &H200000

' ========================================================================================
' FontsConstants enum
' IID: {05428B53-E613-11CD-A2D5-08002B336F60}
' Fonts Dialog Box Constants
' ========================================================================================

%cdlCFScreenFonts                                       = &H1
%cdlCFPrinterFonts                                      = &H2
%cdlCFBoth                                              = &H3
%cdlCFHelpButton                                        = &H4
%cdlCFEffects                                           = &H100
%cdlCFApply                                             = &H200
%cdlCFANSIOnly                                          = &H400
%cdlCFNoVectorFonts                                     = &H800
%cdlCFNoSimulations                                     = &H1000
%cdlCFLimitSize                                         = &H2000
%cdlCFFixedPitchOnly                                    = &H4000
%cdlCFWYSIWYG                                           = &H8000
%cdlCFForceFontExist                                    = &H10000
%cdlCFScalableOnly                                      = &H20000
%cdlCFTTOnly                                            = &H40000
%cdlCFNoFaceSel                                         = &H80000
%cdlCFNoStyleSel                                        = &H100000
%cdlCFNoSizeSel                                         = &H200000

' ========================================================================================
' ErrorConstants enum
' IID: {05428B54-E613-11CD-A2D5-08002B336F60}
' Common Dialog Error Constants
' ========================================================================================

%cdlInvalidPropertyValue                                = 380
%cdlGetNotSupported                                     = 394
%cdlSetNotSupported                                     = 383
%cdlAlloc                                               = 32752
%cdlCancel                                              = 32755
%cdlDialogFailure                                       = -32768
%cdlFindResFailure                                      = 32761
%cdlHelp                                                = 32751
%cdlInitialization                                      = 32765
%cdlLoadResFailure                                      = 32760
%cdlLoadStrFailure                                      = 32762
%cdlLockResFailure                                      = 32759
%cdlMemAllocFailure                                     = 32758
%cdlMemLockFailure                                      = 32757
%cdlNoFonts                                             = 24574
%cdlBufferTooSmall                                      = 20476
%cdlInvalidFileName                                     = 20477
%cdlSubclassFailure                                     = 20478
%cdlCreateICFailure                                     = 28661
%cdlDndmMismatch                                        = 28662
%cdlGetDevModeFail                                      = 28666
%cdlInitFailure                                         = 28665
%cdlLoadDrvFailure                                      = 28667
%cdlNoDefaultPrn                                        = 28663
%cdlNoDevices                                           = 28664
%cdlParseFailure                                        = 28669
%cdlPrinterCodes                                        = 28671
%cdlPrinterNotFound                                     = 28660
%cdlRetDefFailure                                       = 28668
%cdlSetupFailure                                        = 28670
%cdlNoTemplate                                          = 32764
%cdlNoInstance                                          = 32763
%cdlInvalidSafeModeProcCall                             = 680

' ========================================================================================
' HelpConstants enum
' IID: {05428B55-E613-11CD-A2D5-08002B336F60}
' Help Constants
' ========================================================================================

%cdlHelpContext                                         = 1
%cdlHelpQuit                                            = 2
%cdlHelpIndex                                           = 3
%cdlHelpContents                                        = 3
%cdlHelpHelpOnHelp                                      = 4
%cdlHelpSetIndex                                        = 5
%cdlHelpSetContents                                     = 5
%cdlHelpContextPopup                                    = 8
%cdlHelpForceFile                                       = 9
%cdlHelpKey                                             = 257
%cdlHelpCommandHelp                                     = 258
%cdlHelpPartialKey                                      = 261

' ========================================================================================
' PrinterOrientationConstants enum
' IID: {DE7CF09C-0E9A-11D1-8B7A-0000F8754DA1}
' Printer Orientation Constants
' ========================================================================================

%cdlPortrait                                            = 1
%cdlLandscape                                           = 2

' ########################################################################################
' Interface name = ICommonDialog
' IID = {083039C2-13F4-11D1-8B7E-0000F8754DA1}
' Microsoft Common Dialog Control 6.0 (SP3)
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICommonDialog_INTERFACE_DEFINED)
    %ICommonDialog_INTERFACE_DEFINED = 1

INTERFACE ICommonDialog $IID_ICommonDialog

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Action_ <0> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* psAction
   ' =====================================================================================
   PROPERTY SET Action_ <0> ( _                         ' VTable offset = 32
     BYVAL psAction AS INTEGER _                        ' __in short psAction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <1> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET FileName <1> ( _                        ' VTable offset = 40
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DialogTitle <2> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDialogTitle
   ' =====================================================================================
   PROPERTY SET DialogTitle <2> ( _                     ' VTable offset = 48
     BYVAL pbstrDialogTitle AS WSTRING _                ' __in BSTR pbstrDialogTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Filter <3> ( _                          ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilter
   ' =====================================================================================
   PROPERTY SET Filter <3> ( _                          ' VTable offset = 56
     BYVAL pbstrFilter AS WSTRING _                     ' __in BSTR pbstrFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultExt <4> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDefaultExt
   ' =====================================================================================
   PROPERTY SET DefaultExt <4> ( _                      ' VTable offset = 64
     BYVAL pbstrDefaultExt AS WSTRING _                 ' __in BSTR pbstrDefaultExt
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InitDir <5> ( _                         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrInitDir
   ' =====================================================================================
   PROPERTY SET InitDir <5> ( _                         ' VTable offset = 72
     BYVAL pbstrInitDir AS WSTRING _                    ' __in BSTR pbstrInitDir
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Color <6> ( _                           ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out OLE_COLOR* clrColor
   ' =====================================================================================
   PROPERTY SET Color <6> ( _                           ' VTable offset = 80
     BYVAL clrColor AS DWORD _                          ' __in OLE_COLOR clrColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <7> ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* plFlags
   ' =====================================================================================
   PROPERTY SET Flags <7> ( _                           ' VTable offset = 88
     BYVAL plFlags AS LONG _                            ' __in long plFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontName <8> ( _                        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFontName
   ' =====================================================================================
   PROPERTY SET FontName <8> ( _                        ' VTable offset = 96
     BYVAL pbstrFontName AS WSTRING _                   ' __in BSTR pbstrFontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontBold <9> ( _                        ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbFontBold
   ' =====================================================================================
   PROPERTY SET FontBold <9> ( _                        ' VTable offset = 104
     BYVAL pbFontBold AS INTEGER _                      ' __in VARIANT_BOOL pbFontBold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontItalic <10> ( _                     ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbFontItalic
   ' =====================================================================================
   PROPERTY SET FontItalic <10> ( _                     ' VTable offset = 112
     BYVAL pbFontItalic AS INTEGER _                    ' __in VARIANT_BOOL pbFontItalic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontStrikeThru <11> ( _                 ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbFontStrikeThru
   ' =====================================================================================
   PROPERTY SET FontStrikeThru <11> ( _                 ' VTable offset = 120
     BYVAL pbFontStrikeThru AS INTEGER _                ' __in VARIANT_BOOL pbFontStrikeThru
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontUnderLine <12> ( _                  ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbFontUnderLine
   ' =====================================================================================
   PROPERTY SET FontUnderLine <12> ( _                  ' VTable offset = 128
     BYVAL pbFontUnderLine AS INTEGER _                 ' __in VARIANT_BOOL pbFontUnderLine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FromPage <13> ( _                       ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out short* psFromPage
   ' =====================================================================================
   PROPERTY SET FromPage <13> ( _                       ' VTable offset = 136
     BYVAL psFromPage AS INTEGER _                      ' __in short psFromPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToPage <14> ( _                         ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out short* psToPage
   ' =====================================================================================
   PROPERTY SET ToPage <14> ( _                         ' VTable offset = 144
     BYVAL psToPage AS INTEGER _                        ' __in short psToPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Min <15> ( _                            ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out short* psMin
   ' =====================================================================================
   PROPERTY SET Min <15> ( _                            ' VTable offset = 152
     BYVAL psMin AS INTEGER _                           ' __in short psMin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Max <16> ( _                            ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out short* psMax
   ' =====================================================================================
   PROPERTY SET Max <16> ( _                            ' VTable offset = 160
     BYVAL psMax AS INTEGER _                           ' __in short psMax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Copies <17> ( _                         ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out short* psCopies
   ' =====================================================================================
   PROPERTY SET Copies <17> ( _                         ' VTable offset = 168
     BYVAL psCopies AS INTEGER _                        ' __in short psCopies
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CancelError <18> ( _                    ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbCancelError
   ' =====================================================================================
   PROPERTY SET CancelError <18> ( _                    ' VTable offset = 176
     BYVAL pbCancelError AS INTEGER _                   ' __in VARIANT_BOOL pbCancelError
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFile <19> ( _                       ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrHelpFile
   ' =====================================================================================
   PROPERTY SET HelpFile <19> ( _                       ' VTable offset = 184
     BYVAL pbstrHelpFile AS WSTRING _                   ' __in BSTR pbstrHelpFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpCommand <20> ( _                    ' VTable offset = 188
   ) AS INTEGER                                         ' __retval_out short* psHelpCommand
   ' =====================================================================================
   PROPERTY SET HelpCommand <20> ( _                    ' VTable offset = 192
     BYVAL psHelpCommand AS INTEGER _                   ' __in short psHelpCommand
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpKey <21> ( _                        ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrHelpKey
   ' =====================================================================================
   PROPERTY SET HelpKey <21> ( _                        ' VTable offset = 200
     BYVAL pbstrHelpKey AS WSTRING _                    ' __in BSTR pbstrHelpKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrinterDefault <22> ( _                 ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbPrinterDefault
   ' =====================================================================================
   PROPERTY SET PrinterDefault <22> ( _                 ' VTable offset = 208
     BYVAL pbPrinterDefault AS INTEGER _                ' __in VARIANT_BOOL pbPrinterDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterIndex <23> ( _                    ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out short* psFilterIndex
   ' =====================================================================================
   PROPERTY SET FilterIndex <23> ( _                    ' VTable offset = 216
     BYVAL psFilterIndex AS INTEGER _                   ' __in short psFilterIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContext <24> ( _                    ' VTable offset = 220
   ) AS LONG                                            ' __retval_out long* plHelpContext
   ' =====================================================================================
   PROPERTY SET HelpContext <24> ( _                    ' VTable offset = 224
     BYVAL plHelpContext AS LONG _                      ' __in long plHelpContext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontSize <25> ( _                       ' VTable offset = 228
   ) AS SINGLE                                          ' __retval_out float* pfFontSize
   ' =====================================================================================
   PROPERTY SET FontSize <25> ( _                       ' VTable offset = 232
     BYVAL pfFontSize AS SINGLE _                       ' __in float pfFontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Action <26> ( _                         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out short* psAction
   ' =====================================================================================
   PROPERTY SET Action <26> ( _                         ' VTable offset = 240
     BYVAL psAction AS INTEGER _                        ' __in short psAction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxFileSize <27> ( _                    ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out short* psMaxFileSize
   ' =====================================================================================
   PROPERTY SET MaxFileSize <27> ( _                    ' VTable offset = 248
     BYVAL psMaxFileSize AS INTEGER _                   ' __in short psMaxFileSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hDC <28> ( _                            ' VTable offset = 252
   ) AS LONG                                            ' __retval_out int* pihDC
   ' =====================================================================================
   PROPERTY SET hDC <28> ( _                            ' VTable offset = 256
     BYVAL pihDC AS LONG _                              ' __in int pihDC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileTitle <29> ( _                      ' VTable offset = 260
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileTitle
   ' =====================================================================================
   PROPERTY SET FileTitle <29> ( _                      ' VTable offset = 264
     BYVAL pbstrFileTitle AS WSTRING _                  ' __in BSTR pbstrFileTitle
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowOpen <30> ( _                             ' VTable offset = 268
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowSave <31> ( _                             ' VTable offset = 272
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowColor <32> ( _                            ' VTable offset = 276
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowFont <33> ( _                             ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowPrinter <34> ( _                          ' VTable offset = 284
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowHelp <35> ( _                             ' VTable offset = 288
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 292
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <36> ( _                    ' VTable offset = 296
   ) AS LONG                                            ' __retval_out PrinterOrientationConstants* pOrientation
   ' =====================================================================================
   PROPERTY SET Orientation <36> ( _                    ' VTable offset = 300
     BYVAL PrinterOrientationConstants AS LONG _        ' __in PrinterOrientationConstants pOrientation
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommonDialog_INTERFACE_DEFINED__ */
