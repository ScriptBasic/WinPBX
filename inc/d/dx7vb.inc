' ########################################################################################
' Microsoft Windows
' File: dx7vb.inc
' Library name: DxVBLib
' Version: 1.0, Locale ID = 0
' Library GUID: {E1211242-8E94-11D1-8808-00C04FC2C602}
' Path: C:\WINDOWS\system32\dx7vb.dll
' Help file: C:\WINDOWS\system32\directx.chm
' Contents: DirectX 7 for Visual Basic Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DX7VB_INC = 1

#INCLUDE ONCE "ocidl.inc"   ' For IFont interface

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {E1211353-8E94-11D1-8808-00C04FC2C602}
$PROGID_DirectX70 = "DIRECT.DirectX6.0"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DirectX7 = GUID$("{E1211353-8E94-11D1-8808-00C04FC2C602}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_Direct3D7 = GUID$("{9F76FDD5-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DDevice7 = GUID$("{9F76FDD7-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DEnumDevices = GUID$("{9F76FDD3-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DEnumPixelFormats = GUID$("{9F76FDD6-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRM3 = GUID$("{9F76FE24-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMAnimation2 = GUID$("{9F76FE22-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMAnimationArray = GUID$("{9F76FE35-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMAnimationSet2 = GUID$("{9F76FE23-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMCallback = GUID$("{BBD5AD03-8E91-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMClippedVisual = GUID$("{9F76FE30-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMDevice3 = GUID$("{9F76FE27-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMDeviceArray = GUID$("{9F76FE12-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMDeviceUpdateCallback3 = GUID$("{9F76FE34-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMEnumerateObjectsCallback = GUID$("{BBD5AD04-8E91-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMFace2 = GUID$("{9F76FE32-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMFaceArray = GUID$("{9F76FE18-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMFrame3 = GUID$("{9F76FE25-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMFrameArray = GUID$("{9F76FE14-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMFrameInterpolator = GUID$("{5F4637E2-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMFrameMoveCallback3 = GUID$("{9F76FE33-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMInterpolator = GUID$("{9F76FE29-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMLight = GUID$("{9F76FE03-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMLightArray = GUID$("{9F76FE16-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMLightInterpolator = GUID$("{5F4637E4-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMLoadCallback = GUID$("{BBD5AD0A-8E91-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMLoadTextureCallback3 = GUID$("{BBD5AD16-8E91-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMMaterial2 = GUID$("{9F76FE21-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMMaterialInterpolator = GUID$("{5F4637E6-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMMesh = GUID$("{9F76FE06-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMMeshBuilder3 = GUID$("{9F76FE26-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMMeshInterpolator = GUID$("{5F4637E3-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMObject = GUID$("{9F76FE0E-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMObjectArray = GUID$("{9F76FE11-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMPick2Array = GUID$("{9F76FE19-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMPickArray = GUID$("{9F76FE17-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMProgressiveMesh = GUID$("{9F76FE31-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMShadow2 = GUID$("{9F76FE36-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMTexture3 = GUID$("{9F76FE28-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMTextureInterpolator = GUID$("{5F4637E5-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMViewport2 = GUID$("{9F76FE20-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMViewportArray = GUID$("{9F76FE13-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMViewportInterpolator = GUID$("{5F4637E1-62AC-11D2-90B1-00C04FC2C602}")
$IID_Direct3DRMVisual = GUID$("{9F76FE0F-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMVisualArray = GUID$("{9F76FE15-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DRMWrap = GUID$("{9F76FE08-8E92-11D1-8808-00C04FC2C602}")
$IID_Direct3DVertexBuffer7 = GUID$("{9F76FDDA-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDraw4 = GUID$("{BCAA7DA2-F7EF-11D2-93FD-00C04FC2C602}")
$IID_DirectDraw7 = GUID$("{9F76FDE7-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawClipper = GUID$("{9F76FDCA-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawColorControl = GUID$("{9F76FDE0-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawEnum = GUID$("{9F76FDE1-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawEnumModes = GUID$("{9F76FFFF-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawEnumSurfaces = GUID$("{9F76FDE6-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawGammaControl = GUID$("{9F76FDE9-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawIdentifier = GUID$("{BCAA7DA4-F7EF-11D2-93FD-00C04FC2C602}")
$IID_DirectDrawPalette = GUID$("{9F76FDC9-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectDrawSurface4 = GUID$("{BCAA7DA3-F7EF-11D2-93FD-00C04FC2C602}")
$IID_DirectDrawSurface7 = GUID$("{9F76FDE8-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInput = GUID$("{9F76FA02-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputDevice = GUID$("{9F76FA03-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputDeviceInstance = GUID$("{9F76FA04-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputDeviceObjectInstance = GUID$("{9F76FA05-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputEffect = GUID$("{BCAA7DA9-F7EF-11D2-93FD-00C04FC2C602}")
$IID_DirectInputEnumDeviceObjects = GUID$("{9F76FA08-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputEnumDevices = GUID$("{9F76FA09-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectInputEnumEffects = GUID$("{BCAA7DAA-F7EF-11D2-93FD-00C04FC2C602}")
$IID_DirectMusicBand = GUID$("{FAFA35A3-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicChordMap = GUID$("{FAFA35A5-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicCollection = GUID$("{FAFA35A8-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicComposer = GUID$("{FAFA35A2-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicLoader = GUID$("{FAFA35A0-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicPerformance = GUID$("{FAFA35A7-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicSegment = GUID$("{FAFA35A1-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicSegmentState = GUID$("{FAFA35A6-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectMusicStyle = GUID$("{FAFA35A4-8B72-11D2-90B2-00C04FC2C602}")
$IID_DirectPlay4 = GUID$("{9F76FF0F-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayAddress = GUID$("{9F76FF05-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayEnumConnections = GUID$("{9F76FF0A-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayEnumLocalApplications = GUID$("{9F76FF0E-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayEnumPlayers = GUID$("{9F76FF0B-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayEnumServiceProviders = GUID$("{9F76FF0D-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayEnumSessions = GUID$("{9F76FF0C-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayLobby3 = GUID$("{9F76FF10-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayLobbyConnection = GUID$("{9F76FF06-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlayMessage = GUID$("{9F76FF11-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectPlaySessionData = GUID$("{9F76FF12-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSound = GUID$("{9F76FB00-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSound3DBuffer = GUID$("{9F76FB03-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSound3DListener = GUID$("{9F76FB02-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSoundBuffer = GUID$("{9F76FB01-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSoundCapture = GUID$("{9F76FB04-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSoundCaptureBuffer = GUID$("{9F76FB05-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectSoundEnum = GUID$("{9F76FB07-8E92-11D1-8808-00C04FC2C602}")
$IID_DirectXEvent = GUID$("{FAFA35B0-8B72-11D2-90B2-00C04FC2C602}")
$IID_IDirectX7 = GUID$("{FAFA3599-8B72-11D2-90B2-00C04FC2C602}")

' ========================================================================================
' CONST_D3DVERTEXBLENDFLAGS enum
' ========================================================================================

%D3DVBLEND_DISABLE                                      = 0            ' &H0
%D3DVBLEND_1WEIGHT                                      = 1            ' &H1
%D3DVBLEND_2WEIGHTS                                     = 2            ' &H2
%D3DVBLEND_3WEIGHTS                                     = 3            ' &H3

' ========================================================================================
' CONST_D3DTEXTURETRANSFORMFLAGS enum
' ========================================================================================

%D3DTTFF_DISABLE                                        = 0            ' &H0
%D3DTTFF_COUNT1                                         = 1            ' &H1
%D3DTTFF_COUNT2                                         = 2            ' &H2
%D3DTTFF_COUNT3                                         = 3            ' &H3
%D3DTTFF_COUNT4                                         = 4            ' &H4
%D3DTTFF_PROJECTED                                      = 256          ' &H100

' ========================================================================================
' CONST_D3DVTXPCAPSFLAGS enum
' ========================================================================================

%D3DVTXPCAPS_TEXGEN                                     = 1            ' &H1
%D3DVTXPCAPS_MATERIALSOURCE7                            = 2            ' &H2
%D3DVTXPCAPS_VERTEXFOG                                  = 4            ' &H4
%D3DVTXPCAPS_DIRECTIONALLIGHTS                          = 8            ' &H8
%D3DVTXPCAPS_POSITIONALLIGHTS                           = 16           ' &H10
%D3DVTXPCAPS_NONLOCALVIEWER                             = 32           ' &H20

' ========================================================================================
' CONST_D3DFDSFLAGS enum
' ========================================================================================

%D3DFDS_COLORMODE                                       = 1            ' &H1
%D3DFDS_GUID                                            = 2            ' &H2
%D3DFDS_HARDWARE                                        = 4            ' &H4
%D3DFDS_TRIANGLES                                       = 8            ' &H8
%D3DFDS_LINES                                           = 16           ' &H10
%D3DFDS_MISCCAPS                                        = 32           ' &H20
%D3DFDS_RASTERCAPS                                      = 64           ' &H40
%D3DFDS_ZCMPCAPS                                        = 128          ' &H80
%D3DFDS_ALPHACMPCAPS                                    = 256          ' &H100
%D3DFDS_SRCBLENDCAPS                                    = 512          ' &H200
%D3DFDS_DSTBLENDCAPS                                    = 1024         ' &H400
%D3DFDS_SHADECAPS                                       = 2048         ' &H800
%D3DFDS_TEXTURECAPS                                     = 4096         ' &H1000
%D3DFDS_TEXTUREFILTERCAPS                               = 8192         ' &H2000
%D3DFDS_TEXTUREBLENDCAPS                                = 16384        ' &H4000
%D3DFDS_TEXTUREADDRESSCAPS                              = 32768        ' &H8000

' ========================================================================================
' CONST_D3DTEXOPCAPSFLAGS enum
' ========================================================================================

%D3DTEXOPCAPS_DISABLE                                   = 1            ' &H1
%D3DTEXOPCAPS_SELECTARG1                                = 2            ' &H2
%D3DTEXOPCAPS_SELECTARG2                                = 4            ' &H4
%D3DTEXOPCAPS_MODULATE                                  = 8            ' &H8
%D3DTEXOPCAPS_MODULATE2X                                = 16           ' &H10
%D3DTEXOPCAPS_MODULATE4X                                = 32           ' &H20
%D3DTEXOPCAPS_ADD                                       = 64           ' &H40
%D3DTEXOPCAPS_ADDSIGNED                                 = 128          ' &H80
%D3DTEXOPCAPS_ADDSIGNED2X                               = 256          ' &H100
%D3DTEXOPCAPS_SUBTRACT                                  = 512          ' &H200
%D3DTEXOPCAPS_ADDSMOOTH                                 = 1024         ' &H400
%D3DTEXOPCAPS_BLENDDIFFUSEALPHA                         = 2048         ' &H800
%D3DTEXOPCAPS_BLENDTEXTUREALPHA                         = 4096         ' &H1000
%D3DTEXOPCAPS_BLENDFACTORALPHA                          = 8192         ' &H2000
%D3DTEXOPCAPS_BLENDTEXTUREALPHAPM                       = 16384        ' &H4000
%D3DTEXOPCAPS_BLENDCURRENTALPHA                         = 32768        ' &H8000
%D3DTEXOPCAPS_PREMODULATE                               = 65536        ' &H10000
%D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR                    = 131072       ' &H20000
%D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA                    = 262144       ' &H40000
%D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR                 = 524288       ' &H80000
%D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA                 = 1048576      ' &H100000
%D3DTEXOPCAPS_BUMPENVMAP                                = 2097152      ' &H200000
%D3DTEXOPCAPS_BUMPENVMAPLUMINANCE                       = 4194304      ' &H400000
%D3DTEXOPCAPS_DOTPRODUCT3                               = 8388608      ' &H800000

' ========================================================================================
' CONST_D3DDPFLAGS enum
' ========================================================================================

%D3DDP_DEFAULT                                          = 0            ' &H0
%D3DDP_WAIT                                             = 1            ' &H1

' ========================================================================================
' CONST_D3DCLEARFLAGS enum
' ========================================================================================

%D3DCLEAR_TARGET                                        = 1            ' &H1
%D3DCLEAR_ZBUFFER                                       = 2            ' &H2
%D3DCLEAR_STENCIL                                       = 4            ' &H4
%D3DCLEAR_ALL                                           = 7            ' &H7

' ========================================================================================
' CONST_D3DLIGHTCAPSFLAGS enum
' ========================================================================================

%D3DLIGHTCAPS_POINT                                     = 1            ' &H1
%D3DLIGHTCAPS_SPOT                                      = 2            ' &H2
%D3DLIGHTCAPS_DIRECTIONAL                               = 4            ' &H4

' ========================================================================================
' CONST_D3DVOPFLAGS enum
' ========================================================================================

%D3DVOP_LIGHT                                           = 1024         ' &H400
%D3DVOP_TRANSFORM                                       = 1            ' &H1
%D3DVOP_CLIP                                            = 4            ' &H4
%D3DVOP_EXTENTS                                         = 8            ' &H8

' ========================================================================================
' CONST_D3DCOLORMODEL enum
' ========================================================================================

%D3DCOLOR_MONO                                          = 1            ' &H1
%D3DCOLOR_RGB                                           = 2            ' &H2

' ========================================================================================
' CONST_D3DLIGHTTYPE enum
' ========================================================================================

%D3DLIGHT_POINT                                         = 1            ' &H1
%D3DLIGHT_SPOT                                          = 2            ' &H2
%D3DLIGHT_DIRECTIONAL                                   = 3            ' &H3

' ========================================================================================
' CONST_D3DLIGHTINGMODELFLAGS enum
' ========================================================================================

%D3DLIGHTINGMODEL_RGB                                   = 1            ' &H1
%D3DLIGHTINGMODEL_MONO                                  = 2            ' &H2

' ========================================================================================
' CONST_D3DCAPSRASTER enum
' ========================================================================================

%D3DPRASTERCAPS_DITHER                                  = 1            ' &H1
%D3DPRASTERCAPS_ROP2                                    = 2            ' &H2
%D3DPRASTERCAPS_XOR                                     = 4            ' &H4
%D3DPRASTERCAPS_PAT                                     = 8            ' &H8
%D3DPRASTERCAPS_ZTEST                                   = 16           ' &H10
%D3DPRASTERCAPS_SUBPIXEL                                = 32           ' &H20
%D3DPRASTERCAPS_SUBPIXELX                               = 64           ' &H40
%D3DPRASTERCAPS_FOGVERTEX                               = 128          ' &H80
%D3DPRASTERCAPS_FOGTABLE                                = 256          ' &H100
%D3DPRASTERCAPS_STIPPLE                                 = 512          ' &H200
%D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT                  = 1024         ' &H400
%D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT                = 2048         ' &H800
%D3DPRASTERCAPS_ANTIALIASEDGES                          = 4096         ' &H1000
%D3DPRASTERCAPS_MIPMAPLODBIAS                           = 8192         ' &H2000
%D3DPRASTERCAPS_ZBIAS                                   = 16384        ' &H4000
%D3DPRASTERCAPS_ZBUFFERLESSHSR                          = 32768        ' &H8000
%D3DPRASTERCAPS_FOGRANGE                                = 65536        ' &H10000
%D3DPRASTERCAPS_ANISOTROPY                              = 131072       ' &H20000
%D3DPRASTERCAPS_WBUFFER                                 = 262144       ' &H40000
%D3DPRASTERCAPS_WFOG                                    = 1048576      ' &H100000
%D3DPRASTERCAPS_ZFOG                                    = 2097152      ' &H200000

' ========================================================================================
' CONST_D3DCAPSCMP enum
' ========================================================================================

%D3DPCMPCAPS_NEVER                                      = 1            ' &H1
%D3DPCMPCAPS_LESS                                       = 2            ' &H2
%D3DPCMPCAPS_EQUAL                                      = 4            ' &H4
%D3DPCMPCAPS_LESSEQUAL                                  = 8            ' &H8
%D3DPCMPCAPS_GREATER                                    = 16           ' &H10
%D3DPCMPCAPS_NOTEQUAL                                   = 32           ' &H20
%D3DPCMPCAPS_GREATEREQUAL                               = 64           ' &H40
%D3DPCMPCAPS_ALWAYS                                     = 128          ' &H80

' ========================================================================================
' CONST_D3DCAPSBLEND enum
' ========================================================================================

%D3DPBLENDCAPS_ZERO                                     = 1            ' &H1
%D3DPBLENDCAPS_ONE                                      = 2            ' &H2
%D3DPBLENDCAPS_SRCCOLOR                                 = 4            ' &H4
%D3DPBLENDCAPS_INVSRCCOLOR                              = 8            ' &H8
%D3DPBLENDCAPS_SRCALPHA                                 = 16           ' &H10
%D3DPBLENDCAPS_INVSRCALPHA                              = 32           ' &H20
%D3DPBLENDCAPS_DESTALPHA                                = 64           ' &H40
%D3DPBLENDCAPS_INVDESTALPHA                             = 128          ' &H80
%D3DPBLENDCAPS_DESTCOLOR                                = 256          ' &H100
%D3DPBLENDCAPS_INVDESTCOLOR                             = 512          ' &H200
%D3DPBLENDCAPS_SRCALPHASAT                              = 1024         ' &H400
%D3DPBLENDCAPS_BOTHSRCALPHA                             = 2048         ' &H800
%D3DPBLENDCAPS_BOTHINVSRCALPHA                          = 4096         ' &H1000

' ========================================================================================
' CONST_D3DCAPSSHADE enum
' ========================================================================================

%D3DPSHADECAPS_COLORFLATMONO                            = 1            ' &H1
%D3DPSHADECAPS_COLORFLATRGB                             = 2            ' &H2
%D3DPSHADECAPS_COLORGOURAUDMONO                         = 4            ' &H4
%D3DPSHADECAPS_COLORGOURAUDRGB                          = 8            ' &H8
%D3DPSHADECAPS_COLORPHONGMONO                           = 16           ' &H10
%D3DPSHADECAPS_COLORPHONGRGB                            = 32           ' &H20
%D3DPSHADECAPS_SPECULARFLATMONO                         = 64           ' &H40
%D3DPSHADECAPS_SPECULARFLATRGB                          = 128          ' &H80
%D3DPSHADECAPS_SPECULARGOURAUDMONO                      = 256          ' &H100
%D3DPSHADECAPS_SPECULARGOURAUDRGB                       = 512          ' &H200
%D3DPSHADECAPS_SPECULARPHONGMONO                        = 1024         ' &H400
%D3DPSHADECAPS_SPECULARPHONGRGB                         = 2048         ' &H800
%D3DPSHADECAPS_ALPHAFLATBLEND                           = 4096         ' &H1000
%D3DPSHADECAPS_ALPHAFLATSTIPPLED                        = 8192         ' &H2000
%D3DPSHADECAPS_ALPHAGOURAUDBLEND                        = 16384        ' &H4000
%D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED                     = 32768        ' &H8000
%D3DPSHADECAPS_ALPHAPHONGBLEND                          = 65536        ' &H10000
%D3DPSHADECAPS_ALPHAPHONGSTIPPLED                       = 131072       ' &H20000
%D3DPSHADECAPS_FOGFLAT                                  = 262144       ' &H40000
%D3DPSHADECAPS_FOGGOURAUD                               = 524288       ' &H80000
%D3DPSHADECAPS_FOGPHONG                                 = 1048576      ' &H100000

' ========================================================================================
' CONST_D3DCAPSTEXTURE enum
' ========================================================================================

%D3DPTEXTURECAPS_PERSPECTIVE                            = 1            ' &H1
%D3DPTEXTURECAPS_POW2                                   = 2            ' &H2
%D3DPTEXTURECAPS_ALPHA                                  = 4            ' &H4
%D3DPTEXTURECAPS_TRANSPARENCY                           = 8            ' &H8
%D3DPTEXTURECAPS_BORDER                                 = 16           ' &H10
%D3DPTEXTURECAPS_SQUAREONLY                             = 32           ' &H20
%D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE               = 64           ' &H40
%D3DPTEXTURECAPS_ALPHAPALETTE                           = 128          ' &H80
%D3DPTEXTURECAPS_NONPOW2CONDITIONAL                     = 256          ' &H100
%D3DPTEXTURECAPS_TEXTURETRANSFORM                       = 512          ' &H200
%D3DPTEXTURECAPS_PROJECTED                              = 1024         ' &H400
%D3DPTEXTURECAPS_CUBEMAP                                = 2048         ' &H800
%D3DPTEXTURECAPS_COLORKEYBLEND                          = 4096         ' &H1000

' ========================================================================================
' CONST_D3DCAPSTEXTUREFILTER enum
' ========================================================================================

%D3DPTFILTERCAPS_NEAREST                                = 1            ' &H1
%D3DPTFILTERCAPS_LINEAR                                 = 2            ' &H2
%D3DPTFILTERCAPS_MIPNEAREST                             = 4            ' &H4
%D3DPTFILTERCAPS_MIPLINEAR                              = 8            ' &H8
%D3DPTFILTERCAPS_LINEARMIPNEAREST                       = 16           ' &H10
%D3DPTFILTERCAPS_LINEARMIPLINEAR                        = 32           ' &H20

' ========================================================================================
' CONST_D3DCAPSTEXTUREADDRESS enum
' ========================================================================================

%D3DPTADDRESSCAPS_WRAP                                  = 1            ' &H1
%D3DPTADDRESSCAPS_MIRROR                                = 2            ' &H2
%D3DPTADDRESSCAPS_CLAMP                                 = 4            ' &H4
%D3DPTADDRESSCAPS_BORDER                                = 8            ' &H8
%D3DPTADDRESSCAPS_INDEPENDENTUV                         = 16           ' &H10

' ========================================================================================
' CONST_D3DDEVICEDESCCAPS enum
' ========================================================================================

%D3DDEVCAPS_FLOATTLVERTEX                               = 1            ' &H1
%D3DDEVCAPS_SORTINCREASINGZ                             = 2            ' &H2
%D3DDEVCAPS_SORTDECREASINGZ                             = 4            ' &H4
%D3DDEVCAPS_SORTEXACT                                   = 8            ' &H8
%D3DDEVCAPS_TLVERTEXSYSTEMMEMORY                        = 64           ' &H40
%D3DDEVCAPS_TLVERTEXVIDEOMEMORY                         = 128          ' &H80
%D3DDEVCAPS_TEXTURESYSTEMMEMORY                         = 256          ' &H100
%D3DDEVCAPS_TEXTUREVIDEOMEMORY                          = 512          ' &H200
%D3DDEVCAPS_DRAWPRIMTLVERTEX                            = 1024         ' &H400
%D3DDEVCAPS_CANRENDERAFTERFLIP                          = 2048         ' &H800
%D3DDEVCAPS_TEXTURENONLOCALVIDMEM                       = 4096         ' &H1000
%D3DDEVCAPS_SEPARATETEXTUREMEMORIES                     = 16384        ' &H4000
%D3DDEVCAPS_HWTRANSFORMANDLIGHT                         = 32768        ' &H8000
%D3DDEVCAPS_CANBLTSYSTONONLOCAL                         = 131072       ' &H20000
%D3DDEVCAPS_HWRASTERIZATION                             = 524288       ' &H80000

' ========================================================================================
' CONST_D3DCLIPFLAGS enum
' ========================================================================================

%D3DCLIP_LEFT                                           = 1            ' &H1
%D3DCLIP_RIGHT                                          = 2            ' &H2
%D3DCLIP_TOP                                            = 4            ' &H4
%D3DCLIP_BOTTOM                                         = 8            ' &H8
%D3DCLIP_FRONT                                          = 16           ' &H10
%D3DCLIP_BACK                                           = 32           ' &H20
%D3DCLIP_GEN0                                           = 64           ' &H40
%D3DCLIP_GEN1                                           = 128          ' &H80
%D3DCLIP_GEN2                                           = 256          ' &H100
%D3DCLIP_GEN3                                           = 512          ' &H200
%D3DCLIP_GEN4                                           = 1024         ' &H400
%D3DCLIP_GEN5                                           = 2048         ' &H800
%D3DSTATUS_CLIPINTERSECTIONLEFT                         = 4096         ' &H1000
%D3DSTATUS_CLIPINTERSECTIONRIGHT                        = 8192         ' &H2000
%D3DSTATUS_CLIPINTERSECTIONTOP                          = 16384        ' &H4000
%D3DSTATUS_CLIPINTERSECTIONBOTTOM                       = 32768        ' &H8000
%D3DSTATUS_CLIPINTERSECTIONFRONT                        = 65536        ' &H10000
%D3DSTATUS_CLIPINTERSECTIONBACK                         = 131072       ' &H20000
%D3DSTATUS_CLIPINTERSECTIONGEN0                         = 262144       ' &H40000
%D3DSTATUS_CLIPINTERSECTIONGEN1                         = 524288       ' &H80000
%D3DSTATUS_CLIPINTERSECTIONGEN2                         = 1048576      ' &H100000
%D3DSTATUS_CLIPINTERSECTIONGEN3                         = 2097152      ' &H200000
%D3DSTATUS_CLIPINTERSECTIONGEN4                         = 4194304      ' &H400000
%D3DSTATUS_CLIPINTERSECTIONGEN5                         = 8388608      ' &H800000
%D3DSTATUS_CLIPUNIONLEFT                                = 1            ' &H1
%D3DSTATUS_CLIPUNIONRIGHT                               = 2            ' &H2
%D3DSTATUS_CLIPUNIONTOP                                 = 4            ' &H4
%D3DSTATUS_CLIPUNIONBOTTOM                              = 8            ' &H8
%D3DSTATUS_CLIPUNIONFRONT                               = 16           ' &H10
%D3DSTATUS_CLIPUNIONBACK                                = 32           ' &H20
%D3DSTATUS_CLIPUNIONGEN0                                = 64           ' &H40
%D3DSTATUS_CLIPUNIONGEN1                                = 128          ' &H80
%D3DSTATUS_CLIPUNIONGEN2                                = 256          ' &H100
%D3DSTATUS_CLIPUNIONGEN3                                = 512          ' &H200
%D3DSTATUS_CLIPUNIONGEN4                                = 1024         ' &H400
%D3DSTATUS_CLIPUNIONGEN5                                = 2048         ' &H800
%D3DSTATUS_ZNOTVISIBLE                                  = 16777216     ' &H1000000
%D3DSTATUS_CLIPUNIONALL                                 = 16773120     ' &HFFF000
%D3DSTATUS_CLIPINTERSECTIONALL                          = 16773120     ' &HFFF000
%D3DSTATUS_DEFAULT                                      = 33550336     ' &H1FFF000

' ========================================================================================
' CONST_D3DCLIPSTATUSFLAGS enum
' ========================================================================================

%D3DCLIPSTATUS_STATUS                                   = 1            ' &H1
%D3DCLIPSTATUS_EXTENTS2                                 = 2            ' &H2
%D3DCLIPSTATUS_EXTENTS3                                 = 4            ' &H4

' ========================================================================================
' CONST_D3DLIGHTFLAGS enum
' ========================================================================================

%D3DLIGHT_ACTIVE                                        = 1            ' &H1
%D3DLIGHT_NO_SPECULAR                                   = 2            ' &H2
%D3DLIGHT_ALL                                           = 3            ' &H3

' ========================================================================================
' CONST_DDPALFLAGS enum
' ========================================================================================

%PC_DEFAULT                                             = 0            ' &H0
%PC_RESERVED                                            = 1            ' &H1
%PC_EXPLICIT                                            = 2            ' &H2
%PC_NOCOLLAPSE                                          = 4            ' &H4

' ========================================================================================
' CONST_DDDEVICEIDFLAGS enum
' ========================================================================================

%DDGDI_DEFAULT                                          = 0            ' &H0
%DDGDI_GETHOSTIDENTIFIER                                = 1            ' &H1

' ========================================================================================
' CONST_D3DVBCAPSFLAGS enum
' ========================================================================================

%D3DVBCAPS_SYSTEMMEMORY                                 = 2048         ' &H800
%D3DVBCAPS_WRITEONLY                                    = 65536        ' &H10000
%D3DVBCAPS_OPTIMIZED                                    = -2147483648  ' &H80000000
%D3DVBCAPS_DONOTCLIP                                    = 1            ' &H1
%D3DVBCAPS_DEFAULT                                      = 0            ' &H0

' ========================================================================================
' CONST_D3DFVFCAPSFLAGS enum
' ========================================================================================

%D3DFVFCAPS_TEXCOORDCOUNTMASK                           = 65535        ' &HFFFF
%D3DFVFCAPS_DONOTSTRIPELEMENTS                          = 524288       ' &H80000

' ========================================================================================
' CONST_D3DFVFFLAGS enum
' ========================================================================================

%D3DFVF_XYZ                                             = 2            ' &H2
%D3DFVF_XYZRHW                                          = 4            ' &H4
%D3DFVF_XYZB1                                           = 6            ' &H6
%D3DFVF_XYZB2                                           = 8            ' &H8
%D3DFVF_XYZB3                                           = 10           ' &HA
%D3DFVF_XYZB4                                           = 12           ' &HC
%D3DFVF_XYZB5                                           = 14           ' &HE
%D3DFVF_NORMAL                                          = 16           ' &H10
%D3DFVF_DIFFUSE                                         = 64           ' &H40
%D3DFVF_SPECULAR                                        = 128          ' &H80
%D3DFVF_TEX0                                            = 0            ' &H0
%D3DFVF_TEX1                                            = 256          ' &H100
%D3DFVF_TEX2                                            = 512          ' &H200
%D3DFVF_TEX3                                            = 768          ' &H300
%D3DFVF_TEX4                                            = 1024         ' &H400
%D3DFVF_TEX5                                            = 1280         ' &H500
%D3DFVF_TEX6                                            = 1536         ' &H600
%D3DFVF_TEX7                                            = 1792         ' &H700
%D3DFVF_TEX8                                            = 2048         ' &H800
%D3DFVF_VERTEX                                          = 274          ' &H112
%D3DFVF_LVERTEX                                         = 482          ' &H1E2
%D3DFVF_TLVERTEX                                        = 452          ' &H1C4

' ========================================================================================
' CONST_D3DTAFLAGS enum
' ========================================================================================

%D3DTA_SELECTMASK                                       = 15           ' &HF
%D3DTA_DIFFUSE                                          = 0            ' &H0
%D3DTA_CURRENT                                          = 1            ' &H1
%D3DTA_TEXTURE                                          = 2            ' &H2
%D3DTA_TFACTOR                                          = 3            ' &H3
%D3DTA_COMPLEMENT                                       = 16           ' &H10
%D3DTA_ALPHAREPLICATE                                   = 32           ' &H20
%D3DTA_SPECULAR                                         = 4            ' &H4

' ========================================================================================
' CONST_D3DCAPSMISC enum
' ========================================================================================

%D3DPMISCCAPS_MASKPLANES                                = 1            ' &H1
%D3DPMISCCAPS_MASKZ                                     = 2            ' &H2
%D3DPMISCCAPS_CONFORMANT                                = 8            ' &H8
%D3DPMISCCAPS_CULLNONE                                  = 16           ' &H10
%D3DPMISCCAPS_CULLCW                                    = 32           ' &H20
%D3DPMISCCAPS_CULLCCW                                   = 64           ' &H40

' ========================================================================================
' CONST_D3D enum
' ========================================================================================

%D3DRENDERSTATE_WRAPBIAS                                = 128          ' &H80
%D3DDP_MAXTEXCOORD                                      = 8            ' &H8
%D3DWRAPCOORD_0                                         = 1            ' &H1
%D3DWRAPCOORD_1                                         = 2            ' &H2
%D3DWRAPCOORD_2                                         = 4            ' &H4
%D3DWRAPCOORD_3                                         = 8            ' &H8

' ========================================================================================
' CONST_D3DRMCREATEDEVICEFLAGS enum
' ========================================================================================

%D3DRMDEVICE_DEFAULT                                    = 0            ' &H0
%D3DRMDEVICE_NOZBUFFER                                  = 1            ' &H1

' ========================================================================================
' CONST_D3DRMADDFACESFLAGS enum
' ========================================================================================

%D3DRMADDFACES_DEFAULT                                  = 0            ' &H0
%D3DRMADDFACES_VERTICESONLY                             = 1            ' &H1

' ========================================================================================
' CONST_D3DRMMESHBUILDERENABLEFLAGS enum
' ========================================================================================

%D3DRMMESHBUILDER_RENDERENABLE                          = 1            ' &H1
%D3DRMMESHBUILDER_PICKENABLE                            = 2            ' &H2
%D3DRMMESHBUILDER_PICKANDRENDERENABLE                   = 3            ' &H3

' ========================================================================================
' CONST_D3DRMMESHBUILDERAGEFLAGS enum
' ========================================================================================

%D3DRMMESHBUILDERAGE_GEOMETRY                           = 1            ' &H1
%D3DRMMESHBUILDERAGE_MATERIALS                          = 2            ' &H2
%D3DRMMESHBUILDERAGE_TEXTURES                           = 4            ' &H4

' ========================================================================================
' CONST_D3DRMPARENTINGFLAGS enum
' ========================================================================================

%D3DRMMESHBUILDER_DIRECTPARENT                          = 1            ' &H1
%D3DRMMESHBUILDER_ROOTMESH                              = 2            ' &H2

' ========================================================================================
' CONST_D3DRMADDMESHBUILDERFLAGS enum
' ========================================================================================

%D3DRMADDMESHBUILDER_DONTCOPYAPPDATA                    = 1            ' &H1
%D3DRMADDMESHBUILDER_FLATTENSUBMESHES                   = 2            ' &H2
%D3DRMADDMESHBUILDER_NOSUBMESHES                        = 4            ' &H4

' ========================================================================================
' CONST_D3DRMGENERATENORMALSFLAGS enum
' ========================================================================================

%D3DRMGENERATENORMALS_PRECOMPACT                        = 1            ' &H1
%D3DRMGENERATENORMALS_USECREASEANGLE                    = 2            ' &H2

' ========================================================================================
' CONST_D3DRMTEXTURECACHEFLAGS enum
' ========================================================================================

%D3DRMTEXTURE_FORCERESIDENT                             = 1            ' &H1
%D3DRMTEXTURE_STATIC                                    = 2            ' &H2
%D3DRMTEXTURE_DOWNSAMPLEPOINT                           = 4            ' &H4
%D3DRMTEXTURE_DOWNSAMPLEBILINEAR                        = 8            ' &H8
%D3DRMTEXTURE_DOWNSAMPLEREDUCEDEPTH                     = 16           ' &H10
%D3DRMTEXTURE_DOWNSAMPLENONE                            = 32           ' &H20

' ========================================================================================
' CONST_D3DRMLIGHTTYPE enum
' ========================================================================================

%D3DRMLIGHT_AMBIENT                                     = 0            ' &H0
%D3DRMLIGHT_POINT                                       = 1            ' &H1
%D3DRMLIGHT_SPOT                                        = 2            ' &H2
%D3DRMLIGHT_DIRECTIONAL                                 = 3            ' &H3

' ========================================================================================
' CONST_D3DRMVIEWPORTCLEARFLAGS enum
' ========================================================================================

%D3DRMCLEAR_TARGET                                      = 1            ' &H1
%D3DRMCLEAR_ZBUFFER                                     = 2            ' &H2
%D3DRMCLEAR_DIRTYRECTS                                  = 4            ' &H4
%D3DRMCLEAR_ALL                                         = 7            ' &H7

' ========================================================================================
' CONST_D3DRMRENDERQUALITY enum
' ========================================================================================

%D3DRMSHADE_FLAT                                        = 0            ' &H0
%D3DRMSHADE_GOURAUD                                     = 1            ' &H1
%D3DRMSHADE_PHONG                                       = 2            ' &H2
%D3DRMSHADE_MASK                                        = 7            ' &H7
%D3DRMSHADE_MAX                                         = 8            ' &H8
%D3DRMLIGHT_OFF                                         = 0            ' &H0
%D3DRMLIGHT_ON                                          = 8            ' &H8
%D3DRMLIGHT_MASK                                        = 56           ' &H38
%D3DRMLIGHT_MAX                                         = 64           ' &H40
%D3DRMFILL_POINTS                                       = 0            ' &H0
%D3DRMFILL_WIREFRAME                                    = 64           ' &H40
%D3DRMFILL_SOLID                                        = 128          ' &H80
%D3DRMFILL_MASK                                         = 448          ' &H1C0
%D3DRMFILL_MAX                                          = 512          ' &H200
%D3DRMRENDER_WIREFRAME                                  = 64           ' &H40
%D3DRMRENDER_UNLITFLAT                                  = 128          ' &H80
%D3DRMRENDER_FLAT                                       = 136          ' &H88
%D3DRMRENDER_GOURAUD                                    = 137          ' &H89
%D3DRMRENDER_PHONG                                      = 138          ' &H8A

' ========================================================================================
' CONST_D3DRMTEXTURECHANGEDFLAGS enum
' ========================================================================================

%D3DRMTEXTURE_CHANGEDPIXELS                             = 64           ' &H40
%D3DRMTEXTURE_CHANGEDPALETTE                            = 128          ' &H80
%D3DRMTEXTURE_INVALIDATEONLY                            = 256          ' &H100

' ========================================================================================
' CONST_D3DRMTEXTUREQUALITY enum
' ========================================================================================

%D3DRMTEXTURE_NEAREST                                   = 0            ' &H0
%D3DRMTEXTURE_LINEAR                                    = 1            ' &H1
%D3DRMTEXTURE_MIPNEAREST                                = 2            ' &H2
%D3DRMTEXTURE_MIPLINEAR                                 = 3            ' &H3
%D3DRMTEXTURE_LINEARMIPNEAREST                          = 4            ' &H4
%D3DRMTEXTURE_LINEARMIPLINEAR                           = 5            ' &H5

' ========================================================================================
' CONST_D3DRMCOMBINETYPE enum
' ========================================================================================

%D3DRMCOMBINE_REPLACE                                   = 0            ' &H0
%D3DRMCOMBINE_BEFORE                                    = 1            ' &H1
%D3DRMCOMBINE_AFTER                                     = 2            ' &H2

' ========================================================================================
' CONST_D3DRMPALETTEFLAGS enum
' ========================================================================================

%D3DRMPALETTE_FREE                                      = 0            ' &H0
%D3DRMPALETTE_READONLY                                  = 1            ' &H1
%D3DRMPALETTE_RESERVED                                  = 2            ' &H2

' ========================================================================================
' CONST_D3DRMWRAPTYPE enum
' ========================================================================================

%D3DRMWRAP_FLAT                                         = 0            ' &H0
%D3DRMWRAP_CYLINDER                                     = 1            ' &H1
%D3DRMWRAP_SPHERE                                       = 2            ' &H2
%D3DRMWRAP_CHROME                                       = 3            ' &H3

' ========================================================================================
' CONST_D3DRMPROJECTIONTYPE enum
' ========================================================================================

%D3DRMPROJECT_PERSPECTIVE                               = 0            ' &H0
%D3DRMPROJECT_ORTHOGRAPHIC                              = 1            ' &H1
%D3DRMPROJECT_RIGHTHANDPERSPECTIVE                      = 2            ' &H2
%D3DRMPROJECT_RIGHTHANDORTHOGRAPHIC                     = 3            ' &H3

' ========================================================================================
' CONST_D3DRMXOFFORMAT enum
' ========================================================================================

%D3DRMXOF_BINARY                                        = 0            ' &H0
%D3DRMXOF_COMPRESSED                                    = 1            ' &H1
%D3DRMXOF_TEXT                                          = 2            ' &H2

' ========================================================================================
' CONST_D3DRMCOLORSOURCE enum
' ========================================================================================

%D3DRMCOLOR_FROMFACE                                    = 0            ' &H0
%D3DRMCOLOR_FROMVERTEX                                  = 1            ' &H1

' ========================================================================================
' CONST_D3DRMFRAMECONSTRAINT enum
' ========================================================================================

%D3DRMCONSTRAIN_Z                                       = 0            ' &H0
%D3DRMCONSTRAIN_Y                                       = 1            ' &H1
%D3DRMCONSTRAIN_X                                       = 2            ' &H2

' ========================================================================================
' CONST_D3DRMMATERIALMODE enum
' ========================================================================================

%D3DRMMATERIAL_FROMMESH                                 = 0            ' &H0
%D3DRMMATERIAL_FROMPARENT                               = 1            ' &H1
%D3DRMMATERIAL_FROMFRAME                                = 2            ' &H2

' ========================================================================================
' CONST_D3DRMFOGMODE enum
' ========================================================================================

%D3DRMFOG_LINEAR                                        = 0            ' &H0
%D3DRMFOG_EXPONENTIAL                                   = 1            ' &H1
%D3DRMFOG_EXPONENTIALSQUARED                            = 2            ' &H2

' ========================================================================================
' CONST_D3DRMZBUFFERMODE enum
' ========================================================================================

%D3DRMZBUFFER_FROMPARENT                                = 0            ' &H0
%D3DRMZBUFFER_ENABLE                                    = 1            ' &H1
%D3DRMZBUFFER_DISABLE                                   = 2            ' &H2

' ========================================================================================
' CONST_D3DRMSORTMODE enum
' ========================================================================================

%D3DRMSORT_FROMPARENT                                   = 0            ' &H0
%D3DRMSORT_NONE                                         = 1            ' &H1
%D3DRMSORT_FRONTTOBACK                                  = 2            ' &H2
%D3DRMSORT_BACKTOFRONT                                  = 3            ' &H3

' ========================================================================================
' CONST_D3DRMRAYPICKFLAGS enum
' ========================================================================================

%D3DRMRAYPICK_ONLYBOUNDINGBOXES                         = 1            ' &H1
%D3DRMRAYPICK_IGNOREFURTHERPRIMITIVES                   = 2            ' &H2
%D3DRMRAYPICK_INTERPOLATEUV                             = 4            ' &H4
%D3DRMRAYPICK_INTERPOLATECOLOR                          = 8            ' &H8
%D3DRMRAYPICK_INTERPOLATENORMAL                         = 16           ' &H10

' ========================================================================================
' CONST_D3DRMADDTRIANGLESVT enum
' ========================================================================================

%D3DRMFVF_TYPE                                          = 1            ' &H1
%D3DRMFVF_NORMAL                                        = 2            ' &H2
%D3DRMFVF_COLOR                                         = 4            ' &H4
%D3DRMFVF_TEXTURECOORDS                                 = 8            ' &H8

' ========================================================================================
' CONST_D3DRMADDTRIANGLESFLAGS enum
' ========================================================================================

%D3DRMVERTEX_STRIP                                      = 1            ' &H1
%D3DRMVERTEX_FAN                                        = 2            ' &H2
%D3DRMVERTEX_LIST                                       = 4            ' &H4

' ========================================================================================
' CONST_D3DRMFOGMETHOD enum
' ========================================================================================

%D3DRMFOGMETHOD_VERTEX                                  = 1            ' &H1
%D3DRMFOGMETHOD_TABLE                                   = 2            ' &H2
%D3DRMFOGMETHOD_ANY                                     = 4            ' &H4

' ========================================================================================
' CONST_D3DRMTRAVERALFLAGS enum
' ========================================================================================

%D3DRMFRAME_RENDERENABLE                                = 1            ' &H1
%D3DRMFRAME_PICKENABLE                                  = 2            ' &H2
%D3DRMFRAME_RENDERANDPICKENABLE                         = 3            ' &H3

' ========================================================================================
' CONST_D3DRMINTERPOLATIONFLAGS enum
' ========================================================================================

%D3DRMINTERPOLATION_OPEN                                = 1            ' &H1
%D3DRMINTERPOLATION_CLOSED                              = 2            ' &H2
%D3DRMINTERPOLATION_NEAREST                             = 256          ' &H100
%D3DRMINTERPOLATION_LINEAR                              = 4            ' &H4
%D3DRMINTERPOLATION_SPLINE                              = 8            ' &H8
%D3DRMINTERPOLATION_VERTEXCOLOR                         = 64           ' &H40
%D3DRMINTERPOLATION_SLERPNORMALS                        = 128          ' &H80

' ========================================================================================
' CONST_D3DRMHANDEDNESS enum
' ========================================================================================

%D3DRMOPTIONS_LEFTHANDED                                = 1            ' &H1
%D3DRMOPTIONS_RIGHTHANDED                               = 2            ' &H2

' ========================================================================================
' CONST_D3DRMWIREFRAMEFLAGS enum
' ========================================================================================

%D3DRMWIREFRAME_CULL                                    = 1            ' &H1
%D3DRMWIREFRAME_HIDDENLINE                              = 2            ' &H2
%D3DRMWIREFRAME_CULLANDHIDELINES                        = 3            ' &H3

' ========================================================================================
' CONST_D3DRMCALLBACKORDERFLAGS enum
' ========================================================================================

%D3DRMCALLBACK_PREORDER                                 = 0            ' &H0
%D3DRMCALLBACK_POSTORDER                                = 1            ' &H1

' ========================================================================================
' CONST_D3DRMRENDERMODEFLAGS enum
' ========================================================================================

%D3DRMRENDERMODE_DEFAULT                                = 0            ' &H0
%D3DRMRENDERMODE_BLENDEDTRANSPARENCY                    = 1            ' &H1
%D3DRMRENDERMODE_SORTEDTRANSPARENCY                     = 2            ' &H2
%D3DRMRENDERMODE_LIGHTINMODELSPACE                      = 8            ' &H8
%D3DRMRENDERMODE_VIEWDEPENDENTSPECULAR                  = 16           ' &H10
%D3DRMRENDERMODE_DISABLESORTEDALPHAZWRITE               = 32           ' &H20

' ========================================================================================
' CONST_D3DRMPMESHSTATUSFLAGS enum
' ========================================================================================

%D3DRMPMESHSTATUS_VALID                                 = 1            ' &H1
%D3DRMPMESHSTATUS_INTERRUPTED                           = 2            ' &H2
%D3DRMPMESHSTATUS_BASEMESHCOMPLETE                      = 4            ' &H4
%D3DRMPMESHSTATUS_COMPLETE                              = 8            ' &H8
%D3DRMPMESHSTATUS_RENDERABLE                            = 16           ' &H10

' ========================================================================================
' CONST_D3DRMPMESHEVENTFLAGS enum
' ========================================================================================

%D3DRMPMESHEVENT_BASEMESH                               = 1            ' &H1
%D3DRMPMESHEVENT_COMPLETE                               = 2            ' &H2

' ========================================================================================
' CONST_D3DRMFPTFFLAGS enum
' ========================================================================================

%D3DRMFPTF_ALPHA                                        = 1            ' &H1
%D3DRMFPTF_NOALPHA                                      = 2            ' &H2
%D3DRMFPTF_PALETTIZED                                   = 4            ' &H4
%D3DRMFPTF_NOTPALETTIZED                                = 8            ' &H8

' ========================================================================================
' CONST_D3DRMMAPPINGFLAGS enum
' ========================================================================================

%D3DRMMAP_WRAPU                                         = 1            ' &H1
%D3DRMMAP_WRAPV                                         = 2            ' &H2
%D3DRMMAP_PERSPCORRECT                                  = 4            ' &H4

' ========================================================================================
' CONST_D3DRMSTATECHANGEFLAGS enum
' ========================================================================================

%D3DRMSTATECHANGE_UPDATEONLY                            = 1            ' &H1
%D3DRMSTATECHANGE_VOLATILE                              = 2            ' &H2
%D3DRMSTATECHANGE_NONVOLATILE                           = 4            ' &H4
%D3DRMSTATECHANGE_RENDER                                = 32           ' &H20
%D3DRMSTATECHANGE_LIGHT                                 = 64           ' &H40

' ========================================================================================
' CONST_D3DRMLOADFLAGS enum
' ========================================================================================

%D3DRMLOAD_FROMFILE                                     = 0            ' &H0
%D3DRMLOAD_FROMRESOURCE                                 = 1            ' &H1
%D3DRMLOAD_FROMMEMORY                                   = 2            ' &H2
%D3DRMLOAD_FROMSTREAM                                   = 4            ' &H4
%D3DRMLOAD_FROMUR                                       = 8            ' &H8
%D3DRMLOAD_BYNAME                                       = 16           ' &H10
%D3DRMLOAD_BYPOSITION                                   = 32           ' &H20
%D3DRMLOAD_BYGUID                                       = 64           ' &H40
%D3DRMLOAD_FIRST                                        = 128          ' &H80
%D3DRMLOAD_INSTANCEBYREFERENCE                          = 256          ' &H100
%D3DRMLOAD_INSTANCEBYCOPYING                            = 512          ' &H200
%D3DRMLOAD_ASYNCHRONOUS                                 = 1024         ' &H400

' ========================================================================================
' CONST_D3DRMSAVEFLAGS enum
' ========================================================================================

%D3DRMXOFSAVE_NORMALS                                   = 1            ' &H1
%D3DRMXOFSAVE_TEXTURECOORDINATES                        = 2            ' &H2
%D3DRMXOFSAVE_MATERIALS                                 = 4            ' &H4
%D3DRMXOFSAVE_TEXTURENAMES                              = 8            ' &H8
%D3DRMXOFSAVE_ALL                                       = 15           ' &HF
%D3DRMXOFSAVE_TEMPLATES                                 = 16           ' &H10
%D3DRMXOFSAVE_TEXTURETOPOLOGY                           = 32           ' &H20

' ========================================================================================
' CONST_D3DRMMATERIALOVERRIDEFLAGS enum
' ========================================================================================

%D3DRMMATERIALOVERRIDE_DIFFUSE_ALPHAONLY                = 1            ' &H1
%D3DRMMATERIALOVERRIDE_DIFFUSE_RGBONLY                  = 2            ' &H2
%D3DRMMATERIALOVERRIDE_DIFFUSE                          = 3            ' &H3
%D3DRMMATERIALOVERRIDE_AMBIENT                          = 4            ' &H4
%D3DRMMATERIALOVERRIDE_EMISSIVE                         = 8            ' &H8
%D3DRMMATERIALOVERRIDE_SPECULAR                         = 16           ' &H10
%D3DRMMATERIALOVERRIDE_POWER                            = 32           ' &H20
%D3DRMMATERIALOVERRIDE_TEXTURE                          = 64           ' &H40
%D3DRMMATERIALOVERRIDE_DIFFUSE_ALPHAMULTIPLY            = 128          ' &H80
%D3DRMMATERIALOVERRIDE_ALL                              = 255          ' &HFF

' ========================================================================================
' CONST_D3DSHADEMODE enum
' ========================================================================================

%D3DSHADE_FLAT                                          = 1            ' &H1
%D3DSHADE_GOURAUD                                       = 2            ' &H2
%D3DSHADE_PHONG                                         = 3            ' &H3

' ========================================================================================
' CONST_D3DFILLMODE enum
' ========================================================================================

%D3DFILL_POINT                                          = 1            ' &H1
%D3DFILL_WIREFRAME                                      = 2            ' &H2
%D3DFILL_SOLID                                          = 3            ' &H3

' ========================================================================================
' CONST_D3DBLEND enum
' ========================================================================================

%D3DBLEND_ZERO                                          = 1            ' &H1
%D3DBLEND_ONE                                           = 2            ' &H2
%D3DBLEND_SRCCOLOR                                      = 3            ' &H3
%D3DBLEND_INVSRCCOLOR                                   = 4            ' &H4
%D3DBLEND_SRCALPHA                                      = 5            ' &H5
%D3DBLEND_INVSRCALPHA                                   = 6            ' &H6
%D3DBLEND_DESTALPHA                                     = 7            ' &H7
%D3DBLEND_INVDESTALPHA                                  = 8            ' &H8
%D3DBLEND_DESTCOLOR                                     = 9            ' &H9
%D3DBLEND_INVDESTCOLOR                                  = 10           ' &HA
%D3DBLEND_SRCALPHASAT                                   = 11           ' &HB
%D3DBLEND_BOTHSRCALPHA                                  = 12           ' &HC
%D3DBLEND_BOTHINVSRCALPHA                               = 13           ' &HD

' ========================================================================================
' CONST_D3DTEXTUREADDRESS enum
' ========================================================================================

%D3DTADDRESS_WRAP                                       = 1            ' &H1
%D3DTADDRESS_MIRROR                                     = 2            ' &H2
%D3DTADDRESS_CLAMP                                      = 3            ' &H3
%D3DTADDRESS_BORDER                                     = 4            ' &H4

' ========================================================================================
' CONST_D3DCULL enum
' ========================================================================================

%D3DCULL_NONE                                           = 1            ' &H1
%D3DCULL_CW                                             = 2            ' &H2
%D3DCULL_CCW                                            = 3            ' &H3

' ========================================================================================
' CONST_D3DCMPFUNC enum
' ========================================================================================

%D3DCMP_NEVER                                           = 1            ' &H1
%D3DCMP_LESS                                            = 2            ' &H2
%D3DCMP_EQUAL                                           = 3            ' &H3
%D3DCMP_LESSEQUAL                                       = 4            ' &H4
%D3DCMP_GREATER                                         = 5            ' &H5
%D3DCMP_NOTEQUAL                                        = 6            ' &H6
%D3DCMP_GREATEREQUAL                                    = 7            ' &H7
%D3DCMP_ALWAYS                                          = 8            ' &H8

' ========================================================================================
' CONST_D3DSTENCILOP enum
' ========================================================================================

%D3DSTENCILOP_KEEP                                      = 1            ' &H1
%D3DSTENCILOP_ZERO                                      = 2            ' &H2
%D3DSTENCILOP_REPLACE                                   = 3            ' &H3
%D3DSTENCILOP_INCRSAT                                   = 4            ' &H4
%D3DSTENCILOP_DECRSAT                                   = 5            ' &H5
%D3DSTENCILOP_INVERT                                    = 6            ' &H6
%D3DSTENCILOP_INCR                                      = 7            ' &H7
%D3DSTENCILOP_DECR                                      = 8            ' &H8

' ========================================================================================
' CONST_D3DFOGMODE enum
' ========================================================================================

%D3DFOG_NONE                                            = 0            ' &H0
%D3DFOG_EXP                                             = 1            ' &H1
%D3DFOG_EXP2                                            = 2            ' &H2
%D3DFOG_LINEAR                                          = 3            ' &H3

' ========================================================================================
' CONST_D3DZBUFFERTYPE enum
' ========================================================================================

%D3DZB_FALSE                                            = 0            ' &H0
%D3DZB_TRUE                                             = 1            ' &H1
%D3DZB_USEW                                             = 2            ' &H2

' ========================================================================================
' CONST_D3DANTIALIASMODE enum
' ========================================================================================

%D3DANTIALIAS_NONE                                      = 0            ' &H0
%D3DANTIALIAS_SORTDEPENDENT                             = 1            ' &H1
%D3DANTIALIAS_SORTINDEPENDENT                           = 2            ' &H2

' ========================================================================================
' CONST_D3DPROCESSVERTICESFLAGS enum
' ========================================================================================

%D3DPV_DEFAULT                                          = 0            ' &H0
%D3DPV_DONOTCOPYDATA                                    = 1            ' &H1

' ========================================================================================
' CONST_D3DPRIMITIVETYPE enum
' ========================================================================================

%D3DPT_POINTLIST                                        = 1            ' &H1
%D3DPT_LINELIST                                         = 2            ' &H2
%D3DPT_LINESTRIP                                        = 3            ' &H3
%D3DPT_TRIANGLELIST                                     = 4            ' &H4
%D3DPT_TRIANGLESTRIP                                    = 5            ' &H5
%D3DPT_TRIANGLEFAN                                      = 6            ' &H6

' ========================================================================================
' CONST_D3DTRANSFORMSTATETYPE enum
' ========================================================================================

%D3DTRANSFORMSTATE_WORLD                                = 1            ' &H1
%D3DTRANSFORMSTATE_VIEW                                 = 2            ' &H2
%D3DTRANSFORMSTATE_PROJECTION                           = 3            ' &H3

' ========================================================================================
' CONST_D3DRENDERSTATETYPE enum
' ========================================================================================

%D3DRENDERSTATE_ANTIALIAS                               = 2            ' &H2
%D3DRENDERSTATE_TEXTUREPERSPECTIVE                      = 4            ' &H4
%D3DRENDERSTATE_ZENABLE                                 = 7            ' &H7
%D3DRENDERSTATE_FILLMODE                                = 8            ' &H8
%D3DRENDERSTATE_SHADEMODE                               = 9            ' &H9
%D3DRENDERSTATE_LINEPATTERN                             = 10           ' &HA
%D3DRENDERSTATE_ZWRITEENABLE                            = 14           ' &HE
%D3DRENDERSTATE_ALPHATESTENABLE                         = 15           ' &HF
%D3DRENDERSTATE_LASTPIXEL                               = 16           ' &H10
%D3DRENDERSTATE_SRCBLEND                                = 19           ' &H13
%D3DRENDERSTATE_DESTBLEND                               = 20           ' &H14
%D3DRENDERSTATE_CULLMODE                                = 22           ' &H16
%D3DRENDERSTATE_ZFUNC                                   = 23           ' &H17
%D3DRENDERSTATE_ALPHAREF                                = 24           ' &H18
%D3DRENDERSTATE_ALPHAFUNC                               = 25           ' &H19
%D3DRENDERSTATE_DITHERENABLE                            = 26           ' &H1A
%D3DRENDERSTATE_ALPHABLENDENABLE                        = 27           ' &H1B
%D3DRENDERSTATE_FOGENABLE                               = 28           ' &H1C
%D3DRENDERSTATE_SPECULARENABLE                          = 29           ' &H1D
%D3DRENDERSTATE_ZVISIBLE                                = 30           ' &H1E
%D3DRENDERSTATE_STIPPLEDALPHA                           = 33           ' &H21
%D3DRENDERSTATE_FOGCOLOR                                = 34           ' &H22
%D3DRENDERSTATE_FOGTABLEMODE                            = 35           ' &H23
%D3DRENDERSTATE_EDGEANTIALIAS                           = 40           ' &H28
%D3DRENDERSTATE_COLORKEYENABLE                          = 41           ' &H29
%D3DRENDERSTATE_ZBIAS                                   = 47           ' &H2F
%D3DRENDERSTATE_RANGEFOGENABLE                          = 48           ' &H30
%D3DRENDERSTATE_STENCILENABLE                           = 52           ' &H34
%D3DRENDERSTATE_STENCILFAIL                             = 53           ' &H35
%D3DRENDERSTATE_STENCILZFAIL                            = 54           ' &H36
%D3DRENDERSTATE_STENCILPASS                             = 55           ' &H37
%D3DRENDERSTATE_STENCILFUNC                             = 56           ' &H38
%D3DRENDERSTATE_STENCILREF                              = 57           ' &H39
%D3DRENDERSTATE_STENCILMASK                             = 58           ' &H3A
%D3DRENDERSTATE_STENCILWRITEMASK                        = 59           ' &H3B
%D3DRENDERSTATE_TEXTUREFACTOR                           = 60           ' &H3C
%D3DRENDERSTATE_WRAP0                                   = 128          ' &H80
%D3DRENDERSTATE_WRAP1                                   = 129          ' &H81
%D3DRENDERSTATE_WRAP2                                   = 130          ' &H82
%D3DRENDERSTATE_WRAP3                                   = 131          ' &H83
%D3DRENDERSTATE_WRAP4                                   = 132          ' &H84
%D3DRENDERSTATE_WRAP5                                   = 133          ' &H85
%D3DRENDERSTATE_WRAP6                                   = 134          ' &H86
%D3DRENDERSTATE_WRAP7                                   = 135          ' &H87
%D3DRENDERSTATE_CLIPPING                                = 136          ' &H88
%D3DRENDERSTATE_LIGHTING                                = 137          ' &H89
%D3DRENDERSTATE_EXTENTS                                 = 138          ' &H8A
%D3DRENDERSTATE_AMBIENT                                 = 139          ' &H8B
%D3DRENDERSTATE_FOGVERTEXMODE                           = 140          ' &H8C
%D3DRENDERSTATE_COLORVERTEX                             = 141          ' &H8D
%D3DRENDERSTATE_LOCALVIEWER                             = 142          ' &H8E
%D3DRENDERSTATE_NORMALIZENORMALS                        = 143          ' &H8F
%D3DRENDERSTATE_COLORKEYBLENDENABLE                     = 144          ' &H90
%D3DRENDERSTATE_DIFFUSEMATERIALSOURCE                   = 145          ' &H91
%D3DRENDERSTATE_SPECULARMATERIALSOURCE                  = 146          ' &H92
%D3DRENDERSTATE_AMBIENTMATERIALSOURCE                   = 147          ' &H93
%D3DRENDERSTATE_EMISSIVEMATERIALSOURCE                  = 148          ' &H94
%D3DRENDERSTATE_ALPHASOURCE                             = 149          ' &H95
%D3DRENDERSTATE_FOGFACTORSOURCE                         = 150          ' &H96
%D3DRENDERSTATE_VERTEXBLEND                             = 151          ' &H97
%D3DRENDERSTATE_CLIPPLANEENABLE                         = 152          ' &H98

' ========================================================================================
' CONST_D3DRENDERSTATESINGLE enum
' ========================================================================================

%D3DRENDERSTATE_FOGSTART                                = 36           ' &H24
%D3DRENDERSTATE_FOGEND                                  = 37           ' &H25
%D3DRENDERSTATE_FOGDENSITY                              = 38           ' &H26

' ========================================================================================
' CONST_DDLOCKFLAGS enum
' ========================================================================================

%DDLOCK_SURFACEMEMORYPTR                                = 0            ' &H0
%DDLOCK_WAIT                                            = 1            ' &H1
%DDLOCK_EVENT                                           = 2            ' &H2
%DDLOCK_READONLY                                        = 16           ' &H10
%DDLOCK_WRITEONLY                                       = 32           ' &H20
%DDLOCK_NOSYSLOCK                                       = 2048         ' &H800
%DDLOCK_DONOTWAIT                                       = 16384        ' &H4000

' ========================================================================================
' CONST_DDPCAPSFLAGS enum
' ========================================================================================

%DDPCAPS_4BIT                                           = 1            ' &H1
%DDPCAPS_8BITENTRIES                                    = 2            ' &H2
%DDPCAPS_8BIT                                           = 4            ' &H4
%DDPCAPS_INITIALIZE                                     = 8            ' &H8
%DDPCAPS_PRIMARYSURFACE                                 = 16           ' &H10
%DDPCAPS_PRIMARYSURFACELEFT                             = 32           ' &H20
%DDPCAPS_ALLOW256                                       = 64           ' &H40
%DDPCAPS_VSYNC                                          = 128          ' &H80
%DDPCAPS_1BIT                                           = 256          ' &H100
%DDPCAPS_2BIT                                           = 512          ' &H200
%DDPCAPS_ALPHA                                          = 1024         ' &H400

' ========================================================================================
' CONST_DDEDMFLAGS enum
' ========================================================================================

%DDEDM_DEFAULT                                          = 0            ' &H0
%DDEDM_REFRESHRATES                                     = 1            ' &H1
%DDEDM_STANDARDVGAMODES                                 = 2            ' &H2

' ========================================================================================
' CONST_DDSCLFLAGS enum
' ========================================================================================

%DDSCL_FULLSCREEN                                       = 1            ' &H1
%DDSCL_ALLOWREBOOT                                      = 2            ' &H2
%DDSCL_NOWINDOWCHANGES                                  = 4            ' &H4
%DDSCL_NORMAL                                           = 8            ' &H8
%DDSCL_EXCLUSIVE                                        = 16           ' &H10
%DDSCL_ALLOWMODEX                                       = 64           ' &H40
%DDSCL_CREATEDEVICEWINDOW                               = 512          ' &H200
%DDSCL_MULTITHREADED                                    = 1024         ' &H400
%DDSCL_SETDEVICEWINDOW                                  = 256          ' &H100
%DDSCL_SETFOCUSWINDOW                                   = 128          ' &H80

' ========================================================================================
' CONST_DDSDMFLAGS enum
' ========================================================================================

%DDSDM_DEFAULT                                          = 0            ' &H0
%DDSDM_STANDARDVGAMODE                                  = 1            ' &H1

' ========================================================================================
' CONST_DDBLTFLAGS enum
' ========================================================================================

%DDBLT_ASYNC                                            = 512          ' &H200
%DDBLT_COLORFILL                                        = 1024         ' &H400
%DDBLT_DDFX                                             = 2048         ' &H800
%DDBLT_DDROPS                                           = 4096         ' &H1000
%DDBLT_KEYDEST                                          = 8192         ' &H2000
%DDBLT_KEYDESTOVERRIDE                                  = 16384        ' &H4000
%DDBLT_KEYSRC                                           = 32768        ' &H8000
%DDBLT_KEYSRCOVERRIDE                                   = 65536        ' &H10000
%DDBLT_ROP                                              = 131072       ' &H20000
%DDBLT_ROTATIONANGLE                                    = 262144       ' &H40000
%DDBLT_WAIT                                             = 16777216     ' &H1000000
%DDBLT_DEPTHFILL                                        = 33554432     ' &H2000000
%DDBLT_DONOTWAIT                                        = 134217728    ' &H8000000

' ========================================================================================
' CONST_DDBLTFASTFLAGS enum
' ========================================================================================

%DDBLTFAST_NOCOLORKEY                                   = 0            ' &H0
%DDBLTFAST_SRCCOLORKEY                                  = 1            ' &H1
%DDBLTFAST_DESTCOLORKEY                                 = 2            ' &H2
%DDBLTFAST_WAIT                                         = 16           ' &H10
%DDBLTFAST_DONOTWAIT                                    = 32           ' &H20

' ========================================================================================
' CONST_DDFLIPFLAGS enum
' ========================================================================================

%DDFLIP_WAIT                                            = 1            ' &H1
%DDFLIP_EVEN                                            = 2            ' &H2
%DDFLIP_ODD                                             = 4            ' &H4
%DDFLIP_NOVSYNC                                         = 8            ' &H8
%DDFLIP_STEREO                                          = 16           ' &H10
%DDFLIP_DONOTWAIT                                       = 32           ' &H20
%DDFLIP_INTERFVAL2                                      = 536870912    ' &H20000000
%DDFLIP_INTERFVAL3                                      = 805306368    ' &H30000000
%DDFLIP_INTERFVAL4                                      = 1073741824   ' &H40000000

' ========================================================================================
' CONST_DDENUMOVERLAYZFLAGS enum
' ========================================================================================

%DDENUMOVERLAYZ_BACKTOFRONT                             = 0            ' &H0
%DDENUMOVERLAYZ_FRONTTOBACK                             = 1            ' &H1

' ========================================================================================
' CONST_DDOVERFLAGS enum
' ========================================================================================

%DDOVER_ALPHADEST                                       = 1            ' &H1
%DDOVER_ALPHADESTCONSTOVERRIDE                          = 2            ' &H2
%DDOVER_ALPHADESTNEG                                    = 4            ' &H4
%DDOVER_ALPHADESTSURFACEOVERRIDE                        = 8            ' &H8
%DDOVER_ALPHAEDGEBLEND                                  = 16           ' &H10
%DDOVER_ALPHASRC                                        = 32           ' &H20
%DDOVER_ALPHASRCCONSTOVERRIDE                           = 64           ' &H40
%DDOVER_ALPHASRCNEG                                     = 128          ' &H80
%DDOVER_ALPHASRCSURFACEOVERRIDE                         = 256          ' &H100
%DDOVER_HIDE                                            = 512          ' &H200
%DDOVER_KEYDEST                                         = 1024         ' &H400
%DDOVER_KEYDESTOVERRIDE                                 = 2048         ' &H800
%DDOVER_KEYSRC                                          = 4096         ' &H1000
%DDOVER_KEYSRCOVERRIDE                                  = 8192         ' &H2000
%DDOVER_SHOW                                            = 16384        ' &H4000
%DDOVER_ADDDIRTYRECT                                    = 32768        ' &H8000
%DDOVER_REFRESHDIRTYRECTS                               = 65536        ' &H10000
%DDOVER_REFRESHALL                                      = 131072       ' &H20000
%DDOVER_DDFX                                            = 524288       ' &H80000
%DDOVER_AUTOFLIP                                        = 1048576      ' &H100000
%DDOVER_BOB                                             = 2097152      ' &H200000
%DDOVER_OVERRIDEBOBWEAVE                                = 4194304      ' &H400000
%DDOVER_INTERLEAVED                                     = 8388608      ' &H800000
%DDOVER_ARGBSCALEFACTORS                                = 33554432     ' &H2000000
%DDOVER_DEGRADEARGBSCALING                              = 67108864     ' &H4000000

' ========================================================================================
' CONST_DDOVERZFLAGS enum
' ========================================================================================

%DDOVERZ_SENDTOFRONT                                    = 0            ' &H0
%DDOVERZ_SENDTOBACK                                     = 1            ' &H1
%DDOVERZ_MOVEFORWARD                                    = 2            ' &H2
%DDOVERZ_MOVEBACKWARD                                   = 3            ' &H3
%DDOVERZ_INSERTINFRONTOF                                = 4            ' &H4
%DDOVERZ_INSERTINBACKOF                                 = 5            ' &H5

' ========================================================================================
' CONST_DDGFSFLAGS enum
' ========================================================================================

%DDGFS_CANFLIP                                          = 1            ' &H1
%DDGFS_ISFLIPDONE                                       = 2            ' &H2

' ========================================================================================
' CONST_DDGBSFLAGS enum
' ========================================================================================

%DDGBS_CANBLT                                           = 1            ' &H1
%DDGBS_ISBLTDONE                                        = 2            ' &H2

' ========================================================================================
' CONST_DDCKEYFLAGS enum
' ========================================================================================

%DDCKEY_COLORSPACE                                      = 1            ' &H1
%DDCKEY_DESTBLT                                         = 2            ' &H2
%DDCKEY_DESTOVERLAY                                     = 4            ' &H4
%DDCKEY_SRCBLT                                          = 8            ' &H8
%DDCKEY_SRCOVERLAY                                      = 16           ' &H10

' ========================================================================================
' CONST_DDSGRFLAGS enum
' ========================================================================================

%DDSGR_DEFAULT                                          = 0            ' &H0
%DDSGR_CALIBRATE                                        = 1            ' &H1

' ========================================================================================
' CONST_DBOOLFLAGS enum
' ========================================================================================

%D_FALSE                                                = 0            ' &H0
%D_TRUE                                                 = 1            ' &H1

' ========================================================================================
' CONST_DDBITDEPTHFLAGS enum
' ========================================================================================

%DDBD_1                                                 = 16384        ' &H4000
%DDBD_2                                                 = 8192         ' &H2000
%DDBD_4                                                 = 4096         ' &H1000
%DDBD_8                                                 = 2048         ' &H800
%DDBD_16                                                = 1024         ' &H400
%DDBD_24                                                = 512          ' &H200
%DDBD_32                                                = 256          ' &H100

' ========================================================================================
' CONST_DDSURFACEDESCFLAGS enum
' ========================================================================================

%DDSD_CAPS                                              = 1            ' &H1
%DDSD_HEIGHT                                            = 2            ' &H2
%DDSD_WIDTH                                             = 4            ' &H4
%DDSD_PITCH                                             = 8            ' &H8
%DDSD_BACKBUFFERCOUNT                                   = 32           ' &H20
%DDSD_ZBUFFERBITDEPTH                                   = 64           ' &H40
%DDSD_ALPHABITDEPTH                                     = 128          ' &H80
%DDSD_TEXTURESTAGE                                      = 1048576      ' &H100000
%DDSD_LPSURFACE                                         = 2048         ' &H800
%DDSD_PIXELFORMAT                                       = 4096         ' &H1000
%DDSD_CKDESTOVERLAY                                     = 8192         ' &H2000
%DDSD_CKDESTBLT                                         = 16384        ' &H4000
%DDSD_CKSRCOVERLAY                                      = 32768        ' &H8000
%DDSD_CKSRCBLT                                          = 65536        ' &H10000
%DDSD_MIPMAPCOUNT                                       = 131072       ' &H20000
%DDSD_REFRESHRATE                                       = 262144       ' &H40000
%DDSD_LINEARSIZE                                        = 524288       ' &H80000
%DDSD_ALL                                               = 1047022      ' &HFF9EE

' ========================================================================================
' CONST_DDCOLORFLAGS enum
' ========================================================================================

%DDCOLOR_BRIGHTNESS                                     = 1            ' &H1
%DDCOLOR_CONTRAST                                       = 2            ' &H2
%DDCOLOR_HUE                                            = 4            ' &H4
%DDCOLOR_SATURATION                                     = 8            ' &H8
%DDCOLOR_SHARPNESS                                      = 16           ' &H10
%DDCOLOR_GAMMA                                          = 32           ' &H20
%DDCOLOR_COLORENABLE                                    = 64           ' &H40

' ========================================================================================
' CONST_DDSURFACECAPSFLAGS enum
' ========================================================================================

%DDSCAPS_ALPHA                                          = 2            ' &H2
%DDSCAPS_BACKBUFFER                                     = 4            ' &H4
%DDSCAPS_COMPLEX                                        = 8            ' &H8
%DDSCAPS_FLIP                                           = 16           ' &H10
%DDSCAPS_FRONTBUFFER                                    = 32           ' &H20
%DDSCAPS_OFFSCREENPLAIN                                 = 64           ' &H40
%DDSCAPS_OVERLAY                                        = 128          ' &H80
%DDSCAPS_PALETTE                                        = 256          ' &H100
%DDSCAPS_PRIMARYSURFACE                                 = 512          ' &H200
%DDSCAPS_PRIMARYSURFACELEFT                             = 1024         ' &H400
%DDSCAPS_SYSTEMMEMORY                                   = 2048         ' &H800
%DDSCAPS_TEXTURE                                        = 4096         ' &H1000
%DDSCAPS_3DDEVICE                                       = 8192         ' &H2000
%DDSCAPS_VIDEOMEMORY                                    = 16384        ' &H4000
%DDSCAPS_VISIBLE                                        = 32768        ' &H8000
%DDSCAPS_WRITEONLY                                      = 65536        ' &H10000
%DDSCAPS_ZBUFFER                                        = 131072       ' &H20000
%DDSCAPS_OWNDC                                          = 262144       ' &H40000
%DDSCAPS_LIVEVIDEO                                      = 524288       ' &H80000
%DDSCAPS_HWCODEC                                        = 1048576      ' &H100000
%DDSCAPS_MODEX                                          = 2097152      ' &H200000
%DDSCAPS_MIPMAP                                         = 4194304      ' &H400000
%DDSCAPS_RESERVED2                                      = 8388608      ' &H800000
%DDSCAPS_ALLOCONLOAD                                    = 67108864     ' &H4000000
%DDSCAPS_VIDEOPORT                                      = 134217728    ' &H8000000
%DDSCAPS_LOCALVIDMEM                                    = 268435456    ' &H10000000
%DDSCAPS_NONLOCALVIDMEM                                 = 536870912    ' &H20000000
%DDSCAPS_STANDARDVGAMODE                                = 1073741824   ' &H40000000
%DDSCAPS_OPTIMIZED                                      = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DDSURFACECAPS2FLAGS enum
' ========================================================================================

%DDSCAPS2_HARDWAREDEINTERLACE                           = 2            ' &H2
%DDSCAPS2_HINTDYNAMIC                                   = 4            ' &H4
%DDSCAPS2_HINTSTATIC                                    = 8            ' &H8
%DDSCAPS2_TEXTUREMANAGE                                 = 16           ' &H10
%DDSCAPS2_OPAQUE                                        = 128          ' &H80
%DDSCAPS2_HINTANTIALIASING                              = 256          ' &H100
%DDSCAPS2_CUBEMAP                                       = 512          ' &H200
%DDSCAPS2_CUBEMAP_POSITIVEX                             = 1024         ' &H400
%DDSCAPS2_CUBEMAP_NEGATIVEX                             = 2048         ' &H800
%DDSCAPS2_CUBEMAP_POSITIVEY                             = 4096         ' &H1000
%DDSCAPS2_CUBEMAP_NEGATIVEY                             = 8192         ' &H2000
%DDSCAPS2_CUBEMAP_POSITIVEZ                             = 16384        ' &H4000
%DDSCAPS2_CUBEMAP_NEGATIVEZ                             = 32768        ' &H8000
%DDSCAPS2_CUBEMAP_ALLFACES                              = 65024        ' &HFE00
%DDSCAPS2_MIPMAPSUBLEVEL                                = 65536        ' &H10000
%DDSCAPS2_D3DTEXTUREMANAGE                              = 131072       ' &H20000
%DDSCAPS2_STEREOSURFACELEFT                             = 524288       ' &H80000

' ========================================================================================
' CONST_DDCAPS1FLAGS enum
' ========================================================================================

%DDCAPS_3D                                              = 1            ' &H1
%DDCAPS_ALIGNBOUNDARYDEST                               = 2            ' &H2
%DDCAPS_ALIGNSIZEDEST                                   = 4            ' &H4
%DDCAPS_ALIGNBOUNDARYSRC                                = 8            ' &H8
%DDCAPS_ALIGNSIZESRC                                    = 16           ' &H10
%DDCAPS_ALIGNSTRIDE                                     = 32           ' &H20
%DDCAPS_BLT                                             = 64           ' &H40
%DDCAPS_BLTQUEUE                                        = 128          ' &H80
%DDCAPS_BLTFOURCC                                       = 256          ' &H100
%DDCAPS_BLTSTRETCH                                      = 512          ' &H200
%DDCAPS_GDI                                             = 1024         ' &H400
%DDCAPS_OVERLAY                                         = 2048         ' &H800
%DDCAPS_OVERLAYCANTCLIP                                 = 4096         ' &H1000
%DDCAPS_OVERLAYFOURCC                                   = 8192         ' &H2000
%DDCAPS_OVERLAYSTRETCH                                  = 16384        ' &H4000
%DDCAPS_PALETTE                                         = 32768        ' &H8000
%DDCAPS_PALETTEVSYNC                                    = 65536        ' &H10000
%DDCAPS_READSCANLINE                                    = 131072       ' &H20000
%DDCAPS_STEREOVIEW                                      = 262144       ' &H40000
%DDCAPS_VBI                                             = 524288       ' &H80000
%DDCAPS_ZBLTS                                           = 1048576      ' &H100000
%DDCAPS_ZOVERLAYS                                       = 2097152      ' &H200000
%DDCAPS_COLORKEY                                        = 4194304      ' &H400000
%DDCAPS_ALPHA                                           = 8388608      ' &H800000
%DDCAPS_COLORKEYHWASSIST                                = 16777216     ' &H1000000
%DDCAPS_NOHARDWARE                                      = 33554432     ' &H2000000
%DDCAPS_BLTCOLORFILL                                    = 67108864     ' &H4000000
%DDCAPS_BANKSWITCHED                                    = 134217728    ' &H8000000
%DDCAPS_BLTDEPTHFILL                                    = 268435456    ' &H10000000
%DDCAPS_CANCLIP                                         = 536870912    ' &H20000000
%DDCAPS_CANCLIPSTRETCHED                                = 1073741824   ' &H40000000
%DDCAPS_CANBLTSYSMEM                                    = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DDCAPS2FLAGS enum
' ========================================================================================

%DDCAPS2_CERTIFIED                                      = 1            ' &H1
%DDCAPS2_NO2DDURING3DSCENE                              = 2            ' &H2
%DDCAPS2_VIDEOPORT                                      = 4            ' &H4
%DDCAPS2_AUTOFLIPOVERLAY                                = 8            ' &H8
%DDCAPS2_CANBOBINTERLEAVED                              = 16           ' &H10
%DDCAPS2_CANBOBNONINTERLEAVED                           = 32           ' &H20
%DDCAPS2_COLORCONTROLOVERLAY                            = 64           ' &H40
%DDCAPS2_COLORCONTROLPRIMARY                            = 128          ' &H80
%DDCAPS2_CANDROPZ16BIT                                  = 256          ' &H100
%DDCAPS2_NONLOCALVIDMEM                                 = 512          ' &H200
%DDCAPS2_NONLOCALVIDMEMCAPS                             = 1024         ' &H400
%DDCAPS2_NOPAGELOCKREQUIRED                             = 2048         ' &H800
%DDCAPS2_WIDESURFACES                                   = 4096         ' &H1000
%DDCAPS2_CANFLIPODDEVEN                                 = 8192         ' &H2000
%DDCAPS2_CANBOBHARDWARE                                 = 16384        ' &H4000
%DDCAPS2_COPYFOURCC                                     = 32768        ' &H8000
%DDCAPS2_PRIMARYGAMMA                                   = 131072       ' &H20000
%DDCAPS2_CANRENDERWINDOWED                              = 524288       ' &H80000
%DDCAPS2_CANCALIBRATEGAMMA                              = 1048576      ' &H100000
%DDCAPS2_FLIPINTERVAL                                   = 2097152      ' &H200000
%DDCAPS2_FLIPNOVSYNC                                    = 4194304      ' &H400000
%DDCAPS2_CANMANAGETEXTURE                               = 8388608      ' &H800000
%DDCAPS2_STEREO                                         = 33554432     ' &H2000000

' ========================================================================================
' CONST_DDFXCAPSFLAGS enum
' ========================================================================================

%DDFXCAPS_BLTARITHSTRETCHY                              = 32           ' &H20
%DDFXCAPS_BLTARITHSTRETCHYN                             = 16           ' &H10
%DDFXCAPS_BLTMIRRORLEFTRIGHT                            = 64           ' &H40
%DDFXCAPS_BLTMIRRORUPDOWN                               = 128          ' &H80
%DDFXCAPS_BLTROTATION                                   = 256          ' &H100
%DDFXCAPS_BLTROTATION90                                 = 512          ' &H200
%DDFXCAPS_BLTSHRINKX                                    = 1024         ' &H400
%DDFXCAPS_BLTSHRINKXN                                   = 2048         ' &H800
%DDFXCAPS_BLTSHRINKY                                    = 4096         ' &H1000
%DDFXCAPS_BLTSHRINKYN                                   = 8192         ' &H2000
%DDFXCAPS_BLTSTRETCHX                                   = 16384        ' &H4000
%DDFXCAPS_BLTSTRETCHXN                                  = 32768        ' &H8000
%DDFXCAPS_BLTSTRETCHY                                   = 65536        ' &H10000
%DDFXCAPS_BLTSTRETCHYN                                  = 131072       ' &H20000
%DDFXCAPS_OVERLAYARITHSTRETCHY                          = 262144       ' &H40000
%DDFXCAPS_OVERLAYARITHSTRETCHYN                         = 8            ' &H8
%DDFXCAPS_OVERLAYSHRINKX                                = 524288       ' &H80000
%DDFXCAPS_OVERLAYSHRINKXN                               = 1048576      ' &H100000
%DDFXCAPS_OVERLAYSHRINKY                                = 2097152      ' &H200000
%DDFXCAPS_OVERLAYSHRINKYN                               = 4194304      ' &H400000
%DDFXCAPS_OVERLAYSTRETCHX                               = 8388608      ' &H800000
%DDFXCAPS_OVERLAYSTRETCHXN                              = 16777216     ' &H1000000
%DDFXCAPS_OVERLAYSTRETCHY                               = 33554432     ' &H2000000
%DDFXCAPS_OVERLAYSTRETCHYN                              = 67108864     ' &H4000000
%DDFXCAPS_OVERLAYMIRRORLEFTRIGHT                        = 134217728    ' &H8000000
%DDFXCAPS_OVERLAYMIRRORUPDOWN                           = 268435456    ' &H10000000
%DDFXCAPS_BLTALPHA                                      = 1            ' &H1
%DDFXCAPS_BLTTRANSFORM                                  = 2            ' &H2
%DDFXCAPS_BLTFILTER                                     = 32           ' &H20
%DDFXCAPS_OVERLAYALPHA                                  = 4            ' &H4
%DDFXCAPS_OVERLAYTRANSFORM                              = 536870912    ' &H20000000
%DDFXCAPS_OVERLAYFILTER                                 = 262144       ' &H40000

' ========================================================================================
' CONST_DDSTEREOCAPSFLAGS enum
' ========================================================================================

%DDSVCAPS_ENIGMA                                        = 1            ' &H1
%DDSVCAPS_FLICKER                                       = 2            ' &H2
%DDSVCAPS_REDBLUE                                       = 4            ' &H4
%DDSVCAPS_SPLIT                                         = 8            ' &H8
%DDSVCAPS_STEREOSEQUENTIAL                              = 16           ' &H10

' ========================================================================================
' CONST_DDCKEYCAPSFLAGS enum
' ========================================================================================

%DDCKEYCAPS_DESTBLT                                     = 1            ' &H1
%DDCKEYCAPS_DESTBLTCLRSPACE                             = 2            ' &H2
%DDCKEYCAPS_DESTBLTCLRSPACEYUV                          = 4            ' &H4
%DDCKEYCAPS_DESTBLTYUV                                  = 8            ' &H8
%DDCKEYCAPS_DESTOVERLAY                                 = 16           ' &H10
%DDCKEYCAPS_DESTOVERLAYCLRSPACE                         = 32           ' &H20
%DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV                      = 64           ' &H40
%DDCKEYCAPS_DESTOVERLAYONEACTIVE                        = 128          ' &H80
%DDCKEYCAPS_DESTOVERLAYYUV                              = 256          ' &H100
%DDCKEYCAPS_SRCBLT                                      = 512          ' &H200
%DDCKEYCAPS_SRCBLTCLRSPACE                              = 1024         ' &H400
%DDCKEYCAPS_SRCBLTCLRSPACEYUV                           = 2048         ' &H800
%DDCKEYCAPS_SRCBLTYUV                                   = 4096         ' &H1000
%DDCKEYCAPS_SRCOVERLAY                                  = 8192         ' &H2000
%DDCKEYCAPS_SRCOVERLAYCLRSPACE                          = 16384        ' &H4000
%DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV                       = 32768        ' &H8000
%DDCKEYCAPS_SRCOVERLAYONEACTIVE                         = 65536        ' &H10000
%DDCKEYCAPS_SRCOVERLAYYUV                               = 131072       ' &H20000
%DDCKEYCAPS_NOCOSTOVERLAY                               = 262144       ' &H40000

' ========================================================================================
' CONST_DDPIXELFORMATFLAGS enum
' ========================================================================================

%DDPF_ALPHAPIXELS                                       = 1            ' &H1
%DDPF_ALPHA                                             = 2            ' &H2
%DDPF_FOURCC                                            = 4            ' &H4
%DDPF_PALETTEINDEXED4                                   = 8            ' &H8
%DDPF_PALETTEINDEXEDTO8                                 = 16           ' &H10
%DDPF_PALETTEINDEXED8                                   = 32           ' &H20
%DDPF_RGB                                               = 64           ' &H40
%DDPF_COMPRESSED                                        = 128          ' &H80
%DDPF_RGBTOYUV                                          = 256          ' &H100
%DDPF_YUV                                               = 512          ' &H200
%DDPF_ZBUFFER                                           = 1024         ' &H400
%DDPF_PALETTEINDEXED1                                   = 2048         ' &H800
%DDPF_PALETTEINDEXED2                                   = 4096         ' &H1000
%DDPF_ZPIXELS                                           = 8192         ' &H2000
%DDPF_STENCILBUFFER                                     = 16384        ' &H4000
%DDPF_ALPHAPREMULT                                      = 32768        ' &H8000
%DDPF_LUMINANCE                                         = 131072       ' &H20000
%DDPF_BUMPLUMINANCE                                     = 262144       ' &H40000
%DDPF_BUMPDUDV                                          = 524288       ' &H80000

' ========================================================================================
' CONST_DDENUMSURFACESFLAGS enum
' ========================================================================================

%DDENUMSURFACES_ALL                                     = 1            ' &H1
%DDENUMSURFACES_MATCH                                   = 2            ' &H2
%DDENUMSURFACES_NOMATCH                                 = 4            ' &H4
%DDENUMSURFACES_CANBECREATED                            = 8            ' &H8
%DDENUMSURFACES_DOESEXIST                               = 16           ' &H10

' ========================================================================================
' CONST_DDRAW enum
' ========================================================================================

%DD_ROP_SPACE                                           = 8            ' &H8

' ========================================================================================
' CONST_DDBLTFXFLAGS enum
' ========================================================================================

%DDBLTFX_ARITHSTRETCHY                                  = 1            ' &H1
%DDBLTFX_MIRRORLEFTRIGHT                                = 2            ' &H2
%DDBLTFX_MIRRORUPDOWN                                   = 4            ' &H4
%DDBLTFX_NOTEARING                                      = 8            ' &H8
%DDBLTFX_ROTATE180                                      = 16           ' &H10
%DDBLTFX_ROTATE270                                      = 32           ' &H20
%DDBLTFX_ROTATE90                                       = 64           ' &H40
%DDBLTFX_ZBUFFERRANGE                                   = 128          ' &H80
%DDBLTFX_ZBUFFERBASEDEST                                = 256          ' &H100

' ========================================================================================
' CONST_DDWAITVBFLAGS enum
' ========================================================================================

%DDWAITVB_BLOCKBEGIN                                    = 1            ' &H1
%DDWAITVB_BLOCKBEGINEVENT                               = 2            ' &H2
%DDWAITVB_BLOCKEND                                      = 4            ' &H4

' ========================================================================================
' CONST_DIENUMDEVICESFLAGS enum
' ========================================================================================

%DIEDFL_ALLDEVICES                                      = 0            ' &H0
%DIEDFL_ATTACHEDONLY                                    = 1            ' &H1
%DIEDFL_FORCEFEEDBACK                                   = 256          ' &H100
%DIEDFL_INCLUDEALIASES                                  = 65536        ' &H10000
%DIEDFL_INCLUDEPHANTOMS                                 = 131072       ' &H20000

' ========================================================================================
' CONST_DIDEVICETYPE enum
' ========================================================================================

%DIDEVTYPE_DEVICE                                       = 1            ' &H1
%DIDEVTYPE_MOUSE                                        = 2            ' &H2
%DIDEVTYPE_KEYBOARD                                     = 3            ' &H3
%DIDEVTYPE_JOYSTICK                                     = 4            ' &H4
%DIDEVTYPE_HID                                          = 65536        ' &H10000
%DIDEVTYPEMOUSE_UNKNOWN                                 = 256          ' &H100
%DIDEVTYPEMOUSE_TRADITIONAL                             = 512          ' &H200
%DIDEVTYPEMOUSE_FINGERSTICK                             = 768          ' &H300
%DIDEVTYPEMOUSE_TOUCHPAD                                = 1024         ' &H400
%DIDEVTYPEMOUSE_TRACKBALL                               = 1280         ' &H500
%DIDEVTYPEKEYBOARD_UNKNOWN                              = 0            ' &H0
%DIDEVTYPEKEYBOARD_PCXT                                 = 256          ' &H100
%DIDEVTYPEKEYBOARD_OLIVETTI                             = 512          ' &H200
%DIDEVTYPEKEYBOARD_PCAT                                 = 768          ' &H300
%DIDEVTYPEKEYBOARD_PCENH                                = 1024         ' &H400
%DIDEVTYPEKEYBOARD_NOKIA1050                            = 1280         ' &H500
%DIDEVTYPEKEYBOARD_NOKIA9140                            = 1536         ' &H600
%DIDEVTYPEKEYBOARD_NEC98                                = 1792         ' &H700
%DIDEVTYPEKEYBOARD_NEC98LAPTOP                          = 2048         ' &H800
%DIDEVTYPEKEYBOARD_NEC98106                             = 2304         ' &H900
%DIDEVTYPEKEYBOARD_JAPAN106                             = 2560         ' &HA00
%DIDEVTYPEKEYBOARD_JAPANAX                              = 2816         ' &HB00
%DIDEVTYPEKEYBOARD_J3100                                = 3072         ' &HC00
%DIDEVTYPEJOYSTICK_UNKNOWN                              = 256          ' &H100
%DIDEVTYPEJOYSTICK_TRADITIONAL                          = 512          ' &H200
%DIDEVTYPEJOYSTICK_FLIGHTSTICK                          = 768          ' &H300
%DIDEVTYPEJOYSTICK_GAMEPAD                              = 1024         ' &H400
%DIDEVTYPEJOYSTICK_RUDDER                               = 1280         ' &H500
%DIDEVTYPEJOYSTICK_WHEEL                                = 1536         ' &H600
%DIDEVTYPEJOYSTICK_HEADTRACKER                          = 1792         ' &H700

' ========================================================================================
' CONST_DIDFTFLAGS enum
' ========================================================================================

%DIDFT_ALL                                              = 0            ' &H0
%DIDFT_RELAXIS                                          = 1            ' &H1
%DIDFT_ABSAXIS                                          = 2            ' &H2
%DIDFT_AXIS                                             = 3            ' &H3
%DIDFT_PSHBUTTON                                        = 4            ' &H4
%DIDFT_TGLBUTTON                                        = 8            ' &H8
%DIDFT_BUTTON                                           = 12           ' &HC
%DIDFT_POV                                              = 16           ' &H10
%DIDFT_COLLECTION                                       = 64           ' &H40
%DIDFT_NODATA                                           = 128          ' &H80
%DIDFT_ANYINSTANCE                                      = 16776960     ' &HFFFF00
%DIDFT_INSTANCEMASK                                     = 16776960     ' &HFFFF00
%DIDFT_FFACTUATOR                                       = 16777216     ' &H1000000
%DIDFT_FFEFFECTTRIGGER                                  = 33554432     ' &H2000000
%DIDFT_NOCOLLECTION                                     = 16776960     ' &HFFFF00

' ========================================================================================
' CONST_DIDGDDFLAGS enum
' ========================================================================================

%DIGDD_DEFAULT                                          = 0            ' &H0
%DIGDD_PEEK                                             = 1            ' &H1

' ========================================================================================
' CONST_DIPHFLAGS enum
' ========================================================================================

%DIPH_DEVICE                                            = 0            ' &H0
%DIPH_BYOFFSET                                          = 1            ' &H1
%DIPH_BYID                                              = 2            ' &H2

' ========================================================================================
' CONST_DISCLFLAGS enum
' ========================================================================================

%DISCL_EXCLUSIVE                                        = 1            ' &H1
%DISCL_NONEXCLUSIVE                                     = 2            ' &H2
%DISCL_FOREGROUND                                       = 4            ' &H4
%DISCL_BACKGROUND                                       = 8            ' &H8

' ========================================================================================
' CONST_DIDEVCAPSFLAGS enum
' ========================================================================================

%DIDC_ATTACHED                                          = 1            ' &H1
%DIDC_POLLEDDEVICE                                      = 2            ' &H2
%DIDC_EMULATED                                          = 4            ' &H4
%DIDC_POLLEDDATAFORMAT                                  = 8            ' &H8
%DIDC_FORCEFEEDBACK                                     = 256          ' &H100
%DIDC_FFATTACK                                          = 512          ' &H200
%DIDC_FFFADE                                            = 1024         ' &H400
%DIDC_SATURATION                                        = 2048         ' &H800
%DIDC_POSNEGCOEFFICIENTS                                = 4096         ' &H1000
%DIDC_POSNEGSATURATION                                  = 8192         ' &H2000
%DIDC_DEADBAND                                          = 16384        ' &H4000
%DIDC_ALIAS                                             = 65536        ' &H10000
%DIDC_PHANTOM                                           = 131072       ' &H20000

' ========================================================================================
' CONST_DIDATAFORMATFLAGS enum
' ========================================================================================

%DIDF_ABSAXIS                                           = 1            ' &H1
%DIDF_RELAXIS                                           = 2            ' &H2

' ========================================================================================
' CONST_DIDEVICEOBJINSTANCEFLAGS enum
' ========================================================================================

%DIDOI_FFACTUATOR                                       = 1            ' &H1
%DIDOI_FFEFFECTTRIGGER                                  = 2            ' &H2
%DIDOI_POLLED                                           = 32768        ' &H8000
%DIDOI_ASPECTPOSITION                                   = 256          ' &H100
%DIDOI_ASPECTVELOCITY                                   = 512          ' &H200
%DIDOI_ASPECTACCEL                                      = 768          ' &H300
%DIDOI_ASPECTFORCE                                      = 1024         ' &H400
%DIDOI_ASPECTMASK                                       = 3840         ' &HF00

' ========================================================================================
' CONST_DIKEYFLAGS enum
' ========================================================================================

%DIK_ESCAPE                                             = 1            ' &H1
%DIK_1                                                  = 2            ' &H2
%DIK_2                                                  = 3            ' &H3
%DIK_3                                                  = 4            ' &H4
%DIK_4                                                  = 5            ' &H5
%DIK_5                                                  = 6            ' &H6
%DIK_6                                                  = 7            ' &H7
%DIK_7                                                  = 8            ' &H8
%DIK_8                                                  = 9            ' &H9
%DIK_9                                                  = 10           ' &HA
%DIK_0                                                  = 11           ' &HB
%DIK_MINUS                                              = 12           ' &HC
%DIK_EQUALS                                             = 13           ' &HD
%DIK_BACK                                               = 14           ' &HE
%DIK_TAB                                                = 15           ' &HF
%DIK_Q                                                  = 16           ' &H10
%DIK_W                                                  = 17           ' &H11
%DIK_E                                                  = 18           ' &H12
%DIK_R                                                  = 19           ' &H13
%DIK_T                                                  = 20           ' &H14
%DIK_Y                                                  = 21           ' &H15
%DIK_U                                                  = 22           ' &H16
%DIK_I                                                  = 23           ' &H17
%DIK_O                                                  = 24           ' &H18
%DIK_P                                                  = 25           ' &H19
%DIK_LBRACKET                                           = 26           ' &H1A
%DIK_RBRACKET                                           = 27           ' &H1B
%DIK_RETURN                                             = 28           ' &H1C
%DIK_LCONTROL                                           = 29           ' &H1D
%DIK_A                                                  = 30           ' &H1E
%DIK_S                                                  = 31           ' &H1F
%DIK_D                                                  = 32           ' &H20
%DIK_F                                                  = 33           ' &H21
%DIK_G                                                  = 34           ' &H22
%DIK_H                                                  = 35           ' &H23
%DIK_J                                                  = 36           ' &H24
%DIK_K                                                  = 37           ' &H25
%DIK_L                                                  = 38           ' &H26
%DIK_SEMICOLON                                          = 39           ' &H27
%DIK_APOSTROPHE                                         = 40           ' &H28
%DIK_GRAVE                                              = 41           ' &H29
%DIK_LSHIFT                                             = 42           ' &H2A
%DIK_BACKSLASH                                          = 43           ' &H2B
%DIK_Z                                                  = 44           ' &H2C
%DIK_X                                                  = 45           ' &H2D
%DIK_C                                                  = 46           ' &H2E
%DIK_V                                                  = 47           ' &H2F
%DIK_B                                                  = 48           ' &H30
%DIK_N                                                  = 49           ' &H31
%DIK_M                                                  = 50           ' &H32
%DIK_COMMA                                              = 51           ' &H33
%DIK_PERIOD                                             = 52           ' &H34
%DIK_SLASH                                              = 53           ' &H35
%DIK_RSHIFT                                             = 54           ' &H36
%DIK_MULTIPLY                                           = 55           ' &H37
%DIK_LMENU                                              = 56           ' &H38
%DIK_SPACE                                              = 57           ' &H39
%DIK_CAPITAL                                            = 58           ' &H3A
%DIK_F1                                                 = 59           ' &H3B
%DIK_F2                                                 = 60           ' &H3C
%DIK_F3                                                 = 61           ' &H3D
%DIK_F4                                                 = 62           ' &H3E
%DIK_F5                                                 = 63           ' &H3F
%DIK_F6                                                 = 64           ' &H40
%DIK_F7                                                 = 65           ' &H41
%DIK_F8                                                 = 66           ' &H42
%DIK_F9                                                 = 67           ' &H43
%DIK_F10                                                = 68           ' &H44
%DIK_NUMLOCK                                            = 69           ' &H45
%DIK_SCROLL                                             = 70           ' &H46
%DIK_NUMPAD7                                            = 71           ' &H47
%DIK_NUMPAD8                                            = 72           ' &H48
%DIK_NUMPAD9                                            = 73           ' &H49
%DIK_SUBTRACT                                           = 74           ' &H4A
%DIK_NUMPAD4                                            = 75           ' &H4B
%DIK_NUMPAD5                                            = 76           ' &H4C
%DIK_NUMPAD6                                            = 77           ' &H4D
%DIK_ADD                                                = 78           ' &H4E
%DIK_NUMPAD1                                            = 79           ' &H4F
%DIK_NUMPAD2                                            = 80           ' &H50
%DIK_NUMPAD3                                            = 81           ' &H51
%DIK_NUMPAD0                                            = 82           ' &H52
%DIK_DECIMAL                                            = 83           ' &H53
%DIK_F11                                                = 87           ' &H57
%DIK_F12                                                = 88           ' &H58
%DIK_F13                                                = 100          ' &H64
%DIK_F14                                                = 101          ' &H65
%DIK_F15                                                = 102          ' &H66
%DIK_KANA                                               = 112          ' &H70
%DIK_CONVERT                                            = 121          ' &H79
%DIK_NOCONVERT                                          = 123          ' &H7B
%DIK_YEN                                                = 125          ' &H7D
%DIK_NUMPADEQUALS                                       = 141          ' &H8D
%DIK_CIRCUMFLEX                                         = 144          ' &H90
%DIK_AT                                                 = 145          ' &H91
%DIK_COLON                                              = 146          ' &H92
%DIK_UNDERLINE                                          = 147          ' &H93
%DIK_KANJI                                              = 148          ' &H94
%DIK_STOP                                               = 149          ' &H95
%DIK_AX                                                 = 150          ' &H96
%DIK_UNLABELED                                          = 151          ' &H97
%DIK_NUMPADENTER                                        = 156          ' &H9C
%DIK_RCONTROL                                           = 157          ' &H9D
%DIK_NUMPADCOMMA                                        = 179          ' &HB3
%DIK_DIVIDE                                             = 181          ' &HB5
%DIK_SYSRQ                                              = 183          ' &HB7
%DIK_RMENU                                              = 184          ' &HB8
%DIK_PAUSE                                              = 197          ' &HC5
%DIK_HOME                                               = 199          ' &HC7
%DIK_UP                                                 = 200          ' &HC8
%DIK_PRIOR                                              = 201          ' &HC9
%DIK_LEFT                                               = 203          ' &HCB
%DIK_RIGHT                                              = 205          ' &HCD
%DIK_END                                                = 207          ' &HCF
%DIK_DOWN                                               = 208          ' &HD0
%DIK_NEXT                                               = 209          ' &HD1
%DIK_INSERT                                             = 210          ' &HD2
%DIK_DELETE                                             = 211          ' &HD3
%DIK_LWIN                                               = 219          ' &HDB
%DIK_RWIN                                               = 220          ' &HDC
%DIK_APPS                                               = 221          ' &HDD

' ========================================================================================
' CONST_DINPUT enum
' ========================================================================================

%DIPROPRANGE_NOMIN                                      = -2147483648  ' &H80000000
%DIPROPRANGE_NOMAX                                      = 2147483647   ' &H7FFFFFFF
%DIPROPAXISMODE_ABS                                     = 0            ' &H0
%DIPROPAXISMODE_REL                                     = 1            ' &H1
%DIPROPCALIBRATIONMODE_COOKED                           = 0            ' &H0
%DIPROPCALIBRATIONMODE_RAW                              = 1            ' &H1
%DIPROPAUTOCENTER_OFF                                   = 0            ' &H0
%DIPROPAUTOCENTER_ON                                    = 1            ' &H1
%DIEB_NOTRIGGER                                         = -1           ' &HFFFFFFFF

' ========================================================================================
' CONST_DSSCLFLAGS enum
' ========================================================================================

%DSSCL_NORMAL                                           = 1            ' &H1
%DSSCL_PRIORITY                                         = 2            ' &H2
%DSSCL_EXCLUSIVE                                        = 3            ' &H3
%DSSCL_WRITEPRIMARY                                     = 4            ' &H4

' ========================================================================================
' CONST_DSSPEAKERFLAGS enum
' ========================================================================================

%DSSPEAKER_HEADPHONE                                    = 1            ' &H1
%DSSPEAKER_MONO                                         = 2            ' &H2
%DSSPEAKER_QUAD                                         = 3            ' &H3
%DSSPEAKER_STEREO                                       = 4            ' &H4
%DSSPEAKER_SURROUND                                     = 5            ' &H5
%DSSPEAKER_GEOMETRY_MIN                                 = 5            ' &H5
%DSSPEAKER_GEOMETRY_NARROW                              = 10           ' &HA
%DSSPEAKER_GEOMETRY_WIDE                                = 20           ' &H14
%DSSPEAKER_GEOMETRY_MAX                                 = 180          ' &HB4

' ========================================================================================
' CONST_DSBPLAYFLAGS enum
' ========================================================================================

%DSBPLAY_DEFAULT                                        = 0            ' &H0
%DSBPLAY_LOOPING                                        = 1            ' &H1

' ========================================================================================
' CONST_DSBLOCKFLAGS enum
' ========================================================================================

%DSBLOCK_DEFAULT                                        = 0            ' &H0
%DSBLOCK_FROMWRITECURSOR                                = 1            ' &H1
%DSBLOCK_ENTIREBUFFER                                   = 2            ' &H2

' ========================================================================================
' CONST_DSCBLOCKFLAGS enum
' ========================================================================================

%DSCBLOCK_DEFAULT                                       = 0            ' &H0
%DSCBLOCK_ENTIREBUFFER                                  = 1            ' &H1

' ========================================================================================
' CONST_DSBSTATUSFLAGS enum
' ========================================================================================

%DSBSTATUS_PLAYING                                      = 1            ' &H1
%DSBSTATUS_BUFFERLOST                                   = 2            ' &H2
%DSBSTATUS_LOOPING                                      = 4            ' &H4

' ========================================================================================
' CONST_DS3DAPPLYFLAGS enum
' ========================================================================================

%DS3D_IMMEDIATE                                         = 0            ' &H0
%DS3D_DEFERRED                                          = 1            ' &H1

' ========================================================================================
' CONST_DS3DMODEFLAGS enum
' ========================================================================================

%DS3DMODE_NORMAL                                        = 0            ' &H0
%DS3DMODE_HEADRELATIVE                                  = 1            ' &H1
%DS3DMODE_DISABLE                                       = 2            ' &H2

' ========================================================================================
' CONST_DSCBSTATUSFLAGS enum
' ========================================================================================

%DSCBSTATUS_CAPTURING                                   = 1            ' &H1
%DSCBSTATUS_LOOPING                                     = 2            ' &H2

' ========================================================================================
' CONST_DSCBSTARTFLAGS enum
' ========================================================================================

%DSCBSTART_DEFAULT                                      = 0            ' &H0
%DSCBSTART_LOOPING                                      = 1            ' &H1

' ========================================================================================
' CONST_DSCAPSFLAGS enum
' ========================================================================================

%DSCAPS_PRIMARYMONO                                     = 1            ' &H1
%DSCAPS_PRIMARYSTEREO                                   = 2            ' &H2
%DSCAPS_PRIMARY8BIT                                     = 4            ' &H4
%DSCAPS_PRIMARY16BIT                                    = 8            ' &H8
%DSCAPS_CONTINUOUSRATE                                  = 16           ' &H10
%DSCAPS_EMULDRIVER                                      = 32           ' &H20
%DSCAPS_CERTIFIED                                       = 64           ' &H40
%DSCAPS_SECONDARYMONO                                   = 256          ' &H100
%DSCAPS_SECONDARYSTEREO                                 = 512          ' &H200
%DSCAPS_SECONDARY8BIT                                   = 1024         ' &H400
%DSCAPS_SECONDARY16BIT                                  = 2048         ' &H800

' ========================================================================================
' CONST_DSBCAPSFLAGS enum
' ========================================================================================

%DSBCAPS_PRIMARYBUFFER                                  = 1            ' &H1
%DSBCAPS_STATIC                                         = 2            ' &H2
%DSBCAPS_LOCHARDWARE                                    = 4            ' &H4
%DSBCAPS_LOCSOFTWARE                                    = 8            ' &H8
%DSBCAPS_CTRL3D                                         = 16           ' &H10
%DSBCAPS_CTRLFREQUENCY                                  = 32           ' &H20
%DSBCAPS_CTRLPAN                                        = 64           ' &H40
%DSBCAPS_CTRLVOLUME                                     = 128          ' &H80
%DSBCAPS_CTRLPOSITIONNOTIFY                             = 256          ' &H100
%DSBCAPS_STICKYFOCUS                                    = 16384        ' &H4000
%DSBCAPS_GLOBALFOCUS                                    = 32768        ' &H8000
%DSBCAPS_GETCURRENTPOSITION2                            = 65536        ' &H10000
%DSBCAPS_MUTE3DATMAXDISTANCE                            = 131072       ' &H20000

' ========================================================================================
' CONST_DSCBCAPSFLAGS enum
' ========================================================================================

%DSCBCAPS_DEFAULT                                       = 0            ' &H0
%DSCBCAPS_WAVEMAPPED                                    = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DSCCAPSFLAGS enum
' ========================================================================================

%DSCCAPS_DEFAULT                                        = 0            ' &H0
%DSCCAPS_EMULDRIVER                                     = 32           ' &H20

' ========================================================================================
' CONST_DSOUND enum
' ========================================================================================

%DS3D_MINDISTANCEFACTOR                                 = 0            ' &H0
%DS3D_MAXDISTANCEFACTOR                                 = 10           ' &HA
%DS3D_DEFAULTDISTANCEFACTOR                             = 1            ' &H1
%DS3D_MINROLLOFFFACTOR                                  = 0            ' &H0
%DS3D_MAXROLLOFFFACTOR                                  = 10           ' &HA
%DS3D_DEFAULTROLLOFFFACTOR                              = 1            ' &H1
%DS3D_MINDOPPLERFACTOR                                  = 0            ' &H0
%DS3D_MAXDOPPLERFACTOR                                  = 10           ' &HA
%DS3D_DEFAULTDOPPLERFACTOR                              = 1            ' &H1
%DS3D_DEFAULTMINDISTANCE                                = 1            ' &H1
%DS3D_DEFAULTMAXDISTANCE                                = 1000000000   ' &H3B9ACA00
%DS3D_MINCONEANGLE                                      = 0            ' &H0
%DS3D_MAXCONEANGLE                                      = 360          ' &H168
%DS3D_DEFAULTCONEANGLE                                  = 360          ' &H168
%DS3D_DEFAULTCONEOUTSIDEVOLUME                          = 0            ' &H0
%DSBFREQUENCY_MIN                                       = 100          ' &H64
%DSBFREQUENCY_MAX                                       = 100000       ' &H186A0
%DSBFREQUENCY_ORIGINAL                                  = 0            ' &H0
%DSBPAN_LEFT                                            = -10000       ' &HFFFFD8F0
%DSBPAN_CENTER                                          = 0            ' &H0
%DSBPAN_RIGHT                                           = 10000        ' &H2710
%DSBVOLUME_MIN                                          = -10000       ' &HFFFFD8F0
%DSBVOLUME_MAX                                          = 0            ' &H0
%DSBSIZE_MIN                                            = 4            ' &H4
%DSBSIZE_MAX                                            = 268435455    ' &HFFFFFFF
%DSBPN_OFFSETSTOP                                       = -1           ' &HFFFFFFFF
%WAVE_FORMAT_PCM                                        = 1            ' &H1

' ========================================================================================
' CONST_D3DTEXTURESTAGESTATETYPE enum
' ========================================================================================

%D3DTSS_COLOROP                                         = 1            ' &H1
%D3DTSS_COLORARG1                                       = 2            ' &H2
%D3DTSS_COLORARG2                                       = 3            ' &H3
%D3DTSS_ALPHAOP                                         = 4            ' &H4
%D3DTSS_ALPHAARG1                                       = 5            ' &H5
%D3DTSS_ALPHAARG2                                       = 6            ' &H6
%D3DTSS_TEXCOORDINDEX                                   = 11           ' &HB
%D3DTSS_ADDRESS                                         = 12           ' &HC
%D3DTSS_ADDRESSU                                        = 13           ' &HD
%D3DTSS_ADDRESSV                                        = 14           ' &HE
%D3DTSS_BORDERCOLOR                                     = 15           ' &HF
%D3DTSS_MAGFILTER                                       = 16           ' &H10
%D3DTSS_MINFILTER                                       = 17           ' &H11
%D3DTSS_MIPFILTER                                       = 18           ' &H12
%D3DTSS_MAXMIPLEVEL                                     = 20           ' &H14
%D3DTSS_MAXANISOTROPY                                   = 21           ' &H15
%D3DTSS_TEXTURETRANSFORMFLAGS                           = 24           ' &H18

' ========================================================================================
' CONST_D3DTEXCOORDINDEXFLAGS enum
' ========================================================================================

%D3DTSS_TCI_CAMERASPACENORMAL                           = 65536        ' &H10000
%D3DTSS_TCI_CAMERASPACEPOSITION                         = 131072       ' &H20000
%D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR                 = 196608       ' &H30000
%D3DTSS_TCI_PASSTHRU                                    = 0            ' &H0

' ========================================================================================
' CONST_D3DTEXTURESTAGESINGLE enum
' ========================================================================================

%D3DTSS_BUMPENVMAT00                                    = 7            ' &H7
%D3DTSS_BUMPENVMAT01                                    = 8            ' &H8
%D3DTSS_BUMPENVMAT10                                    = 9            ' &H9
%D3DTSS_BUMPENVMAT11                                    = 10           ' &HA
%D3DTSS_MIPMAPLODBIAS                                   = 19           ' &H13
%D3DTSS_BUMPENVLSCALE                                   = 22           ' &H16
%D3DTSS_BUMPENVLOFFSET                                  = 23           ' &H17

' ========================================================================================
' CONST_D3DTEXTUREOP enum
' ========================================================================================

%D3DTOP_DISABLE                                         = 1            ' &H1
%D3DTOP_SELECTARG1                                      = 2            ' &H2
%D3DTOP_SELECTARG2                                      = 3            ' &H3
%D3DTOP_MODULATE                                        = 4            ' &H4
%D3DTOP_MODULATE2X                                      = 5            ' &H5
%D3DTOP_MODULATE4X                                      = 6            ' &H6
%D3DTOP_ADD                                             = 7            ' &H7
%D3DTOP_ADDSIGNED                                       = 8            ' &H8
%D3DTOP_ADDSIGNED2X                                     = 9            ' &H9
%D3DTOP_SUBTRACT                                        = 10           ' &HA
%D3DTOP_ADDSMOOTH                                       = 11           ' &HB
%D3DTOP_BLENDDIFFUSEALPHA                               = 12           ' &HC
%D3DTOP_BLENDTEXTUREALPHA                               = 13           ' &HD
%D3DTOP_BLENDFACTORALPHA                                = 14           ' &HE
%D3DTOP_BLENDTEXTUREALPHAPM                             = 15           ' &HF
%D3DTOP_BLENDCURRENTALPHA                               = 16           ' &H10
%D3DTOP_PREMODULATE                                     = 17           ' &H11
%D3DTOP_MODULATEALPHA_ADDCOLOR                          = 18           ' &H12
%D3DTOP_MODULATECOLOR_ADDALPHA                          = 19           ' &H13
%D3DTOP_MODULATEINVALPHA_ADDCOLOR                       = 20           ' &H14
%D3DTOP_MODULATEINVCOLOR_ADDALPHA                       = 21           ' &H15
%D3DTOP_BUMPENVMAP                                      = 22           ' &H16
%D3DTOP_BUMPENVMAPLUMINANCE                             = 23           ' &H17
%D3DTOP_DOTPRODUCT3                                     = 24           ' &H18

' ========================================================================================
' CONST_D3DTEXTUREMAGFILTER enum
' ========================================================================================

%D3DTFG_POINT                                           = 1            ' &H1
%D3DTFG_LINEAR                                          = 2            ' &H2
%D3DTFG_FLATCUBIC                                       = 3            ' &H3
%D3DTFG_GAUSSIANCUBIC                                   = 4            ' &H4
%D3DTFG_ANISOTROPIC                                     = 5            ' &H5

' ========================================================================================
' CONST_D3DTEXTUREMINFILTER enum
' ========================================================================================

%D3DTFN_POINT                                           = 1            ' &H1
%D3DTFN_LINEAR                                          = 2            ' &H2
%D3DTFN_ANISOTROPIC                                     = 3            ' &H3

' ========================================================================================
' CONST_D3DTEXTUREMIPFILTER enum
' ========================================================================================

%D3DTFP_NONE                                            = 1            ' &H1
%D3DTFP_POINT                                           = 2            ' &H2
%D3DTFP_LINEAR                                          = 3            ' &H3

' ========================================================================================
' CONST_DSETUPFLAGS enum
' ========================================================================================

%DSETUP_DDRAWDRV                                        = 8            ' &H8
%DSETUP_DSOUNDDRV                                       = 16           ' &H10
%DSETUP_DXCORE                                          = 65536        ' &H10000
%DSETUP_DIRECTX                                         = 65560        ' &H10018
%DSETUP_TESTINSTALL                                     = 131072       ' &H20000

' ========================================================================================
' CONST_DSETUPCALLBACKFLAGS enum
' ========================================================================================

%DSETUP_CB_MSG_NOMESSAGE                                = 0            ' &H0
%DSETUP_CB_MSG_CANTINSTALL_UNKNOWNOS                    = 1            ' &H1
%DSETUP_CB_MSG_CANTINSTALL_NT                           = 2            ' &H2
%DSETUP_CB_MSG_CANTINSTALL_BETA                         = 3            ' &H3
%DSETUP_CB_MSG_CANTINSTALL_NOTWIN32                     = 4            ' &H4
%DSETUP_CB_MSG_CANTINSTALL_WRONGLANGUAGE                = 5            ' &H5
%DSETUP_CB_MSG_CANTINSTALL_WRONGPLATFORM                = 6            ' &H6
%DSETUP_CB_MSG_PREINSTALL_NT                            = 7            ' &H7
%DSETUP_CB_MSG_NOTPREINSTALLEDONNT                      = 8            ' &H8
%DSETUP_CB_MSG_SETUP_INIT_FAILED                        = 9            ' &H9
%DSETUP_CB_MSG_INTERNAL_ERROR                           = 10           ' &HA
%DSETUP_CB_MSG_CHECK_DRIVER_UPGRADE                     = 11           ' &HB
%DSETUP_CB_MSG_OUTOFDISKSPACE                           = 12           ' &HC
%DSETUP_CB_MSG_BEGIN_INSTALL                            = 13           ' &HD
%DSETUP_CB_MSG_BEGIN_INSTALL_RUNTIME                    = 14           ' &HE
%DSETUP_CB_MSG_BEGIN_INSTALL_DRIVERS                    = 15           ' &HF
%DSETUP_CB_MSG_BEGIN_RESTORE_DRIVERS                    = 16           ' &H10
%DSETUP_CB_MSG_FILECOPYERROR                            = 17           ' &H11
%DSETUP_CB_UPGRADE_TYPE_MASK                            = 15           ' &HF
%DSETUP_CB_UPGRADE_KEEP                                 = 1            ' &H1
%DSETUP_CB_UPGRADE_SAFE                                 = 2            ' &H2
%DSETUP_CB_UPGRADE_FORCE                                = 4            ' &H4
%DSETUP_CB_UPGRADE_UNKNOWN                              = 8            ' &H8
%DSETUP_CB_UPGRADE_HASWARNINGS                          = 256          ' &H100
%DSETUP_CB_UPGRADE_CANTBACKUP                           = 512          ' &H200
%DSETUP_CB_UPGRADE_DEVICE_ACTIVE                        = 2048         ' &H800
%DSETUP_CB_UPGRADE_DEVICE_DISPLAY                       = 4096         ' &H1000
%DSETUP_CB_UPGRADE_DEVICE_MEDIA                         = 8192         ' &H2000

' ========================================================================================
' CONST_D3DRMANIMATIONFLAGS enum
' ========================================================================================

%D3DRMANIMATION_OPEN                                    = 1            ' &H1
%D3DRMANIMATION_CLOSED                                  = 2            ' &H2
%D3DRMANIMATION_LINEARPOSITION                          = 4            ' &H4
%D3DRMANIMATION_SPLINEPOSITION                          = 8            ' &H8
%D3DRMANIMATION_SCALEANDROTATION                        = 16           ' &H10
%D3DRMANIMATION_POSITION                                = 32           ' &H20

' ========================================================================================
' CONST_D3DRMANIMATIONKEYFLAGS enum
' ========================================================================================

%D3DRMANIMATION_ROTATEKEY                               = 1            ' &H1
%D3DRMANIMATION_SCALEKEY                                = 2            ' &H2
%D3DRMANIMATION_POSITIONKEY                             = 3            ' &H3

' ========================================================================================
' CONST_DPGROUPFLAGS enum
' ========================================================================================

%DPGROUP_DEFAULT                                        = 0            ' &H0
%DPGROUP_LOCAL                                          = 8            ' &H8
%DPGROUP_STAGINGAREA                                    = 2048         ' &H800
%DPGROUP_HIDDEN                                         = 4096         ' &H1000

' ========================================================================================
' CONST_DPPLAYERFLAGS enum
' ========================================================================================

%DPPLAYER_DEFAULT                                       = 0            ' &H0
%DPPLAYER_SERVERPLAYER                                  = 256          ' &H100
%DPPLAYER_SPECTATOR                                     = 512          ' &H200
%DPPLAYER_LOCAL                                         = 8            ' &H8

' ========================================================================================
' CONST_DPENUMCONNECTIONFLAGS enum
' ========================================================================================

%DPCONNECTION_DIRECTPLAY                                = 1            ' &H1
%DPCONNECTION_DIRECTPLAYLOBBY                           = 2            ' &H2

' ========================================================================================
' CONST_DPCONNECTFLAGS enum
' ========================================================================================

%DPCONNECTION_DEFAULT                                   = 0            ' &H0
%DPCONNECTION_RETURNSTATUS                              = 128          ' &H80

' ========================================================================================
' CONST_DPENUMPLAYERFLAGS enum
' ========================================================================================

%DPENUMPLAYERS_ALL                                      = 0            ' &H0
%DPENUMPLAYERS_LOCAL                                    = 8            ' &H8
%DPENUMPLAYERS_REMOTE                                   = 16           ' &H10
%DPENUMPLAYERS_GROUP                                    = 32           ' &H20
%DPENUMPLAYERS_SESSION                                  = 128          ' &H80
%DPENUMPLAYERS_SERVERPLAYER                             = 256          ' &H100
%DPENUMPLAYERS_SPECTATOR                                = 512          ' &H200
%DPENUMPLAYERS_OWNER                                    = 8192         ' &H2000

' ========================================================================================
' CONST_DPENUMGROUPFLAGS enum
' ========================================================================================

%DPENUMGROUPS_ALL                                       = 0            ' &H0
%DPENUMGROUPS_HIDDEN                                    = 4096         ' &H1000
%DPENUMGROUPS_LOCAL                                     = 8            ' &H8
%DPENUMGROUPS_REMOTE                                    = 16           ' &H10
%DPENUMGROUPS_SESSION                                   = 128          ' &H80
%DPENUMGROUPS_STAGINGAREA                               = 2048         ' &H800
%DPENUMGROUPS_SHORTCUT                                  = 1024         ' &H400

' ========================================================================================
' CONST_DPENUMSESSIONFLAGS enum
' ========================================================================================

%DPENUMSESSIONS_ALL                                     = 2            ' &H2
%DPENUMSESSIONS_ASYNC                                   = 16           ' &H10
%DPENUMSESSIONS_AVAILABLE                               = 1            ' &H1
%DPENUMSESSIONS_PASSWORDREQUIRED                        = 64           ' &H40
%DPENUMSESSIONS_RETURNSTATUS                            = 128          ' &H80
%DPENUMSESSIONS_STOPASYNC                               = 16           ' &H10

' ========================================================================================
' CONST_DPGETCAPSFLAGS enum
' ========================================================================================

%DPGETCAPS_DEFAULT                                      = 0            ' &H0
%DPGETCAPS_GUARANTEED                                   = 1            ' &H1

' ========================================================================================
' CONST_DPGETFLAGS enum
' ========================================================================================

%DPGET_REMOTE                                           = 0            ' &H0
%DPGET_LOCAL                                            = 1            ' &H1

' ========================================================================================
' CONST_DPSETFLAGS enum
' ========================================================================================

%DPSET_REMOTE                                           = 0            ' &H0
%DPSET_LOCAL                                            = 1            ' &H1
%DPSET_GUARANTEED                                       = 2            ' &H2

' ========================================================================================
' CONST_DPMESSAGEQUEUEFLAGS enum
' ========================================================================================

%DPMESSAGEQUEUE_SEND                                    = 1            ' &H1
%DPMESSAGEQUEUE_RECEIVE                                 = 2            ' &H2

' ========================================================================================
' CONST_DPOPENFLAGS enum
' ========================================================================================

%DPOPEN_JOIN                                            = 1            ' &H1
%DPOPEN_CREATE                                          = 2            ' &H2
%DPOPEN_RETURNSTATUS                                    = 128          ' &H80

' ========================================================================================
' CONST_DPRECEIVEFLAGS enum
' ========================================================================================

%DPRECEIVE_ALL                                          = 1            ' &H1
%DPRECEIVE_PEEK                                         = 8            ' &H8
%DPRECEIVE_TOPLAYER                                     = 2            ' &H2
%DPRECEIVE_FROMPLAYER                                   = 4            ' &H4

' ========================================================================================
' CONST_DPSENDFLAGS enum
' ========================================================================================

%DPSEND_DEFAULT                                         = 0            ' &H0
%DPSEND_GUARANTEED                                      = 1            ' &H1
%DPSEND_SIGNED                                          = 32           ' &H20
%DPSEND_ENCRYPTED                                       = 64           ' &H40
%DPSEND_NOSENDCOMPLETEMSG                               = 1024         ' &H400
%DPSEND_ASYNC                                           = 512          ' &H200

' ========================================================================================
' CONST_DPLMSG enum
' ========================================================================================

%DPLMSG_SYSTEM                                          = 1            ' &H1
%DPLMSG_STANDARD                                        = 2            ' &H2
%DPLMSG_USERDEFINED                                     = 0            ' &H0

' ========================================================================================
' CONST_DPLWAIT enum
' ========================================================================================

%DPLWAIT_DEFAULT                                        = 0            ' &H0
%DPLWAIT_CANCEL                                         = 1            ' &H1

' ========================================================================================
' CONST_DPIDFLAGS enum
' ========================================================================================

%DPID_SYSMSG                                            = 0            ' &H0
%DPID_ALLPLAYERS                                        = 0            ' &H0
%DPID_SERVERPLAYER                                      = 1            ' &H1
%DPID_UNKNOWN                                           = -1           ' &HFFFFFFFF

' ========================================================================================
' CONST_DPSESSIONFLAGS enum
' ========================================================================================

%DPSESSION_NEWPLAYERSDISABLED                           = 1            ' &H1
%DPSESSION_MIGRATEHOST                                  = 4            ' &H4
%DPSESSION_NOMESSAGEID                                  = 8            ' &H8
%DPSESSION_JOINDISABLED                                 = 32           ' &H20
%DPSESSION_KEEPALIVE                                    = 64           ' &H40
%DPSESSION_NODATAMESSAGES                               = 128          ' &H80
%DPSESSION_SECURESERVER                                 = 256          ' &H100
%DPSESSION_PRIVATE                                      = 512          ' &H200
%DPSESSION_PASSWORDREQUIRED                             = 1024         ' &H400
%DPSESSION_MULTICASTSERVER                              = 2048         ' &H800
%DPSESSION_CLIENTSERVER                                 = 4096         ' &H1000
%DPSESSION_DIRECTPLAYPROTOCOL                           = 8192         ' &H2000
%DPSESSION_NOPRESERVEORDER                              = 16384        ' &H4000
%DPSESSION_OPTIMIZELATENCY                              = 32768        ' &H8000

' ========================================================================================
' CONST_DPLCONNECTIONFLAGS enum
' ========================================================================================

%DPLCONNECTION_CREATESESSION                            = 2            ' &H2
%DPLCONNECTION_JOINSESSION                              = 1            ' &H1

' ========================================================================================
' CONST_DPSYSMSGTYPES enum
' ========================================================================================

%DPSYS_CREATEPLAYERORGROUP                              = 3            ' &H3
%DPSYS_DESTROYPLAYERORGROUP                             = 5            ' &H5
%DPSYS_ADDPLAYERTOGROUP                                 = 7            ' &H7
%DPSYS_DELETEPLAYERFROMGROUP                            = 33           ' &H21
%DPSYS_SESSIONLOST                                      = 49           ' &H31
%DPSYS_HOST                                             = 257          ' &H101
%DPSYS_SETPLAYERORGROUPDATA                             = 258          ' &H102
%DPSYS_SETPLAYERORGROUPNAME                             = 259          ' &H103
%DPSYS_SETSESSIONDESC                                   = 260          ' &H104
%DPSYS_ADDGROUPTOGROUP                                  = 261          ' &H105
%DPSYS_DELETEGROUPFROMGROUP                             = 262          ' &H106
%DPSYS_SECUREMESSAGE                                    = 263          ' &H107
%DPSYS_STARTSESSION                                     = 264          ' &H108
%DPSYS_CHAT                                             = 265          ' &H109
%DPSYS_SETGROUPOWNER                                    = 266          ' &H10A
%DPSYS_SENDCOMPLETE                                     = 269          ' &H10D
%DPLSYS_CONNECTIONSETTINGSREAD                          = 1            ' &H1
%DPLSYS_DPLAYCONNECTFAILED                              = 2            ' &H2
%DPLSYS_DPLAYCONNECTSUCCEEDED                           = 3            ' &H3
%DPLSYS_APPTERMINATED                                   = 4            ' &H4
%DPLSYS_SETPROPERTY                                     = 5            ' &H5
%DPLSYS_SETPROPERTYRESPONSE                             = 6            ' &H6
%DPLSYS_GETPROPERTY                                     = 7            ' &H7
%DPLSYS_GETPROPERTYRESPONSE                             = 8            ' &H8
%DPLSYS_NEWCONNECTIONSETTINGS                           = 10           ' &HA
%DPLSYS_NEWSESSIONHOST                                  = 9            ' &H9

' ========================================================================================
' CONST_DPPLAYERTYPEFLAGS enum
' ========================================================================================

%DPPLAYERTYPE_GROUP                                     = 0            ' &H0
%DPPLAYERTYPE_PLAYER                                    = 1            ' &H1

' ========================================================================================
' CONST_D3DSTENCILCAPSFLAGS enum
' ========================================================================================

%D3DSTENCILCAPS_KEEP                                    = 1            ' &H1
%D3DSTENCILCAPS_ZERO                                    = 2            ' &H2
%D3DSTENCILCAPS_REPLACE                                 = 4            ' &H4
%D3DSTENCILCAPS_INCRSAT                                 = 8            ' &H8
%D3DSTENCILCAPS_DECRSAT                                 = 16           ' &H10
%D3DSTENCILCAPS_INVERT                                  = 32           ' &H20
%D3DSTENCILCAPS_INCR                                    = 64           ' &H40
%D3DSTENCILCAPS_DECR                                    = 128          ' &H80

' ========================================================================================
' CONST_WAVEFORMATFLAGS enum
' ========================================================================================

%WAVE_FORMAT_1M08                                       = 1            ' &H1
%WAVE_FORMAT_1S08                                       = 2            ' &H2
%WAVE_FORMAT_1M16                                       = 4            ' &H4
%WAVE_FORMAT_1S16                                       = 8            ' &H8
%WAVE_FORMAT_2M08                                       = 16           ' &H10
%WAVE_FORMAT_2S08                                       = 32           ' &H20
%WAVE_FORMAT_2M16                                       = 64           ' &H40
%WAVE_FORMAT_2S16                                       = 128          ' &H80
%WAVE_FORMAT_4M08                                       = 256          ' &H100
%WAVE_FORMAT_4S08                                       = 512          ' &H200
%WAVE_FORMAT_4M16                                       = 1024         ' &H400
%WAVE_FORMAT_4S16                                       = 2048         ' &H800

' ========================================================================================
' CONST_DPCAPSFLAGS enum
' ========================================================================================

%DPCAPS_ASYNCCANCELSUPPORTED                            = 4096         ' &H1000
%DPCAPS_ASYNCCANCELALLSUPPORTED                         = 8192         ' &H2000
%DPCAPS_SENDTIMEOUTSUPPORTED                            = 16384        ' &H4000
%DPCAPS_SENDPRIORITYSUPPORTED                           = 32768        ' &H8000
%DPCAPS_ASYNCSUPPORTED                                  = 65536        ' &H10000
%DPCAPS_ISHOST                                          = 2            ' &H2
%DPCAPS_GROUPOPTIMIZED                                  = 8            ' &H8
%DPCAPS_KEEPALIVEOPTIMIZED                              = 16           ' &H10
%DPCAPS_GUARANTEEDOPTIMIZED                             = 32           ' &H20
%DPCAPS_GUARANTEEDSUPPORTED                             = 64           ' &H40
%DPCAPS_SIGNINGSUPPORTED                                = 128          ' &H80
%DPCAPS_ENCRYPTIONSUPPORTED                             = 256          ' &H100

' ========================================================================================
' CONST_DSETUPERR enum
' ========================================================================================

%DSETUPERR_SUCCESS_RESTART                              = 1            ' &H1
%DSETUPERR_SUCCESS                                      = 0            ' &H0
%DSETUPERR_BADWINDOWSVERSION                            = -1           ' &HFFFFFFFF
%DSETUPERR_SOURCEFILENOTFOUND                           = -2           ' &HFFFFFFFE
%DSETUPERR_BADSOURCESIZE                                = -3           ' &HFFFFFFFD
%DSETUPERR_BADSOURCETIME                                = -4           ' &HFFFFFFFC
%DSETUPERR_NOCOPY                                       = -5           ' &HFFFFFFFB
%DSETUPERR_OUTOFDISKSPACE                               = -6           ' &HFFFFFFFA
%DSETUPERR_CANTFINDINF                                  = -7           ' &HFFFFFFF9
%DSETUPERR_CANTFINDDIR                                  = -8           ' &HFFFFFFF8
%DSETUPERR_INTERNAL                                     = -9           ' &HFFFFFFF7
%DSETUPERR_NTWITHNO3D                                   = -10          ' &HFFFFFFF6
%DSETUPERR_UNKNOWNOS                                    = -11          ' &HFFFFFFF5
%DSETUPERR_USERHITCANCEL                                = -12          ' &HFFFFFFF4
%DSETUPERR_NOTPREINSTALLEDONNT                          = -13          ' &HFFFFFFF3

' ========================================================================================
' CONST_DSOUNDERR enum
' ========================================================================================

%DS_OK                                                  = 0            ' &H0
%DSERR_ALLOCATED                                        = -2005401590  ' &H8878000A
%DSERR_CONTROLUNAVAIL                                   = -2005401570  ' &H8878001E
%DSERR_INVALIDPARAM                                     = -2147024809  ' &H80070057
%DSERR_INVALIDCALL                                      = -2005401550  ' &H88780032
%DSERR_GENERIC                                          = -2147467259  ' &H80004005
%DSERR_PRIOLEVELNEEDED                                  = -2005401530  ' &H88780046
%DSERR_OUTOFMEMORY                                      = 7            ' &H7
%DSERR_BADFORMAT                                        = -2005401500  ' &H88780064
%DSERR_UNSUPPORTED                                      = -2147467263  ' &H80004001
%DSERR_NODRIVER                                         = -2005401480  ' &H88780078
%DSERR_ALREADYINITIALIZED                               = -2005401470  ' &H88780082
%DSERR_BUFFERLOST                                       = -2005401450  ' &H88780096
%DSERR_OTHERAPPHASPRIO                                  = -2005401440  ' &H887800A0
%DSERR_UNINITIALIZED                                    = -2005401430  ' &H887800AA
%DSERR_NOINTERFACE                                      = 430          ' &H1AE

' ========================================================================================
' CONST_DDRAWERR enum
' ========================================================================================

%DD_OK                                                  = 0            ' &H0
%DDENUMRET_CANCEL                                       = 0            ' &H0
%DDENUMRET_OK                                           = 1            ' &H1
%DDERR_ALREADYINITIALIZED                               = -2005532667  ' &H88760005
%DDERR_CANNOTATTACHSURFACE                              = -2005532662  ' &H8876000A
%DDERR_CANNOTDETACHSURFACE                              = -2005532652  ' &H88760014
%DDERR_CURRENTLYNOTAVAIL                                = -2005532632  ' &H88760028
%DDERR_EXCEPTION                                        = -2005532617  ' &H88760037
%DDERR_GENERIC                                          = -2147467259  ' &H80004005
%DDERR_HEIGHTALIGN                                      = -2005532582  ' &H8876005A
%DDERR_INCOMPATIBLEPRIMARY                              = -2005532577  ' &H8876005F
%DDERR_INVALIDCAPS                                      = -2005532572  ' &H88760064
%DDERR_INVALIDCLIPLIST                                  = -2005532562  ' &H8876006E
%DDERR_INVALIDMODE                                      = -2005532552  ' &H88760078
%DDERR_INVALIDOBJECT                                    = -2005532542  ' &H88760082
%DDERR_INVALIDPARAMS                                    = 5            ' &H5
%DDERR_INVALIDPIXELFORMAT                               = -2005532527  ' &H88760091
%DDERR_INVALIDRECT                                      = -2005532522  ' &H88760096
%DDERR_LOCKEDSURFACES                                   = -2005532512  ' &H887600A0
%DDERR_NO3D                                             = -2005532502  ' &H887600AA
%DDERR_NOALPHAHW                                        = -2005532492  ' &H887600B4
%DDERR_NOCLIPLIST                                       = -2005532467  ' &H887600CD
%DDERR_NOCOLORCONVHW                                    = -2005532462  ' &H887600D2
%DDERR_NOCOOPERATIVELEVELSET                            = -2005532460  ' &H887600D4
%DDERR_NOCOLORKEY                                       = -2005532457  ' &H887600D7
%DDERR_NOCOLORKEYHW                                     = -2005532452  ' &H887600DC
%DDERR_NODIRECTDRAWSUPPORT                              = -2005532450  ' &H887600DE
%DDERR_NOEXCLUSIVEMODE                                  = -2005532447  ' &H887600E1
%DDERR_NOFLIPHW                                         = -2005532442  ' &H887600E6
%DDERR_NOGDI                                            = -2005532432  ' &H887600F0
%DDERR_NOMIRRORHW                                       = -2005532422  ' &H887600FA
%DDERR_NOTFOUND                                         = -2005532417  ' &H887600FF
%DDERR_NOOVERLAYHW                                      = -2005532412  ' &H88760104
%DDERR_OVERLAPPINGRECTS                                 = -2005532402  ' &H8876010E
%DDERR_NORASTEROPHW                                     = -2005532392  ' &H88760118
%DDERR_NOROTATIONHW                                     = -2005532382  ' &H88760122
%DDERR_NOSTRETCHHW                                      = -2005532362  ' &H88760136
%DDERR_NOT4BITCOLOR                                     = -2005532356  ' &H8876013C
%DDERR_NOT4BITCOLORINDEX                                = -2005532355  ' &H8876013D
%DDERR_NOT8BITCOLOR                                     = -2005532352  ' &H88760140
%DDERR_NOTEXTUREHW                                      = -2005532342  ' &H8876014A
%DDERR_NOVSYNCHW                                        = -2005532337  ' &H8876014F
%DDERR_NOZBUFFERHW                                      = -2005532332  ' &H88760154
%DDERR_NOZOVERLAYHW                                     = -2005532322  ' &H8876015E
%DDERR_OUTOFCAPS                                        = -2005532312  ' &H88760168
%DDERR_OUTOFMEMORY                                      = 7            ' &H7
%DDERR_OUTOFVIDEOMEMORY                                 = -2005532292  ' &H8876017C
%DDERR_OVERLAYCANTCLIP                                  = -2005532290  ' &H8876017E
%DDERR_OVERLAYCOLORKEYONLYONEACTIVE                     = -2005532288  ' &H88760180
%DDERR_PALETTEBUSY                                      = -2005532285  ' &H88760183
%DDERR_COLORKEYNOTSET                                   = -2005532272  ' &H88760190
%DDERR_SURFACEALREADYATTACHED                           = -2005532262  ' &H8876019A
%DDERR_SURFACEALREADYDEPENDENT                          = -2005532252  ' &H887601A4
%DDERR_SURFACEBUSY                                      = -2005532242  ' &H887601AE
%DDERR_CANTLOCKSURFACE                                  = -2005532237  ' &H887601B3
%DDERR_SURFACEISOBSCURED                                = -2005532232  ' &H887601B8
%DDERR_SURFACELOST                                      = -2005532222  ' &H887601C2
%DDERR_SURFACENOTATTACHED                               = -2005532212  ' &H887601CC
%DDERR_TOOBIGHEIGHT                                     = -2005532202  ' &H887601D6
%DDERR_TOOBIGSIZE                                       = -2005532192  ' &H887601E0
%DDERR_TOOBIGWIDTH                                      = -2005532182  ' &H887601EA
%DDERR_UNSUPPORTED                                      = -2147467263  ' &H80004001
%DDERR_UNSUPPORTEDFORMAT                                = -2005532162  ' &H887601FE
%DDERR_UNSUPPORTEDMASK                                  = -2005532152  ' &H88760208
%DDERR_INVALIDSTREAM                                    = -2005532151  ' &H88760209
%DDERR_VERTICALBLANKINPROGRESS                          = -2005532135  ' &H88760219
%DDERR_WASSTILLDRAWING                                  = -2005532132  ' &H8876021C
%DDERR_XALIGN                                           = -2005532112  ' &H88760230
%DDERR_INVALIDDIRECTDRAWGUID                            = -2005532111  ' &H88760231
%DDERR_DIRECTDRAWALREADYCREATED                         = -2005532110  ' &H88760232
%DDERR_NODIRECTDRAWHW                                   = -2005532109  ' &H88760233
%DDERR_PRIMARYSURFACEALREADYEXISTS                      = -2005532108  ' &H88760234
%DDERR_NOEMULATION                                      = -2005532107  ' &H88760235
%DDERR_REGIONTOOSMALL                                   = -2005532106  ' &H88760236
%DDERR_CLIPPERISUSINGHWND                               = -2005532105  ' &H88760237
%DDERR_NOCLIPPERATTACHED                                = -2005532104  ' &H88760238
%DDERR_NOHWND                                           = -2005532103  ' &H88760239
%DDERR_HWNDSUBCLASSED                                   = -2005532102  ' &H8876023A
%DDERR_HWNDALREADYSET                                   = -2005532101  ' &H8876023B
%DDERR_NOPALETTEATTACHED                                = -2005532100  ' &H8876023C
%DDERR_NOPALETTEHW                                      = -2005532099  ' &H8876023D
%DDERR_BLTFASTCANTCLIP                                  = -2005532098  ' &H8876023E
%DDERR_NOBLTHW                                          = -2005532097  ' &H8876023F
%DDERR_NODDROPSHW                                       = -2005532096  ' &H88760240
%DDERR_OVERLAYNOTVISIBLE                                = -2005532095  ' &H88760241
%DDERR_NOOVERLAYDEST                                    = -2005532094  ' &H88760242
%DDERR_INVALIDPOSITION                                  = -2005532093  ' &H88760243
%DDERR_NOTAOVERLAYSURFACE                               = -2005532092  ' &H88760244
%DDERR_EXCLUSIVEMODEALREADYSET                          = -2005532091  ' &H88760245
%DDERR_NOTFLIPPABLE                                     = -2005532090  ' &H88760246
%DDERR_CANTDUPLICATE                                    = -2005532089  ' &H88760247
%DDERR_NOTLOCKED                                        = -2005532088  ' &H88760248
%DDERR_CANTCREATEDC                                     = -2005532087  ' &H88760249
%DDERR_NODC                                             = -2005532086  ' &H8876024A
%DDERR_WRONGMODE                                        = -2005532085  ' &H8876024B
%DDERR_IMPLICITLYCREATED                                = -2005532084  ' &H8876024C
%DDERR_NOTPALETTIZED                                    = -2005532083  ' &H8876024D
%DDERR_UNSUPPORTEDMODE                                  = -2005532082  ' &H8876024E
%DDERR_NOMIPMAPHW                                       = -2005532081  ' &H8876024F
%DDERR_INVALIDSURFACETYPE                               = -2005532080  ' &H88760250
%DDERR_NOOPTIMIZEHW                                     = -2005532072  ' &H88760258
%DDERR_NOTLOADED                                        = -2005532071  ' &H88760259
%DDERR_NOFOCUSWINDOW                                    = -2005532070  ' &H8876025A
%DDERR_DCALREADYCREATED                                 = -2005532052  ' &H8876026C
%DDERR_NONONLOCALVIDMEM                                 = -2005532042  ' &H88760276
%DDERR_CANTPAGELOCK                                     = -2005532032  ' &H88760280
%DDERR_CANTPAGEUNLOCK                                   = -2005532012  ' &H88760294
%DDERR_NOTPAGELOCKED                                    = -2005531992  ' &H887602A8
%DDERR_MOREDATA                                         = -2005531982  ' &H887602B2
%DDERR_EXPIRED                                          = -2005531981  ' &H887602B3
%DDERR_VIDEONOTACTIVE                                   = -2005531977  ' &H887602B7
%DDERR_DEVICEDOESNTOWNSURFACE                           = -2005531973  ' &H887602BB
%DDERR_NOTINITIALIZED                                   = -2147221008  ' &H800401F0
%DDERR_NOSTEREOHARDWARE                                 = -2005532491  ' &H887600B5
%DDERR_NOSURFACELEFT                                    = -2005532490  ' &H887600B6

' ========================================================================================
' CONST_D3DIMERR enum
' ========================================================================================

%D3D_OK                                                 = 0            ' &H0
%D3DERR_BADMAJORVERSION                                 = -2005531972  ' &H887602BC
%D3DERR_BADMINORVERSION                                 = -2005531971  ' &H887602BD
%D3DERR_INVALID_DEVICE                                  = -2005531967  ' &H887602C1
%D3DERR_INITFAILED                                      = -2005531966  ' &H887602C2
%D3DERR_DEVICEAGGREGATED                                = -2005531965  ' &H887602C3
%D3DERR_TEXTURE_NO_SUPPORT                              = -2005531952  ' &H887602D0
%D3DERR_TEXTURE_CREATE_FAILED                           = -2005531951  ' &H887602D1
%D3DERR_TEXTURE_DESTROY_FAILED                          = -2005531950  ' &H887602D2
%D3DERR_TEXTURE_LOCK_FAILED                             = -2005531949  ' &H887602D3
%D3DERR_TEXTURE_UNLOCK_FAILED                           = -2005531948  ' &H887602D4
%D3DERR_TEXTURE_LOAD_FAILED                             = -2005531947  ' &H887602D5
%D3DERR_TEXTURE_SWAP_FAILED                             = -2005531946  ' &H887602D6
%D3DERR_TEXTURE_LOCKED                                  = -2005531945  ' &H887602D7
%D3DERR_TEXTURE_NOT_LOCKED                              = -2005531944  ' &H887602D8
%D3DERR_TEXTURE_GETSURF_FAILED                          = -2005531943  ' &H887602D9
%D3DERR_MATRIX_CREATE_FAILED                            = -2005531942  ' &H887602DA
%D3DERR_MATRIX_DESTROY_FAILED                           = -2005531941  ' &H887602DB
%D3DERR_MATRIX_SETDATA_FAILED                           = -2005531940  ' &H887602DC
%D3DERR_MATRIX_GETDATA_FAILED                           = -2005531939  ' &H887602DD
%D3DERR_SETVIEWPORTDATA_FAILED                          = -2005531938  ' &H887602DE
%D3DERR_INVALIDCURRENTVIEWPORT                          = -2005531937  ' &H887602DF
%D3DERR_INVALIDPRIMITIVETYPE                            = -2005531936  ' &H887602E0
%D3DERR_INVALIDVERTEXTYPE                               = -2005531935  ' &H887602E1
%D3DERR_TEXTURE_BADSIZE                                 = -2005531934  ' &H887602E2
%D3DERR_INVALIDRAMPTEXTURE                              = -2005531933  ' &H887602E3
%D3DERR_MATERIAL_CREATE_FAILED                          = -2005531932  ' &H887602E4
%D3DERR_MATERIAL_DESTROY_FAILED                         = -2005531931  ' &H887602E5
%D3DERR_MATERIAL_SETDATA_FAILED                         = -2005531930  ' &H887602E6
%D3DERR_MATERIAL_GETDATA_FAILED                         = -2005531929  ' &H887602E7
%D3DERR_INVALIDPALETTE                                  = -2005531928  ' &H887602E8
%D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY                        = -2005531927  ' &H887602E9
%D3DERR_ZBUFF_NEEDS_VIDEOMEMORY                         = -2005531926  ' &H887602EA
%D3DERR_SURFACENOTINVIDMEM                              = -2005531925  ' &H887602EB
%D3DERR_LIGHT_SET_FAILED                                = -2005531922  ' &H887602EE
%D3DERR_LIGHTHASVIEWPORT                                = -2005531921  ' &H887602EF
%D3DERR_LIGHTNOTINTHISVIEWPORT                          = -2005531920  ' &H887602F0
%D3DERR_SCENE_IN_SCENE                                  = -2005531912  ' &H887602F8
%D3DERR_SCENE_NOT_IN_SCENE                              = -2005531911  ' &H887602F9
%D3DERR_SCENE_BEGIN_FAILED                              = -2005531910  ' &H887602FA
%D3DERR_SCENE_END_FAILED                                = -2005531909  ' &H887602FB
%D3DERR_INBEGIN                                         = -2005531902  ' &H88760302
%D3DERR_NOTINBEGIN                                      = -2005531901  ' &H88760303
%D3DERR_NOVIEWPORTS                                     = -2005531900  ' &H88760304
%D3DERR_VIEWPORTDATANOTSET                              = -2005531899  ' &H88760305
%D3DERR_VIEWPORTHASNODEVICE                             = -2005531898  ' &H88760306
%D3DERR_NOCURRENTVIEWPORT                               = -2005531897  ' &H88760307
%D3DERR_INVALIDVERTEXFORMAT                             = -2005530624  ' &H88760800
%D3DERR_COLORKEYATTACHED                                = -2005530622  ' &H88760802
%D3DERR_VERTEXBUFFEROPTIMIZED                           = -2005530612  ' &H8876080C
%D3DERR_VBUF_CREATE_FAILED                              = -2005530611  ' &H8876080D
%D3DERR_VERTEXBUFFERLOCKED                              = -2005530610  ' &H8876080E
%D3DERR_ZBUFFER_NOTPRESENT                              = -2005530602  ' &H88760816
%D3DERR_STENCILBUFFER_NOTPRESENT                        = -2005530601  ' &H88760817
%D3DERR_WRONGTEXTUREFORMAT                              = -2005530600  ' &H88760818
%D3DERR_UNSUPPORTEDCOLOROPERATION                       = -2005530599  ' &H88760819
%D3DERR_UNSUPPORTEDCOLORARG                             = -2005530598  ' &H8876081A
%D3DERR_UNSUPPORTEDALPHAOPERATION                       = -2005530597  ' &H8876081B
%D3DERR_UNSUPPORTEDALPHAARG                             = -2005530596  ' &H8876081C
%D3DERR_TOOMANYOPERATIONS                               = -2005530595  ' &H8876081D
%D3DERR_CONFLICTINGTEXTUREFILTER                        = -2005530594  ' &H8876081E
%D3DERR_UNSUPPORTEDFACTORVALUE                          = -2005530593  ' &H8876081F
%D3DERR_CONFLICTINGRENDERSTATE                          = -2005530591  ' &H88760821
%D3DERR_UNSUPPORTEDTEXTUREFILTER                        = -2005530590  ' &H88760822
%D3DERR_TOOMANYPRIMITIVES                               = -2005530589  ' &H88760823
%D3DERR_INVALIDMATRIX                                   = -2005530588  ' &H88760824
%D3DERR_TOOMANYVERTICES                                 = -2005530587  ' &H88760825
%D3DERR_CONFLICTINGTEXTUREPALETTE                       = -2005530586  ' &H88760826
%D3DERR_INVALIDSTATEBLOCK                               = -2005530572  ' &H88760834
%D3DERR_INBEGINSTATEBLOCK                               = -2005530571  ' &H88760835
%D3DERR_NOTINBEGINSTATEBLOCK                            = -2005530570  ' &H88760836
%D3DERR_VERTEXBUFFERUNLOCKFAILED                        = -2005530609  ' &H8876080F

' ========================================================================================
' CONST_DPLAYERR enum
' ========================================================================================

%DP_OK                                                  = 0            ' &H0
%DPERR_ALREADYINITIALIZED                               = -2005467131  ' &H88770005
%DPERR_ACCESSDENIED                                     = -2005467126  ' &H8877000A
%DPERR_ACTIVEPLAYERS                                    = -2005467116  ' &H88770014
%DPERR_BUFFERTOOSMALL                                   = -2005467106  ' &H8877001E
%DPERR_CANTADDPLAYER                                    = -2005467096  ' &H88770028
%DPERR_CANTCREATEGROUP                                  = -2005467086  ' &H88770032
%DPERR_CANTCREATEPLAYER                                 = -2005467076  ' &H8877003C
%DPERR_CANTCREATESESSION                                = -2005467066  ' &H88770046
%DPERR_CAPSNOTAVAILABLEYET                              = -2005467056  ' &H88770050
%DPERR_EXCEPTION                                        = -2005467046  ' &H8877005A
%DPERR_GENERIC                                          = -2147467259  ' &H80004005
%DPERR_INVALIDFLAGS                                     = -2005467016  ' &H88770078
%DPERR_INVALIDOBJECT                                    = -2005467006  ' &H88770082
%DPERR_INVALIDPARAM                                     = -2147024809  ' &H80070057
%DPERR_INVALIDPARAMS                                    = -2147024809  ' &H80070057
%DPERR_INVALIDPLAYER                                    = -2005466986  ' &H88770096
%DPERR_INVALIDGROUP                                     = -2005466981  ' &H8877009B
%DPERR_NOCAPS                                           = -2005466976  ' &H887700A0
%DPERR_NOCONNECTION                                     = -2005466966  ' &H887700AA
%DPERR_OUTOFMEMORY                                      = 7            ' &H7
%DPERR_NOMESSAGES                                       = -2005466946  ' &H887700BE
%DPERR_NONAMESERVERFOUND                                = -2005466936  ' &H887700C8
%DPERR_NOPLAYERS                                        = -2005466926  ' &H887700D2
%DPERR_NOSESSIONS                                       = -2005466916  ' &H887700DC
%DPERR_PENDING                                          = -2147024889  ' &H80070007
%DPERR_SENDTOOBIG                                       = -2005466906  ' &H887700E6
%DPERR_TIMEOUT                                          = -2005466896  ' &H887700F0
%DPERR_UNAVAILABLE                                      = -2005466886  ' &H887700FA
%DPERR_UNSUPPORTED                                      = 445          ' &H1BD
%DPERR_BUSY                                             = -2005466866  ' &H8877010E
%DPERR_USERCANCEL                                       = -2005466856  ' &H88770118
%DPERR_NOINTERFACE                                      = 430          ' &H1AE
%DPERR_CANNOTCREATESERVER                               = -2005466846  ' &H88770122
%DPERR_PLAYERLOST                                       = -2005466836  ' &H8877012C
%DPERR_SESSIONLOST                                      = -2005466826  ' &H88770136
%DPERR_UNINITIALIZED                                    = -2005466816  ' &H88770140
%DPERR_NONEWPLAYERS                                     = -2005466806  ' &H8877014A
%DPERR_INVALIDPASSWORD                                  = -2005466796  ' &H88770154
%DPERR_CONNECTING                                       = -2005466786  ' &H8877015E
%DPERR_CONNECTIONLOST                                   = -2005466776  ' &H88770168
%DPERR_UNKNOWNMESSAGE                                   = -2005466766  ' &H88770172
%DPERR_CANCELFAILED                                     = -2005466756  ' &H8877017C
%DPERR_INVALIDPRIORITY                                  = -2005466746  ' &H88770186
%DPERR_CANCELLED                                        = -2005466726  ' &H8877019A
%DPERR_ABORTED                                          = -2005466716  ' &H887701A4
%DPERR_BUFFERTOOLARGE                                   = -2005466136  ' &H887703E8
%DPERR_CANTCREATEPROCESS                                = -2005466126  ' &H887703F2
%DPERR_APPNOTSTARTED                                    = -2005466116  ' &H887703FC
%DPERR_INVALIDINTERFACE                                 = -2005466106  ' &H88770406
%DPERR_UNKNOWNAPPLICATION                               = -2005466086  ' &H8877041A
%DPERR_NOTLOBBIED                                       = -2005466066  ' &H8877042E
%DPERR_AUTHENTICATIONFAILED                             = -2005465136  ' &H887707D0
%DPERR_CANTLOADSSPI                                     = -2005465126  ' &H887707DA
%DPERR_ENCRYPTIONFAILED                                 = -2005465116  ' &H887707E4
%DPERR_SIGNFAILED                                       = -2005465106  ' &H887707EE
%DPERR_CANTLOADSECURITYPACKAGE                          = -2005465096  ' &H887707F8
%DPERR_ENCRYPTIONNOTSUPPORTED                           = -2005465086  ' &H88770802
%DPERR_CANTLOADCAPI                                     = -2005465076  ' &H8877080C
%DPERR_NOTLOGGEDIN                                      = -2005465066  ' &H88770816
%DPERR_LOGONDENIED                                      = -2005465056  ' &H88770820

' ========================================================================================
' CONST_DINPUTERR enum
' ========================================================================================

%DI_OK                                                  = 0            ' &H0
%DI_BUFFEROVERFLOW                                      = -2147220896  ' &H80040260
%DIERR_INVALIDHANDLE                                    = -2147024890  ' &H80070006
%DIERR_OLDDIRECTINPUTVERSION                            = -2147023746  ' &H8007047E
%DIERR_BETADIRECTINPUTVERSION                           = -2147023743  ' &H80070481
%DIERR_BADDRIVERVER                                     = -2147024777  ' &H80070077
%DIERR_DEVICENOTREG                                     = -2147221164  ' &H80040154
%DIERR_NOTFOUND                                         = -2147024894  ' &H80070002
%DIERR_OBJECTNOTFOUND                                   = -2147024894  ' &H80070002
%DIERR_INVALIDPARAM                                     = 5            ' &H5
%DIERR_NOINTERFACE                                      = 430          ' &H1AE
%DIERR_GENERIC                                          = -2147467259  ' &H80004005
%DIERR_OUTOFMEMORY                                      = 7            ' &H7
%DIERR_UNSUPPORTED                                      = 445          ' &H1BD
%DIERR_NOTINITIALIZED                                   = -2147024875  ' &H80070015
%DIERR_ALREADYINITIALIZED                               = -2147023649  ' &H800704DF
%DIERR_INPUTLOST                                        = -2147024866  ' &H8007001E
%DIERR_ACQUIRED                                         = -2147024726  ' &H800700AA
%DIERR_NOTACQUIRED                                      = -2147024884  ' &H8007000C
%DIERR_NOAGGREGATION                                    = -2147467262  ' &H80004002
%DIERR_OTHERAPPHASPRIO                                  = -2147024891  ' &H80070005
%DIERR_READONLY                                         = -2147024891  ' &H80070005
%DIERR_HANDLEEXISTS                                     = -2147024891  ' &H80070005
'%E_PENDING                                              = -2147024889  ' &H80070007
%DIERR_PENDING                                          = -2147024889  ' &H80070007
%DIERR_INSUFFICIENTPRIVS                                = -2147220992  ' &H80040200
%DIERR_DEVICEFULL                                       = -2147220991  ' &H80040201
%DIERR_MOREDATA                                         = -2147220990  ' &H80040202
%DIERR_NOTDOWNLOADED                                    = -2147220989  ' &H80040203
%DIERR_HASEFFECTS                                       = -2147220988  ' &H80040204
%DIERR_NOTEXCLUSIVEACQUIRED                             = -2147220987  ' &H80040205
%DIERR_INCOMPLETEEFFECT                                 = -2147220986  ' &H80040206
%DIERR_NOTBUFFERED                                      = -2147220985  ' &H80040207
%DIERR_EFFECTPLAYING                                    = -2147220984  ' &H80040208

' ========================================================================================
' CONST_D3DRMERR enum
' ========================================================================================

%D3DRM_OK                                               = 0            ' &H0
%D3DRMERR_BADOBJECT                                     = -2005531891  ' &H8876030D
%D3DRMERR_BADTYPE                                       = -2005531890  ' &H8876030E
%D3DRMERR_BADALLOC                                      = -2005531889  ' &H8876030F
%D3DRMERR_FACEUSED                                      = -2005531888  ' &H88760310
%D3DRMERR_NOTFOUND                                      = -2005531887  ' &H88760311
%D3DRMERR_NOTDONEYET                                    = -2005531886  ' &H88760312
%D3DRMERR_FILENOTFOUND                                  = -2005531885  ' &H88760313
%D3DRMERR_BADFILE                                       = -2005531884  ' &H88760314
%D3DRMERR_BADDEVICE                                     = -2005531883  ' &H88760315
%D3DRMERR_BADVALUE                                      = -2005531882  ' &H88760316
%D3DRMERR_BADMAJORVERSION                               = -2005531881  ' &H88760317
%D3DRMERR_BADMINORVERSION                               = -2005531880  ' &H88760318
%D3DRMERR_UNABLETOEXECUTE                               = -2005531879  ' &H88760319
%D3DRMERR_LIBRARYNOTFOUND                               = -2005531878  ' &H8876031A
%D3DRMERR_INVALIDLIBRARY                                = -2005531877  ' &H8876031B
%D3DRMERR_PENDING                                       = -2005531876  ' &H8876031C
%D3DRMERR_NOTENOUGHDATA                                 = -2005531875  ' &H8876031D
%D3DRMERR_REQUESTTOOLARGE                               = -2005531874  ' &H8876031E
%D3DRMERR_REQUESTTOOSMALL                               = -2005531873  ' &H8876031F
%D3DRMERR_CONNECTIONLOST                                = -2005531872  ' &H88760320
%D3DRMERR_LOADABORTED                                   = -2005531871  ' &H88760321
%D3DRMERR_NOINTERNET                                    = -2005531870  ' &H88760322
%D3DRMERR_BADCACHEFILE                                  = -2005531869  ' &H88760323
%D3DRMERR_BOXNOTSET                                     = -2005531868  ' &H88760324
%D3DRMERR_BADPMDATA                                     = -2005531867  ' &H88760325
%D3DRMERR_CLIENTNOTREGISTERED                           = -2005531866  ' &H88760326
%D3DRMERR_NOTCREATEDFROMDDS                             = -2005531865  ' &H88760327
%D3DRMERR_NOSUCHKEY                                     = -2005531864  ' &H88760328
%D3DRMERR_INCOMPATABLEKEY                               = -2005531863  ' &H88760329
%D3DRMERR_ELEMENTINUSE                                  = -2005531862  ' &H8876032A
%D3DRMERR_TEXTUREFORMATNOTFOUND                         = -2005531861  ' &H8876032B
%D3DRMERR_NOTAGGREGATED                                 = -2005531860  ' &H8876032C

' ========================================================================================
' CONST_DICOMMONDATAFORMATS enum
' ========================================================================================

%DIFORMAT_KEYBOARD                                      = 1            ' &H1
%DIFORMAT_MOUSE                                         = 2            ' &H2
%DIFORMAT_JOYSTICK                                      = 3            ' &H3
%DIFORMAT_JOYSTICK2                                     = 4            ' &H4

' ========================================================================================
' CONST_D3DVERTEXCOMPONENT enum
' ========================================================================================

%D3DVERTCOMP_POSITION                                   = 1            ' &H1
%D3DVERTCOMP_NORMAL                                     = 2            ' &H2
%D3DVERTCOMP_DIFFUSE                                    = 3            ' &H3
%D3DVERTCOMP_SPECULAR                                   = 4            ' &H4
%D3DVERTCOMP_TEXTURE1                                   = 5            ' &H5
%D3DVERTCOMP_TEXTURE2                                   = 6            ' &H6
%D3DVERTCOMP_TEXTURE3                                   = 7            ' &H7
%D3DVERTCOMP_TEXTURE4                                   = 8            ' &H8
%D3DVERTCOMP_TEXTURE5                                   = 9            ' &H9
%D3DVERTCOMP_TEXTURE6                                   = 10           ' &HA
%D3DVERTCOMP_TEXTURE7                                   = 11           ' &HB
%D3DVERTCOMP_TEXTURE8                                   = 12           ' &HC

' ========================================================================================
' CONST_D3DMATERIALCOLORSOURCE enum
' ========================================================================================

%D3DMCS_MATERIAL                                        = 0            ' &H0
%D3DMCS_COLOR1                                          = 1            ' &H1
%D3DMCS_COLOR2                                          = 2            ' &H2

' ========================================================================================
' CONST_DMUS enum
' ========================================================================================

%DMUS_MAXSUBCHORD                                       = 8            ' &H8
%DMUS_TEMPO_MAX                                         = 350          ' &H15E
%DMUS_TEMPO_MIN                                         = 10           ' &HA

' ========================================================================================
' CONST_DMUS_CURVES enum
' ========================================================================================

%DMUS_CURVES_LINEAR                                     = 0            ' &H0
%DMUS_CURVES_INSTANT                                    = 1            ' &H1
%DMUS_CURVES_EXP                                        = 2            ' &H2
%DMUS_CURVES_LOG                                        = 3            ' &H3
%DMUS_CURVES_SINE                                       = 4            ' &H4

' ========================================================================================
' CONST_DMUS_CURVET enum
' ========================================================================================

%DMUS_CURVET_PBCURVE                                    = 3            ' &H3
%DMUS_CURVET_CCCURVE                                    = 4            ' &H4
%DMUS_CURVET_MATCURVE                                   = 5            ' &H5
%DMUS_CURVET_PATCURVE                                   = 6            ' &H6

' ========================================================================================
' CONST_DMUS_NOTIFICATION_SUBTYPE enum
' ========================================================================================

%DMUS_NOTIFICATION_MUSICSTARTED                         = 0            ' &H0
%DMUS_NOTIFICATION_MUSICSTOPPED                         = 1            ' &H1
%DMUS_NOTIFICATION_MEASUREBEAT                          = 0            ' &H0
%DMUS_NOTIFICATION_CHORD                                = 0            ' &H0
%DMUS_NOTIFICATION_GROOVE                               = 0            ' &H0
%DMUS_NOTIFICATION_EMBELLISHMENT                        = 1            ' &H1
%DMUS_NOTIFICATION_SEGSTART                             = 0            ' &H0
%DMUS_NOTIFICATION_SEGEND                               = 1            ' &H1
%DMUS_NOTIFICATION_SEGALMOSTEND                         = 2            ' &H2
%DMUS_NOTIFICATION_SEGLOOP                              = 3            ' &H3
%DMUS_NOTIFICATION_SEGABORT                             = 4            ' &H4

' ========================================================================================
' CONST_DMUS_COMMANDT_TYPES enum
' ========================================================================================

%DMUS_COMMANDT_GROOVE                                   = 0            ' &H0
%DMUS_COMMANDT_FILL                                     = 1            ' &H1
%DMUS_COMMANDT_INTRO                                    = 2            ' &H2
%DMUS_COMMANDT_BREAK                                    = 3            ' &H3
%DMUS_COMMANDT_END                                      = 4            ' &H4
%DMUS_COMMANDT_ENDANDINTRO                              = 5            ' &H5

' ========================================================================================
' CONST_DMUS_SHAPET_TYPES enum
' ========================================================================================

%DMUS_SHAPET_FALLING                                    = 0            ' &H0
%DMUS_SHAPET_LEVEL                                      = 1            ' &H1
%DMUS_SHAPET_LOOPABLE                                   = 2            ' &H2
%DMUS_SHAPET_LOUD                                       = 3            ' &H3
%DMUS_SHAPET_QUIET                                      = 4            ' &H4
%DMUS_SHAPET_PEAKING                                    = 5            ' &H5
%DMUS_SHAPET_RANDOM                                     = 6            ' &H6
%DMUS_SHAPET_RISING                                     = 7            ' &H7
%DMUS_SHAPET_SONG                                       = 8            ' &H8

' ========================================================================================
' CONST_DMUS_COMPOSEF_FLAGS enum
' ========================================================================================

%DMUS_COMPOSEF_NONE                                     = 0            ' &H0
%DMUS_COMPOSEF_ALIGN                                    = 1            ' &H1
%DMUS_COMPOSEF_OVERLAP                                  = 2            ' &H2
%DMUS_COMPOSEF_IMMEDIATE                                = 4            ' &H4
%DMUS_COMPOSEF_GRID                                     = 8            ' &H8
%DMUS_COMPOSEF_BEAT                                     = 16           ' &H10
%DMUS_COMPOSEF_MEASURE                                  = 32           ' &H20
%DMUS_COMPOSEF_AFTERPREPARETIME                         = 64           ' &H40
%DMUS_COMPOSEF_MODULATE                                 = 4096         ' &H1000
%DMUS_COMPOSEF_LONG                                     = 8192         ' &H2000

' ========================================================================================
' CONST_DMUS_PMSGF_FLAGS enum
' ========================================================================================

%DMUS_PMSGF_REFTIME                                     = 1            ' &H1
%DMUS_PMSGF_MUSICTIME                                   = 2            ' &H2
%DMUS_PMSGF_TOOL_IMMEDIATE                              = 4            ' &H4
%DMUS_PMSGF_TOOL_QUEUE                                  = 8            ' &H8
%DMUS_PMSGF_TOOL_ATTIME                                 = 16           ' &H10
%DMUS_PMSGF_TOOL_FLUSH                                  = 32           ' &H20

' ========================================================================================
' CONST_DMUS_SEGF_FLAGS enum
' ========================================================================================

%DMUS_SEGF_REFTIME                                      = 64           ' &H40
%DMUS_SEGF_SECONDARY                                    = 128          ' &H80
%DMUS_SEGF_QUEUE                                        = 256          ' &H100
%DMUS_SEGF_CONTROL                                      = 512          ' &H200
%DMUS_SEGF_AFTERPREPARETIME                             = 1024         ' &H400
%DMUS_SEGF_GRID                                         = 2048         ' &H800
%DMUS_SEGF_BEAT                                         = 4096         ' &H1000
%DMUS_SEGF_MEASURE                                      = 8192         ' &H2000
%DMUS_SEGF_DEFAULT                                      = 16384        ' &H4000
%DMUS_SEGF_NOINVALIDATE                                 = 32768        ' &H8000

' ========================================================================================
' CONST_DMUS_NOTEF_FLAGS enum
' ========================================================================================

%DMUS_NOTEF_NOTEON                                      = 1            ' &H1

' ========================================================================================
' CONST_DMUS_PLAYMODE_FLAGS enum
' ========================================================================================

%DMUS_PLAYMODE_KEY_ROOT                                 = 1            ' &H1
%DMUS_PLAYMODE_CHORD_ROOT                               = 2            ' &H2
%DMUS_PLAYMODE_SCALE_INTERVALS                          = 4            ' &H4
%DMUS_PLAYMODE_CHORD_INTERVALS                          = 8            ' &H8
%DMUS_PLAYMODE_NONE                                     = 16           ' &H10
%DMUS_PLAYMODE_FIXED                                    = 0            ' &H0
%DMUS_PLAYMODE_FIXEDTOKEY                               = 1            ' &H1
%DMUS_PLAYMODE_FIXEDTOCHORD                             = 2            ' &H2
%DMUS_PLAYMODE_PEDALPOINT                               = 5            ' &H5
%DMUS_PLAYMODE_MELODIC                                  = 6            ' &H6
%DMUS_PLAYMODE_NORMALCHORD                              = 10           ' &HA
%DMUS_PLAYMODE_ALWAYSPLAY                               = 14           ' &HE

' ========================================================================================
' CONST_DMUS_CURVE_FLAGS enum
' ========================================================================================

%DMUS_CURVE_RESET                                       = 1            ' &H1

' ========================================================================================
' CONST_DMUSERR enum
' ========================================================================================

%DMUS_E_DRIVER_FAILED                                   = -2005397247  ' &H88781101
%DMUS_E_PORTS_OPEN                                      = -2005397246  ' &H88781102
%DMUS_E_DEVICE_IN_USE                                   = -2005397245  ' &H88781103
%DMUS_E_INSUFFICIENTBUFFER                              = -2005397244  ' &H88781104
%DMUS_E_BUFFERNOTSET                                    = -2005397243  ' &H88781105
%DMUS_E_BUFFERNOTAVAILABLE                              = -2005397242  ' &H88781106
%DMUS_E_NOTADLSCOL                                      = -2005397240  ' &H88781108
%DMUS_E_INVALIDOFFSET                                   = -2005397239  ' &H88781109
%DMUS_E_ALREADY_LOADED                                  = -2005397231  ' &H88781111
%DMUS_E_INVALIDPOS                                      = -2005397229  ' &H88781113
%DMUS_E_INVALIDPATCH                                    = -2005397228  ' &H88781114
%DMUS_E_CANNOTSEEK                                      = -2005397227  ' &H88781115
%DMUS_E_CANNOTWRITE                                     = -2005397226  ' &H88781116
%DMUS_E_CHUNKNOTFOUND                                   = -2005397225  ' &H88781117
%DMUS_E_INVALID_DOWNLOADID                              = -2005397223  ' &H88781119
%DMUS_E_NOT_DOWNLOADED_TO_PORT                          = -2005397216  ' &H88781120
%DMUS_E_ALREADY_DOWNLOADED                              = -2005397215  ' &H88781121
%DMUS_E_UNKNOWN_PROPERTY                                = -2005397214  ' &H88781122
%DMUS_E_SET_UNSUPPORTED                                 = -2005397213  ' &H88781123
%DMUS_E_GET_UNSUPPORTED                                 = -2005397212  ' &H88781124
%DMUS_E_NOTMONO                                         = -2005397211  ' &H88781125
%DMUS_E_BADARTICULATION                                 = -2005397210  ' &H88781126
%DMUS_E_BADINSTRUMENT                                   = -2005397209  ' &H88781127
%DMUS_E_BADWAVELINK                                     = -2005397208  ' &H88781128
%DMUS_E_NOARTICULATION                                  = -2005397207  ' &H88781129
%DMUS_E_NOTPCM                                          = -2005397206  ' &H8878112A
%DMUS_E_BADWAVE                                         = -2005397205  ' &H8878112B
%DMUS_E_BADOFFSETTABLE                                  = -2005397204  ' &H8878112C
%DMUS_E_UNKNOWNDOWNLOAD                                 = -2005397203  ' &H8878112D
%DMUS_E_NOSYNTHSINK                                     = -2005397202  ' &H8878112E
%DMUS_E_ALREADYOPEN                                     = -2005397201  ' &H8878112F
%DMUS_E_ALREADYCLOSED                                   = -2005397200  ' &H88781130
%DMUS_E_SYNTHNOTCONFIGURED                              = -2005397199  ' &H88781131
%DMUS_E_SYNTHACTIVE                                     = -2005397198  ' &H88781132
%DMUS_E_CANNOTREAD                                      = -2005397197  ' &H88781133
%DMUS_E_DMUSIC_RELEASED                                 = -2005397196  ' &H88781134
%DMUS_E_BUFFER_EMPTY                                    = -2005397195  ' &H88781135
%DMUS_E_BUFFER_FULL                                     = -2005397194  ' &H88781136
%DMUS_E_PORT_NOT_CAPTURE                                = -2005397193  ' &H88781137
%DMUS_E_PORT_NOT_RENDER                                 = -2005397192  ' &H88781138
%DMUS_E_DSOUND_NOT_SET                                  = -2005397191  ' &H88781139
%DMUS_E_ALREADY_ACTIVATED                               = -2005397190  ' &H8878113A
%DMUS_E_INVALIDBUFFER                                   = -2005397189  ' &H8878113B
%DMUS_E_WAVEFORMATNOTSUPPORTED                          = -2005397188  ' &H8878113C
%DMUS_E_SYNTHINACTIVE                                   = -2005397187  ' &H8878113D
%DMUS_E_DSOUND_ALREADY_SET                              = -2005397186  ' &H8878113E
%DMUS_E_INVALID_EVENT                                   = -2005397185  ' &H8878113F
%DMUS_E_UNSUPPORTED_STREAM                              = -2005397168  ' &H88781150
%DMUS_E_ALREADY_INITED                                  = -2005397167  ' &H88781151
%DMUS_E_INVALID_BAND                                    = -2005397166  ' &H88781152
%DMUS_E_TRACK_HDR_NOT_FIRST_CK                          = -2005397163  ' &H88781155
%DMUS_E_TOOL_HDR_NOT_FIRST_CK                           = -2005397162  ' &H88781156
%DMUS_E_INVALID_TRACK_HDR                               = -2005397161  ' &H88781157
%DMUS_E_INVALID_TOOL_HDR                                = -2005397160  ' &H88781158
%DMUS_E_ALL_TOOLS_FAILED                                = -2005397159  ' &H88781159
%DMUS_E_ALL_TRACKS_FAILED                               = -2005397152  ' &H88781160
%DMUS_E_NOT_FOUND                                       = -2005397151  ' &H88781161
%DMUS_E_NOT_INIT                                        = -2005397150  ' &H88781162
%DMUS_E_TYPE_DISABLED                                   = -2005397149  ' &H88781163
%DMUS_E_TYPE_UNSUPPORTED                                = -2005397148  ' &H88781164
%DMUS_E_TIME_PAST                                       = -2005397147  ' &H88781165
%DMUS_E_TRACK_NOT_FOUND                                 = -2005397146  ' &H88781166
%DMUS_E_NO_MASTER_CLOCK                                 = -2005397136  ' &H88781170
%DMUS_E_LOADER_NOCLASSID                                = -2005397120  ' &H88781180
%DMUS_E_LOADER_BADPATH                                  = -2005397119  ' &H88781181
%DMUS_E_LOADER_FAILEDOPEN                               = -2005397118  ' &H88781182
%DMUS_E_LOADER_FORMATNOTSUPPORTED                       = -2005397117  ' &H88781183
%DMUS_E_LOADER_FAILEDCREATE                             = -2005397116  ' &H88781184
%DMUS_E_LOADER_OBJECTNOTFOUND                           = -2005397115  ' &H88781185
%DMUS_E_LOADER_NOFILENAME                               = -2005397114  ' &H88781186
%DMUS_E_INVALIDFILE                                     = -2005396992  ' &H88781200
%DMUS_E_ALREADY_EXISTS                                  = -2005396991  ' &H88781201
%DMUS_E_OUT_OF_RANGE                                    = -2005396990  ' &H88781202
%DMUS_E_SEGMENT_INIT_FAILED                             = -2005396989  ' &H88781203
%DMUS_E_ALREADY_SENT                                    = -2005396988  ' &H88781204
%DMUS_E_CANNOT_FREE                                     = -2005396987  ' &H88781205
%DMUS_E_CANNOT_OPEN_PORT                                = -2005396986  ' &H88781206
%DMUS_E_CONNOT_CONVERT                                  = -2005396985  ' &H88781207
%DMUS_E_DESCEND_CHUNK_FAIL                              = -2005396976  ' &H88781210
%DMUS_E_FAIL                                            = -2147024809  ' &H80070057
%DMUS_E_INVALIDARG                                      = 5            ' &H5
%DMUS_E_NOINTERFACE                                     = 430          ' &H1AE
%DMUS_E_OUTOFMEMORY                                     = 7            ' &H7
%DMUS_E_NOTIMPL                                         = 445          ' &H1BD

' ========================================================================================
' CONST_DMUS_PC_CLASS enum
' ========================================================================================

%DMUS_PC_INPUTCLASS                                     = 0            ' &H0
%DMUS_PC_OUTPUTCLASS                                    = 1            ' &H1

' ========================================================================================
' CONST_DMUS_PC_FLAGS enum
' ========================================================================================

%DMUS_PC_DLS                                            = 1            ' &H1
%DMUS_PC_EXTERNAL                                       = 2            ' &H2
%DMUS_PC_SOFTWARESYNTH                                  = 4            ' &H4
%DMUS_PC_MEMORYSIZEFIXED                                = 8            ' &H8
%DMUS_PC_GMINHARDWARE                                   = 16           ' &H10
%DMUS_PC_GSINHARDWARE                                   = 32           ' &H20
%DMUS_PC_XGINHARDWARE                                   = 64           ' &H40
%DMUS_PC_DIRECTSOUND                                    = 128          ' &H80
%DMUS_PC_SHAREABLE                                      = 256          ' &H100
%DMUS_PC_SYSTEMMEMORY                                   = 2147483647   ' &H7FFFFFFF

' ========================================================================================
' CONST_DMUS_PORT_TYPE enum
' ========================================================================================

%DMUS_PORT_WINMM_DRIVER                                 = 0            ' &H0
%DMUS_PORT_USER_MODE_SYNTH                              = 1            ' &H1
%DMUS_PORT_KERNEL_MODE                                  = 2            ' &H2

' ========================================================================================
' CONST_DMUS_PORTPARAMS_FLAGS enum
' ========================================================================================

%DMUS_PORTPARAMS_VOICES                                 = 1            ' &H1
%DMUS_PORTPARAMS_CHANNELGROUPS                          = 2            ' &H2
%DMUS_PORTPARAMS_AUDIOCHANNELS                          = 4            ' &H4
%DMUS_PORTPARAMS_SAMPLERATE                             = 8            ' &H8
%DMUS_PORTPARAMS_EFFECTS                                = 32           ' &H20
%DMUS_PORTPARAMS_SHARE                                  = 64           ' &H40

' ========================================================================================
' CONST_DIMOUSEOFS enum
' ========================================================================================

%DIMOFS_X                                               = 0            ' &H0
%DIMOFS_Y                                               = 4            ' &H4
%DIMOFS_Z                                               = 8            ' &H8
%DIMOFS_BUTTON0                                         = 12           ' &HC
%DIMOFS_BUTTON1                                         = 13           ' &HD
%DIMOFS_BUTTON2                                         = 14           ' &HE
%DIMOFS_BUTTON3                                         = 15           ' &HF

' ========================================================================================
' CONST_DIJOYSTICKOFS enum
' ========================================================================================

%DIJOFS_X                                               = 0            ' &H0
%DIJOFS_Y                                               = 4            ' &H4
%DIJOFS_Z                                               = 8            ' &H8
%DIJOFS_RX                                              = 12           ' &HC
%DIJOFS_RY                                              = 16           ' &H10
%DIJOFS_RZ                                              = 20           ' &H14
%DIJOFS_SLIDER0                                         = 24           ' &H18
%DIJOFS_SLIDER1                                         = 28           ' &H1C
%DIJOFS_POV0                                            = 32           ' &H20
%DIJOFS_POV1                                            = 36           ' &H24
%DIJOFS_POV2                                            = 40           ' &H28
%DIJOFS_POV3                                            = 44           ' &H2C
%DIJOFS_BUTTON0                                         = 48           ' &H30
%DIJOFS_BUTTON1                                         = 49           ' &H31
%DIJOFS_BUTTON2                                         = 50           ' &H32
%DIJOFS_BUTTON3                                         = 51           ' &H33
%DIJOFS_BUTTON4                                         = 52           ' &H34
%DIJOFS_BUTTON5                                         = 53           ' &H35
%DIJOFS_BUTTON6                                         = 54           ' &H36
%DIJOFS_BUTTON7                                         = 55           ' &H37
%DIJOFS_BUTTON8                                         = 56           ' &H38
%DIJOFS_BUTTON9                                         = 57           ' &H39
%DIJOFS_BUTTON10                                        = 58           ' &H3A
%DIJOFS_BUTTON11                                        = 59           ' &H3B
%DIJOFS_BUTTON12                                        = 60           ' &H3C
%DIJOFS_BUTTON13                                        = 61           ' &H3D
%DIJOFS_BUTTON14                                        = 62           ' &H3E
%DIJOFS_BUTTON15                                        = 63           ' &H3F
%DIJOFS_BUTTON16                                        = 64           ' &H40
%DIJOFS_BUTTON17                                        = 65           ' &H41
%DIJOFS_BUTTON18                                        = 66           ' &H42
%DIJOFS_BUTTON19                                        = 67           ' &H43
%DIJOFS_BUTTON20                                        = 68           ' &H44
%DIJOFS_BUTTON21                                        = 69           ' &H45
%DIJOFS_BUTTON22                                        = 70           ' &H46
%DIJOFS_BUTTON23                                        = 71           ' &H47
%DIJOFS_BUTTON24                                        = 72           ' &H48
%DIJOFS_BUTTON25                                        = 73           ' &H49
%DIJOFS_BUTTON26                                        = 74           ' &H4A
%DIJOFS_BUTTON27                                        = 75           ' &H4B
%DIJOFS_BUTTON28                                        = 76           ' &H4C
%DIJOFS_BUTTON29                                        = 77           ' &H4D
%DIJOFS_BUTTON30                                        = 78           ' &H4E
%DIJOFS_BUTTON31                                        = 79           ' &H4F

' ========================================================================================
' CONST_DIEFTFLAGS enum
' ========================================================================================

%DIEFT_ALL                                              = 0            ' &H0
%DIEFT_CONSTANTFORCE                                    = 1            ' &H1
%DIEFT_RAMPFORCE                                        = 2            ' &H2
%DIEFT_PERIODIC                                         = 3            ' &H3
%DIEFT_CONDITION                                        = 4            ' &H4
%DIEFT_CUSTOMFORCE                                      = 5            ' &H5
%DIEFT_HARDWARE                                         = 255          ' &HFF
%DIEFT_FFATTACK                                         = 512          ' &H200
%DIEFT_FFFADE                                           = 1024         ' &H400
%DIEFT_SATURATION                                       = 2048         ' &H800
%DIEFT_POSNEGCOEFFICIENTS                               = 4096         ' &H1000
%DIEFT_POSNEGSATURATION                                 = 8192         ' &H2000
%DIEFT_DEADBAND                                         = 16384        ' &H4000

' ========================================================================================
' CONST_DIEFFFLAGS enum
' ========================================================================================

%DIEFF_OBJECTOFFSETS                                    = 2            ' &H2
%DIEFF_CARTESIAN                                        = 16           ' &H10
%DIEFF_POLAR                                            = 32           ' &H20

' ========================================================================================
' CONST_DIEPFLAGS enum
' ========================================================================================

%DIEP_DURATION                                          = 1            ' &H1
%DIEP_SAMPLEPERIOD                                      = 2            ' &H2
%DIEP_GAIN                                              = 4            ' &H4
%DIEP_TRIGGERBUTTON                                     = 8            ' &H8
%DIEP_TRIGGERREPEATINTERVAL                             = 16           ' &H10
%DIEP_AXES                                              = 32           ' &H20
%DIEP_DIRECTION                                         = 64           ' &H40
%DIEP_ENVELOPE                                          = 128          ' &H80
%DIEP_TYPESPECIFICPARAMS                                = 256          ' &H100
%DIEP_ALLPARAMS                                         = 511          ' &H1FF
%DIEP_START                                             = 536870912    ' &H20000000
%DIEP_NORESTART                                         = 1073741824   ' &H40000000
%DIEP_NODOWNLOAD                                        = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DIEGESFLAGS enum
' ========================================================================================

%DIEGES_PLAYING                                         = 1            ' &H1
%DIEGES_EMULATED                                        = 2            ' &H2

' ========================================================================================
' CONST_DIESFLAGS enum
' ========================================================================================

%DIES_SOLO                                              = 1            ' &H1
%DIES_NODOWNLOAD                                        = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DISFFCFLAGS enum
' ========================================================================================

%DISFFC_RESET                                           = 1            ' &H1
%DISFFC_STOPALL                                         = 2            ' &H2
%DISFFC_PAUSE                                           = 4            ' &H4
%DISFFC_CONTINUE                                        = 8            ' &H8
%DISFFC_SETACTUATORSON                                  = 16           ' &H10
%DISFFC_SETACTUATORSOFF                                 = 32           ' &H20

' ========================================================================================
' CONST_DIGFFSFLAGS enum
' ========================================================================================

%DIGFFS_EMPTY                                           = 1            ' &H1
%DIGFFS_STOPPED                                         = 2            ' &H2
%DIGFFS_PAUSED                                          = 4            ' &H4
%DIGFFS_ACTUATORSON                                     = 16           ' &H10
%DIGFFS_ACTUATORSOFF                                    = 32           ' &H20
%DIGFFS_POWERON                                         = 64           ' &H40
%DIGFFS_POWEROFF                                        = 128          ' &H80
%DIGFFS_SAFETYSWITCHON                                  = 256          ' &H100
%DIGFFS_SAFETYSWITCHOFF                                 = 512          ' &H200
%DIGFFS_USERFFSWITCHON                                  = 1024         ' &H400
%DIGFFS_USERFFSWITCHOFF                                 = 2048         ' &H800
%DIGFFS_DEVICELOST                                      = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DISDDFLAGS enum
' ========================================================================================

%DISDD_DEFAULT                                          = 0            ' &H0
%DISDD_CONTINUE                                         = 1            ' &H1

' ========================================================================================
' CONST_DMUS_EFFECT_FLAGS enum
' ========================================================================================

%DMUS_EFFECT_NONE                                       = 0            ' &H0
%DMUS_EFFECT_REVERB                                     = 1            ' &H1
%DMUS_EFFECT_CHORUS                                     = 2            ' &H2

' ========================================================================================
' CONST_D3DDEVINFOID enum
' ========================================================================================

%D3DDEVINFOID_D3DTEXTUREMANAGER                         = 2            ' &H2
%D3DDEVINFOID_TEXTUREMANAGER                            = 1            ' &H1
%D3DDEVINFOID_TEXTURING                                 = 3            ' &H3

' ========================================================================================
' CONST_DDOVERFXFLAGS enum
' ========================================================================================

%DDOVERFX_ARITHSTRETCHY                                 = 1            ' &H1
%DDOVERFX_MIRRORLEFTRIGHT                               = 2            ' &H2
%DDOVERFX_MIRRORUPDOWN                                  = 4            ' &H4

' ========================================================================================
' CONST_D3DRMSHADOWFLAGS enum
' ========================================================================================

%D3DRMSHADOW_TRUEALPHA                                  = 1            ' &H1

' ========================================================================================
' CONST_DICONDITIONFLAGS enum
' ========================================================================================

%DICONDITION_USE_BOTH_AXES                              = 1            ' &H1
%DICONDITION_USE_DIRECTION                              = 2            ' &H2

' ========================================================================================
' CONST_D3DSTATEBLOCKTYPE enum
' ========================================================================================

%D3DSBT_ALL                                             = 1            ' &H1
%D3DSBT_PIXELSTATE                                      = 2            ' &H2
%D3DSBT_VERTEXSTATE                                     = 3            ' &H3

' ========================================================================================
' CONST_D3DCLIPPLANEFLAGS enum
' ========================================================================================

%D3DCPF_DISABLEALL                                      = 0            ' &H0
%D3DCPF_ENABLEPLANE0                                    = 1            ' &H1
%D3DCPF_ENABLEPLANE1                                    = 2            ' &H2
%D3DCPF_ENABLEPLANE2                                    = 4            ' &H4
%D3DCPF_ENABLEPLANE3                                    = 8            ' &H8
%D3DCPF_ENABLEPLANE4                                    = 16           ' &H10
%D3DCPF_ENABLEPLANE5                                    = 32           ' &H20
%D3DCPF_ENABLEPLANE6                                    = 64           ' &H40
%D3DCPF_ENABLEPLANE7                                    = 128          ' &H80
%D3DCPF_ENABLEPLANE8                                    = 256          ' &H100
%D3DCPF_ENABLEPLANE9                                    = 512          ' &H200
%D3DCPF_ENABLEPLANE10                                   = 1024         ' &H400
%D3DCPF_ENABLEPLANE11                                   = 2048         ' &H800
%D3DCPF_ENABLEPLANE12                                   = 4096         ' &H1000
%D3DCPF_ENABLEPLANE13                                   = 8192         ' &H2000
%D3DCPF_ENABLEPLANE14                                   = 16384        ' &H4000
%D3DCPF_ENABLEPLANE15                                   = 32768        ' &H8000
%D3DCPF_ENABLEPLANE16                                   = 65536        ' &H10000
%D3DCPF_ENABLEPLANE17                                   = 131072       ' &H20000
%D3DCPF_ENABLEPLANE18                                   = 262144       ' &H40000
%D3DCPF_ENABLEPLANE19                                   = 524288       ' &H80000
%D3DCPF_ENABLEPLANE20                                   = 1048576      ' &H100000
%D3DCPF_ENABLEPLANE21                                   = 2097152      ' &H200000
%D3DCPF_ENABLEPLANE22                                   = 4194304      ' &H400000
%D3DCPF_ENABLEPLANE23                                   = 8388608      ' &H800000
%D3DCPF_ENABLEPLANE24                                   = 16777216     ' &H1000000
%D3DCPF_ENABLEPLANE25                                   = 33554432     ' &H2000000
%D3DCPF_ENABLEPLANE26                                   = 67108864     ' &H4000000
%D3DCPF_ENABLEPLANE27                                   = 134217728    ' &H8000000
%D3DCPF_ENABLEPLANE28                                   = 268435456    ' &H10000000
%D3DCPF_ENABLEPLANE29                                   = 536870912    ' &H20000000
%D3DCPF_ENABLEPLANE30                                   = 1073741824   ' &H40000000
%D3DCPF_ENABLEPLANE31                                   = -2147483648  ' &H80000000

' ========================================================================================
' CONST_DMUS_NOTIFICATION_TYPE enum
' ========================================================================================

%DMUS_NOTIFY_ON_CHORD                                   = 1            ' &H1
%DMUS_NOTIFY_ON_COMMAND                                 = 2            ' &H2
%DMUS_NOTIFY_ON_MEASUREANDBEAT                          = 3            ' &H3
%DMUS_NOTIFY_ON_PERFORMANCE                             = 4            ' &H4
%DMUS_NOTIFY_ON_SEGMENT                                 = 5            ' &H5

' ========================================================================================
' RECT record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DXVB_RECT_DEFINED)
%DXVB_RECT_DEFINED = 1

TYPE DXVB_RECT
   Left AS LONG                                         ' VT_I4 <Long>
   Top AS LONG                                          ' VT_I4 <Long>
   Right AS LONG                                        ' VT_I4 <Long>
   Bottom AS LONG                                       ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DXGUID record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DXGUID_DEFINED)
%DXGUID_DEFINED = 1

TYPE DXGUID
   data1 AS LONG                                        ' VT_I4 <Long>
   data2 AS INTEGER                                     ' VT_I2 <Integer>
   data3 AS INTEGER                                     ' VT_I2 <Integer>
   data4 AS STRING * 8                                  ' %VT_CARRAY <VT_UI1 <Byte>>
END TYPE

#ENDIF

' ========================================================================================
' DPAPPLICATIONDESC2 record
' Number of members = 9
' ========================================================================================

#IF NOT %DEF(%DPAPPLICATIONDESC2_DEFINED)
%DPAPPLICATIONDESC2_DEFINED = 1

TYPE DPAPPLICATIONDESC2
   lFlags AS LONG                                       ' VT_I4 <Long>
   strApplicationName AS DWORD                          ' VT_BSTR
   strGuid AS DWORD                                     ' VT_BSTR
   strFilename AS DWORD                                 ' VT_BSTR
   strCommandLine AS DWORD                              ' VT_BSTR
   strPath AS DWORD                                     ' VT_BSTR
   strCurrentDirectory AS DWORD                         ' VT_BSTR
   strDescription AS DWORD                              ' VT_BSTR
   strAppLauncherName AS DWORD                          ' VT_BSTR
END TYPE

#ENDIF

' ========================================================================================
' DIRECTXREGISTERAPP record
' Number of members = 7
' ========================================================================================

#IF NOT %DEF(%DIRECTXREGISTERAPP_DEFINED)
%DIRECTXREGISTERAPP_DEFINED = 1

TYPE DIRECTXREGISTERAPP
   lFlags AS LONG                                       ' VT_I4 <Long>
   strApplicationName AS DWORD                          ' VT_BSTR
   strGuid AS DWORD                                     ' VT_BSTR
   strFilename AS DWORD                                 ' VT_BSTR
   strCommandLine AS DWORD                              ' VT_BSTR
   strPath AS DWORD                                     ' VT_BSTR
   strCurrentDirectory AS DWORD                         ' VT_BSTR
END TYPE

#ENDIF

' ========================================================================================
' PALETTEENTRY record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DXVB_PALETTEENTRY_DEFINED)
%DXVB_PALETTEENTRY_DEFINED = 1

TYPE DXVB_PALETTEENTRY
   red AS BYTE                                          ' VT_UI1 <Byte>
   green AS BYTE                                        ' VT_UI1 <Byte>
   blue AS BYTE                                         ' VT_UI1 <Byte>
   flags AS BYTE                                        ' VT_UI1 <Byte>
END TYPE

#ENDIF

' ========================================================================================
' D3DRECT record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%D3DRECT_DEFINED)
%D3DRECT_DEFINED = 1

' // Size = 16 bytes
TYPE D3DRECT DWORD
   x1 AS LONG                                           ' VT_I4 <Long>
   y1 AS LONG                                           ' VT_I4 <Long>
   x2 AS LONG                                           ' VT_I4 <Long>
   y2 AS LONG                                           ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DVECTOR record
' Number of members = 3
' ========================================================================================

#IF NOT %DEF(%D3DVECTOR_DEFINED)
%D3DVECTOR_DEFINED = 1

' // Size = 12 bytes
TYPE D3DVECTOR DWORD
   x AS SINGLE                                          ' VT_R4 <Single>
   y AS SINGLE                                          ' VT_R4 <Single>
   z AS SINGLE                                          ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DCOLORVALUE record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%D3DCOLORVALUE_DEFINED)
%D3DCOLORVALUE_DEFINED = 1

' // Size = 16 bytes
TYPE D3DCOLORVALUE DWORD
   r AS SINGLE                                          ' VT_R4 <Single>
   g AS SINGLE                                          ' VT_R4 <Single>
   b AS SINGLE                                          ' VT_R4 <Single>
   a AS SINGLE                                          ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DLINEPATTERN record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%D3DLINEPATTERN_DEFINED)
%D3DLINEPATTERN_DEFINED = 1

TYPE D3DLINEPATTERN
   repeatFactor AS LONG                                 ' VT_I4 <Long>
   linePatern AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DTLVERTEX record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DTLVERTEX_DEFINED)
%D3DTLVERTEX_DEFINED = 1

TYPE D3DTLVERTEX
   sx AS SINGLE                                         ' VT_R4 <Single>
   sy AS SINGLE                                         ' VT_R4 <Single>
   sz AS SINGLE                                         ' VT_R4 <Single>
   rhw AS SINGLE                                        ' VT_R4 <Single>
   color AS LONG                                        ' VT_I4 <Long>
   specular AS LONG                                     ' VT_I4 <Long>
   tu AS SINGLE                                         ' VT_R4 <Single>
   tv AS SINGLE                                         ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DLVERTEX record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DLVERTEX_DEFINED)
%D3DLVERTEX_DEFINED = 1

TYPE D3DLVERTEX
   x AS SINGLE                                          ' VT_R4 <Single>
   y AS SINGLE                                          ' VT_R4 <Single>
   z AS SINGLE                                          ' VT_R4 <Single>
   reserved AS LONG                                     ' VT_I4 <Long>
   color AS LONG                                        ' VT_I4 <Long>
   specular AS LONG                                     ' VT_I4 <Long>
   tu AS SINGLE                                         ' VT_R4 <Single>
   tv AS SINGLE                                         ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DVERTEX record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DVERTEX_DEFINED)
%D3DVERTEX_DEFINED = 1

TYPE D3DVERTEX
   x AS SINGLE                                          ' VT_R4 <Single>
   y AS SINGLE                                          ' VT_R4 <Single>
   z AS SINGLE                                          ' VT_R4 <Single>
   nx AS SINGLE                                         ' VT_R4 <Single>
   ny AS SINGLE                                         ' VT_R4 <Single>
   nz AS SINGLE                                         ' VT_R4 <Single>
   tu AS SINGLE                                         ' VT_R4 <Single>
   tv AS SINGLE                                         ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DCLIPSTATUS record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DCLIPSTATUS_DEFINED)
%D3DCLIPSTATUS_DEFINED = 1

TYPE D3DCLIPSTATUS
   lFlags AS LONG                                       ' CONST_D3DCLIPSTATUSFLAGS <enum>
   lStatus AS LONG                                      ' CONST_D3DCLIPFLAGS <enum>
   minx AS SINGLE                                       ' VT_R4 <Single>
   maxx AS SINGLE                                       ' VT_R4 <Single>
   miny AS SINGLE                                       ' VT_R4 <Single>
   maxy AS SINGLE                                       ' VT_R4 <Single>
   minz AS SINGLE                                       ' VT_R4 <Single>
   maxz AS SINGLE                                       ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DVIEWPORT7 record
' Number of members = 6
' ========================================================================================

#IF NOT %DEF(%D3DVIEWPORT7_DEFINED)
%D3DVIEWPORT7_DEFINED = 1

TYPE D3DVIEWPORT7
   lX AS LONG                                           ' VT_I4 <Long>
   lY AS LONG                                           ' VT_I4 <Long>
   lWidth AS LONG                                       ' VT_I4 <Long>
   lHeight AS LONG                                      ' VT_I4 <Long>
   minz AS SINGLE                                       ' VT_R4 <Single>
   maxz AS SINGLE                                       ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DLIGHTINGCAPS record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%D3DLIGHTINGCAPS_DEFINED)
%D3DLIGHTINGCAPS_DEFINED = 1

TYPE D3DLIGHTINGCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lCaps AS LONG                                        ' CONST_D3DLIGHTCAPSFLAGS <enum>
   lLightingModel AS LONG                               ' CONST_D3DLIGHTINGMODELFLAGS <enum>
   lNumLights AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DPRIMCAPS record
' Number of members = 14
' ========================================================================================

#IF NOT %DEF(%D3DPRIMCAPS_DEFINED)
%D3DPRIMCAPS_DEFINED = 1

TYPE D3DPRIMCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lMiscCaps AS LONG                                    ' CONST_D3DCAPSMISC <enum>
   lRasterCaps AS LONG                                  ' CONST_D3DCAPSRASTER <enum>
   lZCmpCaps AS LONG                                    ' CONST_D3DCAPSCMP <enum>
   lSrcBlendCaps AS LONG                                ' CONST_D3DCAPSBLEND <enum>
   lDestBlendCaps AS LONG                               ' CONST_D3DCAPSBLEND <enum>
   lAlphaCmpCaps AS LONG                                ' CONST_D3DCAPSCMP <enum>
   lShadeCaps AS LONG                                   ' CONST_D3DCAPSSHADE <enum>
   lTextureCaps AS LONG                                 ' CONST_D3DCAPSTEXTURE <enum>
   lTextureFilterCaps AS LONG                           ' CONST_D3DCAPSTEXTUREFILTER <enum>
   lReserved1 AS LONG                                   ' VT_I4 <Long>
   lTextureAddressCaps AS LONG                          ' CONST_D3DCAPSTEXTUREADDRESS <enum>
   lStippleWidth AS LONG                                ' VT_I4 <Long>
   lStippleHeight AS LONG                               ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DDEVICEDESC7 record
' Number of members = 32
' ========================================================================================

#IF NOT %DEF(%D3DDEVICEDESC7_DEFINED)
%D3DDEVICEDESC7_DEFINED = 1

TYPE D3DDEVICEDESC7
   lDevCaps AS LONG                                     ' CONST_D3DDEVICEDESCCAPS <enum>
   dpcLineCaps AS D3DPRIMCAPS                           ' D3DPRIMCAPS <record>
   dpcTriCaps AS D3DPRIMCAPS                            ' D3DPRIMCAPS <record>
   lDeviceRenderBitDepth AS LONG                        ' VT_I4 <Long>
   lDeviceZBufferBitDepth AS LONG                       ' VT_I4 <Long>
   lMinTextureWidth AS LONG                             ' VT_I4 <Long>
   lMinTextureHeight AS LONG                            ' VT_I4 <Long>
   lMaxTextureWidth AS LONG                             ' VT_I4 <Long>
   lMaxTextureHeight AS LONG                            ' VT_I4 <Long>
   lMaxTextureRepeat AS LONG                            ' VT_I4 <Long>
   lMaxTextureAspectRatio AS LONG                       ' VT_I4 <Long>
   lMaxAnisotropy AS LONG                               ' VT_I4 <Long>
   dvGuardBandLeft AS SINGLE                            ' VT_R4 <Single>
   dvGuardBandTop AS SINGLE                             ' VT_R4 <Single>
   dvGuardBandRight AS SINGLE                           ' VT_R4 <Single>
   dvGuardBandBottom AS SINGLE                          ' VT_R4 <Single>
   dvExtentsAdjust AS SINGLE                            ' VT_R4 <Single>
   lStencilCaps AS LONG                                 ' CONST_D3DSTENCILCAPSFLAGS <enum>
   lFVFCaps AS LONG                                     ' CONST_D3DFVFCAPSFLAGS <enum>
   lTextureOpCaps AS LONG                               ' CONST_D3DTEXOPCAPSFLAGS <enum>
   nMaxTextureBlendStages AS INTEGER                    ' VT_I2 <Integer>
   nMaxSimultaneousTextures AS INTEGER                  ' VT_I2 <Integer>
   lMaxActiveLights AS LONG                             ' VT_I4 <Long>
   dvMaxVertexW AS SINGLE                               ' VT_R4 <Single>
   deviceGuid AS DXGUID                                 ' DXGUID <record>
   nMaxUserClipPlanes AS INTEGER                        ' VT_I2 <Integer>
   nMaxVertexBlendMatrices AS INTEGER                   ' VT_I2 <Integer>
   lVertexProcessingCaps AS LONG                        ' CONST_D3DVTXPCAPSFLAGS <enum>
   lReserved1 AS LONG                                   ' VT_I4 <Long>
   lReserved2 AS LONG                                   ' VT_I4 <Long>
   lReserved3 AS LONG                                   ' VT_I4 <Long>
   lReserved4 AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DMATERIAL7 record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%D3DMATERIAL7_DEFINED)
%D3DMATERIAL7_DEFINED = 1

TYPE D3DMATERIAL7
   diffuse AS D3DCOLORVALUE                             ' D3DCOLORVALUE <record>
   ambient AS D3DCOLORVALUE                             ' D3DCOLORVALUE <record>
   specular AS D3DCOLORVALUE                            ' D3DCOLORVALUE <record>
   emissive AS D3DCOLORVALUE                            ' D3DCOLORVALUE <record>
   power AS SINGLE                                      ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DLIGHT7 record
' Number of members = 13
' ========================================================================================

#IF NOT %DEF(%D3DLIGHT7_DEFINED)
%D3DLIGHT7_DEFINED = 1

TYPE D3DLIGHT7
   dltType AS LONG                                      ' CONST_D3DLIGHTTYPE <enum>
   diffuse AS D3DCOLORVALUE                             ' D3DCOLORVALUE <record>
   specular AS D3DCOLORVALUE                            ' D3DCOLORVALUE <record>
   ambient AS D3DCOLORVALUE                             ' D3DCOLORVALUE <record>
   position AS D3DVECTOR                                ' D3DVECTOR <record>
   direction AS D3DVECTOR                               ' D3DVECTOR <record>
   range AS SINGLE                                      ' VT_R4 <Single>
   falloff AS SINGLE                                    ' VT_R4 <Single>
   attenuation0 AS SINGLE                               ' VT_R4 <Single>
   attenuation1 AS SINGLE                               ' VT_R4 <Single>
   attenuation2 AS SINGLE                               ' VT_R4 <Single>
   theta AS SINGLE                                      ' VT_R4 <Single>
   phi AS SINGLE                                        ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DMATRIX record
' Number of members = 16
' ========================================================================================

#IF NOT %DEF(%D3DMATRIX_DEFINED)
%D3DMATRIX_DEFINED = 1

TYPE D3DMATRIX
   rc11 AS SINGLE                                       ' VT_R4 <Single>
   rc12 AS SINGLE                                       ' VT_R4 <Single>
   rc13 AS SINGLE                                       ' VT_R4 <Single>
   rc14 AS SINGLE                                       ' VT_R4 <Single>
   rc21 AS SINGLE                                       ' VT_R4 <Single>
   rc22 AS SINGLE                                       ' VT_R4 <Single>
   rc23 AS SINGLE                                       ' VT_R4 <Single>
   rc24 AS SINGLE                                       ' VT_R4 <Single>
   rc31 AS SINGLE                                       ' VT_R4 <Single>
   rc32 AS SINGLE                                       ' VT_R4 <Single>
   rc33 AS SINGLE                                       ' VT_R4 <Single>
   rc34 AS SINGLE                                       ' VT_R4 <Single>
   rc41 AS SINGLE                                       ' VT_R4 <Single>
   rc42 AS SINGLE                                       ' VT_R4 <Single>
   rc43 AS SINGLE                                       ' VT_R4 <Single>
   rc44 AS SINGLE                                       ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMRAY record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%D3DRMRAY_DEFINED)
%D3DRMRAY_DEFINED = 1

TYPE D3DRMRAY
   dir AS D3DVECTOR                                     ' D3DVECTOR <record>
   pos AS D3DVECTOR                                     ' D3DVECTOR <record>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMQUATERNION record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%D3DRMQUATERNION_DEFINED)
%D3DRMQUATERNION_DEFINED = 1

TYPE D3DRMQUATERNION
   s AS SINGLE                                          ' VT_R4 <Single>
   v AS D3DVECTOR                                       ' D3DVECTOR <record>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMVECTOR4D record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%D3DRMVECTOR4D_DEFINED)
%D3DRMVECTOR4D_DEFINED = 1

TYPE D3DRMVECTOR4D
   x AS SINGLE                                          ' VT_R4 <Single>
   y AS SINGLE                                          ' VT_R4 <Single>
   z AS SINGLE                                          ' VT_R4 <Single>
   w AS SINGLE                                          ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMBOX record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%D3DRMBOX_DEFINED)
%D3DRMBOX_DEFINED = 1

TYPE D3DRMBOX
   min AS D3DVECTOR                                     ' D3DVECTOR <record>
   max AS D3DVECTOR                                     ' D3DVECTOR <record>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMPICKDESC record
' Number of members = 3
' ========================================================================================

#IF NOT %DEF(%D3DRMPICKDESC_DEFINED)
%D3DRMPICKDESC_DEFINED = 1

TYPE D3DRMPICKDESC
   lFaceIdx AS LONG                                     ' VT_I4 <Long>
   lGroupIdx AS LONG                                    ' VT_I4 <Long>
   vPosition AS D3DVECTOR                               ' D3DVECTOR <record>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMPICKDESC2 record
' Number of members = 7
' ========================================================================================

#IF NOT %DEF(%D3DRMPICKDESC2_DEFINED)
%D3DRMPICKDESC2_DEFINED = 1

TYPE D3DRMPICKDESC2
   lFaceIdx AS LONG                                     ' VT_I4 <Long>
   lGroupIdx AS LONG                                    ' VT_I4 <Long>
   vPostion AS D3DVECTOR                                ' D3DVECTOR <record>
   tu AS SINGLE                                         ' VT_R4 <Single>
   tv AS SINGLE                                         ' VT_R4 <Single>
   vNormal AS D3DVECTOR                                 ' D3DVECTOR <record>
   color AS LONG                                        ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMVERTEX record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%D3DRMVERTEX_DEFINED)
%D3DRMVERTEX_DEFINED = 1

TYPE D3DRMVERTEX
   position AS D3DVECTOR                                ' D3DVECTOR <record>
   normal AS D3DVECTOR                                  ' D3DVECTOR <record>
   tu AS SINGLE                                         ' VT_R4 <Single>
   tv AS SINGLE                                         ' VT_R4 <Single>
   color AS LONG                                        ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDCOLORKEY record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%DDCOLORKEY_DEFINED)
%DDCOLORKEY_DEFINED = 1

TYPE DDCOLORKEY
   low AS LONG                                          ' VT_I4 <Long>
   high AS LONG                                         ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDSCAPS2 record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DDSCAPS2_DEFINED)
%DDSCAPS2_DEFINED = 1

TYPE DDSCAPS2
   lCaps AS LONG                                        ' CONST_DDSURFACECAPSFLAGS <enum>
   lCaps2 AS LONG                                       ' CONST_DDSURFACECAPS2FLAGS <enum>
   lCaps3 AS LONG                                       ' VT_I4 <Long>
   lCaps4 AS LONG                                       ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDPIXELFORMAT record
' Number of members = 32
' ========================================================================================

#IF NOT %DEF(%DDPIXELFORMAT_DEFINED)
%DDPIXELFORMAT_DEFINED = 1

TYPE DDPIXELFORMAT
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DDPIXELFORMATFLAGS <enum>
   lFourCC AS LONG                                      ' VT_I4 <Long>
   internalVal1 AS LONG                                 ' VT_I4 <Long>
   internalVal2 AS LONG                                 ' VT_I4 <Long>
   internalVal3 AS LONG                                 ' VT_I4 <Long>
   internalVal4 AS LONG                                 ' VT_I4 <Long>
   internalVal5 AS LONG                                 ' VT_I4 <Long>
   lRGBBitCount AS LONG                                 ' VT_I4 <Long>
   lYUVBitCount AS LONG                                 ' VT_I4 <Long>
   lZBufferBitDepth AS LONG                             ' VT_I4 <Long>
   lAlphaBitDepth AS LONG                               ' VT_I4 <Long>
   lLuminanceBitCount AS LONG                           ' VT_I4 <Long>
   lBumpBitCount AS LONG                                ' VT_I4 <Long>
   lRBitMask AS LONG                                    ' VT_I4 <Long>
   lYBitMask AS LONG                                    ' VT_I4 <Long>
   lStencilBitDepth AS LONG                             ' VT_I4 <Long>
   lLuminanceBitMask AS LONG                            ' VT_I4 <Long>
   lBumpDuBitMask AS LONG                               ' VT_I4 <Long>
   lGBitMask AS LONG                                    ' VT_I4 <Long>
   lUBitMask AS LONG                                    ' VT_I4 <Long>
   lZBitMask AS LONG                                    ' VT_I4 <Long>
   lBumpDvBitMask AS LONG                               ' VT_I4 <Long>
   lBBitMask AS LONG                                    ' VT_I4 <Long>
   lVBitMask AS LONG                                    ' VT_I4 <Long>
   lStencilBitMask AS LONG                              ' VT_I4 <Long>
   lBumpLuminanceBitMask AS LONG                        ' VT_I4 <Long>
   lRGBAlphaBitMask AS LONG                             ' VT_I4 <Long>
   lYUVAlphaBitMask AS LONG                             ' VT_I4 <Long>
   lLuminanceAlphaBitMask AS LONG                       ' VT_I4 <Long>
   lRGBZBitMask AS LONG                                 ' VT_I4 <Long>
   lYUVZBitMask AS LONG                                 ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDSURFACEDESC2 record
' Number of members = 20
' ========================================================================================

#IF NOT %DEF(%DDSURFACEDESC2_DEFINED)
%DDSURFACEDESC2_DEFINED = 1

TYPE DDSURFACEDESC2
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DDSURFACEDESCFLAGS <enum>
   lHeight AS LONG                                      ' VT_I4 <Long>
   lWidth AS LONG                                       ' VT_I4 <Long>
   lPitch AS LONG                                       ' VT_I4 <Long>
   lBackBufferCount AS LONG                             ' VT_I4 <Long>
   lZBufferBitDepth AS LONG                             ' VT_I4 <Long>
   lAlphaBitDepth AS LONG                               ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
   lpSurface AS LONG                                    ' VT_I4 <Long>
   ddckCKDestOverlay AS DDCOLORKEY                      ' DDCOLORKEY <record>
   ddckCKDestBlt AS DDCOLORKEY                          ' DDCOLORKEY <record>
   ddckCKSrcOverlay AS DDCOLORKEY                       ' DDCOLORKEY <record>
   ddckCKSrcBlt AS DDCOLORKEY                           ' DDCOLORKEY <record>
   ddpfPixelFormat AS DDPIXELFORMAT                     ' DDPIXELFORMAT <record>
   ddsCaps AS DDSCAPS2                                  ' DDSCAPS2 <record>
   lTextureStage AS LONG                                ' VT_I4 <Long>
   lLinearSize AS LONG                                  ' VT_I4 <Long>
   lMipMapCount AS LONG                                 ' VT_I4 <Long>
   lRefreshRate AS LONG                                 ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDCAPS record
' Number of members = 57
' ========================================================================================

#IF NOT %DEF(%DDCAPS_DEFINED)
%DDCAPS_DEFINED = 1

TYPE DDCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lCaps AS LONG                                        ' CONST_DDCAPS1FLAGS <enum>
   lCaps2 AS LONG                                       ' CONST_DDCAPS2FLAGS <enum>
   lCKeyCaps AS LONG                                    ' CONST_DDCKEYCAPSFLAGS <enum>
   lFXCaps AS LONG                                      ' CONST_DDFXCAPSFLAGS <enum>
   lFXAlphaCaps AS LONG                                 ' VT_I4 <Long>
   lPalCaps AS LONG                                     ' CONST_DDPCAPSFLAGS <enum>
   lSVCaps AS LONG                                      ' CONST_DDSTEREOCAPSFLAGS <enum>
   lAlphaBltConstBitDepths AS LONG                      ' VT_I4 <Long>
   lAlphaBltPixelBitDepths AS LONG                      ' VT_I4 <Long>
   lAlphaBltSurfaceBitDepths AS LONG                    ' VT_I4 <Long>
   lAlphaOverlayConstBitDepths AS LONG                  ' VT_I4 <Long>
   lAlphaOverlayPixelBitDepths AS LONG                  ' VT_I4 <Long>
   lAlphaOverlaySurfaceBitDepths AS LONG                ' VT_I4 <Long>
   lZBufferBitDepths AS LONG                            ' VT_I4 <Long>
   lVidMemTotal AS LONG                                 ' VT_I4 <Long>
   lVidMemFree AS LONG                                  ' VT_I4 <Long>
   lMaxVisibleOverlays AS LONG                          ' VT_I4 <Long>
   lCurrVisibleOverlays AS LONG                         ' VT_I4 <Long>
   lNumFourCCCodes AS LONG                              ' VT_I4 <Long>
   lAlignBoundarySrc AS LONG                            ' VT_I4 <Long>
   lAlignSizeSrc AS LONG                                ' VT_I4 <Long>
   lAlignBoundaryDest AS LONG                           ' VT_I4 <Long>
   lAlignSizeDest AS LONG                               ' VT_I4 <Long>
   lAlignStrideAlign AS LONG                            ' VT_I4 <Long>
   lRops (7) AS LONG                                    ' %VT_CARRAY <VT_I4 <Long>>
   lReservedCaps AS LONG                                ' VT_I4 <Long>
   lMinOverlayStretch AS LONG                           ' VT_I4 <Long>
   lMaxOverlayStretch AS LONG                           ' VT_I4 <Long>
   lMinLiveVideoStretch AS LONG                         ' VT_I4 <Long>
   lMaxLiveVideoStretch AS LONG                         ' VT_I4 <Long>
   lMinHwCodecStretch AS LONG                           ' VT_I4 <Long>
   lMaxHwCodecStretch AS LONG                           ' VT_I4 <Long>
   lReserved1 AS LONG                                   ' VT_I4 <Long>
   lReserved2 AS LONG                                   ' VT_I4 <Long>
   lReserved3 AS LONG                                   ' VT_I4 <Long>
   lSVBCaps AS LONG                                     ' CONST_DDCAPS1FLAGS <enum>
   lSVBCKeyCaps AS LONG                                 ' CONST_DDCKEYCAPSFLAGS <enum>
   lSVBFXCaps AS LONG                                   ' CONST_DDFXCAPSFLAGS <enum>
   lSVBRops (7) AS LONG                                 ' %VT_CARRAY <VT_I4 <Long>>
   lVSBCaps AS LONG                                     ' CONST_DDCAPS1FLAGS <enum>
   lVSBCKeyCaps AS LONG                                 ' CONST_DDCKEYCAPSFLAGS <enum>
   lVSBFXCaps AS LONG                                   ' CONST_DDFXCAPSFLAGS <enum>
   lVSRops (7) AS LONG                                  ' %VT_CARRAY <VT_I4 <Long>>
   lSSBCaps AS LONG                                     ' CONST_DDCAPS1FLAGS <enum>
   lSSBCKeyCaps AS LONG                                 ' CONST_DDCKEYCAPSFLAGS <enum>
   lSSBFXCaps AS LONG                                   ' CONST_DDFXCAPSFLAGS <enum>
   lSSBRops (7) AS LONG                                 ' %VT_CARRAY <VT_I4 <Long>>
   lMaxVideoPorts AS LONG                               ' VT_I4 <Long>
   lCurrVideoPorts AS LONG                              ' VT_I4 <Long>
   lSVBCaps2 AS LONG                                    ' CONST_DDCAPS2FLAGS <enum>
   lNLVBCaps AS LONG                                    ' CONST_DDCAPS1FLAGS <enum>
   lNLVBCaps2 AS LONG                                   ' CONST_DDCAPS2FLAGS <enum>
   lNLVBCKeyCaps AS LONG                                ' CONST_DDCKEYCAPSFLAGS <enum>
   lNLVBFXCaps AS LONG                                  ' CONST_DDFXCAPSFLAGS <enum>
   lNLVBRops (7) AS LONG                                ' %VT_CARRAY <VT_I4 <Long>>
   ddsCaps AS DDSCAPS2                                  ' DDSCAPS2 <record>
END TYPE

#ENDIF

' ========================================================================================
' DDBLTFX record
' Number of members = 25
' ========================================================================================

#IF NOT %DEF(%DDBLTFX_DEFINED)
%DDBLTFX_DEFINED = 1

TYPE DDBLTFX
   lSize AS LONG                                        ' VT_I4 <Long>
   lDDFX AS LONG                                        ' CONST_DDBLTFXFLAGS <enum>
   lROP AS LONG                                         ' VT_I4 <Long>
   lDDROP AS LONG                                       ' VT_I4 <Long>
   lRotationAngle AS LONG                               ' VT_I4 <Long>
   lZBufferOpCode AS LONG                               ' VT_I4 <Long>
   lZBufferLow AS LONG                                  ' VT_I4 <Long>
   lZBufferHigh AS LONG                                 ' VT_I4 <Long>
   lZBufferBaseDest AS LONG                             ' VT_I4 <Long>
   lZDestConstBitDepth AS LONG                          ' VT_I4 <Long>
   lZDestConst AS LONG                                  ' VT_I4 <Long>
   lZSrcConstBitDepth AS LONG                           ' VT_I4 <Long>
   lZSrcConst AS LONG                                   ' VT_I4 <Long>
   lAlphaEdgeBlendBitDepth AS LONG                      ' VT_I4 <Long>
   lAlphaEdgeBlend AS LONG                              ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
   lAlphaDestConstBitDepth AS LONG                      ' VT_I4 <Long>
   lAlphaDestConst AS LONG                              ' VT_I4 <Long>
   lAlphaSrcConstBitDepth AS LONG                       ' VT_I4 <Long>
   lAlphaSrcConst AS LONG                               ' VT_I4 <Long>
   lFill AS LONG                                        ' VT_I4 <Long>
   ddckDestColorKey_low AS LONG                         ' VT_I4 <Long>
   ddckDestColorKey_high AS LONG                        ' VT_I4 <Long>
   ddckSrcColorKey_low AS LONG                          ' VT_I4 <Long>
   ddckSrcColorKey_high AS LONG                         ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDCOLORCONTROL record
' Number of members = 10
' ========================================================================================

#IF NOT %DEF(%DDCOLORCONTROL_DEFINED)
%DDCOLORCONTROL_DEFINED = 1

TYPE DDCOLORCONTROL
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DDCOLORFLAGS <enum>
   lBrightness AS LONG                                  ' VT_I4 <Long>
   lContrast AS LONG                                    ' VT_I4 <Long>
   lHue AS LONG                                         ' VT_I4 <Long>
   lSaturation AS LONG                                  ' VT_I4 <Long>
   lSharpness AS LONG                                   ' VT_I4 <Long>
   lGamma AS LONG                                       ' VT_I4 <Long>
   lColorEnable AS LONG                                 ' VT_I4 <Long>
   lReserved1 AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDGAMMARAMP record
' Number of members = 3
' ========================================================================================

#IF NOT %DEF(%DDGAMMARAMP_DEFINED)
%DDGAMMARAMP_DEFINED = 1

TYPE DDGAMMARAMP
   red (255) AS INTEGER                                 ' %VT_CARRAY <VT_I2 <Integer>>
   green (255) AS INTEGER                               ' %VT_CARRAY <VT_I2 <Integer>>
   blue (255) AS INTEGER                                ' %VT_CARRAY <VT_I2 <Integer>>
END TYPE

#ENDIF

' ========================================================================================
' D3DVERTEXBUFFERDESC record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%D3DVERTEXBUFFERDESC_DEFINED)
%D3DVERTEXBUFFERDESC_DEFINED = 1

TYPE D3DVERTEXBUFFERDESC
   lSize AS LONG                                        ' VT_I4 <Long>
   lCaps AS LONG                                        ' CONST_D3DVBCAPSFLAGS <enum>
   lFVF AS LONG                                         ' CONST_D3DFVFFLAGS <enum>
   lNumVertices AS LONG                                 ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSBCAPS record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%DSBCAPS_DEFINED)
%DSBCAPS_DEFINED = 1

TYPE DSBCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSBCAPSFLAGS <enum>
   lBufferBytes AS LONG                                 ' VT_I4 <Long>
   lUnlockTransferRate AS LONG                          ' VT_I4 <Long>
   lPlayCpuOverhead AS LONG                             ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSCAPS record
' Number of members = 24
' ========================================================================================

#IF NOT %DEF(%DSCAPS_DEFINED)
%DSCAPS_DEFINED = 1

TYPE DSCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSCAPSFLAGS <enum>
   lMinSecondarySampleRate AS LONG                      ' VT_I4 <Long>
   lMaxSecondarySampleRate AS LONG                      ' VT_I4 <Long>
   lPrimaryBuffers AS LONG                              ' VT_I4 <Long>
   lMaxHwMixingAllBuffers AS LONG                       ' VT_I4 <Long>
   lMaxHwMixingStaticBuffers AS LONG                    ' VT_I4 <Long>
   lMaxHwMixingStreamingBuffers AS LONG                 ' VT_I4 <Long>
   lFreeHwMixingAllBuffers AS LONG                      ' VT_I4 <Long>
   lFreeHwMixingStaticBuffers AS LONG                   ' VT_I4 <Long>
   lFreeHwMixingStreamingBuffers AS LONG                ' VT_I4 <Long>
   lMaxHw3DAllBuffers AS LONG                           ' VT_I4 <Long>
   lMaxHw3DStaticBuffers AS LONG                        ' VT_I4 <Long>
   lMaxHw3DStreamingBuffers AS LONG                     ' VT_I4 <Long>
   lFreeHw3DAllBuffers AS LONG                          ' VT_I4 <Long>
   lFreeHw3DStaticBuffers AS LONG                       ' VT_I4 <Long>
   lFreeHw3DStreamingBuffers AS LONG                    ' VT_I4 <Long>
   lTotalHwMemBytes AS LONG                             ' VT_I4 <Long>
   lFreeHwMemBytes AS LONG                              ' VT_I4 <Long>
   lMaxContigFreeHwMemBytes AS LONG                     ' VT_I4 <Long>
   lUnlockTransferRateHwBuffers AS LONG                 ' VT_I4 <Long>
   lPlayCpuOverheadSwBuffers AS LONG                    ' VT_I4 <Long>
   lReserved1 AS LONG                                   ' VT_I4 <Long>
   lReserved2 AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' WAVEFORMATEX record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%DXVB_WAVEFORMATEX_DEFINED)
%DXVB_WAVEFORMATEX_DEFINED = 1

TYPE DXVB_WAVEFORMATEX
   nFormatTag AS INTEGER                                ' VT_I2 <Integer>
   nChannels AS INTEGER                                 ' VT_I2 <Integer>
   lSamplesPerSec AS LONG                               ' VT_I4 <Long>
   lAvgBytesPerSec AS LONG                              ' VT_I4 <Long>
   nBlockAlign AS INTEGER                               ' VT_I2 <Integer>
   nBitsPerSample AS INTEGER                            ' VT_I2 <Integer>
   nSize AS INTEGER                                     ' VT_I2 <Integer>
   lExtra AS LONG                                       ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSBUFFERDESC record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%DSBUFFERDESC_DEFINED)
%DSBUFFERDESC_DEFINED = 1

TYPE DSBUFFERDESC
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSBCAPSFLAGS <enum>
   lBufferBytes AS LONG                                 ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
   lpwfxFormat AS LONG                                  ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSCURSORS record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%DSCURSORS_DEFINED)
%DSCURSORS_DEFINED = 1

TYPE DSCURSORS
   lPlay AS LONG                                        ' VT_I4 <Long>
   lWrite AS LONG                                       ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DS3DBUFFER record
' Number of members = 10
' ========================================================================================

#IF NOT %DEF(%DS3DBUFFER_DEFINED)
%DS3DBUFFER_DEFINED = 1

TYPE DS3DBUFFER
   lSize AS LONG                                        ' VT_I4 <Long>
   vPostion AS D3DVECTOR                                ' D3DVECTOR <record>
   vVelocity AS D3DVECTOR                               ' D3DVECTOR <record>
   lInsideConeAngle AS LONG                             ' VT_I4 <Long>
   lOutsideConeAngle AS LONG                            ' VT_I4 <Long>
   vConeOrientation AS D3DVECTOR                        ' D3DVECTOR <record>
   lConeOutsideVolume AS LONG                           ' VT_I4 <Long>
   minDistance AS SINGLE                                ' VT_R4 <Single>
   maxDistance AS SINGLE                                ' VT_R4 <Single>
   lMode AS LONG                                        ' CONST_DS3DMODEFLAGS <enum>
END TYPE

#ENDIF

' ========================================================================================
' DS3DLISTENER record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%DS3DLISTENER_DEFINED)
%DS3DLISTENER_DEFINED = 1

TYPE DS3DLISTENER
   lSize AS LONG                                        ' VT_I4 <Long>
   vPosition AS D3DVECTOR                               ' D3DVECTOR <record>
   vVelocity AS D3DVECTOR                               ' D3DVECTOR <record>
   vOrientFront AS D3DVECTOR                            ' D3DVECTOR <record>
   vOrientTop AS D3DVECTOR                              ' D3DVECTOR <record>
   distanceFactor AS SINGLE                             ' VT_R4 <Single>
   rolloffFactor AS SINGLE                              ' VT_R4 <Single>
   dopplerFactor AS SINGLE                              ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' DSCBCAPS record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DSCBCAPS_DEFINED)
%DSCBCAPS_DEFINED = 1

TYPE DSCBCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSCBCAPSFLAGS <enum>
   lBufferBytes AS LONG                                 ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSCCAPS record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DSCCAPS_DEFINED)
%DSCCAPS_DEFINED = 1

TYPE DSCCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSCCAPSFLAGS <enum>
   lFormats AS LONG                                     ' CONST_WAVEFORMATFLAGS <enum>
   lChannels AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DSCBUFFERDESC record
' Number of members = 6
' ========================================================================================

#IF NOT %DEF(%DSCBUFFERDESC_DEFINED)
%DSCBUFFERDESC_DEFINED = 1

TYPE DSCBUFFERDESC
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DSCBCAPSFLAGS <enum>
   lBufferBytes AS LONG                                 ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
   pFormat AS LONG                                      ' VT_I4 <Long>
   fxFormat AS DXVB_WAVEFORMATEX                        ' WAVEFORMATEX <record>
END TYPE

#ENDIF

' ========================================================================================
' DSBPOSITIONNOTIFY record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%DSBPOSITIONNOTIFY_DEFINED)
%DSBPOSITIONNOTIFY_DEFINED = 1

TYPE DSBPOSITIONNOTIFY
   lOffset AS LONG                                      ' VT_I4 <Long>
   hEventNotify AS LONG                                 ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DPCREDENTIALS record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DPCREDENTIALS_DEFINED)
%DPCREDENTIALS_DEFINED = 1

TYPE DPCREDENTIALS
   lFlags AS LONG                                       ' VT_I4 <Long>
   strUsername AS DWORD                                 ' VT_BSTR
   strPassword AS DWORD                                 ' VT_BSTR
   strDomain AS DWORD                                   ' VT_BSTR
END TYPE

#ENDIF

' ========================================================================================
' DPSECURITYDESC record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%DPSECURITYDESC_DEFINED)
%DPSECURITYDESC_DEFINED = 1

TYPE DPSECURITYDESC
   lFlags AS LONG                                       ' VT_I4 <Long>
   strSSPIProvider AS DWORD                             ' VT_BSTR
   strCAPIProvider AS DWORD                             ' VT_BSTR
   lCAPIProviderType AS LONG                            ' VT_I4 <Long>
   lEncryptionAlgorithm AS LONG                         ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DPCAPS record
' Number of members = 10
' ========================================================================================

#IF NOT %DEF(%DPCAPS_DEFINED)
%DPCAPS_DEFINED = 1

TYPE DPCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DPCAPSFLAGS <enum>
   lMaxBufferSize AS LONG                               ' VT_I4 <Long>
   lMaxQueueSize AS LONG                                ' VT_I4 <Long>
   lMaxPlayers AS LONG                                  ' VT_I4 <Long>
   lHundredBaud AS LONG                                 ' VT_I4 <Long>
   lLatency AS LONG                                     ' VT_I4 <Long>
   lMaxLocalPlayers AS LONG                             ' VT_I4 <Long>
   lHeaderLength AS LONG                                ' VT_I4 <Long>
   lTimeout AS LONG                                     ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIDEVCAPS record
' Number of members = 11
' ========================================================================================

#IF NOT %DEF(%DIDEVCAPS_DEFINED)
%DIDEVCAPS_DEFINED = 1

TYPE DIDEVCAPS
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DIDEVCAPSFLAGS <enum>
   lDevType AS LONG                                     ' CONST_DIDEVICETYPE <enum>
   lAxes AS LONG                                        ' VT_I4 <Long>
   lButtons AS LONG                                     ' VT_I4 <Long>
   lPOVs AS LONG                                        ' VT_I4 <Long>
   lFFSamplePeriod AS LONG                              ' VT_I4 <Long>
   lFFMinTimeResolution AS LONG                         ' VT_I4 <Long>
   lFirmwareRevision AS LONG                            ' VT_I4 <Long>
   lHardwareRevision AS LONG                            ' VT_I4 <Long>
   lDriverVersion AS LONG                               ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIDEVICEOBJECTDATA record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DIDEVICEOBJECTDATA_DEFINED)
%DIDEVICEOBJECTDATA_DEFINED = 1

TYPE DIDEVICEOBJECTDATA
   lOfs AS LONG                                         ' VT_I4 <Long>
   lData AS LONG                                        ' VT_I4 <Long>
   lTimeStamp AS LONG                                   ' VT_I4 <Long>
   lSequence AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIPROPRANGE record
' Number of members = 6
' ========================================================================================

#IF NOT %DEF(%DIPROPRANGE_DEFINED)
%DIPROPRANGE_DEFINED = 1

TYPE DIPROPRANGE
   lSize AS LONG                                        ' VT_I4 <Long>
   lHeaderSize AS LONG                                  ' VT_I4 <Long>
   lObj AS LONG                                         ' VT_I4 <Long>
   lHow AS LONG                                         ' VT_I4 <Long>
   lMin AS LONG                                         ' VT_I4 <Long>
   lMax AS LONG                                         ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIPROPLONG record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%DIPROPLONG_DEFINED)
%DIPROPLONG_DEFINED = 1

TYPE DIPROPLONG
   lSize AS LONG                                        ' VT_I4 <Long>
   lHeaderSize AS LONG                                  ' VT_I4 <Long>
   lObj AS LONG                                         ' VT_I4 <Long>
   lHow AS LONG                                         ' VT_I4 <Long>
   lData AS LONG                                        ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIOBJECTDATAFORMAT record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DIOBJECTDATAFORMAT_DEFINED)
%DIOBJECTDATAFORMAT_DEFINED = 1

TYPE DIOBJECTDATAFORMAT
   strGuid AS DWORD                                     ' VT_BSTR
   lOfs AS LONG                                         ' VT_I4 <Long>
   lType AS LONG                                        ' CONST_DIDFTFLAGS <enum>
   lFlags AS LONG                                       ' CONST_DIDEVICEOBJINSTANCEFLAGS <enum>
END TYPE

#ENDIF

' ========================================================================================
' DIDATAFORMAT record
' Number of members = 6
' ========================================================================================

#IF NOT %DEF(%DIDATAFORMAT_DEFINED)
%DIDATAFORMAT_DEFINED = 1

TYPE DIDATAFORMAT
   lSize AS LONG                                        ' VT_I4 <Long>
   lObjSize AS LONG                                     ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DIDATAFORMATFLAGS <enum>
   dataSize AS LONG                                     ' VT_I4 <Long>
   numObjs AS LONG                                      ' VT_I4 <Long>
   pData AS LONG                                        ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIMOUSESTATE record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DIMOUSESTATE_DEFINED)
%DIMOUSESTATE_DEFINED = 1

TYPE DIMOUSESTATE
   x AS LONG                                            ' VT_I4 <Long>
   y AS LONG                                            ' VT_I4 <Long>
   z AS LONG                                            ' VT_I4 <Long>
   buttons (3) AS BYTE                                  ' %VT_CARRAY <VT_UI1 <Byte>>
END TYPE

#ENDIF

' ========================================================================================
' DIKEYBOARDSTATE record
' Number of members = 1
' ========================================================================================

#IF NOT %DEF(%DIKEYBOARDSTATE_DEFINED)
%DIKEYBOARDSTATE_DEFINED = 1

TYPE DIKEYBOARDSTATE
   key (255) AS BYTE                                    ' %VT_CARRAY <VT_UI1 <Byte>>
END TYPE

#ENDIF

' ========================================================================================
' DIJOYSTATE record
' Number of members = 9
' ========================================================================================

#IF NOT %DEF(%DIJOYSTATE_DEFINED)
%DIJOYSTATE_DEFINED = 1

TYPE DIJOYSTATE
   x AS LONG                                            ' VT_I4 <Long>
   y AS LONG                                            ' VT_I4 <Long>
   z AS LONG                                            ' VT_I4 <Long>
   rx AS LONG                                           ' VT_I4 <Long>
   ry AS LONG                                           ' VT_I4 <Long>
   rz AS LONG                                           ' VT_I4 <Long>
   slider (1) AS LONG                                   ' %VT_CARRAY <VT_I4 <Long>>
   POV (3) AS LONG                                      ' %VT_CARRAY <VT_I4 <Long>>
   buttons (31) AS BYTE                                 ' %VT_CARRAY <VT_UI1 <Byte>>
END TYPE

#ENDIF

' ========================================================================================
' DIJOYSTATE2 record
' Number of members = 30
' ========================================================================================

#IF NOT %DEF(%DIJOYSTATE2_DEFINED)
%DIJOYSTATE2_DEFINED = 1

TYPE DIJOYSTATE2
   x AS LONG                                            ' VT_I4 <Long>
   y AS LONG                                            ' VT_I4 <Long>
   z AS LONG                                            ' VT_I4 <Long>
   rx AS LONG                                           ' VT_I4 <Long>
   ry AS LONG                                           ' VT_I4 <Long>
   rz AS LONG                                           ' VT_I4 <Long>
   slider (1) AS LONG                                   ' %VT_CARRAY <VT_I4 <Long>>
   POV (3) AS LONG                                      ' %VT_CARRAY <VT_I4 <Long>>
   buttons (127) AS BYTE                                ' %VT_CARRAY <VT_UI1 <Byte>>
   vx AS LONG                                           ' VT_I4 <Long>
   vy AS LONG                                           ' VT_I4 <Long>
   vz AS LONG                                           ' VT_I4 <Long>
   vrx AS LONG                                          ' VT_I4 <Long>
   vry AS LONG                                          ' VT_I4 <Long>
   vrz AS LONG                                          ' VT_I4 <Long>
   vslider (1) AS LONG                                  ' %VT_CARRAY <VT_I4 <Long>>
   ax AS LONG                                           ' VT_I4 <Long>
   ay AS LONG                                           ' VT_I4 <Long>
   az AS LONG                                           ' VT_I4 <Long>
   arx AS LONG                                          ' VT_I4 <Long>
   ary AS LONG                                          ' VT_I4 <Long>
   arz AS LONG                                          ' VT_I4 <Long>
   aslider (1) AS LONG                                  ' %VT_CARRAY <VT_I4 <Long>>
   fx AS LONG                                           ' VT_I4 <Long>
   fy AS LONG                                           ' VT_I4 <Long>
   fz AS LONG                                           ' VT_I4 <Long>
   frx AS LONG                                          ' VT_I4 <Long>
   fry AS LONG                                          ' VT_I4 <Long>
   frz AS LONG                                          ' VT_I4 <Long>
   fslider (1) AS LONG                                  ' %VT_CARRAY <VT_I4 <Long>>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMPMESHLOADSTATUS record
' Number of members = 7
' ========================================================================================

#IF NOT %DEF(%D3DRMPMESHLOADSTATUS_DEFINED)
%D3DRMPMESHLOADSTATUS_DEFINED = 1

TYPE D3DRMPMESHLOADSTATUS
   lSize AS LONG                                        ' VT_I4 <Long>
   lPMeshSize AS LONG                                   ' VT_I4 <Long>
   lBaseMeshSize AS LONG                                ' VT_I4 <Long>
   lBytesLoaded AS LONG                                 ' VT_I4 <Long>
   lVerticesLoaded AS LONG                              ' VT_I4 <Long>
   lFacesLoaded AS LONG                                 ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_D3DRMPMESHSTATUSFLAGS <enum>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMANIMATIONKEY record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DRMANIMATIONKEY_DEFINED)
%D3DRMANIMATIONKEY_DEFINED = 1

TYPE D3DRMANIMATIONKEY
   lSize AS LONG                                        ' VT_I4 <Long>
   lKeyType AS LONG                                     ' VT_I4 <Long>
   dvTime AS SINGLE                                     ' VT_R4 <Single>
   lID AS LONG                                          ' VT_I4 <Long>
   dvX AS SINGLE                                        ' VT_R4 <Single>
   dvY AS SINGLE                                        ' VT_R4 <Single>
   dvZ AS SINGLE                                        ' VT_R4 <Single>
   dvS AS SINGLE                                        ' VT_R4 <Single>
END TYPE

#ENDIF

' ========================================================================================
' D3DRMMATERIALOVERRIDE record
' Number of members = 8
' ========================================================================================

#IF NOT %DEF(%D3DRMMATERIALOVERRIDE_DEFINED)
%D3DRMMATERIALOVERRIDE_DEFINED = 1

TYPE D3DRMMATERIALOVERRIDE
   lSize AS LONG                                        ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_D3DRMMATERIALOVERRIDEFLAGS <enum>
   dcDiffuse AS D3DCOLORVALUE                           ' D3DCOLORVALUE <record>
   dcAmbient AS D3DCOLORVALUE                           ' D3DCOLORVALUE <record>
   dcEmissive AS D3DCOLORVALUE                          ' D3DCOLORVALUE <record>
   dcSpecular AS D3DCOLORVALUE                          ' D3DCOLORVALUE <record>
   dvPower AS SINGLE                                    ' VT_R4 <Single>
   pTex AS DWORD                                        ' VT_UNKNOWN <IUnknown>
END TYPE

#ENDIF

' ========================================================================================
' DMUS_TIMESIGNATURE record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DMUS_TIMESIGNATURE_DEFINED)
%DMUS_TIMESIGNATURE_DEFINED = 1

TYPE DMUS_TIMESIGNATURE
   mtTime AS LONG                                       ' VT_I4 <Long>
   beatsPerMeasure AS BYTE                              ' VT_UI1 <Byte>
   beat AS BYTE                                         ' VT_UI1 <Byte>
   gridsPerBeat AS INTEGER                              ' VT_I2 <Integer>
END TYPE

#ENDIF

' ========================================================================================
' DMUS_NOTIFICATION_PMSG record
' Number of members = 7
' ========================================================================================

#IF NOT %DEF(%DMUS_NOTIFICATION_PMSG_DEFINED)
%DMUS_NOTIFICATION_PMSG_DEFINED = 1

TYPE DMUS_NOTIFICATION_PMSG
   lFlags AS LONG                                       ' VT_I4 <Long>
   ctTime AS LONG                                       ' VT_I4 <Long>
   mtTime AS LONG                                       ' VT_I4 <Long>
   lNotificationType AS LONG                            ' VT_I4 <Long>
   lNotificationOption AS LONG                          ' VT_I4 <Long>
   lField1 AS LONG                                      ' VT_I4 <Long>
   lField2 AS LONG                                      ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DMUS_CURVE_PMSG record
' Number of members = 14
' ========================================================================================

#IF NOT %DEF(%DMUS_CURVE_PMSG_DEFINED)
%DMUS_CURVE_PMSG_DEFINED = 1

TYPE DMUS_CURVE_PMSG
   mtDuration AS LONG                                   ' VT_I4 <Long>
   mtOriginalStart AS LONG                              ' VT_I4 <Long>
   mtResetDuration AS LONG                              ' VT_I4 <Long>
   startValue AS INTEGER                                ' VT_I2 <Integer>
   endValue AS INTEGER                                  ' VT_I2 <Integer>
   resetValue AS INTEGER                                ' VT_I2 <Integer>
   measure AS INTEGER                                   ' VT_I2 <Integer>
   offset AS INTEGER                                    ' VT_I2 <Integer>
   beat AS BYTE                                         ' VT_UI1 <Byte>
   grid AS BYTE                                         ' VT_UI1 <Byte>
   type AS BYTE                                         ' VT_UI1 <Byte>
   curveShape AS BYTE                                   ' VT_UI1 <Byte>
   ccData AS BYTE                                       ' VT_UI1 <Byte>
   flags AS BYTE                                        ' VT_UI1 <Byte>
END TYPE

#ENDIF

' ========================================================================================
' DMUS_NOTE_PMSG record
' Number of members = 15
' ========================================================================================

#IF NOT %DEF(%DMUS_NOTE_PMSG_DEFINED)
%DMUS_NOTE_PMSG_DEFINED = 1

TYPE DMUS_NOTE_PMSG
   mtDuration AS LONG                                   ' VT_I4 <Long>
   musicValue AS INTEGER                                ' VT_I2 <Integer>
   measure AS INTEGER                                   ' VT_I2 <Integer>
   offset AS INTEGER                                    ' VT_I2 <Integer>
   beat AS BYTE                                         ' VT_UI1 <Byte>
   grid AS BYTE                                         ' VT_UI1 <Byte>
   velocity AS BYTE                                     ' VT_UI1 <Byte>
   flags AS BYTE                                        ' VT_UI1 <Byte>
   timeRange AS BYTE                                    ' VT_UI1 <Byte>
   durRange AS BYTE                                     ' VT_UI1 <Byte>
   velRange AS BYTE                                     ' VT_UI1 <Byte>
   playModeFlags AS BYTE                                ' VT_UI1 <Byte>
   subChordLevel AS BYTE                                ' VT_UI1 <Byte>
   midiValue AS BYTE                                    ' VT_UI1 <Byte>
   transpose AS INTEGER                                 ' VT_I2 <Integer>
END TYPE

#ENDIF

' ========================================================================================
' DMUS_PORTCAPS record
' Number of members = 11
' ========================================================================================

#IF NOT %DEF(%DMUS_PORTCAPS_DEFINED)
%DMUS_PORTCAPS_DEFINED = 1

TYPE DMUS_PORTCAPS
   dwSize AS LONG                                       ' VT_I4 <Long>
   lFlags AS LONG                                       ' CONST_DMUS_PC_FLAGS <enum>
   guidPort AS DXGUID                                   ' DXGUID <record>
   lClass AS LONG                                       ' CONST_DMUS_PC_CLASS <enum>
   lType AS LONG                                        ' CONST_DMUS_PORT_TYPE <enum>
   lMemorySize AS LONG                                  ' VT_I4 <Long>
   lMaxChannelGroups AS LONG                            ' VT_I4 <Long>
   lMaxVoices AS LONG                                   ' VT_I4 <Long>
   lMaxAudioChannels AS LONG                            ' VT_I4 <Long>
   lEffectFlags AS LONG                                 ' VT_I4 <Long>
   wszDescription (127) AS INTEGER                      ' %VT_CARRAY <VT_I2 <Integer>>
END TYPE

#ENDIF

' ========================================================================================
' DIENVELOPE record
' Number of members = 5
' ========================================================================================

#IF NOT %DEF(%DIENVELOPE_DEFINED)
%DIENVELOPE_DEFINED = 1

TYPE DIENVELOPE
   lSize AS LONG                                        ' VT_I4 <Long>
   lAttackLevel AS LONG                                 ' VT_I4 <Long>
   lAttackTime AS LONG                                  ' VT_I4 <Long>
   lFadeLevel AS LONG                                   ' VT_I4 <Long>
   lFadeTime AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIRAMPFORCE record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%DIRAMPFORCE_DEFINED)
%DIRAMPFORCE_DEFINED = 1

TYPE DIRAMPFORCE
   lRangeStart AS LONG                                  ' VT_I4 <Long>
   lRangeEnd AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIPERIODICFORCE record
' Number of members = 4
' ========================================================================================

#IF NOT %DEF(%DIPERIODICFORCE_DEFINED)
%DIPERIODICFORCE_DEFINED = 1

TYPE DIPERIODICFORCE
   lMagnitude AS LONG                                   ' VT_I4 <Long>
   lOffset AS LONG                                      ' VT_I4 <Long>
   lPhase AS LONG                                       ' VT_I4 <Long>
   lPeriod AS LONG                                      ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DICONDITION record
' Number of members = 6
' ========================================================================================

#IF NOT %DEF(%DICONDITION_DEFINED)
%DICONDITION_DEFINED = 1

TYPE DICONDITION
   lOffset AS LONG                                      ' VT_I4 <Long>
   lPositiveCoefficient AS LONG                         ' VT_I4 <Long>
   lNegativeCoefficient AS LONG                         ' VT_I4 <Long>
   lPositiveSaturation AS LONG                          ' VT_I4 <Long>
   lNegativeSaturation AS LONG                          ' VT_I4 <Long>
   lDeadBand AS LONG                                    ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DICONSTANTFORCE record
' Number of members = 1
' ========================================================================================

#IF NOT %DEF(%DICONSTANTFORCE_DEFINED)
%DICONSTANTFORCE_DEFINED = 1

TYPE DICONSTANTFORCE
   lMagnitude AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIAXISOFFSETS record
' Number of members = 2
' ========================================================================================

#IF NOT %DEF(%DIAXISOFFSETS_DEFINED)
%DIAXISOFFSETS_DEFINED = 1

TYPE DIAXISOFFSETS
   x AS LONG                                            ' VT_I4 <Long>
   y AS LONG                                            ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DIEFFECT record
' Number of members = 25
' ========================================================================================

#IF NOT %DEF(%DIEFFECT_DEFINED)
%DIEFFECT_DEFINED = 1

TYPE DIEFFECT
   dwSize AS LONG                                       ' VT_I4 <Long>
   lFlags AS LONG                                       ' VT_I4 <Long>
   lDuration AS LONG                                    ' VT_I4 <Long>
   lSamplePeriod AS LONG                                ' VT_I4 <Long>
   lGain AS LONG                                        ' VT_I4 <Long>
   lTriggerButton AS LONG                               ' VT_I4 <Long>
   lTriggerRepeatInterval AS LONG                       ' VT_I4 <Long>
   cAxes AS LONG                                        ' VT_I4 <Long>
   lprgdwAxes AS LONG                                   ' VT_I4 <Long>
   lprglDirection AS LONG                               ' VT_I4 <Long>
   lpEnvelope AS LONG                                   ' VT_I4 <Long>
   cbTypeSpecificParams AS LONG                         ' VT_I4 <Long>
   lpvTypeSpecificParams AS LONG                        ' VT_I4 <Long>
   lStartDelay AS LONG                                  ' VT_I4 <Long>
   x AS LONG                                            ' VT_I4 <Long>
   y AS LONG                                            ' VT_I4 <Long>
   rampForce AS DIRAMPFORCE                             ' DIRAMPFORCE <record>
   periodicForce AS DIPERIODICFORCE                     ' DIPERIODICFORCE <record>
   constantForce AS DICONSTANTFORCE                     ' DICONSTANTFORCE <record>
   conditionX AS DICONDITION                            ' DICONDITION <record>
   conditionY AS DICONDITION                            ' DICONDITION <record>
   conditionFlags AS LONG                               ' CONST_DICONDITIONFLAGS <enum>
   bUseEnvelope AS LONG                                 ' VT_I4 <Long>
   envelope AS DIENVELOPE                               ' DIENVELOPE <record>
   axisOffsets AS DIAXISOFFSETS                         ' DIAXISOFFSETS <record>
END TYPE

#ENDIF

' ========================================================================================
' D3DDEVINFO_TEXTUREMANAGER record
' Number of members = 10
' ========================================================================================

#IF NOT %DEF(%D3DDEVINFO_TEXTUREMANAGER_DEFINED)
%D3DDEVINFO_TEXTUREMANAGER_DEFINED = 1

TYPE D3DDEVINFO_TEXTUREMANAGER
   bThrashing AS LONG                                   ' VT_I4 <Long>
   lNumEvicts AS LONG                                   ' VT_I4 <Long>
   lNumVidCreates AS LONG                               ' VT_I4 <Long>
   lNumTexturesUsed AS LONG                             ' VT_I4 <Long>
   lNumUsedTexInVid AS LONG                             ' VT_I4 <Long>
   lWorkingSet AS LONG                                  ' VT_I4 <Long>
   lWorkingSetBytes AS LONG                             ' VT_I4 <Long>
   lTotalManaged AS LONG                                ' VT_I4 <Long>
   lTotalBytes AS LONG                                  ' VT_I4 <Long>
   lLastPri AS LONG                                     ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' DDOVERLAYFX record
' Number of members = 12
' ========================================================================================

#IF NOT %DEF(%DDOVERLAYFX_DEFINED)
%DDOVERLAYFX_DEFINED = 1

TYPE DDOVERLAYFX
   lSize AS LONG                                        ' VT_I4 <Long>
   lAlphaEdgeBlendBitDepth AS LONG                      ' VT_I4 <Long>
   lAlphaEdgeBlend AS LONG                              ' VT_I4 <Long>
   lReserved AS LONG                                    ' VT_I4 <Long>
   lAlphaDestConstBitDepth AS LONG                      ' VT_I4 <Long>
   lAlphaDestConst AS LONG                              ' VT_I4 <Long>
   lAlphaSrcConstBitDepth AS LONG                       ' VT_I4 <Long>
   lAlphaSrcConst AS LONG                               ' VT_I4 <Long>
   dckDestColorkey AS DDCOLORKEY                        ' DDCOLORKEY <record>
   dckSrcColorkey AS DDCOLORKEY                         ' DDCOLORKEY <record>
   lDDFX AS LONG                                        ' CONST_DDOVERFXFLAGS <enum>
   lFlags AS LONG                                       ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' D3DDEVINFO_TEXTURING record
' Number of members = 10
' ========================================================================================

#IF NOT %DEF(%D3DDEVINFO_TEXTURING_DEFINED)
%D3DDEVINFO_TEXTURING_DEFINED = 1

TYPE D3DDEVINFO_TEXTURING
   lNumLoads AS LONG                                    ' VT_I4 <Long>
   lApproxBytesLoaded AS LONG                           ' VT_I4 <Long>
   lNumPreLoads AS LONG                                 ' VT_I4 <Long>
   lNumSet AS LONG                                      ' VT_I4 <Long>
   lNumCreates AS LONG                                  ' VT_I4 <Long>
   lNumDestroys AS LONG                                 ' VT_I4 <Long>
   lNumSetPriorities AS LONG                            ' VT_I4 <Long>
   lNumSetLODs AS LONG                                  ' VT_I4 <Long>
   lNumLocks AS LONG                                    ' VT_I4 <Long>
   lNumGetDCs AS LONG                                   ' VT_I4 <Long>
END TYPE

#ENDIF

' ========================================================================================
' __MIDL_IWinTypes_0009 union
' Number of members = 2
' ========================================================================================

'#IF NOT %DEF(%u__MIDL_IWinTypes_0009_DEFINED)
'%u__MIDL_IWinTypes_0009_DEFINED = 1

'UNION u__MIDL_IWinTypes_0009
'   hInproc AS LONG                                      ' VT_I4 <Long>
'   hRemote AS LONG                                      ' VT_I4 <Long>
'END UNION

'#ENDIF

' ========================================================================================
' _RemotableHandle record <alias> wireHFONT
' Number of members = 2
' ========================================================================================

'#IF NOT %DEF(%tag_RemotableHandle_DEFINED)
'%tag_RemotableHandle_DEFINED = 1

'TYPE tag_RemotableHandle
'   fContext AS LONG                                     ' VT_I4 <Long>
'   u AS u__MIDL_IWinTypes_0009                          ' __MIDL_IWinTypes_0009 <union>
'END TYPE

'MACRO wireHFONT = tag_RemotableHandle

'#ENDIF

' ========================================================================================
' tagTEXTMETRICW record
' Number of members = 20
' ========================================================================================

'#IF NOT %DEF(%tagTEXTMETRICW_DEFINED)
'%tagTEXTMETRICW_DEFINED = 1

'TYPE tagTEXTMETRICW
'   tmHeight AS LONG                                     ' VT_I4 <Long>
'   tmAscent AS LONG                                     ' VT_I4 <Long>
'   tmDescent AS LONG                                    ' VT_I4 <Long>
'   tmInternalLeading AS LONG                            ' VT_I4 <Long>
'   tmExternalLeading AS LONG                            ' VT_I4 <Long>
'   tmAveCharWidth AS LONG                               ' VT_I4 <Long>
'   tmMaxCharWidth AS LONG                               ' VT_I4 <Long>
'   tmWeight AS LONG                                     ' VT_I4 <Long>
'   tmOverhang AS LONG                                   ' VT_I4 <Long>
'   tmDigitizedAspectX AS LONG                           ' VT_I4 <Long>
'   tmDigitizedAspectY AS LONG                           ' VT_I4 <Long>
'   tmFirstChar AS WORD                                  ' VT_UI2 <Word>
'   tmLastChar AS WORD                                   ' VT_UI2 <Word>
'   tmDefaultChar AS WORD                                ' VT_UI2 <Word>
'   tmBreakChar AS WORD                                  ' VT_UI2 <Word>
'   tmItalic AS BYTE                                     ' VT_UI1 <Byte>
'   tmUnderlined AS BYTE                                 ' VT_UI1 <Byte>
'   tmStruckOut AS BYTE                                  ' VT_UI1 <Byte>
'   tmPitchAndFamily AS BYTE                             ' VT_UI1 <Byte>
'   tmCharSet AS BYTE                                    ' VT_UI1 <Byte>
'END TYPE

'#ENDIF


' ########################################################################################
' Interface name = DirectPlayAddress
' IID = {9F76FF05-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayAddress_INTERFACE_DEFINED)
    %DirectPlayAddress_INTERFACE_DEFINED = 1

INTERFACE DirectPlayAddress $IID_DirectPlayAddress

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetAddress ( _                                ' VTable offset = 12
     BYVAL pAddress AS LONG _                           ' __in pAddress VT_I4 <Long>
   , BYVAL length AS LONG _                             ' __in length VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 16
     BYREF pAddress AS LONG _                           ' __out *pAddress VT_I4 <Long>
   , BYREF length AS LONG _                             ' __out *length VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayAddress_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayLobbyConnection
' IID = {9F76FF06-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayLobbyConnection_INTERFACE_DEFINED)
    %DirectPlayLobbyConnection_INTERFACE_DEFINED = 1

INTERFACE DirectPlayLobbyConnection $IID_DirectPlayLobbyConnection

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetConnectionStruct ( _                       ' VTable offset = 12
     BYREF connect AS LONG _                            ' __out *connect VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConnectionStruct ( _                       ' VTable offset = 16
     BYVAL connect AS LONG _                            ' __in connect VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in flags CONST_DPLCONNECTIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *ret CONST_DPLCONNECTIONFLAGS <enum>
   ' =====================================================================================
   METHOD SetSessionDesc ( _                            ' VTable offset = 28
     BYVAL sessionDesc AS DirectPlaySessionData _       ' __in *sessionDesc DirectPlaySessionData <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSessionDesc ( _                            ' VTable offset = 32
   ) AS DirectPlaySessionData                           ' __retval_out **sessionDesc DirectPlaySessionData <interface>
   ' =====================================================================================
   METHOD SetGuidSP ( _                                 ' VTable offset = 36
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGuidSP ( _                                 ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD SetAddress ( _                                ' VTable offset = 44
     BYVAL address AS DirectPlayAddress _               ' __in *address DirectPlayAddress <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 48
   ) AS DirectPlayAddress                               ' __retval_out **address DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD SetPlayerShortName ( _                        ' VTable offset = 52
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlayerShortName ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetPlayerLongName ( _                         ' VTable offset = 60
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlayerLongName ( _                         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayLobbyConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlaySessionData
' IID = {9F76FF12-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlaySessionData_INTERFACE_DEFINED)
    %DirectPlaySessionData_INTERFACE_DEFINED = 1

INTERFACE DirectPlaySessionData $IID_DirectPlaySessionData

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetGuidInstance ( _                           ' VTable offset = 12
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGuidInstance ( _                           ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD SetGuidApplication ( _                        ' VTable offset = 20
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGuidApplication ( _                        ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD SetMaxPlayers ( _                             ' VTable offset = 28
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMaxPlayers ( _                             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetCurrentPlayers ( _                         ' VTable offset = 36
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentPlayers ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetSessionName ( _                            ' VTable offset = 44
     BYVAL val AS WSTRING _                             ' __in val VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSessionName ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *val VT_BSTR
   ' =====================================================================================
   METHOD SetSessionPassword ( _                        ' VTable offset = 52
     BYVAL val AS WSTRING _                             ' __in val VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSessionPassword ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out *val VT_BSTR
   ' =====================================================================================
   METHOD SetUser1 ( _                                  ' VTable offset = 60
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUser1 ( _                                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetUser2 ( _                                  ' VTable offset = 68
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUser2 ( _                                  ' VTable offset = 72
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetUser3 ( _                                  ' VTable offset = 76
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUser3 ( _                                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetUser4 ( _                                  ' VTable offset = 84
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUser4 ( _                                  ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 92
     BYVAL val AS LONG _                                ' __in val CONST_DPSESSIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 96
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 100
     BYVAL val AS DWORD _                               ' __out *val VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlaySessionData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayEnumConnections
' IID = {9F76FF0A-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayEnumConnections_INTERFACE_DEFINED)
    %DirectPlayEnumConnections_INTERFACE_DEFINED = 1

INTERFACE DirectPlayEnumConnections $IID_DirectPlayEnumConnections

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS DirectPlayAddress                               ' __retval_out **retV DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *retV VT_BSTR
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *retV VT_BSTR
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayEnumConnections_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayEnumPlayers
' IID = {9F76FF0B-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayEnumPlayers_INTERFACE_DEFINED)
    %DirectPlayEnumPlayers_INTERFACE_DEFINED = 1

INTERFACE DirectPlayEnumPlayers $IID_DirectPlayEnumPlayers

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDPID ( _                                   ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetShortName ( _                              ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *retV VT_BSTR
   ' =====================================================================================
   METHOD GetLongName ( _                               ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *retV VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayEnumPlayers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayEnumSessions
' IID = {9F76FF0C-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayEnumSessions_INTERFACE_DEFINED)
    %DirectPlayEnumSessions_INTERFACE_DEFINED = 1

INTERFACE DirectPlayEnumSessions $IID_DirectPlayEnumSessions

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS DirectPlaySessionData                           ' __retval_out **retval DirectPlaySessionData <interface>
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayEnumSessions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayEnumServiceProviders
' IID = {9F76FF0D-8E92-11D1-8808-00C04FC2C602}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayEnumServiceProviders_INTERFACE_DEFINED)
    %DirectPlayEnumServiceProviders_INTERFACE_DEFINED = 1

INTERFACE DirectPlayEnumServiceProviders $IID_DirectPlayEnumServiceProviders

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF majorVersion AS LONG _                       ' __in *majorVersion VT_I4 <Long>
   , BYREF minorVersion AS LONG _                       ' __inout *minorVersion VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayEnumServiceProviders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayEnumLocalApplications
' IID = {9F76FF0E-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayEnumLocalApplications_INTERFACE_DEFINED)
    %DirectPlayEnumLocalApplications_INTERFACE_DEFINED = 1

INTERFACE DirectPlayEnumLocalApplications $IID_DirectPlayEnumLocalApplications

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayEnumLocalApplications_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayMessage
' IID = {9F76FF11-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayMessage_INTERFACE_DEFINED)
    %DirectPlayMessage_INTERFACE_DEFINED = 1

INTERFACE DirectPlayMessage $IID_DirectPlayMessage

   INHERIT IAutomation

   ' =====================================================================================
   METHOD WriteGuid ( _                                 ' VTable offset = 12
     BYVAL val AS WSTRING _                             ' __in val VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadGuid ( _                                  ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out *val VT_BSTR
   ' =====================================================================================
   METHOD WriteString ( _                               ' VTable offset = 20
     BYVAL val AS WSTRING _                             ' __in val VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadString ( _                                ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out *val VT_BSTR
   ' =====================================================================================
   METHOD WriteLong ( _                                 ' VTable offset = 28
     BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadLong ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD WriteShort ( _                                ' VTable offset = 36
     BYVAL val AS INTEGER _                             ' __in val VT_I2 <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadShort ( _                                 ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out *val VT_I2 <Integer>
   ' =====================================================================================
   METHOD WriteSingle ( _                               ' VTable offset = 44
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadSingle ( _                                ' VTable offset = 48
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD WriteDouble ( _                               ' VTable offset = 52
     BYVAL val AS DOUBLE _                              ' __in val VT_R8 <Double>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadDouble ( _                                ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out *val VT_R8 <Double>
   ' =====================================================================================
   METHOD WriteByte ( _                                 ' VTable offset = 60
     BYVAL val AS BYTE _                                ' __in val VT_UI1 <Byte>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadByte ( _                                  ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out *val VT_UI1 <Byte>
   ' =====================================================================================
   METHOD MoveToTop ( _                                 ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessageSize ( _                            ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMessageData ( _                            ' VTable offset = 80
     BYVAL userDefinedType AS DWORD _                   ' __inout *userDefinedType VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMessageData ( _                            ' VTable offset = 84
     BYVAL userDefinedType AS DWORD _                   ' __in *userDefinedType VT_VOID <Dword>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPointer ( _                                ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD ReadSysMsgConnection ( _                      ' VTable offset = 92
   ) AS DirectPlayLobbyConnection                       ' __retval_out **ret DirectPlayLobbyConnection <interface>
   ' =====================================================================================
   METHOD ReadSysMsgSessionDesc ( _                     ' VTable offset = 96
   ) AS DirectPlaySessionData                           ' __retval_out **ret DirectPlaySessionData <interface>
   ' =====================================================================================
   METHOD ReadSysMsgData ( _                            ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD ReadSysChatString ( _                         ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD MoveToSecureMessage ( _                       ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayMessage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlay4
' IID = {9F76FF0F-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlay4_INTERFACE_DEFINED)
    %DirectPlay4_INTERFACE_DEFINED = 1

INTERFACE DirectPlay4 $IID_DirectPlay4

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddGroupToGroup ( _                           ' VTable offset = 20
     BYVAL ParentGroupId AS LONG _                      ' __in ParentGroupId VT_I4 <Long>
   , BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPlayerToGroup ( _                          ' VTable offset = 24
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelMessage ( _                             ' VTable offset = 28
     BYVAL msgid AS LONG _                              ' __in msgid VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelPriority ( _                            ' VTable offset = 32
     BYVAL minPrority AS LONG _                         ' __in minPrority VT_I4 <Long>
   , BYVAL maxPriority AS LONG _                        ' __in maxPriority VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateGroup ( _                               ' VTable offset = 40
     BYVAL friendlyName AS WSTRING _                    ' __in friendlyName VT_BSTR
   , BYVAL formalName AS WSTRING _                      ' __in formalName VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGROUPFLAGS <enum>
   ) AS LONG                                            ' __retval_out *v1 VT_I4 <Long>
   ' =====================================================================================
   METHOD CreateGroupInGroup ( _                        ' VTable offset = 44
     BYVAL parentid AS LONG _                           ' __in parentid VT_I4 <Long>
   , BYVAL friendlyName AS WSTRING _                    ' __in friendlyName VT_BSTR
   , BYVAL formalName AS WSTRING _                      ' __in formalName VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGROUPFLAGS <enum>
   ) AS LONG                                            ' __retval_out *v1 VT_I4 <Long>
   ' =====================================================================================
   METHOD CreatePlayer ( _                              ' VTable offset = 48
     BYVAL friendlyName AS WSTRING _                    ' __in friendlyName VT_BSTR
   , BYVAL formalName AS WSTRING _                      ' __in formalName VT_BSTR
   , BYVAL receiveEvent AS LONG _                       ' __in receiveEvent VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPPLAYERFLAGS <enum>
   ) AS LONG                                            ' __retval_out *v1 VT_I4 <Long>
   ' =====================================================================================
   METHOD DeleteGroupFromGroup ( _                      ' VTable offset = 52
     BYVAL groupParentId AS LONG _                      ' __in groupParentId VT_I4 <Long>
   , BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePlayerFromGroup ( _                     ' VTable offset = 56
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DestroyGroup ( _                              ' VTable offset = 60
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DestroyPlayer ( _                             ' VTable offset = 64
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDPEnumConnections ( _                      ' VTable offset = 68
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMCONNECTIONFLAGS <enum>
   ) AS DirectPlayEnumConnections                       ' __retval_out **retval DirectPlayEnumConnections <interface>
   ' =====================================================================================
   METHOD GetDPEnumGroupPlayers ( _                     ' VTable offset = 72
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL sessionGuid AS WSTRING _                     ' __in sessionGuid VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMPLAYERFLAGS <enum>
   ) AS DirectPlayEnumPlayers                           ' __retval_out **retval DirectPlayEnumPlayers <interface>
   ' =====================================================================================
   METHOD GetDPEnumGroups ( _                           ' VTable offset = 76
     BYVAL sessionGuid AS WSTRING _                     ' __in sessionGuid VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMGROUPFLAGS <enum>
   ) AS DirectPlayEnumPlayers                           ' __retval_out **retval DirectPlayEnumPlayers <interface>
   ' =====================================================================================
   METHOD GetDPEnumGroupsInGroup ( _                    ' VTable offset = 80
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL sessionGuid AS WSTRING _                     ' __in sessionGuid VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMGROUPFLAGS <enum>
   ) AS DirectPlayEnumPlayers                           ' __retval_out **retval DirectPlayEnumPlayers <interface>
   ' =====================================================================================
   METHOD GetDPEnumPlayers ( _                          ' VTable offset = 84
     BYVAL sessionGuid AS WSTRING _                     ' __in sessionGuid VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMPLAYERFLAGS <enum>
   ) AS DirectPlayEnumPlayers                           ' __retval_out **retval DirectPlayEnumPlayers <interface>
   ' =====================================================================================
   METHOD GetDPEnumSessions ( _                         ' VTable offset = 88
     BYVAL sessionDesc AS DirectPlaySessionData _       ' __in *sessionDesc DirectPlaySessionData <interface>
   , BYVAL timeOut AS LONG _                            ' __in timeOut VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPENUMSESSIONFLAGS <enum>
   ) AS DirectPlayEnumSessions                          ' __retval_out **retval DirectPlayEnumSessions <interface>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 92
     BYREF caps AS DPCAPS _                             ' __inout *caps DPCAPS <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGETCAPSFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGroupData ( _                              ' VTable offset = 96
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGETFLAGS <enum>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetGroupFlags ( _                             ' VTable offset = 100
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *flags CONST_DPGROUPFLAGS <enum>
   ' =====================================================================================
   METHOD GetGroupLongName ( _                          ' VTable offset = 104
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetGroupShortName ( _                         ' VTable offset = 108
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetGroupParent ( _                            ' VTable offset = 112
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGroupOwner ( _                             ' VTable offset = 116
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMessageCount ( _                           ' VTable offset = 120
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMessageQueue ( _                           ' VTable offset = 124
     BYVAL from AS LONG _                               ' __in from VT_I4 <Long>
   , BYVAL to AS LONG _                                 ' __in to VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPMESSAGEQUEUEFLAGS <enum>
   , BYREF nMessage AS LONG _                           ' __inout *nMessage VT_I4 <Long>
   , BYREF nBytes AS LONG _                             ' __inout *nBytes VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlayerAccountId ( _                        ' VTable offset = 128
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *acctid VT_BSTR
   ' =====================================================================================
   METHOD GetPlayerAddress ( _                          ' VTable offset = 132
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD GetPlayerCaps ( _                             ' VTable offset = 136
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   , BYREF caps AS DPCAPS _                             ' __out *caps DPCAPS <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGETCAPSFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlayerData ( _                             ' VTable offset = 140
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPGETFLAGS <enum>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetPlayerFlags ( _                            ' VTable offset = 144
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retflags CONST_DPPLAYERFLAGS <enum>
   ' =====================================================================================
   METHOD GetPlayerFormalName ( _                       ' VTable offset = 148
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetPlayerFriendlyName ( _                     ' VTable offset = 152
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetSessionDesc ( _                            ' VTable offset = 156
     BYREF sessionDesc AS DirectPlaySessionData _       ' __inout **sessionDesc DirectPlaySessionData <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeConnection ( _                      ' VTable offset = 160
     BYVAL address AS DirectPlayAddress _               ' __in *address DirectPlayAddress <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 164
     BYVAL sessionDesc AS DirectPlaySessionData _       ' __inout *sessionDesc DirectPlaySessionData <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPOPENFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Receive ( _                                   ' VTable offset = 168
     BYREF fromPlayerId AS LONG _                       ' __inout *fromPlayerId VT_I4 <Long>
   , BYREF toPlayerId AS LONG _                         ' __inout *toPlayerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPRECEIVEFLAGS <enum>
   ) AS DirectPlayMessage                               ' __retval_out **ret DirectPlayMessage <interface>
   ' =====================================================================================
   METHOD ReceiveSize ( _                               ' VTable offset = 172
     BYREF fromPlayerId AS LONG _                       ' __inout *fromPlayerId VT_I4 <Long>
   , BYREF toPlayerId AS LONG _                         ' __inout *toPlayerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPRECEIVEFLAGS <enum>
   ) AS LONG                                            ' __retval_out *dataSize VT_INT <Long>
   ' =====================================================================================
   METHOD SecureOpen ( _                                ' VTable offset = 176
     BYVAL sessionDesc AS DirectPlaySessionData _       ' __in *sessionDesc DirectPlaySessionData <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPOPENFLAGS <enum>
   , BYREF security AS DPSECURITYDESC _                 ' __in *security DPSECURITYDESC <record>
   , BYREF credentials AS DPCREDENTIALS _               ' __in *credentials DPCREDENTIALS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD Send ( _                                      ' VTable offset = 180
     BYVAL fromPlayerId AS LONG _                       ' __in fromPlayerId VT_I4 <Long>
   , BYVAL toPlayerId AS LONG _                         ' __in toPlayerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSENDFLAGS <enum>
   , BYVAL msg AS DirectPlayMessage _                   ' __in *msg DirectPlayMessage <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendChatMessage ( _                           ' VTable offset = 184
     BYVAL fromPlayerId AS LONG _                       ' __in fromPlayerId VT_I4 <Long>
   , BYVAL toPlayerId AS LONG _                         ' __in toPlayerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSENDFLAGS <enum>
   , BYVAL message AS WSTRING _                         ' __in message VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD SendEx ( _                                    ' VTable offset = 188
     BYVAL fromPlayerId AS LONG _                       ' __in fromPlayerId VT_I4 <Long>
   , BYVAL toPlayerId AS LONG _                         ' __in toPlayerId VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSENDFLAGS <enum>
   , BYVAL msg AS DirectPlayMessage _                   ' __in *msg DirectPlayMessage <interface>
   , BYVAL priority AS LONG _                           ' __in priority VT_I4 <Long>
   , BYVAL timeOut AS LONG _                            ' __in timeOut VT_I4 <Long>
   , BYVAL context AS LONG _                            ' __in context VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *messageid VT_I4 <Long>
   ' =====================================================================================
   METHOD CreateMessage ( _                             ' VTable offset = 192
   ) AS DirectPlayMessage                               ' __retval_out **msg DirectPlayMessage <interface>
   ' =====================================================================================
   METHOD SetGroupConnectionSettings ( _                ' VTable offset = 196
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL connection AS DirectPlayLobbyConnection _    ' __in *connection DirectPlayLobbyConnection <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupData ( _                              ' VTable offset = 200
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL data AS WSTRING _                            ' __in data VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSETFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupName ( _                              ' VTable offset = 204
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL friendlyName AS WSTRING _                    ' __in friendlyName VT_BSTR
   , BYVAL formalName AS WSTRING _                      ' __in formalName VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSETFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupOwner ( _                             ' VTable offset = 208
     BYVAL GroupId AS LONG _                            ' __in GroupId VT_I4 <Long>
   , BYVAL ownerId AS LONG _                            ' __in ownerId VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPlayerData ( _                             ' VTable offset = 212
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   , BYVAL data AS WSTRING _                            ' __in data VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSETFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPlayerName ( _                             ' VTable offset = 216
     BYVAL playerId AS LONG _                           ' __in playerId VT_I4 <Long>
   , BYVAL friendlyName AS WSTRING _                    ' __in friendlyName VT_BSTR
   , BYVAL formalName AS WSTRING _                      ' __in formalName VT_BSTR
   , BYVAL flags AS LONG _                              ' __in flags CONST_DPSETFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSessionDesc ( _                            ' VTable offset = 220
     BYVAL sessionDesc AS DirectPlaySessionData _       ' __in *sessionDesc DirectPlaySessionData <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD StartSession ( _                              ' VTable offset = 224
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateSessionData ( _                         ' VTable offset = 228
   ) AS DirectPlaySessionData                           ' __retval_out **sessionDesc DirectPlaySessionData <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlay4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectPlayLobby3
' IID = {9F76FF10-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectPlayLobby3_INTERFACE_DEFINED)
    %DirectPlayLobby3_INTERFACE_DEFINED = 1

INTERFACE DirectPlayLobby3 $IID_DirectPlayLobby3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD connect ( _                                   ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in flags CONST_DPCONNECTFLAGS <enum>
   ) AS DirectPlay4                                     ' __retval_out **directPlay DirectPlay4 <interface>
   ' =====================================================================================
   METHOD GetDPEnumLocalApplications ( _                ' VTable offset = 24
   ) AS DirectPlayEnumLocalApplications                 ' __retval_out **retval DirectPlayEnumLocalApplications <interface>
   ' =====================================================================================
   METHOD GetConnectionSettings ( _                     ' VTable offset = 28
     BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   ) AS DirectPlayLobbyConnection                       ' __retval_out **connection DirectPlayLobbyConnection <interface>
   ' =====================================================================================
   METHOD ReceiveLobbyMessage ( _                       ' VTable offset = 32
     BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   , BYREF messageFlags AS LONG _                       ' __inout *messageFlags VT_I4 <Long>
   ) AS DirectPlayMessage                               ' __retval_out **data DirectPlayMessage <interface>
   ' =====================================================================================
   METHOD ReceiveLobbyMessageSize ( _                   ' VTable offset = 36
     BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   , BYREF messageFlags AS LONG _                       ' __inout *messageFlags VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *dataSize VT_I4 <Long>
   ' =====================================================================================
   METHOD RunApplication ( _                            ' VTable offset = 40
     BYVAL connection AS DirectPlayLobbyConnection _    ' __in *connection DirectPlayLobbyConnection <interface>
   , BYVAL receiveEvent AS LONG _                       ' __in receiveEvent VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *applicationId VT_I4 <Long>
   ' =====================================================================================
   METHOD SendLobbyMessage ( _                          ' VTable offset = 44
     BYVAL flags AS LONG _                              ' __in flags CONST_DPLMSG <enum>
   , BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   , BYVAL msg AS DirectPlayMessage _                   ' __in *msg DirectPlayMessage <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConnectionSettings ( _                     ' VTable offset = 48
     BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   , BYVAL connection AS DirectPlayLobbyConnection _    ' __in *connection DirectPlayLobbyConnection <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLobbyMessageEvent ( _                      ' VTable offset = 52
     BYVAL applicationId AS LONG _                      ' __in applicationId VT_I4 <Long>
   , BYVAL receiveEvent AS LONG _                       ' __in receiveEvent VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterApplication ( _                       ' VTable offset = 56
     BYREF ApplicationInfo AS DPAPPLICATIONDESC2 _      ' __in *ApplicationInfo DPAPPLICATIONDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterApplication ( _                     ' VTable offset = 60
     BYVAL guidApplication AS WSTRING _                 ' __in guidApplication VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD WaitForConnectionSettings ( _                 ' VTable offset = 64
     BYVAL flags AS LONG _                              ' __in flags CONST_DPLWAIT <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateMessage ( _                             ' VTable offset = 68
   ) AS DirectPlayMessage                               ' __retval_out **msg DirectPlayMessage <interface>
   ' =====================================================================================
   METHOD CreateConnectionData ( _                      ' VTable offset = 72
   ) AS DirectPlayLobbyConnection                       ' __retval_out **connection DirectPlayLobbyConnection <interface>
   ' =====================================================================================
   METHOD CreateINetAddress ( _                         ' VTable offset = 76
     BYVAL addr AS WSTRING _                            ' __in addr VT_BSTR
   , BYVAL port AS LONG _                               ' __in port VT_INT <Long>
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateComPortAddress ( _                      ' VTable offset = 80
     BYVAL port AS LONG _                               ' __in port VT_I4 <Long>
   , BYVAL baudRate AS LONG _                           ' __in baudRate VT_I4 <Long>
   , BYVAL stopBits AS LONG _                           ' __in stopBits VT_I4 <Long>
   , BYVAL parity AS LONG _                             ' __in parity VT_I4 <Long>
   , BYVAL flowcontrol AS LONG _                        ' __in flowcontrol VT_I4 <Long>
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateLobbyProviderAddress ( _                ' VTable offset = 84
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateServiceProviderAddress ( _              ' VTable offset = 88
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateModemAddress ( _                        ' VTable offset = 92
     BYVAL modem AS WSTRING _                           ' __in modem VT_BSTR
   , BYVAL phone AS WSTRING _                           ' __in phone VT_BSTR
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateIPXAddress ( _                          ' VTable offset = 96
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD CreateCustomAddress ( _                       ' VTable offset = 100
     BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYVAL data AS DWORD _                              ' __in *data VT_VOID <Dword>
   ) AS DirectPlayAddress                               ' __retval_out **ret DirectPlayAddress <interface>
   ' =====================================================================================
   METHOD GetModemName ( _                              ' VTable offset = 104
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetModemCount ( _                             ' VTable offset = 108
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectPlayLobby3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMEnumerateObjectsCallback
' IID = {BBD5AD04-8E91-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMEnumerateObjectsCallback_INTERFACE_DEFINED)
    %Direct3DRMEnumerateObjectsCallback_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMEnumerateObjectsCallback $IID_Direct3DRMEnumerateObjectsCallback

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMEnumerateObjects ( _                ' VTable offset = 12
     BYVAL object AS Direct3DRMObject _                 ' __in *object Direct3DRMObject <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMEnumerateObjectsCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMObject
' IID = {9F76FE0E-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMObject_INTERFACE_DEFINED)
    %Direct3DRMObject_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMObject $IID_Direct3DRMObject

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMCallback
' IID = {BBD5AD03-8E91-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMCallback_INTERFACE_DEFINED)
    %Direct3DRMCallback_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMCallback $IID_Direct3DRMCallback

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMDestroyObject ( _                   ' VTable offset = 12
     BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMLoadCallback
' IID = {BBD5AD0A-8E91-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMLoadCallback_INTERFACE_DEFINED)
    %Direct3DRMLoadCallback_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMLoadCallback $IID_Direct3DRMLoadCallback

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMLoad ( _                            ' VTable offset = 12
     BYREF Obj AS Direct3DRMObject _                    ' __in **Obj Direct3DRMObject <interface>
   , BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMLoadCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMLoadTextureCallback3
' IID = {BBD5AD16-8E91-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMLoadTextureCallback3_INTERFACE_DEFINED)
    %Direct3DRMLoadTextureCallback3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMLoadTextureCallback3 $IID_Direct3DRMLoadTextureCallback3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMLoadTexture ( _                     ' VTable offset = 12
     BYVAL textureName AS WSTRING _                     ' __in textureName VT_BSTR
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   ) AS Direct3DRMTexture3                              ' __retval_out **retV Direct3DRMTexture3 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMLoadTextureCallback3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMTexture3
' IID = {9F76FE28-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMTexture3_INTERFACE_DEFINED)
    %Direct3DRMTexture3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMTexture3 $IID_Direct3DRMTexture3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD Changed ( _                                   ' VTable offset = 52
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMTEXTURECHANGEDFLAGS <enum>
   , BYVAL nRects AS LONG _                             ' __in nRects VT_I4 <Long>
   , BYREF rects AS DWORD _                             ' __in **rects VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateMIPMap ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCacheFlags ( _                             ' VTable offset = 60
   ) AS LONG                                            ' __retval_out *ret CONST_D3DRMTEXTURECACHEFLAGS <enum>
   ' =====================================================================================
   METHOD GetCacheImportance ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetColors ( _                                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out *c VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDecalOrigin ( _                            ' VTable offset = 72
     BYREF x AS LONG _                                  ' __out *x VT_I4 <Long>
   , BYREF y AS LONG _                                  ' __out *y VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDecalScale ( _                             ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *considerScale CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetDecalSize ( _                              ' VTable offset = 80
     BYREF w AS SINGLE _                                ' __out *w VT_R4 <Single>
   , BYREF h AS SINGLE _                                ' __out *h VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDecalTransparency ( _                      ' VTable offset = 84
   ) AS LONG                                            ' __retval_out *enabled CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetDecalTransparentColor ( _                  ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *tc VT_I4 <Long>
   ' =====================================================================================
   METHOD GetShades ( _                                 ' VTable offset = 92
   ) AS LONG                                            ' __retval_out *shades VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 96
     BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   ) AS DirectDrawSurface4                              ' __retval_out **surface DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD SetCacheOptions ( _                           ' VTable offset = 100
     BYVAL importance AS LONG _                         ' __in importance VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMTEXTURECACHEFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColors ( _                                 ' VTable offset = 104
     BYVAL numColors AS LONG _                          ' __in numColors VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalOrigin ( _                            ' VTable offset = 108
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalScale ( _                             ' VTable offset = 112
     BYVAL considerScale AS LONG _                      ' __in considerScale CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalSize ( _                              ' VTable offset = 116
     BYVAL width AS SINGLE _                            ' __in width VT_R4 <Single>
   , BYVAL height AS SINGLE _                           ' __in height VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalTransparency ( _                      ' VTable offset = 120
     BYVAL transparencyEnabled AS LONG _                ' __in transparencyEnabled CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalTransparentColor ( _                  ' VTable offset = 124
     BYVAL tcolor AS LONG _                             ' __in tcolor VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetShades ( _                                 ' VTable offset = 128
     BYVAL numShades AS LONG _                          ' __in numShades VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMTexture3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawSurface4
' IID = {BCAA7DA3-F7EF-11D2-93FD-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawSurface4_INTERFACE_DEFINED)
    %DirectDrawSurface4_INTERFACE_DEFINED = 1

INTERFACE DirectDrawSurface4 $IID_DirectDrawSurface4

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdds AS IUnknown _                          ' __in *lpdds VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdds VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 20
     BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 24
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDBLTFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltColorFill ( _                              ' VTable offset = 28
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL fillvalue AS LONG _                          ' __in fillvalue VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 32
     BYVAL dx AS LONG _                                 ' __in dx VT_I4 <Long>
   , BYVAL dy AS LONG _                                 ' __in dy VT_I4 <Long>
   , BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL trans AS LONG _                              ' __in trans CONST_DDBLTFASTFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltFx ( _                                     ' VTable offset = 36
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDBLTFLAGS <enum>
   , BYREF BltFx AS DDBLTFX _                           ' __in *BltFx DDBLTFX <record>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltToDC ( _                                   ' VTable offset = 40
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeUniquenessValue ( _                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 48
     BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBox ( _                                   ' VTable offset = 52
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawCircle ( _                                ' VTable offset = 56
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL r AS LONG _                                  ' __in r VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 60
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 64
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedBox ( _                            ' VTable offset = 68
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   , BYVAL rw AS LONG _                                 ' __in rw VT_I4 <Long>
   , BYVAL rh AS LONG _                                 ' __in rh VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 72
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   , BYVAL text AS WSTRING _                            ' __in text VT_BSTR
   , BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 76
     BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDFLIPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 80
     BYREF caps AS DDSCAPS2 _                           ' __in *caps DDSCAPS2 <record>
   ) AS DirectDrawSurface4                              ' __retval_out **ddS DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 84
     BYVAL flags AS LONG _                              ' __in flags CONST_DDGFSFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 88
     BYREF caps AS DDSCAPS2 _                           ' __inout *caps DDSCAPS2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 92
   ) AS DirectDrawClipper                               ' __retval_out **val DirectDrawClipper <interface>
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 96
     BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYREF val AS DDCOLORKEY _                          ' __inout *val DDCOLORKEY <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 100
   ) AS LONG                                            ' __retval_out *hdc VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 104
   ) AS DirectDraw4                                     ' __retval_out **val DirectDraw4 <interface>
   ' =====================================================================================
   METHOD getDrawStyle ( _                              ' VTable offset = 108
   ) AS LONG                                            ' __retval_out *drawStyle VT_I4 <Long>
   ' =====================================================================================
   METHOD getDrawWidth ( _                              ' VTable offset = 112
   ) AS LONG                                            ' __retval_out *drawWidth VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFillColor ( _                              ' VTable offset = 116
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFillStyle ( _                              ' VTable offset = 120
   ) AS LONG                                            ' __retval_out *fillStyle VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 124
     BYVAL flags AS LONG _                              ' __in flags CONST_DDGFSFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFontTransparency ( _                       ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out *b VT_BOOL <Integer>
   ' =====================================================================================
   METHOD GetForeColor ( _                              ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLockedPixel ( _                            ' VTable offset = 136
     BYVAL x AS LONG _                                  ' __in x VT_INT <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_INT <Long>
   ) AS LONG                                            ' __retval_out *col VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 140
   ) AS DirectDrawPalette                               ' __retval_out **val DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 144
     BYREF pf AS DDPIXELFORMAT _                        ' __inout *pf DDPIXELFORMAT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 148
     BYREF surface AS DDSURFACEDESC2 _                  ' __inout *surface DDSURFACEDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUniquenessValue ( _                        ' VTable offset = 152
   ) AS LONG                                            ' __retval_out *retval VT_I4 <Long>
   ' =====================================================================================
   METHOD isLost ( _                                    ' VTable offset = 156
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 160
     BYREF r AS RECT _                                  ' __in *r RECT <record>
   , BYREF desc AS DDSURFACEDESC2 _                     ' __in *desc DDSURFACEDESC2 <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDLOCKFLAGS <enum>
   , BYVAL hnd AS LONG _                                ' __in hnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 164
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD restore ( _                                   ' VTable offset = 168
   )                                                    ' void
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 172
     BYVAL val AS DirectDrawClipper _                   ' __in *val DirectDrawClipper <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 176
     BYVAL flags AS LONG _                              ' __in flags CONST_DDCKEYFLAGS <enum>
   , BYREF val AS DDCOLORKEY _                          ' __in *val DDCOLORKEY <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD setDrawStyle ( _                              ' VTable offset = 180
     BYVAL drawStyle AS LONG _                          ' __in drawStyle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD setDrawWidth ( _                              ' VTable offset = 184
     BYVAL drawWidth AS LONG _                          ' __in drawWidth VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFillColor ( _                              ' VTable offset = 188
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFillStyle ( _                              ' VTable offset = 192
     BYVAL fillStyle AS LONG _                          ' __in fillStyle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFont ( _                                   ' VTable offset = 196
     BYVAL font AS IFont _                              ' __in *font IFont <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontTransparency ( _                       ' VTable offset = 200
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetForeColor ( _                              ' VTable offset = 204
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLockedPixel ( _                            ' VTable offset = 208
     BYVAL x AS LONG _                                  ' __in x VT_INT <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_INT <Long>
   , BYVAL col AS LONG _                                ' __in col VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 212
     BYVAL ddp AS DirectDrawPalette _                   ' __in *ddp DirectDrawPalette <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 216
     BYREF r AS RECT _                                  ' __in *r RECT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLockedArray ( _                            ' VTable offset = 220
     BYREF array AS DWORD _                             ' __in **array VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontBackColor ( _                          ' VTable offset = 224
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontBackColor ( _                          ' VTable offset = 228
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawSurface4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawClipper
' IID = {9F76FDCA-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawClipper_INTERFACE_DEFINED)
    %DirectDrawClipper_INTERFACE_DEFINED = 1

INTERFACE DirectDrawClipper $IID_DirectDrawClipper

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpddc AS IUnknown _                          ' __in *lpddc VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpddc VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetClipListSize ( _                           ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *count VT_INT <Long>
   ' =====================================================================================
   METHOD GetClipList ( _                               ' VTable offset = 24
     BYREF rects AS DWORD _                             ' __inout **rects VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetClipList ( _                               ' VTable offset = 28
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF rects AS DWORD _                             ' __in **rects VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHWnd ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *hdl VT_I4 <Long>
   ' =====================================================================================
   METHOD SetHWnd ( _                                   ' VTable offset = 36
     BYVAL hdl AS LONG _                                ' __in hdl VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD IsClipListChanged ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *status VT_INT <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawClipper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDraw4
' IID = {BCAA7DA2-F7EF-11D2-93FD-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDraw4_INTERFACE_DEFINED)
    %DirectDraw4_INTERFACE_DEFINED = 1

INTERFACE DirectDraw4 $IID_DirectDraw4

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   ) AS DirectDrawClipper                               ' __retval_out **val DirectDrawClipper <interface>
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 24
     BYVAL flags AS LONG _                              ' __in flags CONST_DDPCAPSFLAGS <enum>
   , BYREF pe AS DWORD _                                ' __in **pe VT_SAFEARRAY
   ) AS DirectDrawPalette                               ' __retval_out **val DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 28
     BYREF dd AS DDSURFACEDESC2 _                       ' __in *dd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface4                              ' __retval_out **retV DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD CreateSurfaceFromFile ( _                     ' VTable offset = 32
     BYVAL file AS WSTRING _                            ' __in file VT_BSTR
   , BYREF dd AS DDSURFACEDESC2 _                       ' __inout *dd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface4                              ' __retval_out **retV DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD CreateSurfaceFromResource ( _                 ' VTable offset = 36
     BYVAL file AS WSTRING _                            ' __in file VT_BSTR
   , BYVAL resName AS WSTRING _                         ' __in resName VT_BSTR
   , BYREF ddsd AS DDSURFACEDESC2 _                     ' __inout *ddsd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface4                              ' __retval_out **retV DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 40
     BYVAL ddIn AS DirectDrawSurface4 _                 ' __in *ddIn DirectDrawSurface4 <interface>
   ) AS DirectDrawSurface4                              ' __retval_out **ddOut DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAvailableTotalMem ( _                      ' VTable offset = 48
     BYREF ddsCaps AS DDSCAPS2 _                        ' __in *ddsCaps DDSCAPS2 <record>
   ) AS LONG                                            ' __retval_out *m VT_I4 <Long>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 52
     BYREF hwCaps AS DDCAPS _                           ' __inout *hwCaps DDCAPS <record>
   , BYREF helCaps AS DDCAPS _                          ' __inout *helCaps DDCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 56
     BYREF surface AS DDSURFACEDESC2 _                  ' __inout *surface DDSURFACEDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDisplayModesEnum ( _                       ' VTable offset = 60
     BYVAL flags AS LONG _                              ' __in flags CONST_DDEDMFLAGS <enum>
   , BYREF ddsd AS DDSURFACEDESC2 _                     ' __in *ddsd DDSURFACEDESC2 <record>
   ) AS DirectDrawEnumModes                             ' __retval_out **retval DirectDrawEnumModes <interface>
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 64
     BYREF ccCodes AS DWORD _                           ' __inout **ccCodes VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFreeMem ( _                                ' VTable offset = 68
     BYREF ddsCaps AS DDSCAPS2 _                        ' __in *ddsCaps DDSCAPS2 <record>
   ) AS LONG                                            ' __retval_out *m VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 72
   ) AS DirectDrawSurface4                              ' __retval_out **s DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *freq VT_I4 <Long>
   ' =====================================================================================
   METHOD GetNumFourCCCodes ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out *nCodes VT_I4 <Long>
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 84
     BYREF lines AS LONG _                              ' __inout *lines VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSurfaceFromDC ( _                          ' VTable offset = 88
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   ) AS DirectDrawSurface4                              ' __retval_out **retV DirectDrawSurface4 <interface>
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD LoadPaletteFromBitmap ( _                     ' VTable offset = 96
     BYVAL bName AS WSTRING _                           ' __in bName VT_BSTR
   ) AS DirectDrawPalette                               ' __retval_out **retV DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD RestoreAllSurfaces ( _                        ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 108
     BYVAL hdl AS LONG _                                ' __in hdl VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDSCLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 112
     BYVAL w AS LONG _                                  ' __in w VT_I4 <Long>
   , BYVAL h AS LONG _                                  ' __in h VT_I4 <Long>
   , BYVAL bpp AS LONG _                                ' __in bpp VT_I4 <Long>
   , BYVAL ref AS LONG _                                ' __in ref VT_I4 <Long>
   , BYVAL mode AS LONG _                               ' __in mode CONST_DDSDMFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 116
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 120
     BYVAL flags AS LONG _                              ' __in flags CONST_DDWAITVBFLAGS <enum>
   , BYVAL handle AS LONG _                             ' __in handle VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDraw4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawPalette
' IID = {9F76FDC9-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawPalette_INTERFACE_DEFINED)
    %DirectDrawPalette_INTERFACE_DEFINED = 1

INTERFACE DirectDrawPalette $IID_DirectDrawPalette

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpddp AS IUnknown _                          ' __in *lpddp VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpddp VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *caps CONST_DDPCAPSFLAGS <enum>
   ' =====================================================================================
   METHOD GetEntries ( _                                ' VTable offset = 24
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF val AS DWORD _                               ' __inout **val VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEntries ( _                                ' VTable offset = 28
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF val AS DWORD _                               ' __in **val VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEntriesHalftone ( _                        ' VTable offset = 32
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEntriesSystemPalette ( _                   ' VTable offset = 36
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawPalette_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawEnumModes
' IID = {9F76FFFF-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawEnumModes_INTERFACE_DEFINED)
    %DirectDrawEnumModes_INTERFACE_DEFINED = 1

INTERFACE DirectDrawEnumModes $IID_DirectDrawEnumModes

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF info AS DDSURFACEDESC2 _                     ' __inout *info DDSURFACEDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawEnumModes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3D7
' IID = {9F76FDD5-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3D7_INTERFACE_DEFINED)
    %Direct3D7_INTERFACE_DEFINED = 1

INTERFACE Direct3D7 $IID_Direct3D7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 20
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL surf AS DirectDrawSurface7 _                 ' *surf DirectDrawSurface7 <interface>
   ) AS Direct3DDevice7                                 ' __retval_out **ret Direct3DDevice7 <interface>
   ' =====================================================================================
   METHOD CreateVertexBuffer ( _                        ' VTable offset = 24
     BYREF desc AS D3DVERTEXBUFFERDESC _                ' __in *desc D3DVERTEXBUFFERDESC <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DDPFLAGS <enum>
   ) AS Direct3DVertexBuffer7                           ' __retval_out **f Direct3DVertexBuffer7 <interface>
   ' =====================================================================================
   METHOD EvictManagedTextures ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDevicesEnum ( _                            ' VTable offset = 32
   ) AS Direct3DEnumDevices                             ' __retval_out **retV Direct3DEnumDevices <interface>
   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 36
   ) AS DirectDraw7                                     ' __retval_out **retV DirectDraw7 <interface>
   ' =====================================================================================
   METHOD GetEnumZBufferFormats ( _                     ' VTable offset = 40
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS Direct3DEnumPixelFormats                        ' __retval_out **retV Direct3DEnumPixelFormats <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3D7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawSurface7
' IID = {9F76FDE8-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawSurface7_INTERFACE_DEFINED)
    %DirectDrawSurface7_INTERFACE_DEFINED = 1

INTERFACE DirectDrawSurface7 $IID_DirectDrawSurface7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdds AS IUnknown _                          ' __in *lpdds VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdds VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddAttachedSurface ( _                        ' VTable offset = 20
     BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Blt ( _                                       ' VTable offset = 24
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDBLTFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltColorFill ( _                              ' VTable offset = 28
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL fillvalue AS LONG _                          ' __in fillvalue VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltFast ( _                                   ' VTable offset = 32
     BYVAL dx AS LONG _                                 ' __in dx VT_I4 <Long>
   , BYVAL dy AS LONG _                                 ' __in dy VT_I4 <Long>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL trans AS LONG _                              ' __in trans CONST_DDBLTFASTFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltFx ( _                                     ' VTable offset = 36
     BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDBLTFLAGS <enum>
   , BYREF BltFx AS DDBLTFX _                           ' __in *BltFx DDBLTFX <record>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD BltToDC ( _                                   ' VTable offset = 40
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   , BYREF srcRect AS RECT _                            ' __in *srcRect RECT <record>
   , BYREF destRect AS RECT _                           ' __in *destRect RECT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeUniquenessValue ( _                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAttachedSurface ( _                     ' VTable offset = 48
     BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawBox ( _                                   ' VTable offset = 52
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawCircle ( _                                ' VTable offset = 56
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL r AS LONG _                                  ' __in r VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawEllipse ( _                               ' VTable offset = 60
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawLine ( _                                  ' VTable offset = 64
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawRoundedBox ( _                            ' VTable offset = 68
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   , BYVAL rw AS LONG _                                 ' __in rw VT_I4 <Long>
   , BYVAL rh AS LONG _                                 ' __in rh VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 72
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   , BYVAL text AS WSTRING _                            ' __in text VT_BSTR
   , BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 76
     BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDFLIPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedSurface ( _                        ' VTable offset = 80
     BYREF caps AS DDSCAPS2 _                           ' __in *caps DDSCAPS2 <record>
   ) AS DirectDrawSurface7                              ' __retval_out **ddS DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetAttachedSurfaceEnum ( _                    ' VTable offset = 84
   ) AS DirectDrawEnumSurfaces                          ' __retval_out **retval DirectDrawEnumSurfaces <interface>
   ' =====================================================================================
   METHOD GetBltStatus ( _                              ' VTable offset = 88
     BYVAL flags AS LONG _                              ' __in flags CONST_DDGFSFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 92
     BYREF caps AS DDSCAPS2 _                           ' __inout *caps DDSCAPS2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetClipper ( _                                ' VTable offset = 96
   ) AS DirectDrawClipper                               ' __retval_out **val DirectDrawClipper <interface>
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 100
     BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYREF val AS DDCOLORKEY _                          ' __inout *val DDCOLORKEY <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out *hdc VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 108
   ) AS DirectDraw7                                     ' __retval_out **val DirectDraw7 <interface>
   ' =====================================================================================
   METHOD GetDirectDrawColorControl ( _                 ' VTable offset = 112
   ) AS DirectDrawColorControl                          ' __retval_out **retV DirectDrawColorControl <interface>
   ' =====================================================================================
   METHOD GetDirectDrawGammaControl ( _                 ' VTable offset = 116
   ) AS DirectDrawGammaControl                          ' __retval_out **retV DirectDrawGammaControl <interface>
   ' =====================================================================================
   METHOD getDrawStyle ( _                              ' VTable offset = 120
   ) AS LONG                                            ' __retval_out *drawStyle VT_I4 <Long>
   ' =====================================================================================
   METHOD getDrawWidth ( _                              ' VTable offset = 124
   ) AS LONG                                            ' __retval_out *drawWidth VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFillColor ( _                              ' VTable offset = 128
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFillStyle ( _                              ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *fillStyle VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFlipStatus ( _                             ' VTable offset = 136
     BYVAL flags AS LONG _                              ' __in flags CONST_DDGFSFLAGS <enum>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFontTransparency ( _                       ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out *b VT_BOOL <Integer>
   ' =====================================================================================
   METHOD GetForeColor ( _                              ' VTable offset = 144
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLockedPixel ( _                            ' VTable offset = 148
     BYVAL x AS LONG _                                  ' __in x VT_INT <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_INT <Long>
   ) AS LONG                                            ' __retval_out *col VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 152
   ) AS DirectDrawPalette                               ' __retval_out **val DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 156
     BYREF pf AS DDPIXELFORMAT _                        ' __inout *pf DDPIXELFORMAT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 160
     BYREF surface AS DDSURFACEDESC2 _                  ' __inout *surface DDSURFACEDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUniquenessValue ( _                        ' VTable offset = 164
   ) AS LONG                                            ' __retval_out *retval VT_I4 <Long>
   ' =====================================================================================
   METHOD isLost ( _                                    ' VTable offset = 168
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 172
     BYREF r AS RECT _                                  ' __in *r RECT <record>
   , BYREF desc AS DDSURFACEDESC2 _                     ' __in *desc DDSURFACEDESC2 <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDLOCKFLAGS <enum>
   , BYVAL hnd AS LONG _                                ' __in hnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 176
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD restore ( _                                   ' VTable offset = 180
   )                                                    ' void
   ' =====================================================================================
   METHOD SetClipper ( _                                ' VTable offset = 184
     BYVAL val AS DirectDrawClipper _                   ' __in *val DirectDrawClipper <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 188
     BYVAL flags AS LONG _                              ' __in flags CONST_DDCKEYFLAGS <enum>
   , BYREF val AS DDCOLORKEY _                          ' __in *val DDCOLORKEY <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD setDrawStyle ( _                              ' VTable offset = 192
     BYVAL drawStyle AS LONG _                          ' __in drawStyle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD setDrawWidth ( _                              ' VTable offset = 196
     BYVAL drawWidth AS LONG _                          ' __in drawWidth VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFillColor ( _                              ' VTable offset = 200
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFillStyle ( _                              ' VTable offset = 204
     BYVAL fillStyle AS LONG _                          ' __in fillStyle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFont ( _                                   ' VTable offset = 208
     BYVAL font AS IFont _                              ' __in *font IFont <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontTransparency ( _                       ' VTable offset = 212
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetForeColor ( _                              ' VTable offset = 216
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLockedPixel ( _                            ' VTable offset = 220
     BYVAL x AS LONG _                                  ' __in x VT_INT <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_INT <Long>
   , BYVAL col AS LONG _                                ' __in col VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 224
     BYVAL ddp AS DirectDrawPalette _                   ' __in *ddp DirectDrawPalette <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 228
     BYREF r AS RECT _                                  ' __in *r RECT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 232
     BYVAL priority AS LONG _                           ' __in priority VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out *priority VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 240
   ) AS LONG                                            ' __retval_out *lod VT_I4 <Long>
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 244
     BYVAL lod AS LONG _                                ' __in lod VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLockedArray ( _                            ' VTable offset = 248
     BYREF array AS DWORD _                             ' __in **array VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontBackColor ( _                          ' VTable offset = 252
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontBackColor ( _                          ' VTable offset = 256
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD UpdateOverlay ( _                             ' VTable offset = 260
     BYREF RECT AS RECT _                               ' __in *RECT RECT <record>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYREF rectD AS RECT _                              ' __in *rectD RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDOVERFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateOverlayZOrder ( _                       ' VTable offset = 264
     BYVAL flags AS LONG _                              ' __in flags CONST_DDOVERZFLAGS <enum>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOverlayPosition ( _                        ' VTable offset = 268
     BYREF x AS LONG _                                  ' __inout *x VT_I4 <Long>
   , BYREF y AS LONG _                                  ' __inout *y VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOverlayPosition ( _                        ' VTable offset = 272
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOverlayZOrdersEnum ( _                     ' VTable offset = 276
     BYVAL flags AS LONG _                              ' __in flags CONST_DDENUMOVERLAYZFLAGS <enum>
   ) AS DirectDrawEnumSurfaces                          ' __retval_out **retval DirectDrawEnumSurfaces <interface>
   ' =====================================================================================
   METHOD UpdateOverlayFx ( _                           ' VTable offset = 280
     BYREF RECT AS RECT _                               ' __in *RECT RECT <record>
   , BYVAL ddS AS DirectDrawSurface7 _                  ' __in *ddS DirectDrawSurface7 <interface>
   , BYREF rectD AS RECT _                              ' __in *rectD RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDOVERFLAGS <enum>
   , BYREF ddoverfx AS DDOVERLAYFX _                    ' __inout *ddoverfx DDOVERLAYFX <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawSurface7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawEnumSurfaces
' IID = {9F76FDE6-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawEnumSurfaces_INTERFACE_DEFINED)
    %DirectDrawEnumSurfaces_INTERFACE_DEFINED = 1

INTERFACE DirectDrawEnumSurfaces $IID_DirectDrawEnumSurfaces

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS DirectDrawSurface7                              ' __retval_out **retval DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawEnumSurfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDraw7
' IID = {9F76FDE7-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDraw7_INTERFACE_DEFINED)
    %DirectDraw7_INTERFACE_DEFINED = 1

INTERFACE DirectDraw7 $IID_DirectDraw7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateClipper ( _                             ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   ) AS DirectDrawClipper                               ' __retval_out **val DirectDrawClipper <interface>
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 24
     BYVAL flags AS LONG _                              ' __in flags CONST_DDPCAPSFLAGS <enum>
   , BYREF pe AS DWORD _                                ' __in **pe VT_SAFEARRAY
   ) AS DirectDrawPalette                               ' __retval_out **val DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 28
     BYREF dd AS DDSURFACEDESC2 _                       ' __in *dd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD CreateSurfaceFromFile ( _                     ' VTable offset = 32
     BYVAL file AS WSTRING _                            ' __in file VT_BSTR
   , BYREF dd AS DDSURFACEDESC2 _                       ' __inout *dd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD CreateSurfaceFromResource ( _                 ' VTable offset = 36
     BYVAL file AS WSTRING _                            ' __in file VT_BSTR
   , BYVAL resName AS WSTRING _                         ' __in resName VT_BSTR
   , BYREF ddsd AS DDSURFACEDESC2 _                     ' __inout *ddsd DDSURFACEDESC2 <record>
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD DuplicateSurface ( _                          ' VTable offset = 40
     BYVAL ddIn AS DirectDrawSurface7 _                 ' __in *ddIn DirectDrawSurface7 <interface>
   ) AS DirectDrawSurface7                              ' __retval_out **ddOut DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD FlipToGDISurface ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAvailableTotalMem ( _                      ' VTable offset = 48
     BYREF ddsCaps AS DDSCAPS2 _                        ' __in *ddsCaps DDSCAPS2 <record>
   ) AS LONG                                            ' __retval_out *m VT_I4 <Long>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 52
     BYREF hwCaps AS DDCAPS _                           ' __inout *hwCaps DDCAPS <record>
   , BYREF helCaps AS DDCAPS _                          ' __inout *helCaps DDCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDirect3D ( _                               ' VTable offset = 56
   ) AS Direct3D7                                       ' __retval_out **retV Direct3D7 <interface>
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 60
     BYREF surface AS DDSURFACEDESC2 _                  ' __inout *surface DDSURFACEDESC2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDisplayModesEnum ( _                       ' VTable offset = 64
     BYVAL flags AS LONG _                              ' __in flags CONST_DDEDMFLAGS <enum>
   , BYREF ddsd AS DDSURFACEDESC2 _                     ' __in *ddsd DDSURFACEDESC2 <record>
   ) AS DirectDrawEnumModes                             ' __retval_out **retval DirectDrawEnumModes <interface>
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 68
     BYREF ccCodes AS DWORD _                           ' __inout **ccCodes VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFreeMem ( _                                ' VTable offset = 72
     BYREF ddsCaps AS DDSCAPS2 _                        ' __in *ddsCaps DDSCAPS2 <record>
   ) AS LONG                                            ' __retval_out *m VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGDISurface ( _                             ' VTable offset = 76
   ) AS DirectDrawSurface7                              ' __retval_out **s DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetMonitorFrequency ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out *freq VT_I4 <Long>
   ' =====================================================================================
   METHOD GetNumFourCCCodes ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out *nCodes VT_I4 <Long>
   ' =====================================================================================
   METHOD GetScanLine ( _                               ' VTable offset = 88
     BYREF lines AS LONG _                              ' __inout *lines VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSurfaceFromDC ( _                          ' VTable offset = 92
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetSurfacesEnum ( _                           ' VTable offset = 96
     BYVAL flags AS LONG _                              ' __in flags CONST_DDENUMSURFACESFLAGS <enum>
   , BYREF desc AS DDSURFACEDESC2 _                     ' __in *desc DDSURFACEDESC2 <record>
   ) AS DirectDrawEnumSurfaces                          ' __retval_out **ret DirectDrawEnumSurfaces <interface>
   ' =====================================================================================
   METHOD GetVerticalBlankStatus ( _                    ' VTable offset = 100
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD LoadPaletteFromBitmap ( _                     ' VTable offset = 104
     BYVAL bName AS WSTRING _                           ' __in bName VT_BSTR
   ) AS DirectDrawPalette                               ' __retval_out **retV DirectDrawPalette <interface>
   ' =====================================================================================
   METHOD RestoreAllSurfaces ( _                        ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDisplayMode ( _                        ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 116
     BYVAL hdl AS LONG _                                ' __in hdl VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DDSCLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDisplayMode ( _                            ' VTable offset = 120
     BYVAL w AS LONG _                                  ' __in w VT_I4 <Long>
   , BYVAL h AS LONG _                                  ' __in h VT_I4 <Long>
   , BYVAL bpp AS LONG _                                ' __in bpp VT_I4 <Long>
   , BYVAL ref AS LONG _                                ' __in ref VT_I4 <Long>
   , BYVAL mode AS LONG _                               ' __in mode CONST_DDSDMFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 124
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD WaitForVerticalBlank ( _                      ' VTable offset = 128
     BYVAL flags AS LONG _                              ' __in flags CONST_DDWAITVBFLAGS <enum>
   , BYVAL handle AS LONG _                             ' __in handle VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *status VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDeviceIdentifier ( _                       ' VTable offset = 132
     BYVAL flags AS LONG _                              ' __in flags CONST_DDDEVICEIDFLAGS <enum>
   ) AS DirectDrawIdentifier                            ' __retval_out **ret DirectDrawIdentifier <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDraw7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawIdentifier
' IID = {BCAA7DA4-F7EF-11D2-93FD-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawIdentifier_INTERFACE_DEFINED)
    %DirectDrawIdentifier_INTERFACE_DEFINED = 1

INTERFACE DirectDrawIdentifier $IID_DirectDrawIdentifier

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetDriver ( _                                 ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetDriverVersion ( _                          ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDriverSubVersion ( _                       ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetVendorId ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDeviceId ( _                               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSubSysId ( _                               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetRevision ( _                               ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDeviceIndentifier ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetWHQLLevel ( _                              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawIdentifier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawColorControl
' IID = {9F76FDE0-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawColorControl_INTERFACE_DEFINED)
    %DirectDrawColorControl_INTERFACE_DEFINED = 1

INTERFACE DirectDrawColorControl $IID_DirectDrawColorControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdds AS IUnknown _                          ' __in *lpdds VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdds VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetColorControls ( _                          ' VTable offset = 20
     BYREF colorControl AS DDCOLORCONTROL _             ' __inout *colorControl DDCOLORCONTROL <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorControls ( _                          ' VTable offset = 24
     BYREF colorControl AS DDCOLORCONTROL _             ' __in *colorControl DDCOLORCONTROL <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawColorControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawGammaControl
' IID = {9F76FDE9-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawGammaControl_INTERFACE_DEFINED)
    %DirectDrawGammaControl_INTERFACE_DEFINED = 1

INTERFACE DirectDrawGammaControl $IID_DirectDrawGammaControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdds AS IUnknown _                          ' __in *lpdds VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdds VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetGammaRamp ( _                              ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in flags CONST_DDSGRFLAGS <enum>
   , BYREF gammaRamp AS DDGAMMARAMP _                   ' __inout *gammaRamp DDGAMMARAMP <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGammaRamp ( _                              ' VTable offset = 24
     BYVAL flags AS LONG _                              ' __in flags CONST_DDSGRFLAGS <enum>
   , BYREF gammaRamp AS DDGAMMARAMP _                   ' __in *gammaRamp DDGAMMARAMP <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawGammaControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DDevice7
' IID = {9F76FDD7-8E92-11D1-8808-00C04FC2C602}
' Direct3DDevice7 Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DDevice7_INTERFACE_DEFINED)
    %Direct3DDevice7_INTERFACE_DEFINED = 1

INTERFACE Direct3DDevice7 $IID_Direct3DDevice7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD ApplyStateBlock ( _                           ' VTable offset = 20
     BYVAL blockHandle AS LONG _                        ' __in blockHandle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginScene ( _                                ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginStateBlock ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD CaptureStateBlock ( _                         ' VTable offset = 32
     BYVAL blockHandle AS LONG _                        ' __in blockHandle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 36
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF recs AS DWORD _                              ' __in **recs VT_SAFEARRAY
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DCLEARFLAGS <enum>
   , BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL stencil AS LONG _                            ' __in stencil VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD ComputeSphereVisibility ( _                   ' VTable offset = 40
     BYREF center AS D3DVECTOR _                        ' *center D3DVECTOR <record>
   , BYREF radius AS SINGLE _                           ' *radius VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *returnVal VT_I4 <Long>
   ' =====================================================================================
   METHOD DeleteStateBlock ( _                          ' VTable offset = 44
     BYVAL blockHandle AS LONG _                        ' __in blockHandle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawIndexedPrimitive ( _                      ' VTable offset = 48
     BYVAL d3dpt AS LONG _                              ' __in d3dpt CONST_D3DPRIMITIVETYPE <enum>
   , BYVAL d3dfvf AS LONG _                             ' __in d3dfvf CONST_D3DFVFFLAGS <enum>
   , BYVAL vertices AS DWORD _                          ' __in *vertices VT_VOID <Dword>
   , BYVAL VertexCount AS LONG _                        ' __in VertexCount VT_I4 <Long>
   , BYREF indices AS DWORD _                           ' __in **indices VT_SAFEARRAY
   , BYVAL IndicesCount AS LONG _                       ' __in IndicesCount VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DDPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawIndexedPrimitiveVB ( _                    ' VTable offset = 52
     BYVAL d3dpt AS LONG _                              ' __in d3dpt CONST_D3DPRIMITIVETYPE <enum>
   , BYVAL vertexBuffer AS Direct3DVertexBuffer7 _      ' __in *vertexBuffer Direct3DVertexBuffer7 <interface>
   , BYVAL startVertex AS LONG _                        ' __in startVertex VT_I4 <Long>
   , BYVAL numVertices AS LONG _                        ' __in numVertices VT_I4 <Long>
   , BYREF indexArray AS DWORD _                        ' __in **indexArray VT_SAFEARRAY
   , BYVAL indexcount AS LONG _                         ' __in indexcount VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DDPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawPrimitive ( _                             ' VTable offset = 56
     BYVAL d3dpt AS LONG _                              ' __in d3dpt CONST_D3DPRIMITIVETYPE <enum>
   , BYVAL d3dfvf AS LONG _                             ' __in d3dfvf CONST_D3DFVFFLAGS <enum>
   , BYVAL vertices AS DWORD _                          ' __in *vertices VT_VOID <Dword>
   , BYVAL VertexCount AS LONG _                        ' __in VertexCount VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DDPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawPrimitiveVB ( _                           ' VTable offset = 60
     BYVAL d3dpt AS LONG _                              ' __in d3dpt CONST_D3DPRIMITIVETYPE <enum>
   , BYVAL vertexBuffer AS Direct3DVertexBuffer7 _      ' __in *vertexBuffer Direct3DVertexBuffer7 <interface>
   , BYVAL startVertex AS LONG _                        ' __in startVertex VT_I4 <Long>
   , BYVAL numVertices AS LONG _                        ' __in numVertices VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DDPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD EndScene ( _                                  ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD EndStateBlock ( _                             ' VTable offset = 68
     BYREF blockHandle AS LONG _                        ' __in *blockHandle VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 72
     BYREF desc AS D3DDEVICEDESC7 _                     ' __inout *desc D3DDEVICEDESC7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetClipStatus ( _                             ' VTable offset = 76
     BYREF clipStatus AS D3DCLIPSTATUS _                ' __inout *clipStatus D3DCLIPSTATUS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDirect3D ( _                               ' VTable offset = 80
   ) AS Direct3D7                                       ' __retval_out **dev Direct3D7 <interface>
   ' =====================================================================================
   METHOD GetLight ( _                                  ' VTable offset = 84
     BYVAL LightIndex AS LONG _                         ' __in LightIndex VT_I4 <Long>
   , BYREF Light AS D3DLIGHT7 _                         ' __inout *Light D3DLIGHT7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLightEnable ( _                            ' VTable offset = 88
     BYVAL LightIndex AS LONG _                         ' __in LightIndex VT_I4 <Long>
   ) AS INTEGER                                         ' __retval_out *b VT_BOOL <Integer>
   ' =====================================================================================
   METHOD GetMaterial ( _                               ' VTable offset = 92
     BYREF Material AS D3DMATERIAL7 _                   ' __inout *Material D3DMATERIAL7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRenderState ( _                            ' VTable offset = 96
     BYVAL state AS LONG _                              ' __in state CONST_D3DRENDERSTATETYPE <enum>
   ) AS LONG                                            ' __retval_out *renderstate VT_I4 <Long>
   ' =====================================================================================
   METHOD GetRenderTarget ( _                           ' VTable offset = 100
   ) AS DirectDrawSurface7                              ' __retval_out **ppval DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 104
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetTextureFormatsEnum ( _                     ' VTable offset = 108
   ) AS Direct3DEnumPixelFormats                        ' __retval_out **retval Direct3DEnumPixelFormats <interface>
   ' =====================================================================================
   METHOD GetTextureStageState ( _                      ' VTable offset = 112
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   , BYVAL state AS LONG _                              ' __in state CONST_D3DTEXTURESTAGESTATETYPE <enum>
   ) AS LONG                                            ' __retval_out *val VT_I4 <Long>
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 116
     BYVAL transformType AS LONG _                      ' __in transformType CONST_D3DTRANSFORMSTATETYPE <enum>
   , BYREF matrix AS D3DMATRIX _                        ' __inout *matrix D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 120
     BYREF viewport AS D3DVIEWPORT7 _                   ' __inout *viewport D3DVIEWPORT7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD LightEnable ( _                               ' VTable offset = 124
     BYVAL LightIndex AS LONG _                         ' __in LightIndex VT_I4 <Long>
   , BYVAL bEnable AS INTEGER _                         ' __in bEnable VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 128
     BYVAL DestTex AS DirectDrawSurface7 _              ' __in *DestTex DirectDrawSurface7 <interface>
   , BYVAL xDest AS LONG _                              ' __in xDest VT_I4 <Long>
   , BYVAL yDest AS LONG _                              ' __in yDest VT_I4 <Long>
   , BYVAL SrcTex AS DirectDrawSurface7 _               ' __in *SrcTex DirectDrawSurface7 <interface>
   , BYREF rcSrcRect AS RECT _                          ' __in *rcSrcRect RECT <record>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD MultiplyTransform ( _                         ' VTable offset = 132
     BYVAL dstTransfromStateType AS LONG _              ' __in dstTransfromStateType CONST_D3DTRANSFORMSTATETYPE <enum>
   , BYREF matrix AS D3DMATRIX _                        ' __inout *matrix D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 136
     BYVAL texture AS DirectDrawSurface7 _              ' __in *texture DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetClipStatus ( _                             ' VTable offset = 140
     BYREF clipStatus AS D3DCLIPSTATUS _                ' __in *clipStatus D3DCLIPSTATUS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLight ( _                                  ' VTable offset = 144
     BYVAL LightIndex AS LONG _                         ' __in LightIndex VT_I4 <Long>
   , BYREF Light AS D3DLIGHT7 _                         ' __in *Light D3DLIGHT7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 148
     BYREF mat AS D3DMATERIAL7 _                        ' __in *mat D3DMATERIAL7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRenderState ( _                            ' VTable offset = 152
     BYVAL state AS LONG _                              ' __in state CONST_D3DRENDERSTATETYPE <enum>
   , BYVAL renderstate AS LONG _                        ' __in renderstate VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRenderTarget ( _                           ' VTable offset = 156
     BYVAL surface AS DirectDrawSurface7 _              ' __in *surface DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 160
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   , BYVAL texture AS DirectDrawSurface7 _              ' __in *texture DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureStageState ( _                      ' VTable offset = 164
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   , BYVAL state AS LONG _                              ' __in state CONST_D3DTEXTURESTAGESTATETYPE <enum>
   , BYVAL value AS LONG _                              ' __in value VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 168
     BYVAL transformType AS LONG _                      ' __in transformType CONST_D3DTRANSFORMSTATETYPE <enum>
   , BYREF matrix AS D3DMATRIX _                        ' __in *matrix D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 172
     BYREF viewport AS D3DVIEWPORT7 _                   ' __in *viewport D3DVIEWPORT7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD ValidateDevice ( _                            ' VTable offset = 176
   ) AS LONG                                            ' __retval_out *passes VT_I4 <Long>
   ' =====================================================================================
   METHOD SetTextureStageStateSingle ( _                ' VTable offset = 180
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   , BYVAL state AS LONG _                              ' __in state CONST_D3DTEXTURESTAGESINGLE <enum>
   , BYVAL value AS SINGLE _                            ' __in value VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextureStageStateSingle ( _                ' VTable offset = 184
     BYVAL stage AS LONG _                              ' __in stage VT_I4 <Long>
   , BYVAL state AS LONG _                              ' __in state CONST_D3DTEXTURESTAGESINGLE <enum>
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 188
     BYVAL lDevInfoID AS LONG _                         ' __in lDevInfoID CONST_D3DDEVINFOID <enum>
   , BYVAL DevInfoType AS DWORD _                       ' __inout *DevInfoType VT_VOID <Dword>
   , BYVAL lSize AS LONG _                              ' __in lSize VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRenderStateSingle ( _                      ' VTable offset = 192
     BYVAL state AS LONG _                              ' __in state CONST_D3DRENDERSTATESINGLE <enum>
   , BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRenderStateSingle ( _                      ' VTable offset = 196
     BYVAL state AS LONG _                              ' __in state CONST_D3DRENDERSTATESINGLE <enum>
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD GetDeviceGuid ( _                             ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD CreateStateBlock ( _                          ' VTable offset = 204
     BYVAL d3dsbType AS LONG _                          ' __in d3dsbType CONST_D3DSTATEBLOCKTYPE <enum>
   ) AS LONG                                            ' __retval_out *blockHandle VT_I4 <Long>
   ' =====================================================================================
   METHOD SetClipPlane ( _                              ' VTable offset = 208
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYVAL a AS SINGLE _                                ' __in a VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   , BYVAL c AS SINGLE _                                ' __in c VT_R4 <Single>
   , BYVAL D AS SINGLE _                                ' __in D VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetClipPlane ( _                              ' VTable offset = 212
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF a AS SINGLE _                                ' __inout *a VT_R4 <Single>
   , BYREF b AS SINGLE _                                ' __inout *b VT_R4 <Single>
   , BYREF c AS SINGLE _                                ' __inout *c VT_R4 <Single>
   , BYREF D AS SINGLE _                                ' __inout *D VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DDevice7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DVertexBuffer7
' IID = {9F76FDDA-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DVertexBuffer7_INTERFACE_DEFINED)
    %Direct3DVertexBuffer7_INTERFACE_DEFINED = 1

INTERFACE Direct3DVertexBuffer7 $IID_Direct3DVertexBuffer7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetVertexBufferDesc ( _                       ' VTable offset = 20
     BYREF desc AS D3DVERTEXBUFFERDESC _                ' __inout *desc D3DVERTEXBUFFERDESC <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertices ( _                               ' VTable offset = 24
     BYVAL startIndex AS LONG _                         ' __in startIndex VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYVAL verts AS DWORD _                             ' __in *verts VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 28
     BYVAL flags AS LONG _                              ' __in flags CONST_DDLOCKFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 32
     BYVAL dev AS Direct3DDevice7 _                     ' __in *dev Direct3DDevice7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD ProcessVertices ( _                           ' VTable offset = 36
     BYVAL vertexOp AS LONG _                           ' __in vertexOp CONST_D3DVOPFLAGS <enum>
   , BYVAL destIndex AS LONG _                          ' __in destIndex VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYVAL srcBuffer AS Direct3DVertexBuffer7 _         ' __in *srcBuffer Direct3DVertexBuffer7 <interface>
   , BYVAL srcIndex AS LONG _                           ' __in srcIndex VT_I4 <Long>
   , BYVAL dev AS Direct3DDevice7 _                     ' __in *dev Direct3DDevice7 <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DPROCESSVERTICESFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertices ( _                               ' VTable offset = 40
     BYVAL startIndex AS LONG _                         ' __in startIndex VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYVAL verts AS DWORD _                             ' __in *verts VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertexSize ( _                             ' VTable offset = 48
     BYVAL vertexSizeInBytes AS LONG _                  ' __in vertexSizeInBytes VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DVertexBuffer7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DEnumPixelFormats
' IID = {9F76FDD6-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DEnumPixelFormats_INTERFACE_DEFINED)
    %Direct3DEnumPixelFormats_INTERFACE_DEFINED = 1

INTERFACE Direct3DEnumPixelFormats $IID_Direct3DEnumPixelFormats

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF pixelFormat AS DDPIXELFORMAT _               ' __inout *pixelFormat DDPIXELFORMAT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DEnumPixelFormats_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DEnumDevices
' IID = {9F76FDD3-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DEnumDevices_INTERFACE_DEFINED)
    %Direct3DEnumDevices_INTERFACE_DEFINED = 1

INTERFACE Direct3DEnumDevices $IID_Direct3DEnumDevices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF hwDesc AS D3DDEVICEDESC7 _                   ' __inout *hwDesc D3DDEVICEDESC7 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DEnumDevices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectDrawEnum
' IID = {9F76FDE1-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectDrawEnum_INTERFACE_DEFINED)
    %DirectDrawEnum_INTERFACE_DEFINED = 1

INTERFACE DirectDrawEnum $IID_DirectDrawEnum

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetMonitorHandle ( _                          ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectDrawEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMVisual
' IID = {9F76FE0F-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMVisual_INTERFACE_DEFINED)
    %Direct3DRMVisual_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMVisual $IID_Direct3DRMVisual

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMVisual_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFace2
' IID = {9F76FE32-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFace2_INTERFACE_DEFINED)
    %Direct3DRMFace2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFace2 $IID_Direct3DRMFace2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddVertex ( _                                 ' VTable offset = 52
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddVertexAndNormalIndexed ( _                 ' VTable offset = 56
     BYVAL vertexIndex AS LONG _                        ' __in vertexIndex VT_I4 <Long>
   , BYVAL normalIndex AS LONG _                        ' __in normalIndex VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 60
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMaterial ( _                               ' VTable offset = 64
   ) AS Direct3DRMMaterial2                             ' __retval_out **retV Direct3DRMMaterial2 <interface>
   ' =====================================================================================
   METHOD GetNormal ( _                                 ' VTable offset = 68
     BYREF val AS D3DVECTOR _                           ' __inout *val D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 72
   ) AS Direct3DRMTexture3                              ' __retval_out **ref Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD GetTextureCoordinateIndex ( _                 ' VTable offset = 76
     BYVAL which AS LONG _                              ' __in which VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV VT_INT <Long>
   ' =====================================================================================
   METHOD GetTextureCoordinates ( _                     ' VTable offset = 80
     BYVAL vertex AS LONG _                             ' __in vertex VT_I4 <Long>
   , BYREF u AS SINGLE _                                ' __inout *u VT_R4 <Single>
   , BYREF v AS SINGLE _                                ' __inout *v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertex ( _                                 ' VTable offset = 84
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYREF vert AS D3DVECTOR _                          ' __inout *vert D3DVECTOR <record>
   , BYREF norm AS D3DVECTOR _                          ' __inout *norm D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertexCount ( _                            ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *retV VT_INT <Long>
   ' =====================================================================================
   METHOD GetVertexIndex ( _                            ' VTable offset = 92
     BYVAL which AS LONG _                              ' __in which VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV VT_INT <Long>
   ' =====================================================================================
   METHOD GetVertices ( _                               ' VTable offset = 96
     BYVAL VertexCount AS LONG _                        ' __in VertexCount VT_I4 <Long>
   , BYREF coord AS DWORD _                             ' __inout **coord VT_SAFEARRAY
   , BYREF normals AS DWORD _                           ' __inout **normals VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVerticesJava ( _                           ' VTable offset = 100
     BYVAL vertex_cnt AS LONG _                         ' __in vertex_cnt VT_I4 <Long>
   , BYREF coord AS SINGLE _                            ' __inout *coord VT_R4 <Single>
   , BYREF normals AS SINGLE _                          ' __inout *normals VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 104
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 108
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 112
     BYVAL ref AS Direct3DRMMaterial2 _                 ' __in *ref Direct3DRMMaterial2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 116
     BYVAL ref AS Direct3DRMTexture3 _                  ' __in *ref Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureCoordinates ( _                     ' VTable offset = 120
     BYVAL vertex AS LONG _                             ' __in vertex VT_I4 <Long>
   , BYVAL u AS SINGLE _                                ' __in u VT_R4 <Single>
   , BYVAL v AS SINGLE _                                ' __in v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureTopology ( _                        ' VTable offset = 124
     BYVAL wrap_u AS LONG _                             ' __in wrap_u CONST_DBOOLFLAGS <enum>
   , BYVAL wrap_v AS LONG _                             ' __in wrap_v CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextureTopology ( _                        ' VTable offset = 128
     BYREF wrap_u AS LONG _                             ' __inout *wrap_u CONST_DBOOLFLAGS <enum>
   , BYREF wrap_v AS LONG _                             ' __inout *wrap_v CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFace2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMMaterial2
' IID = {9F76FE21-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMMaterial2_INTERFACE_DEFINED)
    %Direct3DRMMaterial2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMMaterial2 $IID_Direct3DRMMaterial2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetPower ( _                                  ' VTable offset = 52
     BYVAL power AS SINGLE _                            ' __in power VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSpecular ( _                               ' VTable offset = 56
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEmissive ( _                               ' VTable offset = 60
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAmbient ( _                                ' VTable offset = 64
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPower ( _                                  ' VTable offset = 68
   ) AS SINGLE                                          ' __retval_out *power VT_R4 <Single>
   ' =====================================================================================
   METHOD GetSpecular ( _                               ' VTable offset = 72
     BYREF r AS SINGLE _                                ' __out *r VT_R4 <Single>
   , BYREF g AS SINGLE _                                ' __out *g VT_R4 <Single>
   , BYREF b AS SINGLE _                                ' __out *b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEmissive ( _                               ' VTable offset = 76
     BYREF r AS SINGLE _                                ' __out *r VT_R4 <Single>
   , BYREF g AS SINGLE _                                ' __out *g VT_R4 <Single>
   , BYREF b AS SINGLE _                                ' __out *b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAmbient ( _                                ' VTable offset = 80
     BYREF r AS SINGLE _                                ' __out *r VT_R4 <Single>
   , BYREF g AS SINGLE _                                ' __out *g VT_R4 <Single>
   , BYREF b AS SINGLE _                                ' __out *b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMMaterial2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMLight
' IID = {9F76FE03-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMLight_INTERFACE_DEFINED)
    %Direct3DRMLight_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMLight $IID_Direct3DRMLight

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetType ( _                                   ' VTable offset = 52
     BYVAL t AS LONG _                                  ' __in t CONST_D3DRMLIGHTTYPE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 56
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 60
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRange ( _                                  ' VTable offset = 64
     BYVAL rng AS SINGLE _                              ' __in rng VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUmbra ( _                                  ' VTable offset = 68
     BYVAL u AS SINGLE _                                ' __in u VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPenumbra ( _                               ' VTable offset = 72
     BYVAL p AS SINGLE _                                ' __in p VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConstantAttenuation ( _                    ' VTable offset = 76
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLinearAttenuation ( _                      ' VTable offset = 80
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuadraticAttenuation ( _                   ' VTable offset = 84
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 88
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetUmbra ( _                                  ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetPenumbra ( _                               ' VTable offset = 96
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetConstantAttenuation ( _                    ' VTable offset = 100
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetLinearAttenuation ( _                      ' VTable offset = 104
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetQuadraticAttenuation ( _                   ' VTable offset = 108
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 112
   ) AS LONG                                            ' __retval_out *value VT_I4 <Long>
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 116
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMLIGHTTYPE <enum>
   ' =====================================================================================
   METHOD SetEnableFrame ( _                            ' VTable offset = 120
     BYVAL f AS Direct3DRMFrame3 _                      ' __in *f Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnableFrame ( _                            ' VTable offset = 124
   ) AS Direct3DRMFrame3                                ' __retval_out **retV Direct3DRMFrame3 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMLight_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFrame3
' IID = {9F76FE25-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFrame3_INTERFACE_DEFINED)
    %Direct3DRMFrame3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFrame3 $IID_Direct3DRMFrame3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddVisual ( _                                 ' VTable offset = 52
     BYVAL v AS Direct3DRMVisual _                      ' __in *v Direct3DRMVisual <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteVisual ( _                              ' VTable offset = 56
     BYVAL v AS Direct3DRMVisual _                      ' __in *v Direct3DRMVisual <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddLight ( _                                  ' VTable offset = 60
     BYVAL val AS Direct3DRMLight _                     ' __in *val Direct3DRMLight <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteLight ( _                               ' VTable offset = 64
     BYVAL l AS Direct3DRMLight _                       ' __in *l Direct3DRMLight <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddChild ( _                                  ' VTable offset = 68
     BYVAL child AS Direct3DRMFrame3 _                  ' __in *child Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteChild ( _                               ' VTable offset = 72
     BYVAL c AS Direct3DRMFrame3 _                      ' __in *c Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 76
     BYVAL referenceFrame AS Direct3DRMFrame3 _         ' __in *referenceFrame Direct3DRMFrame3 <interface>
   , BYREF val AS DWORD _                               ' __inout **val VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTransform ( _                              ' VTable offset = 80
     BYVAL t AS LONG _                                  ' __in t CONST_D3DRMCOMBINETYPE <enum>
   , BYREF val AS DWORD _                               ' __in **val VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTranslation ( _                            ' VTable offset = 84
     BYVAL t AS LONG _                                  ' __in t CONST_D3DRMCOMBINETYPE <enum>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddScale ( _                                  ' VTable offset = 88
     BYVAL combineType AS LONG _                        ' __in combineType CONST_D3DRMCOMBINETYPE <enum>
   , BYVAL sx AS SINGLE _                               ' __in sx VT_R4 <Single>
   , BYVAL sy AS SINGLE _                               ' __in sy VT_R4 <Single>
   , BYVAL sz AS SINGLE _                               ' __in sz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRotation ( _                               ' VTable offset = 92
     BYVAL combineType AS LONG _                        ' __in combineType CONST_D3DRMCOMBINETYPE <enum>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL theta AS SINGLE _                            ' __in theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMoveCallback ( _                           ' VTable offset = 96
     BYVAL frameMoveImplementation AS Direct3DRMFrameMoveCallback3 _ ' __in *frameMoveImplementation Direct3DRMFrameMoveCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMCALLBACKORDERFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMoveCallback ( _                        ' VTable offset = 100
     BYVAL frameMoveImplementation AS Direct3DRMFrameMoveCallback3 _ ' __in *frameMoveImplementation Direct3DRMFrameMoveCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD Transform ( _                                 ' VTable offset = 104
     BYREF D AS D3DVECTOR _                             ' __inout *D D3DVECTOR <record>
   , BYREF s AS D3DVECTOR _                             ' __in *s D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD TransformVectors ( _                          ' VTable offset = 108
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL num AS LONG _                                ' __in num VT_I4 <Long>
   , BYREF DstVectors AS DWORD _                        ' __inout **DstVectors VT_SAFEARRAY
   , BYREF SrcVectors AS DWORD _                        ' __inout **SrcVectors VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD InverseTransform ( _                          ' VTable offset = 112
     BYREF D AS D3DVECTOR _                             ' __inout *D D3DVECTOR <record>
   , BYREF s AS D3DVECTOR _                             ' __in *s D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD InverseTransformVectors ( _                   ' VTable offset = 116
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL num AS LONG _                                ' __in num VT_I4 <Long>
   , BYREF DstVectors AS DWORD _                        ' __inout **DstVectors VT_SAFEARRAY
   , BYREF SrcVectors AS DWORD _                        ' __inout **SrcVectors VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAxes ( _                                   ' VTable offset = 120
     BYREF dir AS D3DVECTOR _                           ' __inout *dir D3DVECTOR <record>
   , BYREF up AS D3DVECTOR _                            ' __inout *up D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBox ( _                                    ' VTable offset = 124
     BYREF box AS D3DRMBOX _                            ' __inout *box D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBoxEnable ( _                              ' VTable offset = 128
   ) AS LONG                                            ' __retval_out *b CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 132
   ) AS Direct3DRMFrameArray                            ' __retval_out **children Direct3DRMFrameArray <interface>
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 136
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetHierarchyBox ( _                           ' VTable offset = 140
     BYREF box AS D3DRMBOX _                            ' __inout *box D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInheritAxes ( _                            ' VTable offset = 144
   ) AS LONG                                            ' __retval_out *b CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetLights ( _                                 ' VTable offset = 148
   ) AS Direct3DRMLightArray                            ' __retval_out **lights Direct3DRMLightArray <interface>
   ' =====================================================================================
   METHOD GetMaterial ( _                               ' VTable offset = 152
     BYREF ret AS Direct3DRMMaterial2 _                 ' **ret Direct3DRMMaterial2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMaterialMode ( _                           ' VTable offset = 156
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMMATERIALMODE <enum>
   ' =====================================================================================
   METHOD GetOrientation ( _                            ' VTable offset = 160
     BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF dir AS D3DVECTOR _                           ' __inout *dir D3DVECTOR <record>
   , BYREF up AS D3DVECTOR _                            ' __inout *up D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMaterialOverride ( _                       ' VTable offset = 164
     BYREF override AS D3DRMMATERIALOVERRIDE _          ' __inout *override D3DRMMATERIALOVERRIDE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMaterialOverrideTexture ( _                ' VTable offset = 168
   ) AS Direct3DRMTexture3                              ' __retval_out **ret Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 172
   ) AS Direct3DRMFrame3                                ' __retval_out **retV Direct3DRMFrame3 <interface>
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 176
     BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF position AS D3DVECTOR _                      ' __inout *position D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRotation ( _                               ' VTable offset = 180
     BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF axis AS D3DVECTOR _                          ' __inout *axis D3DVECTOR <record>
   , BYREF theta AS SINGLE _                            ' __out *theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetScene ( _                                  ' VTable offset = 184
   ) AS Direct3DRMFrame3                                ' __retval_out **retV Direct3DRMFrame3 <interface>
   ' =====================================================================================
   METHOD GetSceneBackground ( _                        ' VTable offset = 188
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSceneBackgroundDepth ( _                   ' VTable offset = 192
   ) AS DirectDrawSurface7                              ' __retval_out **retV DirectDrawSurface7 <interface>
   ' =====================================================================================
   METHOD GetSceneFogColor ( _                          ' VTable offset = 196
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSceneFogEnable ( _                         ' VTable offset = 200
   ) AS LONG                                            ' __retval_out *bEnable CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetSceneFogMode ( _                           ' VTable offset = 204
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMFOGMODE <enum>
   ' =====================================================================================
   METHOD GetSceneFogMethod ( _                         ' VTable offset = 208
   ) AS LONG                                            ' __retval_out *method CONST_D3DRMFOGMETHOD <enum>
   ' =====================================================================================
   METHOD GetSceneFogParams ( _                         ' VTable offset = 212
     BYREF start AS SINGLE _                            ' __inout *start VT_R4 <Single>
   , BYREF end AS SINGLE _                              ' __inout *end VT_R4 <Single>
   , BYREF density AS SINGLE _                          ' __inout *density VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSortMode ( _                               ' VTable offset = 216
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMSORTMODE <enum>
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 220
   ) AS Direct3DRMTexture3                              ' __retval_out **ref Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD GetVelocity ( _                               ' VTable offset = 224
     BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF vel AS D3DVECTOR _                           ' __inout *vel D3DVECTOR <record>
   , BYVAL includeRotationalVelocity AS LONG _          ' __in includeRotationalVelocity CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisuals ( _                                ' VTable offset = 228
   ) AS Direct3DRMVisualArray                           ' __retval_out **visuals Direct3DRMVisualArray <interface>
   ' =====================================================================================
   METHOD GetVisual ( _                                 ' VTable offset = 232
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMVisual                                ' __retval_out **visualArray Direct3DRMVisual <interface>
   ' =====================================================================================
   METHOD GetVisualCount ( _                            ' VTable offset = 236
   ) AS LONG                                            ' __retval_out *vis VT_I4 <Long>
   ' =====================================================================================
   METHOD GetTraversalOptions ( _                       ' VTable offset = 240
   ) AS LONG                                            ' __retval_out *ret CONST_D3DRMTRAVERALFLAGS <enum>
   ' =====================================================================================
   METHOD GetZBufferMode ( _                            ' VTable offset = 244
   ) AS LONG                                            ' __retval_out *ret CONST_D3DRMZBUFFERMODE <enum>
   ' =====================================================================================
   METHOD LoadFromFile ( _                              ' VTable offset = 248
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   , BYVAL id AS VARIANT _                              ' __in id VT_VARIANT <Variant>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMLOADFLAGS <enum>
   , BYVAL loadTextureImplementation AS Direct3DRMLoadTextureCallback3 _ ' __in *loadTextureImplementation Direct3DRMLoadTextureCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD LookAt ( _                                    ' VTable offset = 252
     BYVAL tgt AS Direct3DRMFrame3 _                    ' __in *tgt Direct3DRMFrame3 <interface>
   , BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL contraint AS LONG _                          ' __in contraint CONST_D3DRMFRAMECONSTRAINT <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 256
     BYVAL delta AS SINGLE _                            ' __in delta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD RayPick ( _                                   ' VTable offset = 260
     BYVAL refer AS Direct3DRMFrame3 _                  ' __in *refer Direct3DRMFrame3 <interface>
   , BYREF ray AS D3DRMRAY _                            ' __in *ray D3DRMRAY <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMRAYPICKFLAGS <enum>
   ) AS Direct3DRMPick2Array                            ' __retval_out **retV Direct3DRMPick2Array <interface>
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 264
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   , BYVAL format AS LONG _                             ' __in format CONST_D3DRMXOFFORMAT <enum>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMSAVEFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAxes ( _                                   ' VTable offset = 268
     BYVAL dx AS SINGLE _                               ' __in dx VT_R4 <Single>
   , BYVAL dy AS SINGLE _                               ' __in dy VT_R4 <Single>
   , BYVAL dz AS SINGLE _                               ' __in dz VT_R4 <Single>
   , BYVAL ux AS SINGLE _                               ' __in ux VT_R4 <Single>
   , BYVAL uy AS SINGLE _                               ' __in uy VT_R4 <Single>
   , BYVAL uz AS SINGLE _                               ' __in uz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBox ( _                                    ' VTable offset = 272
     BYREF box AS D3DRMBOX _                            ' __in *box D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBoxEnable ( _                              ' VTable offset = 276
     BYVAL boxEnable AS LONG _                          ' __in boxEnable CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 280
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 284
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInheritAxes ( _                            ' VTable offset = 288
     BYVAL inheritFromParent AS LONG _                  ' __in inheritFromParent CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 292
     BYVAL mat AS Direct3DRMMaterial2 _                 ' __in *mat Direct3DRMMaterial2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterialMode ( _                           ' VTable offset = 296
     BYVAL val AS LONG _                                ' __in val CONST_D3DRMMATERIALMODE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterialOverride ( _                       ' VTable offset = 300
     BYREF override AS D3DRMMATERIALOVERRIDE _          ' __inout *override D3DRMMATERIALOVERRIDE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterialOverrideTexture ( _                ' VTable offset = 304
     BYVAL tex AS Direct3DRMTexture3 _                  ' __in *tex Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOrientation ( _                            ' VTable offset = 308
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL dx AS SINGLE _                               ' __in dx VT_R4 <Single>
   , BYVAL dy AS SINGLE _                               ' __in dy VT_R4 <Single>
   , BYVAL dz AS SINGLE _                               ' __in dz VT_R4 <Single>
   , BYVAL ux AS SINGLE _                               ' __in ux VT_R4 <Single>
   , BYVAL uy AS SINGLE _                               ' __in uy VT_R4 <Single>
   , BYVAL uz AS SINGLE _                               ' __in uz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 312
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuaternion ( _                             ' VTable offset = 316
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYREF quat AS D3DRMQUATERNION _                    ' *quat D3DRMQUATERNION <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRotation ( _                               ' VTable offset = 320
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL theta AS SINGLE _                            ' __in theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackground ( _                        ' VTable offset = 324
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackgroundDepth ( _                   ' VTable offset = 328
     BYVAL s AS DirectDrawSurface7 _                    ' __in *s DirectDrawSurface7 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackgroundImage ( _                   ' VTable offset = 332
     BYVAL i AS Direct3DRMTexture3 _                    ' __in *i Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackgroundRGB ( _                     ' VTable offset = 336
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogColor ( _                          ' VTable offset = 340
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogEnable ( _                         ' VTable offset = 344
     BYVAL bEnable AS LONG _                            ' __in bEnable CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogMethod ( _                         ' VTable offset = 348
     BYVAL method AS LONG _                             ' __in method CONST_D3DRMFOGMETHOD <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogMode ( _                           ' VTable offset = 352
     BYVAL c AS LONG _                                  ' __in c CONST_D3DRMFOGMODE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogParams ( _                         ' VTable offset = 356
     BYVAL start AS SINGLE _                            ' __in start VT_R4 <Single>
   , BYVAL end AS SINGLE _                              ' __in end VT_R4 <Single>
   , BYVAL density AS SINGLE _                          ' __in density VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSortMode ( _                               ' VTable offset = 360
     BYVAL val AS LONG _                                ' __in val CONST_D3DRMSORTMODE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 364
     BYVAL t AS Direct3DRMTexture3 _                    ' __in *t Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTraversalOptions ( _                       ' VTable offset = 368
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMTRAVERALFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 372
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL with_rotation AS LONG _                      ' __in with_rotation CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetZbufferMode ( _                            ' VTable offset = 376
     BYVAL val AS LONG _                                ' __in val CONST_D3DRMZBUFFERMODE <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFrame3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFrameMoveCallback3
' IID = {9F76FE33-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFrameMoveCallback3_INTERFACE_DEFINED)
    %Direct3DRMFrameMoveCallback3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFrameMoveCallback3 $IID_Direct3DRMFrameMoveCallback3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMFrameMove ( _                       ' VTable offset = 12
     BYVAL f AS Direct3DRMFrame3 _                      ' __in *f Direct3DRMFrame3 <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   , BYVAL delta AS SINGLE _                            ' __in delta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFrameMoveCallback3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFrameArray
' IID = {9F76FE14-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFrameArray_INTERFACE_DEFINED)
    %Direct3DRMFrameArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFrameArray $IID_Direct3DRMFrameArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMFrame3                                ' __retval_out **ppFrame Direct3DRMFrame3 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFrameArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMLightArray
' IID = {9F76FE16-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMLightArray_INTERFACE_DEFINED)
    %Direct3DRMLightArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMLightArray $IID_Direct3DRMLightArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMLight                                 ' __retval_out **retV Direct3DRMLight <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMLightArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMVisualArray
' IID = {9F76FE15-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMVisualArray_INTERFACE_DEFINED)
    %Direct3DRMVisualArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMVisualArray $IID_Direct3DRMVisualArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMVisual                                ' __retval_out **retV Direct3DRMVisual <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMVisualArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMPick2Array
' IID = {9F76FE19-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMPick2Array_INTERFACE_DEFINED)
    %Direct3DRMPick2Array_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMPick2Array $IID_Direct3DRMPick2Array

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPickVisual ( _                             ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF pickDesc AS D3DRMPICKDESC2 _                 ' __in *pickDesc D3DRMPICKDESC2 <record>
   ) AS Direct3DRMVisual                                ' __retval_out **visual Direct3DRMVisual <interface>
   ' =====================================================================================
   METHOD GetPickFrame ( _                              ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF pickDesc AS D3DRMPICKDESC2 _                 ' __in *pickDesc D3DRMPICKDESC2 <record>
   ) AS Direct3DRMFrameArray                            ' __retval_out **frameArray Direct3DRMFrameArray <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMPick2Array_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMMesh
' IID = {9F76FE06-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMMesh_INTERFACE_DEFINED)
    %Direct3DRMMesh_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMMesh $IID_Direct3DRMMesh

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetGroupColor ( _                             ' VTable offset = 52
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupColorRGB ( _                          ' VTable offset = 56
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupMapping ( _                           ' VTable offset = 60
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL value AS LONG _                              ' __in value CONST_D3DRMMAPPINGFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupQuality ( _                           ' VTable offset = 64
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL value AS LONG _                              ' __in value CONST_D3DRMRENDERQUALITY <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupMaterial ( _                          ' VTable offset = 68
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL val AS Direct3DRMMaterial2 _                 ' __in *val Direct3DRMMaterial2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupTexture ( _                           ' VTable offset = 72
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL val AS Direct3DRMTexture3 _                  ' __in *val Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGroupCount ( _                             ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGroupColor ( _                             ' VTable offset = 80
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGroupMapping ( _                           ' VTable offset = 84
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMMAPPINGFLAGS <enum>
   ' =====================================================================================
   METHOD GetGroupQuality ( _                           ' VTable offset = 88
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMRENDERQUALITY <enum>
   ' =====================================================================================
   METHOD GetGroupMaterial ( _                          ' VTable offset = 92
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS Direct3DRMMaterial2                             ' __retval_out **retV Direct3DRMMaterial2 <interface>
   ' =====================================================================================
   METHOD GetGroupTexture ( _                           ' VTable offset = 96
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS Direct3DRMTexture3                              ' __retval_out **retV Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD ScaleMesh ( _                                 ' VTable offset = 100
     BYVAL sx AS SINGLE _                               ' __in sx VT_R4 <Single>
   , BYVAL sy AS SINGLE _                               ' __in sy VT_R4 <Single>
   , BYVAL sz AS SINGLE _                               ' __in sz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 104
     BYVAL tx AS SINGLE _                               ' __in tx VT_R4 <Single>
   , BYVAL ty AS SINGLE _                               ' __in ty VT_R4 <Single>
   , BYVAL tz AS SINGLE _                               ' __in tz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBox ( _                                    ' VTable offset = 108
     BYREF vector AS D3DRMBOX _                         ' __in *vector D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSizes ( _                                  ' VTable offset = 112
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYREF cnt1 AS LONG _                               ' __out *cnt1 VT_I4 <Long>
   , BYREF cnt2 AS LONG _                               ' __out *cnt2 VT_I4 <Long>
   , BYREF cnt3 AS LONG _                               ' __out *cnt3 VT_I4 <Long>
   , BYREF cnt4 AS LONG _                               ' __out *cnt4 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertex ( _                                 ' VTable offset = 116
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYREF values AS D3DRMVERTEX _                      ' __in *values D3DRMVERTEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertex ( _                                 ' VTable offset = 120
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYREF ret AS D3DRMVERTEX _                         ' __inout *ret D3DRMVERTEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertexCount ( _                            ' VTable offset = 124
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *cnt VT_I4 <Long>
   ' =====================================================================================
   METHOD AddGroup ( _                                  ' VTable offset = 128
     BYVAL VertexCount AS LONG _                        ' __in VertexCount VT_I4 <Long>
   , BYVAL faceCount AS LONG _                          ' __in faceCount VT_I4 <Long>
   , BYVAL verticesPerFace AS LONG _                    ' __in verticesPerFace VT_I4 <Long>
   , BYREF fdata AS DWORD _                             ' __in **fdata VT_SAFEARRAY
   ) AS LONG                                            ' __retval_out *retId VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGroupData ( _                              ' VTable offset = 132
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYREF psa AS DWORD _                               ' __inout **psa VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGroupDataSize ( _                          ' VTable offset = 136
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retval VT_I4 <Long>
   ' =====================================================================================
   METHOD SetVertices ( _                               ' VTable offset = 140
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF vertexArray AS DWORD _                       ' __in **vertexArray VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertices ( _                               ' VTable offset = 144
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL count AS LONG _                              ' count VT_I4 <Long>
   , BYREF vertexArray AS DWORD _                       ' __inout **vertexArray VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD AddGroupJava ( _                              ' VTable offset = 148
     BYVAL vcnt AS LONG _                               ' __in vcnt VT_I4 <Long>
   , BYVAL fcnt AS LONG _                               ' __in fcnt VT_I4 <Long>
   , BYVAL vPerFace AS LONG _                           ' __in vPerFace VT_I4 <Long>
   , BYREF fdata AS LONG _                              ' __inout *fdata VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retId VT_I4 <Long>
   ' =====================================================================================
   METHOD GetGroupDataJava ( _                          ' VTable offset = 152
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYREF fdata AS LONG _                              ' __inout *fdata VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVerticesJava ( _                           ' VTable offset = 156
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL cnt AS LONG _                                ' __in cnt VT_I4 <Long>
   , BYREF vertexArray AS SINGLE _                      ' __inout *vertexArray VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVerticesJava ( _                           ' VTable offset = 160
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL cnt AS LONG _                                ' cnt VT_I4 <Long>
   , BYREF vertexArray AS SINGLE _                      ' __inout *vertexArray VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMMesh_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMWrap
' IID = {9F76FE08-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMWrap_INTERFACE_DEFINED)
    %Direct3DRMWrap_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMWrap $IID_Direct3DRMWrap

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD Apply ( _                                     ' VTable offset = 52
     BYVAL visual AS Direct3DRMObject _                 ' __in *visual Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD ApplyRelative ( _                             ' VTable offset = 56
     BYVAL f AS Direct3DRMFrame3 _                      ' __in *f Direct3DRMFrame3 <interface>
   , BYVAL visual AS Direct3DRMObject _                 ' __in *visual Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMWrap_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMObjectArray
' IID = {9F76FE11-8E92-11D1-8808-00C04FC2C602}
' Direct3DRMObjectArray Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMObjectArray_INTERFACE_DEFINED)
    %Direct3DRMObjectArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMObjectArray $IID_Direct3DRMObjectArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMObjectArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMDeviceArray
' IID = {9F76FE12-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMDeviceArray_INTERFACE_DEFINED)
    %Direct3DRMDeviceArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMDeviceArray $IID_Direct3DRMDeviceArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMDevice3                               ' __retval_out **lplpD3DRMDevice Direct3DRMDevice3 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMDeviceArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMDevice3
' IID = {9F76FE27-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMDevice3_INTERFACE_DEFINED)
    %Direct3DRMDevice3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMDevice3 $IID_Direct3DRMDevice3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddUpdateCallback ( _                         ' VTable offset = 52
     BYVAL updateCallbackImplementation AS Direct3DRMDeviceUpdateCallback3 _ ' __in *updateCallbackImplementation Direct3DRMDeviceUpdateCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteUpdateCallback ( _                      ' VTable offset = 56
     BYVAL updateCallbackImplementation AS Direct3DRMDeviceUpdateCallback3 _ ' __in *updateCallbackImplementation Direct3DRMDeviceUpdateCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPreferredTextureFormat ( _                ' VTable offset = 60
     BYVAL bitDepth AS LONG _                           ' __in bitDepth CONST_DDBITDEPTHFLAGS <enum>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMFPTFFLAGS <enum>
   , BYREF ddpf AS DDPIXELFORMAT _                      ' __inout *ddpf DDPIXELFORMAT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBufferCount ( _                            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetColorModel ( _                             ' VTable offset = 68
   ) AS LONG                                            ' __retval_out *retV CONST_D3DCOLORMODEL <enum>
   ' =====================================================================================
   METHOD GetDither ( _                                 ' VTable offset = 72
   ) AS LONG                                            ' __retval_out *ditherEnabled CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *w VT_INT <Long>
   ' =====================================================================================
   METHOD GetQuality ( _                                ' VTable offset = 80
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMRENDERQUALITY <enum>
   ' =====================================================================================
   METHOD GetRenderMode ( _                             ' VTable offset = 84
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMRENDERMODEFLAGS <enum>
   ' =====================================================================================
   METHOD GetShades ( _                                 ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *numShades VT_I4 <Long>
   ' =====================================================================================
   METHOD GetTextureQuality ( _                         ' VTable offset = 92
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMTEXTUREQUALITY <enum>
   ' =====================================================================================
   METHOD GetTrianglesDrawn ( _                         ' VTable offset = 96
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetViewports ( _                              ' VTable offset = 100
   ) AS Direct3DRMViewportArray                         ' __retval_out **views Direct3DRMViewportArray <interface>
   ' =====================================================================================
   METHOD GetWireframeOptions ( _                       ' VTable offset = 104
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMWIREFRAMEFLAGS <enum>
   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out *w VT_INT <Long>
   ' =====================================================================================
   METHOD SetBufferCount ( _                            ' VTable offset = 112
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDither ( _                                 ' VTable offset = 116
     BYVAL ditherEnabled AS LONG _                      ' __in ditherEnabled CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuality ( _                                ' VTable offset = 120
     BYVAL q AS LONG _                                  ' __in q CONST_D3DRMRENDERQUALITY <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRenderMode ( _                             ' VTable offset = 124
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMRENDERMODEFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetShades ( _                                 ' VTable offset = 128
     BYVAL numShades AS LONG _                          ' __in numShades VT_INT <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureQuality ( _                         ' VTable offset = 132
     BYVAL D AS LONG _                                  ' __in D CONST_D3DRMTEXTUREQUALITY <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD HandleActivate ( _                            ' VTable offset = 140
     BYVAL wparam AS LONG _                             ' __in wparam VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD HandlePaint ( _                               ' VTable offset = 144
     BYVAL hdc AS LONG _                                ' __in hdc VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMDevice3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMDeviceUpdateCallback3
' IID = {9F76FE34-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMDeviceUpdateCallback3_INTERFACE_DEFINED)
    %Direct3DRMDeviceUpdateCallback3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMDeviceUpdateCallback3 $IID_Direct3DRMDeviceUpdateCallback3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CallbackRMUpdate ( _                          ' VTable offset = 12
     BYVAL f AS Direct3DRMDevice3 _                     ' __in *f Direct3DRMDevice3 <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   , BYVAL n AS LONG _                                  ' __in n VT_INT <Long>
   , BYREF Update AS D3DRECT _                          ' __in *Update D3DRECT <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMDeviceUpdateCallback3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMViewportArray
' IID = {9F76FE13-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMViewportArray_INTERFACE_DEFINED)
    %Direct3DRMViewportArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMViewportArray $IID_Direct3DRMViewportArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMViewport2                             ' __retval_out **lplpD3DRMViewport Direct3DRMViewport2 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMViewportArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMViewport2
' IID = {9F76FE20-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMViewport2_INTERFACE_DEFINED)
    %Direct3DRMViewport2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMViewport2 $IID_Direct3DRMViewport2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 52
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMVIEWPORTCLEARFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 56
     BYVAL rootFrame AS Direct3DRMFrame3 _              ' __in *rootFrame Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCamera ( _                                 ' VTable offset = 60
   ) AS Direct3DRMFrame3                                ' __retval_out **val Direct3DRMFrame3 <interface>
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 64
   ) AS Direct3DRMDevice3                               ' __retval_out **val Direct3DRMDevice3 <interface>
   ' =====================================================================================
   METHOD SetFront ( _                                  ' VTable offset = 68
     BYVAL v AS SINGLE _                                ' __in v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBack ( _                                   ' VTable offset = 72
     BYVAL v AS SINGLE _                                ' __in v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetField ( _                                  ' VTable offset = 76
     BYVAL v AS SINGLE _                                ' __in v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUniformScaling ( _                         ' VTable offset = 80
     BYVAL flag AS LONG _                               ' __in flag CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCamera ( _                                 ' VTable offset = 84
     BYVAL f AS Direct3DRMFrame3 _                      ' __in *f Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetProjection ( _                             ' VTable offset = 88
     BYVAL val AS LONG _                                ' __in val CONST_D3DRMPROJECTIONTYPE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Transform ( _                                 ' VTable offset = 92
     BYREF D AS D3DRMVECTOR4D _                         ' __out *D D3DRMVECTOR4D <record>
   , BYREF s AS D3DVECTOR _                             ' __in *s D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD InverseTransform ( _                          ' VTable offset = 96
     BYREF D AS D3DVECTOR _                             ' __out *D D3DVECTOR <record>
   , BYREF s AS D3DRMVECTOR4D _                         ' __in *s D3DRMVECTOR4D <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 100
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   , BYVAL width AS LONG _                              ' __in width VT_I4 <Long>
   , BYVAL height AS LONG _                             ' __in height VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD ForceUpdate ( _                               ' VTable offset = 104
     BYVAL x1 AS LONG _                                 ' __in x1 VT_I4 <Long>
   , BYVAL y1 AS LONG _                                 ' __in y1 VT_I4 <Long>
   , BYVAL x2 AS LONG _                                 ' __in x2 VT_I4 <Long>
   , BYVAL y2 AS LONG _                                 ' __in y2 VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPlane ( _                                  ' VTable offset = 108
     BYVAL Left AS SINGLE _                             ' __in Left VT_R4 <Single>
   , BYVAL Right AS SINGLE _                            ' __in Right VT_R4 <Single>
   , BYVAL Bottom AS SINGLE _                           ' __in Bottom VT_R4 <Single>
   , BYVAL Top AS SINGLE _                              ' __in Top VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlane ( _                                  ' VTable offset = 112
     BYREF l AS SINGLE _                                ' __inout *l VT_R4 <Single>
   , BYREF r AS SINGLE _                                ' __inout *r VT_R4 <Single>
   , BYREF b AS SINGLE _                                ' __inout *b VT_R4 <Single>
   , BYREF t AS SINGLE _                                ' __inout *t VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD Pick ( _                                      ' VTable offset = 116
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   ) AS Direct3DRMPickArray                             ' __retval_out **retV Direct3DRMPickArray <interface>
   ' =====================================================================================
   METHOD GetUniformScaling ( _                         ' VTable offset = 120
   ) AS LONG                                            ' __retval_out *retV CONST_DBOOLFLAGS <enum>
   ' =====================================================================================
   METHOD GetX ( _                                      ' VTable offset = 124
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetY ( _                                      ' VTable offset = 128
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *w VT_I4 <Long>
   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 136
   ) AS LONG                                            ' __retval_out *w VT_I4 <Long>
   ' =====================================================================================
   METHOD GetField ( _                                  ' VTable offset = 140
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetBack ( _                                   ' VTable offset = 144
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetFront ( _                                  ' VTable offset = 148
   ) AS SINGLE                                          ' __retval_out *retV VT_R4 <Single>
   ' =====================================================================================
   METHOD GetProjection ( _                             ' VTable offset = 152
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMPROJECTIONTYPE <enum>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMViewport2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMPickArray
' IID = {9F76FE17-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMPickArray_INTERFACE_DEFINED)
    %Direct3DRMPickArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMPickArray $IID_Direct3DRMPickArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPickVisual ( _                             ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF pickDesc AS D3DRMPICKDESC _                  ' __in *pickDesc D3DRMPICKDESC <record>
   ) AS Direct3DRMVisual                                ' __retval_out **visual Direct3DRMVisual <interface>
   ' =====================================================================================
   METHOD GetPickFrame ( _                              ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF pickDesc AS D3DRMPICKDESC _                  ' __in *pickDesc D3DRMPICKDESC <record>
   ) AS Direct3DRMFrameArray                            ' __retval_out **frameArray Direct3DRMFrameArray <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMPickArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFaceArray
' IID = {9F76FE18-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFaceArray_INTERFACE_DEFINED)
    %Direct3DRMFaceArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFaceArray $IID_Direct3DRMFaceArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 24
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMFace2                                 ' __retval_out **retV Direct3DRMFace2 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFaceArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMAnimationArray
' IID = {9F76FE35-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMAnimationArray_INTERFACE_DEFINED)
    %Direct3DRMAnimationArray_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMAnimationArray $IID_Direct3DRMAnimationArray

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS Direct3DRMAnimation2                            ' __retval_out **anim Direct3DRMAnimation2 <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMAnimationArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMAnimation2
' IID = {9F76FE22-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMAnimation2_INTERFACE_DEFINED)
    %Direct3DRMAnimation2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMAnimation2 $IID_Direct3DRMAnimation2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 52
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMANIMATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRotateKey ( _                              ' VTable offset = 56
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   , BYREF q AS D3DRMQUATERNION _                       ' __in *q D3DRMQUATERNION <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPositionKey ( _                            ' VTable offset = 60
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddScaleKey ( _                               ' VTable offset = 64
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 68
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFrame ( _                                  ' VTable offset = 72
     BYVAL frame AS Direct3DRMFrame3 _                  ' __in *frame Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFrame ( _                                  ' VTable offset = 76
   ) AS Direct3DRMFrame3                                ' __retval_out **frame Direct3DRMFrame3 <interface>
   ' =====================================================================================
   METHOD SetTime ( _                                   ' VTable offset = 80
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 84
   ) AS LONG                                            ' __retval_out *options CONST_D3DRMANIMATIONFLAGS <enum>
   ' =====================================================================================
   METHOD AddKey ( _                                    ' VTable offset = 88
     BYREF key AS D3DRMANIMATIONKEY _                   ' __in *key D3DRMANIMATIONKEY <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteKeyById ( _                             ' VTable offset = 92
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetKeys ( _                                   ' VTable offset = 96
     BYVAL timeMin AS SINGLE _                          ' __in timeMin VT_R4 <Single>
   , BYVAL timeMax AS SINGLE _                          ' __in timeMax VT_R4 <Single>
   , BYREF keyArray AS DWORD _                          ' __inout **keyArray VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetKeysCount ( _                              ' VTable offset = 100
     BYVAL timeMin AS SINGLE _                          ' __in timeMin VT_R4 <Single>
   , BYVAL timeMax AS SINGLE _                          ' __in timeMax VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD ModifyKey ( _                                 ' VTable offset = 104
     BYREF key AS D3DRMANIMATIONKEY _                   ' __in *key D3DRMANIMATIONKEY <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMAnimation2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMShadow2
' IID = {9F76FE36-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMShadow2_INTERFACE_DEFINED)
    %Direct3DRMShadow2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMShadow2 $IID_Direct3DRMShadow2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 52
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMSHADOWFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMShadow2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMAnimationSet2
' IID = {9F76FE23-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMAnimationSet2_INTERFACE_DEFINED)
    %Direct3DRMAnimationSet2_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMAnimationSet2 $IID_Direct3DRMAnimationSet2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddAnimation ( _                              ' VTable offset = 52
     BYVAL aid AS Direct3DRMAnimation2 _                ' __in *aid Direct3DRMAnimation2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAnimation ( _                           ' VTable offset = 56
     BYVAL aid AS Direct3DRMAnimation2 _                ' __in *aid Direct3DRMAnimation2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAnimations ( _                             ' VTable offset = 60
   ) AS Direct3DRMAnimationArray                        ' __retval_out **ret Direct3DRMAnimationArray <interface>
   ' =====================================================================================
   METHOD LoadFromFile ( _                              ' VTable offset = 64
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   , BYVAL id AS VARIANT _                              ' __in id VT_VARIANT <Variant>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMLOADFLAGS <enum>
   , BYVAL loadTextureImplementation AS Direct3DRMLoadTextureCallback3 _ ' __in *loadTextureImplementation Direct3DRMLoadTextureCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   , BYVAL parentFrame AS Direct3DRMFrame3 _            ' __in *parentFrame Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime ( _                                   ' VTable offset = 68
     BYVAL time AS SINGLE _                             ' __in time VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMAnimationSet2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRM3
' IID = {9F76FE24-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRM3_INTERFACE_DEFINED)
    %Direct3DRM3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRM3 $IID_Direct3DRM3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateDeviceFromClipper ( _                   ' VTable offset = 20
     BYVAL lpDDClipper AS DirectDrawClipper _           ' __in *lpDDClipper DirectDrawClipper <interface>
   , BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL width AS LONG _                              ' __in width VT_INT <Long>
   , BYVAL height AS LONG _                             ' __in height VT_INT <Long>
   ) AS Direct3DRMDevice3                               ' __retval_out **retV Direct3DRMDevice3 <interface>
   ' =====================================================================================
   METHOD CreateFrame ( _                               ' VTable offset = 24
     BYVAL parent AS Direct3DRMFrame3 _                 ' __in *parent Direct3DRMFrame3 <interface>
   ) AS Direct3DRMFrame3                                ' __retval_out **retV Direct3DRMFrame3 <interface>
   ' =====================================================================================
   METHOD CreateLightRGB ( _                            ' VTable offset = 28
     BYVAL lt AS LONG _                                 ' __in lt CONST_D3DRMLIGHTTYPE <enum>
   , BYVAL vred AS SINGLE _                             ' __in vred VT_R4 <Single>
   , BYVAL vgreen AS SINGLE _                           ' __in vgreen VT_R4 <Single>
   , BYVAL vblue AS SINGLE _                            ' __in vblue VT_R4 <Single>
   ) AS Direct3DRMLight                                 ' __retval_out **retV Direct3DRMLight <interface>
   ' =====================================================================================
   METHOD CreateLight ( _                               ' VTable offset = 32
     BYVAL lt AS LONG _                                 ' __in lt CONST_D3DRMLIGHTTYPE <enum>
   , BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   ) AS Direct3DRMLight                                 ' __retval_out **retV Direct3DRMLight <interface>
   ' =====================================================================================
   METHOD CreateMeshBuilder ( _                         ' VTable offset = 36
   ) AS Direct3DRMMeshBuilder3                          ' __retval_out **retV Direct3DRMMeshBuilder3 <interface>
   ' =====================================================================================
   METHOD CreateMaterial ( _                            ' VTable offset = 40
     BYVAL D AS SINGLE _                                ' __in D VT_R4 <Single>
   ) AS Direct3DRMMaterial2                             ' __retval_out **val Direct3DRMMaterial2 <interface>
   ' =====================================================================================
   METHOD LoadTexture ( _                               ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   ) AS Direct3DRMTexture3                              ' __retval_out **retval Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD CreateViewport ( _                            ' VTable offset = 48
     BYVAL dev AS Direct3DRMDevice3 _                   ' __in *dev Direct3DRMDevice3 <interface>
   , BYVAL fr AS Direct3DRMFrame3 _                     ' __in *fr Direct3DRMFrame3 <interface>
   , BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   , BYVAL w AS LONG _                                  ' __in w VT_I4 <Long>
   , BYVAL h AS LONG _                                  ' __in h VT_I4 <Long>
   ) AS Direct3DRMViewport2                             ' __retval_out **retval Direct3DRMViewport2 <interface>
   ' =====================================================================================
   METHOD SetDefaultTextureColors ( _                   ' VTable offset = 52
     BYVAL numTextureColors AS LONG _                   ' __in numTextureColors VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultTextureShades ( _                   ' VTable offset = 56
     BYVAL numTextureShades AS LONG _                   ' __in numTextureShades VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateAnimationSet ( _                        ' VTable offset = 60
   ) AS Direct3DRMAnimationSet2                         ' __retval_out **retval Direct3DRMAnimationSet2 <interface>
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 64
   ) AS Direct3DRMMesh                                  ' __retval_out **retV Direct3DRMMesh <interface>
   ' =====================================================================================
   METHOD CreateFace ( _                                ' VTable offset = 68
   ) AS Direct3DRMFace2                                 ' __retval_out **retV Direct3DRMFace2 <interface>
   ' =====================================================================================
   METHOD CreateAnimation ( _                           ' VTable offset = 72
   ) AS Direct3DRMAnimation2                            ' __retval_out **retV Direct3DRMAnimation2 <interface>
   ' =====================================================================================
   METHOD Tick ( _                                      ' VTable offset = 76
     BYVAL tic AS SINGLE _                              ' __in tic VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDeviceFromSurface ( _                   ' VTable offset = 80
     BYVAL g AS WSTRING _                               ' __in g VT_BSTR
   , BYVAL dd AS DirectDraw4 _                          ' __in *dd DirectDraw4 <interface>
   , BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMCREATEDEVICEFLAGS <enum>
   ) AS Direct3DRMDevice3                               ' __retval_out **retval Direct3DRMDevice3 <interface>
   ' =====================================================================================
   METHOD CreateTextureFromSurface ( _                  ' VTable offset = 84
     BYVAL ddS AS DirectDrawSurface4 _                  ' __in *ddS DirectDrawSurface4 <interface>
   ) AS Direct3DRMTexture3                              ' __retval_out **retV Direct3DRMTexture3 <interface>
   ' =====================================================================================
   METHOD CreateWrap ( _                                ' VTable offset = 88
     BYVAL t AS LONG _                                  ' __in t CONST_D3DRMWRAPTYPE <enum>
   , BYVAL f AS Direct3DRMFrame3 _                      ' __in *f Direct3DRMFrame3 <interface>
   , BYVAL ox AS SINGLE _                               ' __in ox VT_R4 <Single>
   , BYVAL oy AS SINGLE _                               ' __in oy VT_R4 <Single>
   , BYVAL oz AS SINGLE _                               ' __in oz VT_R4 <Single>
   , BYVAL dx AS SINGLE _                               ' __in dx VT_R4 <Single>
   , BYVAL dy AS SINGLE _                               ' __in dy VT_R4 <Single>
   , BYVAL dz AS SINGLE _                               ' __in dz VT_R4 <Single>
   , BYVAL ux AS SINGLE _                               ' __in ux VT_R4 <Single>
   , BYVAL uy AS SINGLE _                               ' __in uy VT_R4 <Single>
   , BYVAL uz AS SINGLE _                               ' __in uz VT_R4 <Single>
   , BYVAL ou AS SINGLE _                               ' __in ou VT_R4 <Single>
   , BYVAL ov AS SINGLE _                               ' __in ov VT_R4 <Single>
   , BYVAL su AS SINGLE _                               ' __in su VT_R4 <Single>
   , BYVAL sv AS SINGLE _                               ' __in sv VT_R4 <Single>
   ) AS Direct3DRMWrap                                  ' __retval_out **retV Direct3DRMWrap <interface>
   ' =====================================================================================
   METHOD GetSearchPath ( _                             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetDevices ( _                                ' VTable offset = 96
   ) AS Direct3DRMDeviceArray                           ' __retval_out **retval Direct3DRMDeviceArray <interface>
   ' =====================================================================================
   METHOD GetNamedObject ( _                            ' VTable offset = 100
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   ) AS Direct3DRMObject                                ' __retval_out **retval Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetSearchPath ( _                             ' VTable offset = 104
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSearchPath ( _                             ' VTable offset = 108
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateObjects ( _                          ' VTable offset = 112
     BYVAL enumerateObjectsImplementation AS Direct3DRMEnumerateObjectsCallback _ ' __in *enumerateObjectsImplementation Direct3DRMEnumerateObjectsCallback <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadFromFile ( _                              ' VTable offset = 116
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   , BYVAL id AS VARIANT _                              ' __in id VT_VARIANT <Variant>
   , BYREF guidArray AS DWORD _                         ' __in **guidArray VT_SAFEARRAY
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMLOADFLAGS <enum>
   , BYVAL loadCallbackImplementation AS Direct3DRMLoadCallback _ ' __in *loadCallbackImplementation Direct3DRMLoadCallback <interface>
   , BYVAL loadArgument AS IDispatch _                  ' __in *loadArgument VT_DISPATCH <IDispatch>
   , BYVAL loadTextureImplementation AS Direct3DRMLoadTextureCallback3 _ ' __in *loadTextureImplementation Direct3DRMLoadTextureCallback3 <interface>
   , BYVAL loadTextureArgument AS IDispatch _           ' __in *loadTextureArgument VT_DISPATCH <IDispatch>
   , BYVAL parentFrame AS Direct3DRMFrame3 _            ' __in *parentFrame Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateShadow ( _                              ' VTable offset = 120
     BYVAL visual AS Direct3DRMVisual _                 ' __in *visual Direct3DRMVisual <interface>
   , BYVAL Light AS Direct3DRMLight _                   ' __in *Light Direct3DRMLight <interface>
   , BYVAL px AS SINGLE _                               ' __in px VT_R4 <Single>
   , BYVAL py AS SINGLE _                               ' __in py VT_R4 <Single>
   , BYVAL pz AS SINGLE _                               ' __in pz VT_R4 <Single>
   , BYVAL nx AS SINGLE _                               ' __in nx VT_R4 <Single>
   , BYVAL ny AS SINGLE _                               ' __in ny VT_R4 <Single>
   , BYVAL nz AS SINGLE _                               ' __in nz VT_R4 <Single>
   ) AS Direct3DRMShadow2                               ' __retval_out **retV Direct3DRMShadow2 <interface>
   ' =====================================================================================
   METHOD CreateProgressiveMesh ( _                     ' VTable offset = 124
   ) AS Direct3DRMProgressiveMesh                       ' __retval_out **retV Direct3DRMProgressiveMesh <interface>
   ' =====================================================================================
   METHOD CreateClippedVisual ( _                       ' VTable offset = 128
     BYVAL vis AS Direct3DRMVisual _                    ' __in *vis Direct3DRMVisual <interface>
   ) AS Direct3DRMClippedVisual                         ' __retval_out **ret Direct3DRMClippedVisual <interface>
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *options CONST_D3DRMHANDEDNESS <enum>
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 136
     BYVAL options AS LONG _                            ' __in options CONST_D3DRMHANDEDNESS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateInterpolatorMesh ( _                    ' VTable offset = 140
   ) AS Direct3DRMMeshInterpolator                      ' __retval_out **ret Direct3DRMMeshInterpolator <interface>
   ' =====================================================================================
   METHOD CreateInterpolatorTexture ( _                 ' VTable offset = 144
   ) AS Direct3DRMTextureInterpolator                   ' __retval_out **ret Direct3DRMTextureInterpolator <interface>
   ' =====================================================================================
   METHOD CreateInterpolatorMaterial ( _                ' VTable offset = 148
   ) AS Direct3DRMMaterialInterpolator                  ' __retval_out **ret Direct3DRMMaterialInterpolator <interface>
   ' =====================================================================================
   METHOD CreateInterpolatorFrame ( _                   ' VTable offset = 152
   ) AS Direct3DRMFrameInterpolator                     ' __retval_out **ret Direct3DRMFrameInterpolator <interface>
   ' =====================================================================================
   METHOD CreateInterpolatorViewport ( _                ' VTable offset = 156
   ) AS Direct3DRMViewportInterpolator                  ' __retval_out **ret Direct3DRMViewportInterpolator <interface>
   ' =====================================================================================
   METHOD CreateInterpolatorLight ( _                   ' VTable offset = 160
   ) AS Direct3DRMLightInterpolator                     ' __retval_out **ret Direct3DRMLightInterpolator <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRM3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMMeshBuilder3
' IID = {9F76FE26-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMMeshBuilder3_INTERFACE_DEFINED)
    %Direct3DRMMeshBuilder3_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMMeshBuilder3 $IID_Direct3DRMMeshBuilder3

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddFace ( _                                   ' VTable offset = 52
     BYVAL f AS Direct3DRMFace2 _                       ' __in *f Direct3DRMFace2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFaces ( _                                  ' VTable offset = 56
     BYVAL vc AS LONG _                                 ' __in vc VT_I4 <Long>
   , BYREF verexArray AS DWORD _                        ' __in **verexArray VT_SAFEARRAY
   , BYVAL nc AS LONG _                                 ' __in nc VT_I4 <Long>
   , BYREF normalArray AS DWORD _                       ' __in **normalArray VT_SAFEARRAY
   , BYREF data AS DWORD _                              ' __in **data VT_SAFEARRAY
   ) AS Direct3DRMFaceArray                             ' __retval_out **array Direct3DRMFaceArray <interface>
   ' =====================================================================================
   METHOD AddFacesIndexed ( _                           ' VTable offset = 60
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMADDFACESFLAGS <enum>
   , BYREF indexArray AS DWORD _                        ' __in **indexArray VT_SAFEARRAY
   ) AS LONG                                            ' __retval_out *newFaceIndex VT_I4 <Long>
   ' =====================================================================================
   METHOD AddFrame ( _                                  ' VTable offset = 64
     BYVAL frame AS Direct3DRMFrame3 _                  ' __in *frame Direct3DRMFrame3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMesh ( _                                   ' VTable offset = 68
     BYVAL mesh AS Direct3DRMMesh _                     ' __in *mesh Direct3DRMMesh <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMeshBuilder ( _                            ' VTable offset = 72
     BYVAL meshbuilder AS Direct3DRMMeshBuilder3 _      ' __in *meshbuilder Direct3DRMMeshBuilder3 <interface>
   , BYVAL flags AS LONG _                              ' flags CONST_D3DRMADDMESHBUILDERFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNormal ( _                                 ' VTable offset = 76
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *index VT_INT <Long>
   ' =====================================================================================
   METHOD AddTriangles ( _                              ' VTable offset = 80
     BYVAL format AS LONG _                             ' __in format CONST_D3DRMADDTRIANGLESVT <enum>
   , BYVAL VertexCount AS LONG _                        ' __in VertexCount VT_I4 <Long>
   , BYVAL data AS DWORD _                              ' __in *data VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddVertex ( _                                 ' VTable offset = 84
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *index VT_INT <Long>
   ' =====================================================================================
   METHOD CreateFace ( _                                ' VTable offset = 88
   ) AS Direct3DRMFace2                                 ' __retval_out **retV Direct3DRMFace2 <interface>
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 92
   ) AS Direct3DRMMesh                                  ' __retval_out **retV Direct3DRMMesh <interface>
   ' =====================================================================================
   METHOD CreateSubMesh ( _                             ' VTable offset = 96
   ) AS Direct3DRMMeshBuilder3                          ' __retval_out **retV Direct3DRMMeshBuilder3 <interface>
   ' =====================================================================================
   METHOD DeleteFace ( _                                ' VTable offset = 100
     BYVAL face AS Direct3DRMFace2 _                    ' __in *face Direct3DRMFace2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNormals ( _                             ' VTable offset = 104
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteSubMesh ( _                             ' VTable offset = 108
     BYVAL mesh AS Direct3DRMMeshBuilder3 _             ' __in *mesh Direct3DRMMeshBuilder3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteVertices ( _                            ' VTable offset = 112
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Empty ( _                                     ' VTable offset = 116
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableMesh ( _                                ' VTable offset = 120
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMADDMESHBUILDERFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateNormals ( _                           ' VTable offset = 124
     BYVAL angle AS SINGLE _                            ' angle VT_R4 <Single>
   , BYVAL flags AS LONG _                              ' flags CONST_D3DRMGENERATENORMALSFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBox ( _                                    ' VTable offset = 128
     BYREF retV AS D3DRMBOX _                           ' __inout *retV D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColorSource ( _                            ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *data CONST_D3DRMCOLORSOURCE <enum>
   ' =====================================================================================
   METHOD GetEnable ( _                                 ' VTable offset = 136
   ) AS LONG                                            ' __retval_out *flags CONST_D3DRMADDMESHBUILDERFLAGS <enum>
   ' =====================================================================================
   METHOD GetFace ( _                                   ' VTable offset = 140
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   ) AS Direct3DRMFace2                                 ' __retval_out **retV Direct3DRMFace2 <interface>
   ' =====================================================================================
   METHOD GetFaceCount ( _                              ' VTable offset = 144
   ) AS LONG                                            ' __retval_out *retV VT_INT <Long>
   ' =====================================================================================
   METHOD GetFaces ( _                                  ' VTable offset = 148
   ) AS Direct3DRMFaceArray                             ' __retval_out **retV Direct3DRMFaceArray <interface>
   ' =====================================================================================
   METHOD GetGeometry ( _                               ' VTable offset = 152
     BYREF verexArray AS DWORD _                        ' __inout **verexArray VT_SAFEARRAY
   , BYREF normalArray AS DWORD _                       ' __inout **normalArray VT_SAFEARRAY
   , BYREF faceData AS DWORD _                          ' __inout **faceData VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNormal ( _                                 ' VTable offset = 156
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF desc AS D3DVECTOR _                          ' __inout *desc D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNormalCount ( _                            ' VTable offset = 160
   ) AS LONG                                            ' __retval_out *normalCount VT_I4 <Long>
   ' =====================================================================================
   METHOD GetParentMesh ( _                             ' VTable offset = 164
     BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMPARENTINGFLAGS <enum>
   ) AS Direct3DRMMeshBuilder3                          ' __retval_out **vis Direct3DRMMeshBuilder3 <interface>
   ' =====================================================================================
   METHOD GetPerspective ( _                            ' VTable offset = 168
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetQuality ( _                                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out *retV CONST_D3DRMRENDERQUALITY <enum>
   ' =====================================================================================
   METHOD GetSubMeshes ( _                              ' VTable offset = 176
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF arrayOfMeshBuilders AS DWORD _               ' __inout **arrayOfMeshBuilders VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubMeshCount ( _                           ' VTable offset = 180
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetTextureCoordinates ( _                     ' VTable offset = 184
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYREF u AS SINGLE _                                ' __inout *u VT_R4 <Single>
   , BYREF v AS SINGLE _                                ' __inout *v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertex ( _                                 ' VTable offset = 188
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYREF vec AS D3DVECTOR _                           ' __inout *vec D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertexColor ( _                            ' VTable offset = 192
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD GetVertexCount ( _                            ' VTable offset = 196
   ) AS LONG                                            ' __retval_out *retV VT_INT <Long>
   ' =====================================================================================
   METHOD GetFaceDataSize ( _                           ' VTable offset = 200
   ) AS LONG                                            ' __retval_out *faceCount VT_I4 <Long>
   ' =====================================================================================
   METHOD LoadFromFile ( _                              ' VTable offset = 204
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   , BYVAL id AS VARIANT _                              ' __in id VT_VARIANT <Variant>
   , BYVAL flags AS LONG _                              ' __in flags CONST_D3DRMLOADFLAGS <enum>
   , BYVAL loadTextureImplementation AS Direct3DRMLoadTextureCallback3 _ ' __in *loadTextureImplementation Direct3DRMLoadTextureCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 212
     BYVAL fname AS WSTRING _                           ' __in fname VT_BSTR
   , BYVAL xFormat AS LONG _                            ' __in xFormat CONST_D3DRMXOFFORMAT <enum>
   , BYVAL Save AS LONG _                               ' __in Save CONST_D3DRMSAVEFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD ScaleMesh ( _                                 ' VTable offset = 216
     BYVAL sx AS SINGLE _                               ' __in sx VT_R4 <Single>
   , BYVAL sy AS SINGLE _                               ' __in sy VT_R4 <Single>
   , BYVAL sz AS SINGLE _                               ' __in sz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 220
     BYVAL col AS LONG _                                ' __in col VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 224
     BYVAL red AS SINGLE _                              ' __in red VT_R4 <Single>
   , BYVAL green AS SINGLE _                            ' __in green VT_R4 <Single>
   , BYVAL blue AS SINGLE _                             ' __in blue VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorSource ( _                            ' VTable offset = 228
     BYVAL val AS LONG _                                ' __in val CONST_D3DRMCOLORSOURCE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 232
     BYVAL mat AS Direct3DRMMaterial2 _                 ' __in *mat Direct3DRMMaterial2 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNormal ( _                                 ' VTable offset = 236
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPerspective ( _                            ' VTable offset = 240
     BYVAL perspectiveEnabled AS LONG _                 ' __in perspectiveEnabled CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuality ( _                                ' VTable offset = 244
     BYVAL q AS LONG _                                  ' __in q CONST_D3DRMRENDERQUALITY <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 248
     BYVAL tex AS Direct3DRMTexture3 _                  ' __in *tex Direct3DRMTexture3 <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureCoordinates ( _                     ' VTable offset = 252
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL u AS SINGLE _                                ' __in u VT_R4 <Single>
   , BYVAL v AS SINGLE _                                ' __in v VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextureTopology ( _                        ' VTable offset = 256
     BYVAL wrap_u AS LONG _                             ' __in wrap_u CONST_DBOOLFLAGS <enum>
   , BYVAL wrap_v AS LONG _                             ' __in wrap_v CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertex ( _                                 ' VTable offset = 260
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertexColor ( _                            ' VTable offset = 264
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertexColorRGB ( _                         ' VTable offset = 268
     BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 272
     BYVAL tx AS SINGLE _                               ' __in tx VT_R4 <Single>
   , BYVAL ty AS SINGLE _                               ' __in ty VT_R4 <Single>
   , BYVAL tz AS SINGLE _                               ' __in tz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFacesJava ( _                              ' VTable offset = 276
     BYVAL vc AS LONG _                                 ' __in vc VT_I4 <Long>
   , BYREF ver AS SINGLE _                              ' __in *ver VT_R4 <Single>
   , BYVAL nc AS LONG _                                 ' __in nc VT_I4 <Long>
   , BYREF norm AS SINGLE _                             ' __in *norm VT_R4 <Single>
   , BYREF data AS LONG _                               ' __in *data VT_I4 <Long>
   ) AS Direct3DRMFaceArray                             ' __retval_out **array Direct3DRMFaceArray <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMMeshBuilder3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMProgressiveMesh
' IID = {9F76FE31-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMProgressiveMesh_INTERFACE_DEFINED)
    %Direct3DRMProgressiveMesh_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMProgressiveMesh $IID_Direct3DRMProgressiveMesh

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD LoadFromFile ( _                              ' VTable offset = 52
     BYVAL sFile AS WSTRING _                           ' __in sFile VT_BSTR
   , BYVAL id AS VARIANT _                              ' __in id VT_VARIANT <Variant>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMLOADFLAGS <enum>
   , BYVAL loadTextureImplementation AS Direct3DRMLoadTextureCallback3 _ ' __in *loadTextureImplementation Direct3DRMLoadTextureCallback3 <interface>
   , BYVAL userArgument AS IDispatch _                  ' __in *userArgument VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLoadStatus ( _                             ' VTable offset = 56
     BYREF loadStatus AS D3DRMPMESHLOADSTATUS _         ' __inout *loadStatus D3DRMPMESHLOADSTATUS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMinRenderDetail ( _                        ' VTable offset = 60
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFaceDetail ( _                             ' VTable offset = 68
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetVertexDetail ( _                           ' VTable offset = 72
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD SetFaceDetail ( _                             ' VTable offset = 76
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertexDetail ( _                           ' VTable offset = 80
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFaceDetailRange ( _                        ' VTable offset = 84
     BYREF min AS LONG _                                ' __inout *min VT_I4 <Long>
   , BYREF max AS LONG _                                ' __inout *max VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVertexDetailRange ( _                      ' VTable offset = 88
     BYREF min AS LONG _                                ' __inout *min VT_I4 <Long>
   , BYREF max AS LONG _                                ' __inout *max VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDetail ( _                                 ' VTable offset = 92
   ) AS SINGLE                                          ' __retval_out *detail VT_R4 <Single>
   ' =====================================================================================
   METHOD SetDetail ( _                                 ' VTable offset = 96
     BYVAL detail AS SINGLE _                           ' __in detail VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEvents ( _                            ' VTable offset = 100
     BYVAL hEvent AS LONG _                             ' __in hEvent VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL reserved AS LONG _                           ' __in reserved VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateMesh ( _                                ' VTable offset = 104
   ) AS Direct3DRMMesh                                  ' __retval_out **mesh Direct3DRMMesh <interface>
   ' =====================================================================================
   METHOD Duplicate ( _                                 ' VTable offset = 108
   ) AS Direct3DRMProgressiveMesh                       ' __retval_out **mesh Direct3DRMProgressiveMesh <interface>
   ' =====================================================================================
   METHOD GetBox ( _                                    ' VTable offset = 112
     BYREF box AS D3DRMBOX _                            ' __inout *box D3DRMBOX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuality ( _                                ' VTable offset = 116
     BYVAL quality AS LONG _                            ' quality CONST_D3DRMRENDERQUALITY <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetQuality ( _                                ' VTable offset = 120
   ) AS LONG                                            ' __retval_out *quality CONST_D3DRMRENDERQUALITY <enum>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMProgressiveMesh_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMClippedVisual
' IID = {9F76FE30-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMClippedVisual_INTERFACE_DEFINED)
    %Direct3DRMClippedVisual_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMClippedVisual $IID_Direct3DRMClippedVisual

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AddDestroyCallback ( _                        ' VTable offset = 20
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL arg AS IDispatch _                           ' __in *arg VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDestroyCallback ( _                     ' VTable offset = 24
     BYVAL fn AS Direct3DRMCallback _                   ' __in *fn Direct3DRMCallback <interface>
   , BYVAL args AS IDispatch _                          ' __in *args VT_DISPATCH <IDispatch>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloneObject ( _                               ' VTable offset = 28
   ) AS Direct3DRMObject                                ' __retval_out **retV Direct3DRMObject <interface>
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 32
     BYVAL data AS LONG _                               ' __in data VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *data VT_I4 <Long>
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD AddPlane ( _                                  ' VTable offset = 52
     BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF point AS D3DVECTOR _                         ' __inout *point D3DVECTOR <record>
   , BYREF normal AS D3DVECTOR _                        ' __inout *normal D3DVECTOR <record>
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD DeletePlane ( _                               ' VTable offset = 56
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlane ( _                                  ' VTable offset = 60
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF point AS D3DVECTOR _                         ' __inout *point D3DVECTOR <record>
   , BYREF normal AS D3DVECTOR _                        ' __inout *normal D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlaneIds ( _                               ' VTable offset = 64
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF arrayOfIds AS DWORD _                        ' __inout **arrayOfIds VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPlaneIdsCount ( _                          ' VTable offset = 68
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD SetPlane ( _                                  ' VTable offset = 72
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL ref AS Direct3DRMFrame3 _                    ' __in *ref Direct3DRMFrame3 <interface>
   , BYREF point AS D3DVECTOR _                         ' __inout *point D3DVECTOR <record>
   , BYREF normal AS D3DVECTOR _                        ' __inout *normal D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMClippedVisual_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMMeshInterpolator
' IID = {5F4637E3-62AC-11D2-90B1-00C04FC2C602}
' Direct3DRMeshInterpolator Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMMeshInterpolator_INTERFACE_DEFINED)
    %Direct3DRMMeshInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMMeshInterpolator $IID_Direct3DRMMeshInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 44
     BYVAL tx AS SINGLE _                               ' __in tx VT_R4 <Single>
   , BYVAL ty AS SINGLE _                               ' __in ty VT_R4 <Single>
   , BYVAL tz AS SINGLE _                               ' __in tz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVertices ( _                               ' VTable offset = 48
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL idx AS LONG _                                ' __in idx VT_I4 <Long>
   , BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF vertexArray AS DWORD _                       ' __in **vertexArray VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupColor ( _                             ' VTable offset = 52
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL val AS LONG _                                ' __in val VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGroupColorRGB ( _                          ' VTable offset = 56
     BYVAL id AS LONG _                                 ' __in id VT_I4 <Long>
   , BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMMeshInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMTextureInterpolator
' IID = {5F4637E5-62AC-11D2-90B1-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMTextureInterpolator_INTERFACE_DEFINED)
    %Direct3DRMTextureInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMTextureInterpolator $IID_Direct3DRMTextureInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalOrigin ( _                            ' VTable offset = 44
     BYVAL x AS LONG _                                  ' __in x VT_I4 <Long>
   , BYVAL y AS LONG _                                  ' __in y VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalSize ( _                              ' VTable offset = 48
     BYVAL width AS SINGLE _                            ' __in width VT_R4 <Single>
   , BYVAL height AS SINGLE _                           ' __in height VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDecalTransparentColor ( _                  ' VTable offset = 52
     BYVAL tcolor AS LONG _                             ' __in tcolor VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMTextureInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMMaterialInterpolator
' IID = {5F4637E6-62AC-11D2-90B1-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMMaterialInterpolator_INTERFACE_DEFINED)
    %Direct3DRMMaterialInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMMaterialInterpolator $IID_Direct3DRMMaterialInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPower ( _                                  ' VTable offset = 44
     BYVAL power AS SINGLE _                            ' __in power VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSpecular ( _                               ' VTable offset = 48
     BYVAL red AS SINGLE _                              ' __in red VT_R4 <Single>
   , BYVAL green AS SINGLE _                            ' __in green VT_R4 <Single>
   , BYVAL blue AS SINGLE _                             ' __in blue VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEmissive ( _                               ' VTable offset = 52
     BYVAL red AS SINGLE _                              ' __in red VT_R4 <Single>
   , BYVAL green AS SINGLE _                            ' __in green VT_R4 <Single>
   , BYVAL blue AS SINGLE _                             ' __in blue VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMMaterialInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMFrameInterpolator
' IID = {5F4637E2-62AC-11D2-90B1-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMFrameInterpolator_INTERFACE_DEFINED)
    %Direct3DRMFrameInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMFrameInterpolator $IID_Direct3DRMFrameInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 44
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuaternion ( _                             ' VTable offset = 48
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYREF quat AS D3DRMQUATERNION _                    ' *quat D3DRMQUATERNION <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRotation ( _                               ' VTable offset = 52
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL theta AS SINGLE _                            ' __in theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 56
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL with_rotation AS LONG _                      ' __in with_rotation CONST_DBOOLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOrientation ( _                            ' VTable offset = 60
     BYVAL reference AS Direct3DRMFrame3 _              ' __in *reference Direct3DRMFrame3 <interface>
   , BYVAL dx AS SINGLE _                               ' __in dx VT_R4 <Single>
   , BYVAL dy AS SINGLE _                               ' __in dy VT_R4 <Single>
   , BYVAL dz AS SINGLE _                               ' __in dz VT_R4 <Single>
   , BYVAL ux AS SINGLE _                               ' __in ux VT_R4 <Single>
   , BYVAL uy AS SINGLE _                               ' __in uy VT_R4 <Single>
   , BYVAL uz AS SINGLE _                               ' __in uz VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackground ( _                        ' VTable offset = 64
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogColor ( _                          ' VTable offset = 68
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneBackgroundRGB ( _                     ' VTable offset = 72
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSceneFogParams ( _                         ' VTable offset = 76
     BYVAL start AS SINGLE _                            ' __in start VT_R4 <Single>
   , BYVAL end AS SINGLE _                              ' __in end VT_R4 <Single>
   , BYVAL density AS SINGLE _                          ' __in density VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 80
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 84
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMFrameInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMViewportInterpolator
' IID = {5F4637E1-62AC-11D2-90B1-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMViewportInterpolator_INTERFACE_DEFINED)
    %Direct3DRMViewportInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMViewportInterpolator $IID_Direct3DRMViewportInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFront ( _                                  ' VTable offset = 44
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBack ( _                                   ' VTable offset = 48
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetField ( _                                  ' VTable offset = 52
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPlane ( _                                  ' VTable offset = 56
     BYVAL Left AS SINGLE _                             ' __in Left VT_R4 <Single>
   , BYVAL Right AS SINGLE _                            ' __in Right VT_R4 <Single>
   , BYVAL Bottom AS SINGLE _                           ' __in Bottom VT_R4 <Single>
   , BYVAL Top AS SINGLE _                              ' __in Top VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMViewportInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMLightInterpolator
' IID = {5F4637E4-62AC-11D2-90B1-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMLightInterpolator_INTERFACE_DEFINED)
    %Direct3DRMLightInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMLightInterpolator $IID_Direct3DRMLightInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 44
     BYVAL c AS LONG _                                  ' __in c VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColorRGB ( _                               ' VTable offset = 48
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRange ( _                                  ' VTable offset = 52
     BYVAL rng AS SINGLE _                              ' __in rng VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUmbra ( _                                  ' VTable offset = 56
     BYVAL u AS SINGLE _                                ' __in u VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPenumbra ( _                               ' VTable offset = 60
     BYVAL p AS SINGLE _                                ' __in p VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConstantAttenuation ( _                    ' VTable offset = 64
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLinearAttenuation ( _                      ' VTable offset = 68
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetQuadraticAttenuation ( _                   ' VTable offset = 72
     BYVAL atn AS SINGLE _                              ' __in atn VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMLightInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSound
' IID = {9F76FB00-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSound_INTERFACE_DEFINED)
    %DirectSound_INTERFACE_DEFINED = 1

INTERFACE DirectSound $IID_DirectSound

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateSoundBuffer ( _                         ' VTable offset = 20
     BYREF bufferDesc AS DSBUFFERDESC _                 ' __in *bufferDesc DSBUFFERDESC <record>
   , BYREF format AS WAVEFORMATEX _                     ' __in *format WAVEFORMATEX <record>
   ) AS DirectSoundBuffer                               ' __retval_out **soundBuffer DirectSoundBuffer <interface>
   ' =====================================================================================
   METHOD CreateSoundBufferFromFile ( _                 ' VTable offset = 24
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   , BYREF bufferDesc AS DSBUFFERDESC _                 ' __inout *bufferDesc DSBUFFERDESC <record>
   , BYREF format AS WAVEFORMATEX _                     ' __out *format WAVEFORMATEX <record>
   ) AS DirectSoundBuffer                               ' __retval_out **soundBuffer DirectSoundBuffer <interface>
   ' =====================================================================================
   METHOD CreateSoundBufferFromResource ( _             ' VTable offset = 28
     BYVAL dll AS WSTRING _                             ' __in dll VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   , BYREF bufferDesc AS DSBUFFERDESC _                 ' __inout *bufferDesc DSBUFFERDESC <record>
   , BYREF format AS WAVEFORMATEX _                     ' __out *format WAVEFORMATEX <record>
   ) AS DirectSoundBuffer                               ' __retval_out **soundBuffer DirectSoundBuffer <interface>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 32
     BYREF caps AS DSCAPS _                             ' __inout *caps DSCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD DuplicateSoundBuffer ( _                      ' VTable offset = 36
     BYVAL original AS DirectSoundBuffer _              ' __in *original DirectSoundBuffer <interface>
   ) AS DirectSoundBuffer                               ' __retval_out **Duplicate DirectSoundBuffer <interface>
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 40
     BYVAL hwnd AS LONG _                               ' __in hwnd VT_I4 <Long>
   , BYVAL level AS LONG _                              ' __in level CONST_DSSCLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSpeakerConfig ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out *speakerConfig CONST_DSSPEAKERFLAGS <enum>
   ' =====================================================================================
   METHOD SetSpeakerConfig ( _                          ' VTable offset = 48
     BYVAL speakerConfig AS LONG _                      ' __in speakerConfig CONST_DSSPEAKERFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSound_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSoundBuffer
' IID = {9F76FB01-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSoundBuffer_INTERFACE_DEFINED)
    %DirectSoundBuffer_INTERFACE_DEFINED = 1

INTERFACE DirectSoundBuffer $IID_DirectSoundBuffer

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetDirectSound3DListener ( _                  ' VTable offset = 20
   ) AS DirectSound3DListener                           ' __retval_out **lpdsl DirectSound3DListener <interface>
   ' =====================================================================================
   METHOD GetDirectSound3DBuffer ( _                    ' VTable offset = 24
   ) AS DirectSound3DBuffer                             ' __retval_out **lpdsb DirectSound3DBuffer <interface>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 28
     BYREF caps AS DSBCAPS _                            ' __inout *caps DSBCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 32
     BYREF cursors AS DSCURSORS _                       ' __out *cursors DSCURSORS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 36
     BYREF format AS WAVEFORMATEX _                     ' __inout *format WAVEFORMATEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVolume ( _                                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *volume VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPan ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out *pan VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out *frequency VT_I4 <Long>
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out *status CONST_DSBSTATUSFLAGS <enum>
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 56
     BYVAL DirectSound AS DirectSound _                 ' __in *DirectSound DirectSound <interface>
   , BYREF bufferDesc AS DSBUFFERDESC _                 ' __inout *bufferDesc DSBUFFERDESC <record>
   , BYREF wbuf AS BYTE _                               ' __inout *wbuf VT_UI1 <Byte>
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBuffer ( _                               ' VTable offset = 60
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYVAL buffer AS DWORD _                            ' __in *buffer VT_VOID <Dword>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DSBLOCKFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadBuffer ( _                                ' VTable offset = 64
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYVAL buffer AS DWORD _                            ' __in *buffer VT_VOID <Dword>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DSBLOCKFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Play ( _                                      ' VTable offset = 68
     BYVAL flags AS LONG _                              ' __in flags CONST_DSBPLAYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCurrentPosition ( _                        ' VTable offset = 72
     BYVAL newPosition AS LONG _                        ' __in newPosition VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 76
     BYREF format AS WAVEFORMATEX _                     ' __in *format WAVEFORMATEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVolume ( _                                 ' VTable offset = 80
     BYVAL volume AS LONG _                             ' __in volume VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPan ( _                                    ' VTable offset = 84
     BYVAL pan AS LONG _                                ' __in pan VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFrequency ( _                              ' VTable offset = 88
     BYVAL frequency AS LONG _                          ' __in frequency VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD restore ( _                                   ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNotificationPositions ( _                  ' VTable offset = 100
     BYVAL nElements AS LONG _                          ' nElements VT_I4 <Long>
   , BYREF psa AS DWORD _                               ' **psa VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToFile ( _                                ' VTable offset = 104
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSoundBuffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSound3DListener
' IID = {9F76FB02-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSound3DListener_INTERFACE_DEFINED)
    %DirectSound3DListener_INTERFACE_DEFINED = 1

INTERFACE DirectSound3DListener $IID_DirectSound3DListener

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 20
     BYREF listener AS DS3DLISTENER _                   ' __inout *listener DS3DLISTENER <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDistanceFactor ( _                         ' VTable offset = 24
   ) AS SINGLE                                          ' __retval_out *distanceFactor VT_R4 <Single>
   ' =====================================================================================
   METHOD GetDopplerFactor ( _                          ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out *dopplerFactor VT_R4 <Single>
   ' =====================================================================================
   METHOD GetOrientation ( _                            ' VTable offset = 32
     BYREF orientFront AS D3DVECTOR _                   ' __inout *orientFront D3DVECTOR <record>
   , BYREF orientTop AS D3DVECTOR _                     ' __inout *orientTop D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 36
     BYREF position AS D3DVECTOR _                      ' __out *position D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRolloffFactor ( _                          ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out *rolloffFactor VT_R4 <Single>
   ' =====================================================================================
   METHOD GetVelocity ( _                               ' VTable offset = 44
   ) AS D3DVECTOR                                       ' __retval_out *velocity D3DVECTOR <record>
   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 48
     BYREF listener AS DS3DLISTENER _                   ' __in *listener DS3DLISTENER <record>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDistanceFactor ( _                         ' VTable offset = 52
     BYVAL distanceFactor AS SINGLE _                   ' __in distanceFactor VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDopplerFactor ( _                          ' VTable offset = 56
     BYVAL dopplerFactor AS SINGLE _                    ' __in dopplerFactor VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOrientation ( _                            ' VTable offset = 60
     BYVAL xFront AS SINGLE _                           ' __in xFront VT_R4 <Single>
   , BYVAL yFront AS SINGLE _                           ' __in yFront VT_R4 <Single>
   , BYVAL zFront AS SINGLE _                           ' __in zFront VT_R4 <Single>
   , BYVAL xTop AS SINGLE _                             ' __in xTop VT_R4 <Single>
   , BYVAL yTop AS SINGLE _                             ' __in yTop VT_R4 <Single>
   , BYVAL zTop AS SINGLE _                             ' __in zTop VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 64
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRolloffFactor ( _                          ' VTable offset = 68
     BYVAL rolloffFactor AS SINGLE _                    ' __in rolloffFactor VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 72
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitDeferredSettings ( _                    ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDirectSoundBuffer ( _                      ' VTable offset = 80
   ) AS DirectSoundBuffer                               ' __retval_out **retval DirectSoundBuffer <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSound3DListener_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSound3DBuffer
' IID = {9F76FB03-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSound3DBuffer_INTERFACE_DEFINED)
    %DirectSound3DBuffer_INTERFACE_DEFINED = 1

INTERFACE DirectSound3DBuffer $IID_DirectSound3DBuffer

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetDirectSound3DListener ( _                  ' VTable offset = 20
   ) AS DirectSound3DListener                           ' __retval_out **retval DirectSound3DListener <interface>
   ' =====================================================================================
   METHOD GetDirectSoundBuffer ( _                      ' VTable offset = 24
   ) AS DirectSoundBuffer                               ' __retval_out **retval DirectSoundBuffer <interface>
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 28
     BYREF buffer AS DS3DBUFFER _                       ' __inout *buffer DS3DBUFFER <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConeAngles ( _                             ' VTable offset = 32
     BYREF inCone AS LONG _                             ' __inout *inCone VT_I4 <Long>
   , BYREF outCone AS LONG _                            ' __inout *outCone VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConeOrientation ( _                        ' VTable offset = 36
     BYREF orientation AS D3DVECTOR _                   ' __inout *orientation D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConeOutsideVolume ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *coneOutsideVolume VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMaxDistance ( _                            ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out *maxDistance VT_R4 <Single>
   ' =====================================================================================
   METHOD GetMinDistance ( _                            ' VTable offset = 48
   ) AS SINGLE                                          ' __retval_out *minDistance VT_R4 <Single>
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out *mode CONST_DS3DMODEFLAGS <enum>
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 56
     BYREF position AS D3DVECTOR _                      ' __inout *position D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVelocity ( _                               ' VTable offset = 60
     BYREF velocity AS D3DVECTOR _                      ' __inout *velocity D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 64
     BYREF buffer AS DS3DBUFFER _                       ' __in *buffer DS3DBUFFER <record>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConeAngles ( _                             ' VTable offset = 68
     BYVAL inCone AS LONG _                             ' __in inCone VT_I4 <Long>
   , BYVAL outCone AS LONG _                            ' __in outCone VT_I4 <Long>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConeOrientation ( _                        ' VTable offset = 72
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConeOutsideVolume ( _                      ' VTable offset = 76
     BYVAL coneOutsideVolume AS LONG _                  ' __in coneOutsideVolume VT_I4 <Long>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaxDistance ( _                            ' VTable offset = 80
     BYVAL maxDistance AS SINGLE _                      ' __in maxDistance VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMinDistance ( _                            ' VTable offset = 84
     BYVAL minDistance AS SINGLE _                      ' __in minDistance VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 88
     BYVAL mode AS LONG _                               ' __in mode CONST_DS3DMODEFLAGS <enum>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 92
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 96
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL applyFlag AS LONG _                          ' __in applyFlag CONST_DS3DAPPLYFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSound3DBuffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSoundCapture
' IID = {9F76FB04-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSoundCapture_INTERFACE_DEFINED)
    %DirectSoundCapture_INTERFACE_DEFINED = 1

INTERFACE DirectSoundCapture $IID_DirectSoundCapture

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateCaptureBuffer ( _                       ' VTable offset = 20
     BYREF bufferDesc AS DSCBUFFERDESC _                ' __in *bufferDesc DSCBUFFERDESC <record>
   ) AS DirectSoundCaptureBuffer                        ' __retval_out **ret DirectSoundCaptureBuffer <interface>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 24
     BYREF caps AS DSCCAPS _                            ' __inout *caps DSCCAPS <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSoundCapture_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSoundCaptureBuffer
' IID = {9F76FB05-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSoundCaptureBuffer_INTERFACE_DEFINED)
    %DirectSoundCaptureBuffer_INTERFACE_DEFINED = 1

INTERFACE DirectSoundCaptureBuffer $IID_DirectSoundCaptureBuffer

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 20
     BYREF caps AS DSCBCAPS _                           ' __inout *caps DSCBCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 24
     BYREF cursors AS DSCURSORS _                       ' __inout *cursors DSCURSORS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 28
     BYREF waveformat AS WAVEFORMATEX _                 ' __inout *waveformat WAVEFORMATEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *status CONST_DSCBSTATUSFLAGS <enum>
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 36
     BYVAL captureBuffer AS DirectSoundCaptureBuffer _  ' __in *captureBuffer DirectSoundCaptureBuffer <interface>
   , BYREF bufferDesc AS DSCBUFFERDESC _                ' __in *bufferDesc DSCBUFFERDESC <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD start ( _                                     ' VTable offset = 40
     BYVAL flags AS LONG _                              ' __in flags CONST_DSCBSTARTFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBuffer ( _                               ' VTable offset = 48
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYVAL buffer AS DWORD _                            ' __in *buffer VT_VOID <Dword>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DSCBLOCKFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadBuffer ( _                                ' VTable offset = 52
     BYVAL start AS LONG _                              ' __in start VT_I4 <Long>
   , BYVAL size AS LONG _                               ' __in size VT_I4 <Long>
   , BYVAL buffer AS DWORD _                            ' __in *buffer VT_VOID <Dword>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DSCBLOCKFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNotificationPositions ( _                  ' VTable offset = 56
     BYVAL nElements AS LONG _                          ' nElements VT_I4 <Long>
   , BYREF psa AS DWORD _                               ' **psa VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSoundCaptureBuffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectSoundEnum
' IID = {9F76FB07-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectSoundEnum_INTERFACE_DEFINED)
    %DirectSoundEnum_INTERFACE_DEFINED = 1

INTERFACE DirectSoundEnum $IID_DirectSoundEnum

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectSoundEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInput
' IID = {9F76FA02-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInput_INTERFACE_DEFINED)
    %DirectInput_INTERFACE_DEFINED = 1

INTERFACE DirectInput $IID_DirectInput

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 20
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectInputDevice                               ' __retval_out **dev DirectInputDevice <interface>
   ' =====================================================================================
   METHOD GetDIEnumDevices ( _                          ' VTable offset = 24
     BYVAL deviceType AS LONG _                         ' __in deviceType CONST_DIDEVICETYPE <enum>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DIENUMDEVICESFLAGS <enum>
   ) AS DirectInputEnumDevices                          ' __retval_out **retval DirectInputEnumDevices <interface>
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 28
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS INTEGER                                         ' __retval_out *status VT_BOOL <Integer>
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 32
     BYVAL hwndOwner AS LONG _                          ' __in hwndOwner VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInput_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputDevice
' IID = {9F76FA03-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputDevice_INTERFACE_DEFINED)
    %DirectInputDevice_INTERFACE_DEFINED = 1

INTERFACE DirectInputDevice $IID_DirectInputDevice

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceObjectsEnum ( _                      ' VTable offset = 24
     BYVAL flags AS LONG _                              ' __in flags CONST_DIDFTFLAGS <enum>
   ) AS DirectInputEnumDeviceObjects                    ' __retval_out **ppret DirectInputEnumDeviceObjects <interface>
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 28
     BYREF caps AS DIDEVCAPS _                          ' __inout *caps DIDEVCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 32
     BYREF deviceObjectDataArray AS DWORD _             ' __inout **deviceObjectDataArray VT_SAFEARRAY
   , BYVAL flags AS LONG _                              ' __in flags CONST_DIDGDDFLAGS <enum>
   ) AS LONG                                            ' __retval_out *c VT_I4 <Long>
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 36
   ) AS DirectInputDeviceInstance                       ' __retval_out **deviceInstance DirectInputDeviceInstance <interface>
   ' =====================================================================================
   METHOD GetDeviceStateKeyboard ( _                    ' VTable offset = 40
     BYREF state AS DIKEYBOARDSTATE _                   ' __inout *state DIKEYBOARDSTATE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceStateMouse ( _                       ' VTable offset = 44
     BYREF state AS DIMOUSESTATE _                      ' __inout *state DIMOUSESTATE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceStateJoystick ( _                    ' VTable offset = 48
     BYREF state AS DIJOYSTATE _                        ' __inout *state DIJOYSTATE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceStateJoystick2 ( _                   ' VTable offset = 52
     BYREF state AS DIJOYSTATE2 _                       ' __inout *state DIJOYSTATE2 <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 56
     BYVAL cb AS LONG _                                 ' __in cb VT_I4 <Long>
   , BYVAL state AS DWORD _                             ' __in *state VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 60
     BYVAL Obj AS LONG _                                ' __in Obj VT_I4 <Long>
   , BYVAL how AS LONG _                                ' __in how CONST_DIPHFLAGS <enum>
   ) AS DirectInputDeviceObjectInstance                 ' __retval_out **ret DirectInputDeviceObjectInstance <interface>
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 64
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL propertyInfo AS DWORD _                      ' __out *propertyInfo VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 68
     BYVAL hwnd AS LONG _                               ' __in hwnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 72
     BYVAL hwnd AS LONG _                               ' __in hwnd VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DISCLFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCommonDataFormat ( _                       ' VTable offset = 76
     BYVAL format AS LONG _                             ' __in format CONST_DICOMMONDATAFORMATS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 80
     BYREF format AS DIDATAFORMAT _                     ' __in *format DIDATAFORMAT <record>
   , BYREF formatArray AS DWORD _                       ' **formatArray VT_SAFEARRAY
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 84
     BYVAL hEvent AS LONG _                             ' __in hEvent VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 88
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   , BYVAL propertyInfo AS DWORD _                      ' __in *propertyInfo VT_VOID <Dword>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 100
     BYVAL effectGuid AS WSTRING _                      ' __in effectGuid VT_BSTR
   , BYREF effectinfo AS DIEFFECT _                     ' __in *effectinfo DIEFFECT <record>
   ) AS DirectInputEffect                               ' __retval_out **ret DirectInputEffect <interface>
   ' =====================================================================================
   METHOD CreateCustomEffect ( _                        ' VTable offset = 104
     BYREF effectinfo AS DIEFFECT _                     ' __in *effectinfo DIEFFECT <record>
   , BYVAL channels AS LONG _                           ' __in channels VT_I4 <Long>
   , BYVAL samplePeriod AS LONG _                       ' __in samplePeriod VT_I4 <Long>
   , BYVAL nSamples AS LONG _                           ' __in nSamples VT_I4 <Long>
   , BYREF sampledata AS DWORD _                        ' __in **sampledata VT_SAFEARRAY
   ) AS DirectInputEffect                               ' __retval_out **ret DirectInputEffect <interface>
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 108
     BYVAL count AS LONG _                              ' __in count VT_I4 <Long>
   , BYREF data AS DWORD _                              ' __in **data VT_SAFEARRAY
   , BYVAL flags AS LONG _                              ' __in flags CONST_DISDDFLAGS <enum>
   ) AS LONG                                            ' __retval_out *retcount VT_I4 <Long>
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 112
     BYVAL flags AS LONG _                              ' __in flags CONST_DISFFCFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 116
   ) AS LONG                                            ' __retval_out *state CONST_DIGFFSFLAGS <enum>
   ' =====================================================================================
   METHOD GetEffectsEnum ( _                            ' VTable offset = 120
     BYVAL effType AS LONG _                            ' __in effType CONST_DIEFTFLAGS <enum>
   ) AS DirectInputEnumEffects                          ' __retval_out **ret DirectInputEnumEffects <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputEnumDeviceObjects
' IID = {9F76FA08-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputEnumDeviceObjects_INTERFACE_DEFINED)
    %DirectInputEnumDeviceObjects_INTERFACE_DEFINED = 1

INTERFACE DirectInputEnumDeviceObjects $IID_DirectInputEnumDeviceObjects

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS DirectInputDeviceObjectInstance                 ' __retval_out **info DirectInputDeviceObjectInstance <interface>
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputEnumDeviceObjects_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputDeviceObjectInstance
' IID = {9F76FA05-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputDeviceObjectInstance_INTERFACE_DEFINED)
    %DirectInputDeviceObjectInstance_INTERFACE_DEFINED = 1

INTERFACE DirectInputDeviceObjectInstance $IID_DirectInputDeviceObjectInstance

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetGuidType ( _                               ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetOfs ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *ret CONST_DIDEVICEOBJINSTANCEFLAGS <enum>
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetCollectionNumber ( _                       ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetDesignatorIndex ( _                        ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetUsagePage ( _                              ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetUsage ( _                                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetDimension ( _                              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetExponent ( _                               ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputDeviceObjectInstance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputDeviceInstance
' IID = {9F76FA04-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputDeviceInstance_INTERFACE_DEFINED)
    %DirectInputDeviceInstance_INTERFACE_DEFINED = 1

INTERFACE DirectInputDeviceInstance $IID_DirectInputDeviceInstance

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetGuidInstance ( _                           ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetGuidProduct ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetProductName ( _                            ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetInstanceName ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetGuidFFDriver ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetUsagePage ( _                              ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetUsage ( _                                  ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out *ret VT_I2 <Integer>
   ' =====================================================================================
   METHOD GetDevType ( _                                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputDeviceInstance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputEffect
' IID = {BCAA7DA9-F7EF-11D2-93FD-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputEffect_INTERFACE_DEFINED)
    %DirectInputEffect_INTERFACE_DEFINED = 1

INTERFACE DirectInputEffect $IID_DirectInputEffect

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEffectGuid ( _                             ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out *guid VT_BSTR
   ' =====================================================================================
   METHOD GetEffectStatus ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD start ( _                                     ' VTable offset = 32
     BYVAL iterations AS LONG _                         ' __in iterations VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Unload ( _                                    ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD SetParameters ( _                             ' VTable offset = 44
     BYREF effectinfo AS DIEFFECT _                     ' __in *effectinfo DIEFFECT <record>
   , BYVAL flags AS LONG _                              ' __in flags CONST_DIEPFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 48
     BYREF effectinfo AS DIEFFECT _                     ' __inout *effectinfo DIEFFECT <record>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputEffect_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputEnumEffects
' IID = {BCAA7DAA-F7EF-11D2-93FD-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputEnumEffects_INTERFACE_DEFINED)
    %DirectInputEnumEffects_INTERFACE_DEFINED = 1

INTERFACE DirectInputEnumEffects $IID_DirectInputEnumEffects

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetEffectGuid ( _                             ' VTable offset = 16
     BYVAL i AS LONG _                                  ' __in i VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 20
     BYVAL i AS LONG _                                  ' __in i VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret CONST_DIEFTFLAGS <enum>
   ' =====================================================================================
   METHOD GetStaticParams ( _                           ' VTable offset = 24
     BYVAL i AS LONG _                                  ' __in i VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret CONST_DIEPFLAGS <enum>
   ' =====================================================================================
   METHOD GetDynamicParams ( _                          ' VTable offset = 28
     BYVAL i AS LONG _                                  ' __in i VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret CONST_DIEPFLAGS <enum>
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 32
     BYVAL i AS LONG _                                  ' __in i VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *ret VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputEnumEffects_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectInputEnumDevices
' IID = {9F76FA09-8E92-11D1-8808-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectInputEnumDevices_INTERFACE_DEFINED)
    %DirectInputEnumDevices_INTERFACE_DEFINED = 1

INTERFACE DirectInputEnumDevices $IID_DirectInputEnumDevices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS DirectInputDeviceInstance                       ' __retval_out **info DirectInputDeviceInstance <interface>
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectInputEnumDevices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Direct3DRMInterpolator
' IID = {9F76FE29-8E92-11D1-8808-00C04FC2C602}
' Direct3DRMInterpolator Interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%Direct3DRMInterpolator_INTERFACE_DEFINED)
    %Direct3DRMInterpolator_INTERFACE_DEFINED = 1

INTERFACE Direct3DRMInterpolator $IID_Direct3DRMInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 20
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 24
     BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttachedObjects ( _                        ' VTable offset = 28
   ) AS Direct3DRMObjectArray                           ' __retval_out **rmArray Direct3DRMObjectArray <interface>
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 32
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out *val VT_R4 <Single>
   ' =====================================================================================
   METHOD Interpolate ( _                               ' VTable offset = 40
     BYVAL val AS SINGLE _                              ' __in val VT_R4 <Single>
   , BYVAL rmObject AS Direct3DRMObject _               ' __in *rmObject Direct3DRMObject <interface>
   , BYVAL options AS LONG _                            ' __in options CONST_D3DRMINTERPOLATIONFLAGS <enum>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Direct3DRMInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicLoader
' IID = {FAFA35A0-8B72-11D2-90B2-00C04FC2C602}
' DirectMusicLoader Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicLoader_INTERFACE_DEFINED)
    %DirectMusicLoader_INTERFACE_DEFINED = 1

INTERFACE DirectMusicLoader $IID_DirectMusicLoader

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD LoadSegment ( _                               ' VTable offset = 20
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   ) AS DirectMusicSegment                              ' __retval_out **ret DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD LoadStyle ( _                                 ' VTable offset = 24
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   ) AS DirectMusicStyle                                ' __retval_out **ret DirectMusicStyle <interface>
   ' =====================================================================================
   METHOD LoadBand ( _                                  ' VTable offset = 28
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   ) AS DirectMusicBand                                 ' __retval_out **ret DirectMusicBand <interface>
   ' =====================================================================================
   METHOD LoadCollection ( _                            ' VTable offset = 32
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   ) AS DirectMusicCollection                           ' __retval_out **ret DirectMusicCollection <interface>
   ' =====================================================================================
   METHOD LoadSegmentFromResource ( _                   ' VTable offset = 36
     BYVAL moduleName AS WSTRING _                      ' __in moduleName VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   ) AS DirectMusicSegment                              ' __retval_out **ret DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD LoadStyleFromResource ( _                     ' VTable offset = 40
     BYVAL moduleName AS WSTRING _                      ' __in moduleName VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   ) AS DirectMusicStyle                                ' __retval_out **ret DirectMusicStyle <interface>
   ' =====================================================================================
   METHOD LoadBandFromResource ( _                      ' VTable offset = 44
     BYVAL moduleName AS WSTRING _                      ' __in moduleName VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   ) AS DirectMusicBand                                 ' __retval_out **ret DirectMusicBand <interface>
   ' =====================================================================================
   METHOD LoadCollectionFromResource ( _                ' VTable offset = 48
     BYVAL moduleName AS WSTRING _                      ' __in moduleName VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   ) AS DirectMusicCollection                           ' __retval_out **ret DirectMusicCollection <interface>
   ' =====================================================================================
   METHOD SetSearchDirectory ( _                        ' VTable offset = 52
     BYVAL dir AS WSTRING _                             ' __in dir VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadChordMap ( _                              ' VTable offset = 56
     BYVAL filename AS WSTRING _                        ' __in filename VT_BSTR
   ) AS DirectMusicChordMap                             ' __retval_out **ret DirectMusicChordMap <interface>
   ' =====================================================================================
   METHOD LoadChordMapFromResource ( _                  ' VTable offset = 60
     BYVAL moduleName AS WSTRING _                      ' __in moduleName VT_BSTR
   , BYVAL resourceName AS WSTRING _                    ' __in resourceName VT_BSTR
   ) AS DirectMusicChordMap                             ' __retval_out **ret DirectMusicChordMap <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicLoader_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicSegment
' IID = {FAFA35A1-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicSegment_INTERFACE_DEFINED)
    %DirectMusicSegment_INTERFACE_DEFINED = 1

INTERFACE DirectMusicSegment $IID_DirectMusicSegment

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYVAL mtStart AS LONG _                            ' __in mtStart VT_I4 <Long>
   , BYVAL mtEnd AS LONG _                              ' __in mtEnd VT_I4 <Long>
   ) AS DirectMusicSegment                              ' __retval_out **ppSegment DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD SetStartPoint ( _                             ' VTable offset = 24
     BYVAL mtStart AS LONG _                            ' __in mtStart VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStartPoint ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *pmtStart VT_I4 <Long>
   ' =====================================================================================
   METHOD SetLoopPoints ( _                             ' VTable offset = 32
     BYVAL mtStart AS LONG _                            ' __in mtStart VT_I4 <Long>
   , BYVAL mtEnd AS LONG _                              ' __in mtEnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLoopPointStart ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *pmtStart VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLoopPointEnd ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *pmtEnd VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out *pmtLength VT_I4 <Long>
   ' =====================================================================================
   METHOD SetLength ( _                                 ' VTable offset = 48
     BYVAL mtLength AS LONG _                           ' __in mtLength VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRepeats ( _                                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out *lRepeats VT_I4 <Long>
   ' =====================================================================================
   METHOD SetRepeats ( _                                ' VTable offset = 56
     BYVAL lRepeats AS LONG _                           ' __in lRepeats VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 60
     BYVAL performance AS DirectMusicPerformance _      ' __in *performance DirectMusicPerformance <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unload ( _                                    ' VTable offset = 64
     BYVAL performance AS DirectMusicPerformance _      ' __in *performance DirectMusicPerformance <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAutoDownloadEnable ( _                     ' VTable offset = 68
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTempoEnable ( _                            ' VTable offset = 72
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTimeSigEnable ( _                          ' VTable offset = 76
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStandardMidiFile ( _                       ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectToCollection ( _                       ' VTable offset = 84
     BYVAL c AS DirectMusicCollection _                 ' __in *c DirectMusicCollection <interface>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicSegment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicPerformance
' IID = {FAFA35A7-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicPerformance_INTERFACE_DEFINED)
    %DirectMusicPerformance_INTERFACE_DEFINED = 1

INTERFACE DirectMusicPerformance $IID_DirectMusicPerformance

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 20
     BYVAL DirectSound AS DirectSound _                 ' __in *DirectSound DirectSound <interface>
   , BYVAL hwnd AS LONG _                               ' __in hwnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseDown ( _                                 ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD PlaySegment ( _                               ' VTable offset = 28
     BYVAL segment AS DirectMusicSegment _              ' __in *segment DirectMusicSegment <interface>
   , BYVAL lFlags AS LONG _                             ' __in lFlags VT_I4 <Long>
   , BYVAL startTime AS LONG _                          ' __in startTime VT_I4 <Long>
   ) AS DirectMusicSegmentState                         ' __retval_out **segmentState DirectMusicSegmentState <interface>
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 32
     BYVAL segment AS DirectMusicSegment _              ' __in *segment DirectMusicSegment <interface>
   , BYVAL segmentState AS DirectMusicSegmentState _    ' __in *segmentState DirectMusicSegmentState <interface>
   , BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYVAL lFlags AS LONG _                             ' __in lFlags VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSegmentState ( _                           ' VTable offset = 36
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   ) AS DirectMusicSegmentState                         ' __retval_out **ret DirectMusicSegmentState <interface>
   ' =====================================================================================
   METHOD Invalidate ( _                                ' VTable offset = 40
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD IsPlaying ( _                                 ' VTable offset = 44
     BYVAL segment AS DirectMusicSegment _              ' __in *segment DirectMusicSegment <interface>
   , BYVAL segmentState AS DirectMusicSegmentState _    ' __in *segmentState DirectMusicSegmentState <interface>
   ) AS INTEGER                                         ' __retval_out *b VT_BOOL <Integer>
   ' =====================================================================================
   METHOD AddNotificationType ( _                       ' VTable offset = 48
     BYVAL type AS LONG _                               ' __in type CONST_DMUS_NOTIFICATION_TYPE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveNotificationType ( _                    ' VTable offset = 52
     BYVAL type AS LONG _                               ' __in type CONST_DMUS_NOTIFICATION_TYPE <enum>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNotificationHandle ( _                     ' VTable offset = 56
     BYVAL hnd AS LONG _                                ' __in hnd VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNotificationPMSG ( _                       ' VTable offset = 60
     BYREF message AS DMUS_NOTIFICATION_PMSG _          ' __inout *message DMUS_NOTIFICATION_PMSG <record>
   ) AS INTEGER                                         ' __retval_out *success VT_BOOL <Integer>
   ' =====================================================================================
   METHOD MusicToClockTime ( _                          ' VTable offset = 64
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ctTime VT_I4 <Long>
   ' =====================================================================================
   METHOD ClockToMusicTime ( _                          ' VTable offset = 68
     BYVAL ctTime AS LONG _                             ' __in ctTime VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *mtTime VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMusicTime ( _                              ' VTable offset = 72
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetClockTime ( _                              ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPrepareTime ( _                            ' VTable offset = 80
   ) AS LONG                                            ' __retval_out *lMilliSeconds VT_I4 <Long>
   ' =====================================================================================
   METHOD GetBumperLength ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out *lMilliSeconds VT_I4 <Long>
   ' =====================================================================================
   METHOD GetLatencyTime ( _                            ' VTable offset = 88
   ) AS LONG                                            ' __retval_out *ctTime VT_I4 <Long>
   ' =====================================================================================
   METHOD GetQueueTime ( _                              ' VTable offset = 92
   ) AS LONG                                            ' __retval_out *ctTime VT_I4 <Long>
   ' =====================================================================================
   METHOD GetResolvedTime ( _                           ' VTable offset = 96
     BYVAL ctTime AS LONG _                             ' __in ctTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   ) AS LONG                                            ' __retval_out *ret VT_I4 <Long>
   ' =====================================================================================
   METHOD SetPrepareTime ( _                            ' VTable offset = 100
     BYVAL lMilliSeconds AS LONG _                      ' __in lMilliSeconds VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBumperLength ( _                           ' VTable offset = 104
     BYVAL lMilliSeconds AS LONG _                      ' __in lMilliSeconds VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD AdjustTime ( _                                ' VTable offset = 108
     BYVAL tAmount AS LONG _                            ' __in tAmount VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMasterAutoDownload ( _                     ' VTable offset = 112
     BYVAL b AS INTEGER _                               ' __in b VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMasterAutoDownload ( _                     ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out *b VT_BOOL <Integer>
   ' =====================================================================================
   METHOD SetMasterTempo ( _                            ' VTable offset = 120
     BYVAL tempo AS SINGLE _                            ' __in tempo VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMasterTempo ( _                            ' VTable offset = 124
   ) AS SINGLE                                          ' __retval_out *tempo VT_R4 <Single>
   ' =====================================================================================
   METHOD SetMasterVolume ( _                           ' VTable offset = 128
     BYVAL vol AS LONG _                                ' __in vol VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMasterVolume ( _                           ' VTable offset = 132
   ) AS LONG                                            ' __retval_out *v VT_I4 <Long>
   ' =====================================================================================
   METHOD SetMasterGrooveLevel ( _                      ' VTable offset = 136
     BYVAL level AS INTEGER _                           ' __in level VT_I2 <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMasterGrooveLevel ( _                      ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out *level VT_I2 <Integer>
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 144
     BYVAL resetflags AS LONG _                         ' __in resetflags VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStyle ( _                                  ' VTable offset = 148
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   ) AS DirectMusicStyle                                ' __retval_out **ret DirectMusicStyle <interface>
   ' =====================================================================================
   METHOD GetChordMap ( _                               ' VTable offset = 152
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   ) AS DirectMusicChordMap                             ' __retval_out **ret DirectMusicChordMap <interface>
   ' =====================================================================================
   METHOD GetCommand ( _                                ' VTable offset = 156
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   ) AS BYTE                                            ' __retval_out *command VT_UI1 <Byte>
   ' =====================================================================================
   METHOD GetGrooveLevel ( _                            ' VTable offset = 160
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   ) AS BYTE                                            ' __retval_out *level VT_UI1 <Byte>
   ' =====================================================================================
   METHOD GetTempo ( _                                  ' VTable offset = 164
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   ) AS DOUBLE                                          ' __retval_out *tempo VT_R8 <Double>
   ' =====================================================================================
   METHOD GetTimeSig ( _                                ' VTable offset = 168
     BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYREF mtUntil AS LONG _                            ' __inout *mtUntil VT_I4 <Long>
   , BYREF timeSig AS DMUS_TIMESIGNATURE _              ' __inout *timeSig DMUS_TIMESIGNATURE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendNotePMSG ( _                              ' VTable offset = 172
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL channel AS LONG _                            ' __in channel VT_I4 <Long>
   , BYREF msg AS DMUS_NOTE_PMSG _                      ' __in *msg DMUS_NOTE_PMSG <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendCurvePMSG ( _                             ' VTable offset = 176
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL channel AS LONG _                            ' __in channel VT_I4 <Long>
   , BYREF msg AS DMUS_CURVE_PMSG _                     ' __in *msg DMUS_CURVE_PMSG <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendMIDIPMSG ( _                              ' VTable offset = 180
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL channel AS LONG _                            ' __in channel VT_I4 <Long>
   , BYVAL status AS BYTE _                             ' __in status VT_UI1 <Byte>
   , BYVAL byte1 AS BYTE _                              ' __in byte1 VT_UI1 <Byte>
   , BYVAL byte2 AS BYTE _                              ' __in byte2 VT_UI1 <Byte>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendPatchPMSG ( _                             ' VTable offset = 184
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL channel AS LONG _                            ' __in channel VT_I4 <Long>
   , BYVAL instrument AS BYTE _                         ' __in instrument VT_UI1 <Byte>
   , BYVAL byte1 AS BYTE _                              ' __in byte1 VT_UI1 <Byte>
   , BYVAL byte2 AS BYTE _                              ' __in byte2 VT_UI1 <Byte>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendTempoPMSG ( _                             ' VTable offset = 188
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL tempo AS DOUBLE _                            ' __in tempo VT_R8 <Double>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendTransposePMSG ( _                         ' VTable offset = 192
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYVAL channel AS LONG _                            ' __in channel VT_I4 <Long>
   , BYVAL transpose AS INTEGER _                       ' __in transpose VT_I2 <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD SendTimeSigPMSG ( _                           ' VTable offset = 196
     BYVAL lTime AS LONG _                              ' __in lTime VT_I4 <Long>
   , BYVAL flags AS LONG _                              ' __in flags VT_I4 <Long>
   , BYREF timeSig AS DMUS_TIMESIGNATURE _              ' __in *timeSig DMUS_TIMESIGNATURE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPortName ( _                               ' VTable offset = 200
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetPortCount ( _                              ' VTable offset = 204
   ) AS LONG                                            ' __retval_out *c VT_I4 <Long>
   ' =====================================================================================
   METHOD GetPortCaps ( _                               ' VTable offset = 208
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYREF caps AS DMUS_PORTCAPS _                      ' __inout *caps DMUS_PORTCAPS <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPort ( _                                   ' VTable offset = 212
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   , BYVAL numGroups AS LONG _                          ' __in numGroups VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicPerformance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicSegmentState
' IID = {FAFA35A6-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicSegmentState_INTERFACE_DEFINED)
    %DirectMusicSegmentState_INTERFACE_DEFINED = 1

INTERFACE DirectMusicSegmentState $IID_DirectMusicSegmentState

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetRepeats ( _                                ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *repeats VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSeek ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *seek VT_I4 <Long>
   ' =====================================================================================
   METHOD GetStartPoint ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *seek VT_I4 <Long>
   ' =====================================================================================
   METHOD GetStartTime ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out *seek VT_I4 <Long>
   ' =====================================================================================
   METHOD GetSegment ( _                                ' VTable offset = 36
   ) AS DirectMusicSegment                              ' __retval_out **segment DirectMusicSegment <interface>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicSegmentState_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicStyle
' IID = {FAFA35A4-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicStyle_INTERFACE_DEFINED)
    %DirectMusicStyle_INTERFACE_DEFINED = 1

INTERFACE DirectMusicStyle $IID_DirectMusicStyle

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetBandName ( _                               ' VTable offset = 20
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetBandCount ( _                              ' VTable offset = 24
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetBand ( _                                   ' VTable offset = 28
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   ) AS DirectMusicBand                                 ' __retval_out **ret DirectMusicBand <interface>
   ' =====================================================================================
   METHOD GetDefaultBand ( _                            ' VTable offset = 32
   ) AS DirectMusicBand                                 ' __retval_out **ret DirectMusicBand <interface>
   ' =====================================================================================
   METHOD GetMotifName ( _                              ' VTable offset = 36
     BYVAL index AS LONG _                              ' __in index VT_I4 <Long>
   ) AS WSTRING                                         ' __retval_out *name VT_BSTR
   ' =====================================================================================
   METHOD GetMotifCount ( _                             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out *count VT_I4 <Long>
   ' =====================================================================================
   METHOD GetMotif ( _                                  ' VTable offset = 44
     BYVAL name AS WSTRING _                            ' __in name VT_BSTR
   ) AS DirectMusicSegment                              ' __retval_out **ret DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD GetTimeSignature ( _                          ' VTable offset = 48
     BYREF pTimeSig AS DMUS_TIMESIGNATURE _             ' __inout *pTimeSig DMUS_TIMESIGNATURE <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTempo ( _                                  ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out *pTempo VT_R8 <Double>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicStyle_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicBand
' IID = {FAFA35A3-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicBand_INTERFACE_DEFINED)
    %DirectMusicBand_INTERFACE_DEFINED = 1

INTERFACE DirectMusicBand $IID_DirectMusicBand

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD CreateSegment ( _                             ' VTable offset = 20
   ) AS DirectMusicSegment                              ' __retval_out **ret DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 24
     BYVAL performance AS DirectMusicPerformance _      ' __in *performance DirectMusicPerformance <interface>
   )                                                    ' void
   ' =====================================================================================
   METHOD Unload ( _                                    ' VTable offset = 28
     BYVAL performance AS DirectMusicPerformance _      ' __in *performance DirectMusicPerformance <interface>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicBand_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicChordMap
' IID = {FAFA35A5-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicChordMap_INTERFACE_DEFINED)
    %DirectMusicChordMap_INTERFACE_DEFINED = 1

INTERFACE DirectMusicChordMap $IID_DirectMusicChordMap

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD GetScale ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' __retval_out *scale VT_I4 <Long>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicChordMap_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicCollection
' IID = {FAFA35A8-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicCollection_INTERFACE_DEFINED)
    %DirectMusicCollection_INTERFACE_DEFINED = 1

INTERFACE DirectMusicCollection $IID_DirectMusicCollection

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectMusicComposer
' IID = {FAFA35A2-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectMusicComposer_INTERFACE_DEFINED)
    %DirectMusicComposer_INTERFACE_DEFINED = 1

INTERFACE DirectMusicComposer $IID_DirectMusicComposer

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InternalSetObject ( _                         ' VTable offset = 12
     BYVAL lpdd AS IUnknown _                           ' __in *lpdd VT_UNKNOWN <IUnknown>
   )                                                    ' void
   ' =====================================================================================
   METHOD InternalGetObject ( _                         ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out **lpdd VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   METHOD AutoTransition ( _                            ' VTable offset = 20
     BYVAL performance AS DirectMusicPerformance _      ' __in *performance DirectMusicPerformance <interface>
   , BYVAL toSeg AS DirectMusicSegment _                ' __in *toSeg DirectMusicSegment <interface>
   , BYVAL lCommand AS LONG _                           ' __in lCommand VT_I4 <Long>
   , BYVAL lFlags AS LONG _                             ' __in lFlags VT_I4 <Long>
   , BYVAL chordmap AS DirectMusicChordMap _            ' __in *chordmap DirectMusicChordMap <interface>
   ) AS DirectMusicSegment                              ' __retval_out **ppTransSeg DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD ComposeSegmentFromTemplate ( _                ' VTable offset = 24
     BYVAL style AS DirectMusicStyle _                  ' __in *style DirectMusicStyle <interface>
   , BYVAL templateSeg AS DirectMusicSegment _          ' __in *templateSeg DirectMusicSegment <interface>
   , BYVAL activity AS INTEGER _                        ' __in activity VT_I2 <Integer>
   , BYVAL chordmap AS DirectMusicChordMap _            ' __in *chordmap DirectMusicChordMap <interface>
   ) AS DirectMusicSegment                              ' __retval_out **SectionSeg DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD ComposeSegmentFromShape ( _                   ' VTable offset = 28
     BYVAL style AS DirectMusicStyle _                  ' __in *style DirectMusicStyle <interface>
   , BYVAL numberOfMeasures AS INTEGER _                ' __in numberOfMeasures VT_I2 <Integer>
   , BYVAL shape AS INTEGER _                           ' __in shape VT_I2 <Integer>
   , BYVAL activity AS INTEGER _                        ' __in activity VT_I2 <Integer>
   , BYVAL bIntro AS INTEGER _                          ' __in bIntro VT_BOOL <Integer>
   , BYVAL bEnd AS INTEGER _                            ' __in bEnd VT_BOOL <Integer>
   , BYVAL chordmap AS DirectMusicChordMap _            ' __in *chordmap DirectMusicChordMap <interface>
   ) AS DirectMusicSegment                              ' __retval_out **SectionSeg DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD ComposeTransition ( _                         ' VTable offset = 32
     BYVAL fromSeg AS DirectMusicSegment _              ' __in *fromSeg DirectMusicSegment <interface>
   , BYVAL toSeg AS DirectMusicSegment _                ' __in *toSeg DirectMusicSegment <interface>
   , BYVAL mtTime AS LONG _                             ' __in mtTime VT_I4 <Long>
   , BYVAL lCommand AS LONG _                           ' __in lCommand VT_I4 <Long>
   , BYVAL lFlags AS LONG _                             ' __in lFlags VT_I4 <Long>
   , BYVAL chordmap AS DirectMusicChordMap _            ' __in *chordmap DirectMusicChordMap <interface>
   ) AS DirectMusicSegment                              ' __retval_out **SectionSeg DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD ComposeTemplateFromShape ( _                  ' VTable offset = 36
     BYVAL numMeasures AS INTEGER _                     ' __in numMeasures VT_I2 <Integer>
   , BYVAL shape AS INTEGER _                           ' __in shape VT_I2 <Integer>
   , BYVAL bIntro AS INTEGER _                          ' __in bIntro VT_BOOL <Integer>
   , BYVAL bEnd AS INTEGER _                            ' __in bEnd VT_BOOL <Integer>
   , BYVAL endLength AS INTEGER _                       ' __in endLength VT_I2 <Integer>
   ) AS DirectMusicSegment                              ' __retval_out **TempSeg DirectMusicSegment <interface>
   ' =====================================================================================
   METHOD ChangeChordMap ( _                            ' VTable offset = 40
     BYVAL segment AS DirectMusicSegment _              ' __in *segment DirectMusicSegment <interface>
   , BYVAL trackScale AS INTEGER _                      ' __in trackScale VT_BOOL <Integer>
   , BYVAL chordmap AS DirectMusicChordMap _            ' __in *chordmap DirectMusicChordMap <interface>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectMusicComposer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DirectXEvent
' IID = {FAFA35B0-8B72-11D2-90B2-00C04FC2C602}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%DirectXEvent_INTERFACE_DEFINED)
    %DirectXEvent_INTERFACE_DEFINED = 1

INTERFACE DirectXEvent $IID_DirectXEvent

   INHERIT IAutomation

   ' =====================================================================================
   METHOD DXCallback ( _                                ' VTable offset = 12
     BYVAL eventid AS LONG _                            ' __in eventid VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DirectXEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDirectX7
' IID = {FAFA3599-8B72-11D2-90B2-00C04FC2C602}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectX7_INTERFACE_DEFINED)
    %IDirectX7_INTERFACE_DEFINED = 1

INTERFACE IDirectX7 $IID_IDirectX7

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Direct3DRMCreate ( _                          ' VTable offset = 12
   ) AS Direct3DRM3                                     ' __retval_out **ret Direct3DRM3 <interface>
   ' =====================================================================================
   METHOD DirectDrawCreate ( _                          ' VTable offset = 16
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectDraw7                                     ' __retval_out **ret DirectDraw7 <interface>
   ' =====================================================================================
   METHOD GetDDEnum ( _                                 ' VTable offset = 20
   ) AS DirectDrawEnum                                  ' __retval_out **ret DirectDrawEnum <interface>
   ' =====================================================================================
   METHOD DirectSoundCreate ( _                         ' VTable offset = 24
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectSound                                     ' __retval_out **ret DirectSound <interface>
   ' =====================================================================================
   METHOD DirectSoundCaptureCreate ( _                  ' VTable offset = 28
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectSoundCapture                              ' __retval_out **ret DirectSoundCapture <interface>
   ' =====================================================================================
   METHOD GetDSEnum ( _                                 ' VTable offset = 32
   ) AS DirectSoundEnum                                 ' __retval_out **retval DirectSoundEnum <interface>
   ' =====================================================================================
   METHOD GetDSCaptureEnum ( _                          ' VTable offset = 36
   ) AS DirectSoundEnum                                 ' __retval_out **retval DirectSoundEnum <interface>
   ' =====================================================================================
   METHOD DirectInputCreate ( _                         ' VTable offset = 40
   ) AS DirectInput                                     ' __retval_out **ret DirectInput <interface>
   ' =====================================================================================
   METHOD DirectPlayCreate ( _                          ' VTable offset = 44
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectPlay4                                     ' __retval_out **ret DirectPlay4 <interface>
   ' =====================================================================================
   METHOD DirectPlayLobbyCreate ( _                     ' VTable offset = 48
   ) AS DirectPlayLobby3                                ' __retval_out **ret DirectPlayLobby3 <interface>
   ' =====================================================================================
   METHOD GetDPEnum ( _                                 ' VTable offset = 52
   ) AS DirectPlayEnumServiceProviders                  ' __retval_out **retval DirectPlayEnumServiceProviders <interface>
   ' =====================================================================================
   METHOD ColorGetAlpha ( _                             ' VTable offset = 56
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD ColorGetBlue ( _                              ' VTable offset = 60
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD ColorGetGreen ( _                             ' VTable offset = 64
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD ColorGetRed ( _                               ' VTable offset = 68
     BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD CreateColorRGB ( _                            ' VTable offset = 72
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD CreateColorRGBA ( _                           ' VTable offset = 76
     BYVAL r AS SINGLE _                                ' __in r VT_R4 <Single>
   , BYVAL g AS SINGLE _                                ' __in g VT_R4 <Single>
   , BYVAL b AS SINGLE _                                ' __in b VT_R4 <Single>
   , BYVAL a AS SINGLE _                                ' __in a VT_R4 <Single>
   ) AS LONG                                            ' __retval_out *color VT_I4 <Long>
   ' =====================================================================================
   METHOD MatrixFromQuaternion ( _                      ' VTable offset = 80
     BYREF matrix AS D3DMATRIX _                        ' __out *matrix D3DMATRIX <record>
   , BYREF quat AS D3DRMQUATERNION _                    ' __in *quat D3DRMQUATERNION <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD QuaternionRotation ( _                        ' VTable offset = 84
     BYREF quat AS D3DRMQUATERNION _                    ' __out *quat D3DRMQUATERNION <record>
   , BYREF axis AS D3DVECTOR _                          ' __in *axis D3DVECTOR <record>
   , BYVAL theta AS SINGLE _                            ' __in theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD QuaternionMultiply ( _                        ' VTable offset = 88
     BYREF quat AS D3DRMQUATERNION _                    ' __out *quat D3DRMQUATERNION <record>
   , BYREF quatA AS D3DRMQUATERNION _                   ' __in *quatA D3DRMQUATERNION <record>
   , BYREF quatB AS D3DRMQUATERNION _                   ' __in *quatB D3DRMQUATERNION <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD QuaternionSlerp ( _                           ' VTable offset = 92
     BYREF quat AS D3DRMQUATERNION _                    ' __out *quat D3DRMQUATERNION <record>
   , BYREF quatA AS D3DRMQUATERNION _                   ' __in *quatA D3DRMQUATERNION <record>
   , BYREF quatB AS D3DRMQUATERNION _                   ' __in *quatB D3DRMQUATERNION <record>
   , BYVAL alpha AS SINGLE _                            ' __in alpha VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorAdd ( _                                 ' VTable offset = 96
     BYREF v AS D3DVECTOR _                             ' __out *v D3DVECTOR <record>
   , BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYREF vB AS D3DVECTOR _                            ' __in *vB D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorCrossProduct ( _                        ' VTable offset = 100
     BYREF v AS D3DVECTOR _                             ' __out *v D3DVECTOR <record>
   , BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYREF vB AS D3DVECTOR _                            ' __in *vB D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorDotProduct ( _                          ' VTable offset = 104
     BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYREF vB AS D3DVECTOR _                            ' __in *vB D3DVECTOR <record>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD VectorModulus ( _                             ' VTable offset = 108
     BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   ) AS SINGLE                                          ' __retval_out *ret VT_R4 <Single>
   ' =====================================================================================
   METHOD VectorNormalize ( _                           ' VTable offset = 112
     BYREF v AS D3DVECTOR _                             ' __inout *v D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorRandom ( _                              ' VTable offset = 116
     BYREF v AS D3DVECTOR _                             ' __inout *v D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorReflect ( _                             ' VTable offset = 120
     BYREF vDest AS D3DVECTOR _                         ' __out *vDest D3DVECTOR <record>
   , BYREF vRay AS D3DVECTOR _                          ' __in *vRay D3DVECTOR <record>
   , BYREF vNormal AS D3DVECTOR _                       ' __in *vNormal D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorRotate ( _                              ' VTable offset = 124
     BYREF vDest AS D3DVECTOR _                         ' __out *vDest D3DVECTOR <record>
   , BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYREF vAxis AS D3DVECTOR _                         ' __in *vAxis D3DVECTOR <record>
   , BYVAL theta AS SINGLE _                            ' __in theta VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorScale ( _                               ' VTable offset = 128
     BYREF vDest AS D3DVECTOR _                         ' __out *vDest D3DVECTOR <record>
   , BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYVAL factor AS SINGLE _                           ' __in factor VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorSubtract ( _                            ' VTable offset = 132
     BYREF v AS D3DVECTOR _                             ' __out *v D3DVECTOR <record>
   , BYREF vA AS D3DVECTOR _                            ' __in *vA D3DVECTOR <record>
   , BYREF vB AS D3DVECTOR _                            ' __in *vB D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD VectorCopy ( _                                ' VTable offset = 136
     BYREF vDest AS D3DVECTOR _                         ' __inout *vDest D3DVECTOR <record>
   , BYREF vSrc AS D3DVECTOR _                          ' __in *vSrc D3DVECTOR <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD RotateXMatrix ( _                             ' VTable offset = 140
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYVAL radians AS SINGLE _                          ' __in radians VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD RotateYMatrix ( _                             ' VTable offset = 144
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYVAL radians AS SINGLE _                          ' __in radians VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD RotateZMatrix ( _                             ' VTable offset = 148
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYVAL radians AS SINGLE _                          ' __in radians VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD ViewMatrix ( _                                ' VTable offset = 152
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYREF vFrom AS D3DVECTOR _                         ' __in *vFrom D3DVECTOR <record>
   , BYREF vTo AS D3DVECTOR _                           ' __in *vTo D3DVECTOR <record>
   , BYREF vUp AS D3DVECTOR _                           ' __in *vUp D3DVECTOR <record>
   , BYVAL roll AS SINGLE _                             ' __in roll VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD MatrixMultiply ( _                            ' VTable offset = 156
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYREF mA AS D3DMATRIX _                            ' __in *mA D3DMATRIX <record>
   , BYREF mB AS D3DMATRIX _                            ' __in *mB D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD ProjectionMatrix ( _                          ' VTable offset = 160
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYVAL nearPlane AS SINGLE _                        ' __in nearPlane VT_R4 <Single>
   , BYVAL farplane AS SINGLE _                         ' __in farplane VT_R4 <Single>
   , BYVAL fov AS SINGLE _                              ' __in fov VT_R4 <Single>
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyMatrix ( _                                ' VTable offset = 164
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   , BYREF mSrc AS D3DMATRIX _                          ' __in *mSrc D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD IdentityMatrix ( _                            ' VTable offset = 168
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD ZeroMatrix ( _                                ' VTable offset = 172
     BYREF mDest AS D3DMATRIX _                         ' __inout *mDest D3DMATRIX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD TickCount ( _                                 ' VTable offset = 176
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD SystemBpp ( _                                 ' VTable offset = 180
   ) AS LONG                                            ' __retval_out *retV VT_I4 <Long>
   ' =====================================================================================
   METHOD DirectMusicLoaderCreate ( _                   ' VTable offset = 184
   ) AS DirectMusicLoader                               ' __retval_out **ret DirectMusicLoader <interface>
   ' =====================================================================================
   METHOD DirectMusicComposerCreate ( _                 ' VTable offset = 188
   ) AS DirectMusicComposer                             ' __retval_out **ret DirectMusicComposer <interface>
   ' =====================================================================================
   METHOD DirectMusicPerformanceCreate ( _              ' VTable offset = 192
   ) AS DirectMusicPerformance                          ' __retval_out **ret DirectMusicPerformance <interface>
   ' =====================================================================================
   METHOD GetWindowRect ( _                             ' VTable offset = 196
     BYVAL hwnd AS LONG _                               ' __in hwnd VT_I4 <Long>
   , BYREF r AS RECT _                                  ' __inout *r RECT <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateEvent ( _                               ' VTable offset = 200
     BYVAL event AS DirectXEvent _                      ' __in *event DirectXEvent <interface>
   ) AS LONG                                            ' __retval_out *h VT_I4 <Long>
   ' =====================================================================================
   METHOD SetEvent ( _                                  ' VTable offset = 204
     BYVAL eventid AS LONG _                            ' __in eventid VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD DestroyEvent ( _                              ' VTable offset = 208
     BYVAL eventid AS LONG _                            ' __in eventid VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateD3DVertex ( _                           ' VTable offset = 212
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL nx AS SINGLE _                               ' __in nx VT_R4 <Single>
   , BYVAL ny AS SINGLE _                               ' __in ny VT_R4 <Single>
   , BYVAL nz AS SINGLE _                               ' __in nz VT_R4 <Single>
   , BYVAL tu AS SINGLE _                               ' __in tu VT_R4 <Single>
   , BYVAL tv AS SINGLE _                               ' __in tv VT_R4 <Single>
   , BYREF v AS D3DVERTEX _                             ' __inout *v D3DVERTEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateD3DLVertex ( _                          ' VTable offset = 216
     BYVAL x AS SINGLE _                                ' __in x VT_R4 <Single>
   , BYVAL y AS SINGLE _                                ' __in y VT_R4 <Single>
   , BYVAL z AS SINGLE _                                ' __in z VT_R4 <Single>
   , BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   , BYVAL specular AS LONG _                           ' __in specular VT_I4 <Long>
   , BYVAL tu AS SINGLE _                               ' __in tu VT_R4 <Single>
   , BYVAL tv AS SINGLE _                               ' __in tv VT_R4 <Single>
   , BYREF v AS D3DLVERTEX _                            ' __inout *v D3DLVERTEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateD3DTLVertex ( _                         ' VTable offset = 220
     BYVAL sx AS SINGLE _                               ' __in sx VT_R4 <Single>
   , BYVAL sy AS SINGLE _                               ' __in sy VT_R4 <Single>
   , BYVAL sz AS SINGLE _                               ' __in sz VT_R4 <Single>
   , BYVAL rhw AS SINGLE _                              ' __in rhw VT_R4 <Single>
   , BYVAL color AS LONG _                              ' __in color VT_I4 <Long>
   , BYVAL specular AS LONG _                           ' __in specular VT_I4 <Long>
   , BYVAL tu AS SINGLE _                               ' __in tu VT_R4 <Single>
   , BYVAL tv AS SINGLE _                               ' __in tv VT_R4 <Single>
   , BYREF v AS D3DTLVERTEX _                           ' __inout *v D3DTLVERTEX <record>
   )                                                    ' void
   ' =====================================================================================
   METHOD DirectDraw4Create ( _                         ' VTable offset = 224
     BYVAL guid AS WSTRING _                            ' __in guid VT_BSTR
   ) AS DirectDraw4                                     ' __retval_out **ret DirectDraw4 <interface>
   ' =====================================================================================
   METHOD CreateNewGuid ( _                             ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out *retGuid VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectX7_INTERFACE_DEFINED__ */

