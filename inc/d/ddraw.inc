' ########################################################################################
' Microsoft Windows
' File: ddraw.inc
' Contents: DirectDraw include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DDRAW_INC = 1

'/*
' * If you wish an application built against the newest version of DirectDraw
' * to run against an older DirectDraw run time then define DIRECTDRAW_VERSION
' * to be the earlies version of DirectDraw you wish to run against. For,
' * example if you wish an application to run against a DX 3 runtime define
' * DIRECTDRAW_VERSION to be 0x0300.
' */
'#ifndef   DIRECTDRAW_VERSION
'#define   DIRECTDRAW_VERSION 0x0700
'#endif /* DIRECTDRAW_VERSION */

%DIRECTDRAW_VERSION = &H0700

'#if defined( _WIN32 )  && !defined( _NO_COM )
'#define COM_NO_WINDOWS_H
'#include <objbase.h>
#INCLUDE ONCE "objbase.inc"
'#else
'#define IUnknown            void
'#if !defined( NT_BUILD_ENVIRONMENT ) && !defined(WINNT)
%CO_E_NOTINITIALIZED = &H800401F0&
'#endif
'#endif

'#define _FACDD  0x876
'#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )

%FACDD = &H876

FUNCTION MAKE_DDHRESULT (BYVAL code AS DWORD) AS DWORD
   LOCAL sev AS DWORD
   LOCAL fac AS DWORD
   sev = 1
   fac = &H878
   SHIFT LEFT sev, 31
   SHIFT LEFT fac, 16
   FUNCTION = (sev OR fac OR code)
END FUNCTION

%MAKE_DDHRESULT                       = &H88760000&   ' (-2005532672)

'#ifndef MAKEFOURCC
'    #define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
'                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
'                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
'#endif //defined(MAKEFOURCC)

#IF NOT %DEF(%MAKEFOURCC_DEFINED)
%MAKEFOURCC_DEFINED = 1
FUNCTION MAKEFOURCC (BYVAL st0 AS STRING, BYVAL st1 AS STRING, BYVAL st2 AS STRING, BYVAL st3 AS STRING) AS DWORD
   LOCAL ch0 AS DWORD, ch1 AS DWORD, ch2 AS DWORD, ch3 AS DWORD
   ch0 = ASC(st0)
   ch1 = ASC(st1)
   ch2 = ASC(st2)
   ch3 = ASC(st3)
   SHIFT LEFT ch1, 8
   SHIFT LEFT ch2, 16
   SHIFT LEFT ch3, 24
   FUNCTION = ch0 OR ch1 OR ch2 OR ch3
END FUNCTION
#ENDIF

'/*
' * FOURCC codes for DX compressed-texture pixel formats
' */
'#define FOURCC_DXT1  (MAKEFOURCC('D','X','T','1'))
'#define FOURCC_DXT2  (MAKEFOURCC('D','X','T','2'))
'#define FOURCC_DXT3  (MAKEFOURCC('D','X','T','3'))
'#define FOURCC_DXT4  (MAKEFOURCC('D','X','T','4'))
'#define FOURCC_DXT5  (MAKEFOURCC('D','X','T','5'))

%FOURCC_DXT1 = &H827611204
%FOURCC_DXT2 = &H844388420
%FOURCC_DXT3 = &H861165636
%FOURCC_DXT4 = &H877942852
%FOURCC_DXT5 = &H894720068

'/*
' * GUIDS used by DirectDraw objects
' */

$CLSID_DirectDraw            = GUID$("{D7B70EE0-4340-11CF-B063-0020AFC2CD35}")
$CLSID_DirectDraw7           = GUID$("{3C305196-50DB-11D3-9CFE-00C04FD930C5}")
$CLSID_DirectDrawClipper     = GUID$("{593817A0-7DB3-11CF-A2DE-00AA00b93356}")
$IID_IDirectDraw             = GUID$("{6C14DB80-A733-11CE-A521-0020AF0BE560}")
$IID_IDirectDraw2            = GUID$("{B3A6F3E0-2B43-11CF-A2DE-00AA00B93356}")
$IID_IDirectDraw4            = GUID$("{9C59509A-39BD-11D1-8C4A-00C04FD930C5}")
$IID_IDirectDraw7            = GUID$("{15E65EC0-3B9C-11D2-B92F-00609797EA5B}")
$IID_IDirectDrawSurface      = GUID$("{6C14DB81-A733-11CE-A521-0020AF0BE560}")
$IID_IDirectDrawSurface2     = GUID$("{57805885-6EEC-11CF-9441-A82303C10E27}")
$IID_IDirectDrawSurface3     = GUID$("{DA044E00-69B2-11D0-A1D5-00AA00B8DFBB}")
$IID_IDirectDrawSurface4     = GUID$("{0B2B8630-AD35-11D0-8EA6-00609797EA5B}")
$IID_IDirectDrawSurface7     = GUID$("{06675A80-3B9B-11D2-B92F-00609797EA5B}")
$IID_IDirectDrawPalette      = GUID$("{6C14DB84-A733-11CE-A521-0020AF0BE560}")
$IID_IDirectDrawClipper      = GUID$("{6C14DB85-A733-11CE-A521-0020AF0BE560}")
$IID_IDirectDrawColorControl = GUID$("{4B9F0EE0-0D7E-11D0-9B06-00A0C903A3B8}")
$IID_IDirectDrawGammaControl = GUID$("{69C11C3E-B46B-11D1-AD7A-00C04FC29B4E}")


'/*
' * API's
' */

' ========================================================================================
' This function is superseded by the DirectDrawEnumerateEx function.
' The DirectDrawEnumerate function enumerates the primary DirectDraw display device and a
' non-display device, such as a 3-D accelerator that has no 2-D capabilities, if one is
' installed. The NULL entry always identifies the primary display device shared with GDI.
' ========================================================================================

