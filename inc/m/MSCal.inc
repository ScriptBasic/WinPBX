' ########################################################################################
' Microsoft Windows
' File: MSCal.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSACAL
' Version: 7.0, Locale ID = 0
' Description: Control de calendario de Microsoft 11.0
' Documentation string: Microsoft Calendar Control 11.0
' Path: C:\Program Files\Microsoft Office\OFFICE11\MSCAL.OCX
' Library GUID: {8E27C92E-1264-101C-8A2F-040224009C02}
' Help file: C:\Program Files\Microsoft Office\OFFICE11\mscal.hlp
' ########################################################################################

#INCLUDE THIS ONCE
%MSCAL_INC = 1

#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {8E27C92B-1264-101C-8A2F-040224009C02}
$PROGID_MSCAL_Calendar7 = "MSCAL.Calendar.7"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {8E27C92B-1264-101C-8A2F-040224009C02}
$PROGID_MSCAL_Calendar = "MSCAL.Calendar"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSCAL_Calendar = GUID$("{8E27C92B-1264-101C-8A2F-040224009C02}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_MSCAL_DCalendarEvents = GUID$("{8E27C92D-1264-101C-8A2F-040224009C02}")
$IID_MSCAL_ICalendar = GUID$("{8E27C92C-1264-101C-8A2F-040224009C02}")

' ########################################################################################
' Interface name = ICalendar
' IID = {8E27C92C-1264-101C-8A2F-040224009C02}
' Calendar Control
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSCAL_ICalendar_INTERFACE_DEFINED)
    %MSCAL_ICalendar_INTERFACE_DEFINED = 1

