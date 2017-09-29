' ########################################################################################
' Microsoft Windows
' File: DXGIType.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXGITYPE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#include ONCE "ocidl.inc"
#INCLUDE ONCE "dxgiformat.inc"

%FACDXGI    = &H87a

'#define MAKE_DXGI_HRESULT( code )    MAKE_HRESULT( 1, _FACDXGI, code )
'#define MAKE_DXGI_STATUS( code )    MAKE_HRESULT( 0, _FACDXGI, code )

MACRO MAKE_DXGI_HRESULT(code) = MAKE_HRESULT(1,%FACDXGI,code)
MACRO MAKE_DXGI_STATUS(code) = MAKE_HRESULT(0,%FACDXGI,code)

%DXGI_STATUS_OCCLUDED                     = &H087A0001&   ' MAKE_DXGI_STATUS(1)
%DXGI_STATUS_CLIPPED                      = &H087A0002&   ' MAKE_DXGI_STATUS(2)
%DXGI_STATUS_NO_REDIRECTION               = &H087A0004&   ' MAKE_DXGI_STATUS(4)
%DXGI_STATUS_NO_DESKTOP_ACCESS            = &H087A0005&   ' MAKE_DXGI_STATUS(5)
%DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE = &H087A0006&   ' MAKE_DXGI_STATUS(6)
%DXGI_STATUS_MODE_CHANGED                 = &H087A0007&   ' MAKE_DXGI_STATUS(7)
%DXGI_STATUS_MODE_CHANGE_IN_PROGRESS      = &H087A0008&   ' MAKE_DXGI_STATUS(8)

%DXGI_ERROR_INVALID_CALL                  = &H887A0001&   ' MAKE_DXGI_HRESULT(1)
%DXGI_ERROR_NOT_FOUND                     = &H887A0002&   ' MAKE_DXGI_HRESULT(2)
%DXGI_ERROR_MORE_DATA                     = &H887A0003&   ' MAKE_DXGI_HRESULT(3)
%DXGI_ERROR_UNSUPPORTED                   = &H887A0004&   ' MAKE_DXGI_HRESULT(4)
%DXGI_ERROR_DEVICE_REMOVED                = &H887A0005&   ' MAKE_DXGI_HRESULT(5)
%DXGI_ERROR_DEVICE_HUNG                   = &H887A0006&   ' MAKE_DXGI_HRESULT(6)
%DXGI_ERROR_DEVICE_RESET                  = &H887A0007&   ' MAKE_DXGI_HRESULT(7)
%DXGI_ERROR_WAS_STILL_DRAWING             = &H887A000A&   ' MAKE_DXGI_HRESULT(10)
%DXGI_ERROR_FRAME_STATISTICS_DISJOINT     = &H887A000B&   ' MAKE_DXGI_HRESULT(11)
%DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE  = &H887A000C&   ' MAKE_DXGI_HRESULT(12)
%DXGI_ERROR_DRIVER_INTERNAL_ERROR         = &H887A0020&   ' MAKE_DXGI_HRESULT(32)
%DXGI_ERROR_NONEXCLUSIVE                  = &H887A0021&   ' MAKE_DXGI_HRESULT(33)
%DXGI_ERROR_NOT_CURRENTLY_AVAILABLE       = &H887A0022&   ' MAKE_DXGI_HRESULT(34)
%DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED    = &H887A0023&   ' MAKE_DXGI_HRESULT(35)
%DXGI_ERROR_REMOTE_OUTOFMEMORY            = &H887A0024&   ' MAKE_DXGI_HRESULT(36)

%DXGI_CPU_ACCESS_NONE                     = 0
%DXGI_CPU_ACCESS_DYNAMIC                  = 1
%DXGI_CPU_ACCESS_READ_WRITE               = 2
%DXGI_CPU_ACCESS_SCRATCH                  = 3
%DXGI_CPU_ACCESS_FIELD                    = 15

%DXGI_USAGE_SHADER_INPUT                 = &H00000010???   ' ( 1L << (0 + 4) )
%DXGI_USAGE_RENDER_TARGET_OUTPUT         = &H00000020???   ' ( 1L << (1 + 4) )
%DXGI_USAGE_BACK_BUFFER                  = &H00000040???   ' ( 1L << (2 + 4) )
%DXGI_USAGE_SHARED                       = &H00000080???   ' ( 1L << (3 + 4) )
%DXGI_USAGE_READ_ONLY                    = &H00000100???   ' ( 1L << (4 + 4) )
%DXGI_USAGE_DISCARD_ON_PRESENT           = &H00000200???   ' ( 1L << (5 + 4) )
%DXGI_USAGE_UNORDERED_ACCESS             = &H00000400???   ' ( 1L << (6 + 4) )


' // Size = 12 bytes
TYPE DXGI_RGB DWORD
   Red   AS SINGLE   ' float
   Green AS SINGLE   ' float
   Blue  AS SINGLE   ' float
END TYPE

' // Size = 12324 bytes
TYPE DXGI_GAMMA_CONTROL DWORD
   Scale            AS DXGI_RGB
   Offset           AS DXGI_RGB
   GammaCurve(1024) AS DXGI_RGB
END TYPE

' // Size = 4116 bytes
TYPE DXGI_GAMMA_CONTROL_CAPABILITIES DWORD
   ScaleAndOffsetSupported     AS LONG     ' BOOL
   MaxConvertedValue           AS SINGLE   ' float
   MinConvertedValue           AS SINGLE   ' float
   NumGammaControlPoints       AS DWORD    ' UINT
   ControlPointPositions(1024) AS SINGLE   ' float
END TYPE

' // Size = 8 bytes
TYPE DXGI_RATIONAL DWORD
   Numerator   AS DWORD   ' UINT
   Denominator AS DWORD   ' UINT
END TYPE

' enum DXGI_MODE_SCANLINE_ORDER
%DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED       = 0
%DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE       = 1
%DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2
%DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3

' enum DXGI_MODE_SCALING
%DXGI_MODE_SCALING_UNSPECIFIED = 0
%DXGI_MODE_SCALING_CENTERED    = 1
%DXGI_MODE_SCALING_STRETCHED   = 2

' enum DXGI_MODE_ROTATION
%DXGI_MODE_ROTATION_UNSPECIFIED = 0
%DXGI_MODE_ROTATION_IDENTITY    = 1
%DXGI_MODE_ROTATION_ROTATE90    = 2
%DXGI_MODE_ROTATION_ROTATE180   = 3
%DXGI_MODE_ROTATION_ROTATE270   = 4

' // Size = 28 bytes
TYPE DXGI_MODE_DESC DWORD
   Width            AS DWORD           ' UINT
   Height           AS DWORD           ' UINT
   RefreshRate      AS DXGI_RATIONAL   ' DXGI_RATIONAL
   Format           AS DWORD           ' DXGI_FORMAT enum
   ScanlineOrdering AS DWORD           ' DXGI_MODE_SCANLINE_ORDER enum
   Scaling          AS DWORD           ' DXGI_MODE_SCALING enum
END TYPE

' // Size = 8 bytes
TYPE DXGI_SAMPLE_DESC DWORD
   Count   AS DWORD   ' UINT
   Quality AS DWORD   ' UINT
END TYPE