DECLARE FUNCTION DirectDrawEnumerate IMPORT "DDRAW.DLL" ALIAS "DirectDrawEnumerateA" ( _
   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKA lpCallback
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DirectDrawEnumerateW IMPORT "DDRAW.DLL" ALIAS "DirectDrawEnumerateW" ( _
   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKW lpCallback
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' This function enumerates all DirectDraw devices installed on the system. The NULL entry
' always identifies the primary display device shared with GDI.
' ========================================================================================

DECLARE FUNCTION DirectDrawEnumerateEx IMPORT "DDRAW.DLL" ALIAS "DirectDrawEnumerateExA" ( _
   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKEXA lpCallback
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DirectDrawEnumerateExW IMPORT "DDRAW.DLL" ALIAS "DirectDrawEnumerateExW" ( _
   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKEXW lpCallback
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' The DirectDrawCreate function creates an instance of a DirectDraw object. A DirectDraw
' object created with this function does not support the newest set of Direct3D interfaces.
' To create a DirectDraw object capable of exposing the new features of Direct3D, use the
' DirectDrawCreateEx function.
' ========================================================================================

DECLARE FUNCTION DirectDrawCreate IMPORT "DDRAW.DLL" ALIAS "DirectDrawCreate" ( _
   BYREF lpGUID AS GUID _                               ' __in  GUID FAR *lpGUID
 , BYREF lplpDD AS IDirectDraw _                        ' __out LPDIRECTDRAW FAR *lplpDD
 , BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown FAR *pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' The DirectDrawCreateEx function creates an instance of a DirectDraw object that supports
' the newest set of Direct3D interfaces. To use the new features of Direct3D in DirectX
' 7.0, create a DirectDraw object with this function.
' Note: This parameter must be set to IID_IDirectDraw7. This function fails and returns
' DDERR_INVALIDPARAMS if any other interface is specified.
' ========================================================================================

DECLARE FUNCTION DirectDrawCreateEx IMPORT "DDRAW.DLL" ALIAS "DirectDrawCreateEx" ( _
   BYREF lpGUID AS GUID _                               ' __in  GUID FAR *lpGUID
 , BYREF lplpDD AS IDirectDraw _                        ' __out LPDIRECTDRAW FAR *lplpDD
 , BYREF iid AS GUID _                                  ' __in  REFIID  iid
 , BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown FAR *pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' The DirectDrawCreateClipper function creates an instance of a DirectDrawClipper object
' not associated with a DirectDraw object.
' ========================================================================================

DECLARE FUNCTION DirectDrawCreateClipper IMPORT "DDRAW.DLL" ALIAS "DirectDrawCreateClipper" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lplpDDClipper AS IDirectDrawClipper _          ' __out LPDIRECTDRAWCLIPPER FAR *lplpDDClipper
 , BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown FAR *pUnkOuter
 ) AS LONG                                              ' HRESULT


' Callback function prototypes

'FUNCTION DDENUMCALLBACKA ( _
'   BYREF lpGUID AS GUID _                               ' __in GUID FAR *lpGUID
' , BYREF lpDriverDescription AS ASCIIZ _                ' __in LPSTR lpDriverDescription
' , BYREF lpDriverName AS ASCIIZ _                       ' __in LPSTR lpDriverName
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMCALLBACKW ( _
'   BYREF lpGUID AS GUID _                               ' __in GUID FAR *lpGUID
' , BYREF lpDriverDescription AS WSTRINGZ _              ' __in LPWSTR lpDriverDescription
' , BYREF lpDriverName AS WSTRINGZ _                     ' __in LPWSTR lpDriverName
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMCALLBACKEXA ( _
'   BYREF lpGUID AS GUID _                               ' __in GUID FAR *lpGUID
' , BYREF lpDriverDescription AS ASCIIZ _                ' __in LPSTR lpDriverDescription
' , BYREF lpDriverName AS ASCIIZ _                       ' __in LPSTR lpDriverName
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' , BYVAL hm AS DWORD _                                  ' __in HMONITOR hm
' ) AS LONG

'FUNCTION DDENUMCALLBACKEXW ( _
'   BYREF lpGUID AS GUID _                               ' __in GUID FAR *lpGUID
' , BYREF lpDriverDescription AS WSTRINGZ _              ' __in LPWSTR lpDriverDescription
' , BYREF lpDriverName AS WSTRINGZ _                     ' __in LPWSTR lpDriverName
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' , BYVAL hm AS DWORD _                                  ' __in HMONITOR hm
' ) AS LONG

'FUNCTION DIRECTDRAWENUMERATEEXA ( _
'   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKEXA lpCallback
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG

'FUNCTION DIRECTDRAWENUMERATEEXW ( _
'   BYVAL lpCallback AS DWORD _                          ' __in LPDDENUMCALLBACKEXW lpCallback
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG


'/*
' * Flags for DirectDrawEnumerateEx
' * DirectDrawEnumerateEx supercedes DirectDrawEnumerate. You must use GetProcAddress to
' * obtain a function pointer (of type LPDIRECTDRAWENUMERATEEX) to DirectDrawEnumerateEx.
' * By default, only the primary display device is enumerated.
' * DirectDrawEnumerate is equivalent to DirectDrawEnumerate(,,DDENUM_NONDISPLAYDEVICES)
' */

'/*
' * This flag causes enumeration of any GDI display devices which are part of
' * the Windows Desktop
' */
%DDENUM_ATTACHEDSECONDARYDEVICES     = &H00000001???

'/*
' * This flag causes enumeration of any GDI display devices which are not
' * part of the Windows Desktop
' */
%DDENUM_DETACHEDSECONDARYDEVICES     = &H00000002???

'/*
' * This flag causes enumeration of non-display devices
' */
%DDENUM_NONDISPLAYDEVICES            = &H00000004???


$REGSTR_KEY_DDHW_DESCRIPTION     = "Description"
$REGSTR_KEY_DDHW_DRIVERNAME      = "DriverName"
$REGSTR_PATH_DDHW                = "Hardware\DirectDrawDrivers"

%DDCREATE_HARDWAREONLY           = &H00000001???
%DDCREATE_EMULATIONONLY          = &H00000002???


' Callback function prototypes

'FUNCTION DDENUMMODESCALLBACK ( _
'   BYVAL lpDDSurfaceDesc AS DWORD _                     ' __in LPDDSURFACEDESC lpDDSurfaceDesc
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMMODESCALLBACK2 ( _
'   BYVAL lpDDSurfaceDesc AS DWORD _                     ' __in LPDDSURFACEDESC2 lpDDSurfaceDesc
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMSURFACESCALLBACK ( _
'   BYVAL lpDDSurface AS DWORD _                         ' __in LPDIRECTDRAWSURFACE lpDDSurface
' , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _             ' __in LPDDSURFACEDESC lpDDSurfaceDesc
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMSURFACESCALLBACK2 ( _
'   BYVAL lpDDSurface AS DWORD _                         ' __in LPDIRECTDRAWSURFACE4 lpDDSurface
' , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _             ' __in LPDDSURFACEDESC2 lpDDSurfaceDesc
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG

'FUNCTION DDENUMSURFACESCALLBACK7 ( _
'   BYVAL lpDDSurface AS DWORD _                         ' __in LPDIRECTDRAWSURFACE7 lpDDSurface
' , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _             ' __in LPDDSURFACEDESC2 lpDDSurfaceDesc
' , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
' ) AS LONG


'/*
' * Generic pixel format with 8-bit RGB and alpha components
' */

' // Size = 4 bytes
TYPE DDARGB BYTE
   blue  AS BYTE                       ' BYTE blue
   green AS BYTE                       ' BYTE green
   red   AS BYTE                       ' BYTE red
   alpha AS BYTE                       ' BYTE alpha
END TYPE

'/*
' * This version of the structure remains for backwards source compatibility.
' * The DDARGB structure is the one that should be used for all DirectDraw APIs.
' */

' // Size = 4 bytes
TYPE DDRGBA BYTE
   red   AS BYTE                       ' BYTE red
   green AS BYTE                       ' BYTE green
   blue  AS BYTE                       ' BYTE blue
   alpha AS BYTE                       ' BYTE alpha
END TYPE

'/*
' * DDCOLORKEY
' */

' // Size = 8 bytes
TYPE DDCOLORKEY DWORD
   dwColorSpaceLowValue  AS DWORD     ' // low boundary of color space that is to
                                      ' // be treated as Color Key, inclusive
   dwColorSpaceHighValue AS DWORD     ' // high boundary of color space that is
                                      ' // to be treated as Color Key, inclusive
END TYPE

'/*
' * DDBLTFX
' * Used to pass override information to the DIRECTDRAWSURFACE callback Blt.
' */

' // Size = 4 bytes
UNION DDBLTFX_UNION_1 DWORD
   dwZDestConst     AS DWORD           ' // Constant to use as Z buffer for dest
   lpDDSZBufferDest AS DWORD           ' // Surface to use as Z buffer for dest
END UNION

' // Size = 4 bytes
UNION DDBLTFX_UNION_2 DWORD
   dwZSrcConst     AS DWORD            ' // Constant to use as Z buffer for src
   lpDDSZBufferSrc AS DWORD            ' // Surface to use as Z buffer for src
END UNION

' // Size = 4 bytes
UNION DDBLTFX_UNION_3 DWORD
   dwAlphaDestConst AS DWORD           ' // Constant to use as Alpha Channel
   lpDDSAlphaDest   AS DWORD           ' // Surface to use as Alpha Channel
END UNION

' // Size = 4 bytes
UNION DDBLTFX_UNION_4 DWORD
   dwAlphaSrcConst AS DWORD            ' // Constant to use as Alpha Channel
   lpDDSAlphaSrc   AS DWORD            ' // Surface to use as Alpha Channel
END UNION

' // Size = 4 bytes
UNION DDBLTFX_UNION_5 DWORD
   dwFillColor  AS DWORD               ' // color in RGB or Palettized
   dwFillDepth  AS DWORD               ' // depth value for z-buffer
   dwFillPixel  AS DWORD               ' // pixel value for RGBA or RGBZ
   lpDDSPattern AS DWORD               ' // Surface to use as pattern
END UNION

' // Size = 100 bytes
TYPE DDBLTFX DWORD
   dwSize                   AS DWORD        ' // size of structure
   dwDDFX                   AS DWORD        ' // FX operations
   dwROP                    AS DWORD        ' // Win32 raster operations
   dwDDROP                  AS DWORD        ' // Raster operations new for DirectDraw
   dwRotationAngle          AS DWORD        ' // Rotation angle for blt
   dwZBufferOpCode          AS DWORD        ' // ZBuffer compares
   dwZBufferLow             AS DWORD        ' // Low limit of Z buffer
   dwZBufferHigh            AS DWORD        ' // High limit of Z buffer
   dwZBufferBaseDest        AS DWORD        ' // Destination base value
   dwZDestConstBitDepth     AS DWORD        ' // Bit depth used to specify Z constant for destination
   DDBLTFX_UNION_1
   dwZSrcConstBitDepth      AS DWORD        ' // Bit depth used to specify Z constant for source
   DDBLTFX_UNION_2
   dwAlphaEdgeBlendBitDepth AS DWORD        ' // Bit depth used to specify constant for alpha edge blend
   dwAlphaEdgeBlend         AS DWORD        ' // Alpha for edge blending
   dwReserved               AS DWORD
   dwAlphaDestConstBitDepth AS DWORD        ' // Bit depth used to specify alpha constant for destination
   DDBLTFX_UNION_3
   dwAlphaSrcConstBitDepth  AS DWORD        ' // Bit depth used to specify alpha constant for source
   DDBLTFX_UNION_4
   DDBLTFX_UNION_5
   ddckDestColorkey         AS DDCOLORKEY   ' // DestColorkey override
   ddckSrcColorkey          AS DDCOLORKEY   ' // SrcColorkey override
END TYPE


'/*
' * DDSCAPS
' */

' // Size = 4 bytes
TYPE DDSCAPS DWORD
   dwCaps AS DWORD                     ' // capabilities of surface wanted
END TYPE


'/*
' * DDOSCAPS
' */

' // Size = 4 bytes
TYPE DDOSCAPS DWORD
   dwCaps AS DWORD                     ' // capabilities of surface wanted
END TYPE


'/*
' * This structure is used internally by DirectDraw.
' */

' // Size = 4 bytes
UNION DDSCAPSEX_UNION DWORD
   dwCaps4       AS DWORD
   dwVolumeDepth AS DWORD
END UNION

' // Size = 12 bytes
TYPE DDSCAPSEX DWORD
   dwCaps2 AS DWORD
   dwCaps3 AS DWORD
   DDSCAPSEX_UNION
END TYPE


'/*
' * DDSCAPS2
' */

' // Size = 4 bytes
UNION DDSCAPS2_UNION DWORD
   dwCaps4       AS DWORD
   dwVolumeDepth AS DWORD
END UNION

' // Size = 16 bytes
TYPE DDSCAPS2 DWORD
   dwCaps  AS DWORD        ' // capabilities of surface wanted
   dwCaps2 AS DWORD
   dwCaps3 AS DWORD
   DDSCAPS2_UNION
END TYPE

'/*
' * DDCAPS
' */
%DD_ROP_SPACE           = (256/32)     ' // space required to store ROP array

'/*
' * NOTE: Our choosen structure number scheme is to append a single digit to
' * the end of the structure giving the version that structure is associated
' * with.
' */

'/*
' * This structure represents the DDCAPS structure released in DirectDraw 1.0.  It is used internally
' * by DirectDraw to interpret caps passed into ddraw by drivers written prior to the release of DirectDraw 2.0.
' * New applications should use the DDCAPS structure defined below.
' */

' // Size = 172 bytes
TYPE DDCAPS_DX1 DWORD
   dwSize                         AS DWORD       ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD       ' // driver specific capabilities
   dwCaps2                        AS DWORD       ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD       ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD       ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD       ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD       ' // palette capabilities
   dwSVCaps                       AS DWORD       ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD       ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD       ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD       ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD       ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD       ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD       ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD       ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD       ' // total amount of video memory
   dwVidMemFree                   AS DWORD       ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD       ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD       ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD       ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD       ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD       ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD       ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD       ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD       ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD       ' // ROPS supported
   tddsCaps                       AS DDSCAPS     ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD       ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD       ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD       ' // OBSOLETE! This field remains for compatability reasons only
   dwMaxLiveVideoStretch          AS DWORD       ' // OBSOLETE! This field remains for compatability reasons only
   dwMinHwCodecStretch            AS DWORD       ' // OBSOLETE! This field remains for compatability reasons only
   dwMaxHwCodecStretch            AS DWORD       ' // OBSOLETE! This field remains for compatability reasons only
   dwReserved1                    AS DWORD       ' // reserved
   dwReserved2                    AS DWORD       ' // reserved
   dwReserved3                    AS DWORD       ' // reserved
END TYPE


'/*
' * This structure is the DDCAPS structure as it was in version 2 and 3 of Direct X.
' * It is present for back compatability.
' */

' // Size = 316 bytes
TYPE DDCAPS_DX3 DWORD
   dwSize                         AS DWORD    ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD    ' // driver specific capabilities
   dwCaps2                        AS DWORD    ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD    ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD    ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD    ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD    ' // palette capabilities
   dwSVCaps                       AS DWORD    ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD    ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD    ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD    ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD    ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD    ' // total amount of video memory
   dwVidMemFree                   AS DWORD    ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD    ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD    ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD    ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD    ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD    ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD    ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD    ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD    ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD    ' // ROPS supported
   tddsCaps                       AS DDSCAPS  ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD    ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD    ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD    ' // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxLiveVideoStretch          AS DWORD    ' // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinHwCodecStretch            AS DWORD    ' // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxHwCodecStretch            AS DWORD    ' // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwReserved1                    AS DWORD    ' // reserved
   dwReserved2                    AS DWORD    ' // reserved
   dwReserved3                    AS DWORD    ' // reserved
   dwSVBCaps                      AS DWORD    ' // driver specific capabilities for System->Vmem blts
   dwSVBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->Vmem blts
   dwSVBFXCaps                    AS DWORD    ' // driver FX capabilities for System->Vmem blts
   dwSVBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->Vmem blts
   dwVSBCaps                      AS DWORD    ' // driver specific capabilities for Vmem->System blts
   dwVSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for Vmem->System blts
   dwVSBFXCaps                    AS DWORD    ' // driver FX capabilities for Vmem->System blts
   dwVSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for Vmem->System blts
   dwSSBCaps                      AS DWORD    ' // driver specific capabilities for System->System blts
   dwSSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->System blts
   dwSSBFXCaps                    AS DWORD    ' // driver FX capabilities for System->System blts
   dwSSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->System blts
   dwReserved4                    AS DWORD    ' // reserved
   dwReserved5                    AS DWORD    ' // reserved
   dwReserved6                    AS DWORD    ' // reserved
END TYPE


'/*
' * This structure is the DDCAPS structure as it was in version 5 of Direct X.
' * It is present for back compatability.
' */

' // Size = 364 bytes
TYPE DDCAPS_DX5 DWORD
   dwSize                         AS DWORD    ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD    ' // driver specific capabilities
   dwCaps2                        AS DWORD    ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD    ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD    ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD    ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD    ' // palette capabilities
   dwSVCaps                       AS DWORD    ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD    ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD    ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD    ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD    ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD    ' // total amount of video memory
   dwVidMemFree                   AS DWORD    ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD    ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD    ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD    ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD    ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD    ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD    ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD    ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD    ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD    ' // ROPS supported
   tddsCaps                       AS DDSCAPS  ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD    ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD    ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD    ' // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxLiveVideoStretch          AS DWORD    ' // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinHwCodecStretch            AS DWORD    ' // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxHwCodecStretch            AS DWORD    ' // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwReserved1                    AS DWORD    ' // reserved
   dwReserved2                    AS DWORD    ' // reserved
   dwReserved3                    AS DWORD    ' // reserved
   dwSVBCaps                      AS DWORD    ' // driver specific capabilities for System->Vmem blts
   dwSVBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->Vmem blts
   dwSVBFXCaps                    AS DWORD    ' // driver FX capabilities for System->Vmem blts
   dwSVBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->Vmem blts
   dwVSBCaps                      AS DWORD    ' // driver specific capabilities for Vmem->System blts
   dwVSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for Vmem->System blts
   dwVSBFXCaps                    AS DWORD    ' // driver FX capabilities for Vmem->System blts
   dwVSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for Vmem->System blts
   dwSSBCaps                      AS DWORD    ' // driver specific capabilities for System->System blts
   dwSSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->System blts
   dwSSBFXCaps                    AS DWORD    ' // driver FX capabilities for System->System blts
   dwSSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->System blts
   '// Members added for DX5:
   dwMaxVideoPorts                AS DWORD    ' // maximum number of usable video ports
   dwCurrVideoPorts               AS DWORD    ' // current number of video ports used
   dwSVBCaps2                     AS DWORD    ' // more driver specific capabilities for System->Vmem blts
   dwNLVBCaps                     AS DWORD    ' // driver specific capabilities for non-local->local vidmem blts
   dwNLVBCaps2                    AS DWORD    ' // more driver specific capabilities non-local->local vidmem blts
   dwNLVBCKeyCaps                 AS DWORD    ' // driver color key capabilities for non-local->local vidmem blts
   dwNLVBFXCaps                   AS DWORD    ' // driver FX capabilities for non-local->local blts
   dwNLVBRops(%DD_ROP_SPACE-1)    AS DWORD    ' // ROPS supported for non-local->local blts
END TYPE

' // Size = 380 bytes
TYPE DDCAPS_DX6 DWORD
   dwSize                         AS DWORD    ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD    ' // driver specific capabilities
   dwCaps2                        AS DWORD    ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD    ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD    ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD    ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD    ' // palette capabilities
   dwSVCaps                       AS DWORD    ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD    ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD    ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD    ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD    ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD    ' // total amount of video memory
   dwVidMemFree                   AS DWORD    ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD    ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD    ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD    ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD    ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD    ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD    ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD    ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD    ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD    ' // ROPS supported
   tddsOldCaps                    AS DDSCAPS  ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD    ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD    ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD    ' // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxLiveVideoStretch          AS DWORD    ' // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinHwCodecStretch            AS DWORD    ' // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxHwCodecStretch            AS DWORD    ' // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwReserved1                    AS DWORD    ' // reserved
   dwReserved2                    AS DWORD    ' // reserved
   dwReserved3                    AS DWORD    ' // reserved
   dwSVBCaps                      AS DWORD    ' // driver specific capabilities for System->Vmem blts
   dwSVBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->Vmem blts
   dwSVBFXCaps                    AS DWORD    ' // driver FX capabilities for System->Vmem blts
   dwSVBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->Vmem blts
   dwVSBCaps                      AS DWORD    ' // driver specific capabilities for Vmem->System blts
   dwVSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for Vmem->System blts
   dwVSBFXCaps                    AS DWORD    ' // driver FX capabilities for Vmem->System blts
   dwVSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for Vmem->System blts
   dwSSBCaps                      AS DWORD    ' // driver specific capabilities for System->System blts
   dwSSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->System blts
   dwSSBFXCaps                    AS DWORD    ' // driver FX capabilities for System->System blts
   dwSSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->System blts
   '// Members added for DX5:
   dwMaxVideoPorts                AS DWORD    ' // maximum number of usable video ports
   dwCurrVideoPorts               AS DWORD    ' // current number of video ports used
   dwSVBCaps2                     AS DWORD    ' // more driver specific capabilities for System->Vmem blts
   dwNLVBCaps                     AS DWORD    ' // driver specific capabilities for non-local->local vidmem blts
   dwNLVBCaps2                    AS DWORD    ' // more driver specific capabilities non-local->local vidmem blts
   dwNLVBCKeyCaps                 AS DWORD    ' // driver color key capabilities for non-local->local vidmem blts
   dwNLVBFXCaps                   AS DWORD    ' // driver FX capabilities for non-local->local blts
   dwNLVBRops(%DD_ROP_SPACE-1)    AS DWORD    ' // ROPS supported for non-local->local blts
   '// Members added for DX6 release
   tddsCaps                       AS DDSCAPS2 ' // Surface Caps
END TYPE

' // Size = 380 bytes
TYPE DDCAPS_DX7 DWORD
   dwSize                         AS DWORD    ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD    ' // driver specific capabilities
   dwCaps2                        AS DWORD    ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD    ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD    ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD    ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD    ' // palette capabilities
   dwSVCaps                       AS DWORD    ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD    ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD    ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD    ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD    ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD    ' // total amount of video memory
   dwVidMemFree                   AS DWORD    ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD    ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD    ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD    ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD    ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD    ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD    ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD    ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD    ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD    ' // ROPS supported
   tddsOldCaps                    AS DDSCAPS  ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD    ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD    ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD    ' // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxLiveVideoStretch          AS DWORD    ' // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinHwCodecStretch            AS DWORD    ' // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxHwCodecStretch            AS DWORD    ' // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwReserved1                    AS DWORD    ' // reserved
   dwReserved2                    AS DWORD    ' // reserved
   dwReserved3                    AS DWORD    ' // reserved
   dwSVBCaps                      AS DWORD    ' // driver specific capabilities for System->Vmem blts
   dwSVBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->Vmem blts
   dwSVBFXCaps                    AS DWORD    ' // driver FX capabilities for System->Vmem blts
   dwSVBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->Vmem blts
   dwVSBCaps                      AS DWORD    ' // driver specific capabilities for Vmem->System blts
   dwVSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for Vmem->System blts
   dwVSBFXCaps                    AS DWORD    ' // driver FX capabilities for Vmem->System blts
   dwVSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for Vmem->System blts
   dwSSBCaps                      AS DWORD    ' // driver specific capabilities for System->System blts
   dwSSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->System blts
   dwSSBFXCaps                    AS DWORD    ' // driver FX capabilities for System->System blts
   dwSSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->System blts
   '// Members added for DX5:
   dwMaxVideoPorts                AS DWORD    ' // maximum number of usable video ports
   dwCurrVideoPorts               AS DWORD    ' // current number of video ports used
   dwSVBCaps2                     AS DWORD    ' // more driver specific capabilities for System->Vmem blts
   dwNLVBCaps                     AS DWORD    ' // driver specific capabilities for non-local->local vidmem blts
   dwNLVBCaps2                    AS DWORD    ' // more driver specific capabilities non-local->local vidmem blts
   dwNLVBCKeyCaps                 AS DWORD    ' // driver color key capabilities for non-local->local vidmem blts
   dwNLVBFXCaps                   AS DWORD    ' // driver FX capabilities for non-local->local blts
   dwNLVBRops(%DD_ROP_SPACE-1)    AS DWORD    ' // ROPS supported for non-local->local blts
   '// Members added for DX6 release
   tddsCaps                       AS DDSCAPS2 ' // Surface Caps
END TYPE

' // Size = 380 bytes
TYPE DDCAPS DWORD   ' DDCAPS_DX7
   dwSize                         AS DWORD    ' // size of the DDDRIVERCAPS structure
   dwCaps                         AS DWORD    ' // driver specific capabilities
   dwCaps2                        AS DWORD    ' // more driver specific capabilites
   dwCKeyCaps                     AS DWORD    ' // color key capabilities of the surface
   dwFXCaps                       AS DWORD    ' // driver specific stretching and effects capabilites
   dwFXAlphaCaps                  AS DWORD    ' // alpha driver specific capabilities
   dwPalCaps                      AS DWORD    ' // palette capabilities
   dwSVCaps                       AS DWORD    ' // stereo vision capabilities
   dwAlphaBltConstBitDepths       AS DWORD    ' // DDBD_2,4,8
   dwAlphaBltPixelBitDepths       AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaBltSurfaceBitDepths     AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlayConstBitDepths   AS DWORD    ' // DDBD_2,4,8
   dwAlphaOverlayPixelBitDepths   AS DWORD    ' // DDBD_1,2,4,8
   dwAlphaOverlaySurfaceBitDepths AS DWORD    ' // DDBD_1,2,4,8
   dwZBufferBitDepths             AS DWORD    ' // DDBD_8,16,24,32
   dwVidMemTotal                  AS DWORD    ' // total amount of video memory
   dwVidMemFree                   AS DWORD    ' // amount of free video memory
   dwMaxVisibleOverlays           AS DWORD    ' // maximum number of visible overlays
   dwCurrVisibleOverlays          AS DWORD    ' // current number of visible overlays
   dwNumFourCCCodes               AS DWORD    ' // number of four cc codes
   dwAlignBoundarySrc             AS DWORD    ' // source rectangle alignment
   dwAlignSizeSrc                 AS DWORD    ' // source rectangle byte size
   dwAlignBoundaryDest            AS DWORD    ' // dest rectangle alignment
   dwAlignSizeDest                AS DWORD    ' // dest rectangle byte size
   dwAlignStrideAlign             AS DWORD    ' // stride alignment
   dwRops(%DD_ROP_SPACE-1)        AS DWORD    ' // ROPS supported
   tddsOldCaps                    AS DDSCAPS  ' // DDSCAPS structure has all the general capabilities
   dwMinOverlayStretch            AS DWORD    ' // minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxOverlayStretch            AS DWORD    ' // maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinLiveVideoStretch          AS DWORD    ' // minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxLiveVideoStretch          AS DWORD    ' // maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMinHwCodecStretch            AS DWORD    ' // minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwMaxHwCodecStretch            AS DWORD    ' // maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
   dwReserved1                    AS DWORD    ' // reserved
   dwReserved2                    AS DWORD    ' // reserved
   dwReserved3                    AS DWORD    ' // reserved
   dwSVBCaps                      AS DWORD    ' // driver specific capabilities for System->Vmem blts
   dwSVBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->Vmem blts
   dwSVBFXCaps                    AS DWORD    ' // driver FX capabilities for System->Vmem blts
   dwSVBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->Vmem blts
   dwVSBCaps                      AS DWORD    ' // driver specific capabilities for Vmem->System blts
   dwVSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for Vmem->System blts
   dwVSBFXCaps                    AS DWORD    ' // driver FX capabilities for Vmem->System blts
   dwVSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for Vmem->System blts
   dwSSBCaps                      AS DWORD    ' // driver specific capabilities for System->System blts
   dwSSBCKeyCaps                  AS DWORD    ' // driver color key capabilities for System->System blts
   dwSSBFXCaps                    AS DWORD    ' // driver FX capabilities for System->System blts
   dwSSBRops(%DD_ROP_SPACE-1)     AS DWORD    ' // ROPS supported for System->System blts
   '// Members added for DX5:
   dwMaxVideoPorts                AS DWORD    ' // maximum number of usable video ports
   dwCurrVideoPorts               AS DWORD    ' // current number of video ports used
   dwSVBCaps2                     AS DWORD    ' // more driver specific capabilities for System->Vmem blts
   dwNLVBCaps                     AS DWORD    ' // driver specific capabilities for non-local->local vidmem blts
   dwNLVBCaps2                    AS DWORD    ' // more driver specific capabilities non-local->local vidmem blts
   dwNLVBCKeyCaps                 AS DWORD    ' // driver color key capabilities for non-local->local vidmem blts
   dwNLVBFXCaps                   AS DWORD    ' // driver FX capabilities for non-local->local blts
   dwNLVBRops(%DD_ROP_SPACE-1)    AS DWORD    ' // ROPS supported for non-local->local blts
   '// Members added for DX6 release
   tddsCaps                       AS DDSCAPS2 ' // Surface Caps
END TYPE


'/*
' * DDPIXELFORMAT
' */

' // Size = 4 bytes
UNION DDPIXELFORMAT_UNION_1 DWORD
   dwRGBBitCount           AS DWORD   ' // how many bits per pixel
   dwYUVBitCount           AS DWORD   ' // how many bits per pixel
   dwZBufferBitDepth       AS DWORD   ' // how many total bits/pixel in z buffer (including any stencil bits)
   dwAlphaBitDepth         AS DWORD   ' // how many bits for alpha channels
   dwLuminanceBitCount     AS DWORD   ' // how many bits per pixel
   dwBumpBitCount          AS DWORD   ' // how many bits per "buxel", total
   dwPrivateFormatBitCount AS DWORD   ' // Bits per pixel of private driver formats. Only valid in texture
END UNION

' // Size = 4 bytes
UNION DDPIXELFORMAT_UNION_2 DWORD
   dwRBitMask         AS DWORD   ' // mask for red bit
   dwYBitMask         AS DWORD   ' // mask for Y bits
   dwStencilBitDepth  AS DWORD   ' // how many stencil bits (note: dwZBufferBitDepth-dwStencilBitDepth is total Z-only bits)
   dwLuminanceBitMask AS DWORD   ' // mask for luminance bits
   dwBumpDuBitMask    AS DWORD   ' // mask for bump map U delta bits
   dwOperations       AS DWORD   ' // DDPF_D3DFORMAT Operations
END UNION

' // Size = 4 bytes
TYPE DDPIXELFORMAT_MultiSampleCaps DWORD FILL
   wFlipMSTypes AS WORD   ' // Multisample methods supported via flip for this D3DFORMAT
   wBltMSTypes  AS WORD   ' // Multisample methods supported via blt for this D3DFORMAT
END TYPE

' // Size = 4 bytes
UNION DDPIXELFORMAT_UNION_3 DWORD
   dwGBitMask      AS DWORD   ' // mask for green bits
   dwUBitMask      AS DWORD   ' // mask for U bits
   dwZBitMask      AS DWORD   ' // mask for Z bits
   dwBumpDvBitMask AS DWORD   ' // mask for bump map V delta bits
   DDPIXELFORMAT_MultiSampleCaps
END UNION

' // Size = 4 bytes
UNION DDPIXELFORMAT_UNION_4 DWORD
   dwBBitMask             AS DWORD   ' // mask for blue bits
   dwVBitMask             AS DWORD   ' // mask for V bits
   dwStencilBitMask       AS DWORD   ' // mask for stencil bits
   dwBumpLuminanceBitMask AS DWORD   ' // mask for luminance in bump map
END UNION

' // Size = 4 bytes
UNION DDPIXELFORMAT_UNION_5 DWORD
   dwRGBAlphaBitMask       AS DWORD   ' // mask for alpha channel
   dwYUVAlphaBitMask       AS DWORD   ' // mask for alpha channel
   dwLuminanceAlphaBitMask AS DWORD   ' // mask for alpha channel
   dwRGBZBitMask           AS DWORD   ' // mask for Z channel
   dwYUVZBitMask           AS DWORD   ' // mask for Z channel
END UNION

' // Size = 32 bytes
TYPE DDPIXELFORMAT DWORD
   dwSize   AS DWORD      ' // size of structure
   dwFlags  AS DWORD      ' // pixel format flags
   dwFourCC AS DWORD      ' // (FOURCC code)
   DDPIXELFORMAT_UNION_1
   DDPIXELFORMAT_UNION_2
   DDPIXELFORMAT_UNION_3
   DDPIXELFORMAT_UNION_4
   DDPIXELFORMAT_UNION_5
END TYPE

'/*
' * DDOVERLAYFX
' */

' // Size = 4 bytes
UNION DDOVERLAYFX_UNION_1 DWORD
   dwAlphaDestConst AS DWORD           ' // Constant to use as alpha channel for dest
   lpDDSAlphaDest   AS DWORD           ' // Surface to use as alpha channel for dest
END UNION

' // Size = 4 bytes
UNION DDOVERLAYFX_UNION_2 DWORD
   dwAlphaSrcConst AS DWORD            ' // Constant to use as alpha channel for src
   lpDDSAlphaSrc   AS DWORD            ' // Surface to use as alpha channel for src
END UNION

' // Size = 56 bytes
TYPE DDOVERLAYFX DWORD
   dwSize                   AS DWORD        ' // size of structure
   dwAlphaEdgeBlendBitDepth AS DWORD        ' // Bit depth used to specify constant for alpha edge blend
   dwAlphaEdgeBlend         AS DWORD        ' // Constant to use as alpha for edge blend
   dwReserved               AS DWORD
   dwAlphaDestConstBitDepth AS DWORD        ' // Bit depth used to specify alpha constant for destination
   DDOVERLAYFX_UNION_1
   dwAlphaSrcConstBitDepth  AS DWORD        ' // Bit depth used to specify alpha constant for source
   DDOVERLAYFX_UNION_2
   dckDestColorkey          AS DDCOLORKEY   ' // DestColorkey override
   dckSrcColorkey           AS DDCOLORKEY   ' // DestColorkey override
   dwDDFX                   AS DWORD        ' // Overlay FX
   dwFlags                  AS DWORD        ' // flags
END TYPE

'/*
' * DDBLTBATCH: BltBatch entry structure
' */
' // Size = 20 bytes
TYPE DDBLTBATCH DWORD
   lprDest   AS RECT  PTR   ' LPRECT
   lpDDSSrc  AS DWORD       ' LPDIRECTDRAWSURFACE
   lprSrc    AS RECT  PTR   ' LPRECT
   dwFlags   AS DWORD       ' DWORD
   lpDDBltFx AS DWORD       ' LPDDBLTFX
END TYPE

'/*
' * DDGAMMARAMP
' */

' // Size = 1536 bytes
TYPE DDGAMMARAMP WORD
   red   (255) AS WORD   ' WORD[256]
   green (255) AS WORD   ' WORD[256]
   blue  (255) AS WORD   ' WORD[256]
END TYPE

'/*
' *  This is the structure within which DirectDraw returns data about the current graphics driver and chipset
' */

%MAX_DDDEVICEID_STRING          = 512

' // Size = 1064 bytes
TYPE DDDEVICEIDENTIFIER DWORD
'    /*
'     * These elements are for presentation to the user only. They should not be used to identify particular
'     * drivers, since this is unreliable and many different strings may be associated with the same
'     * device, and the same driver from different vendors.
'     */
   szDriver AS ASCIIZ * %MAX_DDDEVICEID_STRING       ' char    szDriver[MAX_DDDEVICEID_STRING];
   szDescription AS ASCIIZ * %MAX_DDDEVICEID_STRING  ' char    szDescription[MAX_DDDEVICEID_STRING];
'    /*
'     * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
'     * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
'     * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
'     *
'     * This version has the form:
'     *  wProduct = HIWORD(liDriverVersion.HighPart)
'     *  wVersion = LOWORD(liDriverVersion.HighPart)
'     *  wSubVersion = HIWORD(liDriverVersion.LowPart)
'     *  wBuild = LOWORD(liDriverVersion.LowPart)
'     */
'#ifdef _WIN32
   liDriverVersion AS QUAD           ' LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */
'#else
'   dwDriverVersionLowPart AS DWORD   ' DWORD   dwDriverVersionLowPart;     /* Defined for 16 bit driver components */
'   dwDriverVersionHighPart AS DWORD  ' DWORD   dwDriverVersionHighPart;
'#endif

'    /*
'     * These elements can be used to identify particular chipsets. Use with extreme caution.
'     *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
'     *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
'     *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
'     *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
'     */
   dwVendorId AS DWORD
   dwDeviceId AS DWORD
   dwSubSysId AS DWORD
   dwRevision AS DWORD

'    /*
'     * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
'     * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
'     * reprofile the graphics subsystem.
'     * This element can also be used to identify particular problematic drivers.
'     */
   guidDeviceIdentifier AS GUID
END TYPE

' // Size = 1072 bytes
TYPE DDDEVICEIDENTIFIER2   ' Must be 8 bytes aligned
'    /*
'     * These elements are for presentation to the user only. They should not be used to identify particular
'     * drivers, since this is unreliable and many different strings may be associated with the same
'     * device, and the same driver from different vendors.
'     */
   szDriver AS ASCIIZ * %MAX_DDDEVICEID_STRING       ' char    szDriver[MAX_DDDEVICEID_STRING];
   szDescription AS ASCIIZ * %MAX_DDDEVICEID_STRING  ' char    szDescription[MAX_DDDEVICEID_STRING];

'    /*
'     * This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
'     * on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
'     * drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
'     *
'     * This version has the form:
'     *  wProduct = HIWORD(liDriverVersion.HighPart)
'     *  wVersion = LOWORD(liDriverVersion.HighPart)
'     *  wSubVersion = HIWORD(liDriverVersion.LowPart)
'     *  wBuild = LOWORD(liDriverVersion.LowPart)
'     */
'#ifdef _WIN32
   liDriverVersion AS QUAD       ' LARGE_INTEGER liDriverVersion;      /* Defined for applications and other 32 bit components */
'#else
'   DWORD   dwDriverVersionLowPart;     /* Defined for 16 bit driver components */
'   DWORD   dwDriverVersionHighPart;
'#endif

'    /*
'     * These elements can be used to identify particular chipsets. Use with extreme caution.
'     *   dwVendorId     Identifies the manufacturer. May be zero if unknown.
'     *   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
'     *   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
'     *   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
'     */
   dwVendorId AS DWORD
   dwDeviceId AS DWORD
   dwSubSysId AS DWORD
   dwRevision AS DWORD

'    /*
'     * This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
'     * driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
'     * reprofile the graphics subsystem.
'     * This element can also be used to identify particular problematic drivers.
'     */
   guidDeviceIdentifier AS GUID

'    /*
'     * This element is used to determine the Windows Hardware Quality Lab (WHQL)
'     * certification level for this driver/device pair.
'     */
   dwWHQLLevel AS DWORD
   alignment__ AS DWORD   ' // To keep 8 bytes alignment

END TYPE

'/*
' * Flags for the IDirectDraw4::GetDeviceIdentifier method
' */

'/*
' * This flag causes GetDeviceIdentifier to return information about the host (typically 2D) adapter in a system equipped
' * with a stacked secondary 3D adapter. Such an adapter appears to the application as if it were part of the
' * host adapter, but is typically physcially located on a separate card. The stacked secondary's information is
' * returned when GetDeviceIdentifier's dwFlags field is zero, since this most accurately reflects the qualities
' * of the DirectDraw object involved.
' */
%DDGDI_GETHOSTIDENTIFIER        = &H00000001???

'/*
' * Macros for interpretting DDEVICEIDENTIFIER2.dwWHQLLevel
' */
'#define GET_WHQL_YEAR( dwWHQLLevel ) \
'    ( (dwWHQLLevel) / 0x10000 )
'#define GET_WHQL_MONTH( dwWHQLLevel ) \
'    ( ( (dwWHQLLevel) / 0x100 ) & 0x00ff )
'#define GET_WHQL_DAY( dwWHQLLevel ) \
'    ( (dwWHQLLevel) & 0xff )

MACRO GET_WHQL_YEAR(dwWHQLLevel) = dwWHQLLevel \ &H10000
MACRO GET_WHQL_MONTH(dwWHQLLevel) = (dwWHQLLevel \ &H100) AND &H00ff
MACRO GET_WHQL_DAY(dwWHQLLevel) = dwWHQLLevel AND &Hff


'/*
' * callbacks
' */
'typedef DWORD   (FAR PASCAL *LPCLIPPERCALLBACK)(LPDIRECTDRAWCLIPPER lpDDClipper, HWND hWnd, DWORD code, LPVOID lpContext );
'#ifdef STREAMING
'typedef DWORD   (FAR PASCAL *LPSURFACESTREAMINGCALLBACK)(DWORD);
'#endif

'FUNCTION CLIPPERCALLBACK (BYVAL lpDDClipper AS DWORD, BYVAL hWnd AS DWORD, BYVAL dwCode AS DWORD, BYVAL lpContext AS DWORD) AS DWORD
'FUNCTION SURFACESTREAMINGCALLBACK (BYVAL DWORD) AS DWORD

'/*
' * DDSURFACEDESC
' */

' // Size = 4 bytes
UNION DDSURFACEDESC_UNION_1 DWORD
   lPitch       AS DWORD               ' // distance to start of next line (return value only)
   dwLinearSize AS DWORD               ' // Formless late-allocated optimized surface size
END UNION

' // Size = 4 bytes
UNION DDSURFACEDESC_UNION_2 DWORD
   dwMipMapCount     AS DWORD          ' // number of mip-map levels requested
   dwZBufferBitDepth AS DWORD          ' // depth of Z buffer requested
   dwRefreshRate     AS DWORD          ' // refresh rate (used when display mode is described)
END UNION

' // Size = 108 bytes
TYPE DDSURFACEDESC DWORD
   dwSize                AS DWORD           ' // size of the DDSURFACEDESC structure
   dwFlags               AS DWORD           ' // determines what fields are valid
   dwHeight              AS DWORD           ' // height of surface to be created
   dwWidth               AS DWORD           ' // width of input surface
   DDSURFACEDESC_UNION_1
   dwBackBufferCount     AS DWORD           ' // number of back buffers requested
   DDSURFACEDESC_UNION_2
   dwAlphaBitDepth       AS DWORD           ' // depth of alpha buffer requested
   dwReserved            AS DWORD           ' // reserved
   lpSurface             AS DWORD           ' // pointer to the associated surface memory
   ddckCKDestOverlay     AS DDCOLORKEY      ' // color key for destination overlay use
   ddckCKDestBlt         AS DDCOLORKEY      ' // color key for destination blt use
   ddckCKSrcOverlay      AS DDCOLORKEY      ' // color key for source overlay use
   ddckCKSrcBlt          AS DDCOLORKEY      ' // color key for source blt use
   ddpfPixelFormat       AS DDPIXELFORMAT   '    // pixel format description of the surface
   ddsCaps               AS DDSCAPS         ' // direct draw surface capabilities
END TYPE

'/*
' * DDSURFACEDESC2
' */

' // Size = 4 bytes
UNION DDSURFACEDESC2_UNION_1 DWORD
   lPitch       AS LONG                ' // distance to start of next line (return value only)
   dwLinearSize AS DWORD               ' // Formless late-allocated optimized surface size
END UNION

' // Size = 4 bytes
UNION DDSURFACEDESC2_UNION_5 DWORD
   dwBackBufferCount AS DWORD          ' // number of back buffers requested
   dwDepth           AS DWORD          ' // the depth if this is a volume texture
END UNION

' // Size = 4 bytes
UNION DDSURFACEDESC2_UNION_2 DWORD
   dwMipMapCount AS DWORD              ' // number of mip-map levels requestde
                                       ' // dwZBufferBitDepth removed, use ddpfPixelFormat one instead
   dwRefreshRate AS DWORD              ' // refresh rate (used when display mode is described)
   dwSrcVBHandle AS DWORD              ' // The source used in VB::Optimize
END UNION

' // Size = 4 bytes
UNION DDSURFACEDESC2_UNION_3 DWORD
   ddckCKDestOverlay AS DDCOLORKEY     ' // color key for destination overlay use
   dwEmptyFaceColor  AS DWORD          ' // Physical color for empty cubemap faces
END UNION

' // Size = 32 bytes
UNION DDSURFACEDESC2_UNION_4 DWORD
   ddpfPixelFormat AS DDPIXELFORMAT    ' // pixel format description of the surface
   dwFVF           AS DWORD            ' // vertex format description of vertex buffers
END UNION

' // Size = 124 bytes
TYPE DDSURFACEDESC2 DWORD
   dwSize                 AS DWORD        ' // size of the DDSURFACEDESC structure
   dwFlags                AS DWORD        ' // determines what fields are valid
   dwHeight               AS DWORD        ' // height of surface to be created
   dwWidth                AS DWORD        ' // width of input surface
   DDSURFACEDESC2_UNION_1
   DDSURFACEDESC2_UNION_5
   DDSURFACEDESC2_UNION_2
   dwAlphaBitDepth        AS DWORD        ' // depth of alpha buffer requested
   dwReserved             AS DWORD        ' // reserved
   lpSurface              AS DWORD        ' // pointer to the associated surface memory
   DDSURFACEDESC2_UNION_3
   ddckCKDestBlt          AS DDCOLORKEY   ' // color key for destination blt use
   ddckCKSrcOverlay       AS DDCOLORKEY   ' // color key for source overlay use
   ddckCKSrcBlt           AS DDCOLORKEY   ' // color key for source blt use
   DDSURFACEDESC2_UNION_4
   ddsCaps                AS DDSCAPS2     ' // direct draw surface capabilities
   dwTextureStage         AS DWORD        ' // stage in multitexture cascade
END TYPE

'/*
' * ddsCaps field is valid.
' */
%DDSD_CAPS               = &H00000001???    ' // default

'/*
' * dwHeight field is valid.
' */
%DDSD_HEIGHT             = &H00000002???

'/*
' * dwWidth field is valid.
' */
%DDSD_WIDTH              = &H00000004???

'/*
' * lPitch is valid.
' */
%DDSD_PITCH              = &H00000008???

'/*
' * dwBackBufferCount is valid.
' */
%DDSD_BACKBUFFERCOUNT    = &H00000020???

'/*
' * dwZBufferBitDepth is valid.  (shouldnt be used in DDSURFACEDESC2)
' */
%DDSD_ZBUFFERBITDEPTH    = &H00000040???

'/*
' * dwAlphaBitDepth is valid.
' */
%DDSD_ALPHABITDEPTH      = &H00000080???


'/*
' * lpSurface is valid.
' */
%DDSD_LPSURFACE          = &H00000800???

'/*
' * ddpfPixelFormat is valid.
' */
%DDSD_PIXELFORMAT        = &H00001000???

'/*
' * ddckCKDestOverlay is valid.
' */
%DDSD_CKDESTOVERLAY      = &H00002000???

'/*
' * ddckCKDestBlt is valid.
' */
%DDSD_CKDESTBLT          = &H00004000???

'/*
' * ddckCKSrcOverlay is valid.
' */
%DDSD_CKSRCOVERLAY       = &H00008000???

'/*
' * ddckCKSrcBlt is valid.
' */
%DDSD_CKSRCBLT           = &H00010000???

'/*
' * dwMipMapCount is valid.
' */
%DDSD_MIPMAPCOUNT        = &H00020000???

' /*
'  * dwRefreshRate is valid
'  */
%DDSD_REFRESHRATE        = &H00040000???

'/*
' * dwLinearSize is valid
' */
%DDSD_LINEARSIZE         = &H00080000???

'/*
' * dwTextureStage is valid
' */
%DDSD_TEXTURESTAGE       = &H00100000???

'/*
' * dwFVF is valid
' */
%DDSD_FVF                = &H00200000???

'/*
' * dwSrcVBHandle is valid
' */
%DDSD_SRCVBHANDLE        = &H00400000???

'/*
' * dwDepth is valid
' */
%DDSD_DEPTH              = &H00800000???

'/*
' * All input fields are valid.
' */
%DDSD_ALL                = &H00FFF9EE???

'/*
' * DDOPTSURFACEDESC
' */

' // Size = 48 bytes
TYPE DDOPTSURFACEDESC DWORD
   dwSize             AS DWORD         ' // size of the DDOPTSURFACEDESC structure
   dwFlags            AS DWORD         ' // determines what fields are valid
   ddSCaps            AS DDSCAPS2      ' // Common caps like: Memory type
   ddOSCaps           AS DDOSCAPS      ' // Common caps like: Memory type
   guid               AS GUID          ' // Compression technique GUID
   dwCompressionRatio AS DWORD         ' // Compression ratio
END TYPE

'/*
' * guid field is valid.
' */
%DDOSD_GUID                  = &H00000001???

'/*
' * dwCompressionRatio field is valid.
' */
%DDOSD_COMPRESSION_RATIO     = &H00000002???

'/*
' * ddSCaps field is valid.
' */
%DDOSD_SCAPS                 = &H00000004???

'/*
' * ddOSCaps field is valid.
' */
%DDOSD_OSCAPS                = &H00000008???

'/*
' * All input fields are valid.
' */
%DDOSD_ALL                   = &H0000000f???

'/*
' * The surface's optimized pixelformat is compressed
' */
%DDOSDCAPS_OPTCOMPRESSED     = &H00000001???

'/*
' * The surface's optimized pixelformat is reordered
' */
%DDOSDCAPS_OPTREORDERED      = &H00000002???

'/*
' * The opt surface is a monolithic mipmap
' */
%DDOSDCAPS_MONOLITHICMIPMAP  = &H00000004???

'/*
' * The valid Surf caps:
' * #define DDSCAPS_SYSTEMMEMORY         0x00000800l
' * #define DDSCAPS_VIDEOMEMORY          0x00004000l
' * #define DDSCAPS_LOCALVIDMEM          0x10000000l
' * #define DDSCAPS_NONLOCALVIDMEM       0x20000000l
' */
%DDOSDCAPS_VALIDSCAPS         = &H30004800???

'/*
' * The valid OptSurf caps
' */
%DDOSDCAPS_VALIDOSCAPS        = &H00000007???


'/*
' * DDCOLORCONTROL
' */
' // Size = 40 bytes
TYPE DDCOLORCONTROL DWORD
   dwSize       AS DWORD
   dwFlags      AS DWORD
   lBrightness  AS LONG
   lContrast    AS LONG
   lHue         AS LONG
   lSaturation  AS LONG
   lSharpness   AS LONG
   lGamma       AS LONG
   lColorEnable AS LONG
   dwReserved1  AS DWORD
END TYPE


'/*
' * lBrightness field is valid.
' */
%DDCOLOR_BRIGHTNESS           = &H00000001???

'/*
' * lContrast field is valid.
' */
%DDCOLOR_CONTRAST             = &H00000002???

'/*
' * lHue field is valid.
' */
%DDCOLOR_HUE                  = &H00000004???

'/*
' * lSaturation field is valid.
' */
%DDCOLOR_SATURATION           = &H00000008???

'/*
' * lSharpness field is valid.
' */
%DDCOLOR_SHARPNESS            = &H00000010???

'/*
' * lGamma field is valid.
' */
%DDCOLOR_GAMMA                = &H00000020???

'/*
' * lColorEnable field is valid.
' */
%DDCOLOR_COLORENABLE          = &H00000040???



'/*============================================================================
' *
' * Direct Draw Capability Flags
' *
' * These flags are used to describe the capabilities of a given Surface.
' * All flags are bit flags.
' *
' *==========================================================================*/

'/****************************************************************************
' *
' * DIRECTDRAWSURFACE CAPABILITY FLAGS
' *
' ****************************************************************************/

'/*
' * This bit is reserved. It should not be specified.
' */
%DDSCAPS_RESERVED1                       = &H00000001???

'/*
' * Indicates that this surface contains alpha-only information.
' * (To determine if a surface is RGBA/YUVA, the pixel format must be
' * interrogated.)
' */
%DDSCAPS_ALPHA                           = &H00000002???

'/*
' * Indicates that this surface is a backbuffer.  It is generally
' * set by CreateSurface when the DDSCAPS_FLIP capability bit is set.
' * It indicates that this surface is THE back buffer of a surface
' * flipping structure.  DirectDraw supports N surfaces in a
' * surface flipping structure.  Only the surface that immediately
' * precedeces the DDSCAPS_FRONTBUFFER has this capability bit set.
' * The other surfaces are identified as back buffers by the presence
' * of the DDSCAPS_FLIP capability, their attachment order, and the
' * absence of the DDSCAPS_FRONTBUFFER and DDSCAPS_BACKBUFFER
' * capabilities.  The bit is sent to CreateSurface when a standalone
' * back buffer is being created.  This surface could be attached to
' * a front buffer and/or back buffers to form a flipping surface
' * structure after the CreateSurface call.  See AddAttachments for
' * a detailed description of the behaviors in this case.
' */
%DDSCAPS_BACKBUFFER                      = &H00000004???

'/*
' * Indicates a complex surface structure is being described.  A
' * complex surface structure results in the creation of more than
' * one surface.  The additional surfaces are attached to the root
' * surface.  The complex structure can only be destroyed by
' * destroying the root.
' */
%DDSCAPS_COMPLEX                         = &H00000008???

'/*
' * Indicates that this surface is a part of a surface flipping structure.
' * When it is passed to CreateSurface the DDSCAPS_FRONTBUFFER and
' * DDSCAP_BACKBUFFER bits are not set.  They are set by CreateSurface
' * on the resulting creations.  The dwBackBufferCount field in the
' * DDSURFACEDESC structure must be set to at least 1 in order for
' * the CreateSurface call to succeed.  The DDSCAPS_COMPLEX capability
' * must always be set with creating multiple surfaces through CreateSurface.
' */
%DDSCAPS_FLIP                            = &H00000010???

'/*
' * Indicates that this surface is THE front buffer of a surface flipping
' * structure.  It is generally set by CreateSurface when the DDSCAPS_FLIP
' * capability bit is set.
' * If this capability is sent to CreateSurface then a standalonw front buffer
' * is created.  This surface will not have the DDSCAPS_FLIP capability.
' * It can be attached to other back buffers to form a flipping structure.
' * See AddAttachments for a detailed description of the behaviors in this
' * case.
' */
%DDSCAPS_FRONTBUFFER                     = &H00000020???

'/*
' * Indicates that this surface is any offscreen surface that is not an overlay,
' * texture, zbuffer, front buffer, back buffer, or alpha surface.  It is used
' * to identify plain vanilla surfaces.
' */
%DDSCAPS_OFFSCREENPLAIN                  = &H00000040???

'/*
' * Indicates that this surface is an overlay.  It may or may not be directly visible
' * depending on whether or not it is currently being overlayed onto the primary
' * surface.  DDSCAPS_VISIBLE can be used to determine whether or not it is being
' * overlayed at the moment.
' */
%DDSCAPS_OVERLAY                         = &H00000080???

'/*
' * Indicates that unique DirectDrawPalette objects can be created and
' * attached to this surface.
' */
%DDSCAPS_PALETTE                         = &H00000100???

'/*
' * Indicates that this surface is the primary surface.  The primary
' * surface represents what the user is seeing at the moment.
' */
%DDSCAPS_PRIMARYSURFACE                  = &H00000200???


'/*
' * This flag used to be DDSCAPS_PRIMARYSURFACELEFT, which is now
' * obsolete.
' */
%DDSCAPS_RESERVED3                       = &H00000400???
%DDSCAPS_PRIMARYSURFACELEFT              = &H00000000???

'/*
' * Indicates that this surface memory was allocated in system memory
' */
%DDSCAPS_SYSTEMMEMORY                    = &H00000800???

'/*
' * Indicates that this surface can be used as a 3D texture.  It does not
' * indicate whether or not the surface is being used for that purpose.
' */
%DDSCAPS_TEXTURE                         = &H00001000???

'/*
' * Indicates that a surface may be a destination for 3D rendering.  This
' * bit must be set in order to query for a Direct3D Device Interface
' * from this surface.
' */
%DDSCAPS_3DDEVICE                        = &H00002000???

'/*
' * Indicates that this surface exists in video memory.
' */
%DDSCAPS_VIDEOMEMORY                     = &H00004000???

'/*
' * Indicates that changes made to this surface are immediately visible.
' * It is always set for the primary surface and is set for overlays while
' * they are being overlayed and texture maps while they are being textured.
' */
%DDSCAPS_VISIBLE                         = &H00008000???

'/*
' * Indicates that only writes are permitted to the surface.  Read accesses
' * from the surface may or may not generate a protection fault, but the
' * results of a read from this surface will not be meaningful.  READ ONLY.
' */
%DDSCAPS_WRITEONLY                       = &H00010000???

'/*
' * Indicates that this surface is a z buffer. A z buffer does not contain
' * displayable information.  Instead it contains bit depth information that is
' * used to determine which pixels are visible and which are obscured.
' */
%DDSCAPS_ZBUFFER                         = &H00020000???

'/*
' * Indicates surface will have a DC associated long term
' */
%DDSCAPS_OWNDC                           = &H00040000???

'/*
' * Indicates surface should be able to receive live video
' */
%DDSCAPS_LIVEVIDEO                       = &H00080000???

'/*
' * Indicates surface should be able to have a stream decompressed
' * to it by the hardware.
' */
%DDSCAPS_HWCODEC                         = &H00100000???

'/*
' * Surface is a ModeX surface.
' *
' */
%DDSCAPS_MODEX                           = &H00200000???

'/*
' * Indicates surface is one level of a mip-map. This surface will
' * be attached to other DDSCAPS_MIPMAP surfaces to form the mip-map.
' * This can be done explicitly, by creating a number of surfaces and
' * attaching them with AddAttachedSurface or by implicitly by CreateSurface.
' * If this bit is set then DDSCAPS_TEXTURE must also be set.
' */
%DDSCAPS_MIPMAP                          = &H00400000???

'/*
' * This bit is reserved. It should not be specified.
' */
%DDSCAPS_RESERVED2                       = &H00800000???


'/*
' * Indicates that memory for the surface is not allocated until the surface
' * is loaded (via the Direct3D texture Load() function).
' */
%DDSCAPS_ALLOCONLOAD                     = &H04000000???

'/*
' * Indicates that the surface will recieve data from a video port.
' */
%DDSCAPS_VIDEOPORT                       = &H08000000???

'/*
' * Indicates that a video memory surface is resident in true, local video
' * memory rather than non-local video memory. If this flag is specified then
' * so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
' * DDSCAPS_NONLOCALVIDMEM.
' */
%DDSCAPS_LOCALVIDMEM                     = &H10000000???

'/*
' * Indicates that a video memory surface is resident in non-local video
' * memory rather than true, local video memory. If this flag is specified
' * then so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
' * DDSCAPS_LOCALVIDMEM.
' */
%DDSCAPS_NONLOCALVIDMEM                  = &H20000000???

'/*
' * Indicates that this surface is a standard VGA mode surface, and not a
' * ModeX surface. (This flag will never be set in combination with the
' * DDSCAPS_MODEX flag).
' */
%DDSCAPS_STANDARDVGAMODE                 = &H40000000???

'/*
' * Indicates that this surface will be an optimized surface. This flag is
' * currently only valid in conjunction with the DDSCAPS_TEXTURE flag. The surface
' * will be created without any underlying video memory until loaded.
' */
%DDSCAPS_OPTIMIZED                       = &H80000000???

'/*
' * This bit is reserved
' */
%DDSCAPS2_RESERVED4                      = &H00000002???
%DDSCAPS2_HARDWAREDEINTERLACE            = &H00000000???

'/*
' * Indicates to the driver that this surface will be locked very frequently
' * (for procedural textures, dynamic lightmaps, etc). Surfaces with this cap
' * set must also have DDSCAPS_TEXTURE. This cap cannot be used with
' * DDSCAPS2_HINTSTATIC and DDSCAPS2_OPAQUE.
' */
%DDSCAPS2_HINTDYNAMIC                    = &H00000004???

'/*
' * Indicates to the driver that this surface can be re-ordered/retiled on
' * load. This operation will not change the size of the texture. It is
' * relatively fast and symmetrical, since the application may lock these
' * bits (although it will take a performance hit when doing so). Surfaces
' * with this cap set must also have DDSCAPS_TEXTURE. This cap cannot be
' * used with DDSCAPS2_HINTDYNAMIC and DDSCAPS2_OPAQUE.
' */
%DDSCAPS2_HINTSTATIC                     = &H00000008???

'/*
' * Indicates that the client would like this texture surface to be managed by the
' * DirectDraw/Direct3D runtime. Surfaces with this cap set must also have
' * DDSCAPS_TEXTURE set.
' */
%DDSCAPS2_TEXTUREMANAGE                  = &H00000010???

'/*
' * These bits are reserved for internal use */
%DDSCAPS2_RESERVED1                      = &H00000020???
%DDSCAPS2_RESERVED2                      = &H00000040???

'/*
' * Indicates to the driver that this surface will never be locked again.
' * The driver is free to optimize this surface via retiling and actual compression.
' * All calls to Lock() or Blts from this surface will fail. Surfaces with this
' * cap set must also have DDSCAPS_TEXTURE. This cap cannot be used with
' * DDSCAPS2_HINTDYNAMIC and DDSCAPS2_HINTSTATIC.
' */
%DDSCAPS2_OPAQUE                         = &H00000080???

'/*
' * Applications should set this bit at CreateSurface time to indicate that they
' * intend to use antialiasing. Only valid if DDSCAPS_3DDEVICE is also set.
' */
%DDSCAPS2_HINTANTIALIASING               = &H00000100???


'/*
' * This flag is used at CreateSurface time to indicate that this set of
' * surfaces is a cubic environment map
' */
%DDSCAPS2_CUBEMAP                        = &H00000200???

'/*
' * These flags preform two functions:
' * - At CreateSurface time, they define which of the six cube faces are
' *   required by the application.
' * - After creation, each face in the cubemap will have exactly one of these
' *   bits set.
' */
%DDSCAPS2_CUBEMAP_POSITIVEX              = &H00000400???
%DDSCAPS2_CUBEMAP_NEGATIVEX              = &H00000800???
%DDSCAPS2_CUBEMAP_POSITIVEY              = &H00001000???
%DDSCAPS2_CUBEMAP_NEGATIVEY              = &H00002000???
%DDSCAPS2_CUBEMAP_POSITIVEZ              = &H00004000???
%DDSCAPS2_CUBEMAP_NEGATIVEZ              = &H00008000???

'/*
' * This macro may be used to specify all faces of a cube map at CreateSurface time
' */
%DDSCAPS2_CUBEMAP_ALLFACES = ( %DDSCAPS2_CUBEMAP_POSITIVEX OR _
                               %DDSCAPS2_CUBEMAP_NEGATIVEX OR _
                               %DDSCAPS2_CUBEMAP_POSITIVEY OR _
                               %DDSCAPS2_CUBEMAP_NEGATIVEY OR _
                               %DDSCAPS2_CUBEMAP_POSITIVEZ OR _
                               %DDSCAPS2_CUBEMAP_NEGATIVEZ )

'/*
' * This flag is an additional flag which is present on mipmap sublevels from DX7 onwards
' * It enables easier use of GetAttachedSurface rather than EnumAttachedSurfaces for surface
' * constructs such as Cube Maps, wherein there are more than one mipmap surface attached
' * to the root surface.
' * This caps bit is ignored by CreateSurface
' */
%DDSCAPS2_MIPMAPSUBLEVEL                 = &H00010000???

'/* This flag indicates that the texture should be managed by D3D only */
%DDSCAPS2_D3DTEXTUREMANAGE               = &H00020000???

'/* This flag indicates that the managed surface can be safely lost */
%DDSCAPS2_DONOTPERSIST                   = &H00040000???

'/* indicates that this surface is part of a stereo flipping chain */
%DDSCAPS2_STEREOSURFACELEFT              = &H00080000???

'/*
' * Indicates that the surface is a volume.
' * Can be combined with DDSCAPS_MIPMAP to indicate a multi-level volume
' */
%DDSCAPS2_VOLUME                         = &H00200000???

'/*
' * Indicates that the surface may be locked multiple times by the application.
' * This cap cannot be used with DDSCAPS2_OPAQUE.
' */
%DDSCAPS2_NOTUSERLOCKABLE                = &H00400000???

'/*
' * Indicates that the vertex buffer data can be used to render points and
' * point sprites.
' */
%DDSCAPS2_POINTS                         = &H00800000???

'/*
' * Indicates that the vertex buffer data can be used to render rt pactches.
' */
%DDSCAPS2_RTPATCHES                      = &H01000000???

'/*
' * Indicates that the vertex buffer data can be used to render n patches.
' */
%DDSCAPS2_NPATCHES                       = &H02000000???

'/*
' * This bit is reserved for internal use
' */
%DDSCAPS2_RESERVED3                      = &H04000000???


'/*
' * Indicates that the contents of the backbuffer do not have to be preserved
' * the contents of the backbuffer after they are presented.
' */
%DDSCAPS2_DISCARDBACKBUFFER              = &H10000000???

'/*
' * Indicates that all surfaces in this creation chain should be given an alpha channel.
' * This flag will be set on primary surface chains that may have no explicit pixel format
' * (and thus take on the format of the current display mode).
' * The driver should infer that all these surfaces have a format having an alpha channel.
' * (e.g. assume D3DFMT_A8R8G8B8 if the display mode is x888.)
' */
%DDSCAPS2_ENABLEALPHACHANNEL             = &H20000000???

'/*
' * Indicates that all surfaces in this creation chain is extended primary surface format.
' * This flag will be set on extended primary surface chains that always have explicit pixel
' * format and the pixel format is typically GDI (Graphics Device Interface) couldn't handle,
' * thus only used with fullscreen application. (e.g. D3DFMT_A2R10G10B10 format)
' */
%DDSCAPS2_EXTENDEDFORMATPRIMARY          = &H40000000???

'/*
' * Indicates that all surfaces in this creation chain is additional primary surface.
' * This flag will be set on primary surface chains which must present on the adapter
' * id provided on dwCaps4. Typically this will be used to create secondary primary surface
' * on DualView display adapter.
' */
%DDSCAPS2_ADDITIONALPRIMARY              = &H80000000???

'/*
' * This is a mask that indicates the set of bits that may be set
' * at createsurface time to indicate number of samples per pixel
' * when multisampling
' */
%DDSCAPS3_MULTISAMPLE_MASK               = &H0000001F???

'/*
' * This is a mask that indicates the set of bits that may be set
' * at createsurface time to indicate the quality level of rendering
' * for the current number of samples per pixel
' */
%DDSCAPS3_MULTISAMPLE_QUALITY_MASK       = &H000000E0???
%DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT      = 5

'/*
' * This bit is reserved for internal use
' */
%DDSCAPS3_RESERVED1                      = &H00000100???

'/*
' * This bit is reserved for internal use
' */
%DDSCAPS3_RESERVED2                      = &H00000200???

'/*
' * This indicates whether this surface has light-weight miplevels
' */
%DDSCAPS3_LIGHTWEIGHTMIPMAP              = &H00000400???

'/*
' * This indicates that the mipsublevels for this surface are auto-generated
' */
%DDSCAPS3_AUTOGENMIPMAP                  = &H00000800???

'/*
' * This indicates that the mipsublevels for this surface are auto-generated
' */
%DDSCAPS3_DMAP                           = &H00001000???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)

'/*
' * This indicates that this surface is to be shared by processes
' */
%DDSCAPS3_CREATESHAREDRESOURCE           = &H00002000???

'/*
' * This indicates that this surface need to be initialized before being
' * shared, this bit implies that this surface is read only after initialization
' * absence of this bit implies that this surface allows both read and write
' */
%DDSCAPS3_READONLYRESOURCE               = &H00004000???

'/*
' * This indicates that this surface is to share an existing video memory with
' * another surface created with DDSCAPS3_CREATESHAREDRESOURCE, This bit is never
' * used with DDSCAPS3_CREATESHAREDRESOURCE
' */
%DDSCAPS3_OPENSHAREDRESOURCE             = &H00008000???

#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */


' /****************************************************************************
' *
' * DIRECTDRAW DRIVER CAPABILITY FLAGS
' *
' ****************************************************************************/

'/*
' * Display hardware has 3D acceleration.
' */
%DDCAPS_3D                       = &H00000001???

'/*
' * Indicates that DirectDraw will support only dest rectangles that are aligned
' * on DIRECTDRAWCAPS.dwAlignBoundaryDest boundaries of the surface, respectively.
' * READ ONLY.
' */
%DDCAPS_ALIGNBOUNDARYDEST        = &H00000002???

'/*
' * Indicates that DirectDraw will support only source rectangles  whose sizes in
' * BYTEs are DIRECTDRAWCAPS.dwAlignSizeDest multiples, respectively.  READ ONLY.
' */
%DDCAPS_ALIGNSIZEDEST            = &H00000004???

'/*
' * Indicates that DirectDraw will support only source rectangles that are aligned
' * on DIRECTDRAWCAPS.dwAlignBoundarySrc boundaries of the surface, respectively.
' * READ ONLY.
' */
%DDCAPS_ALIGNBOUNDARYSRC         = &H00000008???

'/*
' * Indicates that DirectDraw will support only source rectangles  whose sizes in
' * BYTEs are DIRECTDRAWCAPS.dwAlignSizeSrc multiples, respectively.  READ ONLY.
' */
%DDCAPS_ALIGNSIZESRC             = &H00000010???

'/*
' * Indicates that DirectDraw will create video memory surfaces that have a stride
' * alignment equal to DIRECTDRAWCAPS.dwAlignStride.  READ ONLY.
' */
%DDCAPS_ALIGNSTRIDE              = &H00000020???

'/*
' * Display hardware is capable of blt operations.
' */
%DDCAPS_BLT                      = &H00000040???

'/*
' * Display hardware is capable of asynchronous blt operations.
' */
%DDCAPS_BLTQUEUE                 = &H00000080???

'/*
' * Display hardware is capable of color space conversions during the blt operation.
' */
%DDCAPS_BLTFOURCC                = &H00000100???

'/*
' * Display hardware is capable of stretching during blt operations.
' */
%DDCAPS_BLTSTRETCH               = &H00000200???

'/*
' * Display hardware is shared with GDI.
' */
%DDCAPS_GDI                      = &H00000400???

'/*
' * Display hardware can overlay.
' */
%DDCAPS_OVERLAY                  = &H00000800???

'/*
' * Set if display hardware supports overlays but can not clip them.
' */
%DDCAPS_OVERLAYCANTCLIP          = &H00001000???

'/*
' * Indicates that overlay hardware is capable of color space conversions during
' * the overlay operation.
' */
%DDCAPS_OVERLAYFOURCC            = &H00002000???

'/*
' * Indicates that stretching can be done by the overlay hardware.
' */
%DDCAPS_OVERLAYSTRETCH           = &H00004000???

'/*
' * Indicates that unique DirectDrawPalettes can be created for DirectDrawSurfaces
' * other than the primary surface.
' */
%DDCAPS_PALETTE                  = &H00008000???

'/*
' * Indicates that palette changes can be syncd with the veritcal refresh.
' */
%DDCAPS_PALETTEVSYNC             = &H00010000???

'/*
' * Display hardware can return the current scan line.
' */
%DDCAPS_READSCANLINE             = &H00020000???


'/*
' * This flag used to bo DDCAPS_STEREOVIEW, which is now obsolete
' */
%DDCAPS_RESERVED1                = &H00040000???

'/*
' * Display hardware is capable of generating a vertical blank interrupt.
' */
%DDCAPS_VBI                      = &H00080000???

'/*
' * Supports the use of z buffers with blt operations.
' */
%DDCAPS_ZBLTS                    = &H00100000???

'/*
' * Supports Z Ordering of overlays.
' */
%DDCAPS_ZOVERLAYS                = &H00200000???

'/*
' * Supports color key
' */
%DDCAPS_COLORKEY                 = &H00400000???

'/*
' * Supports alpha surfaces
' */
%DDCAPS_ALPHA                    = &H00800000???

'/*
' * colorkey is hardware assisted(DDCAPS_COLORKEY will also be set)
' */
%DDCAPS_COLORKEYHWASSIST         = &H01000000???

'/*
' * no hardware support at all
' */
%DDCAPS_NOHARDWARE               = &H02000000???

'/*
' * Display hardware is capable of color fill with bltter
' */
%DDCAPS_BLTCOLORFILL             = &H04000000???

'/*
' * Display hardware is bank switched, and potentially very slow at
' * random access to VRAM.
' */
%DDCAPS_BANKSWITCHED             = &H08000000???

'/*
' * Display hardware is capable of depth filling Z-buffers with bltter
' */
%DDCAPS_BLTDEPTHFILL             = &H10000000???

'/*
' * Display hardware is capable of clipping while bltting.
' */
%DDCAPS_CANCLIP                  = &H20000000???

'/*
' * Display hardware is capable of clipping while stretch bltting.
' */
%DDCAPS_CANCLIPSTRETCHED         = &H40000000???

'/*
' * Display hardware is capable of bltting to or from system memory
' */
%DDCAPS_CANBLTSYSMEM             = &H80000000???


' /****************************************************************************
' *
' * MORE DIRECTDRAW DRIVER CAPABILITY FLAGS (dwCaps2)
' *
' ****************************************************************************/

'/*
' * Display hardware is certified
' */
%DDCAPS2_CERTIFIED              = &H00000001???

'/*
' * Driver cannot interleave 2D operations (lock and blt) to surfaces with
' * Direct3D rendering operations between calls to BeginScene() and EndScene()
' */
%DDCAPS2_NO2DDURING3DSCENE       = &H00000002???

'/*
' * Display hardware contains a video port
' */
%DDCAPS2_VIDEOPORT               = &H00000004???

'/*
' * The overlay can be automatically flipped according to the video port
' * VSYNCs, providing automatic doubled buffered display of video port
' * data using an overlay
' */
%DDCAPS2_AUTOFLIPOVERLAY         = &H00000008???

'/*
' * Overlay can display each field of interlaced data individually while
' * it is interleaved in memory without causing jittery artifacts.
' */
%DDCAPS2_CANBOBINTERLEAVED       = &H00000010???

'/*
' * Overlay can display each field of interlaced data individually while
' * it is not interleaved in memory without causing jittery artifacts.
' */
%DDCAPS2_CANBOBNONINTERLEAVED    = &H00000020???

'/*
' * The overlay surface contains color controls (brightness, sharpness, etc.)
' */
%DDCAPS2_COLORCONTROLOVERLAY     = &H00000040???

'/*
' * The primary surface contains color controls (gamma, etc.)
' */
%DDCAPS2_COLORCONTROLPRIMARY     = &H00000080???

'/*
' * RGBZ -> RGB supported for 16:16 RGB:Z
' */
%DDCAPS2_CANDROPZ16BIT           = &H00000100???

'/*
' * Driver supports non-local video memory.
' */
%DDCAPS2_NONLOCALVIDMEM          = &H00000200???

'/*
' * Dirver supports non-local video memory but has different capabilities for
' * non-local video memory surfaces. If this bit is set then so must
' * DDCAPS2_NONLOCALVIDMEM.
' */
%DDCAPS2_NONLOCALVIDMEMCAPS      = &H00000400???

'/*
' * Driver neither requires nor prefers surfaces to be pagelocked when performing
' * blts involving system memory surfaces
' */
%DDCAPS2_NOPAGELOCKREQUIRED      = &H00000800???

'/*
' * Driver can create surfaces which are wider than the primary surface
' */
%DDCAPS2_WIDESURFACES            = &H00001000???

'/*
' * Driver supports bob without using a video port by handling the
' * DDFLIP_ODD and DDFLIP_EVEN flags specified in Flip.
' */
%DDCAPS2_CANFLIPODDEVEN          = &H00002000???

'/*
' * Driver supports bob using hardware
' */
%DDCAPS2_CANBOBHARDWARE          = &H00004000???

'/*
' * Driver supports bltting any FOURCC surface to another surface of the same FOURCC
' */
%DDCAPS2_COPYFOURCC              = &H00008000???


'/*
' * Driver supports loadable gamma ramps for the primary surface
' */
%DDCAPS2_PRIMARYGAMMA            = &H00020000???

'/*
' * Driver can render in windowed mode.
' */
%DDCAPS2_CANRENDERWINDOWED       = &H00080000???

'/*
' * A calibrator is available to adjust the gamma ramp according to the
' * physical display properties so that the result will be identical on
' * all calibrated systems.
' */
%DDCAPS2_CANCALIBRATEGAMMA       = &H00100000???

'/*
' * Indicates that the driver will respond to DDFLIP_INTERVALn flags
' */
%DDCAPS2_FLIPINTERVAL            = &H00200000???

'/*
' * Indicates that the driver will respond to DDFLIP_NOVSYNC
' */
%DDCAPS2_FLIPNOVSYNC             = &H00400000???

'/*
' * Driver supports management of video memory, if this flag is ON,
' * driver manages the texture if requested with DDSCAPS2_TEXTUREMANAGE on
' * DirectX manages the texture if this flag is OFF and surface has DDSCAPS2_TEXTUREMANAGE on
' */
%DDCAPS2_CANMANAGETEXTURE        = &H00800000???

'/*
' * The Direct3D texture manager uses this cap to decide whether to put managed
' * surfaces in non-local video memory. If the cap is set, the texture manager will
' * put managed surfaces in non-local vidmem. Drivers that cannot texture from
' * local vidmem SHOULD NOT set this cap.
' */
%DDCAPS2_TEXMANINNONLOCALVIDMEM  = &H01000000???

'/*
' * Indicates that the driver supports DX7 type of stereo in at least one mode (which may
' * not necessarily be the current mode). Applications should use IDirectDraw7 (or higher)
' * ::EnumDisplayModes and check the DDSURFACEDESC.ddsCaps.dwCaps2 field for the presence of
' * DDSCAPS2_STEREOSURFACELEFT to check if a particular mode supports stereo. The application
' * can also use IDirectDraw7(or higher)::GetDisplayMode to check the current mode.
' */
%DDCAPS2_STEREO                  = &H02000000???

'/*
' * This caps bit is intended for internal DirectDraw use.
' * -It is only valid if DDCAPS2_NONLOCALVIDMEMCAPS is set.
' * -If this bit is set, then DDCAPS_CANBLTSYSMEM MUST be set by the driver (and
' *  all the assoicated system memory blt caps must be correct).
' * -It implies that the system->video blt caps in DDCAPS also apply to system to
' *  nonlocal blts. I.e. the dwSVBCaps, dwSVBCKeyCaps, dwSVBFXCaps and dwSVBRops
' *  members of DDCAPS (DDCORECAPS) are filled in correctly.
' * -Any blt from system to nonlocal memory that matches these caps bits will
' *  be passed to the driver.
' *
' * NOTE: This is intended to enable the driver itself to do efficient reordering
' * of textures. This is NOT meant to imply that hardware can write into AGP memory.
' * This operation is not currently supported.
' */
%DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL   = &H04000000???

'/*
' * was DDCAPS2_PUREHAL
' */
%DDCAPS2_RESERVED1                     = &H08000000???

'/*
' * Driver supports management of video memory, if this flag is ON,
' * driver manages the resource if requested with DDSCAPS2_TEXTUREMANAGE on
' * DirectX manages the resource if this flag is OFF and surface has DDSCAPS2_TEXTUREMANAGE on
' */
%DDCAPS2_CANMANAGERESOURCE             = &H10000000???

'/*
' * Driver supports dynamic textures. This will allow the application to set
' * D3DUSAGE_DYNAMIC (DDSCAPS2_HINTDYNAMIC for drivers) at texture create time.
' * Video memory dynamic textures WILL be lockable by applications. It is
' * expected that these locks will be very efficient (which implies that the
' * driver should always maintain a linear copy, a pointer to which can be
' * quickly handed out to the application).
' */
%DDCAPS2_DYNAMICTEXTURES               = &H20000000???

'/*
' * Driver supports auto-generation of mipmaps.
' */
%DDCAPS2_CANAUTOGENMIPMAP              = &H40000000???


'/****************************************************************************
' *
' * DIRECTDRAW FX ALPHA CAPABILITY FLAGS
' *
' ****************************************************************************/

'/*
' * Supports alpha blending around the edge of a source color keyed surface.
' * For Blt.
' */
%DDFXALPHACAPS_BLTALPHAEDGEBLEND         = &H00000001???

'/*
' * Supports alpha information in the pixel format.  The bit depth of alpha
' * information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
' * more opaque as the alpha value increases.  (0 is transparent.)
' * For Blt.
' */
%DDFXALPHACAPS_BLTALPHAPIXELS            = &H00000002???

'/*
' * Supports alpha information in the pixel format.  The bit depth of alpha
' * information in the pixel format can be 1,2,4, or 8.  The alpha value
' * becomes more transparent as the alpha value increases.  (0 is opaque.)
' * This flag can only be set if DDCAPS_ALPHA is set.
' * For Blt.
' */
%DDFXALPHACAPS_BLTALPHAPIXELSNEG         = &H00000004???

'/*
' * Supports alpha only surfaces.  The bit depth of an alpha only surface can be
' * 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
' * (0 is transparent.)
' * For Blt.
' */
%DDFXALPHACAPS_BLTALPHASURFACES          = &H00000008???

'/*
' * The depth of the alpha channel data can range can be 1,2,4, or 8.
' * The NEG suffix indicates that this alpha channel becomes more transparent
' * as the alpha value increases. (0 is opaque.)  This flag can only be set if
' * DDCAPS_ALPHA is set.
' * For Blt.
' */
%DDFXALPHACAPS_BLTALPHASURFACESNEG       = &H00000010???

'/*
' * Supports alpha blending around the edge of a source color keyed surface.
' * For Overlays.
' */
%DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND     = &H00000020???

'/*
' * Supports alpha information in the pixel format.  The bit depth of alpha
' * information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
' * more opaque as the alpha value increases.  (0 is transparent.)
' * For Overlays.
' */
%DDFXALPHACAPS_OVERLAYALPHAPIXELS        = &H00000040???

'/*
' * Supports alpha information in the pixel format.  The bit depth of alpha
' * information in the pixel format can be 1,2,4, or 8.  The alpha value
' * becomes more transparent as the alpha value increases.  (0 is opaque.)
' * This flag can only be set if DDCAPS_ALPHA is set.
' * For Overlays.
' */
%DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG     = &H00000080???

'/*
' * Supports alpha only surfaces.  The bit depth of an alpha only surface can be
' * 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
' * (0 is transparent.)
' * For Overlays.
' */
%DDFXALPHACAPS_OVERLAYALPHASURFACES      = &H00000100???

'/*
' * The depth of the alpha channel data can range can be 1,2,4, or 8.
' * The NEG suffix indicates that this alpha channel becomes more transparent
' * as the alpha value increases. (0 is opaque.)  This flag can only be set if
' * DDCAPS_ALPHA is set.
' * For Overlays.
' */
%DDFXALPHACAPS_OVERLAYALPHASURFACESNEG   = &H00000200???

'#if DIRECTDRAW_VERSION < = &H0600
'#endif  //DIRECTDRAW_VERSION


'/****************************************************************************
' *
' * DIRECTDRAW FX CAPABILITY FLAGS
' *
' ****************************************************************************/

'/*
' * Uses arithmetic operations to stretch and shrink surfaces during blt
' * rather than pixel doubling techniques.  Along the Y axis.
' */
%DDFXCAPS_BLTARITHSTRETCHY       = &H00000020???

'/*
' * Uses arithmetic operations to stretch during blt
' * rather than pixel doubling techniques.  Along the Y axis. Only
' * works for x1, x2, etc.
' */
%DDFXCAPS_BLTARITHSTRETCHYN      = &H00000010???

'/*
' * Supports mirroring left to right in blt.
' */
%DDFXCAPS_BLTMIRRORLEFTRIGHT     = &H00000040???

'/*
' * Supports mirroring top to bottom in blt.
' */
%DDFXCAPS_BLTMIRRORUPDOWN        = &H00000080???

'/*
' * Supports arbitrary rotation for blts.
' */
%DDFXCAPS_BLTROTATION            = &H00000100???

'/*
' * Supports 90 degree rotations for blts.
' */
%DDFXCAPS_BLTROTATION90          = &H00000200???

'/*
' * DirectDraw supports arbitrary shrinking of a surface along the
' * x axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSHRINKX             = &H00000400???

'/*
' * DirectDraw supports integer shrinking (1x,2x,) of a surface
' * along the x axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSHRINKXN            = &H00000800???

'/*
' * DirectDraw supports arbitrary shrinking of a surface along the
' * y axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSHRINKY             = &H00001000???

'/*
' * DirectDraw supports integer shrinking (1x,2x,) of a surface
' * along the y axis (vertical direction) for blts.
' */
%DDFXCAPS_BLTSHRINKYN            = &H00002000???

'/*
' * DirectDraw supports arbitrary stretching of a surface along the
' * x axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSTRETCHX            = &H00004000???

'/*
' * DirectDraw supports integer stretching (1x,2x,) of a surface
' * along the x axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSTRETCHXN           = &H00008000???

'/*
' * DirectDraw supports arbitrary stretching of a surface along the
' * y axis (horizontal direction) for blts.
' */
%DDFXCAPS_BLTSTRETCHY            = &H00010000???

'/*
' * DirectDraw supports integer stretching (1x,2x,) of a surface
' * along the y axis (vertical direction) for blts.
' */
%DDFXCAPS_BLTSTRETCHYN           = &H00020000???

'/*
' * Uses arithmetic operations to stretch and shrink surfaces during
' * overlay rather than pixel doubling techniques.  Along the Y axis
' * for overlays.
' */
%DDFXCAPS_OVERLAYARITHSTRETCHY   = &H00040000???

'/*
' * Uses arithmetic operations to stretch surfaces during
' * overlay rather than pixel doubling techniques.  Along the Y axis
' * for overlays. Only works for x1, x2, etc.
' */
%DDFXCAPS_OVERLAYARITHSTRETCHYN  = &H00000008???

'/*
' * DirectDraw supports arbitrary shrinking of a surface along the
' * x axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSHRINKX         = &H00080000???

'/*
' * DirectDraw supports integer shrinking (1x,2x,) of a surface
' * along the x axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSHRINKXN        = &H00100000???

'/*
' * DirectDraw supports arbitrary shrinking of a surface along the
' * y axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSHRINKY         = &H00200000???

'/*
' * DirectDraw supports integer shrinking (1x,2x,) of a surface
' * along the y axis (vertical direction) for overlays.
' */
%DDFXCAPS_OVERLAYSHRINKYN        = &H00400000???

'/*
' * DirectDraw supports arbitrary stretching of a surface along the
' * x axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSTRETCHX        = &H00800000???

'/*
' * DirectDraw supports integer stretching (1x,2x,) of a surface
' * along the x axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSTRETCHXN       = &H01000000???

'/*
' * DirectDraw supports arbitrary stretching of a surface along the
' * y axis (horizontal direction) for overlays.
' */
%DDFXCAPS_OVERLAYSTRETCHY        = &H02000000???

'/*
' * DirectDraw supports integer stretching (1x,2x,) of a surface
' * along the y axis (vertical direction) for overlays.
' */
%DDFXCAPS_OVERLAYSTRETCHYN       = &H04000000???

'/*
' * DirectDraw supports mirroring of overlays across the vertical axis
' */
%DDFXCAPS_OVERLAYMIRRORLEFTRIGHT = &H08000000???

'/*
' * DirectDraw supports mirroring of overlays across the horizontal axis
' */
%DDFXCAPS_OVERLAYMIRRORUPDOWN    = &H10000000???

'/*
' * DirectDraw supports deinterlacing of overlay surfaces
' */
%DDFXCAPS_OVERLAYDEINTERLACE      = &H20000000???

'/*
' * Driver can do alpha blending for blits.
' */
%DDFXCAPS_BLTALPHA               = &H00000001???


'/*
' * Driver can do surface-reconstruction filtering for warped blits.
' */
%DDFXCAPS_BLTFILTER              = %DDFXCAPS_BLTARITHSTRETCHY

'/*
' * Driver can do alpha blending for overlays.
' */
%DDFXCAPS_OVERLAYALPHA           = &H00000004???


'/*
' * Driver can do surface-reconstruction filtering for warped overlays.
' */
%DDFXCAPS_OVERLAYFILTER          = %DDFXCAPS_OVERLAYARITHSTRETCHY

'/****************************************************************************
' *
' * DIRECTDRAW STEREO VIEW CAPABILITIES
' *
' ****************************************************************************/

'/*
' * This flag used to be DDSVCAPS_ENIGMA, which is now obsolete
' */

%DDSVCAPS_RESERVED1              = &H00000001???

'/*
' * This flag used to be DDSVCAPS_FLICKER, which is now obsolete
' */
%DDSVCAPS_RESERVED2              = &H00000002???

'/*
' * This flag used to be DDSVCAPS_REDBLUE, which is now obsolete
' */
%DDSVCAPS_RESERVED3              = &H00000004???

'/*
' * This flag used to be DDSVCAPS_SPLIT, which is now obsolete
' */
%DDSVCAPS_RESERVED4              = &H00000008???

'/*
' * The stereo view is accomplished with switching technology
' */

%DDSVCAPS_STEREOSEQUENTIAL       = &H00000010???



'/****************************************************************************
' *
' * DIRECTDRAWPALETTE CAPABILITIES
' *
' ****************************************************************************/

'/*
' * Index is 4 bits.  There are sixteen color entries in the palette table.
' */
%DDPCAPS_4BIT                    = &H00000001???

'/*
' * Index is onto a 8 bit color index.  This field is only valid with the
' * DDPCAPS_1BIT, DDPCAPS_2BIT or DDPCAPS_4BIT capability and the target
' * surface is in 8bpp. Each color entry is one byte long and is an index
' * into destination surface's 8bpp palette.
' */
%DDPCAPS_8BITENTRIES             = &H00000002???

'/*
' * Index is 8 bits.  There are 256 color entries in the palette table.
' */
%DDPCAPS_8BIT                    = &H00000004???

'/*
' * Indicates that this DIRECTDRAWPALETTE should use the palette color array
' * passed into the lpDDColorArray parameter to initialize the DIRECTDRAWPALETTE
' * object.
' * This flag is obsolete. DirectDraw always initializes the color array from
' * the lpDDColorArray parameter. The definition remains for source-level
' * compatibility.
' */
%DDPCAPS_INITIALIZE              = &H00000000???

'/*
' * This palette is the one attached to the primary surface.  Changing this
' * table has immediate effect on the display unless DDPSETPAL_VSYNC is specified
' * and supported.
' */
%DDPCAPS_PRIMARYSURFACE          = &H00000010???

'/*
' * This palette is the one attached to the primary surface left.  Changing
' * this table has immediate effect on the display for the left eye unless
' * DDPSETPAL_VSYNC is specified and supported.
' */
%DDPCAPS_PRIMARYSURFACELEFT      = &H00000020???

'/*
' * This palette can have all 256 entries defined
' */
%DDPCAPS_ALLOW256                = &H00000040???

'/*
' * This palette can have modifications to it synced with the monitors
' * refresh rate.
' */
%DDPCAPS_VSYNC                   = &H00000080???

'/*
' * Index is 1 bit.  There are two color entries in the palette table.
' */
%DDPCAPS_1BIT                    = &H00000100???

'/*
' * Index is 2 bit.  There are four color entries in the palette table.
' */
%DDPCAPS_2BIT                    = &H00000200???

'/*
' * The peFlags member of PALETTEENTRY denotes an 8 bit alpha value
' */
%DDPCAPS_ALPHA                   = &H00000400???


'/****************************************************************************
' *
' * DIRECTDRAWPALETTE SETENTRY CONSTANTS
' *
' ****************************************************************************/


'/****************************************************************************
' *
' * DIRECTDRAWPALETTE GETENTRY CONSTANTS
' *
' ****************************************************************************/

'/* 0 is the only legal value */

'/****************************************************************************
' *
' * DIRECTDRAWSURFACE SETPRIVATEDATA CONSTANTS
' *
' ****************************************************************************/

'/*
' * The passed pointer is an IUnknown ptr. The cbData argument to SetPrivateData
' * must be set to sizeof(IUnknown*). DirectDraw will call AddRef through this
' * pointer and Release when the private data is destroyed. This includes when
' * the surface or palette is destroyed before such priovate data is destroyed.
' */
%DDSPD_IUNKNOWNPOINTER           = &H00000001???

'/*
' * Private data is only valid for the current state of the object,
' * as determined by the uniqueness value.
' */
%DDSPD_VOLATILE                  = &H00000002???


'/****************************************************************************
' *
' * DIRECTDRAWSURFACE SETPALETTE CONSTANTS
' *
' ****************************************************************************/


'/****************************************************************************
' *
' * DIRECTDRAW BITDEPTH CONSTANTS
' *
' * NOTE:  These are only used to indicate supported bit depths.   These
' * are flags only, they are not to be used as an actual bit depth.   The
' * absolute numbers 1, 2, 4, 8, 16, 24 and 32 are used to indicate actual
' * bit depths in a surface or for changing the display mode.
' *
' ****************************************************************************/

'/*
' * 1 bit per pixel.
' */
%DDBD_1                  = &H00004000???

'/*
' * 2 bits per pixel.
' */
%DDBD_2                  = &H00002000???

'/*
' * 4 bits per pixel.
' */
%DDBD_4                  = &H00001000???

'/*
' * 8 bits per pixel.
' */
%DDBD_8                  = &H00000800???

'/*
' * 16 bits per pixel.
' */
%DDBD_16                 = &H00000400???

'/*
' * 24 bits per pixel.
' */
%DDBD_24                 = &H00000200???

'/*
' * 32 bits per pixel.
' */
%DDBD_32                 = &H00000100???

'/****************************************************************************
' *
' * DIRECTDRAWSURFACE SET/GET COLOR KEY FLAGS
' *
' ****************************************************************************/

'/*
' * Set if the structure contains a color space.  Not set if the structure
' * contains a single color key.
' */
%DDCKEY_COLORSPACE       = &H00000001???

'/*
' * Set if the structure specifies a color key or color space which is to be
' * used as a destination color key for blt operations.
' */
%DDCKEY_DESTBLT          = &H00000002???

'/*
' * Set if the structure specifies a color key or color space which is to be
' * used as a destination color key for overlay operations.
' */
%DDCKEY_DESTOVERLAY      = &H00000004???

'/*
' * Set if the structure specifies a color key or color space which is to be
' * used as a source color key for blt operations.
' */
%DDCKEY_SRCBLT           = &H00000008???

'/*
' * Set if the structure specifies a color key or color space which is to be
' * used as a source color key for overlay operations.
' */
%DDCKEY_SRCOVERLAY       = &H00000010???


'/****************************************************************************
' *
' * DIRECTDRAW COLOR KEY CAPABILITY FLAGS
' *
' ****************************************************************************/

'/*
' * Supports transparent blting using a color key to identify the replaceable
' * bits of the destination surface for RGB colors.
' */
%DDCKEYCAPS_DESTBLT                      = &H00000001???

'/*
' * Supports transparent blting using a color space to identify the replaceable
' * bits of the destination surface for RGB colors.
' */
%DDCKEYCAPS_DESTBLTCLRSPACE              = &H00000002???

'/*
' * Supports transparent blting using a color space to identify the replaceable
' * bits of the destination surface for YUV colors.
' */
%DDCKEYCAPS_DESTBLTCLRSPACEYUV           = &H00000004???

'/*
' * Supports transparent blting using a color key to identify the replaceable
' * bits of the destination surface for YUV colors.
' */
%DDCKEYCAPS_DESTBLTYUV                   = &H00000008???

'/*
' * Supports overlaying using colorkeying of the replaceable bits of the surface
' * being overlayed for RGB colors.
' */
%DDCKEYCAPS_DESTOVERLAY                  = &H00000010???

'/*
' * Supports a color space as the color key for the destination for RGB colors.
' */
%DDCKEYCAPS_DESTOVERLAYCLRSPACE          = &H00000020???

'/*
' * Supports a color space as the color key for the destination for YUV colors.
' */
%DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV       = &H00000040???

'/*
' * Supports only one active destination color key value for visible overlay
' * surfaces.
' */
%DDCKEYCAPS_DESTOVERLAYONEACTIVE         = &H00000080???

'/*
' * Supports overlaying using colorkeying of the replaceable bits of the
' * surface being overlayed for YUV colors.
' */
%DDCKEYCAPS_DESTOVERLAYYUV               = &H00000100???

'/*
' * Supports transparent blting using the color key for the source with
' * this surface for RGB colors.
' */
%DDCKEYCAPS_SRCBLT                       = &H00000200???

'/*
' * Supports transparent blting using a color space for the source with
' * this surface for RGB colors.
' */
%DDCKEYCAPS_SRCBLTCLRSPACE               = &H00000400???

'/*
' * Supports transparent blting using a color space for the source with
' * this surface for YUV colors.
' */
%DDCKEYCAPS_SRCBLTCLRSPACEYUV            = &H00000800???

'/*
' * Supports transparent blting using the color key for the source with
' * this surface for YUV colors.
' */
%DDCKEYCAPS_SRCBLTYUV                    = &H00001000???

'/*
' * Supports overlays using the color key for the source with this
' * overlay surface for RGB colors.
' */
%DDCKEYCAPS_SRCOVERLAY                   = &H00002000???

'/*
' * Supports overlays using a color space as the source color key for
' * the overlay surface for RGB colors.
' */
%DDCKEYCAPS_SRCOVERLAYCLRSPACE           = &H00004000???

'/*
' * Supports overlays using a color space as the source color key for
' * the overlay surface for YUV colors.
' */
%DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV        = &H00008000???

'/*
' * Supports only one active source color key value for visible
' * overlay surfaces.
' */
%DDCKEYCAPS_SRCOVERLAYONEACTIVE          = &H00010000???

'/*
' * Supports overlays using the color key for the source with this
' * overlay surface for YUV colors.
' */
%DDCKEYCAPS_SRCOVERLAYYUV                = &H00020000???

'/*
' * there are no bandwidth trade-offs for using colorkey with an overlay
' */
%DDCKEYCAPS_NOCOSTOVERLAY                = &H00040000???


'/****************************************************************************
' *
' * DIRECTDRAW PIXELFORMAT FLAGS
' *
' ****************************************************************************/

'/*
' * The surface has alpha channel information in the pixel format.
' */
%DDPF_ALPHAPIXELS                        = &H00000001???

'/*
' * The pixel format contains alpha only information
' */
%DDPF_ALPHA                              = &H00000002???

'/*
' * The FourCC code is valid.
' */
%DDPF_FOURCC                             = &H00000004???

'/*
' * The surface is 4-bit color indexed.
' */
%DDPF_PALETTEINDEXED4                    = &H00000008???

'/*
' * The surface is indexed into a palette which stores indices
' * into the destination surface's 8-bit palette.
' */
%DDPF_PALETTEINDEXEDTO8                  = &H00000010???

'/*
' * The surface is 8-bit color indexed.
' */
%DDPF_PALETTEINDEXED8                    = &H00000020???

'/*
' * The RGB data in the pixel format structure is valid.
' */
%DDPF_RGB                                = &H00000040???

'/*
' * The surface will accept pixel data in the format specified
' * and compress it during the write.
' */
%DDPF_COMPRESSED                         = &H00000080???

'/*
' * The surface will accept RGB data and translate it during
' * the write to YUV data.  The format of the data to be written
' * will be contained in the pixel format structure.  The DDPF_RGB
' * flag will be set.
' */
%DDPF_RGBTOYUV                           = &H00000100???

'/*
' * pixel format is YUV - YUV data in pixel format struct is valid
' */
%DDPF_YUV                                = &H00000200???

'/*
' * pixel format is a z buffer only surface
' */
%DDPF_ZBUFFER                            = &H00000400???

'/*
' * The surface is 1-bit color indexed.
' */
%DDPF_PALETTEINDEXED1                    = &H00000800???

'/*
' * The surface is 2-bit color indexed.
' */
%DDPF_PALETTEINDEXED2                    = &H00001000???

'/*
' * The surface contains Z information in the pixels
' */
%DDPF_ZPIXELS                            = &H00002000???

'/*
' * The surface contains stencil information along with Z
' */
%DDPF_STENCILBUFFER                      = &H00004000???

'/*
' * Premultiplied alpha format -- the color components have been
' * premultiplied by the alpha component.
' */
%DDPF_ALPHAPREMULT                       = &H00008000???


'/*
' * Luminance data in the pixel format is valid.
' * Use this flag for luminance-only or luminance+alpha surfaces,
' * the bit depth is then ddpf.dwLuminanceBitCount.
' */
%DDPF_LUMINANCE                          = &H00020000???

'/*
' * Luminance data in the pixel format is valid.
' * Use this flag when hanging luminance off bumpmap surfaces,
' * the bit mask for the luminance portion of the pixel is then
' * ddpf.dwBumpLuminanceBitMask
' */
%DDPF_BUMPLUMINANCE                      = &H00040000???

'/*
' * Bump map dUdV data in the pixel format is valid.
' */
%DDPF_BUMPDUDV                           = &H00080000???


'/*===========================================================================
' *
' *
' * DIRECTDRAW CALLBACK FLAGS
' *
' *
' *==========================================================================*/

'/****************************************************************************
' *
' * DIRECTDRAW ENUMSURFACES FLAGS
' *
' ****************************************************************************/

'/*
' * Enumerate all of the surfaces that meet the search criterion.
' */
%DDENUMSURFACES_ALL                      = &H00000001???

'/*
' * A search hit is a surface that matches the surface description.
' */
%DDENUMSURFACES_MATCH                    = &H00000002???

'/*
' * A search hit is a surface that does not match the surface description.
' */
%DDENUMSURFACES_NOMATCH                  = &H00000004???

'/*
' * Enumerate the first surface that can be created which meets the search criterion.
' */
%DDENUMSURFACES_CANBECREATED             = &H00000008???

'/*
' * Enumerate the surfaces that already exist that meet the search criterion.
' */
%DDENUMSURFACES_DOESEXIST                = &H00000010???


'/****************************************************************************
' *
' * DIRECTDRAW SETDISPLAYMODE FLAGS
' *
' ****************************************************************************/

'/*
' * The desired mode is a standard VGA mode
' */
%DDSDM_STANDARDVGAMODE                   = &H00000001???


'/****************************************************************************
' *
' * DIRECTDRAW ENUMDISPLAYMODES FLAGS
' *
' ****************************************************************************/

'/*
' * Enumerate Modes with different refresh rates.  EnumDisplayModes guarantees
' * that a particular mode will be enumerated only once.  This flag specifies whether
' * the refresh rate is taken into account when determining if a mode is unique.
' */
%DDEDM_REFRESHRATES                      = &H00000001???

'/*
' * Enumerate VGA modes. Specify this flag if you wish to enumerate supported VGA
' * modes such as mode = &H13 in addition to the usual ModeX modes (which are always
' * enumerated if the application has previously called SetCooperativeLevel with the
' * DDSCL_ALLOWMODEX flag set).
' */
%DDEDM_STANDARDVGAMODES                  = &H00000002???


'/****************************************************************************
' *
' * DIRECTDRAW SETCOOPERATIVELEVEL FLAGS
' *
' ****************************************************************************/

'/*
' * Exclusive mode owner will be responsible for the entire primary surface.
' * GDI can be ignored. used with DD
' */
%DDSCL_FULLSCREEN                        = &H00000001???

'/*
' * allow CTRL_ALT_DEL to work while in fullscreen exclusive mode
' */
%DDSCL_ALLOWREBOOT                       = &H00000002???

'/*
' * prevents DDRAW from modifying the application window.
' * prevents DDRAW from minimize/restore the application window on activation.
' */
%DDSCL_NOWINDOWCHANGES                   = &H00000004???

'/*
' * app wants to work as a regular Windows application
' */
%DDSCL_NORMAL                            = &H00000008???

'/*
' * app wants exclusive access
' */
%DDSCL_EXCLUSIVE                         = &H00000010???


'/*
' * app can deal with non-windows display modes
' */
%DDSCL_ALLOWMODEX                        = &H00000040???

'/*
' * this window will receive the focus messages
' */
%DDSCL_SETFOCUSWINDOW                    = &H00000080???

'/*
' * this window is associated with the DDRAW object and will
' * cover the screen in fullscreen mode
' */
%DDSCL_SETDEVICEWINDOW                   = &H00000100???

'/*
' * app wants DDRAW to create a window to be associated with the
' * DDRAW object
' */
%DDSCL_CREATEDEVICEWINDOW                = &H00000200???

'/*
' * App explicitly asks DDRAW/D3D to be multithread safe. This makes D3D
' * take the global crtisec more frequently.
' */
%DDSCL_MULTITHREADED                     = &H00000400???

'/*
' * App specifies that it would like to keep the FPU set up for optimal Direct3D
' * performance (single precision and exceptions disabled) so Direct3D
' * does not need to explicitly set the FPU each time. This is assumed by
' * default in DirectX 7. See also DDSCL_FPUPRESERVE
' */
%DDSCL_FPUSETUP                          = &H00000800???

'/*
' * App specifies that it needs either double precision FPU or FPU exceptions
' * enabled. This makes Direct3D explicitly set the FPU state eah time it is
' * called. Setting the flag will reduce Direct3D performance. The flag is
' * assumed by default in DirectX 6 and earlier. See also DDSCL_FPUSETUP
' */
%DDSCL_FPUPRESERVE                       = &H00001000???


'/****************************************************************************
' *
' * DIRECTDRAW BLT FLAGS
' *
' ****************************************************************************/

'/*
' * Use the alpha information in the pixel format or the alpha channel surface
' * attached to the destination surface as the alpha channel for this blt.
' */
%DDBLT_ALPHADEST                         = &H00000001???

'/*
' * Use the dwConstAlphaDest field in the DDBLTFX structure as the alpha channel
' * for the destination surface for this blt.
' */
%DDBLT_ALPHADESTCONSTOVERRIDE            = &H00000002???

'/*
' * The NEG suffix indicates that the destination surface becomes more
' * transparent as the alpha value increases. (0 is opaque)
' */
%DDBLT_ALPHADESTNEG                      = &H00000004???

'/*
' * Use the lpDDSAlphaDest field in the DDBLTFX structure as the alpha
' * channel for the destination for this blt.
' */
%DDBLT_ALPHADESTSURFACEOVERRIDE          = &H00000008???

'/*
' * Use the dwAlphaEdgeBlend field in the DDBLTFX structure as the alpha channel
' * for the edges of the image that border the color key colors.
' */
%DDBLT_ALPHAEDGEBLEND                    = &H00000010???

'/*
' * Use the alpha information in the pixel format or the alpha channel surface
' * attached to the source surface as the alpha channel for this blt.
' */
%DDBLT_ALPHASRC                          = &H00000020???

'/*
' * Use the dwConstAlphaSrc field in the DDBLTFX structure as the alpha channel
' * for the source for this blt.
' */
%DDBLT_ALPHASRCCONSTOVERRIDE             = &H00000040???

'/*
' * The NEG suffix indicates that the source surface becomes more transparent
' * as the alpha value increases. (0 is opaque)
' */
%DDBLT_ALPHASRCNEG                       = &H00000080???

'/*
' * Use the lpDDSAlphaSrc field in the DDBLTFX structure as the alpha channel
' * for the source for this blt.
' */
%DDBLT_ALPHASRCSURFACEOVERRIDE           = &H00000100???

'/*
' * Do this blt asynchronously through the FIFO in the order received.  If
' * there is no room in the hardware FIFO fail the call.
' */
%DDBLT_ASYNC                             = &H00000200???

'/*
' * Uses the dwFillColor field in the DDBLTFX structure as the RGB color
' * to fill the destination rectangle on the destination surface with.
' */
%DDBLT_COLORFILL                         = &H00000400???

'/*
' * Uses the dwDDFX field in the DDBLTFX structure to specify the effects
' * to use for the blt.
' */
%DDBLT_DDFX                              = &H00000800???

'/*
' * Uses the dwDDROPS field in the DDBLTFX structure to specify the ROPS
' * that are not part of the Win32 API.
' */
%DDBLT_DDROPS                            = &H00001000???

'/*
' * Use the color key associated with the destination surface.
' */
%DDBLT_KEYDEST                           = &H00002000???

'/*
' * Use the dckDestColorkey field in the DDBLTFX structure as the color key
' * for the destination surface.
' */
%DDBLT_KEYDESTOVERRIDE                   = &H00004000???

'/*
' * Use the color key associated with the source surface.
' */
%DDBLT_KEYSRC                            = &H00008000???

'/*
' * Use the dckSrcColorkey field in the DDBLTFX structure as the color key
' * for the source surface.
' */
%DDBLT_KEYSRCOVERRIDE                    = &H00010000???

'/*
' * Use the dwROP field in the DDBLTFX structure for the raster operation
' * for this blt.  These ROPs are the same as the ones defined in the Win32 API.
' */
%DDBLT_ROP                               = &H00020000???

'/*
' * Use the dwRotationAngle field in the DDBLTFX structure as the angle
' * (specified in 1/100th of a degree) to rotate the surface.
' */
%DDBLT_ROTATIONANGLE                     = &H00040000???

'/*
' * Z-buffered blt using the z-buffers attached to the source and destination
' * surfaces and the dwZBufferOpCode field in the DDBLTFX structure as the
' * z-buffer opcode.
' */
%DDBLT_ZBUFFER                           = &H00080000???

'/*
' * Z-buffered blt using the dwConstDest Zfield and the dwZBufferOpCode field
' * in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
' * for the destination.
' */
%DDBLT_ZBUFFERDESTCONSTOVERRIDE          = &H00100000???

'/*
' * Z-buffered blt using the lpDDSDestZBuffer field and the dwZBufferOpCode
' * field in the DDBLTFX structure as the z-buffer and z-buffer opcode
' * respectively for the destination.
' */
%DDBLT_ZBUFFERDESTOVERRIDE               = &H00200000???

'/*
' * Z-buffered blt using the dwConstSrcZ field and the dwZBufferOpCode field
' * in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
' * for the source.
' */
%DDBLT_ZBUFFERSRCCONSTOVERRIDE           = &H00400000???

'/*
' * Z-buffered blt using the lpDDSSrcZBuffer field and the dwZBufferOpCode
' * field in the DDBLTFX structure as the z-buffer and z-buffer opcode
' * respectively for the source.
' */
%DDBLT_ZBUFFERSRCOVERRIDE                = &H00800000???

'/*
' * wait until the device is ready to handle the blt
' * this will cause blt to not return DDERR_WASSTILLDRAWING
' */
%DDBLT_WAIT                              = &H01000000???

'/*
' * Uses the dwFillDepth field in the DDBLTFX structure as the depth value
' * to fill the destination rectangle on the destination Z-buffer surface
' * with.
' */
%DDBLT_DEPTHFILL                         = &H02000000???


'/*
' * Return immediately (with DDERR_WASSTILLDRAWING) if the device is not
' * ready to schedule the blt at the time Blt() is called.
' */
%DDBLT_DONOTWAIT                         = &H08000000???

'/*
' * These flags indicate a presentation blt (i.e. a blt
' * that moves surface contents from an offscreen back buffer to the primary
' * surface). The driver is not allowed to "queue"  more than three such blts.
' * The "end" of the presentation blt is indicated, since the
' * blt may be clipped, in which case the runtime will call the driver with
' * several blts. All blts (even if not clipped) are tagged with DDBLT_PRESENTATION
' * and the last (even if not clipped) additionally with DDBLT_LAST_PRESENTATION.
' * Thus the true rule is that the driver must not schedule a DDBLT_PRESENTATION
' * blt if there are 3 or more DDBLT_PRESENTLAST blts in the hardware pipe.
' * If there are such blts in the pipe, the driver should return DDERR_WASSTILLDRAWING
' * until the oldest queued DDBLT_LAST_PRESENTATION blts has been retired (i.e. the
' * pixels have been actually written to the primary surface). Once the oldest blt
' * has been retired, the driver is free to schedule the current blt.
' * The goal is to provide a mechanism whereby the device's hardware queue never
' * gets more than 3 frames ahead of the frames being generated by the application.
' * When excessive queueing occurs, applications become unusable because the application
' * visibly lags user input, and such problems make windowed interactive applications impossible.
' * Some drivers may not have sufficient knowledge of their hardware's FIFO to know
' * when a certain blt has been retired. Such drivers should code cautiously, and
' * simply not allow any frames to be queued at all. DDBLT_LAST_PRESENTATION should cause
' * such drivers to return DDERR_WASSTILLDRAWING until the accelerator is completely
' * finished- exactly as if the application had called Lock on the source surface
' * before calling Blt.
' * In other words, the driver is allowed and encouraged to
' * generate as much latency as it can, but never more than 3 frames worth.
' * Implementation detail: Drivers should count blts against the SOURCE surface, not
' * against the primary surface. This enables multiple parallel windowed application
' * to function more optimally.
' * This flag is passed only to DX8 or higher drivers.
' *
' * APPLICATIONS DO NOT SET THESE FLAGS. THEY ARE SET BY THE DIRECTDRAW RUNTIME.
' *
' */
%DDBLT_PRESENTATION                      = &H10000000???
%DDBLT_LAST_PRESENTATION                 = &H20000000???

'/*
' * If DDBLT_EXTENDED_FLAGS is set, then the driver should re-interpret
' * other flags according to the definitions that follow.
' * For example, bit 0 (= &H00000001L) means DDBLT_ALPHADEST, unless
' * DDBLT_EXTENDED_FLAGS is also set, in which case bit 0 means
' * DDBLT_EXTENDED_LINEAR_CONTENT.
' * Only DirectX9 and higher drivers will be given extended blt flags.
' * Only flags explicitly mentioned here should be re-interpreted.
' * All other flags retain their original meanings.
' *
' * List of re-interpreted flags:
' *
' * Bit Hex value   New meaning                                  old meaning
' * ---------------------------------------------------------------
' *  2  = &H00000004  DDBLT_EXTENDED_LINEAR_CONTENT                DDBLT_ALPHADESTNEG
' *  4  = &H00000010  DDBLT_EXTENDED_PRESENTATION_STRETCHFACTOR    DDBLT_ALPHAEDGEBLEND
' *
' *
' * NOTE: APPLICATIONS SHOULD NOT SET THIS FLAG. THIS FLAG IS INTENDED
' * FOR USE BY THE DIRECT3D RUNTIME.
' */
%DDBLT_EXTENDED_FLAGS                    = &H40000000???

'/*
' * EXTENDED FLAG. SEE DEFINITION OF DDBLT_EXTENDED_FLAGS.
' * This flag indidcates that the source surface contains content in a
' * linear color space. The driver may perform gamma correction to the
' * desktop color space (i.e. sRGB, gamma 2.2) as part of this blt.
' * If the device can perform such a conversion as part of the copy,
' * the driver should also set D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION
' *
' * NOTE: APPLICATIONS SHOULD NOT SET THIS FLAG. THIS FLAG IS INTENDED
' * FOR USE BY THE DIRECT3D RUNTIME. Use IDirect3DSwapChain9::Present
' * and specify D3DPRESENT_LINEAR_CONTENT in order to use this functionality.
' */
%DDBLT_EXTENDED_LINEAR_CONTENT           = &H00000004???


'/****************************************************************************
' *
' * BLTFAST FLAGS
' *
' ****************************************************************************/

%DDBLTFAST_NOCOLORKEY                    = &H00000000
%DDBLTFAST_SRCCOLORKEY                   = &H00000001
%DDBLTFAST_DESTCOLORKEY                  = &H00000002
%DDBLTFAST_WAIT                          = &H00000010
%DDBLTFAST_DONOTWAIT                     = &H00000020

'/****************************************************************************
' *
' * FLIP FLAGS
' *
' ****************************************************************************/

%DDFLIP_WAIT                          = &H00000001???

'/*
' * Indicates that the target surface contains the even field of video data.
' * This flag is only valid with an overlay surface.
' */
%DDFLIP_EVEN                          = &H00000002???

'/*
' * Indicates that the target surface contains the odd field of video data.
' * This flag is only valid with an overlay surface.
' */
%DDFLIP_ODD                           = &H00000004???

'/*
' * Causes DirectDraw to perform the physical flip immediately and return
' * to the application. Typically, what was the front buffer but is now the back
' * buffer will still be visible (depending on timing) until the next vertical
' * retrace. Subsequent operations involving the two flipped surfaces will
' * not check to see if the physical flip has finished (i.e. will not return
' * DDERR_WASSTILLDRAWING for that reason (but may for other reasons)).
' * This allows an application to perform Flips at a higher frequency than the
' * monitor refresh rate, but may introduce visible artifacts.
' * Only effective if DDCAPS2_FLIPNOVSYNC is set. If that bit is not set,
' * DDFLIP_NOVSYNC has no effect.
' */
%DDFLIP_NOVSYNC                       = &H00000008???


'/*
' * Flip Interval Flags. These flags indicate how many vertical retraces to wait between
' * each flip. The default is one. DirectDraw will return DDERR_WASSTILLDRAWING for each
' * surface involved in the flip until the specified number of vertical retraces has
' * ocurred. Only effective if DDCAPS2_FLIPINTERVAL is set. If that bit is not set,
' * DDFLIP_INTERVALn has no effect.
' */

'/*
' * DirectDraw will flip on every other vertical sync
' */
%DDFLIP_INTERVAL2                     = &H02000000???


'/*
' * DirectDraw will flip on every third vertical sync
' */
%DDFLIP_INTERVAL3                     = &H03000000???


'/*
' * DirectDraw will flip on every fourth vertical sync
' */
%DDFLIP_INTERVAL4                     = &H04000000???

'/*
' * DirectDraw will flip and display a main stereo surface
' */
%DDFLIP_STEREO                        = &H00000010???

'/*
' * On IDirectDrawSurface7 and higher interfaces, the default is DDFLIP_WAIT. If you wish
' * to override the default and use time when the accelerator is busy (as denoted by
' * the DDERR_WASSTILLDRAWING return code) then use DDFLIP_DONOTWAIT.
' */
%DDFLIP_DONOTWAIT                     = &H00000020???


'/****************************************************************************
' *
' * DIRECTDRAW SURFACE OVERLAY FLAGS
' *
' ****************************************************************************/

'/*
' * Use the alpha information in the pixel format or the alpha channel surface
' * attached to the destination surface as the alpha channel for the
' * destination overlay.
' */
%DDOVER_ALPHADEST                        = &H00000001???

'/*
' * Use the dwConstAlphaDest field in the DDOVERLAYFX structure as the
' * destination alpha channel for this overlay.
' */
%DDOVER_ALPHADESTCONSTOVERRIDE           = &H00000002???

'/*
' * The NEG suffix indicates that the destination surface becomes more
' * transparent as the alpha value increases.
' */
%DDOVER_ALPHADESTNEG                     = &H00000004???

'/*
' * Use the lpDDSAlphaDest field in the DDOVERLAYFX structure as the alpha
' * channel destination for this overlay.
' */
%DDOVER_ALPHADESTSURFACEOVERRIDE         = &H00000008???

'/*
' * Use the dwAlphaEdgeBlend field in the DDOVERLAYFX structure as the alpha
' * channel for the edges of the image that border the color key colors.
' */
%DDOVER_ALPHAEDGEBLEND                   = &H00000010???

'/*
' * Use the alpha information in the pixel format or the alpha channel surface
' * attached to the source surface as the source alpha channel for this overlay.
' */
%DDOVER_ALPHASRC                         = &H00000020???

'/*
' * Use the dwConstAlphaSrc field in the DDOVERLAYFX structure as the source
' * alpha channel for this overlay.
' */
%DDOVER_ALPHASRCCONSTOVERRIDE            = &H00000040???

'/*
' * The NEG suffix indicates that the source surface becomes more transparent
' * as the alpha value increases.
' */
%DDOVER_ALPHASRCNEG                      = &H00000080???

'/*
' * Use the lpDDSAlphaSrc field in the DDOVERLAYFX structure as the alpha channel
' * source for this overlay.
' */
%DDOVER_ALPHASRCSURFACEOVERRIDE          = &H00000100???

'/*
' * Turn this overlay off.
' */
%DDOVER_HIDE                             = &H00000200???

'/*
' * Use the color key associated with the destination surface.
' */
%DDOVER_KEYDEST                          = &H00000400???

'/*
' * Use the dckDestColorkey field in the DDOVERLAYFX structure as the color key
' * for the destination surface
' */
%DDOVER_KEYDESTOVERRIDE                  = &H00000800???

'/*
' * Use the color key associated with the source surface.
' */
%DDOVER_KEYSRC                           = &H00001000???

'/*
' * Use the dckSrcColorkey field in the DDOVERLAYFX structure as the color key
' * for the source surface.
' */
%DDOVER_KEYSRCOVERRIDE                   = &H00002000???

'/*
' * Turn this overlay on.
' */
%DDOVER_SHOW                             = &H00004000???

'/*
' * Add a dirty rect to an emulated overlayed surface.
' */
%DDOVER_ADDDIRTYRECT                     = &H00008000???

'/*
' * Redraw all dirty rects on an emulated overlayed surface.
' */
%DDOVER_REFRESHDIRTYRECTS                = &H00010000???

'/*
' * Redraw the entire surface on an emulated overlayed surface.
' */
%DDOVER_REFRESHALL                       = &H00020000???


'/*
' * Use the overlay FX flags to define special overlay FX
' */
%DDOVER_DDFX                             = &H00080000???

'/*
' * Autoflip the overlay when ever the video port autoflips
' */
%DDOVER_AUTOFLIP                         = &H00100000???

'/*
' * Display each field of video port data individually without
' * causing any jittery artifacts
' */
%DDOVER_BOB                              = &H00200000???

'/*
' * Indicates that bob/weave decisions should not be overridden by other
' * interfaces.
' */
%DDOVER_OVERRIDEBOBWEAVE                 = &H00400000???

'/*
' * Indicates that the surface memory is composed of interleaved fields.
' */
%DDOVER_INTERLEAVED                      = &H00800000???

'/*
' * Indicates that bob will be performed using hardware rather than
' * software or emulated.
' */
%DDOVER_BOBHARDWARE                      = &H01000000???

'/*
' * Indicates that overlay FX structure contains valid ARGB scaling factors.
' */
%DDOVER_ARGBSCALEFACTORS                 = &H02000000???

'/*
' * Indicates that ARGB scaling factors can be degraded to fit driver capabilities.
' */
%DDOVER_DEGRADEARGBSCALING               = &H04000000???


'/****************************************************************************
' *
' * DIRECTDRAWSURFACE LOCK FLAGS
' *
' ****************************************************************************/

'/*
' * The default.  Set to indicate that Lock should return a valid memory pointer
' * to the top of the specified rectangle.  If no rectangle is specified then a
' * pointer to the top of the surface is returned.
' */
%DDLOCK_SURFACEMEMORYPTR                 = &H00000000???    ' // default

'/*
' * Set to indicate that Lock should wait until it can obtain a valid memory
' * pointer before returning.  If this bit is set, Lock will never return
' * DDERR_WASSTILLDRAWING.
' */
%DDLOCK_WAIT                             = &H00000001???

'/*
' * Set if an event handle is being passed to Lock.  Lock will trigger the event
' * when it can return the surface memory pointer requested.
' */
%DDLOCK_EVENT                            = &H00000002???

'/*
' * Indicates that the surface being locked will only be read from.
' */
%DDLOCK_READONLY                         = &H00000010???

'/*
' * Indicates that the surface being locked will only be written to
' */
%DDLOCK_WRITEONLY                        = &H00000020???


'/*
' * Indicates that a system wide lock should not be taken when this surface
' * is locked. This has several advantages (cursor responsiveness, ability
' * to call more Windows functions, easier debugging) when locking video
' * memory surfaces. However, an application specifying this flag must
' * comply with a number of conditions documented in the help file.
' * Furthermore, this flag cannot be specified when locking the primary.
' */
%DDLOCK_NOSYSLOCK                        = &H00000800???

'/*
' * Used only with Direct3D Vertex Buffer Locks. Indicates that no vertices
' * that were referred to in Draw*PrimtiveVB calls since the start of the
' * frame (or the last lock without this flag) will be modified during the
' * lock. This can be useful when one is only appending data to the vertex
' * buffer
' */
%DDLOCK_NOOVERWRITE                      = &H00001000???

'/*
' * Indicates that no assumptions will be made about the contents of the
' * surface or vertex buffer during this lock.
' * This enables two things:
' * -    Direct3D or the driver may provide an alternative memory
' *      area as the vertex buffer. This is useful when one plans to clear the
' *      contents of the vertex buffer and fill in new data.
' * -    Drivers sometimes store surface data in a re-ordered format.
' *      When the application locks the surface, the driver is forced to un-re-order
' *      the surface data before allowing the application to see the surface contents.
' *      This flag is a hint to the driver that it can skip the un-re-ordering process
' *      since the application plans to overwrite every single pixel in the surface
' *      or locked rectangle (and so erase any un-re-ordered pixels anyway).
' *      Applications should always set this flag when they intend to overwrite the entire
' *      surface or locked rectangle.
' */
%DDLOCK_DISCARDCONTENTS                  = &H00002000???

' /*
'  * DDLOCK_OKTOSWAP is an older, less informative name for DDLOCK_DISCARDCONTENTS
'  */
%DDLOCK_OKTOSWAP                         = &H00002000???

'/*
' * On IDirectDrawSurface7 and higher interfaces, the default is DDLOCK_WAIT. If you wish
' * to override the default and use time when the accelerator is busy (as denoted by
' * the DDERR_WASSTILLDRAWING return code) then use DDLOCK_DONOTWAIT.
' */
%DDLOCK_DONOTWAIT                        = &H00004000???

'/*
' * This indicates volume texture lock with front and back specified.
' */
%DDLOCK_HASVOLUMETEXTUREBOXRECT          = &H00008000???

'/*
' * This indicates that the driver should not update dirty rect information for this lock.
' */
%DDLOCK_NODIRTYUPDATE                    = &H00010000???


'/****************************************************************************
' *
' * DIRECTDRAWSURFACE PAGELOCK FLAGS
' *
' ****************************************************************************/

'/*
' * No flags defined at present
' */


'/****************************************************************************
' *
' * DIRECTDRAWSURFACE PAGEUNLOCK FLAGS
' *
' ****************************************************************************/

'/*
' * No flags defined at present
' */


'/****************************************************************************
' *
' * DIRECTDRAWSURFACE BLT FX FLAGS
' *
' ****************************************************************************/

'/*
' * If stretching, use arithmetic stretching along the Y axis for this blt.
' */
%DDBLTFX_ARITHSTRETCHY                   = &H00000001???

'/*
' * Do this blt mirroring the surface left to right.  Spin the
' * surface around its y-axis.
' */
%DDBLTFX_MIRRORLEFTRIGHT                 = &H00000002???

'/*
' * Do this blt mirroring the surface up and down.  Spin the surface
' * around its x-axis.
' */
%DDBLTFX_MIRRORUPDOWN                    = &H00000004???

'/*
' * Schedule this blt to avoid tearing.
' */
%DDBLTFX_NOTEARING                       = &H00000008???

'/*
' * Do this blt rotating the surface one hundred and eighty degrees.
' */
%DDBLTFX_ROTATE180                       = &H00000010???

'/*
' * Do this blt rotating the surface two hundred and seventy degrees.
' */
%DDBLTFX_ROTATE270                       = &H00000020???

'/*
' * Do this blt rotating the surface ninety degrees.
' */
%DDBLTFX_ROTATE90                        = &H00000040???

'/*
' * Do this z blt using dwZBufferLow and dwZBufferHigh as  range values
' * specified to limit the bits copied from the source surface.
' */
%DDBLTFX_ZBUFFERRANGE                    = &H00000080???

'/*
' * Do this z blt adding the dwZBufferBaseDest to each of the sources z values
' * before comparing it with the desting z values.
' */
%DDBLTFX_ZBUFFERBASEDEST                 = &H00000100???

'/****************************************************************************
' *
' * DIRECTDRAWSURFACE OVERLAY FX FLAGS
' *
' ****************************************************************************/

'/*
' * If stretching, use arithmetic stretching along the Y axis for this overlay.
' */
%DDOVERFX_ARITHSTRETCHY                  = &H00000001???

'/*
' * Mirror the overlay across the vertical axis
' */
%DDOVERFX_MIRRORLEFTRIGHT                = &H00000002???

'/*
' * Mirror the overlay across the horizontal axis
' */
%DDOVERFX_MIRRORUPDOWN                   = &H00000004???

'/*
' * Deinterlace the overlay, if possible
' */
%DDOVERFX_DEINTERLACE                    = &H00000008???


'/****************************************************************************
' *
' * DIRECTDRAW WAITFORVERTICALBLANK FLAGS
' *
' ****************************************************************************/

'/*
' * return when the vertical blank interval begins
' */
%DDWAITVB_BLOCKBEGIN                     = &H00000001???

'/*
' * set up an event to trigger when the vertical blank begins
' */
%DDWAITVB_BLOCKBEGINEVENT                = &H00000002???

'/*
' * return when the vertical blank interval ends and display begins
' */
%DDWAITVB_BLOCKEND                       = &H00000004???

'/****************************************************************************
' *
' * DIRECTDRAW GETFLIPSTATUS FLAGS
' *
' ****************************************************************************/

'/*
' * is it OK to flip now?
' */
%DDGFS_CANFLIP                   = &H00000001???

'/*
' * is the last flip finished?
' */
%DDGFS_ISFLIPDONE                = &H00000002???

'/****************************************************************************
' *
' * DIRECTDRAW GETBLTSTATUS FLAGS
' *
' ****************************************************************************/

'/*
' * is it OK to blt now?
' */
%DDGBS_CANBLT                    = &H00000001???

'/*
' * is the blt to the surface finished?
' */
%DDGBS_ISBLTDONE                 = &H00000002???


'/****************************************************************************
' *
' * DIRECTDRAW ENUMOVERLAYZORDER FLAGS
' *
' ****************************************************************************/

'/*
' * Enumerate overlays back to front.
' */
%DDENUMOVERLAYZ_BACKTOFRONT      = &H00000000???

'/*
' * Enumerate overlays front to back
' */
%DDENUMOVERLAYZ_FRONTTOBACK      = &H00000001???

'/****************************************************************************
' *
' * DIRECTDRAW UPDATEOVERLAYZORDER FLAGS
' *
' ****************************************************************************/

'/*
' * Send overlay to front
' */
%DDOVERZ_SENDTOFRONT             = &H00000000???

'/*
' * Send overlay to back
' */
%DDOVERZ_SENDTOBACK              = &H00000001???

'/*
' * Move Overlay forward
' */
%DDOVERZ_MOVEFORWARD             = &H00000002???

'/*
' * Move Overlay backward
' */
%DDOVERZ_MOVEBACKWARD            = &H00000003???

'/*
' * Move Overlay in front of relative surface
' */
%DDOVERZ_INSERTINFRONTOF         = &H00000004???

'/*
' * Move Overlay in back of relative surface
' */
%DDOVERZ_INSERTINBACKOF          = &H00000005???


'/****************************************************************************
' *
' * DIRECTDRAW SETGAMMARAMP FLAGS
' *
' ****************************************************************************/

'/*
' * Request calibrator to adjust the gamma ramp according to the physical
' * properties of the display so that the result should appear identical
' * on all systems.
' */
%DDSGR_CALIBRATE                        = &H00000001???


'/****************************************************************************
' *
' * DIRECTDRAW STARTMODETEST FLAGS
' *
' ****************************************************************************/

'/*
' * Indicates that the mode being tested has passed
' */
%DDSMT_ISTESTREQUIRED                   = &H00000001???


'/****************************************************************************
' *
' * DIRECTDRAW EVALUATEMODE FLAGS
' *
' ****************************************************************************/

'/*
' * Indicates that the mode being tested has passed
' */
%DDEM_MODEPASSED                        = &H00000001???

'/*
' * Indicates that the mode being tested has failed
' */
%DDEM_MODEFAILED                        = &H00000002???


'/*===========================================================================
' *
' *
' * DIRECTDRAW RETURN CODES
' *
' * The return values from DirectDraw Commands and Surface that return an HRESULT
' * are codes from DirectDraw concerning the results of the action
' * requested by DirectDraw.
' *
' *==========================================================================*/

'/*
' * Status is OK
' *
' * Issued by: DirectDraw Commands and all callbacks
' */
%DD_OK                                  = %S_OK
%DD_FALSE                               = %S_FALSE

'/****************************************************************************
' *
' * DIRECTDRAW ENUMCALLBACK RETURN VALUES
' *
' * EnumCallback returns are used to control the flow of the DIRECTDRAW and
' * DIRECTDRAWSURFACE object enumerations.   They can only be returned by
' * enumeration callback routines.
' *
' ****************************************************************************/

'/*
' * stop the enumeration
' */
%DDENUMRET_CANCEL                       = 0

'/*
' * continue the enumeration
' */
%DDENUMRET_OK                           = 1

'/****************************************************************************
' *
' * DIRECTDRAW ERRORS
' *
' * Errors are represented by negative values and cannot be combined.
' *
' ****************************************************************************/

'/*
' * This object is already initialized
' */
%DDERR_ALREADYINITIALIZED               = %MAKE_DDHRESULT + &H5

'/*
' * This surface can not be attached to the requested surface.
' */
%DDERR_CANNOTATTACHSURFACE              = %MAKE_DDHRESULT + &H10

'/*
' * This surface can not be detached from the requested surface.
' */
%DDERR_CANNOTDETACHSURFACE              = %MAKE_DDHRESULT + &H20

'/*
' * Support is currently not available.
' */
%DDERR_CURRENTLYNOTAVAIL                = %MAKE_DDHRESULT + &H40

'/*
' * An exception was encountered while performing the requested operation
' */
%DDERR_EXCEPTION                        = %MAKE_DDHRESULT + &H55

'/*
' * Generic failure.
' */
%DDERR_GENERIC                          = %E_FAIL

'/*
' * Height of rectangle provided is not a multiple of reqd alignment
' */
%DDERR_HEIGHTALIGN                      = %MAKE_DDHRESULT + &H90

'/*
' * Unable to match primary surface creation request with existing
' * primary surface.
' */
%DDERR_INCOMPATIBLEPRIMARY              = %MAKE_DDHRESULT + &H95

'/*
' * One or more of the caps bits passed to the callback are incorrect.
' */
%DDERR_INVALIDCAPS                      = %MAKE_DDHRESULT + &H100

'/*
' * DirectDraw does not support provided Cliplist.
' */
%DDERR_INVALIDCLIPLIST                  = %MAKE_DDHRESULT + &H110

'/*
' * DirectDraw does not support the requested mode
' */
%DDERR_INVALIDMODE                      = %MAKE_DDHRESULT + &H120

'/*
' * DirectDraw received a pointer that was an invalid DIRECTDRAW object.
' */
%DDERR_INVALIDOBJECT                    = %MAKE_DDHRESULT + &H130

'/*
' * One or more of the parameters passed to the callback function are
' * incorrect.
' */
%DDERR_INVALIDPARAMS                    = %E_INVALIDARG

'/*
' * pixel format was invalid as specified
' */
%DDERR_INVALIDPIXELFORMAT               = %MAKE_DDHRESULT + &H145

'/*
' * Rectangle provided was invalid.
' */
%DDERR_INVALIDRECT                      = %MAKE_DDHRESULT + &H150

'/*
' * Operation could not be carried out because one or more surfaces are locked
' */
%DDERR_LOCKEDSURFACES                   = %MAKE_DDHRESULT + &H160

'/*
' * There is no 3D present.
' */
%DDERR_NO3D                             = %MAKE_DDHRESULT + &H170

'/*
' * Operation could not be carried out because there is no alpha accleration
' * hardware present or available.
' */
%DDERR_NOALPHAHW                        = %MAKE_DDHRESULT + &H180

'/*
' * Operation could not be carried out because there is no stereo
' * hardware present or available.
' */
%DDERR_NOSTEREOHARDWARE                 = %MAKE_DDHRESULT + &H181

'/*
' * Operation could not be carried out because there is no hardware
' * present which supports stereo surfaces
' */
%DDERR_NOSURFACELEFT                    = %MAKE_DDHRESULT + &H182



'/*
' * no clip list available
' */
%DDERR_NOCLIPLIST                       = %MAKE_DDHRESULT + &H205

'/*
' * Operation could not be carried out because there is no color conversion
' * hardware present or available.
' */
%DDERR_NOCOLORCONVHW                    = %MAKE_DDHRESULT + &H210

'/*
' * Create function called without DirectDraw object method SetCooperativeLevel
' * being called.
' */
%DDERR_NOCOOPERATIVELEVELSET            = %MAKE_DDHRESULT + &H212

'/*
' * Surface doesn't currently have a color key
' */
%DDERR_NOCOLORKEY                       = %MAKE_DDHRESULT + &H215

'/*
' * Operation could not be carried out because there is no hardware support
' * of the dest color key.
' */
%DDERR_NOCOLORKEYHW                     = %MAKE_DDHRESULT + &H220

'/*
' * No DirectDraw support possible with current display driver
' */
%DDERR_NODIRECTDRAWSUPPORT              = %MAKE_DDHRESULT + &H222

'/*
' * Operation requires the application to have exclusive mode but the
' * application does not have exclusive mode.
' */
%DDERR_NOEXCLUSIVEMODE                  = %MAKE_DDHRESULT + &H225

'/*
' * Flipping visible surfaces is not supported.
' */
%DDERR_NOFLIPHW                         = %MAKE_DDHRESULT + &H230

'/*
' * There is no GDI present.
' */
%DDERR_NOGDI                            = %MAKE_DDHRESULT + &H240

'/*
' * Operation could not be carried out because there is no hardware present
' * or available.
' */
%DDERR_NOMIRRORHW                       = %MAKE_DDHRESULT + &H250

'/*
' * Requested item was not found
' */
%DDERR_NOTFOUND                         = %MAKE_DDHRESULT + &H255

'/*
' * Operation could not be carried out because there is no overlay hardware
' * present or available.
' */
%DDERR_NOOVERLAYHW                      = %MAKE_DDHRESULT + &H260

'/*
' * Operation could not be carried out because the source and destination
' * rectangles are on the same surface and overlap each other.
' */
%DDERR_OVERLAPPINGRECTS                 = %MAKE_DDHRESULT + &H270

'/*
' * Operation could not be carried out because there is no appropriate raster
' * op hardware present or available.
' */
%DDERR_NORASTEROPHW                     = %MAKE_DDHRESULT + &H280

'/*
' * Operation could not be carried out because there is no rotation hardware
' * present or available.
' */
%DDERR_NOROTATIONHW                     = %MAKE_DDHRESULT + &H290

'/*
' * Operation could not be carried out because there is no hardware support
' * for stretching
' */
%DDERR_NOSTRETCHHW                      = %MAKE_DDHRESULT + &H310

'/*
' * DirectDrawSurface is not in 4 bit color palette and the requested operation
' * requires 4 bit color palette.
' */
%DDERR_NOT4BITCOLOR                     = %MAKE_DDHRESULT + &H316

'/*
' * DirectDrawSurface is not in 4 bit color index palette and the requested
' * operation requires 4 bit color index palette.
' */
%DDERR_NOT4BITCOLORINDEX                = %MAKE_DDHRESULT + &H317

'/*
' * DirectDraw Surface is not in 8 bit color mode and the requested operation
' * requires 8 bit color.
' */
%DDERR_NOT8BITCOLOR                     = %MAKE_DDHRESULT + &H320

'/*
' * Operation could not be carried out because there is no texture mapping
' * hardware present or available.
' */
%DDERR_NOTEXTUREHW                      = %MAKE_DDHRESULT + &H330

'/*
' * Operation could not be carried out because there is no hardware support
' * for vertical blank synchronized operations.
' */
%DDERR_NOVSYNCHW                        = %MAKE_DDHRESULT + &H335

'/*
' * Operation could not be carried out because there is no hardware support
' * for zbuffer blting.
' */
%DDERR_NOZBUFFERHW                      = %MAKE_DDHRESULT + &H340

'/*
' * Overlay surfaces could not be z layered based on their BltOrder because
' * the hardware does not support z layering of overlays.
' */
%DDERR_NOZOVERLAYHW                     = %MAKE_DDHRESULT + &H350

'/*
' * The hardware needed for the requested operation has already been
' * allocated.
' */
%DDERR_OUTOFCAPS                        = %MAKE_DDHRESULT + &H360

'/*
' * DirectDraw does not have enough memory to perform the operation.
' */
%DDERR_OUTOFMEMORY                      = %E_OUTOFMEMORY

'/*
' * DirectDraw does not have enough memory to perform the operation.
' */
%DDERR_OUTOFVIDEOMEMORY                 = %MAKE_DDHRESULT + &H380

'/*
' * hardware does not support clipped overlays
' */
%DDERR_OVERLAYCANTCLIP                  = %MAKE_DDHRESULT + &H382

'/*
' * Can only have ony color key active at one time for overlays
' */
%DDERR_OVERLAYCOLORKEYONLYONEACTIVE     = %MAKE_DDHRESULT + &H384

'/*
' * Access to this palette is being refused because the palette is already
' * locked by another thread.
' */
%DDERR_PALETTEBUSY                      = %MAKE_DDHRESULT + &H387

'/*
' * No src color key specified for this operation.
' */
%DDERR_COLORKEYNOTSET                   = %MAKE_DDHRESULT + &H400

'/*
' * This surface is already attached to the surface it is being attached to.
' */
%DDERR_SURFACEALREADYATTACHED           = %MAKE_DDHRESULT + &H410

'/*
' * This surface is already a dependency of the surface it is being made a
' * dependency of.
' */
%DDERR_SURFACEALREADYDEPENDENT          = %MAKE_DDHRESULT + &H420

'/*
' * Access to this surface is being refused because the surface is already
' * locked by another thread.
' */
%DDERR_SURFACEBUSY                      = %MAKE_DDHRESULT + &H430

'/*
' * Access to this surface is being refused because no driver exists
' * which can supply a pointer to the surface.
' * This is most likely to happen when attempting to lock the primary
' * surface when no DCI provider is present.
' * Will also happen on attempts to lock an optimized surface.
' */
%DDERR_CANTLOCKSURFACE                  = %MAKE_DDHRESULT + &H435

'/*
' * Access to Surface refused because Surface is obscured.
' */
%DDERR_SURFACEISOBSCURED                = %MAKE_DDHRESULT + &H440

'/*
' * Access to this surface is being refused because the surface is gone.
' * The DIRECTDRAWSURFACE object representing this surface should
' * have Restore called on it.
' */
%DDERR_SURFACELOST                      = %MAKE_DDHRESULT + &H450

'/*
' * The requested surface is not attached.
' */
%DDERR_SURFACENOTATTACHED               = %MAKE_DDHRESULT + &H460

'/*
' * Height requested by DirectDraw is too large.
' */
%DDERR_TOOBIGHEIGHT                     = %MAKE_DDHRESULT + &H470

'/*
' * Size requested by DirectDraw is too large --  The individual height and
' * width are OK.
' */
%DDERR_TOOBIGSIZE                       = %MAKE_DDHRESULT + &H480

'/*
' * Width requested by DirectDraw is too large.
' */
%DDERR_TOOBIGWIDTH                      = %MAKE_DDHRESULT + &H490

'/*
' * Action not supported.
' */
%DDERR_UNSUPPORTED                      = %E_NOTIMPL

'/*
' * Pixel format requested is unsupported by DirectDraw
' */
%DDERR_UNSUPPORTEDFORMAT                = %MAKE_DDHRESULT + &H510

'/*
' * Bitmask in the pixel format requested is unsupported by DirectDraw
' */
%DDERR_UNSUPPORTEDMASK                  = %MAKE_DDHRESULT + &H520

'/*
' * The specified stream contains invalid data
' */
%DDERR_INVALIDSTREAM                    = %MAKE_DDHRESULT + &H521

'/*
' * vertical blank is in progress
' */
%DDERR_VERTICALBLANKINPROGRESS          = %MAKE_DDHRESULT + &H537

'/*
' * Informs DirectDraw that the previous Blt which is transfering information
' * to or from this Surface is incomplete.
' */
%DDERR_WASSTILLDRAWING                  = %MAKE_DDHRESULT + &H540


'/*
' * The specified surface type requires specification of the COMPLEX flag
' */
%DDERR_DDSCAPSCOMPLEXREQUIRED           = %MAKE_DDHRESULT + &H542


'/*
' * Rectangle provided was not horizontally aligned on reqd. boundary
' */
%DDERR_XALIGN                           = %MAKE_DDHRESULT + &H560

'/*
' * The GUID passed to DirectDrawCreate is not a valid DirectDraw driver
' * identifier.
' */
%DDERR_INVALIDDIRECTDRAWGUID            = %MAKE_DDHRESULT + &H561

'/*
' * A DirectDraw object representing this driver has already been created
' * for this process.
' */
%DDERR_DIRECTDRAWALREADYCREATED         = %MAKE_DDHRESULT + &H562

'/*
' * A hardware only DirectDraw object creation was attempted but the driver
' * did not support any hardware.
' */
%DDERR_NODIRECTDRAWHW                   = %MAKE_DDHRESULT + &H563

'/*
' * this process already has created a primary surface
' */
%DDERR_PRIMARYSURFACEALREADYEXISTS      = %MAKE_DDHRESULT + &H564

'/*
' * software emulation not available.
' */
%DDERR_NOEMULATION                      = %MAKE_DDHRESULT + &H565

'/*
' * region passed to Clipper::GetClipList is too small.
' */
%DDERR_REGIONTOOSMALL                   = %MAKE_DDHRESULT + &H566

'/*
' * an attempt was made to set a clip list for a clipper objec that
' * is already monitoring an hwnd.
' */
%DDERR_CLIPPERISUSINGHWND               = %MAKE_DDHRESULT + &H567

'/*
' * No clipper object attached to surface object
' */
%DDERR_NOCLIPPERATTACHED                = %MAKE_DDHRESULT + &H568

'/*
' * Clipper notification requires an HWND or
' * no HWND has previously been set as the CooperativeLevel HWND.
' */
%DDERR_NOHWND                           = %MAKE_DDHRESULT + &H569

'/*
' * HWND used by DirectDraw CooperativeLevel has been subclassed,
' * this prevents DirectDraw from restoring state.
' */
%DDERR_HWNDSUBCLASSED                   = %MAKE_DDHRESULT + &H570

'/*
' * The CooperativeLevel HWND has already been set.
' * It can not be reset while the process has surfaces or palettes created.
' */
%DDERR_HWNDALREADYSET                   = %MAKE_DDHRESULT + &H571

'/*
' * No palette object attached to this surface.
' */
%DDERR_NOPALETTEATTACHED                = %MAKE_DDHRESULT + &H572

'/*
' * No hardware support for 16 or 256 color palettes.
' */
%DDERR_NOPALETTEHW                      = %MAKE_DDHRESULT + &H573

'/*
' * If a clipper object is attached to the source surface passed into a
' * BltFast call.
' */
%DDERR_BLTFASTCANTCLIP                  = %MAKE_DDHRESULT + &H574

'/*
' * No blter.
' */
%DDERR_NOBLTHW                          = %MAKE_DDHRESULT + &H575

'/*
' * No DirectDraw ROP hardware.
' */
%DDERR_NODDROPSHW                       = %MAKE_DDHRESULT + &H576

'/*
' * returned when GetOverlayPosition is called on a hidden overlay
' */
%DDERR_OVERLAYNOTVISIBLE                = %MAKE_DDHRESULT + &H577

'/*
' * returned when GetOverlayPosition is called on a overlay that UpdateOverlay
' * has never been called on to establish a destionation.
' */
%DDERR_NOOVERLAYDEST                    = %MAKE_DDHRESULT + &H578

'/*
' * returned when the position of the overlay on the destionation is no longer
' * legal for that destionation.
' */
%DDERR_INVALIDPOSITION                  = %MAKE_DDHRESULT + &H579

'/*
' * returned when an overlay member is called for a non-overlay surface
' */
%DDERR_NOTAOVERLAYSURFACE               = %MAKE_DDHRESULT + &H580

'/*
' * An attempt was made to set the cooperative level when it was already
' * set to exclusive.
' */
%DDERR_EXCLUSIVEMODEALREADYSET          = %MAKE_DDHRESULT + &H581

'/*
' * An attempt has been made to flip a surface that is not flippable.
' */
%DDERR_NOTFLIPPABLE                     = %MAKE_DDHRESULT + &H582

'/*
' * Can't duplicate primary & 3D surfaces, or surfaces that are implicitly
' * created.
' */
%DDERR_CANTDUPLICATE                    = %MAKE_DDHRESULT + &H583

'/*
' * Surface was not locked.  An attempt to unlock a surface that was not
' * locked at all, or by this process, has been attempted.
' */
%DDERR_NOTLOCKED                        = %MAKE_DDHRESULT + &H584

'/*
' * Windows can not create any more DCs, or a DC was requested for a paltte-indexed
' * surface when the surface had no palette AND the display mode was not palette-indexed
' * (in this case DirectDraw cannot select a proper palette into the DC)
' */
%DDERR_CANTCREATEDC                     = %MAKE_DDHRESULT + &H585

'/*
' * No DC was ever created for this surface.
' */
%DDERR_NODC                             = %MAKE_DDHRESULT + &H586

'/*
' * This surface can not be restored because it was created in a different
' * mode.
' */
%DDERR_WRONGMODE                        = %MAKE_DDHRESULT + &H587

'/*
' * This surface can not be restored because it is an implicitly created
' * surface.
' */
%DDERR_IMPLICITLYCREATED                = %MAKE_DDHRESULT + &H588

'/*
' * The surface being used is not a palette-based surface
' */
%DDERR_NOTPALETTIZED                    = %MAKE_DDHRESULT + &H589


'/*
' * The display is currently in an unsupported mode
' */
%DDERR_UNSUPPORTEDMODE                  = %MAKE_DDHRESULT + &H590

'/*
' * Operation could not be carried out because there is no mip-map
' * texture mapping hardware present or available.
' */
%DDERR_NOMIPMAPHW                       = %MAKE_DDHRESULT + &H591

'/*
' * The requested action could not be performed because the surface was of
' * the wrong type.
' */
%DDERR_INVALIDSURFACETYPE               = %MAKE_DDHRESULT + &H592


'/*
' * Device does not support optimized surfaces, therefore no video memory optimized surfaces
' */
%DDERR_NOOPTIMIZEHW                     = %MAKE_DDHRESULT + &H600

'/*
' * Surface is an optimized surface, but has not yet been allocated any memory
' */
%DDERR_NOTLOADED                        = %MAKE_DDHRESULT + &H601

'/*
' * Attempt was made to create or set a device window without first setting
' * the focus window
' */
%DDERR_NOFOCUSWINDOW                    = %MAKE_DDHRESULT + &H602

'/*
' * Attempt was made to set a palette on a mipmap sublevel
' */
%DDERR_NOTONMIPMAPSUBLEVEL              = %MAKE_DDHRESULT + &H603

'/*
' * A DC has already been returned for this surface. Only one DC can be
' * retrieved per surface.
' */
%DDERR_DCALREADYCREATED                 = %MAKE_DDHRESULT + &H620

'/*
' * An attempt was made to allocate non-local video memory from a device
' * that does not support non-local video memory.
' */
%DDERR_NONONLOCALVIDMEM                 = %MAKE_DDHRESULT + &H630

'/*
' * The attempt to page lock a surface failed.
' */
%DDERR_CANTPAGELOCK                     = %MAKE_DDHRESULT + &H640


'/*
' * The attempt to page unlock a surface failed.
' */
%DDERR_CANTPAGEUNLOCK                   = %MAKE_DDHRESULT + &H660

'/*
' * An attempt was made to page unlock a surface with no outstanding page locks.
' */
%DDERR_NOTPAGELOCKED                    = %MAKE_DDHRESULT + &H680

'/*
' * There is more data available than the specified buffer size could hold
' */
%DDERR_MOREDATA                         = %MAKE_DDHRESULT + &H690

'/*
' * The data has expired and is therefore no longer valid.
' */
%DDERR_EXPIRED                          = %MAKE_DDHRESULT + &H691

'/*
' * The mode test has finished executing.
' */
%DDERR_TESTFINISHED                     = %MAKE_DDHRESULT + &H692

'/*
' * The mode test has switched to a new mode.
' */
%DDERR_NEWMODE                          = %MAKE_DDHRESULT + &H693

'/*
' * D3D has not yet been initialized.
' */
%DDERR_D3DNOTINITIALIZED                = %MAKE_DDHRESULT + &H694

'/*
' * The video port is not active
' */
%DDERR_VIDEONOTACTIVE                   = %MAKE_DDHRESULT + &H695

'/*
' * The monitor does not have EDID data.
' */
%DDERR_NOMONITORINFORMATION             = %MAKE_DDHRESULT + &H696

'/*
' * The driver does not enumerate display mode refresh rates.
' */
%DDERR_NODRIVERSUPPORT                  = %MAKE_DDHRESULT + &H697

'/*
' * Surfaces created by one direct draw device cannot be used directly by
' * another direct draw device.
' */
%DDERR_DEVICEDOESNTOWNSURFACE           = %MAKE_DDHRESULT + &H699


'/*
' * An attempt was made to invoke an interface member of a DirectDraw object
' * created by CoCreateInstance() before it was initialized.
' */
%DDERR_NOTINITIALIZED                  = %CO_E_NOTINITIALIZED


' ########################################################################################
' Interface name = IDirectDraw
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDraw $IID_IDirectDraw

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lplpDDClipper AS IDirectDrawClipper _        ' __out LPDIRECTDRAWCLIPPER FAR *lplpDDClipper
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpColorTable AS PALETTEENTRY _               ' __in  LPPALETTEENTRY lpColorTable
   , BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPDIRECTDRAWPALETTE FAR* lplpDDPalette
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 24
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in  LPDDSURFACEDESC lpDDSurfaceDesc
   , BYREF lplpDDSurface AS IDirectDrawSurface _        ' __out LPDIRECTDRAWSURFACE FAR *lplpDDSurface
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 28
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in  LPDIRECTDRAWSURFACE lpDDSurface
   , BYREF lplpDupDDSurface AS IDirectDrawSurface _     ' __out LPLPDIRECTDRAWSURFACE lplpDupDDSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDisplayModes ( _                          ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMMODESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSurfaces ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSD AS DDSURFACEDESC _                    ' __in LPDDSURFACEDESC lpDDSD
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMSURFACESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 44
     BYREF lpDDDriverCaps AS DDCAPS _                   ' __out LPDDCAPS lpDDDriverCaps
   , BYREF lpDDHELCaps AS DDCAPS _                      ' __out LPDDCAPS lpDDHELCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 48
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 52
     BYREF lpNumCodes AS DWORD _                        ' __out DWORD FAR *lpNumCodes
   , BYREF lpCodes AS DWORD _                           ' __out DWORD FAR *lpCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 56
     BYREF lplpGDIDDSSurface AS IDirectDrawSurface _    ' __out LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 60
     BYREF lpdwFrequency AS DWORD _                     ' __out LPDWORD lpdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 64
     BYREF lpdwScanLine AS DWORD _                      ' __out LPDWORD lpdwScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 68
     BYREF lpbIsInVB AS LONG _                          ' __out LPBOOL lpbIsInVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 72
     BYREF lpGUID AS GUID _                             ' __in GUID FAR *lpGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 80
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 84
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   , BYVAL dwBpp AS DWORD _                             ' __in DWORD dwBpp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDraw2
' Inherited interface = IDirectDraw
' ########################################################################################

INTERFACE IDirectDraw2 $IID_IDirectDraw2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDraw methods
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lplpDDClipper AS IDirectDrawClipper _        ' __out LPDIRECTDRAWCLIPPER FAR *lplpDDClipper
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpColorTable AS PALETTEENTRY _               ' __in  LPPALETTEENTRY lpColorTable
   , BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPDIRECTDRAWPALETTE FAR* lplpDDPalette
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 24
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in  LPDDSURFACEDESC lpDDSurfaceDesc
   , BYREF lplpDDSurface AS IDirectDrawSurface _        ' __out LPDIRECTDRAWSURFACE FAR *lplpDDSurface
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 28
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in  LPDIRECTDRAWSURFACE lpDDSurface
   , BYREF lplpDupDDSurface AS IDirectDrawSurface _     ' __out LPLPDIRECTDRAWSURFACE lplpDupDDSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDisplayModes ( _                          ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMMODESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSurfaces ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSD AS DDSURFACEDESC _                    ' __in LPDDSURFACEDESC lpDDSD
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMSURFACESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 44
     BYREF lpDDDriverCaps AS DDCAPS _                   ' __out LPDDCAPS lpDDDriverCaps
   , BYREF lpDDHELCaps AS DDCAPS _                      ' __out LPDDCAPS lpDDHELCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 48
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 52
     BYREF lpNumCodes AS DWORD _                        ' __out DWORD FAR *lpNumCodes
   , BYREF lpCodes AS DWORD _                           ' __out DWORD FAR *lpCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 56
     BYREF lplpGDIDDSSurface AS IDirectDrawSurface _    ' __out LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 60
     BYREF lpdwFrequency AS DWORD _                     ' __out LPDWORD lpdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 64
     BYREF lpdwScanLine AS DWORD _                      ' __out LPDWORD lpdwScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 68
     BYREF lpbIsInVB AS LONG _                          ' __out LPBOOL lpbIsInVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 72
     BYREF lpGUID AS GUID _                             ' __in GUID FAR *lpGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 80
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 84
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   , BYVAL dwBpp AS DWORD _                             ' __in DWORD dwBpp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw2 methods
   ' =====================================================================================
   METHOD GetAvailableVidMem ( _                        ' VTable offset = 92
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lpdwTotal AS DWORD _                         ' __out LPDWORD lpdwTotal
   , BYREF lpdwFree AS DWORD _                          ' __out LPDWORD lpdwFree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDraw4
' Inherited interface = IDirectDraw2
' ########################################################################################

INTERFACE IDirectDraw4 $IID_IDirectDraw4

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDraw methods
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lplpDDClipper AS IDirectDrawClipper _        ' __out LPDIRECTDRAWCLIPPER FAR *lplpDDClipper
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpColorTable AS PALETTEENTRY _               ' __in  LPPALETTEENTRY lpColorTable
   , BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPDIRECTDRAWPALETTE FAR* lplpDDPalette
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 24
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in  LPDDSURFACEDESC lpDDSurfaceDesc
   , BYREF lplpDDSurface AS IDirectDrawSurface _        ' __out LPDIRECTDRAWSURFACE FAR *lplpDDSurface
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 28
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in  LPDIRECTDRAWSURFACE lpDDSurface
   , BYREF lplpDupDDSurface AS IDirectDrawSurface _     ' __out LPLPDIRECTDRAWSURFACE lplpDupDDSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDisplayModes ( _                          ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMMODESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSurfaces ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSD AS DDSURFACEDESC _                    ' __in LPDDSURFACEDESC lpDDSD
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMSURFACESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 44
     BYREF lpDDDriverCaps AS DDCAPS _                   ' __out LPDDCAPS lpDDDriverCaps
   , BYREF lpDDHELCaps AS DDCAPS _                      ' __out LPDDCAPS lpDDHELCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 48
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 52
     BYREF lpNumCodes AS DWORD _                        ' __out DWORD FAR *lpNumCodes
   , BYREF lpCodes AS DWORD _                           ' __out DWORD FAR *lpCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 56
     BYREF lplpGDIDDSSurface AS IDirectDrawSurface _    ' __out LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 60
     BYREF lpdwFrequency AS DWORD _                     ' __out LPDWORD lpdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 64
     BYREF lpdwScanLine AS DWORD _                      ' __out LPDWORD lpdwScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 68
     BYREF lpbIsInVB AS LONG _                          ' __out LPBOOL lpbIsInVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 72
     BYREF lpGUID AS GUID _                             ' __in GUID FAR *lpGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 80
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 84
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   , BYVAL dwBpp AS DWORD _                             ' __in DWORD dwBpp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw2 methods
   ' =====================================================================================
   METHOD GetAvailableVidMem ( _                        ' VTable offset = 92
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lpdwTotal AS DWORD _                         ' __out LPDWORD lpdwTotal
   , BYREF lpdwFree AS DWORD _                          ' __out LPDWORD lpdwFree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw4 methods
   ' =====================================================================================
   METHOD GetSurfaceFromDC ( _                          ' VTable offset = 96
     BYVAL hdc AS DWORD _                               ' __in  HDC hdc
   , BYREF lpDDS4 AS IDirectDrawSurface4 _              ' __out LPDIRECTDRAWSURFACE4 *lpDDS4
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreAllSurfaces ( _                        ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 104
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIdentifier ( _                       ' VTable offset = 108
     BYREF lpdddi AS DDDEVICEIDENTIFIER _               ' __out LPDDDEVICEIDENTIFIER lpdddi
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDraw7
' Inherited interface = IDirectDraw4
' ########################################################################################

INTERFACE IDirectDraw7 $IID_IDirectDraw7

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDraw methods
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lplpDDClipper AS IDirectDrawClipper _        ' __out LPDIRECTDRAWCLIPPER FAR *lplpDDClipper
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpColorTable AS PALETTEENTRY _               ' __in  LPPALETTEENTRY lpColorTable
   , BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPDIRECTDRAWPALETTE FAR* lplpDDPalette
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 24
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in  LPDDSURFACEDESC lpDDSurfaceDesc
   , BYREF lplpDDSurface AS IDirectDrawSurface _        ' __out LPDIRECTDRAWSURFACE FAR *lplpDDSurface
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown FAR *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 28
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in  LPDIRECTDRAWSURFACE lpDDSurface
   , BYREF lplpDupDDSurface AS IDirectDrawSurface _     ' __out LPLPDIRECTDRAWSURFACE lplpDupDDSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDisplayModes ( _                          ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMMODESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSurfaces ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDSD AS DDSURFACEDESC _                    ' __in LPDDSURFACEDESC lpDDSD
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumCallback AS DWORD _                    ' __in LPDDENUMSURFACESCALLBACK lpEnumCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 44
     BYREF lpDDDriverCaps AS DDCAPS _                   ' __out LPDDCAPS lpDDDriverCaps
   , BYREF lpDDHELCaps AS DDCAPS _                      ' __out LPDDCAPS lpDDHELCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 48
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 52
     BYREF lpNumCodes AS DWORD _                        ' __out DWORD FAR *lpNumCodes
   , BYREF lpCodes AS DWORD _                           ' __out DWORD FAR *lpCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 56
     BYREF lplpGDIDDSSurface AS IDirectDrawSurface _    ' __out LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 60
     BYREF lpdwFrequency AS DWORD _                     ' __out LPDWORD lpdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 64
     BYREF lpdwScanLine AS DWORD _                      ' __out LPDWORD lpdwScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 68
     BYREF lpbIsInVB AS LONG _                          ' __out LPBOOL lpbIsInVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 72
     BYREF lpGUID AS GUID _                             ' __in GUID FAR *lpGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 80
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 84
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   , BYVAL dwBpp AS DWORD _                             ' __in DWORD dwBpp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw2 methods
   ' =====================================================================================
   METHOD GetAvailableVidMem ( _                        ' VTable offset = 92
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lpdwTotal AS DWORD _                         ' __out LPDWORD lpdwTotal
   , BYREF lpdwFree AS DWORD _                          ' __out LPDWORD lpdwFree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw4 methods
   ' =====================================================================================
   METHOD GetSurfaceFromDC ( _                          ' VTable offset = 96
     BYVAL hdc AS DWORD _                               ' __in  HDC hdc
   , BYREF lpDDS4 AS IDirectDrawSurface4 _              ' __out LPDIRECTDRAWSURFACE4 *lpDDS4
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreAllSurfaces ( _                        ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 104
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIdentifier ( _                       ' VTable offset = 108
     BYREF lpdddi AS DDDEVICEIDENTIFIER _               ' __out LPDDDEVICEIDENTIFIER lpdddi
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDraw7 methods
   ' =====================================================================================
   METHOD StartModeTest ( _                             ' VTable offset = 112
     BYREF lpModesToTest AS SIZE _                      ' __in LPSIZE lpModesToTest
   , BYVAL dwNumEntries AS DWORD _                      ' __in DWORD dwNumEntries
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EvaluateMode ( _                              ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD  dwFlags
   , BYREF pSecondsUntilTimeout AS DWORD _              ' __out DWORD  *pSecondsUntilTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDirectDrawPalette
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDrawPalette $IID_IDirectDrawPalette

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYREF lpdwCaps AS DWORD _                          ' __out LPDWORD lpdwCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntries ( _                                ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwBase AS DWORD _                            ' __in DWORD dwBase
   , BYVAL dwNumEntries AS DWORD _                      ' __in DWORD dwNumEntries
   , BYREF lpEntries AS PALETTEENTRY _                  ' __in_out LPPALETTEENTRY lpEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorTable AS PALETTEENTRY _             ' __in LPPALETTEENTRY lpDDColorTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEntries ( _                                ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwStartingEntry AS DWORD _                   ' __in DWORD dwStartingEntry
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYREF lpEntries AS PALETTEENTRY _                  ' __in LPPALETTEENTRY lpEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE ' IDirectDrawPalette


' ########################################################################################
' Interface name = IDirectDrawClipper
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDrawClipper $IID_IDirectDrawClipper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClipList ( _                               ' VTable offset = 12
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   , BYREF lpClipList AS RGNDATA _                      ' __in_out LPRGNDATA lpClipList
   , BYREF lpdwSize AS DWORD _                          ' __out LPDWORD lpdwSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHWnd ( _                                   ' VTable offset = 16
     BYREF lphWnd AS DWORD _                            ' __out HWND FAR *lphWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYVAL lpDD AS IDIrectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsClipListChanged ( _                         ' VTable offset = 24
     BYREF lpbChanged AS LONG _                         ' __out BOOL FAR *lpbChanged
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipList ( _                               ' VTable offset = 28
     BYREF lpClipList AS RGNDATA _                      ' __in LPRGNDATA lpClipList
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHWnd ( _                                   ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawSurface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDrawSurface $IID_IDirectDrawSurface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 12
     BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddOverlayDirtyRect ( _                       ' VTable offset = 16
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 20
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL lpDDSrcSurface As IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDBltFX AS DDBLTFX _                       ' __in LPDDBLTFX lpDDBltFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltBatch ( _                                  ' VTable offset = 24
     BYREF lpDDBltBatch AS DDBLTBATCH _                 ' __in LPDDBLTBATCH lpDDBltBatch
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 28
     BYVAL dwX AS DWORD _                               ' __in DWORD dwX
   , BYVAL dwY AS DWORD _                               ' __in DWORD dwY
   , BYVAL lpDDSrcSurface AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwTrans AS DWORD _                           ' __in DWORD dwTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttachedSurfaces ( _                      ' VTable offset = 36
     BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumSurfacesCallback AS DWORD _            ' __in LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumOverlayZOrders ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpfnCallback AS DWORD _                      ' __in LPDDENUMSURFACESCALLBACK lpfnCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 44
     BYVAL lpDDSurfaceTargetOverride AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 48
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lplpDDAttachedSurface AS IDirectDrawSurface _ ' __out LPLPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 56
     BYREF lpDDSCaps AS DDSCAPS _                       ' __out LPDDSCAPS lpDDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 60
     BYREF lplpDDClippe AS IDirectDrawClipper _         ' __out LPDIRECTDRAWCLIPPER FAR * lplpDDClippe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __out LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 68
     BYREF lphDC AS DWORD _                             ' __out HDCFAR *lphDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 76
     BYREF lplX AS LONG _                               ' __out LPLONG lplX
   , BYREF lplY AS LONG _                               ' __out LPLONG lplY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 80
     BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPLPDIRECTDRAWPALETTE lplpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 84
     BYREF lpDDPixelFormat AS DDPIXELFORMAT _           ' __out LPDDPIXELFORMAT lpDDPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 88
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 92
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLost ( _                                    ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 100
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 104
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 112
     BYVAL lpDDClipper AS IDirectDrawClipper _          ' __in LPDIRECTDRAWCLIPPER lpDDClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __in LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 120
     BYVAL lX AS LONG _                                 ' __in LONG lX
   , BYVAL lY AS LONG _                                 ' __in LONG lY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 124
     BYVAL lpDDPalette AS IDirectDrawPalette _          ' __in LPDIRECTDRAWPALETTE lpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 128
     BYVAL lpSurfaceData AS DWORD _                     ' __in LPVOID lpSurfaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 132
     BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL lpDDDestSurface AS IDirectDrawSurface _      ' __in LPDIRECTDRAWSURFACE lpDDDestSurface
   , BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDOverlayFx AS DDOVERLAYFX _               ' __in LPDDOVERLAYFX lpDDOverlayFx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayDisplay ( _                      ' VTable offset = 136
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 140
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSReference AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawSurface2
' Inherited interface = IDirectDrawSurface
' ########################################################################################

INTERFACE IDirectDrawSurface2 $IID_IDirectDrawSurface2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDrawSurface methods
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 12
     BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddOverlayDirtyRect ( _                       ' VTable offset = 16
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 20
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL lpDDSrcSurface As IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDBltFX AS DDBLTFX _                       ' __in LPDDBLTFX lpDDBltFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltBatch ( _                                  ' VTable offset = 24
     BYREF lpDDBltBatch AS DDBLTBATCH _                 ' __in LPDDBLTBATCH lpDDBltBatch
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 28
     BYVAL dwX AS DWORD _                               ' __in DWORD dwX
   , BYVAL dwY AS DWORD _                               ' __in DWORD dwY
   , BYVAL lpDDSrcSurface AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwTrans AS DWORD _                           ' __in DWORD dwTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttachedSurfaces ( _                      ' VTable offset = 36
     BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumSurfacesCallback AS DWORD _            ' __in LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumOverlayZOrders ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpfnCallback AS DWORD _                      ' __in LPDDENUMSURFACESCALLBACK lpfnCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 44
     BYVAL lpDDSurfaceTargetOverride AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 48
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lplpDDAttachedSurface AS IDirectDrawSurface _ ' __out LPLPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 56
     BYREF lpDDSCaps AS DDSCAPS _                       ' __out LPDDSCAPS lpDDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 60
     BYREF lplpDDClippe AS IDirectDrawClipper _         ' __out LPDIRECTDRAWCLIPPER FAR * lplpDDClippe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __out LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 68
     BYREF lphDC AS DWORD _                             ' __out HDCFAR *lphDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 76
     BYREF lplX AS LONG _                               ' __out LPLONG lplX
   , BYREF lplY AS LONG _                               ' __out LPLONG lplY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 80
     BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPLPDIRECTDRAWPALETTE lplpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 84
     BYREF lpDDPixelFormat AS DDPIXELFORMAT _           ' __out LPDDPIXELFORMAT lpDDPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 88
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 92
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLost ( _                                    ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 100
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 104
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 112
     BYVAL lpDDClipper AS IDirectDrawClipper _          ' __in LPDIRECTDRAWCLIPPER lpDDClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __in LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 120
     BYVAL lX AS LONG _                                 ' __in LONG lX
   , BYVAL lY AS LONG _                                 ' __in LONG lY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 124
     BYVAL lpDDPalette AS IDirectDrawPalette _          ' __in LPDIRECTDRAWPALETTE lpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 128
     BYVAL lpSurfaceData AS DWORD _                     ' __in LPVOID lpSurfaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 132
     BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL lpDDDestSurface AS IDirectDrawSurface _      ' __in LPDIRECTDRAWSURFACE lpDDDestSurface
   , BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDOverlayFx AS DDOVERLAYFX _               ' __in LPDDOVERLAYFX lpDDOverlayFx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayDisplay ( _                      ' VTable offset = 136
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 140
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSReference AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface2 methods
   ' =====================================================================================
   METHOD GetDDInterface ( _                            ' VTable offset = 144
     BYREF lplpDD AS IUnknown _                         ' __out LPVOID FAR* lplpDD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageLock ( _                                  ' VTable offset = 148
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageUnlock ( _                                ' VTable offset = 152
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawSurface3
' Inherited interface = IDirectDrawSurface2
' ########################################################################################

INTERFACE IDirectDrawSurface3 $IID_IDirectDrawSurface3

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDrawSurface methods
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 12
     BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddOverlayDirtyRect ( _                       ' VTable offset = 16
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 20
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL lpDDSrcSurface As IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDBltFX AS DDBLTFX _                       ' __in LPDDBLTFX lpDDBltFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltBatch ( _                                  ' VTable offset = 24
     BYREF lpDDBltBatch AS DDBLTBATCH _                 ' __in LPDDBLTBATCH lpDDBltBatch
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 28
     BYVAL dwX AS DWORD _                               ' __in DWORD dwX
   , BYVAL dwY AS DWORD _                               ' __in DWORD dwY
   , BYVAL lpDDSrcSurface AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwTrans AS DWORD _                           ' __in DWORD dwTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttachedSurfaces ( _                      ' VTable offset = 36
     BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumSurfacesCallback AS DWORD _            ' __in LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumOverlayZOrders ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpfnCallback AS DWORD _                      ' __in LPDDENUMSURFACESCALLBACK lpfnCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 44
     BYVAL lpDDSurfaceTargetOverride AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 48
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lplpDDAttachedSurface AS IDirectDrawSurface _ ' __out LPLPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 56
     BYREF lpDDSCaps AS DDSCAPS _                       ' __out LPDDSCAPS lpDDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 60
     BYREF lplpDDClippe AS IDirectDrawClipper _         ' __out LPDIRECTDRAWCLIPPER FAR * lplpDDClippe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __out LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 68
     BYREF lphDC AS DWORD _                             ' __out HDCFAR *lphDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 76
     BYREF lplX AS LONG _                               ' __out LPLONG lplX
   , BYREF lplY AS LONG _                               ' __out LPLONG lplY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 80
     BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPLPDIRECTDRAWPALETTE lplpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 84
     BYREF lpDDPixelFormat AS DDPIXELFORMAT _           ' __out LPDDPIXELFORMAT lpDDPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 88
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 92
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLost ( _                                    ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 100
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 104
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 112
     BYVAL lpDDClipper AS IDirectDrawClipper _          ' __in LPDIRECTDRAWCLIPPER lpDDClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __in LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 120
     BYVAL lX AS LONG _                                 ' __in LONG lX
   , BYVAL lY AS LONG _                                 ' __in LONG lY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 124
     BYVAL lpDDPalette AS IDirectDrawPalette _          ' __in LPDIRECTDRAWPALETTE lpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 128
     BYVAL lpSurfaceData AS DWORD _                     ' __in LPVOID lpSurfaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 132
     BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL lpDDDestSurface AS IDirectDrawSurface _      ' __in LPDIRECTDRAWSURFACE lpDDDestSurface
   , BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDOverlayFx AS DDOVERLAYFX _               ' __in LPDDOVERLAYFX lpDDOverlayFx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayDisplay ( _                      ' VTable offset = 136
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 140
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSReference AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface2 methods
   ' =====================================================================================
   METHOD GetDDInterface ( _                            ' VTable offset = 144
     BYREF lplpDD AS IUnknown _                         ' __out LPVOID FAR* lplpDD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageLock ( _                                  ' VTable offset = 148
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageUnlock ( _                                ' VTable offset = 152
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface3 methods
   ' =====================================================================================
   METHOD SetSurfaceDesc ( _                            ' VTable offset = 156
     BYREF lpddsd2 AS DDSURFACEDESC2 _                  ' __in LPDDSURFACEDESC2 lpddsd2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawSurface4
' Inherited interface = IDirectDrawSurface3
' ########################################################################################

INTERFACE IDirectDrawSurface4 $IID_IDirectDrawSurface4

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDrawSurface methods
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 12
     BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddOverlayDirtyRect ( _                       ' VTable offset = 16
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 20
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL lpDDSrcSurface As IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDBltFX AS DDBLTFX _                       ' __in LPDDBLTFX lpDDBltFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltBatch ( _                                  ' VTable offset = 24
     BYREF lpDDBltBatch AS DDBLTBATCH _                 ' __in LPDDBLTBATCH lpDDBltBatch
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 28
     BYVAL dwX AS DWORD _                               ' __in DWORD dwX
   , BYVAL dwY AS DWORD _                               ' __in DWORD dwY
   , BYVAL lpDDSrcSurface AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwTrans AS DWORD _                           ' __in DWORD dwTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttachedSurfaces ( _                      ' VTable offset = 36
     BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumSurfacesCallback AS DWORD _            ' __in LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumOverlayZOrders ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpfnCallback AS DWORD _                      ' __in LPDDENUMSURFACESCALLBACK lpfnCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 44
     BYVAL lpDDSurfaceTargetOverride AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 48
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lplpDDAttachedSurface AS IDirectDrawSurface _ ' __out LPLPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 56
     BYREF lpDDSCaps AS DDSCAPS _                       ' __out LPDDSCAPS lpDDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 60
     BYREF lplpDDClippe AS IDirectDrawClipper _         ' __out LPDIRECTDRAWCLIPPER FAR * lplpDDClippe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __out LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 68
     BYREF lphDC AS DWORD _                             ' __out HDCFAR *lphDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 76
     BYREF lplX AS LONG _                               ' __out LPLONG lplX
   , BYREF lplY AS LONG _                               ' __out LPLONG lplY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 80
     BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPLPDIRECTDRAWPALETTE lplpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 84
     BYREF lpDDPixelFormat AS DDPIXELFORMAT _           ' __out LPDDPIXELFORMAT lpDDPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 88
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 92
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLost ( _                                    ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 100
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 104
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 112
     BYVAL lpDDClipper AS IDirectDrawClipper _          ' __in LPDIRECTDRAWCLIPPER lpDDClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __in LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 120
     BYVAL lX AS LONG _                                 ' __in LONG lX
   , BYVAL lY AS LONG _                                 ' __in LONG lY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 124
     BYVAL lpDDPalette AS IDirectDrawPalette _          ' __in LPDIRECTDRAWPALETTE lpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 128
     BYVAL lpSurfaceData AS DWORD _                     ' __in LPVOID lpSurfaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 132
     BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL lpDDDestSurface AS IDirectDrawSurface _      ' __in LPDIRECTDRAWSURFACE lpDDDestSurface
   , BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDOverlayFx AS DDOVERLAYFX _               ' __in LPDDOVERLAYFX lpDDOverlayFx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayDisplay ( _                      ' VTable offset = 136
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 140
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSReference AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface2 methods
   ' =====================================================================================
   METHOD GetDDInterface ( _                            ' VTable offset = 144
     BYREF lplpDD AS IUnknown _                         ' __out LPVOID FAR* lplpDD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageLock ( _                                  ' VTable offset = 148
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageUnlock ( _                                ' VTable offset = 152
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface3 methods
   ' =====================================================================================
   METHOD SetSurfaceDesc ( _                            ' VTable offset = 156
     BYREF lpddsd2 AS DDSURFACEDESC2 _                  ' __in LPDDSURFACEDESC2 lpddsd2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface4 methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 160
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   , BYVAL lpData AS DWORD _                            ' __in LPVOID lpData
   , BYVAL cbSize AS DWORD _                            ' __in DWORD cbSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 164
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   , BYVAL lpBuffer AS DWORD _                          ' __in_out LPVOID lpBuffer
   , BYREF lpcbBufferSize AS DWORD _                    ' __out LPDWORD lpcbBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 168
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUniquenessValue ( _                        ' VTable offset = 172
     BYREF lpValue AS DWORD _                           ' __out LPDWORD lpValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeUniquenessValue ( _                     ' VTable offset = 176
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawSurface7
' Inherited interface = IDirectDrawSurface4
' ########################################################################################

INTERFACE IDirectDrawSurface7 $IID_IDirectDrawSurface7

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectDrawSurface methods
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 12
     BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddOverlayDirtyRect ( _                       ' VTable offset = 16
     BYREF lpRect AS RECT _                             ' __in LPRECT lpRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 20
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL lpDDSrcSurface As IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDBltFX AS DDBLTFX _                       ' __in LPDDBLTFX lpDDBltFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltBatch ( _                                  ' VTable offset = 24
     BYREF lpDDBltBatch AS DDBLTBATCH _                 ' __in LPDDBLTBATCH lpDDBltBatch
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 28
     BYVAL dwX AS DWORD _                               ' __in DWORD dwX
   , BYVAL dwY AS DWORD _                               ' __in DWORD dwY
   , BYVAL lpDDSrcSurface AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSrcSurface
   , BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL dwTrans AS DWORD _                           ' __in DWORD dwTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSAttachedSurface AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttachedSurfaces ( _                      ' VTable offset = 36
     BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumSurfacesCallback AS DWORD _            ' __in LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumOverlayZOrders ( _                        ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpfnCallback AS DWORD _                      ' __in LPDDENUMSURFACESCALLBACK lpfnCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 44
     BYVAL lpDDSurfaceTargetOverride AS IDirectDrawSurface _ ' __in LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 48
     BYREF lpDDSCaps AS DDSCAPS _                       ' __in  LPDDSCAPS lpDDSCaps
   , BYREF lplpDDAttachedSurface AS IDirectDrawSurface _ ' __out LPLPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 56
     BYREF lpDDSCaps AS DDSCAPS _                       ' __out LPDDSCAPS lpDDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 60
     BYREF lplpDDClippe AS IDirectDrawClipper _         ' __out LPDIRECTDRAWCLIPPER FAR * lplpDDClippe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __out LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 68
     BYREF lphDC AS DWORD _                             ' __out HDCFAR *lphDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 76
     BYREF lplX AS LONG _                               ' __out LPLONG lplX
   , BYREF lplY AS LONG _                               ' __out LPLONG lplY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 80
     BYREF lplpDDPalette AS IDirectDrawPalette _        ' __out LPLPDIRECTDRAWPALETTE lplpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 84
     BYREF lpDDPixelFormat AS DDPIXELFORMAT _           ' __out LPDDPIXELFORMAT lpDDPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 88
     BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __out LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 92
     BYVAL lpDD AS IDirectDraw _                        ' __in LPDIRECTDRAW lpDD
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLost ( _                                    ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 100
     BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYREF lpDDSurfaceDesc AS DDSURFACEDESC _           ' __in LPDDSURFACEDESC lpDDSurfaceDesc
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 104
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 112
     BYVAL lpDDClipper AS IDirectDrawClipper _          ' __in LPDIRECTDRAWCLIPPER lpDDClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 116
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDColorKey AS DDCOLORKEY _                 ' __in LPDDCOLORKEY lpDDColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 120
     BYVAL lX AS LONG _                                 ' __in LONG lX
   , BYVAL lY AS LONG _                                 ' __in LONG lY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 124
     BYVAL lpDDPalette AS IDirectDrawPalette _          ' __in LPDIRECTDRAWPALETTE lpDDPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 128
     BYVAL lpSurfaceData AS DWORD _                     ' __in LPVOID lpSurfaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 132
     BYREF lpSrcRect AS RECT _                          ' __in LPRECT lpSrcRect
   , BYVAL lpDDDestSurface AS IDirectDrawSurface _      ' __in LPDIRECTDRAWSURFACE lpDDDestSurface
   , BYREF lpDestRect AS RECT _                         ' __in LPRECT lpDestRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDOverlayFx AS DDOVERLAYFX _               ' __in LPDDOVERLAYFX lpDDOverlayFx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayDisplay ( _                      ' VTable offset = 136
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 140
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lpDDSReference AS IDirectDrawSurface _       ' __in LPDIRECTDRAWSURFACE lpDDSReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface2 methods
   ' =====================================================================================
   METHOD GetDDInterface ( _                            ' VTable offset = 144
     BYREF lplpDD AS IUnknown _                         ' __out LPVOID FAR* lplpDD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageLock ( _                                  ' VTable offset = 148
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PageUnlock ( _                                ' VTable offset = 152
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface3 methods
   ' =====================================================================================
   METHOD SetSurfaceDesc ( _                            ' VTable offset = 156
     BYREF lpddsd2 AS DDSURFACEDESC2 _                  ' __in LPDDSURFACEDESC2 lpddsd2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface4 methods
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 160
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   , BYVAL lpData AS DWORD _                            ' __in LPVOID lpData
   , BYVAL cbSize AS DWORD _                            ' __in DWORD cbSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 164
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   , BYVAL lpBuffer AS DWORD _                          ' __in_out LPVOID lpBuffer
   , BYREF lpcbBufferSize AS DWORD _                    ' __out LPDWORD lpcbBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 168
     BYREF guidTag AS GUID _                            ' __in REFGUID guidTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUniquenessValue ( _                        ' VTable offset = 172
     BYREF lpValue AS DWORD _                           ' __out LPDWORD lpValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeUniquenessValue ( _                     ' VTable offset = 176
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawSurface7 methods
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 180
     BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 184
     BYREF lpdwPriority AS DWORD _                      ' __out LPDWORD lpdwPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 188
     BYVAL dwMaxLOD AS DWORD _                          ' __in DWORD dwMaxLOD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 192
     BYREF lpdwMaxLOD AS DWORD _                        ' __out LPDWORD lpdwMaxLOD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawColorControl
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDrawColorControl $IID_IDirectDrawColorControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColorControls ( _                          ' VTable offset = 12
     BYREF lpColorControl AS DDCOLORCONTROL _           ' __out LPDDCOLORCONTROL lpColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorControls ( _                          ' VTable offset = 16
     BYREF lpColorControl AS DDCOLORCONTROL _           ' __in LPDDCOLORCONTROL lpColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirectDrawGammaControl
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectDrawGammaControl $IID_IDirectDrawGammaControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGammaRamp ( _                              ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD         dwFlags
   , BYREF lpGammaRamp AS DDGAMMARAMP _                 ' __out LPDDGAMMARAMP lpGammaRamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGammaRamp ( _                              ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD         dwFlags
   , BYREF lpGammaRamp AS DDGAMMARAMP _                 ' __in LPDDGAMMARAMP lpGammaRamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
