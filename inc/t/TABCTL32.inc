' ########################################################################################
' Microsoft Windows
' File: TabCtl32.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TabDlg
' Version: 1.1, Locale ID = 0
' Documentation string: Microsoft Tabbed Dialog Control 6.0 (SP6)
' Path: C:\Software\OCXs\TABCTL32.OCX
' Library GUID: {BDC217C8-ED16-11CD-956C-0000C04E4C0A}
' Help file: C:\Software\OCXs\mstab98.chm
' ########################################################################################

#INCLUDE THIS ONCE
%TABCTL32_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "vbinterf.inc"

$RTLKEY_SSTab = "190B7910-992A-11cf-8AFA-00AA00C00905"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SSTab = GUID$("{BDC217C5-ED16-11CD-956C-0000C04E4C0A}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DSSTabCtlEvents = GUID$("{BDC217C7-ED16-11CD-956C-0000C04E4C0A}")
$IID_ISSTabCtl = GUID$("{2A4FCCB0-DFF1-11CF-8E74-00A0C90F26F8}")

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%ssOLEDropNone                                          = 0            ' &H0
%ssOLEDropManual                                        = 1            ' &H1

' ========================================================================================
' DragOverConstants enum
' IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
' State transition constants for the DragOver and OLEDragOver events.
' ========================================================================================

%ssEnter                                                = 0            ' &H0
%ssLeave                                                = 1            ' &H1
%ssOver                                                 = 2            ' &H2

' ========================================================================================
' ClipBoardConstants enum
' IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
' Clipboard format constants.
' ========================================================================================

%ssCFText                                               = 1            ' &H1
%ssCFBitmap                                             = 2            ' &H2
%ssCFMetafile                                           = 3            ' &H3
%ssCFDIB                                                = 8            ' &H8
%ssCFPalette                                            = 9            ' &H9
%ssCFEMetafile                                          = 14           ' &HE
%ssCFFiles                                              = 15           ' &HF
%ssCFRTF                                                = -16639       ' &HFFFFBF01

' ========================================================================================
' OLEDropEffectConstants enum
' IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
' Drop effect constants for OLE drag and drop events.
' ========================================================================================

%ssOLEDropEffectNone                                    = 0            ' &H0
%ssOLEDropEffectCopy                                    = 1            ' &H1
%ssOLEDropEffectMove                                    = 2            ' &H2
%ssOLEDropEffectScroll                                  = -2147483648  ' &H80000000

' ========================================================================================
' ErrorConstants enum
' IID: {CC5287BF-F932-0099-95A7-0000C04D4C0A}
' Error constants.
' ========================================================================================

%ssOutOfMemory                                          = 7            ' &H7
%ssInvalidPropertyValue                                 = 380          ' &H17C
%ssSetNotSupported                                      = 383          ' &H17F
%ssGetNotSupported                                      = 394          ' &H18A
%ssBadIndex                                             = 381          ' &H17D
%ssInvalidPicture                                       = 481          ' &H1E1
%ssDataObjectLocked                                     = 672          ' &H2A0
%ssExpectedAnArgument                                   = 673          ' &H2A1
%ssInvalidProcedureCall                                 = 5            ' &H5
%ssInvalidObjectUse                                     = 425          ' &H1A9
%ssWrongClipboardFormat                                 = 461          ' &H1CD
%ssRecursiveOleDrag                                     = 674          ' &H2A2
%ssFormatNotByteArray                                   = 675          ' &H2A3
%ssDataNotSetForFormat                                  = 676          ' &H2A4

' ========================================================================================
' MousePointerConstants enum
' IID: {C1A8AF38-1257-101B-8FB0-0020AF039CA3}
' MousePointer constants.
' ========================================================================================

%ssDefault                                              = 0            ' &H0
%ssArrow                                                = 1            ' &H1
%ssCross                                                = 2            ' &H2
%ssIBeam                                                = 3            ' &H3
%ssIcon                                                 = 4            ' &H4
%ssSize                                                 = 5            ' &H5
%ssSizeNESW                                             = 6            ' &H6
%ssSizeNS                                               = 7            ' &H7
%ssSizeNWSE                                             = 8            ' &H8
%ssSizeEW                                               = 9            ' &H9
%ssUpArrow                                              = 10           ' &HA
%ssHourglass                                            = 11           ' &HB
%ssNoDrop                                               = 12           ' &HC
%ssArrowHourglass                                       = 13           ' &HD
%ssArrowQuestion                                        = 14           ' &HE
%ssSizeAll                                              = 15           ' &HF
%ssCustom                                               = 99           ' &H63

' ========================================================================================
' TabOrientationConstants enum
' IID: {CC5287BF-E932-0099-95A7-0000C04D4C0A}
' Constants for TabOrientation property
' ========================================================================================

%ssTabOrientationTop                                    = 0            ' &H0
%ssTabOrientationBottom                                 = 1            ' &H1
%ssTabOrientationLeft                                   = 2            ' &H2
%ssTabOrientationRight                                  = 3            ' &H3

' ========================================================================================
' StyleConstants enum
' IID: {CC5287BF-D932-0099-95A7-0000C04D4C0A}
' Constants for Style property
' ========================================================================================

%ssStyleTabbedDialog                                    = 0            ' &H0
%ssStylePropertyPage                                    = 1            ' &H1

' ########################################################################################
' Interface name = ISSTabCtl
' IID = {2A4FCCB0-DFF1-11CF-8E74-00A0C90F26F8}
' Dispatch interface for Microsoft Tabbed Dialog Control 5.0
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISSTabCtl_INTERFACE_DEFINED)
    %ISSTabCtl_INTERFACE_DEFINED = 1

