' ########################################################################################
' Microsoft Windows
' File: d3d9.inc
' Contents: Direct3D include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D9_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "objbase.inc"

%DIRECT3D_VERSION = &H0900

'/* This identifier is passed to Direct3DCreate9 in order to ensure that an
' * application was built against the correct header files. This number is
' * incremented whenever a header (or other) change would require applications
' * to be rebuilt. If the version doesn't match, Direct3DCreate9 will fail.
' * (The number itself has no meaning.)*/

%D3D_SDK_VERSION   = 32
%D3D9b_SDK_VERSION = 31

'/*
' * Interface IID's
' */

$IID_IDirect3D9                     = GUID$("{81BDCBCA-64D4-426d-AE8D-AD0147F4275C}")
$IID_IDirect3DDevice9               = GUID$("{D0223B96-BF7A-43fd-92BD-A43B0D82B9EB}")
$IID_IDirect3DResource9             = GUID$("{05EEC05D-8F7D-4362-B999-D1BAF357C704}")
$IID_IDirect3DBaseTexture9          = GUID$("{580CA87E-1D3C-4d54-991D-B7D3E3C298CE}")
$IID_IDirect3DTexture9              = GUID$("{85C31227-3DE5-4f00-9B3A-F11AC38C18B5}")
$IID_IDirect3DCubeTexture9          = GUID$("{FFF32F81-D953-473a-9223-93D652ABA93F}")
$IID_IDirect3DVolumeTexture9        = GUID$("{2518526C-E789-4111-A7B9-47EF328D13E6}")
$IID_IDirect3DVertexBuffer9         = GUID$("{B64BB1B5-FD70-4df6-BF91-19D0A12455E3}")
$IID_IDirect3DIndexBuffer9          = GUID$("{7C9DD65E-D3F7-4529-ACEE-785830ACDE35}")
$IID_IDirect3DSurface9              = GUID$("{0CFBAF3A-9FF6-429a-99B3-A2796AF8B89B}")
$IID_IDirect3DVolume9               = GUID$("{24F416E6-1F67-4aa7-B88E-D33F6F3128A1}")
$IID_IDirect3DSwapChain9            = GUID$("{794950F2-ADFC-458a-905E-10A10B0B503B}")
$IID_IDirect3DVertexDeclaration9    = GUID$("{DD13C59C-36FA-4098-A8FB-C7ED39DC8546}")
$IID_IDirect3DVertexShader9         = GUID$("{EFC5557E-6265-4613-8A94-43857889EB36}")
$IID_IDirect3DPixelShader9          = GUID$("{6D3BDBDC-5B02-4415-B852-CE5E8BCCB289}")
$IID_IDirect3DStateBlock9           = GUID$("{B07C4FE5-310D-4ba8-A23C-4F0F206F218B}")
$IID_IDirect3DQuery9                = GUID$("{d9771460-a695-4f26-bbd3-27b840b541cc}")
$IID_HelperName                     = GUID$("{E4A36723-FDFE-4b22-B146-3C04C07F4CC8}")

'/* D3D9Ex only -- */
'#if !defined(D3D_DISABLE_9EX)
$IID_IDirect3D9Ex                   = GUID$("{02177241-69FC-400C-8FF1-93A44DF6861D}")
$IID_IDirect3DDevice9Ex             = GUID$("{B18B10CE-2649-405a-870F-95F777D4313A}")
$IID_IDirect3DSwapChain9Ex          = GUID$("{91886CAF-1C3D-4d2e-A0AB-3E4C7D8D3303}")
$IID_IDirect3D9ExOverlayExtension   = GUID$("{187aeb13-aaf5-4c59-876d-e059088c0df8}")
$IID_IDirect3DDevice9Video          = GUID$("{26DC4561-A1EE-4ae7-96DA-118A36C0EC95}")
$IID_IDirect3DAuthenticatedChannel9 = GUID$("{FF24BEEE-DA21-4beb-98B5-D2F899F98AF9}")
$IID_IDirect3DCryptoSession9        = GUID$("{FA0AB799-7A9C-48ca-8C5B-237E71A54434}")
'#endif // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

#INCLUDE ONCE "d3d9types.inc"
#INCLUDE ONCE "d3d9caps.inc"

'/*
' * DLL Function for creating a Direct3D9 object. This object supports
' * enumeration and allows the creation of Direct3DDevice9 objects.
' * Pass the value of the constant D3D_SDK_VERSION to this function, so
' * that the run-time can validate that your application was compiled
' * against the right headers.
' */

DECLARE FUNCTION Direct3DCreate9 IMPORT "D3D9.DLL" ALIAS "Direct3DCreate9" ( _
   BYVAL SDKVersion AS DWORD _                          ' __in UINT SDKVersion
 ) AS IDirect3D9                                        ' IDirect3D9 *

'/*
' * Stubs for graphics profiling.
' */

DECLARE FUNCTION D3DPERF_BeginEvent IMPORT "D3D9.DLL" ALIAS "D3DPERF_BeginEvent" ( _
   BYVAL col AS DWORD _                                 ' __in D3DCOLOR col
 , BYREF wszName AS WSTRINGZ _                          ' __in LPCWSTR wszName
 ) AS LONG                                              ' int

DECLARE FUNCTION D3DPERF_EndEvent IMPORT "D3D9.DLL" ALIAS "D3DPERF_EndEvent" ( _
 ) AS LONG                                              ' int

DECLARE SUB D3DPERF_SetMarker IMPORT "D3D9.DLL" ALIAS "D3DPERF_SetMarker" ( _
   BYVAL col AS DWORD _                                 ' __in D3DCOLOR col
 , BYREF wszName AS WSTRINGZ _                          ' __in LPCWSTR wszName
 )                                                      ' void

DECLARE SUB D3DPERF_SetRegion IMPORT "D3D9.DLL" ALIAS "D3DPERF_SetRegion" ( _
   BYVAL col AS DWORD _                                 ' __in D3DCOLOR col
 , BYREF wszName AS WSTRINGZ _                          ' __in LPCWSTR wszName
 )                                                      ' void

DECLARE FUNCTION D3DPERF_QueryRepeatFrame IMPORT "D3D9.DLL" ALIAS "D3DPERF_QueryRepeatFrame" ( _
 ) AS LONG                                              ' BOOL

DECLARE SUB D3DPERF_SetOptions IMPORT "D3D9.DLL" ALIAS "D3DPERF_SetOptions" ( _
   BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 )                                                      ' void

DECLARE FUNCTION D3DPERF_GetStatus IMPORT "D3D9.DLL" ALIAS "D3DPERF_GetStatus" ( _
 ) AS DWORD                                             ' DWORD


