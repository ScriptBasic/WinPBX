' ########################################################################################
' Microsoft Windows
' File: MPConfig.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPCONFIG_INC = 1

#INCLUDE ONCE "ddraw.inc"
#INCLUDE ONCE "uuids.inc"
#INCLUDE ONCE "strmif.inc"

' enum AM_ASPECT_RATIO_MODE
%AM_ARMODE_STRETCHED            = 0  ' // don't do any aspect ratio correction
%AM_ARMODE_LETTER_BOX           = 1  ' // letter box the video, paint background color in the excess region
%AM_ARMODE_CROP                 = 2  ' // crop the video to the right aspect ratio
%AM_ARMODE_STRETCHED_AS_PRIMARY = 3  ' // follow whatever the primary stream does (in terms of the mode as well as pict-aspect-ratio values)


' ########################################################################################
' Interface name = IMixerPinConfig
' IID = {593CDDE1-0759-11D1-9E69-00C04FD7C15B}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IMixerPinConfig $IID_IMixerPinConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRelativePosition ( _                       ' VTable offset = 12
     BYVAL dwLeft AS DWORD _                            ' __in DWORD dwLeft
   , BYVAL dwTop AS DWORD _                             ' __in DWORD dwTop
   , BYVAL dwRight AS DWORD _                           ' __in DWORD dwRight
   , BYVAL dwBottom AS DWORD _                          ' __in DWORD dwBottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativePosition ( _                       ' VTable offset = 16
     BYREF pdwLeft AS DWORD _                           ' __out DWORD *pdwLeft
   , BYREF pdwTop AS DWORD _                            ' __out DWORD *pdwTop
   , BYREF pdwRight AS DWORD _                          ' __out DWORD *pdwRight
   , BYREF pdwBottom AS DWORD _                         ' __out DWORD *pdwBottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZOrder ( _                                 ' VTable offset = 20
     BYVAL dwZOrder AS DWORD _                          ' __in DWORD dwZOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZOrder ( _                                 ' VTable offset = 24
     BYREF pdwZOrder AS DWORD _                         ' __out DWORD *pdwZOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 28
     BYREF pColorKey AS COLORKEY _                      ' __in COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 32
     BYREF pColorKey AS COLORKEY _                      ' __out COLORKEY *pColorKey
   , BYREF pColor AS DWORD _                            ' __out DWORD *pColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlendingParameter ( _                      ' VTable offset = 36
     BYVAL dwBlendingParameter AS DWORD _               ' __in DWORD dwBlendingParameter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlendingParameter ( _                      ' VTable offset = 40
     BYREF pdwBlendingParameter AS DWORD _              ' __out DWORD *pdwBlendingParameter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 44
     BYVAL amAspectRatioMode AS DWORD _                 ' __in AM_ASPECT_RATIO_MODE amAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 48
     BYREF pamAspectRatioMode AS DWORD _                ' __out AM_ASPECT_RATIO_MODE* pamAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamTransparent ( _                      ' VTable offset = 52
     BYVAL bStreamTransparent AS LONG _                 ' __in BOOL bStreamTransparent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamTransparent ( _                      ' VTable offset = 56
     BYREF pbStreamTransparent AS LONG _                ' __out BOOL *pbStreamTransparent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IMixerPinConfig2
' IID = {593CDDE1-0759-11D1-9E69-00C04FD7C15B}
' Inherited interface = IMixerPinConfig
' ########################################################################################

INTERFACE IMixerPinConfig2 $IID_IMixerPinConfig2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMixerPinConfig Methods
   ' =====================================================================================
   METHOD SetRelativePosition ( _                       ' VTable offset = 12
     BYVAL dwLeft AS DWORD _                            ' __in DWORD dwLeft
   , BYVAL dwTop AS DWORD _                             ' __in DWORD dwTop
   , BYVAL dwRight AS DWORD _                           ' __in DWORD dwRight
   , BYVAL dwBottom AS DWORD _                          ' __in DWORD dwBottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativePosition ( _                       ' VTable offset = 16
     BYREF pdwLeft AS DWORD _                           ' __out DWORD *pdwLeft
   , BYREF pdwTop AS DWORD _                            ' __out DWORD *pdwTop
   , BYREF pdwRight AS DWORD _                          ' __out DWORD *pdwRight
   , BYREF pdwBottom AS DWORD _                         ' __out DWORD *pdwBottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZOrder ( _                                 ' VTable offset = 20
     BYVAL dwZOrder AS DWORD _                          ' __in DWORD dwZOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZOrder ( _                                 ' VTable offset = 24
     BYREF pdwZOrder AS DWORD _                         ' __out DWORD *pdwZOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 28
     BYREF pColorKey AS COLORKEY _                      ' __in COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 32
     BYREF pColorKey AS COLORKEY _                      ' __out COLORKEY *pColorKey
   , BYREF pColor AS DWORD _                            ' __out DWORD *pColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlendingParameter ( _                      ' VTable offset = 36
     BYVAL dwBlendingParameter AS DWORD _               ' __in DWORD dwBlendingParameter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlendingParameter ( _                      ' VTable offset = 40
     BYREF pdwBlendingParameter AS DWORD _              ' __out DWORD *pdwBlendingParameter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 44
     BYVAL amAspectRatioMode AS DWORD _                 ' __in AM_ASPECT_RATIO_MODE amAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 48
     BYREF pamAspectRatioMode AS DWORD _                ' __out AM_ASPECT_RATIO_MODE* pamAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamTransparent ( _                      ' VTable offset = 52
     BYVAL bStreamTransparent AS LONG _                 ' __in BOOL bStreamTransparent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamTransparent ( _                      ' VTable offset = 56
     BYREF pbStreamTransparent AS LONG _                ' __out BOOL *pbStreamTransparent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMixerPinConfig2 Methods
   ' =====================================================================================
   METHOD SetOverlaySurfaceColorControls ( _            ' VTable offset = 60
     BYREF pColorControl AS DDCOLORCONTROL _            ' __in LPDDCOLORCONTROL pColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlaySurfaceColorControls ( _            ' VTable offset = 64
     BYREF pColorControl AS DDCOLORCONTROL _            ' __out LPDDCOLORCONTROL pColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
