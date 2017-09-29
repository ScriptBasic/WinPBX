' ########################################################################################
' Microsoft Windows
' File: GdiPlusEffects.inc
' Contents: Gdiplus effect structures and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSEFFECTS_INC = 1

#IF (%GDIPVER >= &H0110)

'//-----------------------------------------------------------------------------
'// GDI+ effect GUIDs
'//-----------------------------------------------------------------------------

$BlurEffectGuid                   = GUID$("{633C80A4-1843-482B-9EF2-BE2834C5FDD4}")
$SharpenEffectGuid                = GUID$("{63CBF3EE-C526-402C-8F71-62C540BF5142}")
$ColorMatrixEffectGuid            = GUID$("{718F2615-7933-40E3-A511-5F68FE14DD74}")
$ColorLUTEffectGuid               = GUID$("{A7CE72A9-0F7F-40D7-B3CC-D0C02D5C3212}")
$BrightnessContrastEffectGuid     = GUID$("{D3A1DBE1-8EC4-4C17-9F4C-EA97AD1C343D}")
$HueSaturationLightnessEffectGuid = GUID$("{8B2DD6C3-EB07-4D87-A5F0-7108E26A9C5F}")
$LevelsEffectGuid                 = GUID$("{99C354EC-2A31-4F3A-8C34-17A803B33A25}")
$TintEffectGuid                   = GUID$("{1077AF00-2848-4441-9489-44AD4C2D7A2C}")
$ColorBalanceEffectGuid           = GUID$("{537E597D-251E-48DA-9664-29CA496B70F8}")
$RedEyeCorrectionEffectGuid       = GUID$("{74D29D05-69A4-4266-9549-3CC52836B632}")
$ColorCurveEffectGuid             = GUID$("{DD6A0022-58E4-4A67-9D9B-D48EB881A53D}")

'//-----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE SharpenParams DWORD
   radius AS SINGLE   ' float
   amount AS SINGLE   ' float
END TYPE

' // Size = 8 bytes
TYPE BlurParams DWORD
   radius     AS SINGLE   ' float
   expandEdge AS LONG     ' BLOAT
END TYPE

' // Size = 8 bytes
TYPE BrightnessContrastParams DWORD
   brightnessLevel AS LONG   ' INT
   contrastLevel   AS LONG   ' INT
END TYPE

' // Size = 8 bytes
TYPE RedEyeCorrectionParams DWORD
   numberOfAreas AS DWORD      ' UINT
   areas         AS RECT PTR   ' RECT*
END TYPE

' // Size = 12 bytes
TYPE HueSaturationLightnessParams DWORD
   hueLevel        AS LONG   ' INT
   saturationLevel AS LONG   ' INT
   lightnessLevel  AS LONG   ' INT
END TYPE

' // Size = 8 bytes
TYPE TintParams DWORD
   hue    AS LONG   ' INT
   amount AS LONG   ' INT
END TYPE

' // Size = 12 bytes
TYPE LevelsParams DWORD
   highlight AS LONG   ' INT
   midtone   AS LONG   ' INT
   shadow    AS LONG   ' INT
END TYPE

' // Size = 12 bytes
TYPE ColorBalanceParams DWORD
   cyanRed      AS LONG   ' INT
   magentaGreen AS LONG   ' INT
   yellowBlue   AS LONG   ' INT
END TYPE

' // Size = 1024 bytes
TYPE ColorLUTParams DWORD
   ' // look up tables for each color channel.
   lutB(255) AS BYTE   ' ColorChannelLUT[256]
   lutG(255) AS BYTE   ' ColorChannelLUT[256]
   lutR(255) AS BYTE   ' ColorChannelLUT[256]
   lutA(255) AS BYTE   ' ColorChannelLUT[256]
END TYPE

' enum CurveAdjustments
%AdjustExposure        = 0
%AdjustDensity         = 1
%AdjustContrast        = 2
%AdjustHighlight       = 3
%AdjustShadow          = 4
%AdjustMidtone         = 5
%AdjustWhiteSaturation = 6
%AdjustBlackSaturation = 7

' enum CurveChannel
%CurveChannelAll   = 0
%CurveChannelRed   = 1
%CurveChannelGreen = 2
%CurveChannelBlue  = 3

' // Size = 12 bytes
TYPE ColorCurveParams DWORD
   adjustment  AS LONG   ' CurveAdjustments
   channel     AS LONG   ' CurveChannel
   adjustValue AS LONG   ' INT
END TYPE

'class CGpEffect;

DECLARE FUNCTION GdipCreateEffect IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateEffect" ( _
   BYVAL guid AS GUID _                                 ' __in  const GUID guid
 , BYREF effect AS DWORD _                              ' __out CGpEffect **effect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteEffect IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteEffect" ( _
   BYVAL effect AS DWORD _                              ' __in CGpEffect *effect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetEffectParameterSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetEffectParameterSize" ( _
   BYVAL effect AS DWORD _                              ' __in  CGpEffect *effect
 , BYREF size AS DWORD _                                ' __out UINT *size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetEffectParameters IMPORT "GDIPLUS.DLL" ALIAS "GdipSetEffectParameters" ( _
   BYVAL effect AS DWORD _                              ' __in CGpEffect *effect
 , BYREF params AS ANY _                                ' __in const VOID *params
 , BYVAL size AS DWORD _                                ' __in const UINT size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetEffectParameters IMPORT "GDIPLUS.DLL" ALIAS "GdipGetEffectParameters" ( _
   BYVAL effect AS DWORD _                              ' __in  CGpEffect *effect
 , BYREF size AS DWORD _                                ' __out UINT *size
 , BYREF params AS ANY _                                ' __out VOID *params
 ) AS LONG                                              ' GpStatus

#ENDIF   ' //(%GDIPVER >= &H0110)