' ########################################################################################
' Interface name = IDirect3D9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3D9 $IID_IDirect3D9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterSoftwareDevice ( _                    ' VTable offset = 12
     BYVAL pInitializeFunction AS DWORD _               ' __in void* pInitializeFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterCount ( _                           ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAdapterIdentifier ( _                      ' VTable offset = 20
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pIdentifier AS D3DADAPTER_IDENTIFIER9 _      ' __out D3DADAPTER_IDENTIFIER9* pIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterModeCount ( _                       ' VTable offset = 24
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL Format AS DWORD _                            ' __in D3DFORMAT Format
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD EnumAdapterModes ( _                          ' VTable offset = 28
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Mode AS DWORD _                              ' __in  UINT Mode
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterDisplayMode ( _                     ' VTable offset = 32
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __in_out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceType ( _                           ' VTable offset = 36
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DevType AS DWORD _                           ' __in D3DDEVTYPE DevType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL BackBufferFormat AS DWORD _                  ' __in D3DFORMAT BackBufferFormat
   , BYVAL bWindowed AS LONG _                          ' __in BOOL bWindowed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceFormat ( _                         ' VTable offset = 40
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DevType AS DWORD _                           ' __in D3DDEVTYPE DevType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL Usage AS DWORD _                             ' __in DWORD Usage
   , BYVAL RType AS DWORD _                             ' __in D3DRESOURCETYPE RType
   , BYVAL CheckFormat AS DWORD _                       ' __in D3DFORMAT CheckFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceMultiSampleType ( _                ' VTable offset = 44
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYVAL SurfaceFormat AS DWORD _                     ' __in  D3DFORMAT SurfaceFormat
   , BYVAL Windowed AS LONG _                           ' __in  BOOL Windowed
   , BYVAL MultiSampleType AS DWORD _                   ' __in  D3DMULTISAMPLE_TYPE MultiSampleType
   , BYREF pQualityLevels AS DWORD _                    ' __out DWORD* pQualityLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDepthStencilMatch ( _                    ' VTable offset = 48
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in D3DDEVTYPE DeviceType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYVAL DepthStencilFormat AS DWORD _                ' __in D3DFORMAT DepthStencilFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceFormatConversion ( _               ' VTable offset = 52
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in D3DDEVTYPE DeviceType
   , BYVAL SourceFormat AS DWORD _                      ' __in D3DFORMAT SourceFormat
   , BYVAL TargetFormat AS DWORD _                      ' __in D3DFORMAT TargetFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceCaps ( _                             ' VTable offset = 56
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYREF pCaps AS D3DCAPS9 _                          ' __out D3DCAPS9* pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterMonitor ( _                         ' VTable offset = 60
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   ) AS DWORD                                           ' HMONITOR
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 64
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYVAL hFocusWindow AS DWORD _                      ' __in  HWND hFocusWindow
   , BYVAL BehaviorFlags AS DWORD _                     ' __in  DWORD BehaviorFlags
   , BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in  D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF ppReturnedDeviceInterface AS IDirect3DDevice9 _ ' __out IDirect3DDevice9** ppReturnedDeviceInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DDevice9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DDevice9 $IID_IDirect3DDevice9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableTextureMem ( _                    ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD EvictManagedResources ( _                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirect3D ( _                               ' VTable offset = 24
     BYREF ppD3D9 AS IDirect3D9 _                       ' __out IDirect3D9** ppD3D9
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceCaps ( _                             ' VTable offset = 28
     BYREF pCaps AS D3DCAPS9 _                          ' __out D3DCAPS9* pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 32
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationParameters ( _                     ' VTable offset = 36
     BYREF pParameters AS D3DDEVICE_CREATION_PARAMETERS _ ' __out D3DDEVICE_CREATION_PARAMETERS *pParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCursorProperties ( _                       ' VTable offset = 40
     BYVAL XHotSpot AS DWORD _                          ' __in UINT XHotSpot
   , BYVAL YHotSpot AS DWORD _                          ' __in UINT YHotSpot
   , BYVAL pCursorBitmap AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pCursorBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCursorPosition ( _                         ' VTable offset = 44
     BYVAL X AS LONG _                                  ' __in int X
   , BYVAL Y AS LONG _                                  ' __in int Y
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowCursor ( _                                ' VTable offset = 48
     BYVAL bShow AS LONG _                              ' __in BOOL bShow
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD CreateAdditionalSwapChain ( _                 ' VTable offset = 52
     BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in_out D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF pSwapChain AS IDirect3DSwapChain9 _          ' __out IDirect3DSwapChain9** pSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSwapChain ( _                              ' VTable offset = 56
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYREF pSwapChain AS IDirect3DSwapChain9 _          ' __out IDirect3DSwapChain9** pSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfSwapChains ( _                     ' VTable offset = 60
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 64
     BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in D3DPRESENT_PARAMETERS* pPresentationParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Present ( _                                   ' VTable offset = 68
     BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL hDestWindowOverride AS DWORD _               ' __in HWND hDestWindowOverride
   , BYREF pDirtyRegion AS RGNDATA _                    ' __in CONST RGNDATA* pDirtyRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackBuffer ( _                             ' VTable offset = 72
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYVAL iBackBuffer AS DWORD _                       ' __in  UINT iBackBuffer
   , BYVAL Type AS DWORD _                              ' __in  D3DBACKBUFFER_TYPE Type
   , BYREF ppBackBuffer AS IDirect3DSurface9 _          ' __out IDirect3DSurface9** ppBackBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRasterStatus ( _                           ' VTable offset = 76
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYREF pRasterStatus AS D3DRASTER_STATUS _          ' __out D3DRASTER_STATUS* pRasterStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDialogBoxMode ( _                          ' VTable offset = 80
     BYVAL bEnableDialogs AS LONG _                     ' __in BOOL bEnableDialogs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGammaRamp ( _                              ' VTable offset = 84
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF pRamp AS D3DGAMMARAMP _                      ' __in CONST D3DGAMMARAMP* pRamp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGammaRamp ( _                              ' VTable offset = 88
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYREF pRamp AS D3DGAMMARAMP _                      ' __in_out CONST D3DGAMMARAMP* pRamp
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTexture ( _                             ' VTable offset = 92
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppTexture AS IDirect3DTexture9 _             ' __out IDirect3DTexture9** ppTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVolumeTexture ( _                       ' VTable offset = 96
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Depth AS DWORD _                             ' __in  UINT Depth
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _ ' __out IDirect3DVolumeTexture9** ppVolumeTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCubeTexture ( _                         ' VTable offset = 100
     BYVAL EdgeLength AS DWORD _                        ' __in  UINT EdgeLength
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _     ' __out IDirect3DCubeTexture9** ppCubeTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexBuffer ( _                        ' VTable offset = 104
     BYVAL Length AS DWORD _                            ' __in  UINT Length
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppVertexBuffer AS IDirect3DVertexBuffer9 _   ' __out IDirect3DVertexBuffer9** ppVertexBuffer
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateIndexBuffer ( _                         ' VTable offset = 108
     BYVAL Length AS DWORD _                            ' __in  UINT Length
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppIndexBuffer AS IDirect3DIndexBuffer9 _     ' __out IDirect3DIndexBuffer9** ppIndexBuffer
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRenderTarget ( _                        ' VTable offset = 112
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Lockable AS LONG _                           ' __in  BOOL Lockable
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDepthStencilSurface ( _                 ' VTable offset = 116
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Discard AS LONG _                            ' __in  BOOL Discard
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSurface ( _                             ' __in VTable offset = 120
     BYVAL pSourceSurface AS IDirect3DSurface9 _        ' __in IDirect3DSurface9* pSourceSurface
   , BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYVAL pDestinationSurface AS IDirect3DSurface9 _   ' __in IDirect3DSurface9* pDestinationSurface
   , BYREF pDestPoint AS POINT _                        ' __in CONST POINT* pDestPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTexture ( _                             ' VTable offset = 124
     BYVAL pSourceTexture AS IDirect3DBaseTexture9 _    ' __in IDirect3DBaseTexture9* pSourceTexture
   , BYVAL pDestinationTexture AS IDirect3DBaseTexture9 _ ' __in IDirect3DBaseTexture9* pDestinationTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderTargetData ( _                       ' VTable offset = 128
     BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pRenderTarget
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrontBufferData ( _                        ' VTable offset = 132
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StretchRect ( _                               ' VTable offset = 136
     BYVAL pSourceSurface AS IDirect3DSurface9 _        ' __in IDirect3DSurface9* pSourceSurface
   , BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL Filter AS DWORD _                            ' __in D3DTEXTUREFILTERTYPE Filter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ColorFill ( _                                 ' VTable offset = 140
     BYVAL pSurface AS IDirect3DSurface9 _              ' __in IDirect3DSurface9* pSurface
   , BYREF pRect AS RECT _                              ' __in CONST RECT* pRect
   , BYVAL color AS DWORD _                             ' __in D3DCOLOR color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateOffscreenPlainSurface ( _               ' VTable offset = 144
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderTarget ( _                           ' VTable offset = 148
     BYVAL RenderTargetIndex AS DWORD _                 ' __in DWORD RenderTargetIndex
   , BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderTarget ( _                           ' VTable offset = 152
     BYVAL RenderTargetIndex AS DWORD _                 ' __in DWORD RenderTargetIndex
   , BYREF ppRenderTarget AS IDirect3DSurface9 _        ' __in IDirect3DSurface9** ppRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDepthStencilSurface ( _                    ' VTable offset = 156
     BYVAL pNewZStencil AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pNewZStencil
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDepthStencilSurface ( _                    ' VTable offset = 160
     BYREF ppZStencilSurface AS IDirect3DSurface9 _     ' __in IDirect3DSurface9** ppZStencilSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginScene ( _                                ' VTable offset = 164
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndScene ( _                                  ' VTable offset = 168
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 172
     BYVAL Count AS DWORD _                             ' __in DWORD Count
   , BYREF pRects AS D3DRECT _                          ' __in CONST D3DRECT* pRects
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   , BYVAL Z AS SINGLE _                                ' __in float Z
   , BYVAL Stencil AS DWORD _                           ' __in DWORD Stencil
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 176
     BYVAL State AS DWORD _                             ' __in D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __in CONST D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 180
     BYVAL State AS DWORD _                             ' __in  D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __out D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultiplyTransform ( _                         ' VTable offset = 184
     BYVAL State AS DWORD _                             ' __in D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __in CONST D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 188
     BYREF pViewport AS D3DVIEWPORT9 _                  ' __in CONST D3DVIEWPORT9* pViewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 192
     BYREF pViewport AS D3DVIEWPORT9 _                  ' __out D3DVIEWPORT9* pViewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 196
     BYREF pMaterial AS D3DMATERIAL9 _                  ' __in CONST D3DMATERIAL9* pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaterial ( _                               ' VTable offset = 200
     BYREF pMaterial AS D3DMATERIAL9 _                  ' __out D3DMATERIAL9* pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLight ( _                                  ' VTable offset = 204
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pMaterial AS D3DLIGHT9 _                     ' __in CONST D3DMATERIAL9 * pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLight ( _                                  ' VTable offset = 208
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pMaterial AS D3DLIGHT9 _                     ' __out D3DMATERIAL9 * pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LightEnable ( _                               ' VTable offset = 212
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYVAL Enable AS LONG _                             ' __in BOOL Enable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLightEnable ( _                            ' VTable offset = 216
     BYVAL Index AS DWORD _                             ' __in  DWORD Index
   , BYREF pEnable AS LONG _                            ' __out BOOL* pEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipPlane ( _                              ' VTable offset = 220
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pPlane AS SINGLE _                           ' __in CONST float* pPlane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipPlane ( _                              ' VTable offset = 224
     BYVAL Index AS DWORD _                             ' __in  DWORD Index
   , BYREF pPlane AS SINGLE _                           ' __out float* pPlane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderState ( _                            ' VTable offset = 228
     BYVAL State AS DWORD _                             ' __in D3DRENDERSTATETYPE State
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderState ( _                            ' VTable offset = 232
     BYVAL State AS DWORD _                             ' __in  D3DRENDERSTATETYPE State
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStateBlock ( _                          ' VTable offset = 236
     BYVAL Type AS DWORD _                              ' __in  D3DSTATEBLOCKTYPE Type
   , BYREF ppSB AS IDirect3DStateBlock9 _               ' __out IDirect3DStateBlock9** ppSB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginStateBlock ( _                           ' VTable offset = 240
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndStateBlock ( _                             ' VTable offset = 244
     BYREF ppSB AS IDirect3DStateBlock9 _               ' __out IDirect3DStateBlock9** ppSB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipStatus ( _                             ' VTable offset = 248
     BYREF pClipStatus AS D3DCLIPSTATUS9 _              ' __in CONST D3DCLIPSTATUS9* pClipStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipStatus ( _                             ' VTable offset = 252
     BYREF pClipStatus AS D3DCLIPSTATUS9 _              ' __out D3DCLIPSTATUS9* pClipStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 256
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYREF ppTexture AS IDirect3DBaseTexture9 _         ' __out IDirect3DBaseTexture9** ppTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 260
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYVAL pTexture AS IDirect3DBaseTexture9 _          ' __in IDirect3DBaseTexture9* pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextureStageState ( _                      ' VTable offset = 264
     BYVAL Stage AS DWORD _                             ' __in  DWORD Stage
   , BYVAL Type AS DWORD _                              ' __in  D3DTEXTURESTAGESTATETYPE Type
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextureStageState ( _                      ' VTable offset = 268
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYVAL Type AS DWORD _                              ' __in D3DTEXTURESTAGESTATETYPE Type
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSamplerState ( _                           ' VTable offset = 272
     BYVAL Sampler AS DWORD _                           ' __in  DWORD Sampler
   , BYVAL Type AS DWORD _                              ' __in  D3DSAMPLERSTATETYPE Type
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSamplerState ( _                           ' VTable offset = 276
     BYVAL Sampler AS DWORD _                           ' __in DWORD Sampler
   , BYVAL Type AS DWORD _                              ' __in D3DSAMPLERSTATETYPE Type
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateDevice ( _                            ' VTable offset = 280
     BYREF pNumPasses AS DWORD _                        ' __out DWORD* pNumPasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPaletteEntries ( _                         ' VTable offset = 284
     BYVAL PaletteNumber AS DWORD _                     ' __in UINT PaletteNumber
   , BYREF pEntries AS PALETTEENTRY _                   ' __in CONST PALETTEENTRY* pEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPaletteEntries ( _                         ' VTable offset = 288
     BYVAL PaletteNumber AS DWORD _                     ' __in  UINT PaletteNumber
   , BYREF pEntries AS PALETTEENTRY _                   ' __out PALETTEENTRY* pEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentTexturePalette ( _                  ' VTable offset = 292
     BYVAL PaletteNumber AS DWORD _                     ' __in UINT PaletteNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTexturePalette ( _                  ' VTable offset = 296
     BYREF PaletteNumber AS DWORD _                     ' __out UINT *PaletteNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScissorRect ( _                            ' VTable offset = 300
     BYREF pRect AS RECT _                              ' __in CONST RECT* pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScissorRect ( _                            ' VTable offset = 304
     BYREF pRect AS RECT _                              ' __out RECT* pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSoftwareVertexProcessing ( _               ' VTable offset = 308
     BYVAL bSoftware AS LONG _                          ' __in BOOL bSoftware
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSoftwareVertexProcessing ( _               ' VTable offset = 312
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD SetNPatchMode ( _                             ' VTable offset = 316
     BYVAL bSoftware AS SINGLE _                        ' __in float nSegments
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNPatchMode ( _                             ' VTable offset = 320
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD DrawPrimitive ( _                             ' VTable offset = 324
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL StartVertex AS DWORD _                       ' __in UINT StartVertex
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawIndexedPrimitive ( _                      ' VTable offset = 328
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL BaseVertexIndex AS LONG _                    ' __in INT BaseVertexIndex
   , BYVAL MinVertexIndex AS DWORD _                    ' __in UINT MinVertexIndex
   , BYVAL NumVertices AS DWORD _                       ' __in UINT NumVertices
   , BYVAL startIndex AS DWORD _                        ' __in UINT startIndex
   , BYVAL primCount AS DWORD _                         ' __in UINT primCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawPrimitiveUP ( _                           ' VTable offset = 332
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   , BYVAL pVertexStreamZeroData AS DWORD _             ' __in CONST void* pVertexStreamZeroData
   , BYVAL VertexStreamZeroStride AS DWORD _            ' __in UINT VertexStreamZeroStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawIndexedPrimitiveUP ( _                    ' VTable offset = 336
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL MinVertexIndex AS DWORD _                    ' __in UINT MinVertexIndex
   , BYVAL NumVertices AS DWORD _                       ' __in UINT NumVertices
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   , BYVAL pIndexData AS DWORD _                        ' __in CONST void* pIndexData
   , BYVAL IndexDataFormat AS DWORD _                   ' __in D3DFORMAT IndexDataFormat
   , BYVAL pVertexStreamZeroData AS DWORD _             ' __in CONST void* pVertexStreamZeroData
   , BYVAL VertexStreamZeroStride AS DWORD _            ' __in UINT VertexStreamZeroStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessVertices ( _                           ' VTable offset = 340
     BYVAL SrcStartIndex AS DWORD _                     ' __in UINT SrcStartIndex
   , BYVAL DestIndex AS DWORD _                         ' __in UINT DestIndex
   , BYVAL VertexCount AS DWORD _                       ' __in UINT VertexCount
   , BYVAL pDestBuffer AS IDirect3DVertexBuffer9 _      ' __in IDirect3DVertexBuffer9* pDestBuffer
   , BYVAL pVertexDecl AS IDirect3DVertexDeclaration9 _ ' __in IDirect3DVertexDeclaration9* pVertexDecl
   , BYVAL DWORD _                                      ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexDeclaration ( _                   ' VTable offset = 344
     BYREF pVertexElements AS D3DVERTEXELEMENT9 _       ' __in  CONST D3DVERTEXELEMENT9* pVertexElements
   , BYREF ppDecl AS IDirect3DVertexDeclaration9 _      ' __out IDirect3DVertexDeclaration9** ppDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexDeclaration ( _                      ' VTable offset = 348
     BYVAL pDecl AS IDirect3DVertexDeclaration9 _       ' __in IDirect3DVertexDeclaration9* pDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexDeclaration ( _                      ' VTable offset = 352
     BYREF ppDecl AS IDirect3DVertexDeclaration9 _      ' __in IDirect3DVertexDeclaration9** ppDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFVF ( _                                    ' VTable offset = 356
     BYVAL FVF AS DWORD _                               ' __in DWORD FVF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 360
     BYREF pFVF AS DWORD _                              ' __out DWORD* pFVF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexShader ( _                        ' VTable offset = 364
     BYVAL pFunction AS DWORD _                         ' __in  CONST DWORD* pFunction
   , BYREF ppShader AS IDirect3DVertexShader9 _         ' __out IDirect3DVertexShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShader ( _                           ' VTable offset = 368
     BYVAL pShader AS IDirect3DVertexShader9 _          ' __in IDirect3DVertexShader9* pShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShader ( _                           ' VTable offset = 372
     BYREF ppShader AS IDirect3DVertexShader9 _         ' __out IDirect3DVertexShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantF ( _                  ' VTable offset = 376
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in CONST float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantF ( _                  ' VTable offset = 380
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in_out float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantI ( _                  ' VTable offset = 384
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantI ( _                  ' VTable offset = 388
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out int* pConstantData
   , BYVAL VectorifCount AS DWORD _                     ' __in UINT VectorifCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantB ( _                  ' VTable offset = 392
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantB ( _                  ' VTable offset = 396
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSource ( _                           ' VTable offset = 400
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL pStreamData AS IDirect3DVertexBuffer9 _      ' __in IDirect3DVertexBuffer9* pStreamData
   , BYVAL OffsetInBytes AS DWORD _                     ' __in UINT OffsetInBytes
   , BYVAL Stride AS DWORD _                            ' __in UINT Stride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSource ( _                           ' VTable offset = 404
     BYVAL StreamNumber AS DWORD _                      ' __in  UINT StreamNumber
   , BYREF ppStreamData AS IDirect3DVertexBuffer9 _     ' __out IDirect3DVertexBuffer9** ppStreamData
   , BYREF OffsetInBytes AS DWORD _                     ' __out UINT * OffsetInBytes
   , BYREF Stride AS DWORD _                            ' __out UINT * Stride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSourceFreq ( _                       ' VTable offset = 408
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL Setting AS DWORD _                           ' __in UINT Setting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSourceFreq ( _                       ' VTable offset = 412
     BYVAL StreamNumber AS DWORD _                      ' __in  UINT StreamNumber
   , BYREF pSetting AS DWORD _                          ' __out UINT* pSetting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndices ( _                                ' VTable offset = 416
     BYVAL pIndexData AS IDirect3DIndexBuffer9 _        ' __in IDirect3DIndexBuffer9* pIndexData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndices ( _                                ' VTable offset = 420
     BYREF ppIndexData AS IDirect3DIndexBuffer9 _       ' __out IDirect3DIndexBuffer9** ppIndexData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePixelShader ( _                         ' VTable offset = 424
     BYVAL pFunction AS DWORD _                         ' __in  CONST DWORD* pFunction
   , BYREF ppShader AS IDirect3DPixelShader9 _          ' __out IDirect3DPixelShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShader ( _                            ' VTable offset = 428
     BYVAL pShader AS IDirect3DPixelShader9 _           ' __in IDirect3DPixelShader9* pShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShader ( _                            ' VTable offset = 432
     BYREF ppShader AS IDirect3DPixelShader9 _          ' __out IDirect3DPixelShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantF ( _                   ' VTable offset = 436
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in CONST float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantF ( _                   ' VTable offset = 440
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in_out float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantI ( _                   ' VTable offset = 444
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantI ( _                   ' VTable offset = 448
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantB ( _                   ' VTable offset = 452
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantB ( _                   ' VTable offset = 456
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawRectPatch ( _                             ' VTable offset = 460
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   , BYREF pNumSegs AS SINGLE _                         ' __in CONST float* pNumSegs
   , BYREF pRectPatchInfo AS D3DRECTPATCH_INFO _        ' __in CONST D3DRECTPATCH_INFO* pRectPatchInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawTriPatch ( _                              ' VTable offset = 464
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   , BYREF pNumSegs AS SINGLE _                         ' __in CONST float* pNumSegs
   , BYREF pTriPatchInfo AS D3DTRIPATCH_INFO _          ' __in CONST D3DRECTPATCH_INFO* pTriPatchInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePatch ( _                               ' VTable offset = 468
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQuery ( _                               ' VTable offset = 472
     BYVAL Type AS DWORD _                              ' __in  D3DQUERYTYPE Type
   , BYREF ppQuery AS IDirect3DQuery9 _                 ' __out IDirect3DQuery9** ppQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DStateBlock9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DStateBlock9 $IID_IDirect3DStateBlock9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Capture ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Apply ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DSwapChain9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DSwapChain9 $IID_IDirect3DSwapChain9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Present ( _                                   ' VTable offset = 12
     BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL hDestWindowOverride AS DWORD _               ' __in HWND hDestWindowOverride
   , BYREF pDirtyRegion AS RGNDATA _                    ' __in CONST RGNDATA* pDirtyRegion
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrontBufferData ( _                        ' VTable offset = 16
     BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in_out IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackBuffer ( _                             ' VTable offset = 20
     BYVAL iBackBuffer AS DWORD _                       ' __in  UINT iBackBuffer
   , BYVAL Type AS DWORD _                              ' __in  D3DBACKBUFFER_TYPE Type
   , BYREF ppBackBuffer AS IDirect3DSurface9 _          ' __out IDirect3DSurface9** ppBackBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRasterStatus ( _                           ' VTable offset = 24
     BYREF pRasterStatus AS D3DRASTER_STATUS _          ' __out D3DRASTER_STATUS* pRasterStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 28
     BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 32
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentParameters ( _                      ' VTable offset = 36
     BYREF pPresentationParameters As D3DPRESENT_PARAMETERS _ ' __out D3DPRESENT_PARAMETERS* pPresentationParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DResource9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DResource9 $IID_IDirect3DResource9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DVertexDeclaration9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DVertexDeclaration9 $IID_IDirect3DVertexDeclaration9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 16
     BYREF pElement AS D3DVERTEXELEMENT9 _              ' __in_out D3DVERTEXELEMENT9* pElement
   , BYREF pNumElements AS DWORD _                      ' __out UINT* pNumElements
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DVertexShader9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DVertexShader9 $IID_IDirect3DVertexShader9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 16
     BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out UINT* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DPixelShader9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DPixelShader9 $IID_IDirect3DPixelShader9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 16
     BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out UINT* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DBaseTexture9
' Inherited interface = IDirect3DResource9
' ########################################################################################

INTERFACE IDirect3DBaseTexture9 $IID_IDirect3DBaseTexture9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DBaseTexture9 methods
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 44
     BYVAL LODNew AS DWORD _                            ' __in LODNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 48
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLevelCount ( _                             ' VTable offset = 52
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD SetAutoGenFilterType ( _                      ' VTable offset = 56
     BYVAL FilterType AS DWORD _                        ' __in D3DTEXTUREFILTERTYPE FilterType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoGenFilterType ( _                      ' VTable offset = 60
   ) AS DWORD                                           ' D3DTEXTUREFILTERTYPE
   ' =====================================================================================
   METHOD GenerateMipSubLevels ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DTexture9
' Inherited interface = IDirect3DBaseTexture9
' ########################################################################################

INTERFACE IDirect3DTexture9 $IID_IDirect3DTexture9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DBaseTexture9 methods
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 44
     BYVAL LODNew AS DWORD _                            ' __in LODNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 48
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLevelCount ( _                             ' VTable offset = 52
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD SetAutoGenFilterType ( _                      ' VTable offset = 56
     BYVAL FilterType AS DWORD _                        ' __in D3DTEXTUREFILTERTYPE FilterType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoGenFilterType ( _                      ' VTable offset = 60
   ) AS DWORD                                           ' D3DTEXTUREFILTERTYPE
   ' =====================================================================================
   METHOD GenerateMipSubLevels ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DTexture9 methods
   ' =====================================================================================
   METHOD GetLevelDesc ( _                              ' VTable offset = 68
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pDesc AS D3DSURFACE_DESC _                   ' __out D3DSURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceLevel ( _                           ' VTable offset = 72
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF ppSurfaceLevel AS IDirect3DSurface9 _        ' __out IDirect3DSurface9** ppSurfaceLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRect ( _                                  ' VTable offset = 76
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pLockedRect AS D3DLOCKED_RECT _              ' __out D3DLOCKED_RECT * pLockedRect
   , BYREF pRect AS RECT _                              ' __in  CONST RECT* pRect
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRect ( _                                ' VTable offset = 80
     BYVAL Level AS DWORD _                             ' __in UINT Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDirtyRect ( _                              ' VTable offset = 84
     BYREF pDirtyRect AS RECT _                         ' __in CONST RECT* pDirtyRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DVolumeTexture9
' Inherited interface = IDirect3DBaseTexture9
' ########################################################################################

INTERFACE IDirect3DVolumeTexture9 $IID_IDirect3DVolumeTexture9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DBaseTexture9 methods
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 44
     BYVAL LODNew AS DWORD _                            ' __in LODNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 48
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLevelCount ( _                             ' VTable offset = 52
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD SetAutoGenFilterType ( _                      ' VTable offset = 56
     BYVAL FilterType AS DWORD _                        ' __in D3DTEXTUREFILTERTYPE FilterType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoGenFilterType ( _                      ' VTable offset = 60
   ) AS DWORD                                           ' D3DTEXTUREFILTERTYPE
   ' =====================================================================================
   METHOD GenerateMipSubLevels ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DVolumeTexture9 methods
   ' =====================================================================================
   METHOD GetLevelDesc ( _                              ' VTable offset = 68
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pDesc AS D3DVOLUME_DESC _                    ' __out D3DVOLUME_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeLevel ( _                            ' VTable offset = 72
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF ppVolumeLevel AS IDirect3DVolume9 _          ' __out IDirect3DVolume9** ppVolumeLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockBox ( _                                   ' VTable offset = 76
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pLockedVolume AS D3DLOCKED_BOX _             ' __out D3DLOCKED_BOX* pLockedVolume
   , BYREF pBox AS D3DBOX _                             ' __in  CONST D3DBOX* pBox
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBox ( _                                 ' VTable offset = 80
     BYVAL Level AS DWORD _                             ' __in UINT Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDirtyBox ( _                               ' VTable offset = 84
     BYREF pDirtyBox AS D3DBOX _                        ' __in CONST D3DBOX* pDirtyBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DCubeTexture9
' Inherited interface = IDirect3DBaseTexture9
' ########################################################################################

INTERFACE IDirect3DCubeTexture9 $IID_IDirect3DCubeTexture9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DBaseTexture9 methods
   ' =====================================================================================
   METHOD SetLOD ( _                                    ' VTable offset = 44
     BYVAL LODNew AS DWORD _                            ' __in LODNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLOD ( _                                    ' VTable offset = 48
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetLevelCount ( _                             ' VTable offset = 52
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD SetAutoGenFilterType ( _                      ' VTable offset = 56
     BYVAL FilterType AS DWORD _                        ' __in D3DTEXTUREFILTERTYPE FilterType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoGenFilterType ( _                      ' VTable offset = 60
   ) AS DWORD                                           ' D3DTEXTUREFILTERTYPE
   ' =====================================================================================
   METHOD GenerateMipSubLevels ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DCubeTexture9 methods
   ' =====================================================================================
   METHOD GetLevelDesc ( _                              ' VTable offset = 68
     BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pDesc AS D3DSURFACE_DESC _                   ' __out D3DSURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCubeMapSurface ( _                         ' VTable offset = 72
     BYVAL FaceType AS DWORD _                          ' __in  D3DCUBEMAP_FACES FaceType
   , BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF ppCubeMapSurface AS IDirect3DSurface9 _      ' __out IDirect3DSurface9** ppCubeMapSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRect ( _                                  ' VTable offset = 76
     BYVAL FaceType AS DWORD _                          ' __in  D3DCUBEMAP_FACES FaceType
   , BYVAL Level AS DWORD _                             ' __in  UINT Level
   , BYREF pLockedRect AS D3DLOCKED_RECT _              ' __out D3DLOCKED_RECT* pLockedRect
   , BYREF pRect AS RECT _                              ' __in  CONST RECT* pRect
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRect ( _                                ' VTable offset = 80
     BYVAL FaceType AS DWORD _                          ' __in D3DCUBEMAP_FACES FaceType
   , BYVAL Level AS DWORD _                             ' __in UINT Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDirtyRect ( _                              ' VTable offset = 84
     BYVAL FaceType AS DWORD _                          ' __in D3DCUBEMAP_FACES FaceType
   , BYREF pDirtyRect AS RECT _                         ' __in CONST RECT* pDirtyRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DVertexBuffer9
' Inherited interface = IDirect3DResource9
' ########################################################################################

INTERFACE IDirect3DVertexBuffer9 $IID_IDirect3DVertexBuffer9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DVertexBuffer9 methods
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 44
     BYVAL OffsetToLock AS DWORD _                      ' __in  UINT OffsetToLock
   , BYVAL SizeToLock AS DWORD _                        ' __in  UINT SizeToLock
   , BYREF ppbData AS DWORD _                           ' __out void** ppbData
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 52
     BYREF pDesc AS D3DVERTEXBUFFER_DESC _              ' __out D3DVERTEXBUFFER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DIndexBuffer9
' Inherited interface = IDirect3DResource9
' ########################################################################################

INTERFACE IDirect3DIndexBuffer9 $IID_IDirect3DIndexBuffer9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DIndexBuffer9 methods
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 44
     BYVAL OffsetToLock AS DWORD _                      ' __in  UINT OffsetToLock
   , BYVAL SizeToLock AS DWORD _                        ' __in  UINT SizeToLock
   , BYREF ppbData AS DWORD _                           ' __out void** ppbData
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 52
     BYREF pDesc AS D3DINDEXBUFFER_DESC _               ' __in D3DINDEXBUFFER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DSurface9
' Inherited interface = IDirect3DResource9
' ########################################################################################

INTERFACE IDirect3DSurface9 $IID_IDirect3DSurface9

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DResource9 methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 28
     BYVAL PriorityNew AS DWORD _                       ' __in DWORD PriorityNew
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD PreLoad ( _                                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 40
   ) AS DWORD                                           ' D3DRESOURCETYPE
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DSurface9 methods
   ' =====================================================================================
   METHOD GetContainer ( _                              ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppContainer AS DWORD _                       ' __out void** ppContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS D3DSURFACE_DESC _                   ' __out D3DSURFACE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRect ( _                                  ' VTable offset = 52
     BYREF pLockedRect AS D3DLOCKED_RECT _              ' __out D3DLOCKED_RECT* pLockedRect
   , BYREF pRect AS RECT _                              ' __in  CONST RECT* pRect
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRect ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 60
     BYREF phdc AS DWORD _                              ' __out HDC *phdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDC ( _                                 ' VTable offset = 64
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DVolume9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DVolume9 $IID_IDirect3DVolume9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 16
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in CONST void* pData
   , BYVAL SizeOfData AS DWORD _                        ' __in DWORD SizeOfData
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 20
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   , BYVAL pData AS DWORD _                             ' __in_out void* pData
   , BYREF pSizeOfData AS DWORD _                       ' __in_out DWORD* pSizeOfData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreePrivateData ( _                           ' VTable offset = 24
     BYREF refguid AS GUID _                            ' __in REFGUID refguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainer ( _                              ' VTable offset = 28
     BYREF refguid AS GUID _                            ' __in  REFGUID refguid
   , BYREF ppContainer AS DWORD _                       ' __out void** ppContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS D3DVOLUME_DESC _                    ' __out D3DVOLUME_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockBox ( _                                   ' VTable offset = 36
     BYREF pLockedVolume AS D3DLOCKED_BOX _             ' __out D3DLOCKED_BOX * pLockedVolume
   , BYREF pBox AS D3DBOX _                             ' __in  CONST D3DBOX* pBox
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBox ( _                                 ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DQuery9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DQuery9 $IID_IDirect3DQuery9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
   ) AS DWORD                                           ' D3DQUERYTYPE
   ' =====================================================================================
   METHOD GetDataSize ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD Issue ( _                                     ' VTable offset = 24
     BYVAL dwIssueFlags AS DWORD _                      ' __in DWORD dwIssueFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 28
     BYVAL pData AS DWORD _                             ' __in_ou void* pData
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL dwGetDataFlags AS DWORD _                    ' __in DWORD dwGetDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/****************************************************************************
' * Flags for SetPrivateData method on all D3D9 interfaces
' *
' * The passed pointer is an IUnknown ptr. The SizeOfData argument to SetPrivateData
' * must be set to sizeof(IUnknown*). Direct3D will call AddRef through this
' * pointer and Release when the private data is destroyed. The data will be
' * destroyed when another SetPrivateData with the same GUID is set, when
' * FreePrivateData is called, or when the D3D9 object is freed.
' ****************************************************************************/
%D3DSPD_IUNKNOWN                        = &H00000001???

'/****************************************************************************
' *
' * Flags for IDirect3D9::CreateDevice's BehaviorFlags
' *
' ****************************************************************************/

%D3DCREATE_FPU_PRESERVE                 = &H00000002???
%D3DCREATE_MULTITHREADED                = &H00000004???

%D3DCREATE_PUREDEVICE                   = &H00000010???
%D3DCREATE_SOFTWARE_VERTEXPROCESSING    = &H00000020???
%D3DCREATE_HARDWARE_VERTEXPROCESSING    = &H00000040???
%D3DCREATE_MIXED_VERTEXPROCESSING       = &H00000080???

%D3DCREATE_DISABLE_DRIVER_MANAGEMENT    = &H00000100???
%D3DCREATE_ADAPTERGROUP_DEVICE          = &H00000200???
%D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX = &H00000400???

'// This flag causes the D3D runtime not to alter the focus
'// window in any way. Use with caution- the burden of supporting
'// focus management events (alt-tab, etc.) falls on the
'// application, and appropriate responses (switching display
'// mode, etc.) should be coded.

%D3DCREATE_NOWINDOWCHANGES              = &H00000800???

'/* D3D9Ex only -- */
'// Disable multithreading for software vertex processing
%D3DCREATE_DISABLE_PSGP_THREADING       = &H00002000???
'// This flag enables present statistics on device.
%D3DCREATE_ENABLE_PRESENTSTATS          = &H00004000???
'// This flag disables printscreen support in the runtime for this device
%D3DCREATE_DISABLE_PRINTSCREEN          = &H00008000???

%D3DCREATE_SCREENSAVER                  = &H10000000???
'/* -- D3D9Ex only */


'/****************************************************************************
' *
' * Parameter for IDirect3D9::CreateDevice's Adapter argument
' *
' ****************************************************************************/

%D3DADAPTER_DEFAULT                     = 0

'/****************************************************************************
' *
' * Flags for IDirect3D9::EnumAdapters
' *
' ****************************************************************************/

%D3DENUM_WHQL_LEVEL                     = &H00000002???

'/* D3D9Ex only -- */
'/* NO_DRIVERVERSION will not fill out the DriverVersion field, nor will the
'   DriverVersion be incorporated into the DeviceIdentifier GUID. WINNT only */
%D3DENUM_NO_DRIVERVERSION               = &H00000004???
'/* -- D3D9Ex only */

'/****************************************************************************
' *
' * Maximum number of back-buffers supported in DX9
' *
' ****************************************************************************/

%D3DPRESENT_BACK_BUFFERS_MAX            = 3???

'/* D3D9Ex only -- */
'/****************************************************************************
' *
' * Maximum number of back-buffers supported when apps use CreateDeviceEx
' *
' ****************************************************************************/
%D3DPRESENT_BACK_BUFFERS_MAX_EX         = 30???
'/* -- D3D9Ex only */

'/****************************************************************************
' *
' * Flags for IDirect3DDevice9::SetGammaRamp
' *
' ****************************************************************************/

%D3DSGR_NO_CALIBRATION                  = &H00000000???
%D3DSGR_CALIBRATE                       = &H00000001???

'/****************************************************************************
' *
' * Flags for IDirect3DDevice9::SetCursorPosition
' *
' ****************************************************************************/

%D3DCURSOR_IMMEDIATE_UPDATE             = &H00000001???

'/****************************************************************************
' *
' * Flags for IDirect3DSwapChain9::Present
' *
' ****************************************************************************/

%D3DPRESENT_DONOTWAIT                   = &H00000001???
%D3DPRESENT_LINEAR_CONTENT              = &H00000002???

'/* D3D9Ex only -- */
%D3DPRESENT_DONOTFLIP                   = &H00000004???
%D3DPRESENT_FLIPRESTART                 = &H00000008???
%D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR   = &H00000010???
%D3DPRESENT_UPDATEOVERLAYONLY           = &H00000020???
%D3DPRESENT_HIDEOVERLAY                 = &H00000040???
%D3DPRESENT_UPDATECOLORKEY              = &H00000080???
%D3DPRESENT_FORCEIMMEDIATE              = &H00000100???
'/* -- D3D9Ex only */

'/****************************************************************************
' *
' * Flags for DrawPrimitive/DrawIndexedPrimitive
' *   Also valid for Begin/BeginIndexed
' *   Also valid for VertexBuffer::CreateVertexBuffer
' ****************************************************************************/

'/*
' *  DirectDraw error codes
' */
%FACD3D  = &H876
'#define MAKE_D3DHRESULT( code )  MAKE_HRESULT( 1, _FACD3D, code )
'#define MAKE_D3DSTATUS( code )  MAKE_HRESULT( 0, _FACD3D, code )

FUNCTION MAKE_D3DHRESULT (BYVAL dwCode AS DWORD) AS LONG
   FUNCTION = MAKE_HRESULT(1, %FACD3D, dwCode)
END FUNCTION

FUNCTION MAKE_D3DSTATUS (BYVAL dwCode AS DWORD) AS LONG
   FUNCTION = MAKE_HRESULT(0, %FACD3D, dwCode)
END FUNCTION

'%MAKE_D3DHRESULT                      = &H88760000  ' (-2005532672)
'%MAKE_D3DSTATUS                       = &H08760000  ' (141950976)

'/*
' * Direct3D Errors
' */
%D3D_OK                             = %S_OK

'#define D3DERR_WRONGTEXTUREFORMAT               MAKE_D3DHRESULT(2072)
'#define D3DERR_UNSUPPORTEDCOLOROPERATION        MAKE_D3DHRESULT(2073)
'#define D3DERR_UNSUPPORTEDCOLORARG              MAKE_D3DHRESULT(2074)
'#define D3DERR_UNSUPPORTEDALPHAOPERATION        MAKE_D3DHRESULT(2075)
'#define D3DERR_UNSUPPORTEDALPHAARG              MAKE_D3DHRESULT(2076)
'#define D3DERR_TOOMANYOPERATIONS                MAKE_D3DHRESULT(2077)
'#define D3DERR_CONFLICTINGTEXTUREFILTER         MAKE_D3DHRESULT(2078)
'#define D3DERR_UNSUPPORTEDFACTORVALUE           MAKE_D3DHRESULT(2079)
'#define D3DERR_CONFLICTINGRENDERSTATE           MAKE_D3DHRESULT(2081)
'#define D3DERR_UNSUPPORTEDTEXTUREFILTER         MAKE_D3DHRESULT(2082)
'#define D3DERR_CONFLICTINGTEXTUREPALETTE        MAKE_D3DHRESULT(2086)
'#define D3DERR_DRIVERINTERNALERROR              MAKE_D3DHRESULT(2087)

%D3DERR_WRONGTEXTUREFORMAT        = &H88760818&   ' (-2005530600)
%D3DERR_UNSUPPORTEDCOLOROPERATION = &H88760819&   ' (-2005530599)
%D3DERR_UNSUPPORTEDCOLORARG       = &H8876081A&   ' (-2005530598)
%D3DERR_UNSUPPORTEDALPHAOPERATION = &H8876081B&   ' (-2005530597)
%D3DERR_UNSUPPORTEDALPHAARG       = &H8876081C&   ' (-2005530596)
%D3DERR_TOOMANYOPERATIONS         = &H8876081D&   ' (-2005530595)
%D3DERR_CONFLICTINGTEXTUREFILTER  = &H8876081E&   ' (-2005530594)
%D3DERR_UNSUPPORTEDFACTORVALUE    = &H8876081F&   ' (-2005530593)
%D3DERR_CONFLICTINGRENDERSTATE    = &H88760821&   ' (-2005530591)
%D3DERR_UNSUPPORTEDTEXTUREFILTER  = &H88760822&   ' (-2005530590)
%D3DERR_CONFLICTINGTEXTUREPALETTE = &H88760826&   ' (-2005530586)
%D3DERR_DRIVERINTERNALERROR       = &H88760827&   ' (-2005530585)

'#define D3DERR_NOTFOUND                         MAKE_D3DHRESULT(2150)
'#define D3DERR_MOREDATA                         MAKE_D3DHRESULT(2151)
'#define D3DERR_DEVICELOST                       MAKE_D3DHRESULT(2152)
'#define D3DERR_DEVICENOTRESET                   MAKE_D3DHRESULT(2153)
'#define D3DERR_NOTAVAILABLE                     MAKE_D3DHRESULT(2154)
'#define D3DERR_OUTOFVIDEOMEMORY                 MAKE_D3DHRESULT(380)
'#define D3DERR_INVALIDDEVICE                    MAKE_D3DHRESULT(2155)
'#define D3DERR_INVALIDCALL                      MAKE_D3DHRESULT(2156)
'#define D3DERR_DRIVERINVALIDCALL                MAKE_D3DHRESULT(2157)
'#define D3DERR_WASSTILLDRAWING                  MAKE_D3DHRESULT(540)
'#define D3DOK_NOAUTOGEN                         MAKE_D3DSTATUS(2159)

%D3DERR_NOTFOUND          = &H88760866&   ' (-2005530522)
%D3DERR_MOREDATA          = &H88760867&   ' (-2005530521)
%D3DERR_DEVICELOST        = &H88760868&   ' (-2005530520)
%D3DERR_DEVICENOTRESET    = &H88760869&   ' (-2005530519)
%D3DERR_NOTAVAILABLE      = &H8876086A&   ' (-2005530518)
%D3DERR_OUTOFVIDEOMEMORY  = &H8876017C&   ' (-2005532292)
%D3DERR_INVALIDDEVICE     = &H8876086B&   ' (-2005530517)
%D3DERR_INVALIDCALL       = &H8876086C&   ' (-2005530516)
%D3DERR_DRIVERINVALIDCALL = &H8876086D&   ' (-2005530515)
%D3DERR_WASSTILLDRAWING   = &H8876021C&   ' (-2005532132)
%D3DOK_NOAUTOGEN          = &H0876086F&   ' (141953135)

'/* D3D9Ex only -- */
'#define D3DERR_DEVICEREMOVED                    MAKE_D3DHRESULT(2160)
'#define S_NOT_RESIDENT                          MAKE_D3DSTATUS(2165)
'#define S_RESIDENT_IN_SHARED_MEMORY             MAKE_D3DSTATUS(2166)
'#define S_PRESENT_MODE_CHANGED                  MAKE_D3DSTATUS(2167)
'#define S_PRESENT_OCCLUDED                      MAKE_D3DSTATUS(2168)
'#define D3DERR_DEVICEHUNG                       MAKE_D3DHRESULT(2164)
'#define D3DERR_UNSUPPORTEDOVERLAY               MAKE_D3DHRESULT(2171)
'#define D3DERR_UNSUPPORTEDOVERLAYFORMAT         MAKE_D3DHRESULT(2172)
'#define D3DERR_CANNOTPROTECTCONTENT             MAKE_D3DHRESULT(2173)
'#define D3DERR_UNSUPPORTEDCRYPTO                MAKE_D3DHRESULT(2174)
'#define D3DERR_PRESENT_STATISTICS_DISJOINT      MAKE_D3DHRESULT(2180)

%D3DERR_DEVICEREMOVED               = &H88760870&   ' (-2005530512)
%S_NOT_RESIDENT                     = &H08760875&   ' (-2005530507)
%S_RESIDENT_IN_SHARED_MEMORY        = &H08760876&   ' (-2005530506)
%S_PRESENT_MODE_CHANGED             = &H08760877&   ' (-2005530505)
%S_PRESENT_OCCLUDED                 = &H08760878&   ' (-2005530504)
%D3DERR_DEVICEHUNG                  = &H88760874&   ' (-2005530508)
%D3DERR_UNSUPPORTEDOVERLAY          = &H8876087B&   ' (-2005530501)
%D3DERR_UNSUPPORTEDOVERLAYFORMAT    = &H8876087C&   ' (-2005530500)
%D3DERR_CANNOTPROTECTCONTENT        = &H8876087D&   ' (-2005530499)
%D3DERR_UNSUPPORTEDCRYPTO           = &H8876087E&   ' (-2005530498)
%D3DERR_PRESENT_STATISTICS_DISJOINT = &H88760884&   ' (-2005530492)


'/*********************
'/* D3D9Ex interfaces
'/*********************/

DECLARE FUNCTION Direct3DCreate9Ex IMPORT "D3D9.DLL" ALIAS "Direct3DCreate9Ex" ( _
   BYVAL SDKVersion AS DWORD _                          ' UINT SDKVersion
 , BYREF ppD3D AS IDirect3D9EX _                        ' IDirect3D9EX **ppD3D
 ) AS LONG                                              ' HRESULT

' ########################################################################################
' Interface name = IDirect3D9Ex
' Inherited interface = IDirect3D9
' ########################################################################################

INTERFACE IDirect3D9Ex $IID_IDirect3D9Ex

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3D9 methods
   ' =====================================================================================
   METHOD RegisterSoftwareDevice ( _                    ' VTable offset = 12
     BYVAL pInitializeFunction AS DWORD _               ' __in void* pInitializeFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterCount ( _                           ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAdapterIdentifier ( _                      ' VTable offset = 20
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pIdentifier AS D3DADAPTER_IDENTIFIER9 _      ' __out D3DADAPTER_IDENTIFIER9* pIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterModeCount ( _                       ' VTable offset = 24
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL Format AS DWORD _                            ' __in D3DFORMAT Format
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD EnumAdapterModes ( _                          ' VTable offset = 28
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Mode AS DWORD _                              ' __in  UINT Mode
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterDisplayMode ( _                     ' VTable offset = 32
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __in_out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceType ( _                           ' VTable offset = 36
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DevType AS DWORD _                           ' __in D3DDEVTYPE DevType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL BackBufferFormat AS DWORD _                  ' __in D3DFORMAT BackBufferFormat
   , BYVAL bWindowed AS LONG _                          ' __in BOOL bWindowed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceFormat ( _                         ' VTable offset = 40
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DevType AS DWORD _                           ' __in D3DDEVTYPE DevType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL Usage AS DWORD _                             ' __in DWORD Usage
   , BYVAL RType AS DWORD _                             ' __in D3DRESOURCETYPE RType
   , BYVAL CheckFormat AS DWORD _                       ' __in D3DFORMAT CheckFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceMultiSampleType ( _                ' VTable offset = 44
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYVAL SurfaceFormat AS DWORD _                     ' __in  D3DFORMAT SurfaceFormat
   , BYVAL Windowed AS LONG _                           ' __in  BOOL Windowed
   , BYVAL MultiSampleType AS DWORD _                   ' __in  D3DMULTISAMPLE_TYPE MultiSampleType
   , BYREF pQualityLevels AS DWORD _                    ' __out DWORD* pQualityLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDepthStencilMatch ( _                    ' VTable offset = 48
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in D3DDEVTYPE DeviceType
   , BYVAL AdapterFormat AS DWORD _                     ' __in D3DFORMAT AdapterFormat
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYVAL DepthStencilFormat AS DWORD _                ' __in D3DFORMAT DepthStencilFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceFormatConversion ( _               ' VTable offset = 52
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in D3DDEVTYPE DeviceType
   , BYVAL SourceFormat AS DWORD _                      ' __in D3DFORMAT SourceFormat
   , BYVAL TargetFormat AS DWORD _                      ' __in D3DFORMAT TargetFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceCaps ( _                             ' VTable offset = 56
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYREF pCaps AS D3DCAPS9 _                          ' __out D3DCAPS9* pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterMonitor ( _                         ' VTable offset = 60
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   ) AS DWORD                                           ' HMONITOR
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 64
     BYVAL Adapter AS DWORD _                           ' __in  UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in  D3DDEVTYPE DeviceType
   , BYVAL hFocusWindow AS DWORD _                      ' __in  HWND hFocusWindow
   , BYVAL BehaviorFlags AS DWORD _                     ' __in  DWORD BehaviorFlags
   , BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in  D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF ppReturnedDeviceInterface AS IDirect3DDevice9 _ ' __out IDirect3DDevice9** ppReturnedDeviceInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3D9Ex methods
   ' =====================================================================================
   METHOD GetAdapterModeCountEx ( _                     ' VTable offset = 68
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pFilter AS D3DDISPLAYMODEFILTER _            ' __in CONST D3DDISPLAYMODEFILTER* pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAdapterModesEx ( _                        ' VTable offset = 72
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pFilter AS D3DDISPLAYMODEFILTER _            ' __in CONST D3DDISPLAYMODEFILTER* pFilter
   , BYVAL Mode AS DWORD _                              ' __in UINT Mode
   , BYREF pMode AS D3DDISPLAYMODEEX _                  ' __out D3DDISPLAYMODEEX* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterDisplayModeEx ( _                   ' VTable offset = 76
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pMode AS D3DDISPLAYMODEEX _                  ' __in_out D3DDISPLAYMODEEX * pMode
   , BYREF pRotation AS DWORD _                         ' __in_out D3DDISPLAYROTATION * pRotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDeviceEx ( _                            ' VTable offset = 80
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DeviceType AS DWORD _                        ' __in D3DDEVTYPE DeviceType
   , BYVAL hFocusWindow AS DWORD _                      ' __in HWND hFocusWindow
   , BYVAL BehaviorFlags AS DWORD _                     ' __in DWORD BehaviorFlags
   , BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in_out D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF pFullscreenDisplayMode AS D3DDISPLAYMODEEX _ ' __in_out D3DDISPLAYMODEEX *pFullscreenDisplayMode
   , BYREF ppReturnedDeviceInterface AS IDirect3DDevice9Ex _ ' __out IDirect3DDevice9Ex **ppReturnedDeviceInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterLUID ( _                            ' VTable offset = 84
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYREF pLUID AS LUID _                              ' __in LUID *pLUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DDevice9Ex
' Inherited interface = IDirect3DDevice9
' ########################################################################################

INTERFACE IDirect3DDevice9Ex $IID_IDirect3DDevice9Ex

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DDevice9 methods
   ' =====================================================================================
   METHOD TestCooperativeLevel ( _                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableTextureMem ( _                    ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD EvictManagedResources ( _                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirect3D ( _                               ' VTable offset = 24
     BYREF ppD3D9 AS IDirect3D9 _                       ' __out IDirect3D9** ppD3D9
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceCaps ( _                             ' VTable offset = 28
     BYREF pCaps AS D3DCAPS9 _                          ' __out D3DCAPS9* pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 32
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationParameters ( _                     ' VTable offset = 36
     BYREF pParameters AS D3DDEVICE_CREATION_PARAMETERS _ ' __out D3DDEVICE_CREATION_PARAMETERS *pParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCursorProperties ( _                       ' VTable offset = 40
     BYVAL XHotSpot AS DWORD _                          ' __in UINT XHotSpot
   , BYVAL YHotSpot AS DWORD _                          ' __in UINT YHotSpot
   , BYVAL pCursorBitmap AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pCursorBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCursorPosition ( _                         ' VTable offset = 44
     BYVAL X AS LONG _                                  ' __in int X
   , BYVAL Y AS LONG _                                  ' __in int Y
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowCursor ( _                                ' VTable offset = 48
     BYVAL bShow AS LONG _                              ' __in BOOL bShow
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD CreateAdditionalSwapChain ( _                 ' VTable offset = 52
     BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in_out D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF pSwapChain AS IDirect3DSwapChain9 _          ' __out IDirect3DSwapChain9** pSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSwapChain ( _                              ' VTable offset = 56
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYREF pSwapChain AS IDirect3DSwapChain9 _          ' __out IDirect3DSwapChain9** pSwapChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfSwapChains ( _                     ' VTable offset = 60
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 64
     BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in D3DPRESENT_PARAMETERS* pPresentationParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Present ( _                                   ' VTable offset = 68
     BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL hDestWindowOverride AS DWORD _               ' __in HWND hDestWindowOverride
   , BYREF pDirtyRegion AS RGNDATA _                    ' __in CONST RGNDATA* pDirtyRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackBuffer ( _                             ' VTable offset = 72
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYVAL iBackBuffer AS DWORD _                       ' __in  UINT iBackBuffer
   , BYVAL Type AS DWORD _                              ' __in  D3DBACKBUFFER_TYPE Type
   , BYREF ppBackBuffer AS IDirect3DSurface9 _          ' __out IDirect3DSurface9** ppBackBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRasterStatus ( _                           ' VTable offset = 76
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYREF pRasterStatus AS D3DRASTER_STATUS _          ' __out D3DRASTER_STATUS* pRasterStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDialogBoxMode ( _                          ' VTable offset = 80
     BYVAL bEnableDialogs AS LONG _                     ' __in BOOL bEnableDialogs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGammaRamp ( _                              ' VTable offset = 84
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF pRamp AS D3DGAMMARAMP _                      ' __in CONST D3DGAMMARAMP* pRamp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGammaRamp ( _                              ' VTable offset = 88
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYREF pRamp AS D3DGAMMARAMP _                      ' __in_out CONST D3DGAMMARAMP* pRamp
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTexture ( _                             ' VTable offset = 92
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppTexture AS IDirect3DTexture9 _             ' __out IDirect3DTexture9** ppTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVolumeTexture ( _                       ' VTable offset = 96
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Depth AS DWORD _                             ' __in  UINT Depth
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _ ' __out IDirect3DVolumeTexture9** ppVolumeTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCubeTexture ( _                         ' VTable offset = 100
     BYVAL EdgeLength AS DWORD _                        ' __in  UINT EdgeLength
   , BYVAL Levels AS DWORD _                            ' __in  UINT Levels
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _     ' __out IDirect3DCubeTexture9** ppCubeTexture
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexBuffer ( _                        ' VTable offset = 104
     BYVAL Length AS DWORD _                            ' __in  UINT Length
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppVertexBuffer AS IDirect3DVertexBuffer9 _   ' __out IDirect3DVertexBuffer9** ppVertexBuffer
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateIndexBuffer ( _                         ' VTable offset = 108
     BYVAL Length AS DWORD _                            ' __in  UINT Length
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppIndexBuffer AS IDirect3DIndexBuffer9 _     ' __out IDirect3DIndexBuffer9** ppIndexBuffer
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRenderTarget ( _                        ' VTable offset = 112
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Lockable AS LONG _                           ' __in  BOOL Lockable
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDepthStencilSurface ( _                 ' VTable offset = 116
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Discard AS LONG _                            ' __in  BOOL Discard
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSurface ( _                             ' __in VTable offset = 120
     BYVAL pSourceSurface AS IDirect3DSurface9 _        ' __in IDirect3DSurface9* pSourceSurface
   , BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYVAL pDestinationSurface AS IDirect3DSurface9 _   ' __in IDirect3DSurface9* pDestinationSurface
   , BYREF pDestPoint AS POINT _                        ' __in CONST POINT* pDestPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTexture ( _                             ' VTable offset = 124
     BYVAL pSourceTexture AS IDirect3DBaseTexture9 _    ' __in IDirect3DBaseTexture9* pSourceTexture
   , BYVAL pDestinationTexture AS IDirect3DBaseTexture9 _ ' __in IDirect3DBaseTexture9* pDestinationTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderTargetData ( _                       ' VTable offset = 128
     BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pRenderTarget
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrontBufferData ( _                        ' VTable offset = 132
     BYVAL iSwapChain AS DWORD _                        ' __in UINT iSwapChain
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StretchRect ( _                               ' VTable offset = 136
     BYVAL pSourceSurface AS IDirect3DSurface9 _        ' __in IDirect3DSurface9* pSourceSurface
   , BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pDestSurface
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL Filter AS DWORD _                            ' __in D3DTEXTUREFILTERTYPE Filter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ColorFill ( _                                 ' VTable offset = 140
     BYVAL pSurface AS IDirect3DSurface9 _              ' __in IDirect3DSurface9* pSurface
   , BYREF pRect AS RECT _                              ' __in CONST RECT* pRect
   , BYVAL color AS DWORD _                             ' __in D3DCOLOR color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateOffscreenPlainSurface ( _               ' VTable offset = 144
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9** ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE* pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderTarget ( _                           ' VTable offset = 148
     BYVAL RenderTargetIndex AS DWORD _                 ' __in DWORD RenderTargetIndex
   , BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9* pRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderTarget ( _                           ' VTable offset = 152
     BYVAL RenderTargetIndex AS DWORD _                 ' __in DWORD RenderTargetIndex
   , BYREF ppRenderTarget AS IDirect3DSurface9 _        ' __in IDirect3DSurface9** ppRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDepthStencilSurface ( _                    ' VTable offset = 156
     BYVAL pNewZStencil AS IDirect3DSurface9 _          ' __in IDirect3DSurface9* pNewZStencil
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDepthStencilSurface ( _                    ' VTable offset = 160
     BYREF ppZStencilSurface AS IDirect3DSurface9 _     ' __in IDirect3DSurface9** ppZStencilSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginScene ( _                                ' VTable offset = 164
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndScene ( _                                  ' VTable offset = 168
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 172
     BYVAL Count AS DWORD _                             ' __in DWORD Count
   , BYREF pRects AS D3DRECT _                          ' __in CONST D3DRECT* pRects
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   , BYVAL Z AS SINGLE _                                ' __in float Z
   , BYVAL Stencil AS DWORD _                           ' __in DWORD Stencil
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 176
     BYVAL State AS DWORD _                             ' __in D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __in CONST D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 180
     BYVAL State AS DWORD _                             ' __in  D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __out D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultiplyTransform ( _                         ' VTable offset = 184
     BYVAL State AS DWORD _                             ' __in D3DTRANSFORMSTATETYPE State
   , BYREF pMatrix AS D3DMATRIX _                       ' __in CONST D3DMATRIX * pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewport ( _                               ' VTable offset = 188
     BYREF pViewport AS D3DVIEWPORT9 _                  ' __in CONST D3DVIEWPORT9* pViewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewport ( _                               ' VTable offset = 192
     BYREF pViewport AS D3DVIEWPORT9 _                  ' __out D3DVIEWPORT9* pViewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaterial ( _                               ' VTable offset = 196
     BYREF pMaterial AS D3DMATERIAL9 _                  ' __in CONST D3DMATERIAL9* pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaterial ( _                               ' VTable offset = 200
     BYREF pMaterial AS D3DMATERIAL9 _                  ' __out D3DMATERIAL9* pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLight ( _                                  ' VTable offset = 204
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pMaterial AS D3DLIGHT9 _                     ' __in CONST D3DMATERIAL9 * pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLight ( _                                  ' VTable offset = 208
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pMaterial AS D3DLIGHT9 _                     ' __out D3DMATERIAL9 * pMaterial
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LightEnable ( _                               ' VTable offset = 212
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYVAL Enable AS LONG _                             ' __in BOOL Enable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLightEnable ( _                            ' VTable offset = 216
     BYVAL Index AS DWORD _                             ' __in  DWORD Index
   , BYREF pEnable AS LONG _                            ' __out BOOL* pEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipPlane ( _                              ' VTable offset = 220
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF pPlane AS SINGLE _                           ' __in CONST float* pPlane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipPlane ( _                              ' VTable offset = 224
     BYVAL Index AS DWORD _                             ' __in  DWORD Index
   , BYREF pPlane AS SINGLE _                           ' __out float* pPlane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderState ( _                            ' VTable offset = 228
     BYVAL State AS DWORD _                             ' __in D3DRENDERSTATETYPE State
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderState ( _                            ' VTable offset = 232
     BYVAL State AS DWORD _                             ' __in  D3DRENDERSTATETYPE State
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStateBlock ( _                          ' VTable offset = 236
     BYVAL Type AS DWORD _                              ' __in  D3DSTATEBLOCKTYPE Type
   , BYREF ppSB AS IDirect3DStateBlock9 _               ' __out IDirect3DStateBlock9** ppSB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginStateBlock ( _                           ' VTable offset = 240
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndStateBlock ( _                             ' VTable offset = 244
     BYREF ppSB AS IDirect3DStateBlock9 _               ' __out IDirect3DStateBlock9** ppSB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipStatus ( _                             ' VTable offset = 248
     BYREF pClipStatus AS D3DCLIPSTATUS9 _              ' __in CONST D3DCLIPSTATUS9* pClipStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipStatus ( _                             ' VTable offset = 252
     BYREF pClipStatus AS D3DCLIPSTATUS9 _              ' __out D3DCLIPSTATUS9* pClipStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 256
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYREF ppTexture AS IDirect3DBaseTexture9 _         ' __out IDirect3DBaseTexture9** ppTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 260
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYVAL pTexture AS IDirect3DBaseTexture9 _          ' __in IDirect3DBaseTexture9* pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextureStageState ( _                      ' VTable offset = 264
     BYVAL Stage AS DWORD _                             ' __in  DWORD Stage
   , BYVAL Type AS DWORD _                              ' __in  D3DTEXTURESTAGESTATETYPE Type
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextureStageState ( _                      ' VTable offset = 268
     BYVAL Stage AS DWORD _                             ' __in DWORD Stage
   , BYVAL Type AS DWORD _                              ' __in D3DTEXTURESTAGESTATETYPE Type
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSamplerState ( _                           ' VTable offset = 272
     BYVAL Sampler AS DWORD _                           ' __in  DWORD Sampler
   , BYVAL Type AS DWORD _                              ' __in  D3DSAMPLERSTATETYPE Type
   , BYREF pValue AS DWORD _                            ' __out DWORD* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSamplerState ( _                           ' VTable offset = 276
     BYVAL Sampler AS DWORD _                           ' __in DWORD Sampler
   , BYVAL Type AS DWORD _                              ' __in D3DSAMPLERSTATETYPE Type
   , BYVAL Value AS DWORD _                             ' __in DWORD Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateDevice ( _                            ' VTable offset = 280
     BYREF pNumPasses AS DWORD _                        ' __out DWORD* pNumPasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPaletteEntries ( _                         ' VTable offset = 284
     BYVAL PaletteNumber AS DWORD _                     ' __in UINT PaletteNumber
   , BYREF pEntries AS PALETTEENTRY _                   ' __in CONST PALETTEENTRY* pEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPaletteEntries ( _                         ' VTable offset = 288
     BYVAL PaletteNumber AS DWORD _                     ' __in  UINT PaletteNumber
   , BYREF pEntries AS PALETTEENTRY _                   ' __out PALETTEENTRY* pEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentTexturePalette ( _                  ' VTable offset = 292
     BYVAL PaletteNumber AS DWORD _                     ' __in UINT PaletteNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTexturePalette ( _                  ' VTable offset = 296
     BYREF PaletteNumber AS DWORD _                     ' __out UINT *PaletteNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScissorRect ( _                            ' VTable offset = 300
     BYREF pRect AS RECT _                              ' __in CONST RECT* pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScissorRect ( _                            ' VTable offset = 304
     BYREF pRect AS RECT _                              ' __out RECT* pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSoftwareVertexProcessing ( _               ' VTable offset = 308
     BYVAL bSoftware AS LONG _                          ' __in BOOL bSoftware
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSoftwareVertexProcessing ( _               ' VTable offset = 312
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD SetNPatchMode ( _                             ' VTable offset = 316
     BYVAL bSoftware AS SINGLE _                        ' __in float nSegments
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNPatchMode ( _                             ' VTable offset = 320
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD DrawPrimitive ( _                             ' VTable offset = 324
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL StartVertex AS DWORD _                       ' __in UINT StartVertex
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawIndexedPrimitive ( _                      ' VTable offset = 328
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL BaseVertexIndex AS LONG _                    ' __in INT BaseVertexIndex
   , BYVAL MinVertexIndex AS DWORD _                    ' __in UINT MinVertexIndex
   , BYVAL NumVertices AS DWORD _                       ' __in UINT NumVertices
   , BYVAL startIndex AS DWORD _                        ' __in UINT startIndex
   , BYVAL primCount AS DWORD _                         ' __in UINT primCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawPrimitiveUP ( _                           ' VTable offset = 332
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   , BYVAL pVertexStreamZeroData AS DWORD _             ' __in CONST void* pVertexStreamZeroData
   , BYVAL VertexStreamZeroStride AS DWORD _            ' __in UINT VertexStreamZeroStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawIndexedPrimitiveUP ( _                    ' VTable offset = 336
     BYVAL PrimitiveType AS DWORD _                     ' __in D3DPRIMITIVETYPE PrimitiveType
   , BYVAL MinVertexIndex AS DWORD _                    ' __in UINT MinVertexIndex
   , BYVAL NumVertices AS DWORD _                       ' __in UINT NumVertices
   , BYVAL PrimitiveCount AS DWORD _                    ' __in UINT PrimitiveCount
   , BYVAL pIndexData AS DWORD _                        ' __in CONST void* pIndexData
   , BYVAL IndexDataFormat AS DWORD _                   ' __in D3DFORMAT IndexDataFormat
   , BYVAL pVertexStreamZeroData AS DWORD _             ' __in CONST void* pVertexStreamZeroData
   , BYVAL VertexStreamZeroStride AS DWORD _            ' __in UINT VertexStreamZeroStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessVertices ( _                           ' VTable offset = 340
     BYVAL SrcStartIndex AS DWORD _                     ' __in UINT SrcStartIndex
   , BYVAL DestIndex AS DWORD _                         ' __in UINT DestIndex
   , BYVAL VertexCount AS DWORD _                       ' __in UINT VertexCount
   , BYVAL pDestBuffer AS IDirect3DVertexBuffer9 _      ' __in IDirect3DVertexBuffer9* pDestBuffer
   , BYVAL pVertexDecl AS IDirect3DVertexDeclaration9 _ ' __in IDirect3DVertexDeclaration9* pVertexDecl
   , BYVAL DWORD _                                      ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexDeclaration ( _                   ' VTable offset = 344
     BYREF pVertexElements AS D3DVERTEXELEMENT9 _       ' __in  CONST D3DVERTEXELEMENT9* pVertexElements
   , BYREF ppDecl AS IDirect3DVertexDeclaration9 _      ' __out IDirect3DVertexDeclaration9** ppDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexDeclaration ( _                      ' VTable offset = 348
     BYVAL pDecl AS IDirect3DVertexDeclaration9 _       ' __in IDirect3DVertexDeclaration9* pDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexDeclaration ( _                      ' VTable offset = 352
     BYREF ppDecl AS IDirect3DVertexDeclaration9 _      ' __in IDirect3DVertexDeclaration9** ppDecl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFVF ( _                                    ' VTable offset = 356
     BYVAL FVF AS DWORD _                               ' __in DWORD FVF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 360
     BYREF pFVF AS DWORD _                              ' __out DWORD* pFVF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexShader ( _                        ' VTable offset = 364
     BYVAL pFunction AS DWORD _                         ' __in  CONST DWORD* pFunction
   , BYREF ppShader AS IDirect3DVertexShader9 _         ' __out IDirect3DVertexShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShader ( _                           ' VTable offset = 368
     BYVAL pShader AS IDirect3DVertexShader9 _          ' __in IDirect3DVertexShader9* pShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShader ( _                           ' VTable offset = 372
     BYREF ppShader AS IDirect3DVertexShader9 _         ' __out IDirect3DVertexShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantF ( _                  ' VTable offset = 376
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in CONST float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantF ( _                  ' VTable offset = 380
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in_out float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantI ( _                  ' VTable offset = 384
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantI ( _                  ' VTable offset = 388
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out int* pConstantData
   , BYVAL VectorifCount AS DWORD _                     ' __in UINT VectorifCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShaderConstantB ( _                  ' VTable offset = 392
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShaderConstantB ( _                  ' VTable offset = 396
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSource ( _                           ' VTable offset = 400
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL pStreamData AS IDirect3DVertexBuffer9 _      ' __in IDirect3DVertexBuffer9* pStreamData
   , BYVAL OffsetInBytes AS DWORD _                     ' __in UINT OffsetInBytes
   , BYVAL Stride AS DWORD _                            ' __in UINT Stride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSource ( _                           ' VTable offset = 404
     BYVAL StreamNumber AS DWORD _                      ' __in  UINT StreamNumber
   , BYREF ppStreamData AS IDirect3DVertexBuffer9 _     ' __out IDirect3DVertexBuffer9** ppStreamData
   , BYREF OffsetInBytes AS DWORD _                     ' __out UINT * OffsetInBytes
   , BYREF Stride AS DWORD _                            ' __out UINT * Stride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSourceFreq ( _                       ' VTable offset = 408
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL Setting AS DWORD _                           ' __in UINT Setting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSourceFreq ( _                       ' VTable offset = 412
     BYVAL StreamNumber AS DWORD _                      ' __in  UINT StreamNumber
   , BYREF pSetting AS DWORD _                          ' __out UINT* pSetting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndices ( _                                ' VTable offset = 416
     BYVAL pIndexData AS IDirect3DIndexBuffer9 _        ' __in IDirect3DIndexBuffer9* pIndexData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndices ( _                                ' VTable offset = 420
     BYREF ppIndexData AS IDirect3DIndexBuffer9 _       ' __out IDirect3DIndexBuffer9** ppIndexData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePixelShader ( _                         ' VTable offset = 424
     BYVAL pFunction AS DWORD _                         ' __in  CONST DWORD* pFunction
   , BYREF ppShader AS IDirect3DPixelShader9 _          ' __out IDirect3DPixelShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShader ( _                            ' VTable offset = 428
     BYVAL pShader AS IDirect3DPixelShader9 _           ' __in IDirect3DPixelShader9* pShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShader ( _                            ' VTable offset = 432
     BYREF ppShader AS IDirect3DPixelShader9 _          ' __out IDirect3DPixelShader9** ppShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantF ( _                   ' VTable offset = 436
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in CONST float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantF ( _                   ' VTable offset = 440
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS SINGLE _                    ' __in_out float* pConstantData
   , BYVAL Vector4fCount AS DWORD _                     ' __in UINT Vector4fCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantI ( _                   ' VTable offset = 444
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantI ( _                   ' VTable offset = 448
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out int* pConstantData
   , BYVAL Vector4iCount AS DWORD _                     ' __in UINT Vector4iCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShaderConstantB ( _                   ' VTable offset = 452
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in CONST BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShaderConstantB ( _                   ' VTable offset = 456
     BYVAL StartRegister AS DWORD _                     ' __in UINT StartRegister
   , BYREF pConstantData AS LONG _                      ' __in_out BOOL* pConstantData
   , BYVAL BoolCount AS DWORD _                         ' __in UINT BoolCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawRectPatch ( _                             ' VTable offset = 460
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   , BYREF pNumSegs AS SINGLE _                         ' __in CONST float* pNumSegs
   , BYREF pRectPatchInfo AS D3DRECTPATCH_INFO _        ' __in CONST D3DRECTPATCH_INFO* pRectPatchInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawTriPatch ( _                              ' VTable offset = 464
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   , BYREF pNumSegs AS SINGLE _                         ' __in CONST float* pNumSegs
   , BYREF pTriPatchInfo AS D3DTRIPATCH_INFO _          ' __in CONST D3DRECTPATCH_INFO* pTriPatchInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePatch ( _                               ' VTable offset = 468
     BYVAL Handle AS DWORD _                            ' __in UINT Handle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQuery ( _                               ' VTable offset = 472
     BYVAL Type AS DWORD _                              ' __in  D3DQUERYTYPE Type
   , BYREF ppQuery AS IDirect3DQuery9 _                 ' __out IDirect3DQuery9** ppQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DDevice9Ex methods
   ' =====================================================================================
   METHOD SetConvolutionMonoKernel ( _                  ' VTable offset = 476
     BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   , BYREF RowWeights AS SINGLE _                       ' __in float *RowWeights
   , BYREF ColumnWeights AS SINGLE _                    ' __in float *ColumnWeights
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComposeRects ( _                              ' VTable offset = 480
     BYVAL pSource AS IDirect3DSurface9 _               ' __in IDirect3DSurface9 *pSource
   , BYVAL pDestination AS IDirect3DSurface9 _          ' __in IDirect3DSurface9 *pDestination
   , BYVAL pSrcRectDescriptors AS IDirect3DVertexBuffer9 _ ' __in IDirect3DVertexBuffer9 *pSrcRectDescriptors
   , BYVAL NumRects AS DWORD _                          ' __in UINT NumRects
   , BYVAL pDstRectDescriptors AS IDirect3DVertexBuffer9 _ ' __in IDirect3DVertexBuffer9 *pDstRectDescriptors
   , BYREF Operation AS DWORD _                         ' __in D3DCOMPOSERECTSOP Operation
   , BYVAL XOffset AS LONG _                            ' __in INT XOffset
   , BYVAL YOffset AS LONG _                            ' __in INT YOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PresentEx ( _                                 ' VTable offset = 484
     BYREF pSourceRect AS RECT _                        ' __in CONST RECT *pSourceRect
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT *pDestRect
   , BYVAL hDestWindowOverride AS DWORD _               ' __in HWND hDestWindowOverride
   , BYREF pDirtyRegion AS RGNDATA _                    ' __in CONST RGNDATA *pDirtyRegion
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGPUThreadPriority ( _                      ' VTable offset = 488
     BYREF pPriority AS LONG _                          ' __out INT *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGPUThreadPriority ( _                      ' VTable offset = 492
     BYVAL pPriority AS LONG _                          ' __out INT *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForVBlank ( _                             ' VTable offset = 496
     BYVAL SwapChainIndex AS DWORD _                    ' __in UINT SwapChainIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckResourceResidency ( _                    ' VTable offset = 500
     BYREF pResourceArray AS IDirect3DResource9 _       ' __in IDirect3DResource9 * pResourceArray
   , BYVAL NumResources AS DWORD _                      ' __in UINT32 NumResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaximumFrameLatency ( _                    ' VTable offset = 504
     BYVAL pMaxLatency AS DWORD _                       ' __in UINT pMaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumFrameLatency ( _                    ' VTable offset = 508
     BYREF pMaxLatency AS DWORD _                       ' __out UINT* pMaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckDeviceState ( _                          ' VTable offset = 512
     BYVAL hDestinationWindow AS DWORD _                ' __in HWND hDestinationWindow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRenderTargetEx ( _                      ' VTable offset = 516
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Lockable AS LONG _                           ' __in  BOOL Lockable
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE *pSharedHandle
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateOffscreenPlainSurfaceEx ( _             ' VTable offset = 520
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  DWORD Pool
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE *pSharedHandle
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDepthStencilSurfaceEx ( _               ' VTable offset = 524
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL MultiSample AS DWORD _                       ' __in  D3DMULTISAMPLE_TYPE MultiSample
   , BYVAL MultisampleQuality AS DWORD _                ' __in  DWORD MultisampleQuality
   , BYVAL Discard AS LONG _                            ' __in  BOOL Discard
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYVAL pSharedHandle AS DWORD _                     ' __in  HANDLE *pSharedHandle
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetEx ( _                                   ' VTable offset = 528
     BYREF pPresentationParameters AS D3DPRESENT_PARAMETERS _ ' __in_out D3DPRESENT_PARAMETERS* pPresentationParameters
   , BYREF pFullscreenDisplayMode AS D3DDISPLAYMODEEX _ ' __in_out D3DDISPLAYMODEEX* pFullscreenDisplayMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayModeEx ( _                          ' VTable offset = 532
     BYVAL iSwapChain AS DWORD _                        ' __in  UINT iSwapChain
   , BYREF pMode AS D3DDISPLAYMODEEX _                  ' __out D3DDISPLAYMODEEX *pMode
   , BYREF pRotation AS DWORD _                         ' __out D3DDISPLAYROTATION *pRotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IDirect3DSwapChain9Ex
' Inherited interface = IDirect3DSwapChain9
' ########################################################################################

INTERFACE IDirect3DSwapChain9Ex $IID_IDirect3DSwapChain9Ex

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirect3DSwapChain9 methods
   ' =====================================================================================
   METHOD Present ( _                                   ' VTable offset = 12
     BYREF pSourceRect AS RECT _                        ' __in CONST RECT* pSourceRect
   , BYREF pDestRect AS RECT _                          ' __in CONST RECT* pDestRect
   , BYVAL hDestWindowOverride AS DWORD _               ' __in HWND hDestWindowOverride
   , BYREF pDirtyRegion AS RGNDATA _                    ' __in CONST RGNDATA* pDirtyRegion
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrontBufferData ( _                        ' VTable offset = 16
     BYVAL pDestSurface AS IDirect3DSurface9 _          ' __in_out IDirect3DSurface9* pDestSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackBuffer ( _                             ' VTable offset = 20
     BYVAL iBackBuffer AS DWORD _                       ' __in  UINT iBackBuffer
   , BYVAL Type AS DWORD _                              ' __in  D3DBACKBUFFER_TYPE Type
   , BYREF ppBackBuffer AS IDirect3DSurface9 _          ' __out IDirect3DSurface9** ppBackBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRasterStatus ( _                           ' VTable offset = 24
     BYREF pRasterStatus AS D3DRASTER_STATUS _          ' __out D3DRASTER_STATUS* pRasterStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayMode ( _                            ' VTable offset = 28
     BYREF pMode AS D3DDISPLAYMODE _                    ' __out D3DDISPLAYMODE* pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 32
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentParameters ( _                      ' VTable offset = 36
     BYREF pPresentationParameters As D3DPRESENT_PARAMETERS _ ' __out D3DPRESENT_PARAMETERS* pPresentationParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirect3DSwapChain9Ex methods
   ' =====================================================================================
   METHOD GetLastPresentCount ( _                       ' VTable offset = 40
     BYREF pLastPresentCount AS DWORD _                 ' __out UINT * pLastPresentCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentStats ( _                           ' VTable offset = 44
     BYREF pPresentationStatistics AS D3DPRESENTSTATS _ ' __out D3DPRESENTSTATS * pPresentationStatistics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayModeEx ( _                          ' VTable offset = 48
     BYREF pMode AS D3DDISPLAYMODEEX _                  ' __out D3DDISPLAYMODEEX *pMode
   , BYREF pRotation AS DWORD _                         ' __out D3DDISPLAYROTATION *pRotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* -- D3D9Ex only */

' ########################################################################################
' Interface name = IDirect3D9ExOverlayExtension
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3D9ExOverlayExtension $IID_IDirect3D9ExOverlayExtension

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CheckDeviceOverlayType ( _                    ' VTable offset = 12
     BYVAL Adapter AS DWORD _                           ' __in UINT Adapter
   , BYVAL DevType AS DWORD _                           ' __in D3DDEVTYPE DevType
   , BYVAL OverlayWidth AS DWORD _                      ' __in UINT OverlayWidth
   , BYVAL OverlayHeight AS DWORD _                     ' __in UINT OverlayHeight
   , BYVAL OverlayFormat AS DWORD _                     ' __in D3DFORMAT OverlayFormat
   , BYREF pDisplayMode AS D3DDISPLAYMODEEX _           ' __in D3DDISPLAYMODEEX *pDisplayMode
   , BYVAL DisplayRotation AS DWORD _                   ' __in D3DDISPLAYROTATION DisplayRotation
   , BYREF pOverlayCaps AS D3DOVERLAYCAPS _             ' __out D3DOVERLAYCAPS *pOverlayCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDirect3DDevice9Video
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DDevice9Video $IID_IDirect3DDevice9Video

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContentProtectionCaps ( _                  ' VTable offset = 12
     BYREF pCryptoType AS GUID _                        ' __in const GUID *pCryptoType
   , BYREF pDecodeProfile AS GUID _                     ' __in const GUID *pDecodeProfile
   , BYREF pCaps AS D3DCONTENTPROTECTIONCAPS _          ' __in D3DCONTENTPROTECTIONCAPS *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAuthenticatedChannel ( _                ' VTable offset = 16
     BYVAL ChannelType AS LONG _                        ' __in D3DAUTHENTICATEDCHANNELTYPE ChannelType
   , BYREF ppAuthenticatedChannel AS IDirect3DAuthenticatedChannel9 _ ' __out IDirect3DAuthenticatedChannel9 **ppAuthenticatedChannel
   , BYREF pChannelHandle AS DWORD _                    ' __out HANDLE *pChannelHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCryptoSession ( _                       ' VTable offset = 20
     BYREF pCryptoType AS GUID _                        ' __in const GUID *pCryptoType
   , BYREF pDecodeProfile AS GUID _                     ' __in const GUID *pDecodeProfile
   , BYREF ppCryptoSession AS IDirect3DCryptoSession9 _ ' __out IDirect3DCryptoSession9 **ppCryptoSession
   , BYREF pCryptoHandle AS DWORD _                     ' __out HANDLE *pCryptoHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDirect3DAuthenticatedChannel9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DAuthenticatedChannel9 $IID_IDirect3DAuthenticatedChannel9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCertificateSize ( _                        ' VTable offset = 12
     BYREF pCertificateSize AS DWORD _                  ' __out UINT *pCertificateSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 16
     BYVAL CertifacteSize AS DWORD _                    ' __in UINT CertifacteSize
   , BYVAL ppCertificate AS BYTE PTR _                  ' __out BYTE *ppCertificate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NegotiateKeyExchange ( _                      ' VTable offset = 20
     BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS BYTE PTR _                          ' __in VOID *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Query ( _                                     ' VTable offset = 24
     BYVAL InputSize AS DWORD _                         ' __in UINT InputSize
   , BYVAL pInput AS BYTE PTR _                         ' __in const VOID *pInput
   , BYVAL OutputSize AS DWORD _                        ' __in UINT OutputSize
   , BYVAL pOutput AS BYTE PTR _                        ' __out VOID *pOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 28
     BYVAL InputSize AS DWORD _                         ' __in UINT InputSize
   , BYVAL pInput AS BYTE PTR _                         ' __in const VOID *pInput
   , BYREF pOutput AS D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT _ ' __out D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT *pOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IDirect3DCryptoSession9
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirect3DCryptoSession9 $IID_IDirect3DCryptoSession9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCertificateSize ( _                        ' VTable offset = 12
     BYREF pCertificateSize AS DWORD _                  ' __out UINT *pCertificateSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 16
     BYVAL CertifacteSize AS DWORD _                    ' __in UINT CertifacteSize
   , BYVAL ppCertificate AS BYTE PTR _                  ' __out BYTE *ppCertificate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NegotiateKeyExchange ( _                      ' VTable offset = 20
     BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS BYTE PTR _                          ' __in VOID *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncryptionBlt ( _                             ' VTable offset = 24
     BYVAL pSrcSurface AS IDirect3DSurface9 _           ' __in IDirect3DSurface9 *pSrcSurface
   , BYVAL pDstSurface AS IDirect3DSurface9 _           ' __inout IDirect3DSurface9 *pDstSurface
   , BYVAL DstSurfaceSize AS DWORD _                    ' __in UINT DstSurfaceSize
   , BYVAL pIV AS DWORD _                               ' __inout VOID *pIV
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecryptionBlt ( _                             ' VTable offset = 28
     BYVAL pSrcSurface AS IDirect3DSurface9 _           ' __in IDirect3DSurface9 *pSrcSurface
   , BYVAL pDstSurface AS IDirect3DSurface9 _           ' __inout IDirect3DSurface9 *pDstSurface
   , BYVAL SrcSurfaceSize AS DWORD _                    ' __in UINT SrcSurfaceSize
   , BYREF pEncryptedBlockInfo AS D3DENCRYPTED_BLOCK_INFO _ ' D3DENCRYPTED_BLOCK_INFO *pEncryptedBlockInfo
   , BYVAL pContentKey AS DWORD _                       ' __in VOID *pContentKey
   , BYVAL pIV AS DWORD _                               ' __in VOID *pIV
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfacePitch ( _                           ' VTable offset = 32
     BYVAL pSrcSurface AS IDirect3DSurface9 _           ' __in IDirect3DSurface9 *pSrcSurface
   , BYREF pSurfacePitch AS DWORD _                     ' __out UINT *pSurfacePitch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartSessionKeyRefresh ( _                    ' VTable offset = 36
     BYVAL pRandomNumber AS BYTE PTR _                  ' __inout VOID *pRandomNumber
   , BYVAL RandomNumberSize AS DWORD _                  ' __in UINT RandomNumberSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishSessionKeyRefresh ( _                   ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEncryptionBltKey ( _                       ' VTable offset = 44
     BYVAL pReadbackKey AS BYTE PTR _                   ' __inout VOID *pReadbackKey
   , BYVAL KeySize AS DWORD _                           ' __in UINT KeySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
