' ########################################################################################
' Microsoft Windows
' File: ISysmon.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SystemMonitor
' Version: 3.7, Locale ID = 0
' Description: System Monitor Control
' Path: C:\Windows\system32\sysmon.ocx
' Library GUID: {1B773E42-2509-11CF-942F-008029004347}
' ########################################################################################

#INCLUDE THIS ONCE
%ISYSMON_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "olectl.inc"   ' for StdFont

$LIBID_SystemMonitor = GUID$("{1B773E42-2509-11CF-942F-008029004347}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {C4D2D8E0-D1DD-11CE-940F-008029004347}
$PROGID_SystemMonitor3 = "Sysmon.3"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {C4D2D8E0-D1DD-11CE-940F-008029004347}
$PROGID_SystemMonitor = "Sysmon"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AppearPropPage = GUID$("{E49741E9-93A8-4AB1-8E96-BF4482282E9C}")
$CLSID_CounterItem = GUID$("{C4D2D8E0-D1DD-11CE-940F-008029004348}")
$CLSID_CounterItem2 = GUID$("{43196C62-C31F-4CE3-A02E-79EFE0F6A525}")
$CLSID_CounterPropPage = GUID$("{CF948561-EDE8-11CE-941E-008029004347}")
$CLSID_Counters = GUID$("{B2B066D2-2AAC-11CF-942F-008029004347}")
$CLSID_GeneralPropPage = GUID$("{C3E5D3D2-1A03-11CF-942D-008029004347}")
$CLSID_GraphPropPage = GUID$("{C3E5D3D3-1A03-11CF-942D-008029004347}")
$CLSID_LogFileItem = GUID$("{16EC5BE8-DF93-4237-94E4-9EE918111D71}")
$CLSID_LogFiles = GUID$("{2735D9FD-F6B9-4F19-A5D9-E2D068584BC5}")
$CLSID_SourcePropPage = GUID$("{0CF32AA1-7571-11D0-93C4-00AA00A3DDEA}")
$CLSID_SystemMonitor2 = GUID$("{7F30578C-5F38-4612-ACFE-6ED04C7B7AF8}")
$CLSID_SystemMonitor = GUID$("{C4D2D8E0-D1DD-11CE-940F-008029004347}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DICounterItem = GUID$("{C08C4FF2-0E2E-11CF-942C-008029004347}")
$IID_DILogFileItem = GUID$("{8D093FFC-F777-4917-82D1-833FBC54C58F}")
$IID_DISystemMonitor = GUID$("{13D73D81-C32E-11CF-9398-00AA00A3DDEA}")
$IID_DISystemMonitorEvents = GUID$("{84979930-4AB3-11CF-943A-008029004347}")
$IID_DISystemMonitorInternal = GUID$("{194EB242-C32C-11CF-9398-00AA00A3DDEA}")
$IID_ICounterItem = GUID$("{771A9520-EE28-11CE-941E-008029004347}")
$IID_ICounterItem2 = GUID$("{EEFCD4E1-EA1C-4435-B7F4-E341BA03B4F9}")
$IID_ICounters = GUID$("{79167962-28FC-11CF-942F-008029004347}")
$IID_ILogFileItem = GUID$("{D6B518DD-05C7-418A-89E6-4F9CE8C6841E}")
$IID_ILogFiles = GUID$("{6A2A97E6-6851-41EA-87AD-2A8225335865}")
$IID_IPropertyPage = GUID$("{B196B28D-BAB4-101A-B69C-00AA00341D07}")
$IID_IPropertyPage2 = GUID$("{01E44665-24AC-101B-84ED-08002B2EC713}")
$IID_IPropertyPageSite = GUID$("{B196B28C-BAB4-101A-B69C-00AA00341D07}")
$IID_ISystemMonitor = GUID$("{194EB241-C32C-11CF-9398-00AA00A3DDEA}")
$IID_ISystemMonitor2 = GUID$("{08E3206A-5FD2-4FDE-A8A5-8CB3B63D2677}")
$IID_ISystemMonitorEvents = GUID$("{EE660EA0-4ABD-11CF-943A-008029004347}")
$IID__ICounterItemUnion = GUID$("{DE1A6B74-9182-4C41-8E2C-24C2CD30EE83}")
$IID__ISystemMonitorUnion = GUID$("{C8A77338-265F-4DE5-AA25-C7DA1CE5A8F4}")

' ========================================================================================
' DisplayTypeConstants enum
' System Monitor display type constants
' ========================================================================================

%sysmonLineGraph                                        = 1
%sysmonHistogram                                        = 2
%sysmonReport                                           = 3
%sysmonChartArea                                        = 4
%sysmonChartStackedArea                                 = 5

' ========================================================================================
' ReportValueTypeConstants enum
' System Monitor report value type constants
' ========================================================================================

%sysmonDefaultValue                                     = 0???
%sysmonCurrentValue                                     = &H1???
%sysmonAverage                                          = &H2???
%sysmonMinimum                                          = &H3???
%sysmonMaximum                                          = &H4???

' ========================================================================================
' DataSourceTypeConstants enum
' System Monitor data source type constants
' ========================================================================================

%sysmonNullDataSource                                   = &HFFFFFFFF???
%sysmonCurrentActivity                                  = &H1???
%sysmonLogFiles                                         = &H2???
%sysmonSqlLog                                           = &H3???

' ========================================================================================
' SysmonFileType enum
' Different file types sysmon supports.
' ========================================================================================

%sysmonFileHtml                                         = 1
%sysmonFileReport                                       = 2
%sysmonFileCsv                                          = 3
%sysmonFileTsv                                          = 4
%sysmonFileBlg                                          = 5
%sysmonFileRetiredBlg                                   = 6
%sysmonFileGif                                          = 7

' ========================================================================================
' SysmonDataType enum
' Different data types.
' ========================================================================================

%sysmonDataAvg                                          = 1
%sysmonDataMin                                          = 2
%sysmonDataMax                                          = 3
%sysmonDataTime                                         = 4
%sysmonDataCount                                        = 5

' ========================================================================================
' SysmonBatchReason enum
' Reason for batching operation.
' ========================================================================================

%sysmonBatchNone                                        = 0
%sysmonBatchAddFiles                                    = 1
%sysmonBatchAddCounters                                 = 2
%sysmonBatchAddFilesAutoCounters                        = 3

' ########################################################################################
' Interface name = ICounterItem
' IID = {771A9520-EE28-11CE-941E-008029004347}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICounterItem_INTERFACE_DEFINED)
    %ICounterItem_INTERFACE_DEFINED = 1

INTERFACE ICounterItem $IID_ICounterItem

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 12
   ) AS DOUBLE                                          ' __retval_out double *pdblValue
   ' =====================================================================================
   PROPERTY SET Color ( _                               ' VTable offset = 16
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Color ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET Width ( _                               ' VTable offset = 24
     BYVAL iWidth AS LONG _                             ' __in INT iWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET LineStyle ( _                           ' VTable offset = 32
     BYVAL iLineStyle AS LONG _                         ' __in INT iLineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET ScaleFactor ( _                         ' VTable offset = 40
     BYVAL iScale AS LONG _                             ' __in INT iScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleFactor ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET Path ( _                                ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pstrValue
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 52
     BYREF Value AS DOUBLE _                            ' __out double *Value
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 56
     BYREF Max AS DOUBLE _                              ' __out double *Max
   , BYREF Min AS DOUBLE _                              ' __out double *Min
   , BYREF Avg AS DOUBLE _                              ' __out double *Avg
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICounterItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICounterItem2
' IID = {EEFCD4E1-EA1C-4435-B7F4-E341BA03B4F9}
' Inherited interface = ICounterItem
' ########################################################################################

#IF NOT %DEF(%ICounterItem2_INTERFACE_DEFINED)
    %ICounterItem2_INTERFACE_DEFINED = 1

INTERFACE ICounterItem2 $IID_ICounterItem2

   INHERIT IAutomation

   ' =====================================================================================
   ' ICounterItem Methods
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 12
   ) AS DOUBLE                                          ' __retval_out double *pdblValue
   ' =====================================================================================
   PROPERTY SET Color ( _                               ' VTable offset = 16
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Color ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET Width ( _                               ' VTable offset = 24
     BYVAL iWidth AS LONG _                             ' __in INT iWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET LineStyle ( _                           ' VTable offset = 32
     BYVAL iLineStyle AS LONG _                         ' __in INT iLineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET ScaleFactor ( _                         ' VTable offset = 40
     BYVAL iScale AS LONG _                             ' __in INT iScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleFactor ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET Path ( _                                ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pstrValue
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 52
     BYREF Value AS DOUBLE _                            ' __out double *Value
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 56
     BYREF Max AS DOUBLE _                              ' __out double *Max
   , BYREF Min AS DOUBLE _                              ' __out double *Min
   , BYREF Avg AS DOUBLE _                              ' __out double *Avg
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICounterItem2 Methods
   ' =====================================================================================
   PROPERTY SET Selected ( _                            ' VTable offset = 60
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected ( _                            ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET Visible ( _                             ' VTable offset = 68
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible ( _                             ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   METHOD GetDataAt ( _                                 ' VTable offset = 76
     BYVAL iIndex AS LONG _                             ' __in INT iIndex
   , BYVAL iWhich AS LONG _                             ' __in SysmonDataType iWhich
   , BYREF pVariant AS VARIANT _                        ' __out VARIANT *pVariant
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICounterItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _ICounterItemUnion
' IID = {DE1A6B74-9182-4C41-8E2C-24C2CD30EE83}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICounterItemUnion_INTERFACE_DEFINED)
    %ICounterItemUnion_INTERFACE_DEFINED = 1

INTERFACE ICounterItemUnion $IID__ICounterItemUnion

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 12
   ) AS DOUBLE                                          ' __retval_out double *pdblValue
   ' =====================================================================================
   PROPERTY SET Color ( _                               ' VTable offset = 16
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Color ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET Width ( _                               ' VTable offset = 24
     BYVAL iWidth AS LONG _                             ' __in INT iWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET LineStyle ( _                           ' VTable offset = 32
     BYVAL iLineStyle AS LONG _                         ' __in INT iLineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET ScaleFactor ( _                         ' VTable offset = 40
     BYVAL iScale AS LONG _                             ' __in INT iScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleFactor ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET Path ( _                                ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pstrValue
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 52
     BYREF Value AS DOUBLE _                            ' __out double *Value
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 56
     BYREF Max AS DOUBLE _                              ' __out double *Max
   , BYREF Min AS DOUBLE _                              ' __out double *Min
   , BYREF Avg AS DOUBLE _                              ' __out double *Avg
   , BYREF Status AS LONG _                             ' __out long *Status
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Selected ( _                            ' VTable offset = 60
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected ( _                            ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET Visible ( _                             ' VTable offset = 68
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible ( _                             ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   METHOD GetDataAt ( _                                 ' VTable offset = 76
     BYVAL iIndex AS LONG _                             ' __in INT iIndex
   , BYVAL iWhich AS LONG _                             ' __in SysmonDataType iWhich
   , BYREF pVariant AS VARIANT _                        ' __out VARIANT *pVariant
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICounterItemUnion_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CounterItem
' Interface name = DICounterItem
' IID = {C08C4FF2-0E2E-11CF-942C-008029004347}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DICounterItem_DISPINTERFACE_DEFINED)
    %DICounterItem_DISPINTERFACE_DEFINED = 1

INTERFACE DICounterItem $IID_DICounterItem

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DICounterItem_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICounters
' IID = {79167962-28FC-11CF-942F-008029004347}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICounters_INTERFACE_DEFINED)
    %ICounters_INTERFACE_DEFINED = 1

INTERFACE ICounters $IID_ICounters

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pLong
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIunk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS DICounterItem                                   ' __retval_out DICounterItem **ppI
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL pathname AS WSTRING _                        ' __in BSTR pathname
   ) AS DICounterItem                                   ' __retval_out DICounterItem **ppI
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICounters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogFileItem
' IID = {D6B518DD-05C7-418A-89E6-4F9CE8C6841E}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILogFileItem_INTERFACE_DEFINED)
    %ILogFileItem_INTERFACE_DEFINED = 1

INTERFACE ILogFileItem $IID_ILogFileItem

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Path ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pstrValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogFileItem_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = LogFileItem
' Interface name = DILogFileItem
' IID = {8D093FFC-F777-4917-82D1-833FBC54C58F}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DILogFileItem_DISPINTERFACE_DEFINED)
    %DILogFileItem_DISPINTERFACE_DEFINED = 1

INTERFACE DILogFileItem $IID_DILogFileItem

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DILogFileItem_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogFiles
' IID = {6A2A97E6-6851-41EA-87AD-2A8225335865}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILogFiles_INTERFACE_DEFINED)
    %ILogFiles_INTERFACE_DEFINED = 1

INTERFACE ILogFiles $IID_ILogFiles

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pLong
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIunk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS DILogFileItem                                   ' __retval_out DILogFileItem **ppI
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL pathname AS WSTRING _                        ' __in BSTR pathname
   ) AS DILogFileItem                                   ' __retval_out DILogFileItem **ppI
   ' =====================================================================================
   METHOD Remove <1610743812> ( _                       ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogFiles_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISystemMonitor
' IID = {194EB241-C32C-11CF-9398-00AA00A3DDEA}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISystemMonitor_INTERFACE_DEFINED)
    %ISystemMonitor_INTERFACE_DEFINED = 1

INTERFACE ISystemMonitor $IID_ISystemMonitor

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Appearance ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out INT *iAppearance
   ' =====================================================================================
   PROPERTY SET Appearance ( _                          ' VTable offset = 16
     BYVAL iAppearance AS LONG _                        ' __in INT iAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor ( _                           ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColor ( _                           ' VTable offset = 24
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *iBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle ( _                         ' VTable offset = 32
     BYVAL iBorderStyle AS LONG _                       ' __in INT iBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor ( _                           ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET ForeColor ( _                           ' VTable offset = 40
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font ( _                                ' VTable offset = 44
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font ( _                         ' VTable offset = 48
     BYVAL pFont AS IFontDisp _                         ' __in IFontDisp *pFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Counters ( _                            ' VTable offset = 52
   ) AS ICounters                                       ' __retval_out ICounters **ppICounters
   ' =====================================================================================
   PROPERTY SET ShowVerticalGrid ( _                    ' VTable offset = 56
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowVerticalGrid ( _                    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowHorizontalGrid ( _                  ' VTable offset = 64
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowHorizontalGrid ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowLegend ( _                          ' VTable offset = 72
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowLegend ( _                          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowScaleLabels ( _                     ' VTable offset = 80
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowScaleLabels ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowValueBar ( _                        ' VTable offset = 88
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowValueBar ( _                        ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET MaximumScale ( _                        ' VTable offset = 96
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaximumScale ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET MinimumScale ( _                        ' VTable offset = 104
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinimumScale ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET UpdateInterval ( _                      ' VTable offset = 112
     BYVAL fValue AS SINGLE _                           ' __in FLOAT fValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateInterval ( _                      ' VTable offset = 116
   ) AS SINGLE                                          ' __retval_out FLOAT *pfValue
   ' =====================================================================================
   PROPERTY SET DisplayType ( _                         ' VTable offset = 120
     BYVAL eDisplayType AS LONG _                       ' __in DisplayTypeConstants eDisplayType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayType ( _                         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out DisplayTypeConstants *peDisplayType
   ' =====================================================================================
   PROPERTY SET ManualUpdate ( _                        ' VTable offset = 128
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManualUpdate ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET GraphTitle ( _                          ' VTable offset = 136
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraphTitle ( _                          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   PROPERTY SET YAxisLabel ( _                          ' VTable offset = 144
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET YAxisLabel ( _                          ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   METHOD CollectSample ( _                             ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateGraph ( _                               ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD BrowseCounters ( _                            ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayProperties ( _                         ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Counter ( _                                   ' VTable offset = 168
     BYVAL iIndex AS LONG _                             ' __in INT iIndex
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD AddCounter ( _                                ' VTable offset = 172
     BYVAL bsPath AS WSTRING _                          ' __in BSTR bsPath
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteCounter ( _                             ' VTable offset = 176
     BYVAL pCtr AS ICounterItem _                       ' __in ICounterItem *pCtr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColorCtl ( _                        ' VTable offset = 180
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColorCtl ( _                        ' VTable offset = 184
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LogFileName ( _                         ' VTable offset = 188
     BYVAL bsFileName AS WSTRING _                      ' __in BSTR bsFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogFileName ( _                         ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *bsFileName
   ' =====================================================================================
   PROPERTY SET LogViewStart ( _                        ' VTable offset = 196
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStart ( _                        ' VTable offset = 200
   ) AS DOUBLE                                          ' __retval_out DATE *StartTime
   ' =====================================================================================
   PROPERTY SET LogViewStop ( _                         ' VTable offset = 204
     BYVAL StopTime AS DOUBLE _                         ' __in DATE StopTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStop ( _                         ' VTable offset = 208
   ) AS DOUBLE                                          ' __retval_out DATE *StopTime
   ' =====================================================================================
   PROPERTY GET GridColor ( _                           ' VTable offset = 212
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET GridColor ( _                           ' VTable offset = 216
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeBarColor ( _                        ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET TimeBarColor ( _                        ' VTable offset = 224
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Highlight ( _                           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET Highlight ( _                           ' VTable offset = 232
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowToolbar ( _                         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowToolbar ( _                         ' VTable offset = 240
     BYVAL bState  AS INTEGER _                         ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   METHOD Paste ( _                                     ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ReadOnly ( _                            ' VTable offset = 256
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadOnly ( _                            ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ReportValueType ( _                     ' VTable offset = 264
     BYVAL eReportValueType AS LONG _                   ' __in ReportValueTypeConstants eReportValueType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReportValueType ( _                     ' VTable offset = 268
   ) AS LONG                                            ' __retval_out ReportValueTypeConstants *peReportValueType
   ' =====================================================================================
   PROPERTY SET MonitorDuplicateInstances ( _           ' VTable offset = 272
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonitorDuplicateInstances ( _           ' VTable offset = 276
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET DisplayFilter ( _                       ' VTable offset = 280
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayFilter ( _                       ' VTable offset = 284
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET LogFiles ( _                            ' VTable offset = 288
   ) AS ILogFiles                                       ' __retval_out ILogFiles **ppILogFiles
   ' =====================================================================================
   PROPERTY SET DataSourceType ( _                      ' VTable offset = 292
     BYVAL eDataSourceType AS LONG _                    ' __in DataSourceTypeConstants eDataSourceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSourceType ( _                      ' VTable offset = 296
   ) AS LONG                                            ' __retval_out DataSourceTypeConstants *peDataSourceType
   ' =====================================================================================
   PROPERTY SET SqlDsnName ( _                          ' VTable offset = 300
     BYVAL bsSqlDsnName AS WSTRING _                    ' __in BSTR bsSqlDsnName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlDsnName ( _                          ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlDsnName
   ' =====================================================================================
   PROPERTY SET SqlLogSetName ( _                       ' VTable offset = 308
     BYVAL bsSqlLogSetName AS WSTRING _                 ' __in BSTR bsSqlLogSetName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlLogSetName ( _                       ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlLogSetName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISystemMonitor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISystemMonitor2
' IID = {08E3206A-5FD2-4FDE-A8A5-8CB3B63D2677}
' Inherited interface = ISystemMonitor
' ########################################################################################

#IF NOT %DEF(%ISystemMonitor2_INTERFACE_DEFINED)
    %ISystemMonitor2_INTERFACE_DEFINED = 1

INTERFACE ISystemMonitor2 $IID_ISystemMonitor2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISystemMonitor Methods
   ' =====================================================================================
   PROPERTY GET Appearance ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out INT *iAppearance
   ' =====================================================================================
   PROPERTY SET Appearance ( _                          ' VTable offset = 16
     BYVAL iAppearance AS LONG _                        ' __in INT iAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor ( _                           ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColor ( _                           ' VTable offset = 24
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *iBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle ( _                         ' VTable offset = 32
     BYVAL iBorderStyle AS LONG _                       ' __in INT iBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor ( _                           ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET ForeColor ( _                           ' VTable offset = 40
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font ( _                                ' VTable offset = 44
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font ( _                         ' VTable offset = 48
     BYVAL pFont AS IFontDisp _                         ' __in IFontDisp *pFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Counters ( _                            ' VTable offset = 52
   ) AS ICounters                                       ' __retval_out ICounters **ppICounters
   ' =====================================================================================
   PROPERTY SET ShowVerticalGrid ( _                    ' VTable offset = 56
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowVerticalGrid ( _                    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowHorizontalGrid ( _                  ' VTable offset = 64
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowHorizontalGrid ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowLegend ( _                          ' VTable offset = 72
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowLegend ( _                          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowScaleLabels ( _                     ' VTable offset = 80
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowScaleLabels ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowValueBar ( _                        ' VTable offset = 88
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowValueBar ( _                        ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET MaximumScale ( _                        ' VTable offset = 96
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaximumScale ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET MinimumScale ( _                        ' VTable offset = 104
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinimumScale ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET UpdateInterval ( _                      ' VTable offset = 112
     BYVAL fValue AS SINGLE _                           ' __in FLOAT fValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateInterval ( _                      ' VTable offset = 116
   ) AS SINGLE                                          ' __retval_out FLOAT *pfValue
   ' =====================================================================================
   PROPERTY SET DisplayType ( _                         ' VTable offset = 120
     BYVAL eDisplayType AS LONG _                       ' __in DisplayTypeConstants eDisplayType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayType ( _                         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out DisplayTypeConstants *peDisplayType
   ' =====================================================================================
   PROPERTY SET ManualUpdate ( _                        ' VTable offset = 128
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManualUpdate ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET GraphTitle ( _                          ' VTable offset = 136
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraphTitle ( _                          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   PROPERTY SET YAxisLabel ( _                          ' VTable offset = 144
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET YAxisLabel ( _                          ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   METHOD CollectSample ( _                             ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateGraph ( _                               ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD BrowseCounters ( _                            ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayProperties ( _                         ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Counter ( _                                   ' VTable offset = 168
     BYVAL iIndex AS LONG _                             ' __in INT iIndex
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD AddCounter ( _                                ' VTable offset = 172
     BYVAL bsPath AS WSTRING _                          ' __in BSTR bsPath
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteCounter ( _                             ' VTable offset = 176
     BYVAL pCtr AS ICounterItem _                       ' __in ICounterItem *pCtr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColorCtl ( _                        ' VTable offset = 180
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColorCtl ( _                        ' VTable offset = 184
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LogFileName ( _                         ' VTable offset = 188
     BYVAL bsFileName AS WSTRING _                      ' __in BSTR bsFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogFileName ( _                         ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *bsFileName
   ' =====================================================================================
   PROPERTY SET LogViewStart ( _                        ' VTable offset = 196
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStart ( _                        ' VTable offset = 200
   ) AS DOUBLE                                          ' __retval_out DATE *StartTime
   ' =====================================================================================
   PROPERTY SET LogViewStop ( _                         ' VTable offset = 204
     BYVAL StopTime AS DOUBLE _                         ' __in DATE StopTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStop ( _                         ' VTable offset = 208
   ) AS DOUBLE                                          ' __retval_out DATE *StopTime
   ' =====================================================================================
   PROPERTY GET GridColor ( _                           ' VTable offset = 212
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET GridColor ( _                           ' VTable offset = 216
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeBarColor ( _                        ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET TimeBarColor ( _                        ' VTable offset = 224
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Highlight ( _                           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET Highlight ( _                           ' VTable offset = 232
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowToolbar ( _                         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowToolbar ( _                         ' VTable offset = 240
     BYVAL bState  AS INTEGER _                         ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   METHOD Paste ( _                                     ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ReadOnly ( _                            ' VTable offset = 256
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadOnly ( _                            ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ReportValueType ( _                     ' VTable offset = 264
     BYVAL eReportValueType AS LONG _                   ' __in ReportValueTypeConstants eReportValueType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReportValueType ( _                     ' VTable offset = 268
   ) AS LONG                                            ' __retval_out ReportValueTypeConstants *peReportValueType
   ' =====================================================================================
   PROPERTY SET MonitorDuplicateInstances ( _           ' VTable offset = 272
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonitorDuplicateInstances ( _           ' VTable offset = 276
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET DisplayFilter ( _                       ' VTable offset = 280
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayFilter ( _                       ' VTable offset = 284
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET LogFiles ( _                            ' VTable offset = 288
   ) AS ILogFiles                                       ' __retval_out ILogFiles **ppILogFiles
   ' =====================================================================================
   PROPERTY SET DataSourceType ( _                      ' VTable offset = 292
     BYVAL eDataSourceType AS LONG _                    ' __in DataSourceTypeConstants eDataSourceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSourceType ( _                      ' VTable offset = 296
   ) AS LONG                                            ' __retval_out DataSourceTypeConstants *peDataSourceType
   ' =====================================================================================
   PROPERTY SET SqlDsnName ( _                          ' VTable offset = 300
     BYVAL bsSqlDsnName AS WSTRING _                    ' __in BSTR bsSqlDsnName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlDsnName ( _                          ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlDsnName
   ' =====================================================================================
   PROPERTY SET SqlLogSetName ( _                       ' VTable offset = 308
     BYVAL bsSqlLogSetName AS WSTRING _                 ' __in BSTR bsSqlLogSetName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlLogSetName ( _                       ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlLogSetName
   ' =====================================================================================

   ' =====================================================================================
   ' ISystemMonitor2 Methods
   ' =====================================================================================
   PROPERTY SET EnableDigitGrouping ( _                 ' VTable offset = 316
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableDigitGrouping ( _                 ' VTable offset = 320
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET EnableToolTips ( _                      ' VTable offset = 324
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableToolTips ( _                      ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowTimeAxisLabels ( _                  ' VTable offset = 332
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTimeAxisLabels ( _                  ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ChartScroll ( _                         ' VTable offset = 340
     BYVAL bScroll AS INTEGER _                         ' __in VARIANT_BOOL bScroll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChartScroll ( _                         ' VTable offset = 344
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbScroll
   ' =====================================================================================
   PROPERTY SET DataPointCount ( _                      ' VTable offset = 348
     BYVAL iNewCount AS LONG _                          ' __in INT iNewCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataPointCount ( _                      ' VTable offset = 352
   ) AS LONG                                            ' __retval_out INT *piDataPointCount
   ' =====================================================================================
   METHOD ScaleToFit ( _                                ' VTable offset = 356
     BYVAL bSelectedCountersOnly AS INTEGER _           ' VARIANT_BOOL bSelectedCountersOnly
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveAs ( _                                    ' VTable offset = 360
     BYVAL bstrFileName AS WSTRING _                    ' BSTR bstrFileName
   , BYVAL eSysmonFileType AS LONG _                    ' SysmonFileType eSysmonFileType
   )                                                    ' void
   ' =====================================================================================
   METHOD Relog ( _                                     ' VTable offset = 364
     BYVAL bstrFileName AS WSTRING _                    ' BSTR bstrFileName
   , BYVAL eSysmonFileType AS LONG _                    ' SysmonFileType eSysmonFileType
   , BYVAL iFilter AS LONG _                            ' INT iFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearData ( _                                 ' VTable offset = 368
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogSourceStartTime ( _                  ' VTable offset = 372
   ) AS DOUBLE                                          ' __out DATE *pDate
   ' =====================================================================================
   PROPERTY GET LogSourceStopTime ( _                   ' VTable offset = 376
   ) AS DOUBLE                                          ' __out DATE *pDate
   ' =====================================================================================
   METHOD SetLogViewRange ( _                           ' VTable offset = 380
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   , BYVAL StopTime AS DOUBLE _                         ' __in DATE StopTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLogViewRange ( _                           ' VTable offset = 384
     BYREF StartTime AS DOUBLE _                        ' __out DATE *StartTime
   , BYREF StopTime AS DOUBLE _                         ' __out DATE *StopTime
   )                                                    ' void
   ' =====================================================================================
   METHOD BatchingLock ( _                              ' VTable offset = 388
     BYVAL fLock AS INTEGER _                           ' __in VARIANT_BOOL fLock
   , BYVAL eBatchReason AS LONG _                       ' __in SysmonBatchReason eBatchReason
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadSettings ( _                              ' VTable offset = 392
     BYVAL bstrSettingFileName AS WSTRING _             ' __in BSTR bstrSettingFileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISystemMonitor2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _ISystemMonitorUnion
' IID = {C8A77338-265F-4DE5-AA25-C7DA1CE5A8F4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISystemMonitorUnion_INTERFACE_DEFINED)
    %ISystemMonitorUnion_INTERFACE_DEFINED = 1

INTERFACE ISystemMonitorUnion $IID__ISystemMonitorUnion

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Appearance ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out INT *iAppearance
   ' =====================================================================================
   PROPERTY SET Appearance ( _                          ' VTable offset = 16
     BYVAL iAppearance AS LONG _                        ' __in INT iAppearance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor ( _                           ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColor ( _                           ' VTable offset = 24
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT *iBorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle ( _                         ' VTable offset = 32
     BYVAL iBorderStyle AS LONG _                       ' __in INT iBorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor ( _                           ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET ForeColor ( _                           ' VTable offset = 40
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font ( _                                ' VTable offset = 44
   ) AS IFontDisp                                       ' __retval_out IFontDisp **ppFont
   ' =====================================================================================
   PROPERTY SET putref_Font ( _                         ' VTable offset = 48
     BYVAL pFont AS IFontDisp _                         ' __in IFontDisp *pFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Counters ( _                            ' VTable offset = 52
   ) AS ICounters                                       ' __retval_out ICounters **ppICounters
   ' =====================================================================================
   PROPERTY SET ShowVerticalGrid ( _                    ' VTable offset = 56
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowVerticalGrid ( _                    ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowHorizontalGrid ( _                  ' VTable offset = 64
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowHorizontalGrid ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowLegend ( _                          ' VTable offset = 72
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowLegend ( _                          ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowScaleLabels ( _                     ' VTable offset = 80
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowScaleLabels ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowValueBar ( _                        ' VTable offset = 88
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowValueBar ( _                        ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET MaximumScale ( _                        ' VTable offset = 96
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaximumScale ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET MinimumScale ( _                        ' VTable offset = 104
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinimumScale ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY SET UpdateInterval ( _                      ' VTable offset = 112
     BYVAL fValue AS SINGLE _                           ' __in FLOAT fValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateInterval ( _                      ' VTable offset = 116
   ) AS SINGLE                                          ' __retval_out FLOAT *pfValue
   ' =====================================================================================
   PROPERTY SET DisplayType ( _                         ' VTable offset = 120
     BYVAL eDisplayType AS LONG _                       ' __in DisplayTypeConstants eDisplayType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayType ( _                         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out DisplayTypeConstants *peDisplayType
   ' =====================================================================================
   PROPERTY SET ManualUpdate ( _                        ' VTable offset = 128
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManualUpdate ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET GraphTitle ( _                          ' VTable offset = 136
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraphTitle ( _                          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   PROPERTY SET YAxisLabel ( _                          ' VTable offset = 144
     BYVAL bsTitle AS WSTRING _                         ' __in BSTR bsTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET YAxisLabel ( _                          ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbsTitle
   ' =====================================================================================
   METHOD CollectSample ( _                             ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateGraph ( _                               ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD BrowseCounters ( _                            ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayProperties ( _                         ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD Counter ( _                                   ' VTable offset = 168
     BYVAL iIndex AS LONG _                             ' __in INT iIndex
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD AddCounter ( _                                ' VTable offset = 172
     BYVAL bsPath AS WSTRING _                          ' __in BSTR bsPath
   , BYREF ppICounter AS ICounterItem _                 ' __out ICounterItem **ppICounter
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteCounter ( _                             ' VTable offset = 176
     BYVAL pCtr AS ICounterItem _                       ' __in ICounterItem *pCtr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColorCtl ( _                        ' VTable offset = 180
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET BackColorCtl ( _                        ' VTable offset = 184
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LogFileName ( _                         ' VTable offset = 188
     BYVAL bsFileName AS WSTRING _                      ' __in BSTR bsFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogFileName ( _                         ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *bsFileName
   ' =====================================================================================
   PROPERTY SET LogViewStart ( _                        ' VTable offset = 196
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStart ( _                        ' VTable offset = 200
   ) AS DOUBLE                                          ' __retval_out DATE *StartTime
   ' =====================================================================================
   PROPERTY SET LogViewStop ( _                         ' VTable offset = 204
     BYVAL StopTime AS DOUBLE _                         ' __in DATE StopTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogViewStop ( _                         ' VTable offset = 208
   ) AS DOUBLE                                          ' __retval_out DATE *StopTime
   ' =====================================================================================
   PROPERTY GET GridColor ( _                           ' VTable offset = 212
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET GridColor ( _                           ' VTable offset = 216
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeBarColor ( _                        ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pColor
   ' =====================================================================================
   PROPERTY SET TimeBarColor ( _                        ' VTable offset = 224
     BYVAL Color AS DWORD _                             ' __in OLE_COLOR Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Highlight ( _                           ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET Highlight ( _                           ' VTable offset = 232
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowToolbar ( _                         ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowToolbar ( _                         ' VTable offset = 240
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   METHOD Paste ( _                                     ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ReadOnly ( _                            ' VTable offset = 256
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadOnly ( _                            ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ReportValueType ( _                     ' VTable offset = 264
     BYVAL eReportValueType AS LONG _                   ' __in ReportValueTypeConstants eReportValueType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReportValueType ( _                     ' VTable offset = 268
   ) AS LONG                                            ' __retval_out ReportValueTypeConstants *peReportValueType
   ' =====================================================================================
   PROPERTY SET MonitorDuplicateInstances ( _           ' VTable offset = 272
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonitorDuplicateInstances ( _           ' VTable offset = 276
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET DisplayFilter ( _                       ' VTable offset = 280
     BYVAL iValue AS LONG _                             ' __in INT iValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayFilter ( _                       ' VTable offset = 284
   ) AS LONG                                            ' __retval_out INT *piValue
   ' =====================================================================================
   PROPERTY GET LogFiles ( _                            ' VTable offset = 288
   ) AS ILogFiles                                       ' __retval_out ILogFiles **ppILogFiles
   ' =====================================================================================
   PROPERTY SET DataSourceType ( _                      ' VTable offset = 292
     BYVAL LeDataSourceType AS LONG _                   ' __in DataSourceTypeConstants eDataSourceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSourceType ( _                      ' VTable offset = 296
   ) AS LONG                                            ' __retval_out DataSourceTypeConstants *peDataSourceType
   ' =====================================================================================
   PROPERTY SET SqlDsnName ( _                          ' VTable offset = 300
     BYVAL bsSqlDsnName AS WSTRING _                    ' __in BSTR bsSqlDsnName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlDsnName ( _                          ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlDsnName
   ' =====================================================================================
   PROPERTY SET SqlLogSetName ( _                       ' VTable offset = 308
     BYVAL bsSqlLogSetName AS WSTRING _                 ' __in BSTR bsSqlLogSetName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SqlLogSetName ( _                       ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *bsSqlLogSetName
   ' =====================================================================================
   PROPERTY SET EnableDigitGrouping ( _                 ' VTable offset = 316
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableDigitGrouping ( _                 ' VTable offset = 320
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET EnableToolTips ( _                      ' VTable offset = 324
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableToolTips ( _                      ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ShowTimeAxisLabels ( _                  ' VTable offset = 332
     BYVAL bState AS INTEGER _                          ' __in VARIANT_BOOL bState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTimeAxisLabels ( _                  ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbState
   ' =====================================================================================
   PROPERTY SET ChartScroll ( _                         ' VTable offset = 340
     BYVAL bScroll AS INTEGER _                         ' __in VARIANT_BOOL bScroll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChartScroll ( _                         ' VTable offset = 344
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbScroll
   ' =====================================================================================
   PROPERTY SET DataPointCount ( _                      ' VTable offset = 348
     BYVAL iNewCount AS LONG _                          ' __in INT iNewCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataPointCount ( _                      ' VTable offset = 352
   ) AS LONG                                            ' __retval_out INT *piDataPointCount
   ' =====================================================================================
   METHOD ScaleToFit ( _                                ' VTable offset = 356
     BYVAL bSelectedCountersOnly AS INTEGER _           ' VARIANT_BOOL bSelectedCountersOnly
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveAs ( _                                    ' VTable offset = 360
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   , BYVAL eSysmonFileType AS LONG _                    ' __in SysmonFileType eSysmonFileType
   )                                                    ' void
   ' =====================================================================================
   METHOD Relog ( _                                     ' VTable offset = 364
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   , BYVAL eSysmonFileType AS LONG _                    ' __in SysmonFileType eSysmonFileType
   , BYVAL iFilter AS LONG _                            ' __in INT iFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearData ( _                                 ' VTable offset = 368
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogSourceStartTime ( _                  ' VTable offset = 372
   ) AS DOUBLE                                          ' __out DATE *pDate
   ' =====================================================================================
   PROPERTY GET LogSourceStopTime ( _                   ' VTable offset = 376
   ) AS DOUBLE                                          ' __out DATE *pDate
   ' =====================================================================================
   METHOD SetLogViewRange ( _                           ' VTable offset = 380
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   , BYVAL StopTime AS DOUBLE _                         ' __in DATE StopTime
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLogViewRange ( _                           ' VTable offset = 384
     BYREF StartTime AS DOUBLE _                        ' __out DATE *StartTime
   , BYREF StopTime AS DOUBLE _                         ' __out DATE *StopTime
   )                                                    ' void
   ' =====================================================================================
   METHOD BatchingLock ( _                              ' VTable offset = 388
     BYVAL fLock AS INTEGER _                           ' __in VARIANT_BOOL fLock
   , BYVAL eBatchReason AS LONG _                       ' __in SysmonBatchReason eBatchReason
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadSettings ( _                              ' VTable offset = 392
     BYVAL bstrSettingFileName AS WSTRING _             ' __in BSTR bstrSettingFileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISystemMonitorUnion_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = SystemMonitor
' Interface name = DISystemMonitor
' IID = {13D73D81-C32E-11CF-9398-00AA00A3DDEA}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DISystemMonitor_DISPINTERFACE_DEFINED)
    %DISystemMonitor_DISPINTERFACE_DEFINED = 1

INTERFACE DISystemMonitor $IID_DISystemMonitor

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DISystemMonitor_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DISystemMonitorInternal
' IID = {194EB242-C32C-11CF-9398-00AA00A3DDEA}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DISystemMonitorInternal_DISPINTERFACE_DEFINED)
    %DISystemMonitorInternal_DISPINTERFACE_DEFINED = 1

INTERFACE DISystemMonitorInternal $IID_DISystemMonitorInternal

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DISystemMonitorInternal_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISystemMonitorEvents
' IID = {EE660EA0-4ABD-11CF-943A-008029004347}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISystemMonitorEvents_INTERFACE_DEFINED)
    %ISystemMonitorEvents_INTERFACE_DEFINED = 1

INTERFACE ISystemMonitorEvents $IID_ISystemMonitorEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCounterSelected ( _                         ' VTable offset = 12
     BYVAL Index AS LONG _                              ' __in INT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD OnCounterAdded ( _                            ' VTable offset = 16
     BYVAL Index AS LONG _                              ' __in INT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD OnCounterDeleted ( _                          ' VTable offset = 20
     BYVAL Index AS LONG _                              ' __in INT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSampleCollected ( _                         ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDblClick ( _                                ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in INT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISystemMonitorEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DISystemMonitorEvents
' IID = {84979930-4AB3-11CF-943A-008029004347}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DISystemMonitorEvents_DISPINTERFACE_DEFINED)
    %DISystemMonitorEvents_DISPINTERFACE_DEFINED = 1

INTERFACE DISystemMonitorEvents $IID_DISystemMonitorEvents

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __DISystemMonitorEvents_DISPINTERFACE_DEFINED__ */
