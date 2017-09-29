' ########################################################################################
' Microsoft Windows
' File: tpcshrd.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TPCSHRD_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"

#IF NOT %DEF(%WISPSHRD_INC)
    %WISPSHRD_INC = 1

%WM_TABLET_DEFBASE                    = &H02C0
%WM_TABLET_MAXOFFSET                  = &H20
%WM_TABLET_ADDED                      = %WM_TABLET_DEFBASE + 8
%WM_TABLET_DELETED                    = %WM_TABLET_DEFBASE + 9
%WM_TABLET_FLICK                      = %WM_TABLET_DEFBASE + 11
%WM_TABLET_QUERYSYSTEMGESTURESTATUS   = %WM_TABLET_DEFBASE + 12

'#define MICROSOFT_TABLETPENSERVICE_PROPERTY _T("MicrosoftTabletPenServiceProperty")
$MICROSOFT_TABLETPENSERVICE_PROPERTY = "MicrosoftTabletPenServiceProperty"

%TABLET_DISABLE_PRESSANDHOLD        = &H00000001
%TABLET_DISABLE_PENTAPFEEDBACK      = &H00000008
%TABLET_DISABLE_PENBARRELFEEDBACK   = &H00000010
%TABLET_DISABLE_TOUCHUIFORCEON      = &H00000100
%TABLET_DISABLE_TOUCHUIFORCEOFF     = &H00000200
%TABLET_DISABLE_TOUCHSWITCH         = &H00008000
%TABLET_DISABLE_FLICKS              = &H00010000
%TABLET_ENABLE_FLICKSONCONTEXT      = &H00020000
%TABLET_ENABLE_FLICKLEARNINGMODE    = &H00040000
%TABLET_DISABLE_SMOOTHSCROLLING     = &H00080000
%TABLET_DISABLE_FLICKFALLBACKKEYS   = &H00100000
%TABLET_ENABLE_MULTITOUCHDATA       = &H01000000

%MAX_PACKET_PROPERTY_COUNT          = 32
%MAX_PACKET_BUTTON_COUNT            = 32

%IP_CURSOR_DOWN                     = &H00000001
%IP_INVERTED                        = &H00000002
%IP_MARGIN                          = &H00000004

'typedef DWORD CURSOR_ID;
'typedef USHORT SYSTEM_EVENT;
'typedef DWORD TABLET_CONTEXT_ID;

' enum PROPERTY_UNITS
%PROPERTY_UNITS_DEFAULT     = 0
%PROPERTY_UNITS_INCHES      = 1
%PROPERTY_UNITS_CENTIMETERS = 2
%PROPERTY_UNITS_DEGREES     = 3
%PROPERTY_UNITS_RADIANS     = 4
%PROPERTY_UNITS_SECONDS     = 5
%PROPERTY_UNITS_POUNDS      = 6
%PROPERTY_UNITS_GRAMS       = 7
%PROPERTY_UNITS_SILINEAR    = 8
%PROPERTY_UNITS_SIROTATION  = 9
%PROPERTY_UNITS_ENGLINEAR   = 10
%PROPERTY_UNITS_ENGROTATION = 11
%PROPERTY_UNITS_SLUGS       = 12
%PROPERTY_UNITS_KELVIN      = 13
%PROPERTY_UNITS_FAHRENHEIT  = 14
%PROPERTY_UNITS_AMPERE      = 15
%PROPERTY_UNITS_CANDELA     = 16

#IF NOT %DEF(%XFORM)
%XFORM = 1
' // Size = 24 bytes
TYPE XFORM DWORD
   eM11 AS SINGLE   ' FLOAT
   eM12 AS SINGLE   ' FLOAT
   eM21 AS SINGLE   ' FLOAT
   eM22 AS SINGLE   ' FLOAT
   eDx  AS SINGLE   ' FLOAT
   eDy  AS SINGLE   ' FLOAT
END TYPE
#ENDIF

' // Size = 20 bytes
TYPE SYSTEM_EVENT_DATA DWORD FILL
   bModifier     AS BYTE    ' BYTE
   wKey          AS WORD    ' WCHAR
   xPos          AS LONG    ' LONG
   yPos          AS LONG    ' LONG
   bCursorMode   AS BYTE    ' BYTE
   dwButtonState AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE STROKE_RANGE DWORD
   iStrokeBegin AS DWORD   ' ULONG
   iStrokeEnd   AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE PROPERTY_METRICS DWORD
   nLogicalMin AS LONG     ' LONG
   nLogicalMax AS LONG     ' LONG
   Units       AS LONG     ' PROPERTY_UNITS
   fResolution AS SINGLE   ' FLOAT
END TYPE

' // Size = 32 bytes
TYPE PACKET_PROPERTY DWORD
   guid            AS GUID               ' GUID
   PropertyMetrics AS PROPERTY_METRICS   ' PROPERTY_METRICS
END TYPE

' // Size = 20 bytes
TYPE PACKET_DESCRIPTION DWORD
   cbPacketSize      AS DWORD                 ' ULONG
   cPacketProperties AS DWORD                 ' ULONG
   pPacketProperties AS PACKET_PROPERTY PTR   ' PACKET_PROPERTY *
   cButtons          AS DWORD                 ' ULONG
   pguidButtons      AS GUID PTR              ' GUID *
END TYPE

#ENDIF   ' // __WISPSHRD_H