INTERFACE MSCAL_ICalendar $IID_MSCAL_ICalendar

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BackColor <-501> ( _                    ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclrBackColor
   ' =====================================================================================
   PROPERTY SET BackColor <-501> ( _                    ' VTable offset = 32
     BYVAL pclrBackColor AS DWORD _                     ' __in OLE_COLOR pclrBackColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Day <17> ( _                            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* pnDay
   ' =====================================================================================
   PROPERTY SET Day <17> ( _                            ' VTable offset = 40
     BYVAL pnDay AS INTEGER _                           ' __in short pnDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayFont <1> ( _                         ' VTable offset = 44
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppfontDayFont
   ' =====================================================================================
   PROPERTY SET DayFont <1> ( _                         ' VTable offset = 48
     BYVAL ppfontDayFont AS IFontDisp _                 ' __in IFontDisp* ppfontDayFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayFontColor <2> ( _                    ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclrDayFontColor
   ' =====================================================================================
   PROPERTY SET DayFontColor <2> ( _                    ' VTable offset = 56
     BYVAL pclrDayFontColor AS DWORD _                  ' __in OLE_COLOR pclrDayFontColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DayLength <18> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* pnDayLength
   ' =====================================================================================
   PROPERTY SET DayLength <18> ( _                      ' VTable offset = 64
     BYVAL pnDayLength AS INTEGER _                     ' __in short pnDayLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstDay <19> ( _                       ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short* pnFirstDay
   ' =====================================================================================
   PROPERTY SET FirstDay <19> ( _                       ' VTable offset = 72
     BYVAL pnFirstDay AS INTEGER _                      ' __in short pnFirstDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GridCellEffect <20> ( _                 ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* plGridCellEffect
   ' =====================================================================================
   PROPERTY SET GridCellEffect <20> ( _                 ' VTable offset = 80
     BYVAL plGridCellEffect AS LONG _                   ' __in long plGridCellEffect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GridFont <3> ( _                        ' VTable offset = 84
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppfontGridFont
   ' =====================================================================================
   PROPERTY SET GridFont <3> ( _                        ' VTable offset = 88
     BYVAL ppfontGridFont AS IFontDisp _                ' __in IFontDisp* ppfontGridFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GridFontColor <4> ( _                   ' VTable offset = 92
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclrGridFontColor
   ' =====================================================================================
   PROPERTY SET GridFontColor <4> ( _                   ' VTable offset = 96
     BYVAL pclrGridFontColor AS DWORD _                 ' __in OLE_COLOR pclrGridFontColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GridLinesColor <13> ( _                 ' VTable offset = 100
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclrGridLinesColor
   ' =====================================================================================
   PROPERTY SET GridLinesColor <13> ( _                 ' VTable offset = 104
     BYVAL pclrGridLinesColor AS DWORD _                ' __in OLE_COLOR pclrGridLinesColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Month <16> ( _                          ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out short* pnMonth
   ' =====================================================================================
   PROPERTY SET Month <16> ( _                          ' VTable offset = 112
     BYVAL pnMonth AS INTEGER _                         ' __in short pnMonth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthLength <21> ( _                    ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out short* pnMonthLength
   ' =====================================================================================
   PROPERTY SET MonthLength <21> ( _                    ' VTable offset = 120
     BYVAL pnMonthLength AS INTEGER _                   ' __in short pnMonthLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDateSelectors <5> ( _               ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShowDateSelectors
   ' =====================================================================================
   PROPERTY SET ShowDateSelectors <5> ( _               ' VTable offset = 128
     BYVAL pfShowDateSelectors AS INTEGER _             ' __in VARIANT_BOOL pfShowDateSelectors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowDays <6> ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShowDays
   ' =====================================================================================
   PROPERTY SET ShowDays <6> ( _                        ' VTable offset = 136
     BYVAL pfShowDays AS INTEGER _                      ' __in VARIANT_BOOL pfShowDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowHorizontalGrid <7> ( _              ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShowHorizontalGrid
   ' =====================================================================================
   PROPERTY SET ShowHorizontalGrid <7> ( _              ' VTable offset = 144
     BYVAL pfShowHorizontalGrid AS INTEGER _            ' __in VARIANT_BOOL pfShowHorizontalGrid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowTitle <8> ( _                       ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShowTitle
   ' =====================================================================================
   PROPERTY SET ShowTitle <8> ( _                       ' VTable offset = 152
     BYVAL pfShowTitle AS INTEGER _                     ' __in VARIANT_BOOL pfShowTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowVerticalGrid <9> ( _                ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShowVerticalGrid
   ' =====================================================================================
   PROPERTY SET ShowVerticalGrid <9> ( _                ' VTable offset = 160
     BYVAL pfShowVerticalGrid AS INTEGER _              ' __in VARIANT_BOOL pfShowVerticalGrid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleFont <10> ( _                      ' VTable offset = 164
   ) AS IFontDisp                                       ' __retval_out IFontDisp** ppfontTitleFont
   ' =====================================================================================
   PROPERTY SET TitleFont <10> ( _                      ' VTable offset = 168
     BYVAL ppfontTitleFont AS IFontDisp _               ' __in IFontDisp* ppfontTitleFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleFontColor <11> ( _                 ' VTable offset = 172
   ) AS DWORD                                           ' __retval_out OLE_COLOR* pclrTitleFontColor
   ' =====================================================================================
   PROPERTY SET TitleFontColor <11> ( _                 ' VTable offset = 176
     BYVAL pclrTitleFontColor AS DWORD _                ' __in OLE_COLOR pclrTitleFontColor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <12> ( _                          ' VTable offset = 180
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarValue
   ' =====================================================================================
   PROPERTY SET Value <12> ( _                          ' VTable offset = 184
     BYVAL pvarValue AS VARIANT _                       ' __in VARIANT pvarValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value_ <0> ( _                          ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarValue
   ' =====================================================================================
   PROPERTY SET Value_ <0> ( _                          ' VTable offset = 192
     BYVAL pvarValue AS VARIANT _                       ' __in VARIANT pvarValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueIsNull <14> ( _                    ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfValueIsNull
   ' =====================================================================================
   PROPERTY SET ValueIsNull <14> ( _                    ' VTable offset = 200
     BYVAL pfValueIsNull AS INTEGER _                   ' __in VARIANT_BOOL pfValueIsNull
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Year <15> ( _                           ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out short* pnYear
   ' =====================================================================================
   PROPERTY SET Year <15> ( _                           ' VTable offset = 208
     BYVAL pnYear AS INTEGER _                          ' __in short pnYear
   )                                                    ' void
   ' =====================================================================================
   METHOD NextDay <22> ( _                              ' VTable offset = 212
   )                                                    ' void
   ' =====================================================================================
   METHOD NextMonth <23> ( _                            ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD NextWeek <24> ( _                             ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   METHOD NextYear <25> ( _                             ' VTable offset = 224
   )                                                    ' void
   ' =====================================================================================
   METHOD PreviousDay <26> ( _                          ' VTable offset = 228
   )                                                    ' void
   ' =====================================================================================
   METHOD PreviousMonth <27> ( _                        ' VTable offset = 232
   )                                                    ' void
   ' =====================================================================================
   METHOD PreviousWeek <28> ( _                         ' VTable offset = 236
   )                                                    ' void
   ' =====================================================================================
   METHOD PreviousYear <29> ( _                         ' VTable offset = 240
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD Today <30> ( _                                ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 252
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_DayFont <1> ( _                  ' VTable offset = 256
     BYVAL ppfontDayFont AS IFontDisp _                 ' __in IFontDisp* ppfontDayFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_GridFont <3> ( _                 ' VTable offset = 260
     BYVAL ppfontGridFont AS IFontDisp _                ' __in IFontDisp* ppfontGridFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_TitleFont <10> ( _               ' VTable offset = 264
     BYVAL ppfontTitleFont AS IFontDisp _               ' __in IFontDisp* ppfontTitleFont
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSCAL_ICalendar_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDCalendarEvents
' Interface name = DCalendarEvents
' IID = {8E27C92D-1264-101C-8A2F-040224009C02}
' Event interface for Calendar control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDCalendarEvents GUID$("{1435BCBB-8784-4A32-A543-5973445E315F}") AS EVENT

'INTERFACE DCalendarEventsImpl GUID$("{8E27C92D-1264-101C-8A2F-040224009C02}") AS EVENT

'  INHERIT IDispatch

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
'     BYREF KeyCode AS INTEGER _                         ' __in_out short *KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in     short Shift
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
'   , BYVAL iShift AS INTEGER _                          ' __in     short Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD BeforeUpdate <2> ( _
'     BYREF iCancel AS INTEGER _                         ' __in short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AfterUpdate <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NewMonth <3>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NewYear <4>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
