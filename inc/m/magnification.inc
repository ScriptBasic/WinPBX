' ########################################################################################
' Microsoft Windows
' File: Magnification.inc
' Contents: Magnification Control API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAGNIFICATION_INC = 1

#INCLUDE ONCE "wincodec.inc"

'#ifdef _WIN32

'// Magnifier Class Name
$WC_MAGNIFIERA          = "Magnifier"
$$WC_MAGNIFIERW         = "Magnifier"$$
#IF %DEF(%UNICODE)
   MACRO WC_MAGNIFIER = $WC_MAGNIFIERA
#ELSE
   MACRO WC_MAGNIFIER = $$WC_MAGNIFIERW
#ENDIF

'// Magnifier Window Styles
%MS_SHOWMAGNIFIEDCURSOR = &H0001&
%MS_CLIPAROUNDCURSOR    = &H0002&
%MS_INVERTCOLORS        = &H0004&

'// Filter Modes
%MW_FILTERMODE_EXCLUDE  = 0
%MW_FILTERMODE_INCLUDE  = 1

' // Size = 36 bytes
TYPE MAGTRANSFORM DWORD
   v (2, 2) AS SINGLE   ' float v[3][3]
END TYPE

' // Size = 36 bytes
TYPE MAGIMAGEHEADER DWORD
   width  AS DWORD   ' UINT
   height AS DWORD   ' UINT
   format AS GUID    ' WICPixelFormatGUID
   stride AS DWORD   ' UINT
   offset AS DWORD   ' UINT
   cbSize AS DWORD   ' SIZE_T
END TYPE

' // Size = 100 bytes
TYPE MAGCOLOREFFECT DWORD
   transform (4, 4) AS SINGLE   ' float transform[5][5]
END TYPE

'typedef BOOL (CALLBACK* MagImageScalingCallback)(HWND hwnd, void * srcdata, MAGIMAGEHEADER srcheader, void * destdata, MAGIMAGEHEADER destheader, RECT unclipped, RECT clipped, HRGN dirty );

'FUNCTION MagImageScalingCallback ( _
'   BYVAL hwnd AS DWORD _                      ' HWND hwnd
' , BYVAL srcdata AS DWORD _                   ' void * srcdata
' , BYREF srcheader AS MAGIMAGEHEADER _        ' MAGIMAGEHEADER srcheader
' , BYVAL destdata AS DWORD _                  ' void * destdata
' , BYREF destheader AS MAGIMAGEHEADER _       ' MAGIMAGEHEADER destheader
' , BYREF unclipped AS RECT _                  ' RECT unclipped
' , BYREF clipped AS RECT _                    ' RECT clipped
' , BYVAL dirty AS DWORD _                     ' HRGN dirty
' ) AS LONG                                              ' BOOL

'// Public Functions

DECLARE FUNCTION MagInitialize IMPORT "magnification.dll" ALIAS "MagInitialize" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagUninitialize IMPORT "magnification.dll" ALIAS "MagUninitialize" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagSetWindowSource IMPORT "magnification.dll" ALIAS "MagSetWindowSource" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL rect AS RECT _                                 ' __in RECT rect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagGetWindowSource IMPORT "magnification.dll" ALIAS "MagGetWindowSource" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pRect AS RECT _                                ' __out RECT *pRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagSetWindowTransform IMPORT "magnification.dll" ALIAS "MagSetWindowTransform" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pTransform AS MAGTRANSFORM _                   ' __in PMAGTRANSFORM pTransform
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagGetWindowTransform IMPORT "magnification.dll" ALIAS "MagGetWindowTransform" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pTransform AS MAGTRANSFORM _                   ' __out PMAGTRANSFORM pTransform
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagSetWindowFilterList IMPORT "magnification.dll" ALIAS "MagSetWindowFilterList" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwFilterMode AS DWORD _                        ' __in DWORD dwFilterMode
 , BYVAL count AS LONG _                                ' __in int count
 , BYREF pHWND AS DWORD _                               ' __in HWND *pHWND
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagGetWindowFilterList IMPORT "magnification.dll" ALIAS "MagGetWindowFilterList" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pdwFilterMode AS DWORD _                       ' __in  DWORD *pdwFilterMode
 , BYVAL count AS LONG _                                ' __in  int count
 , BYREF pHWND AS DWORD _                               ' __out HWND *pHWND
 ) AS LONG                                              ' int

DECLARE FUNCTION MagSetImageScalingCallback IMPORT "magnification.dll" ALIAS "MagSetImageScalingCallback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL callback AS DWORD _                            ' __in MagImageScalingCallback callback
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagGetImageScalingCallback IMPORT "magnification.dll" ALIAS "MagGetImageScalingCallback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' MagImageScalingCallback

DECLARE FUNCTION MagSetColorEffect IMPORT "magnification.dll" ALIAS "MagSetColorEffect" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pEffect AS MAGCOLOREFFECT _                    ' __in PMAGCOLOREFFECT pEffect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MagGetColorEffect IMPORT "magnification.dll" ALIAS "MagGetColorEffect" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pEffect AS MAGCOLOREFFECT _                    ' __out PMAGCOLOREFFECT pEffect
 ) AS LONG                                              ' BOOL