INTERFACE ISSTabCtl $IID_ISSTabCtl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 32
     BYVAL pocBackColor AS DWORD _                      ' __in OLE_COLOR pocBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-512> ( _                         ' VTable offset = 36
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font <-512> ( _                  ' VTable offset = 40
     BYVAL ppFont AS IFontDisp _                        ' __in IFontDisp* ppFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-513> ( _                    ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pocForeColor
   ' =====================================================================================
   PROPERTY SET ForeColor <-513> ( _                    ' VTable offset = 48
     BYVAL pocForeColor AS DWORD _                      ' __in OLE_COLOR pocForeColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <-518> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrCaption
   ' =====================================================================================
   PROPERTY SET Caption <-518> ( _                      ' VTable offset = 56
     BYVAL pbstrCaption AS WSTRING _                    ' __in BSTR pbstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 64
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out OLE_HANDLE* phWnd
   ' =====================================================================================
   PROPERTY SET hWnd <-515> ( _                         ' VTable offset = 72
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tab_ <0> ( _                            ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short* pTab
   ' =====================================================================================
   PROPERTY SET Tab_ <0> ( _                            ' VTable offset = 80
     BYVAL pTab AS INTEGER _                            ' __in short pTab
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabsPerRow <1> ( _                      ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out short* psTabsPerRow
   ' =====================================================================================
   PROPERTY SET TabsPerRow <1> ( _                      ' VTable offset = 88
     BYVAL psTabsPerRow AS INTEGER _                    ' __in short psTabsPerRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tabs <2> ( _                            ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out short* psTabs
   ' =====================================================================================
   PROPERTY SET Tabs <2> ( _                            ' VTable offset = 96
     BYVAL psTabs AS INTEGER _                          ' __in short psTabs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rows <3> ( _                            ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out short* psRows
   ' =====================================================================================
   PROPERTY SET Rows <3> ( _                            ' VTable offset = 104
     BYVAL psRows AS INTEGER _                          ' __in short psRows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tab <4> ( _                             ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out short* psTab
   ' =====================================================================================
   PROPERTY SET Tab <4> ( _                             ' VTable offset = 112
     BYVAL psTab AS INTEGER _                           ' __in short psTab
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabOrientation <5> ( _                  ' VTable offset = 116
   ) AS LONG                                            ' __retval_out TabOrientationConstants* pTabOrientation
   ' =====================================================================================
   PROPERTY SET TabOrientation <5> ( _                  ' VTable offset = 120
     BYVAL pTabOrientation AS LONG _                    ' __in TabOrientationConstants pTabOrientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <6> ( _                         ' VTable offset = 124
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp** ppPicture
   ' =====================================================================================
   PROPERTY SET Picture <6> ( _                         ' VTable offset = 128
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp* ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Picture <6> ( _                  ' VTable offset = 132
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp* ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowFocusRect <7> ( _                   ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbShowFocusRect
   ' =====================================================================================
   PROPERTY SET ShowFocusRect <7> ( _                   ' VTable offset = 140
     BYVAL pbShowFocusRect AS INTEGER _                 ' __in VARIANT_BOOL pbShowFocusRect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WordWrap <8> ( _                        ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbWordWrap
   ' =====================================================================================
   PROPERTY SET WordWrap <8> ( _                        ' VTable offset = 148
     BYVAL pbWordWrap AS INTEGER _                      ' __in VARIANT_BOOL pbWordWrap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <9> ( _                           ' VTable offset = 152
   ) AS LONG                                            ' __retval_out StyleConstants* pStyle
   ' =====================================================================================
   PROPERTY SET Style <9> ( _                           ' VTable offset = 156
     BYVAL pStyle AS LONG _                             ' __in StyleConstants pStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabHeight <10> ( _                      ' VTable offset = 160
   ) AS SINGLE                                          ' __retval_out float* pfTabHeight
   ' =====================================================================================
   PROPERTY SET TabHeight <10> ( _                      ' VTable offset = 164
     BYVAL pfTabHeight AS SINGLE _                      ' __in float pfTabHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabMaxWidth <11> ( _                    ' VTable offset = 168
   ) AS SINGLE                                          ' __retval_out float* pfTabMaxWidth
   ' =====================================================================================
   PROPERTY SET TabMaxWidth <11> ( _                    ' VTable offset = 172
     BYVAL pfTabMaxWidth AS SINGLE _                    ' __in float pfTabMaxWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MousePointer <12> ( _                   ' VTable offset = 176
   ) AS LONG                                            ' __retval_out MousePointerConstants* pMousePtr
   ' =====================================================================================
   PROPERTY SET MousePointer <12> ( _                   ' VTable offset = 180
     BYVAL pMousePtr AS LONG _                          ' __in MousePointerConstants pMousePtr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MouseIcon <13> ( _                      ' VTable offset = 184
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp** ppMouseIcon
   ' =====================================================================================
   PROPERTY SET MouseIcon <13> ( _                      ' VTable offset = 188
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp* ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MouseIcon <13> ( _               ' VTable offset = 192
     BYVAL ppMouseIcon AS IPictureDisp _                ' __in IPictureDisp* ppMouseIcon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 196
   ) AS LONG                                            ' __retval_out OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 200
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabPicture <14> ( _                     ' VTable offset = 208
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS IPictureDisp                                    ' __retval_out IPictureDisp** ppTabPicture
   ' =====================================================================================
   PROPERTY SET TabPicture <14> ( _                     ' VTable offset = 212
     BYVAL Index AS INTEGER _                           ' __in short Index
   , BYVAL ppTabPicture AS IPictureDisp _               ' __in IPictureDisp* ppTabPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_TabPicture <14> ( _              ' VTable offset = 216
     BYVAL Index AS INTEGER _                           ' __in short Index
   , BYVAL ppTabPicture AS IPictureDisp _               ' __in IPictureDisp* ppTabPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabVisible <15> ( _                     ' VTable offset = 220
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbTabVisible
   ' =====================================================================================
   PROPERTY SET TabVisible <15> ( _                     ' VTable offset = 224
     BYVAL Index AS INTEGER _                           ' __in short Index
   , BYVAL pbTabVisible AS INTEGER _                    ' __in VARIANT_BOOL pbTabVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabEnabled <16> ( _                     ' VTable offset = 228
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbTabEnabled
   ' =====================================================================================
   PROPERTY SET TabEnabled <16> ( _                     ' VTable offset = 232
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   , BYVAL pbTabEnabled AS INTEGER _                    ' __in VARIANT_BOOL pbTabEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TabCaption <17> ( _                     ' VTable offset = 236
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTabCaption
   ' =====================================================================================
   PROPERTY SET TabCaption <17> ( _                     ' VTable offset = 240
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   , BYVAL pbstrTabCaption AS WSTRING _                 ' __in BSTR pbstrTabCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISSTabCtl_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDSSTabCtlEvents
' Interface name = DSSTabCtlEvents
' IID = {BDC217C7-ED16-11CD-956C-0000C04E4C0A}
' Event interface for Microsoft Tabbed Dialog 5.0
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDSSTabCtlEvents GUID$("{A35984AE-8097-42B1-9EEA-B9FDCC834621}") AS EVENT

'INTERFACE DSSTabCtlEventsImpl GUID$("{BDC217C7-ED16-11CD-956C-0000C04E4C0A}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYVAL KeyCode AS INTEGER _                         ' KeyCode VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' *KeyAscii VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYVAL KeyCode AS INTEGER _                         ' KeyCode VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL X AS LONG _                                  ' X OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL Y AS LONG _                                  ' Y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL X AS LONG _                                  ' X OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL Y AS LONG _                                  ' Y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' Button VT_I2 <Integer>
'   , BYVAL iShift AS INTEGER _                          ' Shift VT_I2 <Integer>
'   , BYVAL X AS LONG _                                  ' X OLE_XPOS_PIXELS <alias> <VT_I4>
'   , BYVAL Y AS LONG _                                  ' Y OLE_YPOS_PIXELS <alias> <VT_I4>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <-600> ( _
'     BYVAL PreviousTab AS INTEGER _                     ' PreviousTab VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF AllowedEffects AS LONG _                     ' [in][out] *AllowedEffects VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF DefaultCursors AS INTEGER _                  ' [in][out] *DefaultCursors VT_BOOL <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF DataFormat AS INTEGER _                      ' [in][out] *DataFormat VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF iButton AS INTEGER _                         ' [in][out] *Button VT_I2 <Integer>
'   , BYREF iShift AS INTEGER _                          ' [in][out] *Shift VT_I2 <Integer>
'   , BYREF X AS SINGLE _                                ' [in][out] *X VT_R4 <Single>
'   , BYREF Y AS SINGLE _                                ' [in][out] *Y VT_R4 <Single>
'   , BYREF iState AS INTEGER _                          ' [in][out] *State VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' [in][out] **Data DataObject <coclass>
'   , BYREF Effect AS LONG _                             ' [in][out] *Effect VT_I4 <Long>
'   , BYREF iButton AS INTEGER _                         ' [in][out] *Button VT_I2 <Integer>
'   , BYREF iShift AS INTEGER _                          ' [in][out] *Shift VT_I2 <Integer>
'   , BYREF X AS SINGLE _                                ' [in][out] *X VT_R4 <Single>
'   , BYREF Y AS SINGLE _                                ' [in][out] *Y VT_R4 <Single>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
